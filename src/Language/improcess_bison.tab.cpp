/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse yyipparse
#define yylex   yyiplex
#define yyerror yyiperror
#define yylval  yyiplval
#define yychar  yyipchar
#define yydebug yyipdebug
#define yynerrs yyipnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LEX_ERROR = 258,
     T_SetDebugOn = 259,
     T_SetDebugOff = 260,
     T_SetVerboseOn = 261,
     T_SetVerboseOff = 262,
     T_SetProgress = 263,
     T_argc = 264,
     T_emptyargs = 265,
     END_INSTRUCTION = 266,
     T_Image = 267,
     T_ReadRawImages = 268,
     T_Transform = 269,
     SHOW = 270,
     HELP = 271,
     QUIT = 272,
     T_HIDE = 273,
     PRINT = 274,
     PRINTN = 275,
     T_SPRINT = 276,
     ASHELL = 277,
     LS = 278,
     T_SetName = 279,
     T_GetName = 280,
     T_GetOutput = 281,
     T_GetDiffCoeff = 282,
     ASTRING = 283,
     ABLOCK = 284,
     NUMBER = 285,
     IDENTIFIER = 286,
     VAR_IMAGE = 287,
     VAR_FLOAT = 288,
     VAR_INT = 289,
     VAR_UCHAR = 290,
     VAR_STRING = 291,
     VAR_IMAGEDRAW = 292,
     VAR_SURFACE = 293,
     VAR_SURFDRAW = 294,
     VAR_MATRIX = 295,
     VAR_FILE = 296,
     VAR_C_FUNCTION = 297,
     VAR_C_PROCEDURE = 298,
     VAR_C_IMAGE_FUNCTION = 299,
     VAR_AMI_FUNCTION = 300,
     VAR_PARAMWIN = 301,
     VAR_GLTRANSFORM = 302,
     VAR_ARRAY_SURFACE = 303,
     VAR_ARRAY_IMAGE = 304,
     T_del = 305,
     ENDOP = 306,
     T_global = 307,
     T_local = 308,
     T_global_new = 309,
     T_local_new = 310,
     T_wait = 311,
     T_schedule = 312,
     T_ParamWin = 313,
     T_BeginPanel = 314,
     T_EndPanel = 315,
     T_BeginBook = 316,
     T_EndBook = 317,
     T_AddPage = 318,
     T_AddFloat = 319,
     T_AddInt = 320,
     T_CreateWin = 321,
     T_Display = 322,
     T_AddButton = 323,
     T_AddBoolean = 324,
     T_AddEnum = 325,
     T_AddEnumChoice = 326,
     T_AddString = 327,
     T_AddFilename = 328,
     T_ShowSlider = 329,
     T_SetCallback = 330,
     T_SetDragCallback = 331,
     T_BeginBox = 332,
     T_EndBox = 333,
     T_BeginHorizontal = 334,
     T_EndHorizontal = 335,
     T_redraw = 336,
     RIGHT_ASSIGN = 337,
     LEFT_ASSIGN = 338,
     ADD_ASSIGN = 339,
     SUB_ASSIGN = 340,
     MUL_ASSIGN = 341,
     DIV_ASSIGN = 342,
     MOD_ASSIGN = 343,
     AND_ASSIGN = 344,
     XOR_ASSIGN = 345,
     OR_ASSIGN = 346,
     RIGHT_OP = 347,
     INC_OP = 348,
     DEC_OP = 349,
     PTR_OP = 350,
     AND_OP = 351,
     OR_OP = 352,
     LE_OP = 353,
     GE_OP = 354,
     EQ_OP = 355,
     NE_OP = 356,
     TRANSPOSE_OP = 357,
     POINTWISE_MULT = 358,
     ASSIGN_OP = 359,
     T_COUNT = 360,
     T_MAX = 361,
     T_argmax = 362,
     T_MIN = 363,
     T_MEDIAN = 364,
     OpImage = 365,
     FILTER = 366,
     NormGrad = 367,
     T_DiscNormGrad = 368,
     T_gradient = 369,
     SecDerGrad = 370,
     SecDerGrad2 = 371,
     SubImage = 372,
     PutImage = 373,
     T_AutoCrop = 374,
     T_DiscSecDerGrad = 375,
     T_EDPdilate = 376,
     T_EDPerode = 377,
     T_EDPopen = 378,
     T_EDPclose = 379,
     AnisoGS = 380,
     AnisoSmoothGS = 381,
     T_vtkAnisoGS = 382,
     T_SetDistMap = 383,
     T_DiscMeanCurvature = 384,
     T_vtkMedian3D = 385,
     T_NULL = 386,
     T_InitTime = 387,
     T_TimeSpent = 388,
     T_EndTime = 389,
     T_LevelSetsCURV = 390,
     T_UpdateResult = 391,
     T_SetMeanCurv = 392,
     T_SetAffineCurv = 393,
     T_SetBalloonScheme = 394,
     T_SetVelocity = 395,
     T_SetExpansion = 396,
     T_SetExpansionImage = 397,
     T_SetAdvectionField = 398,
     T_SetCurvWeights = 399,
     T_GetAttachVect = 400,
     T_GetCurvature = 401,
     T_GetDistMap = 402,
     T_GetAdvection = 403,
     T_GetVelocity = 404,
     T_GetExpansion = 405,
     T_GetSkeleton = 406,
     T_SetDistMethod = 407,
     T_SetParam = 408,
     T_SetIsoContourBin = 409,
     T_SetBandTube = 410,
     T_SetThreads = 411,
     T_SaveDistMap = 412,
     T_SaveSecDerGrad = 413,
     T_SetNumGaussians = 414,
     T_SetGaussian = 415,
     T_SetProbThreshold = 416,
     T_SetILowTh = 417,
     T_SetIHighTh = 418,
     T_SetProbHighTh = 419,
     T_SetNumInitPoints = 420,
     T_SetInitPoint = 421,
     T_vtkFastMarching = 422,
     T_vtkFastMarchingTarget = 423,
     T_FluxDiffusion = 424,
     T_AnisoWeickert = 425,
     T_AnisoCW = 426,
     T_SRAD_qcoeff = 427,
     T_AnisoSRAD = 428,
     T_AnisoSRAD2 = 429,
     T_AnisoLeeAdd2 = 430,
     T_AnisoDPAD = 431,
     T_AnisoDPAD2 = 432,
     T_AnisoNRAD = 433,
     T_AnisoRudinMult = 434,
     TInit = 435,
     TSetCoeff = 436,
     TIterate = 437,
     TEnd = 438,
     TAddGaussNoise = 439,
     T_SNR = 440,
     T_SetNoiseType = 441,
     T_SetNoiseSD = 442,
     T_GetNoiseSD = 443,
     T_GetDAcoeff = 444,
     T_SetMask = 445,
     T_SetSRADROI = 446,
     T_SetRNRADROI = 447,
     T_SetRNRADROI_NEW = 448,
     T_SetLocalStruct = 449,
     T_SetEigenMode = 450,
     T_Setdt = 451,
     T_Setneighborhood = 452,
     T_info = 453,
     T_NbPoints = 454,
     T_NbPolys = 455,
     T_save = 456,
     T_normalize = 457,
     T_OrientField = 458,
     T_OrientPositive = 459,
     T_2DFlux = 460,
     T_OutFlux = 461,
     T_OutFluxScalar = 462,
     T_OrientationRatio = 463,
     T_Skeleton = 464,
     T_SimplePoints = 465,
     T_CircleIntegral = 466,
     T_CircleIntegralExc = 467,
     T_CircleIntSdExc = 468,
     T_CircleMinIntSdExc = 469,
     T_LocalExtrema = 470,
     T_NormalField = 471,
     T_DirConnectivity = 472,
     T_eccentricity = 473,
     T_rot2D = 474,
     T_mean = 475,
     T_SUM = 476,
     T_localmean = 477,
     T_localmean2 = 478,
     T_localSD = 479,
     T_localSD2 = 480,
     T_struct_tensor = 481,
     T_StructTensorH = 482,
     T_HessianMatrix = 483,
     T_HessianEVal = 484,
     T_Derivatives = 485,
     T_curvatures = 486,
     T_Laplacian = 487,
     T_setvoxelsize = 488,
     T_settranslation = 489,
     T_setendianness = 490,
     T_Skeleton2lines = 491,
     T_SmoothLines = 492,
     T_ResampleLines = 493,
     T_RemoveLine = 494,
     T_ConnectLines = 495,
     T_threscross = 496,
     T_IsocontourPoints = 497,
     T_IsosurfDist = 498,
     T_vtkIsoContourDist = 499,
     T_ShortestPath = 500,
     T_ShortestPathImage = 501,
     T_PathFromDispl = 502,
     T_PathFromVectField = 503,
     T_LineRecons = 504,
     T_ReadCTALine = 505,
     T_ReadCTALineRadii = 506,
     T_WriteCTALine = 507,
     T_SetIsoContour = 508,
     T_SetIsoContourParam = 509,
     T_DrawIsoContour = 510,
     T_SetIsoContourColor = 511,
     T_DrawAllContours = 512,
     T_AllContoursParam = 513,
     T_GetZmin = 514,
     T_GetZmax = 515,
     T_GetYmin = 516,
     T_GetYmax = 517,
     T_GetXmin = 518,
     T_GetXmax = 519,
     T_GetXPos = 520,
     T_GetYPos = 521,
     T_GetZPos = 522,
     T_vtkDicomRead = 523,
     T_vtkMINCRead = 524,
     T_Convolve = 525,
     T_ConvolveMask = 526,
     T_Pad = 527,
     T_Eigen2D = 528,
     T_Eigen3D = 529,
     T_ChamferDT = 530,
     T_Chamfer2DT = 531,
     T_BorgeforsDT = 532,
     T_BorgeforsSDT = 533,
     T_vtkSignedBorgefors = 534,
     T_vtkSignedFMDist = 535,
     T_PropagationDist = 536,
     T_PropagationDist2 = 537,
     T_PropDanielsson = 538,
     T_vtkPropDanielsson = 539,
     T_vtkPropDaniel2 = 540,
     T_CC = 541,
     T_ProcessXEvents = 542,
     T_ProcessEvents = 543,
     T_isoarea2D = 544,
     T_posarea = 545,
     T_isosurf = 546,
     T_isosurf_inv = 547,
     T_isosurf_ijk = 548,
     T_isosurf_ras = 549,
     T_vtkDecimate = 550,
     T_vtkMarchingCubes = 551,
     T_vtkSmooth = 552,
     T_Recompute = 553,
     T_vtkWindowedSinc = 554,
     T_isoline = 555,
     T_vtkDist = 556,
     T_AndreDist = 557,
     T_Surface = 558,
     T_getimage = 559,
     T_GetImageFromX = 560,
     T_rotate = 561,
     T_computeCC = 562,
     T_drawCC = 563,
     T_setminCC = 564,
     T_addobj = 565,
     T_setcurrentobj = 566,
     T_writeVRML = 567,
     T_writeVTK = 568,
     T_OwnMaterial = 569,
     T_SetColor = 570,
     T_SetColors = 571,
     T_SetColorOpacity = 572,
     T_Paint = 573,
     T_SetLight = 574,
     T_SetLightPos = 575,
     T_SetLightAmbient = 576,
     T_SetLightDiffuse = 577,
     T_SetLightSpecular = 578,
     T_SetBackground = 579,
     T_Remove = 580,
     T_SwapBuffers = 581,
     T_SetAmbient = 582,
     T_SetDiffuse = 583,
     T_SetSpecular = 584,
     T_SetShininess = 585,
     T_SetOpacity = 586,
     T_SetOpacityImage = 587,
     T_SetVisible = 588,
     T_SetColorMaterial = 589,
     T_penguin = 590,
     T_Statistics = 591,
     T_GetIntensities = 592,
     T_GetLinesLength = 593,
     T_GetLinesExtremities = 594,
     T_GetConnections = 595,
     T_SelectLines = 596,
     T_RemoveSelection = 597,
     T_mergepoints = 598,
     T_Triangulate = 599,
     T_Displace = 600,
     T_Normals = 601,
     T_InvertNormals = 602,
     T_Translate = 603,
     T_Scale = 604,
     T_SetPointsColors = 605,
     T_SetLineWidth = 606,
     T_AddPoint = 607,
     T_NewLine = 608,
     T_EndLine = 609,
     T_LineAddPointNumber = 610,
     T_GetTransform = 611,
     T_SetTransform = 612,
     T_Interpolate = 613,
     T_Matrix = 614,
     T_Invert = 615,
     T_PrintMatrices = 616,
     SET = 617,
     SETPOS = 618,
     SHOWCURSOR = 619,
     UPDATE = 620,
     COMPARE = 621,
     SETVECTOR = 622,
     T_SetCompareDisplacement = 623,
     T_DrawVector = 624,
     T_DisplayVectors = 625,
     T_SetVectParam = 626,
     T_SetVectColor = 627,
     T_SetVectStyle = 628,
     T_SetLineThickness = 629,
     T_SetZoom = 630,
     T_SetWindowSize = 631,
     T_SetColormap = 632,
     T_drawcircle = 633,
     T_setGLwin = 634,
     T_initvalue = 635,
     T_ShowSection = 636,
     T_HideSection = 637,
     T_Xpos = 638,
     T_Ypos = 639,
     T_Zpos = 640,
     T_SpacePos = 641,
     T_CHAR = 642,
     T_UCHAR = 643,
     T_SHORT = 644,
     T_USHORT = 645,
     T_INT = 646,
     T_UINT = 647,
     T_FLOAT = 648,
     T_DOUBLE = 649,
     T_RGB = 650,
     T_FLOAT_VECTOR = 651,
     T_GetFormat = 652,
     T_atof = 653,
     T_gnuplot = 654,
     T_histo = 655,
     T_cumhisto = 656,
     T_DisplayHisto = 657,
     T_OPEN = 658,
     T_CLOSE = 659,
     T_scan_float = 660,
     T_read = 661,
     T_rewind = 662,
     T_LineNumber = 663,
     CONST_PI = 664,
     SIN = 665,
     COS = 666,
     TAN = 667,
     ASIN = 668,
     ACOS = 669,
     ATAN = 670,
     SINH = 671,
     COSH = 672,
     EXP = 673,
     LN = 674,
     LOG = 675,
     SQRT = 676,
     ABS = 677,
     ROUND = 678,
     FLOOR = 679,
     NORM = 680,
     FOR = 681,
     TO = 682,
     STEP = 683,
     ENDFOR = 684,
     T_REPEAT = 685,
     T_UNTIL = 686,
     T_BREAK = 687,
     IF = 688,
     THEN = 689,
     ELSE = 690,
     VARIABLES = 691,
     FUNCTION = 692,
     T_exists = 693,
     T_slice = 694,
     T_GenRead = 695,
     T_IMAGE = 696,
     T_IMAGEDRAW = 697,
     T_SURFACE = 698,
     T_NUM = 699,
     T_STRING = 700,
     T_TRANSFORM = 701,
     T_PROC = 702,
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
     T_Set3DArrowParam = 718,
     T_CreateEllipsoids = 719,
     T_ComputeAltitudes = 720,
     T_Temp2Altitudes = 721,
     T_ReadFlow = 722,
     T_SetFluidNavFile = 723,
     T_DrawEarthCoord = 724,
     T_PaintCallback = 725,
     T_SaveStructuredGrid = 726,
     T_import_ami = 727,
     T_import_vtk = 728,
     T_import_itk = 729,
     T_import_wii = 730,
     T_import_filters = 731,
     T_amiOFCorr2D = 732,
     T_amiOFVar2D = 733
   };
#endif
/* Tokens.  */
#define LEX_ERROR 258
#define T_SetDebugOn 259
#define T_SetDebugOff 260
#define T_SetVerboseOn 261
#define T_SetVerboseOff 262
#define T_SetProgress 263
#define T_argc 264
#define T_emptyargs 265
#define END_INSTRUCTION 266
#define T_Image 267
#define T_ReadRawImages 268
#define T_Transform 269
#define SHOW 270
#define HELP 271
#define QUIT 272
#define T_HIDE 273
#define PRINT 274
#define PRINTN 275
#define T_SPRINT 276
#define ASHELL 277
#define LS 278
#define T_SetName 279
#define T_GetName 280
#define T_GetOutput 281
#define T_GetDiffCoeff 282
#define ASTRING 283
#define ABLOCK 284
#define NUMBER 285
#define IDENTIFIER 286
#define VAR_IMAGE 287
#define VAR_FLOAT 288
#define VAR_INT 289
#define VAR_UCHAR 290
#define VAR_STRING 291
#define VAR_IMAGEDRAW 292
#define VAR_SURFACE 293
#define VAR_SURFDRAW 294
#define VAR_MATRIX 295
#define VAR_FILE 296
#define VAR_C_FUNCTION 297
#define VAR_C_PROCEDURE 298
#define VAR_C_IMAGE_FUNCTION 299
#define VAR_AMI_FUNCTION 300
#define VAR_PARAMWIN 301
#define VAR_GLTRANSFORM 302
#define VAR_ARRAY_SURFACE 303
#define VAR_ARRAY_IMAGE 304
#define T_del 305
#define ENDOP 306
#define T_global 307
#define T_local 308
#define T_global_new 309
#define T_local_new 310
#define T_wait 311
#define T_schedule 312
#define T_ParamWin 313
#define T_BeginPanel 314
#define T_EndPanel 315
#define T_BeginBook 316
#define T_EndBook 317
#define T_AddPage 318
#define T_AddFloat 319
#define T_AddInt 320
#define T_CreateWin 321
#define T_Display 322
#define T_AddButton 323
#define T_AddBoolean 324
#define T_AddEnum 325
#define T_AddEnumChoice 326
#define T_AddString 327
#define T_AddFilename 328
#define T_ShowSlider 329
#define T_SetCallback 330
#define T_SetDragCallback 331
#define T_BeginBox 332
#define T_EndBox 333
#define T_BeginHorizontal 334
#define T_EndHorizontal 335
#define T_redraw 336
#define RIGHT_ASSIGN 337
#define LEFT_ASSIGN 338
#define ADD_ASSIGN 339
#define SUB_ASSIGN 340
#define MUL_ASSIGN 341
#define DIV_ASSIGN 342
#define MOD_ASSIGN 343
#define AND_ASSIGN 344
#define XOR_ASSIGN 345
#define OR_ASSIGN 346
#define RIGHT_OP 347
#define INC_OP 348
#define DEC_OP 349
#define PTR_OP 350
#define AND_OP 351
#define OR_OP 352
#define LE_OP 353
#define GE_OP 354
#define EQ_OP 355
#define NE_OP 356
#define TRANSPOSE_OP 357
#define POINTWISE_MULT 358
#define ASSIGN_OP 359
#define T_COUNT 360
#define T_MAX 361
#define T_argmax 362
#define T_MIN 363
#define T_MEDIAN 364
#define OpImage 365
#define FILTER 366
#define NormGrad 367
#define T_DiscNormGrad 368
#define T_gradient 369
#define SecDerGrad 370
#define SecDerGrad2 371
#define SubImage 372
#define PutImage 373
#define T_AutoCrop 374
#define T_DiscSecDerGrad 375
#define T_EDPdilate 376
#define T_EDPerode 377
#define T_EDPopen 378
#define T_EDPclose 379
#define AnisoGS 380
#define AnisoSmoothGS 381
#define T_vtkAnisoGS 382
#define T_SetDistMap 383
#define T_DiscMeanCurvature 384
#define T_vtkMedian3D 385
#define T_NULL 386
#define T_InitTime 387
#define T_TimeSpent 388
#define T_EndTime 389
#define T_LevelSetsCURV 390
#define T_UpdateResult 391
#define T_SetMeanCurv 392
#define T_SetAffineCurv 393
#define T_SetBalloonScheme 394
#define T_SetVelocity 395
#define T_SetExpansion 396
#define T_SetExpansionImage 397
#define T_SetAdvectionField 398
#define T_SetCurvWeights 399
#define T_GetAttachVect 400
#define T_GetCurvature 401
#define T_GetDistMap 402
#define T_GetAdvection 403
#define T_GetVelocity 404
#define T_GetExpansion 405
#define T_GetSkeleton 406
#define T_SetDistMethod 407
#define T_SetParam 408
#define T_SetIsoContourBin 409
#define T_SetBandTube 410
#define T_SetThreads 411
#define T_SaveDistMap 412
#define T_SaveSecDerGrad 413
#define T_SetNumGaussians 414
#define T_SetGaussian 415
#define T_SetProbThreshold 416
#define T_SetILowTh 417
#define T_SetIHighTh 418
#define T_SetProbHighTh 419
#define T_SetNumInitPoints 420
#define T_SetInitPoint 421
#define T_vtkFastMarching 422
#define T_vtkFastMarchingTarget 423
#define T_FluxDiffusion 424
#define T_AnisoWeickert 425
#define T_AnisoCW 426
#define T_SRAD_qcoeff 427
#define T_AnisoSRAD 428
#define T_AnisoSRAD2 429
#define T_AnisoLeeAdd2 430
#define T_AnisoDPAD 431
#define T_AnisoDPAD2 432
#define T_AnisoNRAD 433
#define T_AnisoRudinMult 434
#define TInit 435
#define TSetCoeff 436
#define TIterate 437
#define TEnd 438
#define TAddGaussNoise 439
#define T_SNR 440
#define T_SetNoiseType 441
#define T_SetNoiseSD 442
#define T_GetNoiseSD 443
#define T_GetDAcoeff 444
#define T_SetMask 445
#define T_SetSRADROI 446
#define T_SetRNRADROI 447
#define T_SetRNRADROI_NEW 448
#define T_SetLocalStruct 449
#define T_SetEigenMode 450
#define T_Setdt 451
#define T_Setneighborhood 452
#define T_info 453
#define T_NbPoints 454
#define T_NbPolys 455
#define T_save 456
#define T_normalize 457
#define T_OrientField 458
#define T_OrientPositive 459
#define T_2DFlux 460
#define T_OutFlux 461
#define T_OutFluxScalar 462
#define T_OrientationRatio 463
#define T_Skeleton 464
#define T_SimplePoints 465
#define T_CircleIntegral 466
#define T_CircleIntegralExc 467
#define T_CircleIntSdExc 468
#define T_CircleMinIntSdExc 469
#define T_LocalExtrema 470
#define T_NormalField 471
#define T_DirConnectivity 472
#define T_eccentricity 473
#define T_rot2D 474
#define T_mean 475
#define T_SUM 476
#define T_localmean 477
#define T_localmean2 478
#define T_localSD 479
#define T_localSD2 480
#define T_struct_tensor 481
#define T_StructTensorH 482
#define T_HessianMatrix 483
#define T_HessianEVal 484
#define T_Derivatives 485
#define T_curvatures 486
#define T_Laplacian 487
#define T_setvoxelsize 488
#define T_settranslation 489
#define T_setendianness 490
#define T_Skeleton2lines 491
#define T_SmoothLines 492
#define T_ResampleLines 493
#define T_RemoveLine 494
#define T_ConnectLines 495
#define T_threscross 496
#define T_IsocontourPoints 497
#define T_IsosurfDist 498
#define T_vtkIsoContourDist 499
#define T_ShortestPath 500
#define T_ShortestPathImage 501
#define T_PathFromDispl 502
#define T_PathFromVectField 503
#define T_LineRecons 504
#define T_ReadCTALine 505
#define T_ReadCTALineRadii 506
#define T_WriteCTALine 507
#define T_SetIsoContour 508
#define T_SetIsoContourParam 509
#define T_DrawIsoContour 510
#define T_SetIsoContourColor 511
#define T_DrawAllContours 512
#define T_AllContoursParam 513
#define T_GetZmin 514
#define T_GetZmax 515
#define T_GetYmin 516
#define T_GetYmax 517
#define T_GetXmin 518
#define T_GetXmax 519
#define T_GetXPos 520
#define T_GetYPos 521
#define T_GetZPos 522
#define T_vtkDicomRead 523
#define T_vtkMINCRead 524
#define T_Convolve 525
#define T_ConvolveMask 526
#define T_Pad 527
#define T_Eigen2D 528
#define T_Eigen3D 529
#define T_ChamferDT 530
#define T_Chamfer2DT 531
#define T_BorgeforsDT 532
#define T_BorgeforsSDT 533
#define T_vtkSignedBorgefors 534
#define T_vtkSignedFMDist 535
#define T_PropagationDist 536
#define T_PropagationDist2 537
#define T_PropDanielsson 538
#define T_vtkPropDanielsson 539
#define T_vtkPropDaniel2 540
#define T_CC 541
#define T_ProcessXEvents 542
#define T_ProcessEvents 543
#define T_isoarea2D 544
#define T_posarea 545
#define T_isosurf 546
#define T_isosurf_inv 547
#define T_isosurf_ijk 548
#define T_isosurf_ras 549
#define T_vtkDecimate 550
#define T_vtkMarchingCubes 551
#define T_vtkSmooth 552
#define T_Recompute 553
#define T_vtkWindowedSinc 554
#define T_isoline 555
#define T_vtkDist 556
#define T_AndreDist 557
#define T_Surface 558
#define T_getimage 559
#define T_GetImageFromX 560
#define T_rotate 561
#define T_computeCC 562
#define T_drawCC 563
#define T_setminCC 564
#define T_addobj 565
#define T_setcurrentobj 566
#define T_writeVRML 567
#define T_writeVTK 568
#define T_OwnMaterial 569
#define T_SetColor 570
#define T_SetColors 571
#define T_SetColorOpacity 572
#define T_Paint 573
#define T_SetLight 574
#define T_SetLightPos 575
#define T_SetLightAmbient 576
#define T_SetLightDiffuse 577
#define T_SetLightSpecular 578
#define T_SetBackground 579
#define T_Remove 580
#define T_SwapBuffers 581
#define T_SetAmbient 582
#define T_SetDiffuse 583
#define T_SetSpecular 584
#define T_SetShininess 585
#define T_SetOpacity 586
#define T_SetOpacityImage 587
#define T_SetVisible 588
#define T_SetColorMaterial 589
#define T_penguin 590
#define T_Statistics 591
#define T_GetIntensities 592
#define T_GetLinesLength 593
#define T_GetLinesExtremities 594
#define T_GetConnections 595
#define T_SelectLines 596
#define T_RemoveSelection 597
#define T_mergepoints 598
#define T_Triangulate 599
#define T_Displace 600
#define T_Normals 601
#define T_InvertNormals 602
#define T_Translate 603
#define T_Scale 604
#define T_SetPointsColors 605
#define T_SetLineWidth 606
#define T_AddPoint 607
#define T_NewLine 608
#define T_EndLine 609
#define T_LineAddPointNumber 610
#define T_GetTransform 611
#define T_SetTransform 612
#define T_Interpolate 613
#define T_Matrix 614
#define T_Invert 615
#define T_PrintMatrices 616
#define SET 617
#define SETPOS 618
#define SHOWCURSOR 619
#define UPDATE 620
#define COMPARE 621
#define SETVECTOR 622
#define T_SetCompareDisplacement 623
#define T_DrawVector 624
#define T_DisplayVectors 625
#define T_SetVectParam 626
#define T_SetVectColor 627
#define T_SetVectStyle 628
#define T_SetLineThickness 629
#define T_SetZoom 630
#define T_SetWindowSize 631
#define T_SetColormap 632
#define T_drawcircle 633
#define T_setGLwin 634
#define T_initvalue 635
#define T_ShowSection 636
#define T_HideSection 637
#define T_Xpos 638
#define T_Ypos 639
#define T_Zpos 640
#define T_SpacePos 641
#define T_CHAR 642
#define T_UCHAR 643
#define T_SHORT 644
#define T_USHORT 645
#define T_INT 646
#define T_UINT 647
#define T_FLOAT 648
#define T_DOUBLE 649
#define T_RGB 650
#define T_FLOAT_VECTOR 651
#define T_GetFormat 652
#define T_atof 653
#define T_gnuplot 654
#define T_histo 655
#define T_cumhisto 656
#define T_DisplayHisto 657
#define T_OPEN 658
#define T_CLOSE 659
#define T_scan_float 660
#define T_read 661
#define T_rewind 662
#define T_LineNumber 663
#define CONST_PI 664
#define SIN 665
#define COS 666
#define TAN 667
#define ASIN 668
#define ACOS 669
#define ATAN 670
#define SINH 671
#define COSH 672
#define EXP 673
#define LN 674
#define LOG 675
#define SQRT 676
#define ABS 677
#define ROUND 678
#define FLOOR 679
#define NORM 680
#define FOR 681
#define TO 682
#define STEP 683
#define ENDFOR 684
#define T_REPEAT 685
#define T_UNTIL 686
#define T_BREAK 687
#define IF 688
#define THEN 689
#define ELSE 690
#define VARIABLES 691
#define FUNCTION 692
#define T_exists 693
#define T_slice 694
#define T_GenRead 695
#define T_IMAGE 696
#define T_IMAGEDRAW 697
#define T_SURFACE 698
#define T_NUM 699
#define T_STRING 700
#define T_TRANSFORM 701
#define T_PROC 702
#define T_MeanHalfSize 703
#define T_Resize 704
#define T_ReSlice 705
#define T_Flip 706
#define T_SetCompTransf 707
#define T_ConvexHull 708
#define T_itk 709
#define T_CannyEdgeDetector 710
#define T_CreateFlatMesh 711
#define T_CreateVolume 712
#define T_vtkCreateFlatMesh 713
#define T_Altitude2Position 714
#define T_GeoCoordinates 715
#define T_ElevateMesh 716
#define T_CreateVectors 717
#define T_Set3DArrowParam 718
#define T_CreateEllipsoids 719
#define T_ComputeAltitudes 720
#define T_Temp2Altitudes 721
#define T_ReadFlow 722
#define T_SetFluidNavFile 723
#define T_DrawEarthCoord 724
#define T_PaintCallback 725
#define T_SaveStructuredGrid 726
#define T_import_ami 727
#define T_import_vtk 728
#define T_import_itk 729
#define T_import_wii 730
#define T_import_filters 731
#define T_amiOFCorr2D 732
#define T_amiOFVar2D 733




/* Copy the first part of user declarations.  */
#line 11 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

  //#include <stdlib.h>
  //#include <stdio.h>

#include "MainFrame.h"
#include "ParamPanel.hpp"
#include <locale.h>
#include "fonctions.h"
#include "func_isoline.hpp"
#include "ami_function.h"
//#include "dist_squared.hpp"
#include "improcess_bison.tab.hpp"
#include "wrapAMIFluid.h"
#include "wrapVTK.h"
#include "wrapITK.h"
#include "itkCannyEdgeDetector.h"
#include "wrapWII.h"
#include "wrapFilters.h"
#include <cstdlib>

#include "myscan.h"
#include "ImageDraw.hpp"
#include "Func_ReadCTALine.h"
#include "LineRecons.h"
//#include "PruneLines.h"

  //#define IDENT_MAX_SIZE 15

int               yy_num_buf = 0;
YY_BUFFER_STATE   yy_buf_stack[YY_MAX_BUF];
int               yyERROR;


#include "Viewer3D.hpp"

//#include "Erreurs.Main.hpp"
 // #include "Graphique.hpp"
#include "Viewer3D.hpp"
#include "DessinImage.hpp"
#include "CompareImage.hpp"
#include "bruit.hpp"
#include "CalculAireSection.hpp"
#include "reponse_cercle.hpp"
#include "func_shortestpath.h"
#include "AnisoGaussSeidel.h"
#include "LevelSetsCURVES.h"
#include "vtkwrap.h"

#include "gnuplot.hpp"

#include "xmtext.hpp"
#include "StringUtils.hpp"
//#include "histo.hpp"

#ifndef WIN32
#include <unistd.h>
#endif

#include <iostream>



#include "VarContexts.hpp"
#include "Duree.hpp"

#include "DefineClass.hpp"
/*
#include <boost/shared_ptr.hpp>
//--- string formatting using boost
#include <iostream>
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"
namespace MyNS_ForOutput {
  using std::cout; using std::cerr;
  using std::string;
  using std::endl; using std::flush;

  using boost::format;
  using boost::io::group;
}
using namespace MyNS_ForOutput;
*/

//-------

#include "wx/evtloop.h"

#include "penguin.h"

ImageStack        im_stack;
SurfStack         surf_stack;
MatrixStack       matrix_stack;
GLTransformStack  gltransf_stack;
VarContexts       Vars;

Duree            IP_time;

//Widget              GB_main_window;

extern MainFrame*   GB_main_wxFrame;
extern wxApp*       GB_wxApp;
extern int       GB_argc;

//extern TextControl* TC;
//extern int          GB_argc;
extern int       GB_num_arg_parsed;
extern wxString  GB_scripts_dir;
extern wxString  GB_help_dir;


namespace AMIFluid {
extern char* FLUID_NAVIGATION_FILE;
}

DessinImage* CreateIDraw(  std::string title, InrImage::ptr image);
// Creation of a DessinImage pointer
// this function is distinct if compiling with all amilab


//extern XtAppContext         GB_contexte;
//extern Widget               GB_app_shell;
extern unsigned char        GB_debug;
extern unsigned char        GB_verbose;
extern unsigned char        verbose;
extern unsigned char        GB_nofile;

extern char program[80];
//extern unsigned char verbose;

extern unsigned char DELETE_IDRAW;

extern int procedure_declaration;

#define MAX_TIMEOUT 10
int GB_TimeOut[MAX_TIMEOUT];



char  tmp_string[255];
FILE_ptr gr_output; // grammar
std::ostream* err_output; // errors
std::ostream* res_output; // result

FILE_ptr       cmdhistory;
std::string cmdhistory_filename;


 void init_gr_output();
 void gr_print(const char* st);
// void close_gr_output();

 void init_err_output();
 void err_print(const char* st);
// void close_err_output();

 void init_res_output();
 void res_print(const char* st);
// void close_res_output();

 void init_cmdhistory();
 void ws_print(const char* st);
// void close_cmdhistory();

/*
static wxString GetwxStr(const char* str) {
  return wxString::FromAscii(str);
}

static wxString GetwxStr(const string& str) {
  return wxString::FromAscii(str.c_str());
}
*/

class wxWaitTimer : public wxTimer
{
  public:
    bool finished;

    wxWaitTimer() : finished(false) {}
    //Called each time the timer's timeout expires
    void Notify()     { finished = true; }
};

static void CB_ParamWin( void* cd );


class wxScheduleTimer : public wxTimer
{
  DEFINE_CLASS(wxScheduleTimer)

  public:

    wxScheduleTimer( AMIFunction_ptr& callback) 
    { 
      f = callback; 
    }

    ~wxScheduleTimer() 
    { 
       cout << "~wxScheduleTimer()" << endl;
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    AMIFunction_ptr f;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;


void wxScheduleTimer::Notify()
{
  cout << "Notify()" << endl;
  CB_ParamWin(&f);

  std::list<wxScheduleTimer::ptr>::iterator Iter;
  for (Iter  = schedule_timers.begin(); 
       Iter != schedule_timers.end()  ; Iter++ )
  {
    if ((*Iter).use_count()) {
      if (Iter->get() == this) {
        Iter = schedule_timers.erase(Iter);
     }
    }
  }
}



static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}


void yyip_switch_to_block( const AmiInstructionBlock_ptr& b )
{
  yyiplineno = b->GetStartingLine();
  yyip_switch_to_string(b->GetBody().c_str());
}

void yyip_call_function( const AMIFunction_ptr& f)
{
  int    previous_lineno   = yyiplineno;
  string previous_filename = GB_current_file;

  // Call the function
  GB_current_file = f->GetFileName();
  yyip_switch_to_block(f->GetBody());
  yyip_parse();
  yyip_popup_buffer();

  // Restore position
  yyiplineno = previous_lineno;
  GB_current_file = previous_filename;

  // Continue parsing
  //continue_parse();
}


static void CB_ParamWin( void* cd ) {

  AMIFunction_ptr f;
  f = *(AMIFunction_ptr*) (cd);

  Vars.NewContext(f->GetName().c_str());
  yyip_call_function(f);
  Vars.DeleteLastContext();
  // need to continue parse here ??
  //continue_parse(); // --> segmentation fault

} // CB_ParamWin( void* cd )


void CB_delete_imagedraw( void* varname)
{
  if (GB_debug) fprintf(stderr,"CB_delete_imagedraw() \n");
  std::string* name = (std::string*) varname;
  if (Vars.deleteVar( name->c_str())==0)
    fprintf(stderr,"CB_delete_imagedraw() could not delete variable '%s' !!! \n",name->c_str());

// deleting is risky, use smart pointers instead ...
//  delete name;
}

void CB_delete_surfdraw( void* varid)
{
  fprintf(stderr," CB_delete_surfdraw begin \n");
  Variable* v = (Variable*) varid;
  fprintf(stderr," Delete var %s \n", v->Name());
  Vars.deleteVar( v->Name());
  fprintf(stderr," CB_delete_surfdraw end \n");
}


#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);                             \
  gr_print("\n  unary_op castE->unaryE");


#define UNARYOP_IMAGE(operator)           \
  InrImage* im;                           \
  int       i;                            \
  im = im_stack.GetLastImage();           \
  im->InitBuffer();                       \
  Si im->ScalarFormat() Alors             \
    Repeter                                \
     im->FixeValeur( operator(im->ValeurBuffer()) );   \
    JusquA Non(im->IncBuffer()) FinRepeter             \
  Sinon                                                \
    Pour(i,0,im->GetVDim()-1)                 \
      im->InitBuffer();                       \
      Repeter                                 \
       im->VectFixeValeur( i, operator(im->VectValeurBuffer(i)) );   \
      JusquA Non(im->IncBuffer()) FinRepeter  \
    FinPour                                   \
  FinSi                                       \
  im_stack.AddImage(im);

#define IMAGE_OP_EXPR(operator,expr)                     \
  InrImage* im1;                                         \
  int       i;                                           \
  double    val = expr;                                  \
  im1 = im_stack.GetLastImage();                         \
  im1->InitBuffer();                                     \
  Si im1->ScalarFormat() Alors                           \
    Repeter                                              \
      im1->FixeValeur(im1->ValeurBuffer() operator val); \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,im1->GetVDim()-1)                         \
        im1->VectFixeValeur(i,im1->VectValeurBuffer(i) operator val);  \
      FinPour                                            \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  im_stack.AddImage(im1);

#define EXPR_OP_IMAGE(operator,expr)                     \
  InrImage* im1;                                         \
  int       i;                                           \
  double    val = expr;                                  \
  im1 = im_stack.GetLastImage();                         \
  im1->InitBuffer();                                     \
  Si im1->ScalarFormat() Alors                           \
    Repeter                                              \
      im1->FixeValeur(val operator im1->ValeurBuffer() ); \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,im1->GetVDim()-1)                         \
        im1->VectFixeValeur(i, val operator im1->VectValeurBuffer(i));  \
      FinPour                                            \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  im_stack.AddImage(im1);

#define IMAGE_OP_IMAGE(operator)    \
  InrImage* im1;                    \
  InrImage* im2;                    \
  im2 = im_stack.GetLastImage();    \
  im1 = im_stack.GetLastImage();    \
  im1->InitBuffer();                \
  im2->InitBuffer();                \
  Repeter                           \
    im1->FixeValeur(im1->ValeurBuffer() operator im2->ValeurBuffer()); \
    im2->IncBuffer();               \
  JusquA Non(im1->IncBuffer())      \
  FinRepeter                        \
  im_stack.AddImage(im1);           \
  delete im2;

#define IMAGE_OP_IMAGE_2(operator)  \
  InrImage* im1;                    \
  InrImage* im2;                    \
  InrImage* res;                    \
  im2 = im_stack.GetLastImage();    \
  im1 = im_stack.GetLastImage();    \
  res = (*im1) operator (*im2);     \
  Si res == NULL Alors              \
    fprintf(stderr,"Error in operation \t IMAGE_OP_IMAGE_2 \n"); \
  FinSi                             \
  im_stack.AddImage(res);           \
  delete im1;                       \
  delete im2;

#define UNARYOP_MATRIX(operator)           \
  FloatMatrix* mat;                         \
  int       i,j;                            \
  mat = matrix_stack.GetLastMatrix();       \
  for (i=0;i<mat->Rows();i++)               \
  for (j=0;j<mat->Cols();j++) {             \
    (*mat)[i][j]=operator((*mat)[i][j]);               \
  }                                         \
  matrix_stack.AddMatrix(mat);

#define MATRIX_OP_EXPR(operator,expr)        \
  FloatMatrix* mat;                          \
  int       i,j;                             \
  float     val = expr;                      \
  mat = matrix_stack.GetLastMatrix();        \
  for (i=0;i<mat->Rows();i++)               \
  for (j=0;j<mat->Cols();j++) {             \
    (*mat)[i][j]=(*mat)[i][j] operator val;            \
  }                                         \
  matrix_stack.AddMatrix(mat);

#define MATRIX_OP_MATRIX_2(operator)        \
  FloatMatrix* mat1;                          \
  FloatMatrix* mat2;                          \
  FloatMatrix* mat;                          \
  int       i,j;                             \
  mat2 = matrix_stack.GetLastMatrix();        \
  mat1 = matrix_stack.GetLastMatrix();        \
  if ((mat1->Rows()==mat2->Rows())&&(mat1->Cols()==mat2->Cols())) { \
    mat=new FloatMatrix(mat1->Rows(),mat1->Cols()); \
    for (i=0;i<mat1->Rows();i++)               \
    for (j=0;j<mat1->Cols();j++)              \
      (*mat)[i][j]=(*mat1)[i][j] operator (*mat2)[i][j];            \
    matrix_stack.AddMatrix(mat);                 \
    delete mat1;                                    \
    delete mat2;                                    \
  }                                              \
  else {                                         \
    delete mat2;                                    \
    matrix_stack.AddMatrix(mat1);                \
  }




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
  char                  ident[IDENT_MAX_SIZE];
  Variable*             variable;
  char*                 astring;
  AmiInstructionBlock*  ablock;
  float                 afloat;
  double                adouble;
  int                   aint;
  ParamList*            paramlist; // here smart pointer
                            // not allowed in union ...
  ParamListDecl*        paramlistdecl;
  ImageExtent*          imageextent;
}
/* Line 187 of yacc.c.  */
#line 1510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  360
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  499
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  818
/* YYNRULES -- Number of states.  */
#define YYNSTATES  3254

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   733

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   490,     2,     2,     2,     2,   487,     2,
     480,   481,   491,   488,   482,   489,   485,   493,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   486,   479,
     494,     2,   495,   498,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   483,     2,   484,   496,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   497,     2,   492,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    15,    17,    20,    22,
      25,    27,    30,    32,    35,    37,    39,    48,    59,    62,
      67,    74,    82,    86,    88,    94,    97,    99,   101,   103,
     105,   107,   109,   114,   121,   128,   135,   142,   146,   150,
     157,   164,   168,   172,   176,   180,   187,   191,   195,   202,
     209,   216,   220,   224,   233,   242,   246,   248,   250,   252,
     254,   259,   261,   264,   267,   270,   272,   276,   280,   284,
     291,   298,   315,   318,   321,   325,   328,   331,   335,   339,
     342,   345,   349,   352,   355,   361,   364,   366,   368,   371,
     374,   379,   382,   385,   388,   390,   395,   399,   402,   405,
     416,   423,   427,   434,   441,   450,   479,   488,   497,   501,
     510,   523,   530,   537,   554,   563,   580,   591,   598,   609,
     618,   629,   644,   653,   666,   673,   682,   689,   696,   703,
     714,   721,   732,   743,   756,   763,   770,   783,   790,   797,
     804,   811,   818,   825,   832,   839,   846,   853,   860,   867,
     876,   880,   884,   888,   892,   896,   900,   913,   930,   937,
     944,   951,   958,   965,   972,   979,   986,   993,  1000,  1011,
    1018,  1033,  1040,  1049,  1056,  1063,  1072,  1079,  1090,  1097,
    1104,  1111,  1118,  1125,  1132,  1139,  1146,  1153,  1160,  1167,
    1171,  1175,  1180,  1184,  1191,  1198,  1203,  1208,  1215,  1226,
    1237,  1248,  1255,  1262,  1269,  1276,  1283,  1294,  1301,  1312,
    1319,  1326,  1333,  1337,  1344,  1351,  1362,  1373,  1380,  1387,
    1394,  1398,  1402,  1406,  1410,  1417,  1424,  1428,  1435,  1442,
    1451,  1462,  1466,  1473,  1477,  1482,  1503,  1510,  1521,  1528,
    1532,  1536,  1543,  1547,  1554,  1563,  1570,  1577,  1586,  1603,
    1610,  1614,  1621,  1630,  1634,  1647,  1660,  1673,  1684,  1693,
    1702,  1713,  1722,  1733,  1746,  1753,  1762,  1771,  1782,  1799,
    1818,  1831,  1838,  1857,  1874,  1887,  1898,  1909,  1920,  1927,
    1938,  1945,  1952,  1959,  1968,  1970,  1975,  1980,  1989,  1994,
    2013,  2018,  2020,  2022,  2029,  2036,  2040,  2044,  2051,  2058,
    2062,  2066,  2070,  2074,  2078,  2082,  2086,  2095,  2102,  2109,
    2116,  2120,  2125,  2127,  2129,  2131,  2133,  2135,  2166,  2191,
    2196,  2205,  2206,  2208,  2212,  2214,  2218,  2221,  2226,  2229,
    2234,  2236,  2240,  2243,  2248,  2251,  2256,  2258,  2262,  2263,
    2266,  2269,  2272,  2275,  2278,  2283,  2288,  2293,  2298,  2303,
    2305,  2307,  2309,  2316,  2318,  2322,  2324,  2328,  2332,  2334,
    2338,  2339,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,
    2358,  2360,  2365,  2372,  2381,  2392,  2403,  2412,  2419,  2423,
    2427,  2431,  2435,  2439,  2443,  2450,  2455,  2466,  2471,  2482,
    2487,  2492,  2497,  2502,  2507,  2512,  2520,  2528,  2536,  2546,
    2554,  2561,  2566,  2570,  2574,  2578,  2582,  2586,  2590,  2594,
    2598,  2602,  2606,  2610,  2614,  2621,  2630,  2641,  2652,  2661,
    2668,  2677,  2684,  2693,  2702,  2715,  2719,  2726,  2731,  2736,
    2738,  2745,  2752,  2754,  2757,  2760,  2763,  2766,  2769,  2772,
    2775,  2778,  2781,  2784,  2787,  2790,  2793,  2796,  2799,  2802,
    2805,  2807,  2809,  2811,  2816,  2818,  2822,  2826,  2828,  2832,
    2836,  2838,  2840,  2844,  2848,  2852,  2856,  2858,  2862,  2866,
    2870,  2874,  2876,  2880,  2882,  2886,  2888,  2892,  2894,  2898,
    2900,  2904,  2906,  2912,  2914,  2916,  2918,  2920,  2922,  2924,
    2926,  2928,  2930,  2932,  2934,  2936,  2940,  2942,  2947,  2950,
    2955,  2972,  2987,  3004,  3009,  3014,  3019,  3021,  3032,  3045,
    3054,  3056,  3061,  3068,  3075,  3082,  3091,  3100,  3107,  3114,
    3123,  3132,  3143,  3154,  3167,  3180,  3191,  3196,  3207,  3212,
    3219,  3224,  3229,  3234,  3247,  3252,  3265,  3278,  3295,  3316,
    3327,  3340,  3345,  3352,  3359,  3366,  3371,  3376,  3383,  3388,
    3395,  3402,  3409,  3414,  3425,  3442,  3453,  3462,  3475,  3486,
    3495,  3508,  3517,  3530,  3539,  3552,  3556,  3560,  3569,  3578,
    3582,  3589,  3602,  3615,  3630,  3643,  3656,  3673,  3678,  3687,
    3698,  3711,  3722,  3735,  3746,  3759,  3772,  3787,  3800,  3809,
    3824,  3829,  3834,  3839,  3844,  3848,  3852,  3856,  3863,  3870,
    3877,  3884,  3893,  3908,  3921,  3936,  3949,  3956,  3965,  3976,
    3987,  4000,  4007,  4014,  4021,  4028,  4035,  4042,  4049,  4056,
    4065,  4076,  4081,  4086,  4097,  4108,  4113,  4120,  4127,  4140,
    4171,  4180,  4186,  4192,  4198,  4205,  4212,  4217,  4224,  4229,
    4236,  4241,  4246,  4265,  4274,  4281,  4283,  4287,  4289,  4291,
    4294,  4297,  4300,  4303,  4306,  4309,  4312,  4315,  4318,  4321,
    4324,  4327,  4330,  4333,  4336,  4339,  4342,  4344,  4349,  4351,
    4355,  4359,  4363,  4367,  4371,  4373,  4375,  4379,  4383,  4387,
    4391,  4393,  4395,  4399,  4403,  4407,  4411,  4415,  4419,  4423,
    4427,  4429,  4433,  4437,  4441,  4445,  4447,  4451,  4453,  4455,
    4459,  4461,  4465,  4467,  4471,  4473,  4479,  4481,  4485,  4487,
    4489,  4493,  4502,  4507,  4514,  4516,  4521,  4523,  4527,  4529,
    4531,  4534,  4537,  4540,  4543,  4546,  4549,  4552,  4555,  4558,
    4561,  4564,  4567,  4570,  4573,  4576,  4579,  4582,  4584,  4586,
    4590,  4594,  4598,  4600,  4604,  4608,  4612,  4616,  4618,  4620,
    4622,  4624,  4626,  4628,  4630,  4632,  4634,  4636,  4638,  4640,
    4645,  4652,  4659,  4668,  4677,  4682,  4689,  4696,  4703,  4710,
    4714,  4717,  4722,  4724,  4729,  4736,  4738,  4743,  4748,  4759,
    4766,  4783,  4802,  4813,  4834,  4843,  4848,  4855,  4864,  4873,
    4886,  4903,  4920,  4939,  4954,  4969,  4986,  5007,  5009,  5011,
    5013,  5015,  5017,  5019,  5021,  5023,  5025,  5027,  5029,  5031,
    5033,  5035,  5037,  5039,  5041,  5043,  5055,  5063,  5065
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     500,     0,    -1,   501,    -1,   500,   501,    -1,   506,   501,
      -1,   500,   506,   501,    -1,   502,    -1,   500,   502,    -1,
     503,    -1,   500,   503,    -1,   505,    -1,   500,   505,    -1,
     504,    -1,   500,   504,    -1,    11,    -1,   479,    -1,   426,
     576,   104,   533,   427,   533,   513,   501,    -1,   426,   576,
     104,   533,   427,   533,   428,   533,   513,   501,    -1,   430,
     513,    -1,   433,   533,   513,   501,    -1,   433,   533,   513,
     435,   513,   501,    -1,   447,   576,   480,   508,   481,   513,
     501,    -1,   437,    28,   501,    -1,   437,    -1,    45,   480,
     507,   481,   501,    -1,    45,   501,    -1,    10,    -1,   432,
      -1,    52,    -1,    54,    -1,    55,    -1,    53,    -1,    56,
     480,   533,   481,    -1,    57,   480,   533,   482,    45,   481,
      -1,   576,   104,   303,   483,   533,   484,    -1,   576,    83,
     303,   483,   533,   484,    -1,   576,   104,    12,   483,   533,
     484,    -1,   576,   104,   554,    -1,   576,    83,   554,    -1,
     576,   104,    42,   480,   507,   481,    -1,    49,   483,   533,
     484,   104,   554,    -1,   576,   104,   573,    -1,   576,   104,
     555,    -1,    40,   104,   533,    -1,    40,   104,   573,    -1,
      48,   483,   533,   484,   104,   575,    -1,   576,   104,   575,
      -1,   574,    83,   575,    -1,    48,    83,   303,   483,   533,
     484,    -1,   576,   104,   391,   480,   533,   481,    -1,   576,
     104,   388,   480,   533,   481,    -1,   576,   104,   533,    -1,
     576,   104,   512,    -1,   576,   104,   403,   480,   512,   482,
      28,   481,    -1,    41,   104,   403,   480,   512,   482,    28,
     481,    -1,    41,   485,   407,    -1,     4,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,   480,   533,   481,    -1,    17,
      -1,    15,   535,    -1,    18,   535,    -1,    15,   574,    -1,
     335,    -1,   535,   104,   554,    -1,   535,    83,   554,    -1,
     535,   104,   533,    -1,   535,   483,   533,   484,   104,   554,
      -1,   535,   483,   533,   484,   104,   533,    -1,   535,   480,
     533,   486,   533,   482,   533,   486,   533,   482,   533,   486,
     533,   481,   104,   554,    -1,    33,    93,    -1,    33,    94,
      -1,    33,   104,   533,    -1,    34,    93,    -1,    34,    94,
      -1,    34,   104,   533,    -1,    35,   104,   533,    -1,    35,
      93,    -1,    35,    94,    -1,    36,   104,   512,    -1,    15,
     436,    -1,    50,   577,    -1,    50,    48,   483,   533,   484,
      -1,    22,   512,    -1,    23,    -1,    16,    -1,    16,   576,
      -1,    16,    28,    -1,    41,   485,    19,   512,    -1,    19,
     512,    -1,    20,   512,    -1,    19,   573,    -1,   573,    -1,
      41,   485,    19,   533,    -1,    41,   485,   404,    -1,    19,
     533,    -1,    20,   533,    -1,    37,   485,   363,   480,   533,
     482,   533,   482,   533,   481,    -1,    37,   485,   364,   480,
     533,   481,    -1,    37,   485,   365,    -1,    37,   485,   366,
     480,   535,   481,    -1,    37,   485,   366,   480,    37,   481,
      -1,    37,   485,   368,   480,    37,   482,   535,   481,    -1,
      37,   485,   452,   480,   533,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   481,    -1,    37,
     485,   367,   480,    30,   482,   535,   481,    -1,    37,   485,
     369,   480,   533,   482,   533,   481,    -1,    37,   485,   370,
      -1,    37,   485,   371,   480,   533,   482,   533,   481,    -1,
      37,   485,   372,   480,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,    37,   485,   373,   480,   533,   481,    -1,
      37,   485,   374,   480,   533,   481,    -1,    37,   485,   375,
     480,   533,   482,   533,   482,   533,   482,   533,   482,   533,
     482,   533,   481,    -1,    37,   485,   376,   480,   533,   482,
     533,   481,    -1,    37,   485,   378,   480,   533,   482,   533,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
      37,   485,   377,   480,   554,   482,   533,   482,   533,   481,
      -1,    37,   485,   379,   480,    39,   481,    -1,    37,   485,
     253,   480,   533,   482,   535,   482,   533,   481,    -1,    37,
     485,   253,   480,   535,   482,   533,   481,    -1,    37,   485,
     254,   480,   533,   482,   533,   482,   533,   481,    -1,    37,
     485,   254,   480,   533,   482,   533,   482,   533,   482,   533,
     482,   533,   481,    -1,    37,   485,   255,   480,   533,   482,
     533,   481,    -1,    37,   485,   256,   480,   533,   482,   533,
     482,   533,   482,   533,   481,    -1,    37,   485,   257,   480,
     533,   481,    -1,    37,   485,   258,   480,   533,   482,   533,
     481,    -1,    37,   485,   470,   480,    45,   481,    -1,    37,
     485,   332,   480,   535,   481,    -1,   535,   485,   380,   480,
     533,   481,    -1,   535,   485,   380,   480,   533,   482,   533,
     482,   533,   481,    -1,   535,   485,   362,   480,   533,   481,
      -1,   535,   485,   362,   480,   533,   482,   533,   482,   533,
     481,    -1,   535,   485,   363,   480,   533,   482,   533,   482,
     533,   481,    -1,   535,   485,   118,   480,   535,   482,   533,
     482,   533,   482,   533,   481,    -1,   535,   485,   118,   480,
     535,   481,    -1,   535,   485,    24,   480,   512,   481,    -1,
     125,   485,   180,   480,   535,   482,   533,   482,   533,   482,
     533,   481,    -1,   125,   485,   181,   480,   533,   481,    -1,
     125,   485,   128,   480,   533,   481,    -1,   125,   485,   186,
     480,   533,   481,    -1,   125,   485,   187,   480,   533,   481,
      -1,   125,   485,   190,   480,   535,   481,    -1,   125,   485,
     191,   480,   535,   481,    -1,   125,   485,   192,   480,   535,
     481,    -1,   125,   485,   193,   480,   535,   481,    -1,   125,
     485,   194,   480,   533,   481,    -1,   125,   485,   195,   480,
     533,   481,    -1,   125,   485,   196,   480,   533,   481,    -1,
     125,   485,   197,   480,   533,   481,    -1,   125,   485,   181,
     480,   533,   482,   533,   481,    -1,   125,   485,   182,    -1,
     125,   485,   183,    -1,   170,   485,   182,    -1,   170,   485,
     183,    -1,   171,   485,   182,    -1,   171,   485,   183,    -1,
     135,   485,   153,   480,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   135,   485,   153,   480,   533,   482,   533,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     135,   485,   137,   480,   533,   481,    -1,   135,   485,   138,
     480,   533,   481,    -1,   135,   485,   139,   480,   533,   481,
      -1,   135,   485,   152,   480,   533,   481,    -1,   135,   485,
     156,   480,   533,   481,    -1,   135,   485,   161,   480,   533,
     481,    -1,   135,   485,   162,   480,   533,   481,    -1,   135,
     485,   163,   480,   533,   481,    -1,   135,   485,   164,   480,
     533,   481,    -1,   135,   485,   159,   480,   533,   481,    -1,
     135,   485,   160,   480,   533,   482,   533,   482,   533,   481,
      -1,   135,   485,   165,   480,   533,   481,    -1,   135,   485,
     166,   480,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   135,   485,   154,   480,   533,   481,    -1,
     135,   485,   140,   480,   535,   482,   533,   481,    -1,   135,
     485,   141,   480,   533,   481,    -1,   135,   485,   142,   480,
     535,   481,    -1,   135,   485,   155,   480,   533,   482,   533,
     481,    -1,   135,   485,   144,   480,   535,   481,    -1,   135,
     485,   143,   480,   535,   482,   535,   482,   535,   481,    -1,
     135,   485,   146,   480,   535,   481,    -1,   135,   485,   147,
     480,   535,   481,    -1,   135,   485,   148,   480,   535,   481,
      -1,   135,   485,   151,   480,   535,   481,    -1,   135,   485,
     149,   480,   535,   481,    -1,   135,   485,   150,   480,   535,
     481,    -1,   135,   485,   146,   480,   131,   481,    -1,   135,
     485,   148,   480,   131,   481,    -1,   135,   485,   149,   480,
     131,   481,    -1,   135,   485,   157,   480,   533,   481,    -1,
     135,   485,   158,   480,   533,   481,    -1,   135,   485,   182,
      -1,   135,   485,   183,    -1,   535,   485,   201,   512,    -1,
     535,   485,   202,    -1,   535,   485,   203,   480,   535,   481,
      -1,   535,   485,   204,   480,   535,   481,    -1,   574,   485,
     201,   512,    -1,   574,   485,   252,   512,    -1,   574,   485,
     314,   480,   533,   481,    -1,   574,   485,   327,   480,   533,
     482,   533,   482,   533,   481,    -1,   574,   485,   328,   480,
     533,   482,   533,   482,   533,   481,    -1,   574,   485,   329,
     480,   533,   482,   533,   482,   533,   481,    -1,   574,   485,
     330,   480,   533,   481,    -1,   574,   485,   331,   480,   533,
     481,    -1,   574,   485,   333,   480,   533,   481,    -1,   574,
     485,   334,   480,   533,   481,    -1,   574,   485,   317,   480,
     533,   481,    -1,   574,   485,   315,   480,   533,   482,   533,
     482,   533,   481,    -1,   574,   485,   350,   480,   535,   481,
      -1,   574,   485,   316,   480,   554,   482,   533,   482,   533,
     481,    -1,   574,   485,   316,   480,   554,   481,    -1,   574,
     485,   336,   480,   535,   481,    -1,   574,   485,   343,   480,
     533,   481,    -1,   574,   485,   344,    -1,   574,   485,   231,
     480,   533,   481,    -1,   574,   485,   345,   480,   554,   481,
      -1,   574,   485,   348,   480,   533,   482,   533,   482,   533,
     481,    -1,   574,   485,   349,   480,   533,   482,   533,   482,
     533,   481,    -1,   574,   485,   351,   480,   533,   481,    -1,
     574,   485,   239,   480,   533,   481,    -1,   574,   485,   341,
     480,   554,   481,    -1,   574,   485,   342,    -1,   574,   485,
     298,    -1,   574,   485,   346,    -1,   574,   485,   347,    -1,
     574,   485,   297,   480,   533,   481,    -1,   574,   485,   299,
     480,   533,   481,    -1,   574,   485,   295,    -1,   574,   485,
     309,   480,   533,   481,    -1,   574,   485,   308,   480,   533,
     481,    -1,   574,   485,   308,   480,   533,   482,   533,   481,
      -1,   574,   485,   352,   480,   533,   482,   533,   482,   533,
     481,    -1,   574,   485,   353,    -1,   574,   485,   355,   480,
     533,   481,    -1,   574,   485,   354,    -1,   468,   480,   512,
     481,    -1,   469,   480,    37,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   574,   485,   461,   480,   554,   481,    -1,
      39,   485,   306,   480,   533,   482,   533,   482,   533,   481,
      -1,    39,   485,   310,   480,   575,   481,    -1,    39,    84,
     574,    -1,    39,    85,   574,    -1,    39,   485,   325,   480,
     574,   481,    -1,    39,   485,   326,    -1,    39,   485,   308,
     480,   533,   481,    -1,    39,   485,   308,   480,   533,   482,
     533,   481,    -1,    39,   485,   311,   480,   533,   481,    -1,
      39,   485,   366,   480,    39,   481,    -1,    39,   485,   367,
     480,    30,   482,   535,   481,    -1,    39,   485,   381,   480,
     533,   482,   554,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,    39,   485,   382,   480,   533,   481,    -1,
      39,   485,   361,    -1,    39,   485,   357,   480,   555,   481,
      -1,    39,   485,   357,   480,   555,   482,   533,   481,    -1,
      39,   485,   318,    -1,    39,   485,   321,   480,   533,   482,
     533,   482,   533,   482,   533,   481,    -1,    39,   485,   322,
     480,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
      39,   485,   323,   480,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,    39,   485,   324,   480,   533,   482,   533,
     482,   533,   481,    -1,    39,   485,   376,   480,   533,   482,
     533,   481,    -1,   226,   480,   535,   482,   533,   482,   533,
     481,    -1,   226,   480,   535,   482,   533,   482,   533,   482,
     554,   481,    -1,   227,   480,   535,   482,   533,   482,   533,
     481,    -1,   227,   480,   535,   482,   533,   482,   533,   482,
     554,   481,    -1,   227,   480,   535,   482,   533,   482,   533,
     482,   554,   482,   533,   481,    -1,   228,   480,   535,   482,
     533,   481,    -1,   228,   480,   535,   482,   533,   482,   554,
     481,    -1,   228,   480,   535,   482,   533,   482,   533,   481,
      -1,   228,   480,   535,   482,   533,   482,   533,   482,   554,
     481,    -1,   230,   480,   535,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   481,    -1,   230,
     480,   535,   482,   533,   482,   533,   482,   533,   482,   533,
     482,   533,   482,   533,   482,   554,   481,    -1,   229,   480,
     535,   482,   533,   482,   533,   482,   554,   482,   533,   481,
      -1,   231,   480,   535,   482,   533,   481,    -1,   274,   480,
      28,   482,   535,   482,   535,   482,   535,   482,   535,   482,
     535,   482,   535,   482,   554,   481,    -1,   274,   480,    28,
     482,   535,   482,   535,   482,   535,   482,   535,   482,   535,
     482,   535,   481,    -1,   273,   480,    28,   482,   535,   482,
     535,   482,   535,   482,   554,   481,    -1,   273,   480,    28,
     482,   535,   482,   535,   482,   535,   481,    -1,   233,   480,
     535,   482,   533,   482,   533,   482,   533,   481,    -1,   535,
     485,   233,   480,   533,   482,   533,   482,   533,   481,    -1,
     535,   485,   233,   480,   535,   481,    -1,   535,   485,   234,
     480,   533,   482,   533,   482,   533,   481,    -1,   535,   485,
     234,   480,   535,   481,    -1,   535,   485,   235,   480,   533,
     481,    -1,   120,   480,   535,   482,   535,   481,    -1,   120,
     480,   535,   482,   535,   482,   535,   481,    -1,   533,    -1,
     287,   480,   533,   481,    -1,   288,   480,   533,   481,    -1,
     399,   480,   554,   482,   512,   482,   533,   481,    -1,   402,
     480,   535,   481,    -1,   272,   480,   535,   482,   535,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   440,   480,    28,   481,    -1,   132,    -1,
     134,    -1,   576,   104,    58,   480,   512,   481,    -1,    46,
     485,    77,   480,   512,   481,    -1,    46,   485,    61,    -1,
      46,   485,    62,    -1,    46,   485,    63,   480,   512,   481,
      -1,    46,   485,    59,   480,   512,   481,    -1,    46,   485,
      60,    -1,    46,   485,    78,    -1,    46,   485,    79,    -1,
      46,   485,    80,    -1,    46,   485,    66,    -1,    46,   485,
      67,    -1,    46,   485,    81,    -1,    46,   485,    74,   480,
     533,   482,   533,   481,    -1,    46,   485,    75,   480,    45,
     481,    -1,    46,   485,    76,   480,   533,   481,    -1,   471,
     480,   535,   482,   512,   481,    -1,    47,   485,    19,    -1,
      47,   485,   201,   512,    -1,   472,    -1,   473,    -1,   474,
      -1,   475,    -1,   476,    -1,   477,   480,   535,   482,   535,
     482,   535,   482,   535,   482,   535,   482,   535,   482,   535,
     482,   533,   482,   533,   482,   533,   482,   533,   482,   533,
     482,   533,   482,   533,   481,    -1,   478,   480,   535,   482,
     535,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   535,   482,   535,   482,   533,   481,
      -1,    43,   480,   507,   481,    -1,   463,   480,   533,   482,
     533,   482,   533,   481,    -1,    -1,   533,    -1,   507,   482,
     533,    -1,   512,    -1,   507,   482,   512,    -1,   487,    33,
      -1,   507,   482,   487,    33,    -1,   487,    34,    -1,   507,
     482,   487,    34,    -1,   554,    -1,   507,   482,   554,    -1,
     487,   535,    -1,   507,   482,   487,   535,    -1,   487,   574,
      -1,   507,   482,   487,   574,    -1,    37,    -1,   507,   482,
      37,    -1,    -1,   444,    31,    -1,   445,    31,    -1,   441,
      31,    -1,   442,    31,    -1,   443,    31,    -1,   508,   482,
     444,    31,    -1,   508,   482,   445,    31,    -1,   508,   482,
     441,    31,    -1,   508,   482,   442,    31,    -1,   508,   482,
     443,    31,    -1,    28,    -1,    36,    -1,   509,    -1,    21,
     480,   512,   482,   533,   481,    -1,   133,    -1,   535,   485,
      25,    -1,   510,    -1,   511,   488,   510,    -1,   511,   489,
     510,    -1,   511,    -1,   514,    29,   515,    -1,    -1,    -1,
      30,    -1,     9,    -1,   408,    -1,   409,    -1,    33,    -1,
      34,    -1,    35,    -1,   480,   533,   481,    -1,   516,    -1,
     535,   480,   533,   481,    -1,   535,   480,   533,   482,   533,
     481,    -1,   535,   480,   533,   482,   533,   482,   533,   481,
      -1,   535,   480,   533,   482,   533,   482,   533,   482,   533,
     481,    -1,   535,   480,   533,   482,   533,   482,   533,   479,
     533,   481,    -1,   535,   480,   533,   482,   533,   479,   533,
     481,    -1,   535,   480,   533,   479,   533,   481,    -1,   535,
     485,   180,    -1,   535,   485,   576,    -1,   535,   485,   198,
      -1,   574,   485,   198,    -1,   574,   485,   199,    -1,   574,
     485,   200,    -1,   185,   480,   535,   482,   535,   481,    -1,
     218,   480,   535,   481,    -1,   289,   480,   535,   482,   533,
     482,   533,   482,   533,   481,    -1,   290,   480,   535,   481,
      -1,   290,   480,   533,   482,   533,   482,   533,   482,   533,
     481,    -1,   105,   480,   554,   481,    -1,   220,   480,   554,
     481,    -1,   106,   480,   535,   481,    -1,   107,   480,   554,
     481,    -1,   108,   480,   535,   481,    -1,   109,   480,   535,
     481,    -1,   106,   483,   554,   484,   480,   535,   481,    -1,
     108,   483,   554,   484,   480,   535,   481,    -1,   109,   483,
     554,   484,   480,   535,   481,    -1,   109,   483,   554,   484,
     480,   535,   482,   533,   481,    -1,   220,   483,   554,   484,
     480,   554,   481,    -1,   220,   480,   535,   482,   554,   481,
      -1,   398,   480,    28,   481,    -1,    37,   485,   263,    -1,
      37,   485,   264,    -1,    37,   485,   261,    -1,    37,   485,
     262,    -1,    37,   485,   259,    -1,    37,   485,   260,    -1,
      37,   485,   265,    -1,    37,   485,   266,    -1,    37,   485,
     267,    -1,   125,   485,   188,    -1,   125,   485,   189,    -1,
     135,   485,   136,    -1,    40,   480,   533,   482,   533,   481,
      -1,    40,   480,   533,   482,   533,   481,   104,   533,    -1,
      46,   485,    64,   480,    33,   482,   533,   482,   533,   481,
      -1,    46,   485,    65,   480,    34,   482,   533,   482,   533,
     481,    -1,    46,   485,    68,   480,   512,   482,    45,   481,
      -1,    46,   485,    69,   480,    35,   481,    -1,    46,   485,
      70,   480,    34,   482,   533,   481,    -1,    46,   485,    70,
     480,    34,   481,    -1,    46,   485,    71,   480,   533,   482,
     512,   481,    -1,    46,   485,    72,   480,    36,   482,   512,
     481,    -1,    46,   485,    73,   480,    36,   482,   512,   482,
     512,   482,   512,   481,    -1,    46,   485,   365,    -1,    46,
     485,   365,   480,   533,   481,    -1,   438,   480,   576,   481,
      -1,   438,   480,   577,   481,    -1,   534,    -1,    41,   485,
     405,   480,   512,   481,    -1,    41,   485,   406,   480,    33,
     481,    -1,   517,    -1,   519,   520,    -1,   490,   520,    -1,
     489,   520,    -1,   488,   520,    -1,   410,   520,    -1,   411,
     520,    -1,   421,   520,    -1,   422,   520,    -1,   423,   520,
      -1,   424,   520,    -1,   412,   520,    -1,   413,   520,    -1,
     414,   520,    -1,   415,   520,    -1,   418,   520,    -1,   420,
     520,    -1,   419,   520,    -1,   491,    -1,   492,    -1,   518,
      -1,   480,   534,   481,   518,    -1,   520,    -1,   521,   491,
     520,    -1,   521,   493,   520,    -1,   521,    -1,   522,   488,
     521,    -1,   522,   489,   521,    -1,   522,    -1,   523,    -1,
     524,   494,   523,    -1,   524,   495,   523,    -1,   524,    98,
     523,    -1,   524,    99,   523,    -1,   524,    -1,   525,   100,
     524,    -1,   525,   101,   524,    -1,   512,   100,   512,    -1,
     512,   101,   512,    -1,   525,    -1,   526,   487,   525,    -1,
     526,    -1,   527,   496,   526,    -1,   527,    -1,   528,   497,
     527,    -1,   528,    -1,   529,    96,   528,    -1,   529,    -1,
     530,    97,   529,    -1,   530,    -1,   530,   498,   530,   486,
     531,    -1,   531,    -1,   532,    -1,   387,    -1,   388,    -1,
     389,    -1,   390,    -1,   391,    -1,   392,    -1,   393,    -1,
     394,    -1,   395,    -1,   396,    -1,   535,   485,   397,    -1,
      32,    -1,    49,   483,   533,   484,    -1,    12,    28,    -1,
      12,   480,   512,   481,    -1,    13,   480,   533,   482,   533,
     482,   534,   482,   533,   482,   512,   482,   533,   482,   533,
     481,    -1,    13,   480,   533,   482,   533,   482,   533,   482,
     534,   482,   533,   482,   512,   481,    -1,    13,   480,   533,
     482,   533,   482,   533,   482,   534,   482,   533,   482,   533,
     482,   512,   481,    -1,   268,   480,   512,   481,    -1,   269,
     480,   512,   481,    -1,    44,   480,   507,   481,    -1,    12,
      -1,    12,   480,   534,   482,   533,   482,   533,   482,   533,
     481,    -1,    12,   480,   534,   482,   533,   482,   533,   482,
     533,   482,   533,   481,    -1,    12,   480,   534,   482,   533,
     482,   535,   481,    -1,   535,    -1,   535,   483,   533,   484,
      -1,   221,   480,   554,   482,   533,   481,    -1,   222,   480,
     554,   482,   533,   481,    -1,   223,   480,   554,   482,   533,
     481,    -1,   224,   480,   554,   482,   554,   482,   533,   481,
      -1,   225,   480,   554,   482,   554,   482,   533,   481,    -1,
     106,   480,   554,   482,   554,   481,    -1,   110,   480,   535,
     482,    28,   481,    -1,   110,   480,   535,   482,    28,   482,
     534,   481,    -1,   110,   480,   535,   482,   535,   482,    28,
     481,    -1,   110,   480,   535,   482,   535,   482,    28,   482,
     534,   481,    -1,   110,   480,   535,   482,   535,   482,   535,
     482,    28,   481,    -1,   110,   480,   535,   482,   535,   482,
     535,   482,    28,   482,   534,   481,    -1,   111,   480,   554,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     454,   485,   455,   480,   535,   482,   533,   482,   533,   481,
      -1,   301,   480,   535,   481,    -1,   130,   480,   535,   482,
     533,   482,   533,   482,   533,   481,    -1,   302,   480,   535,
     481,    -1,   205,   480,   554,   482,   533,   481,    -1,   206,
     480,   535,   481,    -1,   207,   480,   535,   481,    -1,   208,
     480,   535,   481,    -1,   209,   480,   535,   482,   535,   482,
     533,   482,   533,   482,   533,   481,    -1,   210,   480,   535,
     481,    -1,   211,   480,   535,   482,   535,   482,   535,   482,
     533,   482,   535,   481,    -1,   212,   480,   535,   482,   535,
     482,   535,   482,   533,   482,   535,   481,    -1,   213,   480,
     535,   482,   535,   482,   535,   482,   533,   482,   535,   482,
     533,   482,   533,   481,    -1,   214,   480,   535,   482,   535,
     482,   535,   482,   533,   482,   535,   482,   533,   482,   533,
     482,   533,   482,   533,   481,    -1,   215,   480,   535,   482,
     535,   482,   535,   482,   535,   481,    -1,   215,   480,   535,
     482,   535,   482,   535,   482,   535,   482,   533,   481,    -1,
     216,   480,   535,   481,    -1,   216,   480,   535,   482,   535,
     481,    -1,   217,   480,   535,   482,   535,   481,    -1,   112,
     480,   554,   482,   533,   481,    -1,   113,   480,   535,   481,
      -1,   129,   480,   535,   481,    -1,   114,   480,   535,   482,
     533,   481,    -1,   232,   480,   535,   481,    -1,   115,   480,
     535,   482,   533,   481,    -1,   116,   480,   535,   482,   533,
     481,    -1,   119,   480,   554,   482,   533,   481,    -1,   535,
     483,   578,   484,    -1,   535,   483,   486,   482,   486,   482,
     533,   486,   533,   484,    -1,   117,   480,   535,   482,   533,
     482,   533,   482,   533,   482,   533,   482,   533,   482,   533,
     481,    -1,   121,   480,   535,   482,   533,   482,   533,   482,
     533,   481,    -1,   121,   480,   535,   482,   533,   482,   533,
     481,    -1,   121,   480,   535,   482,   533,   482,   533,   482,
     533,   482,   533,   481,    -1,   122,   480,   535,   482,   533,
     482,   533,   482,   533,   481,    -1,   122,   480,   535,   482,
     533,   482,   533,   481,    -1,   122,   480,   535,   482,   533,
     482,   533,   482,   533,   482,   533,   481,    -1,   123,   480,
     535,   482,   533,   482,   533,   481,    -1,   123,   480,   535,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     124,   480,   535,   482,   533,   482,   533,   481,    -1,   124,
     480,   535,   482,   533,   482,   533,   482,   533,   482,   533,
     481,    -1,   125,   485,    26,    -1,   125,   485,    27,    -1,
     135,   485,   180,   480,   535,   482,   533,   481,    -1,   135,
     485,   180,   480,   535,   482,   535,   481,    -1,   135,   485,
      26,    -1,   135,   485,   145,   480,   535,   481,    -1,   125,
     480,   535,   482,   533,   482,   533,   482,   533,   482,   533,
     481,    -1,   169,   480,   535,   482,   535,   482,   533,   482,
     533,   482,   533,   481,    -1,   127,   480,   535,   482,   533,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     126,   480,   535,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   170,   485,   180,   480,   535,   482,   533,
     482,   533,   482,   533,   481,    -1,   171,   485,   180,   480,
     535,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   172,   480,   535,   481,    -1,   173,   480,
     535,   482,   533,   482,   533,   481,    -1,   173,   480,   535,
     482,   533,   482,   533,   482,   578,   481,    -1,   173,   480,
     535,   482,   533,   482,   533,   482,   533,   482,   578,   481,
      -1,   174,   480,   535,   482,   533,   482,   533,   482,   578,
     481,    -1,   174,   480,   535,   482,   533,   482,   533,   482,
     533,   482,   578,   481,    -1,   175,   480,   535,   482,   533,
     482,   533,   482,   578,   481,    -1,   176,   480,   535,   482,
     533,   482,   533,   482,   533,   482,   578,   481,    -1,   177,
     480,   535,   482,   533,   482,   533,   482,   533,   482,   578,
     481,    -1,   178,   480,   535,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   578,   481,    -1,   179,   480,   535,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     184,   480,   535,   482,   533,   482,   533,   481,    -1,   219,
     480,   535,   482,   533,   482,   533,   482,   533,   482,   533,
     482,   533,   481,    -1,   383,   480,   535,   481,    -1,   384,
     480,   535,   481,    -1,   385,   480,   535,   481,    -1,   386,
     480,   535,   481,    -1,    39,   485,   304,    -1,    39,   485,
     305,    -1,    37,   485,   304,    -1,   241,   480,   535,   482,
     533,   481,    -1,   242,   480,   535,   482,   533,   481,    -1,
     243,   480,   535,   482,   533,   481,    -1,   244,   480,   535,
     482,   533,   481,    -1,   167,   480,   554,   482,   554,   482,
     533,   481,    -1,   168,   480,   554,   482,   554,   482,   533,
     482,   533,   482,   533,   482,   533,   481,    -1,   167,   480,
     554,   482,   554,   482,   533,   482,   533,   482,   533,   481,
      -1,   167,   480,   554,   482,   554,   482,   533,   482,   533,
     482,   533,   482,   533,   481,    -1,   167,   480,   554,   482,
     554,   482,   535,   482,   533,   482,   533,   481,    -1,   270,
     480,   535,   482,   535,   481,    -1,   271,   480,   535,   482,
     535,   482,   554,   481,    -1,   275,   480,   535,   482,   533,
     482,   533,   482,   533,   481,    -1,   276,   480,   535,   482,
     533,   482,   533,   482,   533,   481,    -1,   276,   480,   535,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     277,   480,   535,   482,   533,   481,    -1,   278,   480,   535,
     482,   533,   481,    -1,   279,   480,   535,   482,   533,   481,
      -1,   280,   480,   535,   482,   533,   481,    -1,   281,   480,
     535,   482,   533,   481,    -1,   282,   480,   535,   482,   533,
     481,    -1,   283,   480,   535,   482,   533,   481,    -1,   284,
     480,   535,   482,   533,   481,    -1,   284,   480,   535,   482,
     533,   482,   533,   481,    -1,   285,   480,   535,   482,   533,
     482,   533,   482,   533,   481,    -1,   286,   480,   554,   481,
      -1,   535,   480,   554,   481,    -1,   400,   480,   554,   482,
     533,   482,   533,   482,   533,   481,    -1,   401,   480,   554,
     482,   533,   482,   533,   482,   533,   481,    -1,   448,   480,
     554,   481,    -1,   448,   480,   554,   482,   533,   481,    -1,
     451,   480,   554,   482,   533,   481,    -1,   449,   480,   554,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     450,   480,   535,   482,   535,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   481,
      -1,   453,   480,   554,   482,   533,   482,   533,   481,    -1,
     574,   485,   338,   480,   481,    -1,   574,   485,   339,   480,
     481,    -1,   574,   485,   340,   480,   481,    -1,   574,   485,
     337,   480,   535,   481,    -1,   459,   480,   554,   482,   533,
     481,    -1,   459,   480,   554,   481,    -1,   460,   480,   554,
     482,   533,   481,    -1,   460,   480,   554,   481,    -1,   465,
     480,   554,   482,   554,   481,    -1,   466,   480,   554,   481,
      -1,   467,   480,   512,   481,    -1,   439,   480,   554,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   482,   533,   481,    -1,   249,   480,   574,   482,   535,
     482,   554,   481,    -1,   251,   480,   574,   482,   512,   481,
      -1,   536,    -1,   480,   554,   481,    -1,   537,    -1,   538,
      -1,   519,   540,    -1,   489,   540,    -1,   488,   540,    -1,
     410,   540,    -1,   411,   540,    -1,   421,   540,    -1,   422,
     540,    -1,   423,   540,    -1,   424,   540,    -1,   412,   540,
      -1,   413,   540,    -1,   414,   540,    -1,   415,   540,    -1,
     418,   540,    -1,   420,   540,    -1,   419,   540,    -1,   425,
     540,    -1,   539,    -1,   480,   534,   481,   539,    -1,   540,
      -1,   541,   491,   520,    -1,   541,   493,   520,    -1,   541,
     491,   540,    -1,   541,   493,   540,    -1,   541,   496,   540,
      -1,   541,    -1,   542,    -1,   543,   488,   521,    -1,   543,
     489,   521,    -1,   543,   488,   541,    -1,   543,   489,   541,
      -1,   543,    -1,   544,    -1,   545,   494,   544,    -1,   545,
     495,   544,    -1,   545,    98,   544,    -1,   545,    99,   544,
      -1,   545,   494,   523,    -1,   545,   495,   523,    -1,   545,
      98,   523,    -1,   545,    99,   523,    -1,   545,    -1,   546,
     100,   545,    -1,   546,   101,   545,    -1,   546,   100,   523,
      -1,   546,   101,   523,    -1,   546,    -1,   547,   487,   546,
      -1,   547,    -1,   548,    -1,   549,   497,   548,    -1,   549,
      -1,   550,    96,   549,    -1,   550,    -1,   551,    97,   550,
      -1,   551,    -1,   551,   498,   551,   486,   552,    -1,   552,
      -1,   539,   104,   553,    -1,   553,    -1,    47,    -1,    39,
     485,   356,    -1,   358,   480,    47,   482,    47,   482,   533,
     481,    -1,    14,   480,   512,   481,    -1,   359,   480,   533,
     482,   533,   481,    -1,    40,    -1,   360,   480,   573,   481,
      -1,   556,    -1,   480,   573,   481,    -1,   557,    -1,   558,
      -1,   519,   560,    -1,   489,   560,    -1,   488,   560,    -1,
     560,   102,    -1,   410,   560,    -1,   411,   560,    -1,   421,
     560,    -1,   422,   560,    -1,   423,   560,    -1,   424,   560,
      -1,   412,   560,    -1,   413,   560,    -1,   414,   560,    -1,
     415,   560,    -1,   418,   560,    -1,   420,   560,    -1,   419,
     560,    -1,   559,    -1,   560,    -1,   561,   491,   520,    -1,
     561,   103,   560,    -1,   561,   491,   560,    -1,   561,    -1,
     562,   488,   521,    -1,   562,   489,   521,    -1,   562,   488,
     561,    -1,   562,   489,   561,    -1,   562,    -1,   563,    -1,
     564,    -1,   565,    -1,   566,    -1,   567,    -1,   568,    -1,
     569,    -1,   570,    -1,   571,    -1,   572,    -1,    38,    -1,
      48,   483,   533,   484,    -1,   291,   480,   554,   482,   533,
     481,    -1,   294,   480,   535,   482,   533,   481,    -1,   291,
     480,   554,   482,   533,   482,   535,   481,    -1,   300,   480,
     554,   482,   533,   482,   554,   481,    -1,   295,   480,   574,
     481,    -1,   295,   480,   574,   482,   533,   481,    -1,   296,
     480,   535,   482,   533,   481,    -1,   297,   480,   574,   482,
     533,   481,    -1,   299,   480,   574,   482,   533,   481,    -1,
     303,   480,   481,    -1,   303,    28,    -1,   303,   480,   512,
     481,    -1,   303,    -1,   250,   480,   512,   481,    -1,   250,
     480,   512,   482,   533,   481,    -1,   574,    -1,   236,   480,
     535,   481,    -1,   237,   480,   574,   481,    -1,   237,   480,
     574,   482,   533,   482,   533,   482,   533,   481,    -1,   238,
     480,   574,   482,   533,   481,    -1,   245,   480,   574,   482,
     533,   482,   533,   482,   533,   482,   533,   482,   533,   482,
     533,   481,    -1,   246,   480,   554,   482,   533,   482,   533,
     482,   533,   482,   533,   482,   533,   482,   533,   482,   533,
     481,    -1,   247,   480,   554,   482,   533,   482,   533,   482,
     533,   481,    -1,   248,   480,   554,   482,   533,   482,   533,
     482,   533,   482,   533,   482,   533,   482,   533,   482,   533,
     482,   533,   481,    -1,   574,   485,   240,   480,   533,   482,
     533,   481,    -1,   456,   480,   554,   481,    -1,   456,   480,
     554,   482,   533,   481,    -1,   456,   480,   554,   482,   533,
     482,   533,   481,    -1,   458,   480,   554,   482,   533,   482,
     533,   481,    -1,   457,   480,   554,   482,   533,   482,   533,
     482,   554,   482,   554,   481,    -1,   457,   480,   554,   482,
     533,   482,   533,   482,   554,   482,   554,   482,   554,   482,
     533,   481,    -1,   462,   480,   554,   482,   554,   482,   554,
     482,   533,   482,   533,   482,   533,   482,   533,   481,    -1,
     462,   480,   554,   482,   554,   482,   554,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   481,    -1,   462,
     480,   554,   482,   554,   482,   554,   482,   533,   482,   533,
     482,   533,   481,    -1,   462,   480,   554,   482,   533,   482,
     533,   482,   533,   482,   533,   482,   533,   481,    -1,   464,
     480,   554,   482,   554,   482,   554,   482,   533,   482,   533,
     482,   533,   482,   533,   481,    -1,   464,   480,   554,   482,
     554,   482,   554,   482,   533,   482,   533,   482,   533,   482,
     533,   482,   554,   482,   554,   481,    -1,    31,    -1,    34,
      -1,    33,    -1,   535,    -1,    37,    -1,    38,    -1,    39,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    36,    -1,    40,    -1,    47,    -1,    46,    -1,    48,
      -1,    49,    -1,   533,   486,   533,   482,   533,   486,   533,
     482,   533,   486,   533,    -1,   533,   486,   533,   482,   533,
     486,   533,    -1,   535,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   934,   934,   934,   935,   939,   943,   943,   944,   944,
     945,   945,   946,   946,   949,   953,   957,   986,  1012,  1037,
    1057,  1088,  1111,  1133,  1177,  1221,  1237,  1245,  1249,  1263,
    1277,  1291,  1301,  1313,  1332,  1342,  1352,  1362,  1374,  1385,
    1400,  1424,  1436,  1447,  1452,  1462,  1487,  1499,  1517,  1539,
    1547,  1555,  1563,  1572,  1603,  1619,  1624,  1628,  1632,  1637,
    1641,  1645,  1650,  1689,  1709,  1738,  1755,  1768,  1788,  1801,
    1836,  1866,  1884,  1888,  1892,  1896,  1900,  1904,  1908,  1912,
    1916,  1920,  1925,  1929,  1938,  1947,  1954,  1963,  1977,  2225,
    2279,  2287,  2296,  2306,  2312,  2318,  2325,  2331,  2341,  2351,
    2369,  2381,  2391,  2440,  2455,  2476,  2507,  2522,  2529,  2536,
    2554,  2577,  2582,  2587,  2600,  2611,  2620,  2629,  2637,  2654,
    2670,  2687,  2707,  2722,  2740,  2753,  2767,  2776,  2790,  2801,
    2814,  2832,  2854,  2878,  2908,  2940,  2945,  2963,  2968,  2973,
    2978,  2983,  2988,  3002,  3017,  3034,  3048,  3068,  3073,  3078,
    3085,  3095,  3103,  3108,  3115,  3120,  3125,  3145,  3169,  3174,
    3179,  3184,  3189,  3194,  3199,  3204,  3209,  3214,  3219,  3224,
    3229,  3234,  3239,  3244,  3249,  3254,  3259,  3264,  3272,  3277,
    3282,  3287,  3292,  3297,  3302,  3307,  3312,  3317,  3322,  3327,
    3332,  3336,  3363,  3376,  3381,  3385,  3391,  3404,  3410,  3416,
    3422,  3429,  3436,  3443,  3454,  3465,  3480,  3495,  3503,  3512,
    3521,  3529,  3533,  3537,  3574,  3583,  3590,  3597,  3608,  3616,
    3634,  3644,  3649,  3656,  3663,  3671,  3679,  3698,  3714,  3731,
    3748,  3753,  3758,  3763,  3768,  3776,  3877,  3911,  3918,  3926,
    3932,  3939,  3949,  3958,  3965,  3972,  3982,  3989,  4003,  4017,
    4025,  4030,  4038,  4046,  4057,  4069,  4081,  4093,  4099,  4112,
    4119,  4130,  4152,  4178,  4206,  4216,  4229,  4239,  4252,  4281,
    4298,  4313,  4320,  4342,  4361,  4379,  4393,  4398,  4403,  4412,
    4417,  4426,  4440,  4447,  4454,  4460,  4477,  4493,  4527,  4540,
    4584,  4589,  4594,  4600,  4616,  4623,  4629,  4635,  4642,  4649,
    4655,  4661,  4667,  4673,  4679,  4691,  4697,  4714,  4721,  4732,
    4739,  4744,  4750,  4755,  4760,  4765,  4770,  4775,  4810,  4837,
    4844,  4866,  4870,  4877,  4884,  4892,  4900,  4909,  4916,  4923,
    4930,  4937,  4944,  4951,  4958,  4965,  4972,  4979,  4989,  4994,
    5000,  5006,  5012,  5018,  5024,  5030,  5036,  5042,  5048,  5055,
    5060,  5072,  5078,  5092,  5105,  5112,  5113,  5123,  5131,  5137,
    5148,  5149,  5152,  5157,  5165,  5173,  5183,  5188,  5194,  5200,
    5209,  5214,  5229,  5245,  5249,  5266,  5282,  5296,  5309,  5330,
    5389,  5408,  5425,  5432,  5440,  5445,  5450,  5478,  5484,  5495,
    5515,  5535,  5553,  5573,  5591,  5609,  5632,  5655,  5678,  5685,
    5710,  5733,  5740,  5750,  5760,  5770,  5780,  5790,  5800,  5814,
    5831,  5847,  5852,  5857,  5861,  5868,  5876,  5911,  5924,  5934,
    5951,  5970,  5986,  6004,  6024,  6045,  6058,  6071,  6079,  6087,
    6091,  6099,  6109,  6114,  6119,  6120,  6121,  6122,  6123,  6124,
    6125,  6126,  6127,  6135,  6136,  6137,  6138,  6139,  6140,  6141,
    6146,  6147,  6151,  6157,  6173,  6174,  6175,  6179,  6180,  6181,
    6185,  6193,  6194,  6195,  6196,  6197,  6201,  6202,  6203,  6204,
    6205,  6209,  6213,  6221,  6225,  6232,  6236,  6243,  6247,  6254,
    6258,  6265,  6266,  6273,  6277,  6286,  6291,  6295,  6299,  6303,
    6307,  6311,  6315,  6319,  6323,  6327,  6335,  6340,  6357,  6364,
    6371,  6430,  6485,  6542,  6564,  6586,  6600,  6630,  6639,  6659,
    6685,  6699,  6777,  6844,  6852,  6860,  6870,  6880,  6910,  6929,
    6950,  6969,  6990,  7009,  7029,  7070,  7086,  7101,  7118,  7141,
    7156,  7171,  7186,  7201,  7237,  7252,  7274,  7296,  7338,  7385,
    7403,  7423,  7438,  7453,  7468,  7488,  7504,  7520,  7538,  7560,
    7577,  7593,  7605,  7633,  7653,  7698,  7710,  7721,  7734,  7746,
    7757,  7783,  7810,  7842,  7859,  7877,  7890,  7903,  7923,  7946,
    7960,  7975,  8009,  8046,  8081,  8114,  8131,  8148,  8162,  8183,
    8206,  8230,  8255,  8280,  8302,  8324,  8348,  8391,  8415,  8447,
    8461,  8498,  8535,  8572,  8607,  8612,  8621,  8626,  8637,  8647,
    8657,  8666,  8687,  8717,  8745,  8776,  8811,  8822,  8838,  8848,
    8858,  8873,  8887,  8901,  8914,  8927,  8939,  8951,  8963,  8974,
    8987,  9014,  9047,  9155,  9179,  9221,  9234,  9245,  9254,  9278,
    9303,  9316,  9326,  9336,  9346,  9356,  9366,  9374,  9382,  9390,
    9417,  9438,  9446,  9484,  9507,  9527,  9527,  9529,  9531,  9532,
    9533,  9534,  9535,  9536,  9537,  9538,  9539,  9540,  9541,  9542,
    9543,  9544,  9545,  9546,  9547,  9548,  9564,  9565,  9589,  9590,
    9596,  9598,  9599,  9600,  9603,  9608,  9609,  9610,  9611,  9612,
    9615,  9619,  9620,  9621,  9622,  9623,  9624,  9625,  9626,  9627,
    9631,  9632,  9633,  9634,  9635,  9639,  9640,  9645,  9649,  9650,
    9654,  9655,  9659,  9660,  9664,  9665,  9669,  9670,  9673,  9677,
    9687,  9700,  9711,  9729,  9736,  9746,  9761,  9761,  9763,  9765,
    9766,  9767,  9768,  9769,  9778,  9779,  9780,  9781,  9782,  9783,
    9784,  9785,  9786,  9787,  9788,  9789,  9790,  9794,  9796,  9797,
    9798,  9799,  9809,  9810,  9811,  9812,  9813,  9816,  9820,  9824,
    9828,  9833,  9837,  9841,  9845,  9849,  9853,  9856,  9861,  9866,
    9883,  9895,  9907,  9919,  9952,  9961,  9970,  9979,  9988,  9997,
   10004, 10012, 10019, 10037, 10051, 10067, 10077, 10096, 10125, 10153,
   10169, 10187, 10222, 10255, 10302, 10329, 10339, 10362, 10374, 10387,
   10427, 10472, 10522, 10575, 10621, 10650, 10683, 10724, 10728, 10730,
   10732, 10736, 10738, 10740, 10742, 10744, 10746, 10748, 10750, 10752,
   10754, 10756, 10758, 10760, 10762, 10768, 10776, 10783, 10799
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_ERROR", "T_SetDebugOn",
  "T_SetDebugOff", "T_SetVerboseOn", "T_SetVerboseOff", "T_SetProgress",
  "T_argc", "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_ReadRawImages",
  "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE", "PRINT", "PRINTN",
  "T_SPRINT", "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetOutput",
  "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER", "IDENTIFIER",
  "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR", "VAR_STRING",
  "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE",
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_C_IMAGE_FUNCTION",
  "VAR_AMI_FUNCTION", "VAR_PARAMWIN", "VAR_GLTRANSFORM",
  "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del", "ENDOP", "T_global",
  "T_local", "T_global_new", "T_local_new", "T_wait", "T_schedule",
  "T_ParamWin", "T_BeginPanel", "T_EndPanel", "T_BeginBook", "T_EndBook",
  "T_AddPage", "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display",
  "T_AddButton", "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice",
  "T_AddString", "T_AddFilename", "T_ShowSlider", "T_SetCallback",
  "T_SetDragCallback", "T_BeginBox", "T_EndBox", "T_BeginHorizontal",
  "T_EndHorizontal", "T_redraw", "RIGHT_ASSIGN", "LEFT_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP", "INC_OP", "DEC_OP",
  "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP", "T_COUNT", "T_MAX",
  "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER", "NormGrad",
  "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2", "SubImage",
  "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
  "T_EDPerode", "T_EDPopen", "T_EDPclose", "AnisoGS", "AnisoSmoothGS",
  "T_vtkAnisoGS", "T_SetDistMap", "T_DiscMeanCurvature", "T_vtkMedian3D",
  "T_NULL", "T_InitTime", "T_TimeSpent", "T_EndTime", "T_LevelSetsCURV",
  "T_UpdateResult", "T_SetMeanCurv", "T_SetAffineCurv",
  "T_SetBalloonScheme", "T_SetVelocity", "T_SetExpansion",
  "T_SetExpansionImage", "T_SetAdvectionField", "T_SetCurvWeights",
  "T_GetAttachVect", "T_GetCurvature", "T_GetDistMap", "T_GetAdvection",
  "T_GetVelocity", "T_GetExpansion", "T_GetSkeleton", "T_SetDistMethod",
  "T_SetParam", "T_SetIsoContourBin", "T_SetBandTube", "T_SetThreads",
  "T_SaveDistMap", "T_SaveSecDerGrad", "T_SetNumGaussians",
  "T_SetGaussian", "T_SetProbThreshold", "T_SetILowTh", "T_SetIHighTh",
  "T_SetProbHighTh", "T_SetNumInitPoints", "T_SetInitPoint",
  "T_vtkFastMarching", "T_vtkFastMarchingTarget", "T_FluxDiffusion",
  "T_AnisoWeickert", "T_AnisoCW", "T_SRAD_qcoeff", "T_AnisoSRAD",
  "T_AnisoSRAD2", "T_AnisoLeeAdd2", "T_AnisoDPAD", "T_AnisoDPAD2",
  "T_AnisoNRAD", "T_AnisoRudinMult", "TInit", "TSetCoeff", "TIterate",
  "TEnd", "TAddGaussNoise", "T_SNR", "T_SetNoiseType", "T_SetNoiseSD",
  "T_GetNoiseSD", "T_GetDAcoeff", "T_SetMask", "T_SetSRADROI",
  "T_SetRNRADROI", "T_SetRNRADROI_NEW", "T_SetLocalStruct",
  "T_SetEigenMode", "T_Setdt", "T_Setneighborhood", "T_info", "T_NbPoints",
  "T_NbPolys", "T_save", "T_normalize", "T_OrientField",
  "T_OrientPositive", "T_2DFlux", "T_OutFlux", "T_OutFluxScalar",
  "T_OrientationRatio", "T_Skeleton", "T_SimplePoints", "T_CircleIntegral",
  "T_CircleIntegralExc", "T_CircleIntSdExc", "T_CircleMinIntSdExc",
  "T_LocalExtrema", "T_NormalField", "T_DirConnectivity", "T_eccentricity",
  "T_rot2D", "T_mean", "T_SUM", "T_localmean", "T_localmean2", "T_localSD",
  "T_localSD2", "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix",
  "T_HessianEVal", "T_Derivatives", "T_curvatures", "T_Laplacian",
  "T_setvoxelsize", "T_settranslation", "T_setendianness",
  "T_Skeleton2lines", "T_SmoothLines", "T_ResampleLines", "T_RemoveLine",
  "T_ConnectLines", "T_threscross", "T_IsocontourPoints", "T_IsosurfDist",
  "T_vtkIsoContourDist", "T_ShortestPath", "T_ShortestPathImage",
  "T_PathFromDispl", "T_PathFromVectField", "T_LineRecons",
  "T_ReadCTALine", "T_ReadCTALineRadii", "T_WriteCTALine",
  "T_SetIsoContour", "T_SetIsoContourParam", "T_DrawIsoContour",
  "T_SetIsoContourColor", "T_DrawAllContours", "T_AllContoursParam",
  "T_GetZmin", "T_GetZmax", "T_GetYmin", "T_GetYmax", "T_GetXmin",
  "T_GetXmax", "T_GetXPos", "T_GetYPos", "T_GetZPos", "T_vtkDicomRead",
  "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask", "T_Pad", "T_Eigen2D",
  "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT", "T_BorgeforsDT",
  "T_BorgeforsSDT", "T_vtkSignedBorgefors", "T_vtkSignedFMDist",
  "T_PropagationDist", "T_PropagationDist2", "T_PropDanielsson",
  "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents",
  "T_ProcessEvents", "T_isoarea2D", "T_posarea", "T_isosurf",
  "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate",
  "T_vtkMarchingCubes", "T_vtkSmooth", "T_Recompute", "T_vtkWindowedSinc",
  "T_isoline", "T_vtkDist", "T_AndreDist", "T_Surface", "T_getimage",
  "T_GetImageFromX", "T_rotate", "T_computeCC", "T_drawCC", "T_setminCC",
  "T_addobj", "T_setcurrentobj", "T_writeVRML", "T_writeVTK",
  "T_OwnMaterial", "T_SetColor", "T_SetColors", "T_SetColorOpacity",
  "T_Paint", "T_SetLight", "T_SetLightPos", "T_SetLightAmbient",
  "T_SetLightDiffuse", "T_SetLightSpecular", "T_SetBackground", "T_Remove",
  "T_SwapBuffers", "T_SetAmbient", "T_SetDiffuse", "T_SetSpecular",
  "T_SetShininess", "T_SetOpacity", "T_SetOpacityImage", "T_SetVisible",
  "T_SetColorMaterial", "T_penguin", "T_Statistics", "T_GetIntensities",
  "T_GetLinesLength", "T_GetLinesExtremities", "T_GetConnections",
  "T_SelectLines", "T_RemoveSelection", "T_mergepoints", "T_Triangulate",
  "T_Displace", "T_Normals", "T_InvertNormals", "T_Translate", "T_Scale",
  "T_SetPointsColors", "T_SetLineWidth", "T_AddPoint", "T_NewLine",
  "T_EndLine", "T_LineAddPointNumber", "T_GetTransform", "T_SetTransform",
  "T_Interpolate", "T_Matrix", "T_Invert", "T_PrintMatrices", "SET",
  "SETPOS", "SHOWCURSOR", "UPDATE", "COMPARE", "SETVECTOR",
  "T_SetCompareDisplacement", "T_DrawVector", "T_DisplayVectors",
  "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
  "T_SetLineThickness", "T_SetZoom", "T_SetWindowSize", "T_SetColormap",
  "T_drawcircle", "T_setGLwin", "T_initvalue", "T_ShowSection",
  "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos", "T_SpacePos", "T_CHAR",
  "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT", "T_UINT", "T_FLOAT",
  "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR", "T_GetFormat", "T_atof",
  "T_gnuplot", "T_histo", "T_cumhisto", "T_DisplayHisto", "T_OPEN",
  "T_CLOSE", "T_scan_float", "T_read", "T_rewind", "T_LineNumber",
  "CONST_PI", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH",
  "EXP", "LN", "LOG", "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO",
  "STEP", "ENDFOR", "T_REPEAT", "T_UNTIL", "T_BREAK", "IF", "THEN", "ELSE",
  "VARIABLES", "FUNCTION", "T_exists", "T_slice", "T_GenRead", "T_IMAGE",
  "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING", "T_TRANSFORM", "T_PROC",
  "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf",
  "T_ConvexHull", "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh",
  "T_CreateVolume", "T_vtkCreateFlatMesh", "T_Altitude2Position",
  "T_GeoCoordinates", "T_ElevateMesh", "T_CreateVectors",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_PaintCallback", "T_SaveStructuredGrid",
  "T_import_ami", "T_import_vtk", "T_import_itk", "T_import_wii",
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "';'", "'('", "')'",
  "','", "'['", "']'", "'.'", "':'", "'&'", "'+'", "'-'", "'!'", "'*'",
  "'~'", "'/'", "'<'", "'>'", "'^'", "'|'", "'?'", "$accept",
  "list_commands", "end_instr", "loop_inst", "cond_inst", "proc_decl",
  "func_inst", "command", "param_list", "param_list_decl",
  "primary_expr_string", "postfix_expr_string", "additive_expr_string",
  "expr_string", "instr_block", "begin_block", "end_block", "primary_expr",
  "postfix_expr", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "and_expr", "exclusive_or_expr", "inclusive_or_expr",
  "logical_and_expr", "logical_or_expr", "conditional_expr",
  "assignment_expr", "expr", "basic_type", "var_image", "image",
  "primary_image", "postfix_image", "unary_image", "cast_image",
  "multiplicative_image", "additive_image2", "additive_image",
  "shift_image", "relational_image", "equality_image", "and_image",
  "exclusive_or_image", "inclusive_or_image", "logical_and_image",
  "logical_or_image", "conditional_image", "assignment_image",
  "expr_image", "gltransform", "matrix", "primary_matrix",
  "postfix_matrix", "unary_matrix", "cast_matrix", "multiplicative_matrix",
  "additive_matrix", "shift_matrix", "relational_matrix",
  "equality_matrix", "and_matrix", "exclusive_or_matrix",
  "inclusive_or_matrix", "logical_and_matrix", "logical_or_matrix",
  "conditional_matrix", "assignment_matrix", "expr_matrix", "var_surface",
  "surface", "identifier", "variable", "image_extent", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,    59,
      40,    41,    44,    91,    93,    46,    58,    38,    43,    45,
      33,    42,   126,    47,    60,    62,    94,   124,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   499,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   501,   501,   502,   502,   502,   503,
     503,   504,   505,   505,   505,   505,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   509,
     509,   510,   510,   510,   510,   511,   511,   511,   512,   513,
     514,   515,   516,   516,   516,   516,   516,   516,   516,   516,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     519,   519,   520,   520,   521,   521,   521,   522,   522,   522,
     523,   524,   524,   524,   524,   524,   525,   525,   525,   525,
     525,   526,   526,   527,   527,   528,   528,   529,   529,   530,
     530,   531,   531,   532,   533,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   535,   535,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   537,   537,   538,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   540,   540,   541,   541,
     541,   541,   541,   541,   542,   543,   543,   543,   543,   543,
     544,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     546,   546,   546,   546,   546,   547,   547,   548,   549,   549,
     550,   550,   551,   551,   552,   552,   553,   553,   554,   555,
     555,   555,   555,   556,   556,   556,   557,   557,   558,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   560,   561,   561,
     561,   561,   562,   562,   562,   562,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   574,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   576,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   578,   578,   578,   578
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     8,    10,     2,     4,
       6,     7,     3,     1,     5,     2,     1,     1,     1,     1,
       1,     1,     4,     6,     6,     6,     6,     3,     3,     6,
       6,     3,     3,     3,     3,     6,     3,     3,     6,     6,
       6,     3,     3,     8,     8,     3,     1,     1,     1,     1,
       4,     1,     2,     2,     2,     1,     3,     3,     3,     6,
       6,    16,     2,     2,     3,     2,     2,     3,     3,     2,
       2,     3,     2,     2,     5,     2,     1,     1,     2,     2,
       4,     2,     2,     2,     1,     4,     3,     2,     2,    10,
       6,     3,     6,     6,     8,    28,     8,     8,     3,     8,
      12,     6,     6,    16,     8,    16,    10,     6,    10,     8,
      10,    14,     8,    12,     6,     8,     6,     6,     6,    10,
       6,    10,    10,    12,     6,     6,    12,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     8,
       3,     3,     3,     3,     3,     3,    12,    16,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,    10,     6,
      14,     6,     8,     6,     6,     8,     6,    10,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     3,
       3,     4,     3,     6,     6,     4,     4,     6,    10,    10,
      10,     6,     6,     6,     6,     6,    10,     6,    10,     6,
       6,     6,     3,     6,     6,    10,    10,     6,     6,     6,
       3,     3,     3,     3,     6,     6,     3,     6,     6,     8,
      10,     3,     6,     3,     4,    20,     6,    10,     6,     3,
       3,     6,     3,     6,     8,     6,     6,     8,    16,     6,
       3,     6,     8,     3,    12,    12,    12,    10,     8,     8,
      10,     8,    10,    12,     6,     8,     8,    10,    16,    18,
      12,     6,    18,    16,    12,    10,    10,    10,     6,    10,
       6,     6,     6,     8,     1,     4,     4,     8,     4,    18,
       4,     1,     1,     6,     6,     3,     3,     6,     6,     3,
       3,     3,     3,     3,     3,     3,     8,     6,     6,     6,
       3,     4,     1,     1,     1,     1,     1,    30,    24,     4,
       8,     0,     1,     3,     1,     3,     2,     4,     2,     4,
       1,     3,     2,     4,     2,     4,     1,     3,     0,     2,
       2,     2,     2,     2,     4,     4,     4,     4,     4,     1,
       1,     1,     6,     1,     3,     1,     3,     3,     1,     3,
       0,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     6,     8,    10,    10,     8,     6,     3,     3,
       3,     3,     3,     3,     6,     4,    10,     4,    10,     4,
       4,     4,     4,     4,     4,     7,     7,     7,     9,     7,
       6,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     8,    10,    10,     8,     6,
       8,     6,     8,     8,    12,     3,     6,     4,     4,     1,
       6,     6,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     2,     4,
      16,    14,    16,     4,     4,     4,     1,    10,    12,     8,
       1,     4,     6,     6,     6,     8,     8,     6,     6,     8,
       8,    10,    10,    12,    12,    10,     4,    10,     4,     6,
       4,     4,     4,    12,     4,    12,    12,    16,    20,    10,
      12,     4,     6,     6,     6,     4,     4,     6,     4,     6,
       6,     6,     4,    10,    16,    10,     8,    12,    10,     8,
      12,     8,    12,     8,    12,     3,     3,     8,     8,     3,
       6,    12,    12,    14,    12,    12,    16,     4,     8,    10,
      12,    10,    12,    10,    12,    12,    14,    12,     8,    14,
       4,     4,     4,     4,     3,     3,     3,     6,     6,     6,
       6,     8,    14,    12,    14,    12,     6,     8,    10,    10,
      12,     6,     6,     6,     6,     6,     6,     6,     6,     8,
      10,     4,     4,    10,    10,     4,     6,     6,    12,    30,
       8,     5,     5,     5,     6,     6,     4,     6,     4,     6,
       4,     4,    18,     8,     6,     1,     3,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     4,     1,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       3,     8,     4,     6,     1,     4,     1,     3,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     6,     8,     8,     4,     6,     6,     6,     6,     3,
       2,     4,     1,     4,     6,     1,     4,     4,    10,     6,
      16,    18,    10,    20,     8,     4,     6,     8,     8,    12,
      16,    16,    18,    14,    14,    16,    20,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,    11,     7,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    56,    57,    58,    59,     0,   363,    26,    14,     0,
      87,    61,     0,     0,     0,     0,     0,    86,   349,   362,
     797,   496,   366,   367,   368,   350,     0,   758,     0,   714,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    31,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   353,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,     0,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
     364,   365,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   360,    27,     0,    23,
       0,     0,     0,     0,     0,     0,     0,   312,   313,   314,
     315,   316,     0,     0,    15,     0,     0,     0,     0,   450,
     451,     0,     2,     6,     8,    12,    10,     0,   351,   355,
     358,     0,   370,   432,   452,     0,   454,   457,   460,   461,
     466,   471,   473,   475,   477,   479,   481,   483,   484,   284,
     429,     0,   716,   718,   719,   737,   738,   742,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,   757,    94,
       0,     0,     0,     0,     0,    82,    62,    64,    89,    88,
      63,   366,   367,   368,   350,     0,   714,     0,     0,     0,
       0,    91,    97,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    98,     0,    85,     0,    72,
      73,     0,    75,    76,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,   321,    25,
       0,     0,     0,     0,     0,   799,   798,   809,   801,   802,
     803,   810,   804,   805,   806,   807,   808,   812,   811,   813,
     814,   800,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   437,     0,   724,   438,   725,   443,   730,   444,   731,
     445,   732,   446,   733,   447,   734,   449,   736,   448,   735,
     439,   726,   440,   727,   441,   728,   442,   729,     0,    18,
       0,   360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,     0,   436,   722,   435,   721,   434,
       1,     3,     7,     9,    13,    11,     0,     4,     0,     0,
       0,     0,   433,   720,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    77,    78,
      81,     0,     0,     0,     0,     0,     0,   406,   407,   404,
     405,   402,   403,   408,   409,   410,     0,     0,     0,   101,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,     0,     0,
       0,     0,   253,     0,     0,     0,     0,     0,   242,     0,
     250,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,    96,     0,     0,    55,   506,     0,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,     0,   322,   510,   645,
     647,   648,   666,   668,   674,   675,   680,   681,   690,   695,
     697,   698,   700,   702,   704,   706,   708,   330,     0,     0,
       0,   299,   295,   296,     0,     0,     0,   303,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   300,
     301,   302,   305,   425,   310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,     0,
       0,   411,   412,     0,     0,     0,     0,     0,     0,     0,
       0,   413,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,   190,   152,   153,   154,   155,     0,     0,   510,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   361,     0,    22,   813,     0,     0,     0,   338,
       0,     0,     0,     0,     0,     0,   369,     0,   717,     5,
     356,   357,   469,   470,   455,   456,   458,   459,   464,   465,
     462,   463,   467,   468,   472,   474,   476,   478,   480,     0,
      67,     0,    68,    66,     0,     0,     0,   354,     0,   378,
     380,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   379,   740,   739,   741,   743,   745,   744,   746,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   772,     0,     0,     0,     0,
       0,   775,    47,   381,   382,   383,     0,     0,     0,     0,
     226,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,   212,     0,   222,   223,     0,     0,     0,     0,     0,
     231,   233,     0,     0,     0,    38,   506,     0,     0,     0,
     709,     0,   772,     0,   486,   489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,    51,    37,    42,    41,   775,
      46,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    95,     0,
       0,   498,     0,     0,     0,     0,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   510,   666,   652,   653,   658,   659,   660,   661,
     662,   664,   663,   654,   655,   656,   657,   665,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,   326,   328,   332,   334,   651,   650,   319,     0,
     649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   311,     0,   759,
     497,     0,    32,     0,     0,     0,     0,     0,     0,   510,
       0,   389,     0,   391,     0,   392,   393,     0,   394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   385,     0,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,   286,
       0,     0,   387,     0,   715,   401,     0,   288,     0,   359,
     360,    19,   427,   428,   290,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,     0,     0,     0,   453,     0,
       0,   371,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   770,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   321,     0,     0,     0,     0,     0,     0,
       0,   759,   497,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   596,   594,   595,     0,   510,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   565,   566,     0,     0,     0,     0,
     569,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     646,   337,     0,   325,   323,   331,     0,   818,     0,     0,
     817,     0,   707,   669,   671,   670,   672,   673,   676,   678,
     677,   679,   688,   684,   689,   685,   686,   682,   687,   683,
     693,   691,   694,   692,   696,   699,   701,   703,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   341,   342,   343,   339,   340,   360,
       0,     0,     0,     0,     0,     0,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   769,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,     0,     0,
       0,   124,     0,   127,     0,   100,   103,   102,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,     0,   117,
       0,   126,     0,   243,     0,   238,   245,     0,     0,     0,
       0,   241,     0,   251,     0,   246,     0,     0,     0,   249,
     414,     0,   430,   431,   499,     0,     0,     0,   505,     0,
       0,     0,     0,   545,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   530,   531,   532,     0,   534,
       0,     0,     0,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,   548,     0,     0,     0,     0,     0,
       0,   503,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   621,   526,   528,   590,
     591,   592,   593,     0,     0,     0,   625,     0,     0,     0,
       0,     0,     0,   636,     0,   638,     0,     0,   640,   641,
       0,   667,   327,   329,   333,   335,   622,     0,   511,     0,
     552,     0,     0,     0,     0,     0,   298,   297,     0,     0,
       0,   419,   421,     0,     0,     0,     0,     0,   307,   308,
     294,   426,    48,    45,    40,    33,     0,     0,     0,     0,
     282,     0,   138,     0,   137,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   158,   159,   160,     0,
     173,   174,     0,   176,   184,   178,   179,   185,   180,   186,
     182,   183,   181,   161,     0,   171,     0,   162,   187,   188,
     167,     0,   163,   164,   165,   166,   169,     0,   384,   400,
       0,     0,     0,   264,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,   713,     0,   360,    20,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,     0,   377,
       0,   372,     0,     0,    70,    69,   135,   134,     0,   193,
     194,     0,   278,     0,   280,   281,   130,     0,     0,   128,
       0,   776,   777,     0,     0,     0,     0,     0,     0,   773,
       0,     0,     0,   764,     0,     0,     0,     0,     0,   771,
     785,     0,     0,     0,     0,     0,     0,   213,   218,   224,
     225,   228,     0,   227,   197,     0,   209,     0,   205,     0,
       0,     0,   201,   202,   203,   204,   210,   219,   211,   214,
       0,     0,   207,   217,     0,   232,   236,    35,    36,   712,
      39,   293,    34,     0,    50,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   705,
       0,   631,   632,   633,     0,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,   346,   347,   348,   344,   345,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,   122,     0,   125,     0,   106,
     104,   107,   109,     0,     0,   114,     0,     0,     0,     0,
     244,     0,     0,     0,     0,   252,   247,   258,     0,   415,
      54,     0,     0,   517,   518,     0,     0,     0,   544,   547,
     549,   550,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,   570,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,     0,   542,   543,     0,   512,   513,   514,
       0,     0,   597,   598,   599,   600,     0,   644,   606,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,     0,     0,     0,   626,     0,     0,   627,     0,
       0,   635,   637,   639,     0,     0,   634,     0,     0,   418,
     420,   422,   423,     0,   306,     0,   283,     0,   149,   172,
       0,     0,   175,     0,     0,   259,     0,   261,     0,   266,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   360,    16,   320,     0,     0,     0,   376,     0,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   779,
       0,     0,     0,     0,   774,   760,     0,   761,   765,   766,
     767,   768,     0,   786,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   120,     0,     0,    99,     0,     0,   116,     0,
       0,   237,     0,     0,     0,   257,     0,     0,   509,     0,
       0,   519,   520,     0,     0,     0,     0,   556,     0,   559,
       0,   561,     0,   563,     0,     0,     0,     0,     0,   567,
     568,   601,     0,     0,     0,     0,     0,     0,   578,     0,
       0,     0,     0,     0,     0,     0,   588,     0,     0,     0,
       0,     0,     0,     0,   515,   516,   643,   607,     0,     0,
     619,     0,     0,     0,     0,     0,     0,   630,     0,     0,
       0,   416,   417,     0,     0,   177,     0,   168,     0,   260,
     262,     0,   267,     0,     0,   276,     0,   275,     0,     0,
     386,   388,    17,     0,     0,     0,   375,   374,     0,     0,
     277,   279,   131,   132,   129,     0,     0,     0,     0,     0,
     762,   763,   787,     0,   788,     0,     0,     0,   784,   206,
     208,   198,   199,   200,   215,   216,   230,   711,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   816,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   110,     0,     0,     0,   254,   255,   256,
       0,   507,     0,     0,     0,   521,   522,     0,     0,     0,
     555,     0,   558,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,     0,     0,     0,     0,   579,     0,   581,
     583,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,   608,   609,     0,   620,   623,   624,     0,
       0,     0,   525,   553,     0,   424,   136,   156,     0,     0,
     263,   270,     0,     0,   274,     0,     0,     0,     0,     0,
     133,   778,     0,     0,   782,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,     0,   508,     0,     0,   523,   524,     0,   557,
     560,   562,   564,   571,   574,     0,   603,     0,   605,     0,
     572,   575,     0,   580,   582,   584,   585,     0,   587,   533,
     535,   536,     0,     0,   540,     0,   610,     0,   628,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   789,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   815,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   115,     0,   248,   501,     0,     0,     0,
     573,   604,   602,     0,   586,     0,     0,   589,     0,     0,
     157,   268,     0,     0,   273,     0,     0,     0,     0,    71,
       0,     0,     0,     0,   794,   793,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     502,   500,   554,   576,   537,     0,     0,     0,   269,   289,
     272,     0,     0,     0,   780,     0,     0,   790,   791,     0,
     795,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,     0,   235,     0,     0,
     781,     0,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   538,     0,     0,     0,   783,   796,     0,     0,
       0,     0,     0,     0,     0,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,   317,     0,   629
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   131,   132,   133,   134,   135,   136,   137,   604,  1280,
     138,   139,   140,   141,   339,   340,  1269,   142,   143,   144,
     224,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   352,   160,   203,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,  1131,   957,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   354,   205,   882,   852,   272,  1541
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2385
static const yytype_int16 yypact[] =
{
    9380, -2385, -2385, -2385, -2385,  -399, -2385, -2385, -2385,    -6,
      95, -2385,    18,  3566,  5285,  -390,    63, -2385, -2385, -2385,
   -2385, -2385,    25,    67,    69,    30,  -387, -2385,   -50,   -26,
     -74,  -314,     4,  -307,  -278,   -10,  -233,  1113, -2385, -2385,
   -2385, -2385,  -168,  -146,   -90,  -251,   -82,  -241,  -212,   -80,
     -77, -2385, -2385, -2385,   -39,   -25,    -7,     5,    16,  -173,
      31,    36,    39,    49,    73,   111,   113,   137,   140,   158,
     182,   203,   218,   271, -2385,   281,   292, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, -2385,   296,   310,   312,
   -2385, -2385,  7056,  7056,  7056,  7056,  7056,  7056,  7056,  7056,
    7056,  7056,  7056,  7056,  7056,   462, -2385, -2385,  5285,   520,
     321,   393,   462,   411,   427,   428,   433, -2385, -2385, -2385,
   -2385, -2385,   434,   435, -2385,  3566,  7056,  7056,  8214, -2385,
   -2385,  8873, -2385, -2385, -2385, -2385, -2385,    11, -2385, -2385,
    -289,   119, -2385, -2385, -2385,  7056, -2385,  -382,  -209, -2385,
     -33,   374,    88,   148,   154,   574,   -61, -2385, -2385, -2385,
   -2385,   -15, -2385, -2385, -2385, -2385,   748,   -32,    19, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
     -58,   -11,  5285,   436,   437, -2385, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385,   432,   438,   442,   445,   447,
     449,   119, -2385,  -363, -2385,   450,   438,  8214,  8214,  8214,
    8214,  8214,  8214,  8214,  8214,  8214,  8214,  8214,  8214,  8214,
    5285,  8214,  8214,   119,  8214, -2385,    63, -2385,   466, -2385,
   -2385,  5285, -2385, -2385,  5285, -2385, -2385,  5285,    63,  1146,
     127,   127,   701,  3566,  5285,   452,    51, 10828, 10828, -2385,
     535,    22,   618,  5285,  5285, -2385, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,   469,
     437, -2385, -2385,  5285,  5285, 14585,    18, 14585, 14585,    18,
   14585,    18, 14585,    18,   622,  1301,   309,   332,    18,    18,
   14585, 14585,    18,    18,    18,    18,    18,    18,    18,    18,
     925,   926,  5285,  5285,    18,  5285,  5285,    29,   927, 14585,
      18, -2385,  -350,   748, -2385,   748, -2385,   748, -2385,   748,
   -2385,   748, -2385,   748, -2385,   748, -2385,   748, -2385,   748,
   -2385,   748, -2385,   748, -2385,   748, -2385,   748,   852, -2385,
     928, -2385,    11,   648,   930,   479,  5285,    63,   923,    18,
      18,    18,   480,   482,   483, -2385,   748, -2385,   748, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385,    11, -2385,    63,    63,
      63,    63, -2385,   748,  8214,  8214,  8214,  8214,  8214,  8214,
    8214,  8214,  8214,  8214,  5285,  5285,  5285,  5285,  5285,  5285,
   14585, 11758,  5285,  5285,   519, -2385,    29,  7056,  7056,  7056,
      48,   595, 14191,  9898,   491,  5285,  5285,    94,   129,    68,
     369,   839,  5285,    89,   164,   494,   952, -2385, -2385, -2385,
   -2385,   509,   512,   518,   521,   528,   530, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385,   534,   537,   538, -2385,
     540,   541,   561,   564, -2385,   566,   567,   568,   569,   570,
     571,   572,   573,   575,   577,   579, -2385, -2385,   580,   581,
     583,   584, -2385,   585,   586,   589,   590,   592, -2385,   593,
   -2385,   594,   596,   598,   599,   600, -2385, -2385,   503,   601,
    5285, -2385,   604,   605, -2385,    -9,   606,   502,   514,   608,
    -161,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     619,   633,   636,   638,  -306,   639,   641,   642,   643,   515,
     644,   645,   646,   602,   647,   649,   651,   653,   654,   655,
     656,   657,   658,   660,   663,   664,   683,   684,   685,   686,
     687,   688,   690,   691,   693,   695,   697,   699,   700,   702,
     703,   704,   705,   706,   707,   708,   709,   711,   712,   714,
     715,   717,   718,   719,   720,   722,   726,   727,   728,   729,
     737,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     763,   764,   765,   766, 12684, 12684, 12684, 12684, 12684, 12684,
   12684, 12684, 12684, 12684, 12684, 12684, 12684, 14585,   767,   775,
     776,   777,   778,   779,   696,   782,   784,   785,   786,   787,
   11758,   498, 12684, 12684,    92,   119, 12684, -2385,  -398, -2385,
   -2385, -2385,   911, -2385,  -324, -2385,   130, -2385,     3,   542,
     588, -2385,   557,  1002,   -60, -2385, -2385, -2385,   783,   171,
     789, -2385, -2385, -2385,   790,   791,   792, -2385, -2385,   793,
     794,   795,   796,   797,   798,   799,   800,   802,   804, -2385,
   -2385, -2385, -2385,   805, -2385,    63,   803,   807,   810,  5285,
     806,   813,   811,   808,  -208,   812, 14585, 14585, 14585, 14585,
   14585, 14585, 14585, 14585, 14585, 14585, 14585, 14585, 14585, 13797,
   14585, 14585, 14585,   -97,   817,   814,   825,   826,   828,   830,
     831,   833,   834,   835,   809,   832,   840, -2385, -2385,   841,
     842, -2385, -2385,   844,   845,   846,   847,   848,   849,   859,
     868, -2385,   869,   871,   874,   878,   881,   882,   884,   886,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   903,   904,   907,   908,   909,   910,
     912, -2385, -2385, -2385, -2385, -2385, -2385,   913,   915,    -1,
     916,   931,   932,   934,   935,   936,   937,   938,   939,   940,
     941,   942,   944,   945,   946,   947,  -240,   948, -2385,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,   950,   951,   953,   987,
      72,  5285, -2385,    10, -2385, -2385,   990,   991,   993,   145,
     994,   996,   997,   998,   999,  1003, -2385, 13468, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385,  -382,  -382, -2385, -2385,
   -2385, -2385,   -33,   -33,   374,    88,   148,   154,   574,   -73,
   -2385,   502, -2385, -2385,  -182,   943,   914, -2385,   954, -2385,
   -2385,    63, -2385,   995,  1006,  1007,  1008,  1009,  1010,  1011,
    1012, -2385, -2385,   748, -2385,   748,  -382,   -32,  -382,   -32,
    1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,    -8,  1028,  1046,  1047,  1048,
    1049,   906, -2385, -2385, -2385, -2385,    63,  1050,  1051,    63,
   -2385,  1052, -2385,  1053,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068, -2385,
    1069, -2385,  1070, -2385, -2385,  1071,  1072,  1073,  1074,  1075,
   -2385, -2385,  1076,  1077,  1078, -2385,   -17,  1079,  1080,  1082,
   -2385,  1083,   -16,  1084,  1086,  1087,  1088, 12221, 12221, 12221,
   12221, 12221, 12221, 12221, 12221, 12221, 12221, 12221, 12221, 12221,
   10363, 12221, 12221,   119, 12221, -2385, -2385, -2385, -2385,  1085,
   -2385, -2385,   949,  1090,    44,  5285,  5285,  5285,  5285,  5285,
    5285,  5285,    18,  5285,  5285,    78,  1097,  1091,  5285,  5285,
    5285,  5285,  5285,  5285,  5285, 14585,  5285,  1354,  5285,  1513,
    5285,  5285,    48,  5285,  5285,  5285,  5285,  5285,   127,    74,
    1521,  1539,  5285,  5285,  5285,  5285,    63,   119, -2385,    63,
    1538, -2385,   176,  5285,    65,   353, 10828, 14585,    18, 14585,
   14585,    18,    18,    18,    18,    18, 14585,    18,    18,    18,
      18,    18,    21,    18,    18,    18,    18,    66, 14585, 14585,
      18,  1392,  1395,    18,    18,    18,    18,    18,    18,    18,
      18,    18, 14585,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    18, 14585, 14585, 14585, 14585,
   14585,    18,    18,    18,    18,    18,   127,   127,    63,    63,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18, 14585,    18,    18,    18,    18,    18,    18,
   14585, 14585,  -250, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385, 14585, 14585,
   14585,    18, 14585, 14585,  1121, 14585, 14585, 14585, 14585,    63,
    1096,  1098, -2385, -2385, -2385, -2385, -2385, -2385, -2385, 11293,
   -2385, 11758,  4789, 14585, 12684, 12684, 14585, 12684, 12684, 12684,
   12684, 12684, 12684, 12684, 12684, 14585, 14585, 14585, 14585, 14585,
      28,    11,    63,    63,  1545,  1546,    63,  1547,  1549,  5285,
    1548,  1550,  5285,  1536,  5285,    63,  5285, -2385,  5285,  1481,
    1483,  1104, -2385,  1544,  1286, 14585,   634,    23,  1111,  -202,
   14585, -2385,   202, -2385,  1114, -2385, -2385,  1115, -2385,  1116,
      18,  5285,    18,  5285,  5285,  5285,    18,    18,    18,    18,
    5285,  5285,  5285,  5285,  5285,  5285,  5285,    18,  5285,    18,
      18,    18,    45,    18,    75,    93,    18,    18,  5285,  5285,
    5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285,
    5285,  5285,  5285,    18, -2385, 14585, -2385,  1117,  5285,  5285,
    5285,  5285,  5285,  5285,  5285,    18,    18,    18, -2385, -2385,
    5285,  5285, -2385,  5285, -2385, -2385,    63, -2385,  1166, -2385,
   -2385, -2385, -2385, -2385, -2385,  1568,  1569,  1570,  1572,  1573,
     183,  5285, -2385,  5285,    63,    18,    18,  5285, -2385,  5285,
    5285, -2385,  5285,  5285,  1501,    63,    18, -2385,    18,    18,
    5285,  5285,  5285,  5285,  5285,  5285,    18,   127,   127,   127,
   14585, 14585, 14585,    63, 14585,    18,   127,    18,   127,   127,
   14585, -2385,    -5, 14585, 14585, 14585, 14585, 14585,  1366, -2385,
    5285,  5285, -2385,  5285,  5285,  5285,  5285,  5285,  5285, 14585,
    5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285,    18, 14585,
    5285, 14585,  5285,  5285,    18,  5285,  5285,  5285, 14585,  5285,
    5285,    63,  -200, 10828,    63,  5285,  1560,  5285,  5285,    63,
    -124, -2385, -2385,  1127,  1128,  -144,  1129,  1130,  1131,  1133,
    1135,  1134,  1136,  1138,  1140,  1141,  1142,  1143,  1144,  1145,
    1148,  1147,  1150,  1151,  1152,  1153,  1154,  1156,  1157,  1159,
    1160,   185,  1162,  1163,  1164,  1165,  1167,  1168,  1170,  1124,
     187,  1171,  1172,  1173,  1174,  1176,  1177,  1178,  1180,  1182,
    1183,  1184,  1187,  1185, -2385, -2385, -2385,   190,  -131,  1191,
    1192,  1193,  1195,  1188,  1196,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207, -2385, -2385,  1208,  1209,  1211,  1212,
   -2385,  1158,  1161,  1213,  1214,  1215,  1179,  1218,  1219,  1217,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1229,  1230,
    1231,  1232,  1234,  1235,  1236,  1237,  1238,  1239,   192,  1240,
    1241,  1242,  1243,  1244,  1245,  1246,  1248,  1249,  1250,  1251,
    1252,  1253,  1254,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1272,  1273,
    1274,  1275,  1280,  1282,  1284,  1285,  1287,  1291,   194,  1292,
    1297,  1299,  1303,  1233,   219,   221,  1304,  1302,  1310, 13147,
   -2385,   502,   607,   119, -2385, -2385,  1311,   432,  1313,  -235,
    -363,  1139, -2385, -2385, -2385, -2385, -2385, -2385,  -382,  -324,
    -382,  -324, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
   -2385,     3, -2385,     3,   542, -2385,   557,  1002,   -52,  1288,
    1316,  1318,  1319, -2385,  1312,  1320,  1321,  1322,  1324,  1327,
     223,  1328,  1331,  1344,  1346,  1348,  1349,  1350,  1351,  1169,
      48, 14585, -2385,  1352, 14979,  1296,    18,    18,    18,   225,
    1353,  1363,   227,  1365,  1367,  1368,  1369,  1370,  1371,  1372,
    1373,  1374,  1375,  1376,  1381,  1382,  1387,  1383,  1389,  1390,
    1393,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1415,  1418,
    1421,  1391,  1422,  1423,  1426,  1427,  1428,  1429,  1430,  1432,
    1433,  1434,  1435,  1436,  1438,  1437,  1440, 14585,  1441,  1442,
     230,  1443,  1444,  1446,  1448,  1449,  1450,  1452,  1453,  1454,
    1457,  1458,  5285,    11, -2385, -2385, -2385, -2385, -2385, -2385,
     205,  1459,  1460,  1462,  1463,  1464, -2385,  1466,    70,  1467,
   11758,  1469,   232,  1470,  1471,  1472,  -167,  1474,   -86,  1476,
     234,  1477,   237,  1479,   243,  1480,  1482,  1484,  1485,  1486,
     245,  1488,  1489,   247,  1490,  1491,  1492,  1493, -2385,  1495,
     249,  1496,  1497,  1498,  1499,  1329,  1502,  1504,  1507,  1508,
     252,  1509,  1511,  1500,   254,  1512,  1514,  1516,  1517,  1519,
    1522,  1526,  1529,  1530,  1533,  1535,  1537,  1540,  1541,  1553,
    1554,  1555,  1558,  1559,  1181,  1255,  1561, -2385,   274,  1563,
    1455,  1564,  1571,  1578,  1567, -2385,    18,  5285,  5285,  5285,
    5285, -2385,  5285, -2385,  5285, -2385, -2385, -2385,    18,    18,
    5285,  5285,  5285, -2385, -2385,  5285,  5285,  5285,  5285, -2385,
    5285, -2385,  5285, -2385,  5285, -2385, -2385,  5285,  5285,  5285,
    5285, -2385,  1289, -2385,  5285, -2385,    18,  5285, 14585, -2385,
    1597,  1620, -2385, -2385, -2385,  5285,    13,  5285, -2385, 14585,
     149,  5285,  5285, -2385,  5285,  5285,  5285,  5285,  5285,  5285,
    5285,  5285,  5285,  5285,  5285,  5285, -2385,  5285,    18,    18,
   14585, 14585,    18,    18,    18, -2385,  5285,  5285,  5285,  5285,
    5285,  5285,  5285,  5285,  5285, -2385, -2385, -2385,    18, -2385,
      18,    18,    18,    18,    18, -2385,    18,    18,  5285,  5285,
    5285,  5285, 14585, 14585, -2385,  5285,  5285,  5285,  5285,    18,
      63, -2385, -2385,    18,    18,  5285,  5285,  5285,  5285,  5285,
    5285,  5285,  5285,  5285,  5285,  5285, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385,  5285,  5285,  5285, -2385,  5285,  5285,    18,
    5285,  5285,    18, -2385,  5285, -2385,  5285, 14585, -2385, -2385,
   11758, -2385, -2385, -2385, -2385, -2385, -2385,  1314, -2385,  5285,
   -2385, 14585,    18,  1582,  1588,  1589, -2385, -2385,  5285,  5285,
    1671, -2385, -2385,  5285,    63,    63,    63,  5285, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, 14585,  1594,  1596,   276,
   -2385,    18, -2385,  5285, -2385,  5285, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,  5285,
   -2385, -2385,    18, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385,  5285, -2385,  5285, -2385, -2385, -2385,
   -2385,  5285, -2385, -2385, -2385, -2385, -2385,  5285, -2385, -2385,
    1598,  5285,  5285, -2385, 11758,  5285,  5285, -2385,  5285,  5285,
      18,    18,  5285,  5285, -2385,  5285,  1338, -2385,    11,  1699,
    1771,  1804,  1816,  1840,  5285,  5285, -2385,    18,  5285, -2385,
    5285, -2385,  5285,  5285, -2385, -2385, -2385, -2385,  5285, -2385,
   -2385,  5285, -2385,  5285, -2385, -2385, -2385,  5285,  5285, -2385,
    5285, -2385, -2385,  5285,  5285,  5285,  5285,  5285,  5285, -2385,
    5285,  5285,  5285, -2385,  5285,  5285,  5285,  5285,  5285, -2385,
   -2385,  5285,  5285,  5285, 11758, 14585,  5285, -2385, -2385, -2385,
   -2385, -2385,  5285, -2385, -2385,  5285, -2385,  5285, -2385,  5285,
    5285,  5285, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
    5285,  5285, -2385, -2385,  5285, -2385, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385,  1864, -2385, -2385,  1894,  1599,  1602,  1604,
    1603,  1606,  1611,  1612,  1614,  1615,  1617,  1618,  1621,  1623,
    1625,  1626,  1627,  1628,  1629,  1631,  1632,  1633,  1634,  1635,
    1637,  1638,  1639,  1640,  5285,  1642,  1643,  1644,  1646,   278,
    1647,  1648,  1650,  1651,  1652,  1654,  1655,  1657,  1658,  1659,
    1660,  1661,  1663,  1664,  1665,  1666,  1668,  1669,  1670,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1693,  1694,
    1696,  1695,  1698,  1700,  1701,  1702,  1704,  1705,  1706,  1707,
    1722,  1708,  1724,  1725,  1726,  1727,  1729,  1730,  1731,  1732,
    1733,  1734,  1735,   282,  1738,  1739,  1741,  1742,  1736,  1743,
    1744,  1746,  1748,  1749,  1747,  1752,  1753,  1754,  1755, -2385,
    1757, -2385, -2385, -2385,  1758,  1762,  1765,  1766,  1767,  1768,
    1769,  1772, -2385, -2385, -2385,  5285,  1773,  1770,  1774,  1775,
    1776,  1777,  1779,  1780,  1781, -2385,   286,   289,   293,  1783,
    1784,  1785,  1786,  1788,  1789,  1790,  1791,  1792,  1794,  5285,
      11, -2385, -2385, -2385, -2385, -2385, -2385,  1795,  1796,  1797,
    1798,  1800,    80,  1475,  1813,  1817,  1818,  1819,  1820,  1821,
    1822,  1824,  1825,  1826,  1827,  1828,  1830,   302,  1831,  1832,
    1833,  1834,  1835,  1836,   304,  1837,  1838,  1839,  1841,  1843,
    1845,  1848,  1849,  1850,  1853,  1858,  1863,  1865,  1867,  1868,
    1871,  1873,  5285, -2385,  5285, -2385,  5285, -2385,  5285, -2385,
   -2385, -2385, -2385,  5285,  5285, -2385,  5285,  5285,  5285,  5285,
   -2385,  5285,  5285,  5285,  5285, -2385, -2385, -2385,  5285, -2385,
   -2385,  5285,  5285, -2385, -2385,   189,   173,  5285, -2385, -2385,
   -2385, -2385,  5285, -2385,  5285,  5285,  5285,  5285,  5285,  5285,
    5285,  5285, -2385,  5285,  5285,  5285,  5285,  5285,  5285,  5285,
    5285,  5285,  5285,  5285,  5285,  5285,  5285, -2385,  5285,    18,
      18,    18,    18,    18, -2385, -2385,  5285, -2385, -2385, -2385,
    5285,  5285, -2385, -2385, -2385, -2385, 14585, -2385, -2385, 14585,
    5285,  5285, -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
    5285,  5285,  5285,  5285,  5285, -2385,  5285,  5285, -2385,  5285,
    5285, -2385, -2385, -2385,  5285,  5285, -2385,  5285,  5285, -2385,
   -2385, -2385, -2385,    63, -2385,  1874, -2385,  5285, -2385, -2385,
      18,  5285, -2385,  5285,  5285, -2385, 14585, -2385, 14585, -2385,
   14585, -2385, 14585,  5285,  5285,  5285,    18,    18,  5285,  5285,
   -2385, -2385, -2385, -2385,  5285,    18,  5285, -2385,  5285, -2385,
    5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285, -2385,
    5285,  5285,  5285,  5285, -2385, -2385,    18, -2385, -2385, -2385,
   -2385, -2385, 14585, -2385,  5285,  5285,  5285,  5285, 14585, 14585,
    5285, -2385,  5285,  5285,  5285,  5285,  5285,  5285,  5285,  5285,
    5285, -2385,  1875,   316,  1876,  1878,  1879,  1881,  1891,  1905,
    1907,  1909,  1910,  1911,  1912,  1914,  1915,  1916,   -84,  1917,
    1920,  1922,  1473,   318,  1923,  1924,  1925,   325,   339,   341,
     343,  1926,  1927,  1930,  1931,  1933,    14,   347,   -78,  1934,
    1935,  1936,  1937,   349,  1943,  1946,  1949,  1950,  1951,  1954,
    1958,  1959,  1960,  1961,  1962,  1963,  1964,  1966,  1968,  1969,
    1971,  1974,  1975,  1976,  1978,  1979,  1980,  1984,  1985,  1988,
    1989,  1991,  1993,  1531,  1534,  1992,  1996,  1997, -2385,  2007,
    2013,  2014,  2016,  2017,  2019,   351,  2020,  2021,  2026,  2028,
    2029,   354,  2039,  2041,  2042,    11,  2043,  2044,  2045,  2047,
    2048,  2049,  2050,  2052,  2053,  2054,  2055,  2056,  2057,  2058,
    2059,  2060,  2061,  2063,  2064,  2066,  2067,  2070,  2084,  2087,
    2089,  2071,  2091,  2092,  2093,  2094,  2095,  2096,  2097,  2098,
    2099, -2385, -2385,  5285,  5285, -2385,  5285,  5285, -2385,  5285,
    5285, -2385,  5285,  5285,  5285, -2385,  5285,  5285, -2385,   189,
    5285, -2385, -2385,   189,  1967,  5285,  5285, -2385,  5285, -2385,
    5285, -2385,  5285, -2385,  5285,  5285,  5285,  5285,  5285, -2385,
   -2385, -2385,  5285,  5285,  5285,  5285,  5285,  5285, -2385,  6054,
    6054,  6054,  5285,  5285,  5285,  5285, -2385,  5285,  5285,  5285,
    5285,  5285,    18,  5285, -2385, -2385, -2385, -2385,  5285,  5285,
   -2385,  5285,  5285,  5285,  5285,  5285,  5285, -2385,  5285,  5285,
    5285, -2385, -2385,    63,  5285, -2385,  5285, -2385,  5285, -2385,
   -2385,  5285, -2385,  5285,  5285, -2385,  5285, -2385, 14585,    18,
   -2385, -2385, -2385,  5285,    18,  5285, -2385, -2385,  5285,  5285,
   -2385, -2385, -2385, -2385, -2385,  5285,  5285,  5285,  5285,  5285,
   -2385, -2385, -2385, 14585, -2385,  5285,  5285,  5285, -2385, -2385,
   -2385, -2385, -2385, -2385, -2385, -2385, -2385, -2385,  2100,  2102,
    2104,  2105,  2106,  2107,  2109,  2110,  2111,  2112,   356,  2113,
    2114,  2116,   358,  2117,  2118,   360,   362,  2119,  2120,  2121,
    2122,  2123,  2125,  2126,  2127,  2128,  2129,  2130,  2131,  -194,
    2133,  -149,  2134,  1543,  2135,  2136,  2137,  2138,  2139,  2140,
    2141,  2142,  2143,  2144,   364,  2145,  2147,   367,  2148,  2149,
    2150,  2151,  2152,  2153,  2155,  1510,  2156,  2158,  2159,   370,
    2160,  2162,  2163,  2164,  2165,  2167,  2168,  2169,  2170,  2173,
    1565,  2177,  2180,  2183,  2186,  2188,  2189,  2190,  2191,  2192,
    2195,  5285, -2385, -2385,  5285,  5285,  5285, -2385, -2385, -2385,
    5285, -2385,  5285,  5285,    63, -2385, -2385,   189,  5285,  5285,
   -2385,  5285, -2385,  5285,  5285,  5285,  5285,  5285,  5285, -2385,
    5285,  5285,  5285,  5285,  5285,  5285,  6054, -2385,  6054, -2385,
   -2385,  6054,  6054,  5285,  5285,  5285,    18,    18,    18,    18,
   -2385,  5285,  5285, -2385, -2385,  5285, -2385, -2385, -2385,  5285,
    5285,  5285, -2385, -2385,  5285, -2385, -2385, -2385,  5285,  5285,
   -2385, -2385,  5285,  5285, -2385,    18,  5285,    18,  5285,  5285,
   -2385, -2385,  5285,  5285, -2385,  5285, 14585,  5285,  5285,  5285,
    2198,  2199,  2201,  2207,  2208,  2210,  2216,  2224,  2231,  2233,
    2234,  2236,  2239,  2246,  2250,  2251,  2252,  2253,   372,  2256,
    2257,  2259,  2261,  2263,  2266,  2267,  2268,  2270,  2272,  2271,
    2275,  2276,  2282,  2288,  2289,  2291,  2292,  2297,  2298,  2300,
    2301,  1592,  2302,  2304,  2305,  2306,  2307,  2308,  2309,  2310,
    2312,  2313,  2314,  2315,   375,  2316,  2317,  2318, -2385,  5285,
    5285,  5285,  5285, -2385,  5285,  5285, -2385, -2385,  5285, -2385,
   -2385, -2385, -2385, -2385, -2385,  5285, -2385,  5285, -2385,  5285,
   -2385, -2385,  5285, -2385, -2385, -2385, -2385,  6054, -2385, -2385,
   -2385, -2385,  5285,  5285, -2385,  5285, -2385,  5285, -2385,  5285,
    5285,  5285, -2385,  5285,  5285,    18,  5285,    18,  5285,  1844,
    5285,  5285,  5285, -2385, 14585,  5285,  5285,  5285,  2320,  2321,
    2322,  2324,   -72,  2325,  2326,  2327,  2329,  2330,  2331,  2332,
    2334,  2335,  2336,  2338,  2339,  2340, -2385,  2342,   377,  2343,
     396,  2344,  2345,  2346, 14585,  2347,  2348,  2349,  2350,  2352,
     398,  2353, -2385, -2385,  5285, -2385, -2385,    63,  5285,  5285,
   -2385, -2385, -2385,  5285, -2385,  5285,  5285, -2385,  5285,  5285,
   -2385, -2385, 14585,  5285, -2385, 14585,  5285,  5285,  5285, -2385,
    5285,  5285,  5285,  5285, -2385, -2385,  5285,  5285,  2354,  2356,
    2357,  2358,  2359,  2360,  2361,  2362,  2363,  2365,  2366,  2367,
    2368,  2369,  2370,  2372,  2373,  2374,  2376,   402,   404,  5285,
   -2385, -2385, -2385, -2385, -2385,  5285,  5285,  5285, -2385, -2385,
   -2385,  5285,  5285,    18, -2385,  5285,  5285, -2385, -2385,  5285,
   -2385, 14585,  2377,  2378,  2380,  2381,  2383,  2384,  2385,  2387,
    2388,  2391,  2395,  5285,  5285, -2385,  5285, -2385,  5285,    18,
   -2385,  5285, -2385, 14585,  2396,  2392,  2397,  2399,  2402,  2404,
    2405,  5285, -2385,  5285,  5285,  5285, -2385, -2385,  2408,  2410,
    2417,  2406,  5285,  5285,  5285, -2385,  2425,  2427,  2428,  5285,
    5285,  5285,  2435,  2436,  2437, -2385,  5285,  5285,  2438,  2442,
    5285, -2385,  2443, -2385
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2385, -2385,   -31,  1846,  1888,  1890,  1895,  1896,  -243, -2385,
   -2385,   527, -2385,   307,  -337, -2385, -2385, -2385, -2385,  -797,
    5724,   163,  -359, -2385,  -372,   505,  1579,  1580,  1645,  1557,
    1692,  1656,   818, -2385,     0,  -123,  3162, -2385, -2385, -2385,
    -523,  1616,  -246, -2385, -2385,  -649,  -256,   958, -2385,   880,
     964,   966,   969,   172,   959,  6867,  1137, -2385, -2385, -2385,
   -2385,    91,   507, -2385, -2385, -2385, -2385, -2385, -2385, -2385,
   -2385, -2385, -2385, -2385,    33,  6710,  -400,   170,  1807, -2384
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     159,   249,   353,   960,   793,   629,   818,   819,   820,   821,
    1288,  1011,  1321,   202,   225,     8,    15,   816,   817,  1011,
    1321,     8,     8,    18,   388,   400,    21,    21,   370,   371,
     245,   194,    27,   179,   240,   241,   388,  1158,   837,   856,
     858,   654,   183,   184,   184,  1158,   204,  1444,  1445,  1450,
      21,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,   378,   379,   184,   390,   768,
     480,   396,   402,   252,   883,   884,   885,    21,   243,  1103,
    1103,   182,  1141,  1103,    15,  1142,    27,   413,   927,   391,
     226,    18,  1450,   403,   184,    21,   183,   353,   239,   194,
     361,  1149,  1150,    20,  1425,  1426,   367,    21,   341,   374,
      21,   375,   184,  1409,   837,  1384,  1715,   412,   229,   230,
      20,   930,   413,   188,   184,    21,    20,   184,    52,   231,
     412,   159,   635,   636,   238,   790,   639,   640,   641,   642,
     643,   644,   184,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1747,  1103,  1103,  1103,
     232,   233,   235,   236,   179,    27,   247,  1144,  1451,  1145,
     181,   234,  1146,   237,  1031,   183,  1621,  2149,   250,  1032,
     189,    21,   404,   313,   315,   317,   319,   321,   323,   325,
     327,   329,   331,   333,   335,   337,    52,    15,   184,   368,
     369,  2543,   711,  1452,    18,    21,  1624,   251,    21,   701,
     702,  1451,   194,  1569,  1570,  1571,  1572,   356,   358,   370,
     371,    21,   184,   655,  1626,   184,   883,   884,   885,   276,
    1141,   417,   277,  1142,   418,   790,   373,   419,   184,   279,
     412,  1262,   280,   476,   478,   413,  1452,   607,   607,  1918,
     254,  1919,   839,   657,   658,   311,   314,   316,   318,   320,
     322,   324,   326,   328,   330,   332,   334,   336,   281,   839,
     840,   282,  1031,   660,   661,   338,   477,  1186,  1190,   376,
     377,  1142,   345,  1595,   860,   861,   862,   840,  2906,   355,
     357,   359,  1919,   863,   864,   865,   866,  1290,   867,  1291,
    1292,   181,   762,   763,  1293,   765,   767,   290,   372,    52,
     291,   794,   273,   412,  2042,  2820,  2822,  2824,   413,  1017,
     201,   223,   277,   227,   427,   428,   429,   430,   431,   432,
     433,   434,   435,  2908,   274,   809,   412,  1919,  1757,   868,
     786,   413,   869,   870,   871,   872,   800,   873,   874,  1190,
    1193,   875,  1142,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   883,   884,   885,  1569,  1570,  1571,  1572,  1424,
     311,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,  1190,   355,   357,  1142,   372,    75,    76,
     275,   832,   834,   835,   412,  2044,   412,  2668,   278,   413,
     283,   413,   412,   955,  2693,   962,   963,   413,   284,  3116,
     851,   246,   964,  1289,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,   401,  1103,  1103,
     185,  1103,   933,   653,  1921,   242,   958,   389,  1159,   769,
     770,   771,   772,   773,   774,  1270,   285,   775,   776,   777,
     778,   779,   780,   781,   244,   481,   482,   483,   484,   397,
     286,   380,   381,  1012,  1322,   392,  1360,  1365,   393,   851,
     394,  1012,  1322,   253,   382,   383,  1708,  1130,   287,  1190,
    1008,  1245,  1142,   124,   248,   288,   851,   853,   855,   124,
     124,   743,   744,    20,   412,  2690,   289,  1151,  1152,   413,
    1553,  1555,  1557,  1559,   876,   877,   878,   398,   399,   782,
     879,   292,   880,   796,   745,   746,   293,   783,   784,   294,
     129,   130,  2984,  1290,  2985,  1291,  1292,  2986,  2987,   295,
      21,  1132,  1133,   415,   482,   483,    27,   814,   815,  1569,
    1570,  1571,  1572,   836,   837,   420,   183,   184,   342,  2030,
      20,  2031,  2032,   296,   605,   605,  1188,   701,   702,  2478,
     854,  2479,  2480,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,  1138,  1139,   384,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,  1275,  1276,  1277,  1278,
    1279,   297,  1402,   298,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   299,  1147,  1148,
     300,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,   838,   301,    21,
    1912,  1913,  1153,  1154,   385,    27,  2019,  2020,  2021,  2022,
    2023,   386,  1161,  1139,   801,   183,   184,  1425,  1426,  1181,
    1444,  1445,   302,  3090,  1669,  1670,  1783,  1784,  1793,  1794,
     387,  1808,  1139,  1855,  1856,  1896,  1897,   812,   813,    20,
      21,   255,   256,   303,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   795,   270,   304,   839,
    1903,  1904,  1905,  1906,  1932,  1933,  1950,  1951,  1954,  1955,
     953,  2003,  2004,  2037,  2038,  2046,  2047,   840,  2049,  2050,
     841,   842,   843,   844,  2052,  2053,  2059,  2060,  2063,  2064,
    2070,  2071,  1288,  2081,  2082,  2086,  2087,   311,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   336,
     694,   305,   845,   846,   847,  2110,  1139,  2244,  2245,  2354,
    2355,   306,  1271,  2419,  2420,   355,   357,  2455,  2456,   372,
    2457,  2458,   307,  1427,  2459,  2460,   308,  1552,  1554,  1556,
    1558,  1560,  1562,  2495,  2496,  2503,  2504,  1007,  1548,  1550,
     309,  1268,   310,   883,   884,   885,   886,  2652,  2653,  2672,
    2673,   343,   695,   696,   697,   698,  2677,  2678,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
    2679,  2680,  2681,  2682,  2683,  2684,   887,  1130,  2691,  2692,
    2698,  2699,  2740,  2741,   888,  2747,  2748,  2881,  2882,  2886,
    2887,  2890,  2891,  2892,  2893,  2920,  2921,   889,  2924,  2925,
     395,  2937,  2938,  3036,  3037,   479,  3073,  3074,  3131,  3132,
     313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
     333,   335,   337,   344,   356,   358,   373,  3134,  3135,  3145,
    3146,   848,   849,  3188,  3189,  3190,  3191,   822,   823,  1421,
     890,   346,   891,   892,   893,   810,   811,  1561,  1563,   850,
     653,  1549,  1551,   894,   895,   857,   859,   347,   348,   896,
     897,   898,   899,   349,   350,   351,   851,   407,   244,   405,
     406,   656,   900,   901,   902,   903,   904,   408,   905,   906,
     409,   907,   410,  1663,   411,   414,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   416,   659,   760,   761,   787,   791,   792,   798,   799,
     802,   806,  1177,   807,   808,  1373,  1374,  1376,  1377,  1378,
    1379,  1380,   961,  1382,  1383,   711,   965,   837,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1005,  1396,  1014,  1398,   966,
    1400,  1401,   967,  1403,  1404,  1405,  1406,  1407,   968,  1015,
    1037,   969,  1413,  1414,  1415,  1416,  1911,   458,   970,   459,
     971,   460,   461,  1423,   972,  1143,   607,   973,   974,   462,
     975,   976,   463,   464,   465,   466,   467,   468,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   977,   356,   358,   978,   373,   979,   980,   981,   982,
     983,   984,   985,   986,  1156,   987,   923,   988,   469,   989,
     990,   991,   470,   992,   993,   994,   995,   471,   472,   996,
     997,  1911,   998,   999,  1000,  1155,  1001,   473,  1002,  1003,
    1004,  1006,   474,   475,  1009,  1010,  1013,  1041,  1016,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1157,  1027,
     311,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,  1028,   355,   357,  1029,   372,  1030,  1033,
    1748,  1034,  1035,  1036,  1038,  1039,  1040,  1386,  1387,  1043,
    1573,  1044,  1042,  1045,  1046,  1047,  1048,  1049,  1050,  1534,
    1051,   964,  1539,  1052,  1053,    21,   255,   256,  1297,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,  1054,  1055,  1056,  1057,  1058,  1059,  1581,
    1060,  1061,  1584,  1062,  1586,  1063,  1588,  1064,  1589,  1065,
    1066,  1124,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1943,  1075,  1076,  1329,  1077,  1078,  1332,  1079,  1080,  1081,
    1082,  1600,  1083,  1602,  1603,  1604,  1084,  1085,  1086,  1087,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1088,  1617,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1098,  1099,  1100,  1101,  1118,  1648,  1649,
    1650,  1651,  1652,  1653,  1654,  1119,  1120,  1121,  1122,  1123,
    1658,  1659,  1125,  1660,  1126,  1127,  1128,  1129,  1160,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1671,  1174,  1672,  1175,  1176,  1178,  1182,  1185,  1201,
    1677,  1179,  1678,  1679,  1180,  1183,  1184,  1187,  1191,  1192,
    1685,  1687,  1689,  1690,  1691,  1692,  1193,  1543,  1545,  1195,
    1194,  1196,  1202,  1417,  1198,  1197,  1418,  1200,  1199,  1420,
    1203,  1204,  1205,   605,  1206,  1207,  1208,  1209,  1210,  1211,
    1716,  1717,  2018,  1718,  1719,  1720,  1721,  1722,  1723,  1212,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1213,  1214,
    1735,  1215,  1737,  1738,  1216,  1740,  1741,  1742,  1217,  1744,
    1745,  1218,  1219,   607,  1220,  1750,  1221,  1752,  1753,  1222,
    1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1237,  1493,  1494,  1238,  1239,  1240,
    1241,  1328,  1242,  1397,  1295,  1243,  1244,  1246,  1103,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,  1248,  1247,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1294,  1260,  1261,
    1263,  1264,  1265,  1371,  1296,  1266,  1528,   711,   712,   713,
     714,   715,   716,   717,   718,   719,  1533,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   740,  1267,  1574,
    1575,  1272,  1273,  1578,  1274,  1298,  1281,  1282,   436,  1283,
    1284,  1285,  1587,   741,   742,  1286,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1323,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,  1324,  1325,  1326,  1327,
    1330,  1331,  1333,  1334,  1335,  1336,  1337,  1338,  1339,  1340,
    1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,
    1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1399,  1361,
    1411,  1359,  1363,  1364,  1366,  1362,  1367,  1368,  1369,  1412,
    1370,  1419,  1456,  1661,  1372,  1457,  1523,  1529,  1576,  1530,
    1577,  1585,  1579,  1580,  1582,  1590,  1583,  1591,  1592,  1593,
    1424,  1673,  1594,  1662,  1596,  1597,  1598,  1647,   454,  1664,
    1665,  1666,  1681,  1667,  1668,  1680,  1715,  1751,  1755,  1792,
    1756,  1758,  1759,  1760,  1761,  1763,   455,  1762,  1764,  1765,
    1700,  1766,  1767,  1920,  1768,  1769,  1770,  1771,  1773,  1709,
    1772,  1774,  2017,  1775,  1776,  1777,  1778,  1779,  1828,  1780,
    1781,  1829,  1782,  1785,  1786,  1747,  1787,  1788,  2145,  1789,
    1790,  1791,  1795,  1942,  1796,  1797,  1798,  1799,  1800,  1833,
    1801,  1802,  2016,  1803,  1804,  2107,  1805,  1807,  1746,  1813,
     605,  1749,  1806,  1809,  1810,  1811,  1754,  1812,  1814,  2270,
    2034,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,
    1824,  1825,  1826,   851,  1827,  1830,  1831,  1832,  1834,  1836,
    1835,  2144,  1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1902,  1848,  1849,  2236,  1850,  1851,  1852,
    1853,  1854,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,
    2272,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  2108,
    1873,  1874,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,
    1883,  1884,  1885,  1886,  1887,  1888,  1889,  2118,  2119,  2120,
    2121,  1890,  2122,  1891,  2123,  1892,  2269,  1893,  1922,  1894,
    2126,  2127,  2128,  1895,  1898,  2129,  2130,  2131,  2132,  1899,
    2133,  1900,  2134,  1908,  2135,  1901,  1907,  2136,  2137,  2138,
    2139,  1909,  1916,  1926,  2140,  1917,  1923,  2142,  1924,  1925,
    2227,  1927,  2273,  1928,  1929,  2146,  1930,  2147,  1931,  2076,
    1934,  2151,  2152,  1935,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  1936,  2165,  1937,  1938,
    1939,  1940,  1941,  1945,  1952,  2274,  2173,  2174,  2175,  2176,
    2177,  2178,  2179,  2180,  2181,  1953,  1956,  2275,  1957,  1958,
    1959,  1960,  1961,  1962,  1963,  1964,  1965,  1966,  2190,  2191,
    2192,  2193,  1967,  1968,  1970,  2196,  2197,  2198,  2199,  1969,
    1971,  2276,  1972,  1984,  1973,  2204,  2205,  2206,  2207,  2208,
    2209,  2210,  2211,  2212,  2213,  2214,  1974,  1975,  1976,  1977,
    1978,  1979,  1980,  2215,  2216,  2217,  1981,  2218,  2219,  1982,
    2221,  2222,  1983,  1985,  2224,  1986,  2225,  1987,  1988,  1989,
    1990,  2320,  1991,  1992,  1993,  1994,  1995,  1996,  1998,  2228,
    1997,  1999,  2321,  2001,  2002,  2005,  2006,  2007,  2234,  2235,
    2008,  2009,  2010,  2237,  2011,  2012,  2013,  2241,  2014,  2112,
    2015,  2024,  2025,  2026,   827,  2027,  2028,  2029,  3104,  2033,
    2036,  2039,  2040,  2247,  2041,  2248,  2043,  2045,  1595,  2048,
    2051,  2481,  2054,   824,  2055,   825,  2056,  2057,  2058,  2249,
    2061,  2062,  2065,  2066,  2067,  2068,  2069,   362,  2072,  2073,
    2074,  2075,  2085,  2077,  2251,  2078,  2252,  2271,  2079,  2080,
    2083,  2253,  2084,  2088,  2933,  2802,  2089,  2254,  2090,  2091,
    2092,  2256,  2257,  2093,  2258,  2260,  2261,  2094,  2262,  2263,
    2095,  2096,  2266,  2267,  2097,  2268,  2098,  2729,  2099,   363,
    2730,   364,  2100,  2101,  2277,  2278,   365,   366,  2280,  1919,
    2281,   826,  2282,  2283,  2102,  2103,  1565,  2104,  2284,  2105,
    2106,  2285,  2109,  2286,  2111,   829,  2113,  2287,  2288,  2116,
    2289,  2949,  2114,  2290,  2291,  2292,  2293,  2294,  2295,  2115,
    2296,  2297,  2298,  2231,  2299,  2300,  2301,  2302,  2303,  2232,
    2233,  2304,  2305,  2306,  2307,  2242,  2310,  2243,  3060,  2255,
     828,  2322,  2311,  2323,  2325,  2312,  2324,  2313,  2326,  2314,
    2315,  2316,  2327,  2229,  2328,  2329,  2330,     0,  2331,  2332,
    2317,  2318,  1542,  2333,  2319,  2334,  2335,  1676,  2336,  2337,
    2338,  2339,  2340,  1564,  2341,  2342,  2343,  2344,  2345,  2346,
    2347,  1566,  2348,  2350,  1567,  2351,  2352,  2353,  1568,  2356,
    2357,  2358,  2359,  2360,  2615,  2361,  1410,  2362,  2363,     0,
    2364,  2365,  2366,  2367,  2349,  2368,  2369,  2370,  2371,  2372,
     797,  2373,  2374,     0,  2375,  2376,  2377,  2378,  2379,  2380,
    2381,  2382,  2383,  2384,  2385,  2386,  2387,     0,  2388,  2389,
    2390,  2391,  2392,  2393,  2394,  2395,  2397,  2201,  2396,  2398,
       0,  2399,     0,  2400,  2401,  2402,  2403,  2404,  2405,  2407,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  2406,  2408,     0,  2409,  2410,  2411,
    2412,  2413,  2414,  2415,  2416,  2417,  2418,  2425,  1136,  1137,
    2421,  2422,  1140,  2423,  2424,  2426,  2427,  2428,  2431,  2540,
    2429,  2430,  2541,  2432,  2433,     0,  2434,  2435,  2436,  2472,
    2437,  2238,  2239,  2240,  2438,  2445,  2439,  2440,  2441,  2442,
       0,  2443,  2447,  2444,  2446,  2448,  2449,     0,  2450,  2451,
    2452,     0,  2453,  2454,  2461,     0,  2462,  2463,  2464,  2471,
    2465,  2466,  2467,  2468,  2469,  2470,  2473,     0,  2474,  2475,
    2476,  2477,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,  1116,  2482,  1136,  1137,  1140,  2483,
    2484,  2485,  2486,  2487,  2488,  2489,     0,  2490,  2491,  2492,
    2493,  2494,  2497,  2498,  2499,  2500,  2501,     0,  2502,  2505,
    2506,  2507,  2522,  2508,  2523,  2509,  2524,  2510,  2525,  2511,
       0,  2512,  2513,  2526,  2527,  2514,  2528,  2529,  2530,  2531,
    2515,  2532,  2533,  2534,  2535,  2516,     0,  2517,  2536,  2518,
    2519,  2537,  2539,  2520,  2521,  2598,  2651,  2545,  2654,  2655,
       0,  2656,  2546,  2657,  2547,  2548,  2549,  2550,  2551,  2552,
    2553,  2554,  2658,  2555,  2557,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,  2569,  2570,  2659,  2571,  2660,
    2661,     0,  2662,  2663,  2664,  2665,  2577,  2666,  2667,  2669,
    2578,  2579,  2670,  2671,     0,  2674,  2675,  2676,  2685,  2686,
    2582,  2583,  2687,  2688,  2689,     0,  2694,  2695,  2696,  2697,
    2584,  2585,  2586,  2587,  2588,  2700,  2589,  2590,  2701,  2591,
    2592,  2702,  2703,  2704,  2593,  2594,  2705,  2595,  2596,  2706,
       0,  2707,  2708,  2709,  2710,  2711,  2712,  2599,  2713,  2714,
    2715,  2601,  2716,  2602,  2603,  2717,     0,  2718,  2719,  2720,
       0,  2721,  2722,  2608,  2609,  2610,  2723,  2724,  2613,  2614,
    2725,  2726,  2727,  2731,  2616,  2728,  2618,  2732,  2619,  2733,
    2620,  2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,  2734,
    2629,  2630,  2631,  2632,  2735,     0,  2736,  2737,     0,  2738,
    2739,  2742,     0,  2743,  2635,  2636,  2637,  2638,  2744,  2745,
    2641,  2746,  2642,  2643,  2644,  2645,  2646,  2647,  2648,  2649,
    2650,  2749,  2750,  2751,     0,  2753,  2754,  2755,  2756,  2757,
       0,  2758,  2759,  2760,  2761,  2762,  2763,  2764,     0,  2765,
    2766,  2767,  2768,  2769,  2770,  2771,  2799,  2772,     0,  2773,
    2801,  2774,  2778,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,  1116,  2775,  1136,  1137,  2776,
    1140,  2777,  2779,  2780,  2781,  2782,  2783,  2784,  2785,  2786,
    2787,     0,  2871,  2872,  2752,  2873,     0,  2874,  2875,  2876,
    2877,  2878,  2879,     0,  2880,  2883,  2884,  2885,     0,  2888,
    2889,  2894,  2895,  2896,  2897,  2898,  2899,     0,  2900,  2901,
    2902,  2903,  2904,  2905,  2907,  2909,  2910,     0,  2911,  2912,
    2913,  2914,  2915,  2916,  2917,  2918,  2919,  2922,  2923,  2926,
    2927,  2928,     0,  2929,  2930,  2931,  2932,     0,  2934,  2935,
    2936,     0,  2939,  2940,  2941,     0,  2942,  2943,  2944,     0,
    2945,  2946,  2947,  2788,  2789,  2948,  2790,  2791,  2950,  2792,
    2793,  2951,  2794,  2795,  2796,  2952,  2797,  2798,  2953,  2954,
    2800,  2955,  2956,  2957,  2958,  2803,  2804,  2959,  2805,  3018,
    2806,  3019,  2807,  3020,  2808,  2809,  2810,  2811,  2812,  3021,
    3022,  3023,  2813,  2814,  2815,  2816,  2817,  2818,  3024,  2819,
    2821,  2823,  2825,  2826,  2827,  2828,  3025,  2829,  2830,  2831,
    2832,  2833,  3026,  2835,  3027,     0,  3028,  3029,  2836,  2837,
    3030,  2838,  2839,  2840,  2841,  2842,  2843,  3031,  2844,  2845,
    2846,  3032,  3033,  3034,  2848,  3035,  2849,  3038,  2850,  3039,
    3040,  2851,  3041,  2852,  2853,  3042,  2854,  3043,  3044,  3045,
    2597,  3046,  3048,  2857,  3047,  2859,  3049,  3050,  2860,  2861,
    1544,  1546,  1547,  3051,  2968,  2862,  2863,  2864,  2865,  2866,
    3052,  3053,  3054,     0,  3055,  2868,  2869,  2870,  3056,     0,
    3057,  3058,     0,  3059,  3061,  3062,     0,  3063,  3064,  3065,
    3066,  3067,  3068,  3069,     0,  3070,  3071,  3072,  3075,  3076,
    3077,  3112,  3113,     0,  3114,  3115,     0,  3117,  3118,  3119,
    3120,  3121,  3122,     0,  3123,  3124,     0,  3125,  3126,  3127,
       0,  3128,  3129,  3130,     0,  3133,  3136,  3137,  3138,  3140,
    3141,  3142,  3143,  3144,     0,  3147,  3169,  3170,  3171,  3172,
    3173,  3174,     0,  3175,  3176,  3177,  3178,  3179,  3180,     0,
    3181,  3182,  3183,  3184,     0,  3185,  3186,  3187,     0,  3203,
    3204,  3205,     0,  3206,  3207,     0,  3208,  3209,  3210,     0,
    3211,  2960,  3212,  3222,  2961,  2962,  2963,  3213,  3221,  3223,
    2964,  3224,  2965,  2966,  3225,  3226,  3227,  3235,  2969,  2970,
    3232,  2971,  3233,  2972,  2973,  2974,  2975,  2976,  2977,  3234,
    2978,  2979,  2980,  2981,  2982,  2983,  2823,  3239,  2823,  3240,
    3241,  2823,  2823,  2988,  2989,  2990,  3245,     0,  3246,  3247,
    3250,  2995,  2996,  3251,  3253,  2997,     0,     0,     0,  2998,
    2999,  3000,     0,     0,  3001,     0,     0,     0,  3002,  3003,
       0,     0,  3004,  3005,     0,     0,  3007,     0,  3009,  3010,
       0,     0,  3011,  3012,     0,  3013,     0,  3015,  3016,  3017,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3078,
    3079,  3080,  3081,     0,  3083,  3084,     0,     0,  3085,     0,
       0,     0,     0,     0,     0,  3086,     0,  3087,     0,  3088,
    2847,     0,  3089,     0,     0,     0,     0,  2823,     0,     0,
       0,     0,  3091,  3092,     0,  3093,     0,  3094,     0,  3095,
    3096,  3097,     0,  3098,  3099,     0,  3101,     0,  3103,     0,
    3105,  3106,  3107,     0,     0,  3109,  3110,  3111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3148,     0,     0,     0,  3150,  3151,
       0,     0,     0,  3152,     0,  3153,  3154,     0,  3155,  3156,
       0,     0,     0,  3158,     0,     0,  3160,  3161,  3162,     0,
    3163,  3164,  3165,  3166,     0,     0,  3167,  3168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,  3192,
       0,   186,     0,     0,   190,  3193,  3194,  3195,   228,     0,
       0,  3196,  3197,     0,     0,  3199,  3200,     0,     0,  3201,
       0,  2967,     0,     0,     0,     0,     0,     0,     0,   271,
       0,     0,     0,  3214,  3215,     0,  3216,     0,  3217,     0,
       0,  3219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3228,     0,  3229,  3230,  3231,     0,     0,     0,     0,
       0,     0,  3236,  3237,  3238,     0,     0,     0,     0,  3242,
    3243,  3244,     0,     0,     0,     0,  3248,  3249,     0,     0,
    3252,     0,     0,     0,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   312,   312,
     312,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3082,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,     0,   312,   312,     0,   312,     0,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,     0,     0,     0,     0,     0,     0,   608,
     608,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   683,   686,   683,
     683,   689,   683,   691,   683,   693,     0,     0,     0,     0,
     747,   748,   749,   683,   752,   753,   754,   755,   756,   757,
     758,   759,     0,     0,     0,     0,   764,   766,     0,     0,
       0,   683,   789,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   228,
       0,   803,   804,   805,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   228,   228,   228,     0,     0,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,     0,     0,     0,     0,
       0,     0,   683,   608,     0,     0,     0,     0,     0,   312,
     312,   312,     0,     0,   683,   608,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,    18,     0,    19,     0,    21,   191,
     192,   193,   194,   195,    27,     0,   196,   197,     0,     0,
       0,     0,   198,     0,   183,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,    52,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,  1102,  1102,  1102,
    1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,   683,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   608,  1134,  1102,  1102,     0,     0,  1102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,   683,
     683,   683,   683,   683,   683,   683,   683,   683,   683,   683,
     683,  1189,   683,   683,   683,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,    87,     0,     0,     0,     0,   312,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   228,     0,
       0,   228,     0,     0,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
    1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,
    1102,  1102,   608,  1102,  1102,     0,  1102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1375,     0,
       0,     0,     0,     0,  1381,     0,     0,  1385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,   228,     0,     0,  1422,     0,     0,     0,   608,  1428,
    1430,   683,   683,  1433,  1434,  1435,  1436,  1437,   683,  1439,
    1440,  1441,  1442,  1443,     0,  1446,  1447,  1448,  1449,     0,
     683,   683,  1455,     0,     0,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1466,   683,  1468,  1469,  1470,  1471,  1472,
    1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,   683,   683,
     683,   683,   683,  1486,  1487,  1488,  1489,  1490,     0,     0,
     228,   228,  1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,
    1503,  1504,  1505,  1506,  1507,   683,  1509,  1510,  1511,  1512,
    1513,  1514,   683,   683,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     683,   683,   683,  1520,   683,   683,     0,   683,   683,   683,
     683,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   608,     0,   608,  1540,   683,  1102,  1102,   683,  1102,
    1102,  1102,  1102,  1102,  1102,  1102,  1102,   683,   683,   683,
     683,   683,     0,     0,   228,   228,     0,     0,   228,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   683,     0,     0,
       0,     0,   683,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1599,     0,  1601,     0,     0,     0,  1605,  1606,
    1607,  1608,     0,     0,     0,     0,     0,     0,     0,  1616,
       0,  1618,  1619,  1620,  1622,  1623,  1625,  1627,  1628,  1629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1645,     0,   683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1655,  1656,  1657,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,  1674,  1675,     0,
       0,     0,     0,     0,     0,     0,     0,   228,  1682,     0,
    1683,  1684,  1686,  1688,     0,     0,     0,     0,  1693,     0,
       0,     0,   683,   683,   683,   228,   683,  1702,     0,  1704,
       0,     0,   683,     0,   228,   683,   683,   683,   683,   683,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   683,     0,     0,     0,     0,     0,     0,     0,     0,
    1733,   683,     0,   683,     0,     0,  1739,     0,     0,     0,
     683,     0,     0,   228,     0,   608,   228,     0,     0,     0,
       0,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1102,     0,     0,  1914,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   683,     0,     0,   683,     0,  1947,  1948,
    1949,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   683,
      15,     0,     0,     0,     0,     0,     0,    18,     0,    19,
       0,    21,   191,   192,   193,   194,  1537,    27,     0,   206,
     197,     0,     0,     0,     0,   198,     0,   183,   184,     0,
       0,     0,   608,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,  2117,     0,
       0,     0,    52,     0,   200,     0,     0,     0,     0,     0,
    2124,  2125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2141,     0,
     683,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   683,  2150,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2166,  2167,   683,   683,  2170,  2171,  2172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    59,
    2182,     0,  2183,  2184,  2185,  2186,  2187,     0,  2188,  2189,
       0,     0,     0,     0,   683,   683,     0,     0,     0,     0,
       0,  2200,   228,     0,     0,  2202,  2203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2220,     0,     0,  2223,     0,     0,     0,     0,   683,
       0,     0,   608,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,   683,  2230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   228,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,     0,
       0,     0,     0,  2246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   608,     0,     0,     0,
       0,     0,  2264,  2265,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,    87,     0,  2279,
       0,     0,     0,     0,     0,     0,     0,    90,    91,   207,
     208,   209,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,   608,   683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,  1538,     0,   221,   222,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,    18,     0,    19,     0,    21,   191,   192,
     193,   194,   195,    27,     0,   206,   197,     0,     0,     0,
       0,   198,     0,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,     0,    52,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    59,     0,     0,     0,     0,
       0,     0,     0,  2538,     0,     0,     0,  2542,  2544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2556,  2558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2572,  2573,  2574,  2575,  2576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,     0,
       0,   683,     0,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,  2600,     0,     0,     0,     0,     0,   683,     0,
     683,     0,   683,     0,   683,     0,     0,     0,  2611,  2612,
       0,     0,     0,     0,     0,     0,     0,  2617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2633,     0,
       0,     0,     0,     0,   683,     0,     0,     0,     0,     0,
     683,   683,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,   207,   208,   209,   210,   211,
     212,     0,     0,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,   221,   222,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,     0,
       0,  2542,     0,     0,     0,  2542,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     145,   145,     0,     0,     0,   145,     0,     0,     0,     0,
       0,  1540,  1540,  1540,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,  2834,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     683,  2856,     0,     0,     0,     0,  2858,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   683,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   606,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   682,
       0,   682,   682,     0,   682,     0,   682,     0,     0,     0,
       0,     0,     0,     0,   682,   682,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   785,     0,   682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,     0,     0,  2542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,  1540,     0,
    1540,     0,     0,  1540,  1540,    15,     0,     0,  2991,  2992,
    2993,  2994,    18,     0,    19,     0,    21,   191,   192,   193,
     194,  1537,    27,     0,   206,   197,     0,     0,     0,     0,
     198,     0,   183,   184,     0,     0,     0,  3006,     0,  3008,
       0,     0,     0,     0,   682,   606,     0,     0,   683,     0,
     785,   145,   145,   145,     0,     0,   682,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,    52,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3100,     0,  3102,
       0,     0,     0,     0,     0,     0,   683,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   683,     0,     0,     0,
       0,     0,    58,     0,    59,     0,     0,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   683,     0,     0,   683,   606,   606,
     606,   606,   606,   606,   606,   606,   606,   606,   606,   606,
     606,   682,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   606,     0,   606,   606,     0,     0,
     606,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,  3198,     0,     0,     0,     0,
       0,     0,     0,   683,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3218,     0,     0,     0,   683,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682,   682,   682,   682,   682,   682,   682,   682,   682,   682,
     682,   682,   682,   682,   682,   682,   682,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,   207,   208,   209,   210,   211,   212,
       0,     0,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
       0,     0,   221,   222,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   954,   954,   954,   954,   954,   954,   954,   954,   954,
     954,   954,   954,   954,   954,   954,   954,     0,   954,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   682,
     180,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     606,   682,     0,   682,   682,     0,     0,     0,     0,     0,
     682,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   682,   682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682,   682,   682,   682,   682,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   682,     0,     0,
       0,     0,     0,     0,   682,   682,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   682,   682,   682,     0,   682,   682,     0,   682,
     682,   682,   682,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,     0,   606,     0,   682,   606,   606,
     682,   606,   606,   606,   606,   606,   606,   606,   606,   682,
     682,   682,   682,   682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   682,
       0,     0,     0,     0,   682,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     456,   457,     0,     0,     0,     0,     0,   628,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   682,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   685,     0,   685,   685,     0,
     685,     0,   685,     0,     0,     0,     0,     0,     0,     0,
     685,   685,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   682,   682,   682,     0,   682,     0,
       0,     0,     0,     0,   682,     0,     0,   682,   682,   682,
     682,   682,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   682,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   682,     0,   682,     0,     0,     0,     0,
       0,     0,   682,     0,     0,     0,    19,   606,    21,   191,
     192,   193,     0,   195,    27,     0,   196,   197,     0,     0,
     685,   628,   198,     0,   183,   184,     0,     0,     0,     0,
     881,     0,   685,   959,   627,   627,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   684,     0,   687,   688,     0,   690,     0,   692,
       0,     0,     0,     0,     0,     0,     0,   750,   751,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   788,     0,     0,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,   830,   833,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   925,
     956,     0,     0,     0,    58,     0,    59,     0,     0,     0,
       0,     0,     0,     0,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   685,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     628,  1135,   628,   628,     0,   682,   628,     0,   682,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   682,     0,     0,     0,     0,   685,   685,   685,   685,
     685,   685,   685,   685,   685,   685,   685,   685,   685,   685,
     685,   685,   685,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   682,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   682,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,   682,   682,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,   682,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   682,     0,     0,   606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   682,     0,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,     0,   628,     0,     0,     0,     0,     0,
     682,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   685,     0,     0,     0,     0,
       0,     0,   881,     0,     0,     0,     0,     0,  1408,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,   685,   606,   685,
     685,     0,     0,     0,     0,     0,   685,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   685,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   685,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,   685,   685,   685,
     685,     0,     0,     0,     0,     0,  1491,  1492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   606,   682,
       0,     0,     0,   685,     0,     0,     0,     0,     0,     0,
     685,   685,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   685,   685,
     685,     0,   685,   685,     0,   685,   685,   685,   685,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   628,
       0,   628,  1395,   685,   628,   628,   685,   628,   628,   628,
     628,   628,   628,   628,   628,   685,   685,   685,   685,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   627,  1429,     0,  1431,  1432,     0,     0,
       0,     0,     0,  1438,     0,   685,     0,     0,     0,     0,
     685,     0,     0,     0,     0,  1453,  1454,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1467,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1481,  1482,  1483,  1484,  1485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   685,     0,     0,     0,     0,
    1508,     0,     0,     0,     0,     0,     0,  1515,  1516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1517,  1518,  1519,     0,  1521,
    1522,     0,  1524,  1525,  1526,  1527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1535,     0,  1536,     0,
       0,     0,     0,     0,     0,     0,     0,  1694,  1695,  1696,
     685,   685,   685,     0,   685,     0,  1703,     0,  1705,  1706,
     685,     0,     0,   685,   685,   685,   685,   685,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   685,
       0,     0,  1429,     0,     0,     0,     0,  1536,     0,   685,
       0,   685,     0,     0,     0,     0,     0,     0,   685,     0,
       0,     0,     0,   628,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682,     0,     0,   682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1697,  1698,  1699,
     682,  1701,   682,     0,   682,     0,   682,  1707,     0,     0,
    1710,  1711,  1712,  1713,  1714,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1724,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1734,     0,  1736,     0,
       0,     0,     0,     6,     0,  1743,   682,     0,     0,     0,
     627,     0,   682,   682,     0,     0,     0,     0,     0,   628,
       0,     0,  1915,     0,    19,     0,    21,   191,   192,   193,
       0,   195,    27,     0,   206,   197,     0,     0,     0,     0,
     198,     0,   183,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     881,   685,     0,     0,   685,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,   685,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     628,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1944,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   682,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   682,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,   685,     0,
       0,     0,     0,     0,  2000,     0,     0,     0,     0,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     685,   685,     0,     0,     0,     0,     0,  2035,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   685,   685,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,    87,     0,     0,     0,     0,   685,     0,     0,
     628,     0,    90,    91,   207,   208,   209,   210,   211,   212,
       0,   685,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,   685,     0,     0,     0,
       0,     0,     0,     0,     0,  2143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2148,     0,     0,     0,
     682,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,  2168,  2169,     0,
       0,     0,   221,   222,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,   628,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2194,
    2195,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   628,   685,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   682,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   682,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,     0,     0,   682,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2259,     0,   360,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   682,    31,     0,    32,    33,
      34,    35,    36,    37,     0,    38,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,   682,     0,     0,
       0,  2308,  2309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,    59,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,     0,     0,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,     0,     0,   685,     0,   685,     0,
     685,     0,   685,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,   685,     0,     0,     0,     0,     0,   685,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,    87,    88,  2580,     0,    89,  2581,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    96,    97,     0,
       0,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,     0,   106,     0,   107,   108,     0,     0,     0,
     109,   110,     0,   111,     0,     0,     0,     0,     0,     0,
     112,     0,     0,  2604,     0,  2605,     0,  2606,     0,  2607,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,   126,   127,   128,   129,   130,     0,     0,     0,  2634,
       0,     0,     0,     0,     0,  2639,  2640,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,     0,    32,    33,    34,    35,    36,
      37,     0,    38,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   685,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   685,     0,    44,    45,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,    51,    52,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
      59,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    66,     0,  2855,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2867,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,    70,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,    87,    88,
       0,     0,    89,     0,   685,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,     0,     0,
     106,     0,   107,   108,   685,     0,     0,   109,   110,     0,
     111,     0,     0,  3014,     0,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   685,   113,     0,   685,     0,     0,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,   126,   127,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   685,     0,     0,     0,     0,     0,     6,     0,     0,
     926,   486,   927,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,   685,     0,     0,    18,     0,    19,     0,
      21,   191,   192,   193,   194,   831,    27,   928,   196,   197,
     929,  3108,   489,     0,   198,   930,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,   931,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3157,
       0,     0,  3159,    44,   490,    46,    47,    48,   491,   492,
     493,   494,   495,   496,   497,   498,     0,   499,     0,   500,
     501,   502,   503,   504,   505,   506,     0,   507,   508,     0,
       0,    52,     0,   509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3202,     0,
       0,     0,     0,     0,     0,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,     0,     0,
    3220,     0,   523,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,    58,   537,    59,   538,
     539,   540,   541,   542,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,   860,   861,   862,     0,     0,   544,
     545,   546,   547,   863,   864,   865,   866,   548,   867,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   551,   552,   553,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,     0,     0,    72,    73,   868,
       0,     0,   869,   870,   871,   872,     0,   873,   874,   566,
     567,   932,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   933,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   569,   570,   571,    77,   934,    79,    80,   935,
      82,    83,    84,    85,    86,     0,    87,     0,   572,   573,
       0,   936,     0,     0,     0,     0,    90,    91,   937,   938,
     939,   940,   941,   942,     0,     0,   943,   944,   945,   946,
     947,   948,   949,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   588,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   590,   591,   592,
       0,   593,   594,     0,   876,   877,   878,   595,   596,     0,
     879,     0,   880,   597,   598,   599,     0,     0,     0,     0,
       0,     0,     6,     0,     0,   485,   486,     0,   950,     0,
       0,     0,     0,     0,    15,     0,   951,   952,   128,   129,
     130,    18,     0,    19,     0,    21,   191,   192,   193,   194,
     831,    27,   488,   196,   197,     0,     0,   489,     0,   198,
       0,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,   490,
      46,    47,    48,   491,   492,   493,   494,   495,   496,   497,
     498,     0,   499,     0,   500,   501,   502,   503,   504,   505,
     506,     0,   507,   508,     0,     0,    52,     0,   509,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,     0,     0,     0,     0,   523,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,    58,   537,    59,   538,   539,   540,   541,   542,     0,
       0,     0,     0,     0,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   549,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,   551,   552,   553,     0,     0,     0,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,   567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   568,   569,   570,   571,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,    87,     0,   572,   573,     0,     0,     0,     0,     0,
       0,    90,    91,   937,   938,   939,   940,   941,   942,     0,
       0,   943,   944,   945,   946,   947,   948,   949,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   588,     0,     0,     0,     0,     0,     0,     0,
       0,   589,   590,   591,   592,     0,   593,   594,     0,     0,
       0,     0,   595,   596,     0,     0,     0,     0,   597,   598,
     599,     0,     0,     0,     0,     0,     0,     6,     0,     0,
     485,   486,     0,   950,     0,     0,     0,     0,     0,    15,
       0,   951,   952,   128,   129,   130,    18,     0,    19,     0,
      21,   191,   192,   193,   194,   487,    27,   488,   206,   197,
       0,     0,   489,     0,   198,     0,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,   490,    46,    47,    48,   491,   492,
     493,   494,   495,   496,   497,   498,     0,   499,     0,   500,
     501,   502,   503,   504,   505,   506,     0,   507,   508,     0,
       0,    52,     0,   509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,     0,     0,
       0,     0,   523,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,    58,   537,    59,   538,
     539,   540,   541,   542,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   551,   552,   553,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   569,   570,   571,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,    87,     0,   572,   573,
       0,     0,     0,     0,     0,     0,    90,    91,   574,   575,
     576,   577,   578,   579,     0,     0,   580,   581,   582,   583,
     584,   585,   586,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   588,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   590,   591,   592,
       0,   593,   594,     0,     0,     0,     0,   595,   596,     0,
       0,     0,     0,   597,   598,   599,     0,     0,     0,     0,
       0,     0,     6,     0,     0,   485,   486,     0,   600,     0,
       0,     0,     0,     0,    15,   601,   602,   603,   128,   129,
     130,    18,     0,    19,     0,    21,   191,   192,   193,   194,
    1531,    27,   488,   206,   197,     0,     0,   489,     0,   198,
       0,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,   490,
      46,    47,    48,   491,   492,   493,   494,   495,   496,   497,
     498,     0,   499,     0,   500,   501,   502,   503,   504,   505,
     506,     0,   507,   508,     0,     0,    52,     0,   509,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,     0,     0,     0,     0,   523,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,    58,   537,    59,   538,   539,   540,   541,   542,     0,
       0,     0,     0,     0,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,   544,   545,   546,   547,     0,     0,
       0,     0,   548,     0,   549,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,   551,   552,   553,     0,     0,     0,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,   567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   568,   569,   570,   571,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,    87,     0,   572,   573,     0,     0,     0,     0,     0,
       0,    90,    91,   574,   575,   576,   577,   578,   579,     0,
       0,   580,   581,   582,   583,   584,   585,   586,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   588,     0,     0,     0,     0,     0,     0,     0,
       0,   589,   590,   591,   592,     0,   593,   594,     0,     0,
       0,     0,   595,   596,     0,     0,     0,     0,   597,   598,
     599,     0,     0,     0,     0,     0,     0,     6,     0,     0,
     485,   486,     0,   600,     0,     0,     0,     0,     0,    15,
    1532,   602,   603,   128,   129,   130,    18,     0,    19,     0,
      21,   191,   192,   193,   194,   831,    27,   488,   206,   197,
       0,     0,   489,     0,   198,     0,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,   490,    46,    47,    48,   491,   492,
     493,   494,   495,   496,   497,   498,     0,   499,     0,   500,
     501,   502,   503,   504,   505,   506,     0,   507,   508,     0,
       0,    52,     0,   509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,     0,     0,
       0,     0,   523,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,    58,   537,    59,   538,
     539,   540,   541,   542,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,   544,
     545,   546,   547,     0,     0,     0,     0,   548,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   551,   552,   553,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   569,   570,   571,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,    87,     0,   572,   573,
       0,     0,     0,     0,     0,     0,    90,    91,   574,   575,
     576,   577,   578,   579,     0,     0,   580,   581,   582,   583,
     584,   585,   586,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   588,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   590,   591,   592,
       0,   593,   594,     0,     0,     0,     0,   595,   596,     0,
       0,     0,     0,   597,   598,   599,     0,     0,     0,     0,
       6,     0,     0,   485,   486,     0,     0,     0,   600,     0,
       0,     0,     0,     0,     0,     0,   602,   603,   128,   129,
     130,    19,     0,    21,   191,   192,   193,     0,   831,    27,
     488,   196,   197,     0,     0,   489,     0,   198,     0,   183,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,   490,    46,    47,
      48,   491,   492,   493,   494,   495,   496,   497,   498,     0,
     499,     0,   500,   501,   502,   503,   504,   505,   506,     0,
     507,   508,     0,     0,     0,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,     0,     0,     0,     0,   523,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,    58,
     537,    59,   538,   539,   540,   541,   542,     0,     0,     0,
       0,     0,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
     551,   552,   553,     0,     0,     0,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,     0,     0,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   566,   567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,   569,   570,   571,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,    87,
       0,   572,   573,     0,     0,     0,     0,     0,     0,    90,
      91,   937,   938,   939,   940,   941,   942,     0,     0,   943,
     944,   945,   946,   947,   948,   949,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     588,     0,     0,     0,     0,     0,     0,     0,     0,   589,
     590,   591,   592,     0,   593,   594,     0,     0,     0,     0,
     595,   596,     0,     0,     0,     0,   597,   598,   599,     0,
       0,     0,     0,     6,     0,     0,   485,   486,     0,     0,
       0,   950,     0,     0,     0,     0,     0,     0,     0,   951,
     952,   128,   129,   130,    19,     0,    21,   191,   192,   193,
       0,   831,    27,   488,   206,   197,     0,     0,   489,     0,
     198,     0,   183,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
     490,    46,    47,    48,   491,   492,   493,   494,   495,   496,
     497,   498,     0,   499,     0,   500,   501,   502,   503,   504,
     505,   506,     0,   507,   508,     0,     0,     0,     0,   509,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,     0,     0,     0,     0,   523,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,    58,   537,    59,   538,   539,   540,   541,   542,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,   544,   545,   546,   547,     0,
       0,     0,     0,   548,     0,   549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   550,   551,   552,   553,     0,     0,     0,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,     0,     0,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   566,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   568,   569,   570,
     571,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,    87,     0,   572,   573,     0,     0,     0,     0,
       0,     0,    90,    91,   574,   575,   576,   577,   578,   579,
       0,     0,   580,   581,   582,   583,   584,   585,   586,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   588,     0,     0,     0,     0,     0,     0,
       0,     0,   589,   590,   591,   592,     0,   593,   594,     0,
       0,     0,     0,   595,   596,     0,     0,     0,     0,   597,
     598,   599,     0,     0,     0,     0,     6,     0,     0,   485,
     486,     0,     0,     0,   600,     0,     0,     0,     0,     0,
       0,     0,   602,   603,   128,   129,   130,    19,     0,    21,
     191,   192,   193,     0,   831,    27,   488,   206,   197,     0,
       0,   489,     0,   198,     0,   183,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,   490,    46,    47,    48,   491,   492,   493,
     494,   495,   496,   497,   498,     0,   499,     0,   500,   501,
     502,   503,   504,   505,   506,     0,   507,   508,     0,     0,
       0,     0,   509,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,     0,     0,     0,
       0,   523,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,    58,   537,    59,   538,   539,
     540,   541,   542,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   551,   552,   553,     0,
       0,     0,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,     0,     0,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,   191,   192,   193,     0,   195,    27,     0,   206,   197,
       0,     0,     0,     0,   198,     0,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     568,   569,   570,   571,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,    87,     0,   572,   573,     0,
       0,     0,     0,     0,     0,    90,    91,   574,   575,   576,
     577,   578,   579,     0,     0,   580,   581,   582,   583,   584,
     585,   586,   587,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,     0,   110,   588,     0,     0,     0,
       0,     0,     0,   199,     0,   589,   590,   591,   592,     0,
     593,   594,     0,   200,     0,     0,   595,   596,     0,     0,
       0,     0,   597,   598,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1910,     0,     0,
       0,     0,     0,     0,     0,   602,   603,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,   662,    27,   488,     0,     0,     0,
       0,   489,     0,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,   207,   208,
     209,   210,   211,   212,     0,     0,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   663,     0,     0,   110,   491,   492,   493,
     494,   495,   496,   497,   498,     0,   499,     0,   500,   501,
     502,   503,   664,   505,   506,     0,   507,   508,     0,     0,
       0,     0,   665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1287,     0,
       0,     0,     0,     0,     0,     0,   221,   222,   128,   129,
     130,     0,     0,     0,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,     0,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,     0,   537,     0,   538,   539,
     540,   541,   542,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,   544,   545,
     546,   547,     0,     0,     0,     0,   548,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   551,   552,   553,     0,
       0,     0,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     568,   569,   570,   571,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,   572,   573,     0,
       0,     0,     0,   485,   486,     0,     0,   666,   667,   668,
     669,   670,   671,     0,     0,   672,   673,   674,   675,   676,
     677,   678,   587,    21,     0,     0,     0,     0,   662,    27,
     488,     0,     0,     0,     0,   489,   588,     0,     0,   183,
     184,     0,     0,     0,     0,   589,   590,   591,   592,     0,
     593,   594,     0,     0,     0,     0,   595,   596,     0,     0,
       0,     0,   597,   598,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   679,     0,     0,
       0,     0,     0,     0,     0,   680,   681,     0,   129,   130,
       0,     0,     0,     0,     0,     0,     0,   663,     0,     0,
       0,   491,   492,   493,   494,   495,   496,   497,   498,     0,
     499,     0,   500,   501,   502,   503,   664,   505,   506,     0,
     507,   508,     0,     0,     0,     0,   665,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,     0,     0,     0,     0,   523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,     0,
     537,     0,   538,   539,   540,   541,   542,     0,     0,     0,
       0,     0,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,   544,   545,   546,   547,     0,     0,     0,     0,
     548,     0,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
     551,   552,   553,     0,     0,     0,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   566,   567,   924,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,   569,   570,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   572,   573,     0,     0,     0,     0,   485,   486,     0,
       0,   666,   667,   668,   669,   670,   671,     0,     0,   672,
     673,   674,   675,   676,   677,   678,   587,    21,     0,     0,
       0,     0,   662,    27,   488,     0,     0,     0,     0,   489,
     588,     0,     0,   183,   184,     0,     0,     0,     0,   589,
     590,   591,   592,     0,   593,   594,     0,     0,     0,     0,
     595,   596,     0,     0,     0,     0,   597,   598,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   679,     0,     0,     0,     0,     0,     0,     0,   680,
     681,     0,   129,   130,     0,     0,     0,     0,     0,     0,
       0,   663,     0,     0,     0,   491,   492,   493,   494,   495,
     496,   497,   498,     0,   499,     0,   500,   501,   502,   503,
     664,   505,   506,     0,   507,   508,     0,     0,     0,     0,
     665,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,     0,     0,     0,     0,   523,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,     0,   537,     0,   538,   539,   540,   541,
     542,     0,     0,     0,     0,     0,     0,   543,     0,     0,
       0,     0,     0,     0,     0,     0,   544,   545,   546,   547,
       0,     0,     0,     0,   548,     0,   549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   550,   551,   552,   553,     0,     0,     0,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   566,   567,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,   569,
     570,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   572,   573,     0,     0,     0,
       0,   485,   486,     0,     0,   666,   667,   668,   669,   670,
     671,     0,     0,   672,   673,   674,   675,   676,   677,   678,
     587,    21,     0,     0,     0,     0,   662,    27,   488,     0,
       0,     0,     0,   489,   588,     0,     0,   183,   184,     0,
       0,     0,     0,   589,   590,   591,   592,     0,   593,   594,
       0,     0,     0,     0,   595,   596,     0,     0,     0,     0,
     597,   598,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   679,     0,     0,     0,     0,
       0,     0,     0,   680,   681,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,   663,     0,     0,     0,   491,
     492,   493,   494,   495,   496,   497,   498,     0,   499,     0,
     500,   501,   502,   503,   664,   505,   506,     0,   507,   508,
       0,     0,     0,     0,   665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,     0,
       0,     0,     0,   523,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,     0,   537,     0,
     538,   539,   540,   541,   542,     0,     0,     0,     0,     0,
       0,   543,     0,     0,     0,     0,     0,     0,     0,     0,
     544,   545,   546,   547,     0,     0,     0,     0,   548,     0,
     549,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,     0,     0,     0,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   568,   569,   570,   571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   572,
     573,     0,     0,     0,     0,     0,     0,     0,     0,   666,
     667,   668,   669,   670,   671,     0,     0,   672,   673,   674,
     675,   676,   677,   678,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   588,     0,
       0,     0,     0,     0,     0,     0,     0,   589,   590,   591,
     592,     0,   593,   594,     0,     0,     0,     0,   595,   596,
       0,     0,     0,     0,   597,   598,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1946,
       0,     0,     0,     0,     0,     0,     0,   680,   681,     0,
     129,   130
};

static const yytype_int16 yycheck[] =
{
       0,    32,   125,   403,   341,   248,   378,   379,   380,   381,
     807,    28,    28,    13,    14,    11,    21,   376,   377,    28,
      28,    11,    11,    28,    97,    83,    32,    32,   100,   101,
     104,    36,    38,     0,    84,    85,    97,    97,    25,   398,
     399,    19,    48,    49,    49,    97,    13,    26,    27,    26,
      32,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,    98,    99,    49,    83,    40,
      19,   103,    83,    83,   198,   199,   200,    32,   104,   602,
     603,   480,   480,   606,    21,   483,    38,   485,    14,   104,
     480,    28,    26,   104,    49,    32,    48,   220,   485,    36,
     131,    98,    99,    31,   304,   305,   137,    32,   108,   491,
      32,   493,    49,    39,    25,    37,   240,   480,    93,    94,
      31,    47,   485,    28,    49,    32,    31,    49,   133,   104,
     480,   131,    64,    65,   104,   485,    68,    69,    70,    71,
      72,    73,    49,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   356,   680,   681,   682,
      93,    94,    93,    94,   131,    38,   480,   491,   145,   493,
       0,   104,   496,   104,   480,    48,   131,    28,   485,   485,
      10,    32,   182,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   133,    21,    49,   488,
     489,    28,   136,   180,    28,    32,   131,   485,    32,   188,
     189,   145,    36,   337,   338,   339,   340,   126,   127,   100,
     101,    32,    49,   201,   131,    49,   198,   199,   200,   480,
     480,   231,   483,   483,   234,   485,   145,   237,    49,   480,
     480,   481,   483,   243,   244,   485,   180,   247,   248,   484,
     483,   486,   180,   253,   254,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   480,   180,
     198,   483,   480,   273,   274,   105,   243,   485,   480,   488,
     489,   483,   112,   485,   236,   237,   238,   198,   482,   126,
     127,   128,   486,   245,   246,   247,   248,   479,   250,   481,
     482,   131,   302,   303,   486,   305,   306,   480,   145,   133,
     483,   342,   480,   480,   481,  2699,  2700,  2701,   485,   480,
      13,    14,   483,    16,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   482,   480,   366,   480,   486,   482,   291,
     307,   485,   294,   295,   296,   297,   346,   299,   300,   480,
     481,   303,   483,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   198,   199,   200,   337,   338,   339,   340,   304,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   480,   221,   222,   483,   224,   359,   360,
     480,   391,   392,   393,   480,   481,   480,   481,   480,   485,
     480,   485,   480,   403,   482,   405,   406,   485,   485,   481,
     397,   485,   412,   486,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   485,   951,   952,
     436,   954,   358,   365,   486,   485,   403,   498,   498,   410,
     411,   412,   413,   414,   415,   435,   485,   418,   419,   420,
     421,   422,   423,   424,   480,   404,   405,   406,   407,   491,
     485,   494,   495,   480,   480,   480,   483,   483,   483,   397,
     485,   480,   480,   483,   100,   101,   481,   600,   485,   480,
     480,   482,   483,   479,   480,   480,   397,   396,   397,   479,
     479,   182,   183,    31,   480,   481,   480,   494,   495,   485,
    1149,  1150,  1151,  1152,   456,   457,   458,   488,   489,   480,
     462,   480,   464,   343,   182,   183,   480,   488,   489,   480,
     491,   492,  2906,   479,  2908,   481,   482,  2911,  2912,   480,
      32,    33,    34,   226,   405,   406,    38,   374,   375,   337,
     338,   339,   340,    24,    25,   238,    48,    49,    28,   479,
      31,   481,   482,   480,   247,   248,   679,   188,   189,   479,
     397,   481,   482,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   481,   482,   487,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   441,   442,   443,   444,
     445,   480,   992,   480,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   480,   488,   489,
     480,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,   118,   480,    32,
      33,    34,   100,   101,   496,    38,   441,   442,   443,   444,
     445,   497,   481,   482,   347,    48,    49,   304,   305,   659,
      26,    27,   480,  3047,   481,   482,   481,   482,   481,   482,
      96,   481,   482,   481,   482,   481,   482,   370,   371,    31,
      32,    33,    34,   480,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   480,   180,
     481,   482,   481,   482,   481,   482,   481,   482,   481,   482,
     403,   481,   482,   481,   482,   481,   482,   198,   481,   482,
     201,   202,   203,   204,   481,   482,   481,   482,   481,   482,
     481,   482,  1529,   481,   482,   481,   482,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     128,   480,   233,   234,   235,   481,   482,   481,   482,   481,
     482,   480,   793,   481,   482,   602,   603,   481,   482,   606,
     481,   482,   480,  1016,   481,   482,   480,  1149,  1150,  1151,
    1152,  1153,  1154,   481,   482,   481,   482,   480,  1147,  1148,
     480,   791,   480,   198,   199,   200,   201,   481,   482,   481,
     482,   480,   180,   181,   182,   183,   481,   482,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     481,   482,   481,   482,   481,   482,   231,   950,   481,   482,
     481,   482,   481,   482,   239,   481,   482,   481,   482,   481,
     482,   481,   482,   481,   482,   481,   482,   252,   481,   482,
     102,   481,   482,   481,   482,   403,   481,   482,   481,   482,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   781,   480,   783,   784,   785,   481,   482,   481,
     482,   362,   363,   481,   482,   481,   482,   382,   383,  1012,
     295,   480,   297,   298,   299,   368,   369,  1153,  1154,   380,
     365,  1147,  1148,   308,   309,   398,   399,   480,   480,   314,
     315,   316,   317,   480,   480,   480,   397,   485,   480,   483,
     483,   303,   327,   328,   329,   330,   331,   485,   333,   334,
     485,   336,   485,  1270,   485,   485,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   485,   483,    28,    28,    28,   104,    29,    28,   480,
      37,   481,   655,   481,   481,   965,   966,   967,   968,   969,
     970,   971,   481,   973,   974,   136,   482,    25,   978,   979,
     980,   981,   982,   983,   984,   482,   986,   485,   988,   480,
     990,   991,   480,   993,   994,   995,   996,   997,   480,   485,
     485,   480,  1002,  1003,  1004,  1005,  1529,   306,   480,   308,
     480,   310,   311,  1013,   480,   104,  1016,   480,   480,   318,
     480,   480,   321,   322,   323,   324,   325,   326,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,   480,   951,   952,   480,   954,   480,   480,   480,   480,
     480,   480,   480,   480,   497,   480,   461,   480,   357,   480,
     480,   480,   361,   480,   480,   480,   480,   366,   367,   480,
     480,  1594,   480,   480,   480,   487,   480,   376,   480,   480,
     480,   480,   381,   382,   480,   480,   480,   485,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,    96,   480,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,   480,   951,   952,   480,   954,   480,   480,
    1363,   480,   480,   480,   480,   480,   480,    30,    37,   480,
    1161,   480,   485,   480,   480,   480,   480,   480,   480,  1139,
     480,  1141,  1142,   480,   480,    32,    33,    34,   841,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   480,   480,   480,   480,   480,   480,  1169,
     480,   480,  1172,   480,  1174,   480,  1176,   480,  1178,   480,
     480,   485,   480,   480,   480,   480,   480,   480,   480,   480,
    1590,   480,   480,   886,   480,   480,   889,   480,   480,   480,
     480,  1201,   480,  1203,  1204,  1205,   480,   480,   480,   480,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,   480,  1218,   480,
     480,   480,   480,   480,   480,   480,   480,   480,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,   480,   480,   480,   480,   480,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,   480,   480,   480,   480,   480,
    1260,  1261,   480,  1263,   480,   480,   480,   480,   485,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,  1281,   480,  1283,   480,   480,   483,   481,   480,   480,
    1290,   484,  1292,  1293,   484,   482,   485,   485,   481,   485,
    1300,  1301,  1302,  1303,  1304,  1305,   481,  1144,  1145,   481,
     484,   481,   480,  1006,   481,   484,  1009,   482,   484,  1012,
     480,   480,   480,  1016,   480,   480,   480,   480,   480,   480,
    1330,  1331,  1669,  1333,  1334,  1335,  1336,  1337,  1338,   480,
    1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,   480,   480,
    1350,   480,  1352,  1353,   480,  1355,  1356,  1357,   480,  1359,
    1360,   480,   480,  1363,   480,  1365,   480,  1367,  1368,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,  1078,  1079,   480,   480,   480,
     480,   485,   480,    39,   480,   482,   481,   481,  1921,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   482,   484,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   481,   481,   484,   482,   482,
     482,   481,   481,   484,   480,   482,  1129,   136,   137,   138,
     139,   140,   141,   142,   143,   144,  1139,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   481,  1162,
    1163,   481,   481,  1166,   481,   480,   482,   481,   332,   482,
     482,   482,  1175,   182,   183,   482,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,    45,   480,
      39,   483,   480,   480,   480,   485,   480,   480,   480,    30,
     485,    33,   180,  1266,   484,   180,   455,   481,    33,   481,
      34,    45,    35,    34,    36,   104,    36,   104,   484,    45,
     304,  1284,   481,   427,   480,   480,   480,   480,   452,    31,
      31,    31,  1295,    31,    31,   104,   240,    47,   481,   485,
     482,   482,   482,   482,   481,   481,   470,   482,   482,   481,
    1313,   481,   481,   484,   482,   482,   482,   482,   481,  1322,
     482,   481,  1663,   482,   482,   482,   482,   481,   480,   482,
     481,   480,   482,   481,   481,   356,   482,   482,    28,   482,
     482,   481,   481,   484,   482,   482,   482,   481,   481,   480,
     482,   481,  1662,   481,   481,   484,   482,   482,  1361,   481,
    1363,  1364,   485,   482,   482,   482,  1369,   482,   482,  2016,
    1680,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   481,   397,   482,   482,   482,   482,   480,   482,
     481,   104,   482,   482,   482,   482,   482,   482,   482,   482,
     481,   481,   481,   480,   482,   481,    45,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   481,
      31,   482,   482,   482,   482,   482,   482,   481,   481,   484,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   481,   481,   481,   481,  1757,  1758,  1759,
    1760,   481,  1762,   481,  1764,   481,   428,   482,   480,   482,
    1770,  1771,  1772,   482,   482,  1775,  1776,  1777,  1778,   482,
    1780,   482,  1782,   481,  1784,   482,   482,  1787,  1788,  1789,
    1790,   481,   481,   481,  1794,   482,   480,  1797,   480,   480,
     486,   481,    31,   482,   482,  1805,   482,  1807,   481,   480,
     482,  1811,  1812,   482,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,   482,  1827,   482,   481,
     481,   481,   481,   481,   481,    31,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,   482,   481,    31,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,  1858,  1859,
    1860,  1861,   481,   481,   481,  1865,  1866,  1867,  1868,   482,
     481,    31,   482,   482,   481,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,   481,   481,   481,   481,
     481,   481,   481,  1893,  1894,  1895,   481,  1897,  1898,   481,
    1900,  1901,   481,   481,  1904,   482,  1906,   481,   481,   481,
     481,    47,   482,   481,   481,   481,   481,   481,   481,  1919,
     482,   481,    28,   482,   482,   482,   482,   481,  1928,  1929,
     482,   482,   482,  1933,   482,   482,   482,  1937,   481,   484,
     482,   482,   482,   481,   387,   482,   482,   481,   104,   482,
     481,   481,   481,  1953,   482,  1955,   482,   481,   485,   482,
     481,   486,   482,   384,   482,   385,   482,   482,   482,  1969,
     482,   482,   482,   482,   482,   482,   481,   131,   482,   482,
     482,   482,   482,   481,  1984,   481,  1986,  2018,   481,   481,
     481,  1991,   481,   481,   484,    28,   482,  1997,   482,   482,
     481,  2001,  2002,   481,  2004,  2005,  2006,   481,  2008,  2009,
     481,   481,  2012,  2013,   481,  2015,   481,   486,   481,   131,
     486,   131,   482,   482,  2024,  2025,   131,   131,  2028,   486,
    2030,   386,  2032,  2033,   481,   481,  1156,   482,  2038,   481,
     481,  2041,   481,  2043,   481,   389,   482,  2047,  2048,   482,
    2050,   486,   481,  2053,  2054,  2055,  2056,  2057,  2058,   481,
    2060,  2061,  2062,   481,  2064,  2065,  2066,  2067,  2068,   481,
     481,  2071,  2072,  2073,  2074,   481,  2076,   481,   486,   481,
     388,   482,  2082,   481,   481,  2085,   482,  2087,   482,  2089,
    2090,  2091,   481,  1921,   482,   481,   481,    -1,   481,   481,
    2100,  2101,  1143,   482,  2104,   482,   481,  1289,   482,   482,
     482,   482,   481,  1155,   482,   482,   482,   482,   481,   481,
     481,  1157,   482,   481,  1158,   482,   482,   481,  1159,   482,
     482,   481,   481,   481,  2471,   481,   999,   482,   481,    -1,
     482,   482,   482,   482,  2144,   482,   482,   482,   482,   481,
     343,   482,   482,    -1,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   481,    -1,   482,   482,
     482,   482,   482,   482,   481,   481,   481,  1870,   482,   481,
      -1,   481,    -1,   482,   482,   481,   481,   481,   481,   481,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   482,   481,    -1,   482,   482,   482,
     481,   481,   481,   481,   481,   481,   481,   481,   602,   603,
     482,   482,   606,   482,   482,   482,   482,   481,   481,  2352,
     482,   482,  2355,   481,   481,    -1,   482,   482,   481,  2270,
     482,  1934,  1935,  1936,   482,  2245,   481,   481,   481,   481,
      -1,   482,   482,   481,   481,   481,   481,    -1,   482,   482,
     481,    -1,   482,   482,   481,    -1,   482,   482,   482,  2269,
     482,   482,   482,   482,   482,   481,   481,    -1,   482,   482,
     482,   481,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   482,   680,   681,   682,   482,
     482,   482,   482,   482,   482,   481,    -1,   482,   482,   482,
     482,   481,   481,   481,   481,   481,   481,    -1,   482,   482,
     482,   482,  2322,   482,  2324,   482,  2326,   482,  2328,   481,
      -1,   482,   482,  2333,  2334,   482,  2336,  2337,  2338,  2339,
     482,  2341,  2342,  2343,  2344,   482,    -1,   482,  2348,   482,
     482,  2351,  2352,   482,   481,   481,   481,  2357,   482,   481,
      -1,   482,  2362,   482,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,   481,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,  2383,  2384,  2385,  2386,   482,  2388,   482,
     481,    -1,   482,   482,   482,   481,  2396,   482,   482,   482,
    2400,  2401,   482,   481,    -1,   482,   482,   482,   482,   482,
    2410,  2411,   482,   482,   481,    -1,   482,   482,   482,   482,
    2420,  2421,  2422,  2423,  2424,   482,  2426,  2427,   482,  2429,
    2430,   482,   482,   482,  2434,  2435,   482,  2437,  2438,   481,
      -1,   482,   482,   482,   482,   482,   482,  2447,   482,   481,
     481,  2451,   481,  2453,  2454,   481,    -1,   482,   482,   481,
      -1,   482,   482,  2463,  2464,  2465,   482,   482,  2468,  2469,
     482,   482,   481,   481,  2474,   482,  2476,   481,  2478,   482,
    2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,   482,
    2490,  2491,  2492,  2493,   481,    -1,   482,   481,    -1,   482,
     481,   481,    -1,   482,  2504,  2505,  2506,  2507,   482,   481,
    2510,   482,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,
    2520,   482,   481,   481,    -1,   482,   482,   482,   481,   481,
      -1,   482,   482,   481,   481,   481,   481,   481,    -1,   482,
     482,   482,   482,   482,   481,   481,  2669,   481,    -1,   482,
    2673,   481,   481,   937,   938,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   482,   951,   952,   482,
     954,   482,   481,   481,   481,   481,   481,   481,   481,   481,
     481,    -1,   482,   481,  2615,   481,    -1,   482,   482,   482,
     481,   481,   481,    -1,   482,   482,   482,   481,    -1,   482,
     482,   482,   482,   482,   482,   482,   481,    -1,   482,   482,
     482,   482,   482,   482,   481,   481,   481,    -1,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   481,   481,
     481,   481,    -1,   482,   482,   482,   481,    -1,   482,   481,
     481,    -1,   482,   481,   481,    -1,   482,   482,   481,    -1,
     482,   482,   482,  2653,  2654,   482,  2656,  2657,   481,  2659,
    2660,   481,  2662,  2663,  2664,   482,  2666,  2667,   482,   481,
    2670,   482,   482,   482,   482,  2675,  2676,   482,  2678,   481,
    2680,   482,  2682,   482,  2684,  2685,  2686,  2687,  2688,   482,
     482,   481,  2692,  2693,  2694,  2695,  2696,  2697,   482,  2699,
    2700,  2701,  2702,  2703,  2704,  2705,   482,  2707,  2708,  2709,
    2710,  2711,   481,  2713,   481,    -1,   482,   481,  2718,  2719,
     481,  2721,  2722,  2723,  2724,  2725,  2726,   481,  2728,  2729,
    2730,   481,   481,   481,  2734,   482,  2736,   481,  2738,   482,
     481,  2741,   481,  2743,  2744,   482,  2746,   481,   481,   481,
    2443,   481,   481,  2753,   482,  2755,   481,   481,  2758,  2759,
    1144,  1145,  1146,   481,  2887,  2765,  2766,  2767,  2768,  2769,
     482,   482,   481,    -1,   482,  2775,  2776,  2777,   481,    -1,
     482,   481,    -1,   482,   482,   481,    -1,   482,   482,   482,
     482,   482,   482,   481,    -1,   482,   482,   482,   482,   482,
     482,   481,   481,    -1,   482,   481,    -1,   482,   482,   482,
     481,   481,   481,    -1,   482,   481,    -1,   482,   482,   481,
      -1,   482,   482,   481,    -1,   482,   482,   482,   482,   482,
     482,   482,   482,   481,    -1,   482,   482,   481,   481,   481,
     481,   481,    -1,   482,   482,   482,   481,   481,   481,    -1,
     482,   482,   482,   481,    -1,   482,   482,   481,    -1,   482,
     482,   481,    -1,   482,   481,    -1,   482,   482,   481,    -1,
     482,  2871,   481,   481,  2874,  2875,  2876,   482,   482,   482,
    2880,   482,  2882,  2883,   482,   481,   481,   481,  2888,  2889,
     482,  2891,   482,  2893,  2894,  2895,  2896,  2897,  2898,   482,
    2900,  2901,  2902,  2903,  2904,  2905,  2906,   482,  2908,   482,
     482,  2911,  2912,  2913,  2914,  2915,   481,    -1,   482,   482,
     482,  2921,  2922,   481,   481,  2925,    -1,    -1,    -1,  2929,
    2930,  2931,    -1,    -1,  2934,    -1,    -1,    -1,  2938,  2939,
      -1,    -1,  2942,  2943,    -1,    -1,  2946,    -1,  2948,  2949,
      -1,    -1,  2952,  2953,    -1,  2955,    -1,  2957,  2958,  2959,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3019,
    3020,  3021,  3022,    -1,  3024,  3025,    -1,    -1,  3028,    -1,
      -1,    -1,    -1,    -1,    -1,  3035,    -1,  3037,    -1,  3039,
    2733,    -1,  3042,    -1,    -1,    -1,    -1,  3047,    -1,    -1,
      -1,    -1,  3052,  3053,    -1,  3055,    -1,  3057,    -1,  3059,
    3060,  3061,    -1,  3063,  3064,    -1,  3066,    -1,  3068,    -1,
    3070,  3071,  3072,    -1,    -1,  3075,  3076,  3077,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3114,    -1,    -1,    -1,  3118,  3119,
      -1,    -1,    -1,  3123,    -1,  3125,  3126,    -1,  3128,  3129,
      -1,    -1,    -1,  3133,    -1,    -1,  3136,  3137,  3138,    -1,
    3140,  3141,  3142,  3143,    -1,    -1,  3146,  3147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,  3169,
      -1,     9,    -1,    -1,    12,  3175,  3176,  3177,    16,    -1,
      -1,  3181,  3182,    -1,    -1,  3185,  3186,    -1,    -1,  3189,
      -1,  2884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,  3203,  3204,    -1,  3206,    -1,  3208,    -1,
      -1,  3211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3221,    -1,  3223,  3224,  3225,    -1,    -1,    -1,    -1,
      -1,    -1,  3232,  3233,  3234,    -1,    -1,    -1,    -1,  3239,
    3240,  3241,    -1,    -1,    -1,    -1,  3246,  3247,    -1,    -1,
    3250,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,   221,   222,    -1,   224,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,   277,
     278,   279,   280,   281,   282,   283,    -1,    -1,    -1,    -1,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    -1,    -1,    -1,    -1,   304,   305,    -1,    -1,
      -1,   309,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,   347,
      -1,   349,   350,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     368,   369,   370,   371,    -1,    -1,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,    -1,    -1,    -1,    -1,
      -1,    -1,   390,   391,    -1,    -1,    -1,    -1,    -1,   397,
     398,   399,    -1,    -1,   402,   403,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   600,   601,   602,   603,    -1,    -1,   606,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   289,   290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,   360,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,    -1,   398,    -1,    -1,    -1,    -1,   807,
      -1,    -1,    -1,    -1,   408,   409,   410,   411,   412,   413,
     414,   415,    -1,    -1,   418,   419,   420,   421,   422,   423,
     424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   841,   438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   886,    -1,
      -1,   889,    -1,    -1,   488,   489,   490,   491,   492,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   946,   947,
     948,   949,   950,   951,   952,    -1,   954,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,    -1,
      -1,    -1,    -1,    -1,   972,    -1,    -1,   975,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1006,    -1,
      -1,  1009,    -1,    -1,  1012,    -1,    -1,    -1,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,    -1,  1033,  1034,  1035,  1036,    -1,
    1038,  1039,  1040,    -1,    -1,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,    -1,    -1,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1118,  1119,  1120,  1121,  1122,  1123,    -1,  1125,  1126,  1127,
    1128,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1139,    -1,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1159,    -1,    -1,  1162,  1163,    -1,    -1,  1166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,    -1,    -1,
      -1,    -1,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1200,    -1,  1202,    -1,    -1,    -1,  1206,  1207,
    1208,  1209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,
      -1,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1243,    -1,  1245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1255,  1256,  1257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1284,  1285,  1286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,  1296,    -1,
    1298,  1299,  1300,  1301,    -1,    -1,    -1,    -1,  1306,    -1,
      -1,    -1,  1310,  1311,  1312,  1313,  1314,  1315,    -1,  1317,
      -1,    -1,  1320,    -1,  1322,  1323,  1324,  1325,  1326,  1327,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1348,  1349,    -1,  1351,    -1,    -1,  1354,    -1,    -1,    -1,
    1358,    -1,    -1,  1361,    -1,  1363,  1364,    -1,    -1,    -1,
      -1,  1369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1529,    -1,    -1,  1532,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1591,    -1,    -1,  1594,    -1,  1596,  1597,
    1598,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,
      -1,    -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,  1756,    -1,
      -1,    -1,   133,    -1,   135,    -1,    -1,    -1,    -1,    -1,
    1768,  1769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1796,    -1,
    1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1809,  1810,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,   220,
    1848,    -1,  1850,  1851,  1852,  1853,  1854,    -1,  1856,  1857,
      -1,    -1,    -1,    -1,  1862,  1863,    -1,    -1,    -1,    -1,
      -1,  1869,  1870,    -1,    -1,  1873,  1874,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1899,    -1,    -1,  1902,    -1,    -1,    -1,    -1,  1907,
      -1,    -1,  1910,    -1,    -1,    -1,    -1,    -1,   289,   290,
      -1,    -1,    -1,  1921,  1922,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1934,  1935,  1936,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1946,    -1,
      -1,    -1,    -1,  1951,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1972,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2004,    -1,    -1,    -1,
      -1,    -1,  2010,  2011,    -1,    -1,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,    -1,   398,    -1,  2027,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,   409,   410,
     411,   412,   413,   414,   415,    -1,    -1,   418,   419,   420,
     421,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2074,  2075,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,   486,    -1,   488,   489,   490,
     491,   492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2351,    -1,    -1,    -1,  2355,  2356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2373,  2374,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2389,  2390,  2391,  2392,  2393,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2406,    -1,
      -1,  2409,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2443,    -1,    -1,    -1,    -1,
      -1,    -1,  2450,    -1,    -1,    -1,    -1,    -1,  2456,    -1,
    2458,    -1,  2460,    -1,  2462,    -1,    -1,    -1,  2466,  2467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2496,    -1,
      -1,    -1,    -1,    -1,  2502,    -1,    -1,    -1,    -1,    -1,
    2508,  2509,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   408,   409,   410,   411,   412,   413,   414,
     415,    -1,    -1,   418,   419,   420,   421,   422,   423,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   438,     0,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   488,   489,   490,   491,   492,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,  2669,    -1,    -1,    -1,  2673,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,  2699,  2700,  2701,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,  2712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2733,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2748,  2749,    -1,    -1,    -1,    -1,  2754,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2773,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,   277,   278,    -1,   280,    -1,   282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   290,   291,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   307,    -1,   309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2884,    -1,    -1,  2887,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,  2906,    -1,
    2908,    -1,    -1,  2911,  2912,    21,    -1,    -1,  2916,  2917,
    2918,  2919,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,    -1,    -1,    -1,  2945,    -1,  2947,
      -1,    -1,    -1,    -1,   390,   391,    -1,    -1,  2956,    -1,
     396,   397,   398,   399,    -1,    -1,   402,   403,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3047,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3065,    -1,  3067,
      -1,    -1,    -1,    -1,    -1,    -1,  3074,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3104,    -1,    -1,    -1,
      -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    -1,  3117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3132,    -1,    -1,  3135,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   600,    -1,   602,   603,    -1,    -1,
     606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   289,   290,  3183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3209,    -1,    -1,    -1,  3213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   408,   409,   410,   411,   412,   413,   414,   415,
      -1,    -1,   418,   419,   420,   421,   422,   423,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   769,   770,   771,   772,   773,   774,   775,
     776,   777,   778,   779,   780,   781,   782,   783,   784,   785,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   488,   489,   490,   491,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,   952,    -1,   954,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1016,  1017,    -1,  1019,  1020,    -1,    -1,    -1,    -1,    -1,
    1026,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1038,  1039,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1052,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1066,  1067,  1068,  1069,  1070,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1093,    -1,    -1,
      -1,    -1,    -1,    -1,  1100,  1101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,  1118,  1119,  1120,    -1,  1122,  1123,    -1,  1125,
    1126,  1127,  1128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1139,    -1,  1141,    -1,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,
      -1,    -1,    -1,    -1,  1190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   241,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,    -1,   277,   278,    -1,
     280,    -1,   282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     290,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1310,  1311,  1312,    -1,  1314,    -1,
      -1,    -1,    -1,    -1,  1320,    -1,    -1,  1323,  1324,  1325,
    1326,  1327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1339,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1349,    -1,  1351,    -1,    -1,    -1,    -1,
      -1,    -1,  1358,    -1,    -1,    -1,    30,  1363,    32,    33,
      34,    35,    -1,    37,    38,    -1,    40,    41,    -1,    -1,
     390,   391,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,
     400,    -1,   402,   403,   247,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,   277,   278,    -1,   280,    -1,   282,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,   291,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1529,    -1,    -1,    -1,   390,   391,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,
     403,    -1,    -1,    -1,   218,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,   601,   602,   603,    -1,  1591,   606,    -1,  1594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   289,   290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1647,    -1,    -1,    -1,    -1,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,   360,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,    -1,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   408,   409,   410,   411,   412,   413,
     414,   415,    -1,    -1,   418,   419,   420,   421,   422,   423,
     424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1809,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   488,   489,   490,   491,   492,    -1,
      -1,    -1,    -1,    -1,  1830,  1831,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1862,  1863,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1907,    -1,    -1,  1910,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1921,    -1,   937,   938,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,    -1,   954,    -1,    -1,    -1,    -1,    -1,
    1946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   985,    -1,    -1,    -1,    -1,
      -1,    -1,   992,    -1,    -1,    -1,    -1,    -1,   998,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1016,  1017,  2004,  1019,
    1020,    -1,    -1,    -1,    -1,    -1,  1026,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1038,  1039,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1052,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1066,  1067,  1068,  1069,
    1070,    -1,    -1,    -1,    -1,    -1,  1076,  1077,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2074,  2075,
      -1,    -1,    -1,  1093,    -1,    -1,    -1,    -1,    -1,    -1,
    1100,  1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,  1119,
    1120,    -1,  1122,  1123,    -1,  1125,  1126,  1127,  1128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1139,
      -1,  1141,   985,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1016,  1017,    -1,  1019,  1020,    -1,    -1,
      -1,    -1,    -1,  1026,    -1,  1185,    -1,    -1,    -1,    -1,
    1190,    -1,    -1,    -1,    -1,  1038,  1039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1066,  1067,  1068,  1069,  1070,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1245,    -1,    -1,    -1,    -1,
    1093,    -1,    -1,    -1,    -1,    -1,    -1,  1100,  1101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1118,  1119,  1120,    -1,  1122,
    1123,    -1,  1125,  1126,  1127,  1128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1139,    -1,  1141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1307,  1308,  1309,
    1310,  1311,  1312,    -1,  1314,    -1,  1316,    -1,  1318,  1319,
    1320,    -1,    -1,  1323,  1324,  1325,  1326,  1327,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1339,
      -1,    -1,  1185,    -1,    -1,    -1,    -1,  1190,    -1,  1349,
      -1,  1351,    -1,    -1,    -1,    -1,    -1,    -1,  1358,    -1,
      -1,    -1,    -1,  1363,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2406,    -1,    -1,  2409,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1310,  1311,  1312,
    2456,  1314,  2458,    -1,  2460,    -1,  2462,  1320,    -1,    -1,
    1323,  1324,  1325,  1326,  1327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1349,    -1,  1351,    -1,
      -1,    -1,    -1,     9,    -1,  1358,  2502,    -1,    -1,    -1,
    1363,    -1,  2508,  2509,    -1,    -1,    -1,    -1,    -1,  1529,
      -1,    -1,  1532,    -1,    30,    -1,    32,    33,    34,    35,
      -1,    37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1590,  1591,    -1,    -1,  1594,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2773,    -1,    -1,
      -1,    -1,    -1,   289,   290,    -1,    -1,    -1,  1798,    -1,
      -1,    -1,    -1,    -1,  1647,    -1,    -1,    -1,    -1,  1809,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1830,  1831,    -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1862,  1863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,   398,    -1,    -1,    -1,    -1,  1907,    -1,    -1,
    1910,    -1,   408,   409,   410,   411,   412,   413,   414,   415,
      -1,  1921,   418,   419,   420,   421,   422,   423,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,    -1,    -1,    -1,  1946,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1798,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
    2956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,    -1,  1830,  1831,    -1,
      -1,    -1,   488,   489,   490,   491,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2004,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1862,
    1863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1907,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2074,  2075,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3074,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3132,    -1,    -1,  3135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2004,    -1,     0,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,  3191,    43,    -1,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,  3213,    -1,    -1,
      -1,  2074,  2075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,    -1,   220,    -1,    -1,    -1,    -1,    -1,   226,
     227,   228,   229,   230,   231,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2406,    -1,    -1,  2409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,   273,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     287,   288,   289,   290,    -1,    -1,  2456,    -1,  2458,    -1,
    2460,    -1,  2462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,
      -1,    -1,  2502,    -1,    -1,    -1,    -1,    -1,  2508,  2509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   359,   360,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
      -1,   398,   399,  2406,    -1,   402,  2409,    -1,    -1,    -1,
      -1,   408,   409,   410,   411,   412,   413,   414,   415,    -1,
      -1,   418,   419,   420,   421,   422,   423,   424,    -1,   426,
      -1,    -1,    -1,   430,    -1,   432,   433,    -1,    -1,    -1,
     437,   438,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,
     447,    -1,    -1,  2456,    -1,  2458,    -1,  2460,    -1,  2462,
      -1,    -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,
      -1,   468,   469,    -1,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   488,   489,   490,   491,   492,    -1,    -1,    -1,  2502,
      -1,    -1,    -1,    -1,    -1,  2508,  2509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2748,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2773,    -1,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,
     220,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,    -1,   233,    -1,  2748,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2956,   287,   288,   289,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,
     360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,    -1,   398,   399,
      -1,    -1,   402,    -1,  3074,    -1,    -1,    -1,   408,   409,
     410,   411,   412,   413,   414,   415,    -1,    -1,   418,   419,
     420,   421,   422,   423,   424,    -1,   426,    -1,    -1,    -1,
     430,    -1,   432,   433,  3104,    -1,    -1,   437,   438,    -1,
     440,    -1,    -1,  2956,    -1,    -1,    -1,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3132,   463,    -1,  3135,    -1,    -1,   468,   469,
      -1,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,   489,
     490,   491,   492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3191,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,  3213,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,  3074,    44,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3132,
      -1,    -1,  3135,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3191,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
    3213,    -1,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,   236,   237,   238,    -1,    -1,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,
      -1,    -1,    -1,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,    -1,    -1,   289,   290,   291,
      -1,    -1,   294,   295,   296,   297,    -1,   299,   300,   301,
     302,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   358,   359,   360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,   398,    -1,   400,   401,
      -1,   403,    -1,    -1,    -1,    -1,   408,   409,   410,   411,
     412,   413,   414,   415,    -1,    -1,   418,   419,   420,   421,
     422,   423,   424,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   438,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,   449,   450,   451,
      -1,   453,   454,    -1,   456,   457,   458,   459,   460,    -1,
     462,    -1,   464,   465,   466,   467,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    12,    13,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    21,    -1,   488,   489,   490,   491,
     492,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    -1,    46,
      -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,    -1,    -1,   133,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,   269,   270,   271,    -1,    -1,    -1,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
      -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   301,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   359,   360,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
      -1,   398,    -1,   400,   401,    -1,    -1,    -1,    -1,    -1,
      -1,   408,   409,   410,   411,   412,   413,   414,   415,    -1,
      -1,   418,   419,   420,   421,   422,   423,   424,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,   449,   450,   451,    -1,   453,   454,    -1,    -1,
      -1,    -1,   459,   460,    -1,    -1,    -1,    -1,   465,   466,
     467,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      12,    13,    -1,   480,    -1,    -1,    -1,    -1,    -1,    21,
      -1,   488,   489,   490,   491,   492,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,
      -1,    -1,    -1,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,    -1,    -1,   289,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,   398,    -1,   400,   401,
      -1,    -1,    -1,    -1,    -1,    -1,   408,   409,   410,   411,
     412,   413,   414,   415,    -1,    -1,   418,   419,   420,   421,
     422,   423,   424,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   438,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,   449,   450,   451,
      -1,   453,   454,    -1,    -1,    -1,    -1,   459,   460,    -1,
      -1,    -1,    -1,   465,   466,   467,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    12,    13,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    21,   487,   488,   489,   490,   491,
     492,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    -1,    46,
      -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,    -1,    -1,   133,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,   269,   270,   271,    -1,    -1,    -1,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
      -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   301,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
      -1,   398,    -1,   400,   401,    -1,    -1,    -1,    -1,    -1,
      -1,   408,   409,   410,   411,   412,   413,   414,   415,    -1,
      -1,   418,   419,   420,   421,   422,   423,   424,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,   449,   450,   451,    -1,   453,   454,    -1,    -1,
      -1,    -1,   459,   460,    -1,    -1,    -1,    -1,   465,   466,
     467,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      12,    13,    -1,   480,    -1,    -1,    -1,    -1,    -1,    21,
     487,   488,   489,   490,   491,   492,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,    -1,
      -1,   133,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,
      -1,    -1,    -1,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,    -1,    -1,   289,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,   398,    -1,   400,   401,
      -1,    -1,    -1,    -1,    -1,    -1,   408,   409,   410,   411,
     412,   413,   414,   415,    -1,    -1,   418,   419,   420,   421,
     422,   423,   424,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   438,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,   449,   450,   451,
      -1,   453,   454,    -1,    -1,    -1,    -1,   459,   460,    -1,
      -1,    -1,    -1,   465,   466,   467,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,   489,   490,   491,
     492,    30,    -1,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    41,    -1,    -1,    44,    -1,    46,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     269,   270,   271,    -1,    -1,    -1,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,    -1,    -1,
     289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,    -1,   398,
      -1,   400,   401,    -1,    -1,    -1,    -1,    -1,    -1,   408,
     409,   410,   411,   412,   413,   414,   415,    -1,    -1,   418,
     419,   420,   421,   422,   423,   424,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,
     439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,
     449,   450,   451,    -1,   453,   454,    -1,    -1,    -1,    -1,
     459,   460,    -1,    -1,    -1,    -1,   465,   466,   467,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,
     489,   490,   491,   492,    30,    -1,    32,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    -1,    -1,    44,    -1,
      46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,    -1,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   269,   270,   271,    -1,    -1,    -1,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   301,   302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,   398,    -1,   400,   401,    -1,    -1,    -1,    -1,
      -1,    -1,   408,   409,   410,   411,   412,   413,   414,   415,
      -1,    -1,   418,   419,   420,   421,   422,   423,   424,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   448,   449,   450,   451,    -1,   453,   454,    -1,
      -1,    -1,    -1,   459,   460,    -1,    -1,    -1,    -1,   465,
     466,   467,    -1,    -1,    -1,    -1,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   488,   489,   490,   491,   492,    30,    -1,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    -1,
      -1,    44,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,    -1,
      -1,    -1,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,    -1,    -1,   289,   290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    -1,    37,    38,    -1,    40,    41,
      -1,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,    -1,   398,    -1,   400,   401,    -1,
      -1,    -1,    -1,    -1,    -1,   408,   409,   410,   411,   412,
     413,   414,   415,    -1,    -1,   418,   419,   420,   421,   422,
     423,   424,   425,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   438,   439,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,   448,   449,   450,   451,    -1,
     453,   454,    -1,   135,    -1,    -1,   459,   460,    -1,    -1,
      -1,    -1,   465,   466,   467,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   488,   489,   490,   491,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,   398,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   408,   409,   410,   411,
     412,   413,   414,   415,    -1,    -1,   418,   419,   420,   421,
     422,   423,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,   438,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,   489,   490,   491,
     492,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,    -1,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,    -1,
      -1,    -1,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,    -1,    -1,    -1,   400,   401,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,   410,   411,   412,
     413,   414,   415,    -1,    -1,   418,   419,   420,   421,   422,
     423,   424,   425,    32,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,   439,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,   448,   449,   450,   451,    -1,
     453,   454,    -1,    -1,    -1,    -1,   459,   460,    -1,    -1,
      -1,    -1,   465,   466,   467,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   488,   489,    -1,   491,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,    -1,   221,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     269,   270,   271,    -1,    -1,    -1,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   301,   302,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   383,   384,   385,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,   401,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,   410,   411,   412,   413,   414,   415,    -1,    -1,   418,
     419,   420,   421,   422,   423,   424,   425,    32,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
     439,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,   448,
     449,   450,   451,    -1,   453,   454,    -1,    -1,    -1,    -1,
     459,   460,    -1,    -1,    -1,    -1,   465,   466,   467,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,
     489,    -1,   491,   492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,    -1,   121,   122,   123,   124,
     125,   126,   127,    -1,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,    -1,   221,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,   269,   270,   271,    -1,    -1,    -1,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   301,   302,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,   384,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,   401,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,   410,   411,   412,   413,   414,
     415,    -1,    -1,   418,   419,   420,   421,   422,   423,   424,
     425,    32,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,   439,    -1,    -1,    48,    49,    -1,
      -1,    -1,    -1,   448,   449,   450,   451,    -1,   453,   454,
      -1,    -1,    -1,    -1,   459,   460,    -1,    -1,    -1,    -1,
     465,   466,   467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   488,   489,    -1,   491,   492,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,    -1,
     121,   122,   123,   124,   125,   126,   127,    -1,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,    -1,
      -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   219,    -1,
     221,   222,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,
     271,    -1,    -1,    -1,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   383,   384,   385,   386,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
     401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,
     411,   412,   413,   414,   415,    -1,    -1,   418,   419,   420,
     421,   422,   423,   424,   425,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,   449,   450,
     451,    -1,   453,   454,    -1,    -1,    -1,    -1,   459,   460,
      -1,    -1,    -1,    -1,   465,   466,   467,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,   489,    -1,
     491,   492
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    43,    45,    46,    47,    48,    49,    50,    52,    53,
      54,    55,    56,    57,   105,   106,   107,   108,   109,   120,
     125,   132,   133,   134,   135,   170,   171,   185,   218,   220,
     226,   227,   228,   229,   230,   231,   233,   272,   273,   274,
     287,   288,   289,   290,   335,   359,   360,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   398,   399,   402,
     408,   409,   410,   411,   412,   413,   414,   415,   418,   419,
     420,   421,   422,   423,   424,   426,   430,   432,   433,   437,
     438,   440,   447,   463,   468,   469,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   488,   489,   490,   491,
     492,   500,   501,   502,   503,   504,   505,   506,   509,   510,
     511,   512,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   576,   480,    48,    49,   436,   535,   574,    28,   576,
     535,    33,    34,    35,    36,    37,    40,    41,    46,   125,
     135,   512,   533,   535,   573,   574,    40,   410,   411,   412,
     413,   414,   415,   418,   419,   420,   421,   422,   423,   424,
     480,   488,   489,   512,   519,   533,   480,   512,   535,    93,
      94,   104,    93,    94,   104,    93,    94,   104,   104,   485,
      84,    85,   485,   104,   480,   104,   485,   480,   480,   501,
     485,   485,    83,   483,   483,    33,    34,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   535,   577,   480,   480,   480,   480,   483,   480,   480,
     483,   480,   483,   480,   485,   485,   485,   485,   480,   480,
     480,   483,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   520,   535,   560,   520,   560,   520,   560,   520,   560,
     520,   560,   520,   560,   520,   560,   520,   560,   520,   560,
     520,   560,   520,   560,   520,   560,   520,   560,   576,   513,
     514,   533,    28,   480,   480,   576,   480,   480,   480,   480,
     480,   480,   533,   534,   573,   520,   560,   520,   560,   520,
       0,   501,   502,   503,   504,   505,   506,   501,   488,   489,
     100,   101,   520,   560,   491,   493,   488,   489,    98,    99,
     494,   495,   100,   101,   487,   496,   497,    96,    97,   498,
      83,   104,   480,   483,   485,   102,   103,   491,   488,   489,
      83,   485,    83,   104,   533,   483,   483,   485,   485,   485,
     485,   485,   480,   485,   485,   512,   485,   533,   533,   533,
     512,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   332,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   452,   470,   574,   574,   306,   308,
     310,   311,   318,   321,   322,   323,   324,   325,   326,   357,
     361,   366,   367,   376,   381,   382,   533,   573,   533,   403,
      19,   404,   405,   406,   407,    12,    13,    37,    39,    44,
     106,   110,   111,   112,   113,   114,   115,   116,   117,   119,
     121,   122,   123,   124,   125,   126,   127,   129,   130,   135,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   184,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   219,   221,   222,
     223,   224,   225,   232,   241,   242,   243,   244,   249,   251,
     268,   269,   270,   271,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   301,   302,   383,   384,
     385,   386,   400,   401,   410,   411,   412,   413,   414,   415,
     418,   419,   420,   421,   422,   423,   424,   425,   439,   448,
     449,   450,   451,   453,   454,   459,   460,   465,   466,   467,
     480,   487,   488,   489,   507,   512,   519,   533,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   574,   507,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   365,    19,   201,   303,   533,   533,   483,
     533,   533,    37,   106,   125,   135,   410,   411,   412,   413,
     414,   415,   418,   419,   420,   421,   422,   423,   424,   480,
     488,   489,   519,   535,   554,   574,   535,   554,   554,   535,
     554,   535,   554,   535,   128,   180,   181,   182,   183,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   182,   183,   182,   183,   182,   183,   535,   535,   535,
     554,   554,   535,   535,   535,   535,   535,   535,   535,   535,
      28,    28,   533,   533,   535,   533,   535,   533,    40,   410,
     411,   412,   413,   414,   415,   418,   419,   420,   421,   422,
     423,   424,   480,   488,   489,   519,   573,    28,   554,   535,
     485,   104,    29,   513,   501,    48,   576,   577,    28,   480,
     533,   512,    37,   535,   535,   535,   481,   481,   481,   501,
     510,   510,   512,   512,   520,   520,   521,   521,   523,   523,
     523,   523,   524,   524,   525,   526,   527,   528,   529,   530,
     554,    37,   533,   554,   533,   533,    24,    25,   118,   180,
     198,   201,   202,   203,   204,   233,   234,   235,   362,   363,
     380,   397,   576,   560,   520,   560,   521,   561,   521,   561,
     236,   237,   238,   245,   246,   247,   248,   250,   291,   294,
     295,   296,   297,   299,   300,   303,   456,   457,   458,   462,
     464,   574,   575,   198,   199,   200,   201,   231,   239,   252,
     295,   297,   298,   299,   308,   309,   314,   315,   316,   317,
     327,   328,   329,   330,   331,   333,   334,   336,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   461,   303,   554,    12,    14,    39,    42,
      47,    58,   303,   358,   388,   391,   403,   410,   411,   412,
     413,   414,   415,   418,   419,   420,   421,   422,   423,   424,
     480,   488,   489,   512,   519,   533,   554,   555,   573,   574,
     575,   481,   533,   533,   533,   482,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   482,   480,   512,   533,   480,
     480,    28,   480,   480,   485,   485,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   485,   480,   480,   480,   480,   485,   480,   480,
     480,   485,   485,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   535,   539,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   480,   480,
     480,   480,   480,   480,   485,   480,   480,   480,   480,   480,
     534,   554,    33,    34,   535,   574,   540,   540,   481,   482,
     540,   480,   483,   104,   491,   493,   496,   488,   489,    98,
      99,   494,   495,   100,   101,   487,   497,    96,    97,   498,
     485,   481,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   512,   483,   484,
     484,   533,   481,   482,   485,   480,   485,   485,   534,   535,
     480,   481,   485,   481,   484,   481,   481,   484,   481,   484,
     482,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   482,   481,   482,   481,   484,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   481,   481,
     482,   482,   481,   482,   481,   481,   482,   481,   533,   515,
     435,   501,   481,   481,   481,   441,   442,   443,   444,   445,
     508,   482,   481,   482,   482,   482,   482,   480,   518,   486,
     479,   481,   482,   486,   484,   480,   480,   512,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,    28,   480,   480,   480,   480,   480,   480,   485,   512,
     480,   480,   512,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   483,
     483,   480,   485,   480,   480,   483,   480,   480,   480,   480,
     485,   484,   484,   533,   533,   535,   533,   533,   533,   533,
     533,   535,   533,   533,    37,   535,    30,    37,   533,   533,
     533,   533,   533,   533,   533,   554,   533,    39,   533,    45,
     533,   533,   575,   533,   533,   533,   533,   533,   574,    39,
     555,    39,    30,   533,   533,   533,   533,   512,   512,    33,
     512,   534,   535,   533,   304,   304,   305,   507,   535,   554,
     535,   554,   554,   535,   535,   535,   535,   535,   554,   535,
     535,   535,   535,   535,    26,    27,   535,   535,   535,   535,
      26,   145,   180,   554,   554,   535,   180,   180,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   554,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   554,   554,   554,   554,   554,   535,   535,   535,   535,
     535,   574,   574,   512,   512,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   554,   535,
     535,   535,   535,   535,   535,   554,   554,   554,   554,   554,
     535,   554,   554,   455,   554,   554,   554,   554,   512,   481,
     481,    37,   487,   512,   533,   554,   554,    37,   486,   533,
     535,   578,   553,   520,   540,   520,   540,   540,   521,   541,
     521,   541,   523,   544,   523,   544,   523,   544,   523,   544,
     523,   545,   523,   545,   546,   548,   549,   550,   551,   337,
     338,   339,   340,   501,   512,   512,    33,    34,   512,    35,
      34,   533,    36,    36,   533,    45,   533,   512,   533,   533,
     104,   104,   484,    45,   481,   485,   480,   480,   480,   535,
     533,   535,   533,   533,   533,   535,   535,   535,   535,   533,
     533,   533,   533,   533,   533,   533,   535,   533,   535,   535,
     535,   131,   535,   535,   131,   535,   131,   535,   535,   535,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   535,   554,   480,   533,   533,
     533,   533,   533,   533,   533,   535,   535,   535,   533,   533,
     533,   512,   427,   513,    31,    31,    31,    31,    31,   481,
     482,   533,   533,   512,   535,   535,   531,   533,   533,   533,
     104,   512,   535,   535,   535,   533,   535,   533,   535,   533,
     533,   533,   533,   535,   574,   574,   574,   554,   554,   554,
     512,   554,   535,   574,   535,   574,   574,   554,   481,   512,
     554,   554,   554,   554,   554,   240,   533,   533,   533,   533,
     533,   533,   533,   533,   554,   533,   533,   533,   533,   533,
     533,   533,   533,   535,   554,   533,   554,   533,   533,   535,
     533,   533,   533,   554,   533,   533,   512,   356,   507,   512,
     533,    47,   533,   533,   512,   481,   482,   482,   482,   482,
     482,   481,   482,   481,   482,   481,   481,   481,   482,   482,
     482,   482,   482,   481,   481,   482,   482,   482,   482,   481,
     482,   481,   482,   481,   482,   481,   481,   482,   482,   482,
     482,   481,   485,   481,   482,   481,   482,   482,   482,   481,
     481,   482,   481,   481,   481,   482,   485,   482,   481,   482,
     482,   482,   482,   481,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   481,   482,   480,   480,
     482,   482,   482,   480,   480,   481,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   481,   481,   481,   482,   481,
     482,   482,   482,   482,   482,   481,   482,   482,   482,   482,
     482,   482,   482,   482,   481,   482,   482,   482,   482,   482,
     482,   481,   481,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   481,   481,   481,   481,
     481,   481,   481,   482,   482,   482,   481,   482,   482,   482,
     482,   482,   480,   481,   482,   481,   482,   482,   481,   481,
     480,   539,    33,    34,   535,   574,   481,   482,   484,   486,
     484,   486,   480,   480,   480,   480,   481,   481,   482,   482,
     482,   481,   481,   482,   482,   482,   482,   482,   481,   481,
     481,   481,   484,   575,   554,   481,   480,   535,   535,   535,
     481,   482,   481,   482,   481,   482,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   482,
     481,   481,   482,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   482,   481,   482,   481,   481,   481,
     481,   482,   481,   481,   481,   481,   481,   482,   481,   481,
     554,   482,   482,   481,   482,   482,   482,   481,   482,   482,
     482,   482,   482,   482,   481,   482,   533,   501,   513,   441,
     442,   443,   444,   445,   482,   482,   481,   482,   482,   481,
     479,   481,   482,   482,   533,   554,   481,   481,   482,   481,
     481,   482,   481,   482,   481,   481,   481,   482,   482,   481,
     482,   481,   481,   482,   482,   482,   482,   482,   482,   481,
     482,   482,   482,   481,   482,   482,   482,   482,   482,   481,
     481,   482,   482,   482,   482,   482,   480,   481,   481,   481,
     481,   481,   482,   481,   481,   482,   481,   482,   481,   482,
     482,   482,   481,   481,   481,   481,   481,   481,   481,   481,
     482,   482,   481,   481,   482,   481,   481,   484,   484,   481,
     481,   481,   484,   482,   481,   481,   482,   535,   533,   533,
     533,   533,   533,   533,   535,   535,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   535,   533,   554,   104,    28,   533,   533,   554,    28,
     535,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   535,   535,   554,   554,
     535,   535,   535,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   535,   535,   535,   535,   535,   535,   535,   535,
     533,   533,   533,   533,   554,   554,   533,   533,   533,   533,
     535,   512,   535,   535,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     535,   533,   533,   535,   533,   533,   554,   486,   533,   552,
     535,   481,   481,   481,   533,   533,    45,   533,   512,   512,
     512,   533,   481,   481,   481,   482,   535,   533,   533,   533,
     535,   533,   533,   533,   533,   481,   533,   533,   533,   554,
     533,   533,   533,   533,   535,   535,   533,   533,   533,   428,
     513,   501,    31,    31,    31,    31,    31,   533,   533,   535,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   554,   554,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
      47,    28,   482,   481,   482,   481,   482,   481,   482,   481,
     481,   481,   481,   482,   482,   481,   482,   482,   482,   482,
     481,   482,   482,   482,   482,   481,   481,   481,   482,   533,
     481,   482,   482,   481,   481,   482,   482,   482,   481,   481,
     481,   481,   482,   481,   482,   482,   482,   482,   482,   482,
     482,   482,   481,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   481,   482,   482,
     482,   482,   482,   482,   481,   481,   482,   481,   481,   481,
     482,   482,   481,   481,   481,   481,   482,   481,   481,   482,
     482,   482,   481,   481,   481,   481,   481,   481,   481,   481,
     482,   482,   482,   482,   482,   481,   482,   482,   481,   482,
     482,   481,   481,   481,   482,   482,   481,   482,   482,   481,
     481,   481,   481,   482,   481,   533,   481,   482,   481,   481,
     482,   482,   481,   482,   482,   481,   482,   481,   482,   481,
     482,   481,   482,   482,   482,   482,   482,   482,   482,   482,
     481,   533,   501,   481,   482,   482,   482,   481,   479,   481,
     482,   486,   482,   482,   482,   482,   482,   482,   482,   481,
     482,   482,   482,   482,   481,   481,   482,   481,   481,   481,
     481,   481,   482,   481,   482,   482,   482,   482,   482,   482,
     482,   481,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   481,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   535,   533,
     534,   534,   535,    28,   535,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   535,   533,   535,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   535,   535,   535,   535,   535,   533,   533,   533,
     554,   554,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   512,   481,   533,
     535,   533,   533,   533,   554,   554,   554,   554,   533,   533,
     533,   535,   535,   533,   533,   513,   533,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   535,   554,   533,   533,   533,   533,   554,
     554,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   481,   481,   482,   482,   481,   482,   482,   481,   482,
     482,   481,   482,   482,   482,   481,   482,   482,   481,   482,
     482,   481,   481,   482,   482,   482,   482,   481,   482,   481,
     482,   481,   482,   481,   482,   482,   482,   482,   482,   481,
     481,   481,   482,   482,   482,   482,   482,   482,   481,   482,
     482,   482,   482,   482,   482,   482,   481,   482,   482,   482,
     482,   482,   482,   482,   481,   481,   481,   481,   482,   482,
     481,   482,   482,   482,   482,   482,   482,   481,   482,   486,
     486,   481,   481,   482,   482,   481,   482,   481,   482,   481,
     481,   482,   481,   482,   482,   481,   482,   481,   482,   482,
     481,   481,   501,   482,   482,   482,   481,   481,   482,   482,
     481,   481,   481,   481,   481,   482,   482,   482,   482,   482,
     481,   481,   481,   482,   481,   482,   482,   482,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   534,
     533,   534,    28,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     578,   533,   578,   533,   578,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   535,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   512,   533,   533,
     533,   533,   533,   533,   533,   554,   535,   533,   535,   533,
     533,   533,   533,   533,   533,   533,   533,   554,   533,   533,
     533,   482,   481,   481,   482,   482,   482,   481,   481,   481,
     482,   481,   482,   482,   482,   481,   481,   482,   482,   482,
     481,   482,   481,   482,   482,   482,   482,   482,   482,   481,
     482,   482,   482,   482,   482,   482,   482,   481,   482,   481,
     481,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     481,   482,   482,   481,   481,   482,   481,   481,   481,   482,
     482,   482,   481,   484,   482,   481,   481,   481,   482,   482,
     481,   481,   482,   482,   481,   482,   482,   482,   482,   486,
     481,   481,   482,   482,   481,   482,   482,   482,   482,   482,
     533,   533,   533,   533,   533,   533,   533,   512,   534,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   578,   578,   578,   578,   533,   533,
     533,   535,   535,   535,   535,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   535,   533,   535,   533,
     533,   533,   533,   533,   554,   533,   533,   533,   481,   482,
     482,   482,   482,   481,   482,   482,   481,   481,   482,   481,
     481,   481,   481,   481,   481,   482,   481,   482,   481,   482,
     481,   481,   482,   481,   481,   481,   481,   482,   481,   481,
     481,   481,   482,   482,   481,   482,   481,   482,   481,   482,
     486,   482,   481,   482,   482,   482,   482,   482,   482,   481,
     482,   482,   482,   481,   482,   482,   482,   482,   533,   533,
     533,   533,   512,   533,   533,   533,   533,   533,   533,   533,
     578,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     535,   533,   535,   533,   104,   533,   533,   533,   554,   533,
     533,   533,   481,   481,   482,   481,   481,   482,   482,   482,
     481,   481,   481,   482,   481,   482,   482,   481,   482,   482,
     481,   481,   482,   482,   481,   482,   482,   482,   482,   554,
     482,   482,   482,   482,   481,   481,   482,   482,   533,   512,
     533,   533,   533,   533,   533,   533,   533,   554,   533,   554,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   482,
     481,   481,   481,   481,   481,   482,   482,   482,   481,   481,
     481,   482,   482,   482,   481,   482,   482,   481,   481,   482,
     481,   482,   533,   533,   533,   533,   533,   533,   535,   533,
     533,   533,   554,   482,   482,   481,   482,   481,   482,   482,
     481,   482,   481,   482,   533,   533,   533,   533,   535,   533,
     554,   482,   481,   482,   482,   482,   481,   481,   533,   533,
     533,   533,   482,   482,   482,   481,   533,   533,   533,   482,
     482,   482,   533,   533,   533,   481,   482,   482,   533,   533,
     482,   481,   533,   481
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       gr_print("list_command : command\n ");
     ;}
    break;

  case 5:
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       gr_print("list_command : list_commands command\n ");
     ;}
    break;

  case 14:
#line 950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
                      yyiplineno++;
        ;}
    break;

  case 16:
#line 959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=yyiplineno;
       int* varint;
        AmiInstructionBlock_ptr block((yyvsp[(7) - (8)].ablock));

      varint = new int;
      Vars.AddVar(type_int,(yyvsp[(2) - (8)].ident),(void*)varint);
      gr_print("command : FOR identifier ASSIGN_OP ");
      gr_print("expr TO expr instr_block\n ");

      //          printf(" block = %s \n",$7);
      yyip_switch_to_block(block);
      for(*varint = (int) (yyvsp[(4) - (8)].adouble); *varint <= (int) (yyvsp[(6) - (8)].adouble); (*varint)++)
        {

          yyiplineno = block->GetStartingLine();
          yyip_reinit_current_buffer();
          yyip_parse();

        }
      yyip_popup_buffer();
      Vars.deleteVar((yyvsp[(2) - (8)].ident));
      //      free($7);
      yyiplineno=previous_lineno;
      continue_parse();
    ;}
    break;

  case 17:
#line 988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=yyiplineno;
       float* var;
        AmiInstructionBlock_ptr block((yyvsp[(9) - (10)].ablock));

      var = new float;
      Vars.AddVar(type_float,(yyvsp[(2) - (10)].ident),(void*)var);

      yyip_switch_to_block(block);
      for(*var = (yyvsp[(4) - (10)].adouble); *var <= (yyvsp[(6) - (10)].adouble); (*var)+=(yyvsp[(8) - (10)].adouble))
        {

          yyiplineno = block->GetStartingLine();
          //yyiplineno=previous_lineno;
          yyip_reinit_current_buffer();
          yyip_parse();

        }
      yyip_popup_buffer();
      Vars.deleteVar((yyvsp[(2) - (10)].ident));
      yyiplineno=previous_lineno;
      continue_parse();
    ;}
    break;

  case 18:
#line 1013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=yyiplineno;
        AmiInstructionBlock_ptr block((yyvsp[(2) - (2)].ablock));


      //          printf(" block = %s \n",$7);
          int res;
      //yyiplineno = $2->GetStartingLine();
      yyip_switch_to_block(block);
      do {

          //yyiplineno=previous_lineno;
          yyiplineno = block->GetStartingLine();
          yyip_reinit_current_buffer();
          res=yyip_parse();

      } while (!res);
      yyip_popup_buffer();
      yyiplineno = previous_lineno;
      continue_parse();
    ;}
    break;

  case 19:
#line 1038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno;
      AmiInstructionBlock_ptr block((yyvsp[(3) - (4)].ablock));

      gr_print("command : IF expr instr_block  \n");

      // Pb with line numbers
      previous_lineno=yyiplineno;

        if ((yyvsp[(2) - (4)].adouble)>0.5)
        {
          //yyiplineno=previous_lineno;
          yyip_switch_to_block(block);
          yyip_parse();
          yyip_popup_buffer();
          yyiplineno = previous_lineno;
          continue_parse();
        }
    ;}
    break;

  case 20:
#line 1058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno = yyiplineno;

      AmiInstructionBlock_ptr block_if(  (yyvsp[(3) - (6)].ablock));
      AmiInstructionBlock_ptr block_else((yyvsp[(5) - (6)].ablock));

      gr_print("command : IF expr instr_block ELSE instr_block \n");

      // Pb with line numbers
      previous_lineno=yyiplineno;

        if ((yyvsp[(2) - (6)].adouble)>0.5)
        {
          yyip_switch_to_block(block_if);
          yyip_parse();
          yyip_popup_buffer();
        }
      else
        {
          yyip_switch_to_block(block_else);
          yyip_parse();
          yyip_popup_buffer();
        }
      yyiplineno = previous_lineno;
      continue_parse();

    ;}
    break;

  case 21:
#line 1091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock_ptr body((yyvsp[(6) - (7)].ablock));

      amifunc = new AMIFunction;

      amifunc->SetName((yyvsp[(2) - (7)].ident));
      amifunc->SetFileName(GB_current_file);
      amifunc->SetParamList((yyvsp[(4) - (7)].paramlistdecl));
      amifunc->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", (yyvsp[(2) - (7)].ident),body->GetBody().c_str());

      Vars.AddVar( type_ami_function, (yyvsp[(2) - (7)].ident), (void*) amifunc);

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      procedure_declaration = 0;
    ;}
    break;

  case 22:
#line 1112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int previous_lineno;
        string current_filename;

       previous_lineno=yyiplineno;
       current_filename = GB_current_file;

        res_print((yyvsp[(2) - (3)].astring));
       if (yyip_switch_to_file((yyvsp[(2) - (3)].astring))) {
         delete [] (yyvsp[(2) - (3)].astring);
         yyiplineno=1;
         yyip_parse();
         yyip_popup_buffer( );

         GB_current_file = current_filename;
         yyiplineno=previous_lineno;
         continue_parse();
       }

     ;}
    break;

  case 23:
#line 1134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          //cout << "current wd = "  <<  wxGetCwd() << endl; 
          res=AskScript(name);
          if (!res) {
            yyiperror(" Need script \n");
            YYABORT;
          }
          //cout << "current wd = "  <<  wxGetCwd() << endl; 

        int previous_lineno;
        string current_filename;

       previous_lineno=yyiplineno;
       current_filename = GB_current_file;

        res_print(name.c_str());
        res_print("\n");
       if (yyip_switch_to_file((char*)name.c_str())) {
         yyiplineno=1;
         yyip_parse();
         yyip_popup_buffer( );

         GB_current_file = current_filename;
         yyiplineno=previous_lineno;
         continue_parse();
       }

        // convert path delimiters to avoid pbs with \ character
        wxFileName filename(GetwxStr(name.c_str()),wxPATH_NATIVE);
        filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
        wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                            filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX));
        res_print( newname.mb_str());
        res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.c_str());
          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      ;}
    break;

  case 24:
#line 1178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*       var   = (yyvsp[(1) - (5)].variable);
          ParamList::ptr  param((yyvsp[(3) - (5)].paramlist));
          AMIFunction::ptr f;
          int          i,n;
          char*        name;

          f = *(AMIFunction_ptr*) (var->Pointer());

          // Verifier les parametres
          if (f->GetParamList( )->CheckParam(param.get())) {

          // Create the variables in a new context
          Vars.NewContext(f->GetName().c_str());
          for(i=0;i<param->GetNumParam();i++) {
            name = f->GetParamList( )->GetName(i);
            if (Vars.GetCurrentContext()->ExistVar(name,n)) {
              fprintf(stderr,"variable %s already exists ... \n",name);
            }
            else {
              // LOTS OF CARE HERE, now GetParam is a pointer
              // to a smart pointer !!!
              Vars.AddVarPtr( param->GetType(i),
                              name,
                              param->GetParam(i)
                            );
            }
          }

        yyip_call_function(f);
        // destroy the context and its variables
        // removing each parameter is not necessary
        // cause it will be done by DeleteLastContext()
        Vars.DeleteLastContext();

        if (GB_debug)
          cerr  << "End function body = "
                << f->GetString()
                << endl;
        continue_parse();
      }

        ;}
    break;

  case 25:
#line 1222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yyvsp[(1) - (2)].variable);
          AMIFunction_ptr f;

          f = *(AMIFunction_ptr*) (var->Pointer());

          // Call the function
          Vars.NewContext(f->GetName().c_str());
          yyip_call_function(f);
          Vars.DeleteLastContext();
          continue_parse();
        ;}
    break;

  case 26:
#line 1237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 27:
#line 1245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         ;}
    break;

  case 28:
#line 1250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for variables,
          creates new variables as global and can only
          access global variables

         Others:
          local, global_new
         **/
       Vars.SetCurrentContext(0);
         ;}
    break;

  case 29:
#line 1264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for new variables,
          creates new variables as global,
          but allow access to lobal variables

         Others:
          local, global
         **/
       Vars.SetGlobalNew(1);
         ;}
    break;

  case 30:
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a local context for new variables,
          creates new variables as local,
          and allow access to local variables

         Others:
          local, global, global_new
         **/
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 31:
#line 1292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
    ;}
    break;

  case 32:
#line 1302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int ms = (int) (yyvsp[(3) - (4)].adouble);
      wxWaitTimer w;
      w.Start(ms,wxTIMER_ONE_SHOT);
      while (!w.finished) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
      } // end while
    ;}
    break;

  case 33:
#line 1314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
          (3) time in ms
          (5) function to schedule
      **/
      // TODO To avoid pbs, make sure that the variable does not disappears
      // by making a copy of it

      int ms = (int) (yyvsp[(3) - (6)].adouble);
      Variable*    var   = (yyvsp[(5) - (6)].variable);

      wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer(  *(AMIFunction_ptr*) (var->Pointer()) ));
      // add to the list of schedule timers
      schedule_timers.push_back(w);
      w->Start(ms,wxTIMER_ONE_SHOT);
   ;}
    break;

  case 34:
#line 1333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yyvsp[(5) - (6)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yyvsp[(1) - (6)].ident),arraysurf);
          ;}
    break;

  case 35:
#line 1343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yyvsp[(5) - (6)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yyvsp[(1) - (6)].ident),arraysurf);
          ;}
    break;

  case 36:
#line 1353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* array;
            int size = (int) (yyvsp[(5) - (6)].adouble);
            if (size<1) size = 1;
            array = new VarArray();
            array->Init(type_image,size);
            Vars.AddVar(type_array,(yyvsp[(1) - (6)].ident),array);
          ;}
    break;

  case 37:
#line 1363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yyvsp[(1) - (3)].ident),imptr);
          else
            err_print("assignment of NULL image\n");

          gr_print("command : identifier ASSIGN_OP image\n ");
        ;}
    break;

  case 38:
#line 1375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yyvsp[(1) - (3)].ident),imptr);
          else
            err_print("assignment of NULL image\n");

          gr_print("command : identifier ASSIGN_OP image\n ");
        ;}
    break;

  case 39:
#line 1386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*      var   = (yyvsp[(3) - (6)].variable);
          ParamList::ptr param((yyvsp[(5) - (6)].paramlist));
          Variable::ptr  res;

          res = ((Variable::ptr (*)(ParamList*)) var->Pointer())(param.get());
          if (!res.use_count()) {
            yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename((yyvsp[(1) - (6)].ident));
          Vars.AddVar(res);
        ;}
    break;

  case 40:
#line 1401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * imptr = (void*)im_stack.GetLastImage();
          int  i = (int) (yyvsp[(3) - (6)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer()));
          if (imptr != NULL)
            if (array->GetVar(i).Pointer()==NULL) {
              sprintf(name,"%s[%d]",(yyvsp[(1) - (6)].variable)->Name(),i);
              array->InitElement(i,imptr,name);
            }
            else
            {
              err_print("array element already assigned\n");
              delete (InrImage*)imptr;
            }
          else
            err_print("assignment of NULL image\n");

          gr_print("command : identifier ASSIGN_OP image\n ");
        ;}
    break;

  case 41:
#line 1425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*) matrix_stack.GetLastMatrix();
          if (imptr != NULL)
        Vars.AddVar(type_matrix,(yyvsp[(1) - (3)].ident),imptr);
          else
        err_print("assignment of NULL matrix\n");

          gr_print("command : identifier ASSIGN_OP matrix\n ");
        ;}
    break;

  case 42:
#line 1437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)gltransf_stack.GetLastMatrix();
          if (imptr != NULL)
            Vars.AddVar(type_gltransform,(yyvsp[(1) - (3)].ident),imptr);
          else
            err_print("assignment of NULL matrix\n");

          gr_print("command : identifier ASSIGN_OP matrix\n ");
        ;}
    break;

  case 43:
#line 1448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer()));
          (*m1) = (yyvsp[(3) - (3)].adouble);
       ;}
    break;

  case 44:
#line 1453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer()));
          FloatMatrix* m2 = matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       ;}
    break;

  case 45:
#line 1463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * surfptr;
          int  i = (int) (yyvsp[(3) - (6)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer()));
          surfptr = (void*)surf_stack.GetLastSurf();
          if (surfptr != NULL)
          if (array->GetVar(i).Pointer()==NULL) {
            sprintf(name,"%s[%d]",(yyvsp[(1) - (6)].variable)->Name(),i);
            array->InitElement(i,surfptr,name);
          }
          else
          {
            err_print("array element already assigned\n");
            delete (SurfacePoly*)surfptr;
          }
          else
            err_print("assignment of NULL surface\n");

          gr_print("command : identifier ASSIGN_OP surface\n ");
        ;}
    break;

  case 46:
#line 1488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * surfptr;
          surfptr = (void*)surf_stack.GetLastSurf();
          if (surfptr != NULL)
            Vars.AddVar(type_surface,(yyvsp[(1) - (3)].ident),surfptr);
          else
            err_print("assignment of NULL surface\n");

          gr_print("command : identifier ASSIGN_OP surface\n ");
        ;}
    break;

  case 47:
#line 1500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yyvsp[(1) - (3)].variable);
          void* surfptr  = (void*) surf_stack.GetLastSurf();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr != NULL) {
            var->FreeMemory();
            var->Init(type_surface,
                      var->Name(),
                      surfptr);
          }
          else
            err_print("assignment of NULL surface\n");

        ;}
    break;

  case 48:
#line 1518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yyvsp[(1) - (6)].variable);
          VarArray* arraysurf;
          int size = (int) (yyvsp[(5) - (6)].adouble);
          if (size<1) size = 1;
          arraysurf = new VarArray();
          arraysurf->Init(type_surface,size);

          // instead of deleting and creating,
          // replace the pointer and the information
          if (arraysurf != NULL) {
            var->FreeMemory();
            var->Init(type_array,
                      var->Name(),
                      arraysurf);
          }
          else
            err_print("not able to create surface array !\n");

        ;}
    break;

  case 49:
#line 1540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          varint = new int((int)(yyvsp[(5) - (6)].adouble));
          Vars.AddVar(type_int,(yyvsp[(1) - (6)].ident),(void*)varint);
          gr_print("command : identifier ASSIGN_OP T_INT(expr)\n ");
        ;}
    break;

  case 50:
#line 1548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        varuchar = new unsigned char((unsigned char)(yyvsp[(5) - (6)].adouble));
        Vars.AddVar(type_uchar,(yyvsp[(1) - (6)].ident),(void*)varuchar);
        gr_print("command : identifier ASSIGN_OP T_UCHAR(expr)\n ");
        ;}
    break;

  case 51:
#line 1556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          varfloat = new float((yyvsp[(3) - (3)].adouble));
          Vars.AddVar(type_float,(yyvsp[(1) - (3)].ident),(void*)varfloat);
          gr_print("command : identifier ASSIGN_OP expr\n ");
        ;}
    break;

  case 52:
#line 1564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yyvsp[(3) - (3)].astring));
          Vars.AddVar(type_string,(yyvsp[(1) - (3)].ident),(void*)varstring);
              delete [] (yyvsp[(3) - (3)].astring);
          gr_print("command : identifier ASSIGN_OP expr_string\n ");
        ;}
    break;

  case 53:
#line 1573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE* file;

          file = fopen((yyvsp[(5) - (8)].astring),(yyvsp[(7) - (8)].astring));
          if (file!=NULL) {
            Vars.AddVar(type_file,(yyvsp[(1) - (8)].ident),(void*)file);
          } else {
          fprintf(stderr,"error opening file \n");
          /*
          switch (errno) {
          case EEXIST: fprintf(stderr,"EEXIST \n"); break;
          case EISDIR: fprintf(stderr,"EISDIR \n"); break;
          case ETXTBSY:fprintf(stderr,"ETXTBSY \n"); break;
          case EFAULT: fprintf(stderr,"EFAULT \n"); break;
          case EACCES: fprintf(stderr,"EACCES \n"); break;
          case ENAMETOOLONG: fprintf(stderr,"ENAMETOOLONG \n"); break;
          case ENOENT: fprintf(stderr,"ENOENT \n"); break;
          case ENOTDIR:fprintf(stderr,"ENOTDIR \n"); break;
          case EMFILE: fprintf(stderr,"EMFILE \n"); break;
          case ENFILE: fprintf(stderr,"ENFILE \n"); break;
          case ENOMEM: fprintf(stderr,"ENOMEM \n"); break;
          case EROFS:  fprintf(stderr,"EROFS \n"); break;
          case ELOOP:  fprintf(stderr,"ELOOP \n"); break;
          case ENOSPC: fprintf(stderr,"ENOSPC \n"); break;
                  default: fprintf("unknown error \n");
          }
          */
          }
        ;}
    break;

  case 54:
#line 1604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::string filename((yyvsp[(1) - (8)].variable)->Name());
            Variable* var;

            if (Vars.GetVar(filename.c_str(),&var))
                Vars.deleteVar(filename.c_str());

            FILE* file;
            file = fopen((yyvsp[(5) - (8)].astring),(yyvsp[(7) - (8)].astring));
            if (file!=NULL) {
                Vars.AddVar(type_file,filename.c_str(),(void*)file);
            } else {
                fprintf(stderr,"error opening file \n");
            }
        ;}
    break;

  case 55:
#line 1620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
            rewind(file.get());
        ;}
    break;

  case 56:
#line 1625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 57:
#line 1629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        ;}
    break;

  case 58:
#line 1633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        ;}
    break;

  case 59:
#line 1638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        ;}
    break;

  case 60:
#line 1642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yyvsp[(3) - (4)].adouble)+0.5));
        ;}
    break;

  case 61:
#line 1645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        gr_print("command : QUIT\n ");

        GB_main_wxFrame->Close(true);
    ;}
    break;

  case 62:
#line 1651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          int i;
          Variable* var;
          int var_context = Vars.GetContext((yyvsp[(2) - (2)].variable));

          if (var_context>=0) {
            sprintf(titre,"%s_draw",(yyvsp[(2) - (2)].variable)->Name());
            if (GB_debug) fprintf(stderr,
                      "SHOW var_image  title %s \n",
                      titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            if (Vars.GetVar(titre,&var,var_context)) {
              DessinImageParametres* param;
              DessinImage::ptr di;
              di = *((DessinImage::ptr*) var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
            }
            else
            {
              if (GB_debug) fprintf(stderr,"SHOW var_image creating title %s \n",titre);
              DessinImage* di;

              std::string* varname = new std::string(titre);

              di = CreateIDraw( *varname,
                    *((InrImage::ptr*) (yyvsp[(2) - (2)].variable)->Pointer()));

              Vars.SetNextVarContext(var_context);
              i = Vars.AddVar(type_imagedraw,titre, (void*) di);
              di->SetCloseFunction(
                (void*) CB_delete_imagedraw,
                (void*) (varname));
            }
          } // var_context >=0
        ;}
    break;

  case 63:
#line 1690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;

          sprintf(titre,"%s_draw",(yyvsp[(2) - (2)].variable)->Name());
          if (Vars.GetVar(titre,&var)) {

        if (var->Type() == type_imagedraw) {
            err_print("Hide window \n");
            (*(DessinImage::ptr*) var->Pointer())->Hide();
        }
        else
          fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
            (yyvsp[(2) - (2)].variable)->Name());
          } else
        fprintf(stderr,"Image %s not visible \n",
            (yyvsp[(2) - (2)].variable)->Name());

        ;}
    break;

  case 64:
#line 1710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string    titre;
          Viewer3D* surfdraw;
          Variable* var;
          int     i;
          int var_context = Vars.GetContext((yyvsp[(2) - (2)].variable));

          if (var_context>=0) {
            titre = str(format("%s_draw") % (yyvsp[(2) - (2)].variable)->Name());
            if (!Vars.GetVar(titre.c_str(),&var,var_context)) {
              surfdraw = new Viewer3D(  GB_main_wxFrame,
                                        wxString::FromAscii(titre.c_str()));

              Vars.SetNextVarContext(var_context);
              i = Vars.AddVar(type_surfdraw,titre.c_str(), (void*) surfdraw);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_surfdraw,
                              (void*) (*Vars.GetCurrentContext())[i]);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface(
                                *(SurfacePoly::ptr*) (yyvsp[(2) - (2)].variable)->Pointer());
              surfdraw->Paint();
              surfdraw->GetCanvas()->Normalize();
              surfdraw->GetCanvas()->Center();
            } else
              cerr << " variable " << titre << " already exists " << endl;
          } // var_context >=0
        ;}
    break;

  case 65:
#line 1739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // Create the main frame window
          PenguinFrame *frame = new PenguinFrame(GB_main_wxFrame, wxT("wxWidgets Penguin Sample"),
              wxDefaultPosition, wxDefaultSize);

          #if wxUSE_ZLIB
            if (wxFileExists(wxT("penguin.dxf.gz")))
              frame->GetCanvas()->LoadDXF(wxT("penguin.dxf.gz"));
          #else
            if (wxFileExists(wxT("penguin.dxf")))
              frame->GetCanvas()->LoadDXF(wxT("penguin.dxf"));
          #endif

          // Show the frame 
          frame->Show(true);
        ;}
    break;

  case 66:
#line 1756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          InrImage* i2 = (InrImage*) im_stack.GetLastImage();

          Si i2!=NULL Alors
            // copy option
            if (!((*i1)=(*i2))) err_print(" Error in images assignement\n");
          Sinon
            err_print("Error\n");
          FinSi
          delete i2;
        ;}
    break;

  case 67:
#line 1769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          Variable* var = (yyvsp[(1) - (3)].variable);
          void* imptr  = (void*) im_stack.GetLastImage();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (imptr != NULL) {
            var->FreeMemory();
            var->Init(type_image,
                      var->Name(),
                      imptr);
          }
          else
            err_print("assignment of NULL image\n");
        ;}
    break;

  case 68:
#line 1789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image
        (3) expression

        description:
        Sets the whole image to a constant value given by expression.
        **/
          InrImage::ptr i1 = *(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          i1->InitImage((yyvsp[(3) - (3)].adouble));
        ;}
    break;

  case 69:
#line 1802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) imageval: image expression

        description:
        assigns imageval to the component 'n' of the input image
        **/
          int comp = (int) (yyvsp[(3) - (6)].adouble);

          InrImage::ptr i1 = *(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(
                                im_stack.GetLastImage());

          Si (comp<0) Ou (comp>i1->GetVDim()) Alors
            fprintf(stderr,"image[n]=image error index too high, reset to 0 \n");
            comp = 0;
          FinSi

          Si i2->ScalarFormat()  Alors
             i1->InitBuffer();
             i2->InitBuffer();
             Repeter
                i1->VectFixeValeur(comp,i2->ValeurBuffer());
                i2->IncBuffer();
             JusquA Non(i1->IncBuffer()) FinRepeter
          Sinon
            yyiperror("image[]=image\t second image has to be scalar \n");
            YYABORT;
          FinSi

        ;}
    break;

  case 70:
#line 1837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        description:
        assigns the value val to every component 'n' of the input image
        **/
          int comp = (int) (yyvsp[(3) - (6)].adouble);

          Si (comp<0) Ou (comp>2) Alors
        fprintf(stderr,"image[n]=image error \n");
        comp = 0;
          FinSi

         InrImage::ptr i1 = *(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();

          Si i1->VectorialFormat()  Alors

             i1->InitBuffer();
             Repeter
           i1->VectFixeValeur(comp,(yyvsp[(6) - (6)].adouble));
             JusquA Non(i1->IncBuffer()) FinRepeter

      FinSi

        ;}
    break;

  case 71:
#line 1867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int posx  = (int) (yyvsp[(3) - (16)].adouble);
          int stepx = (int) (yyvsp[(5) - (16)].adouble);
          int posy  = (int) (yyvsp[(7) - (16)].adouble);
          int stepy = (int) (yyvsp[(9) - (16)].adouble);
          int posz  = (int) (yyvsp[(11) - (16)].adouble);
          int stepz = (int) (yyvsp[(13) - (16)].adouble);


          InrImage::ptr i1 = *(InrImage::ptr*) (yyvsp[(1) - (16)].variable)->Pointer();
          InrImage* i2 = (InrImage*) im_stack.GetLastImage();

          Func_Pad(i1.get(),i2,stepx,posx,stepy,posy,stepz,posz);

          delete i2;

        ;}
    break;

  case 72:
#line 1885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))++;
        ;}
    break;

  case 73:
#line 1889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))--;
        ;}
    break;

  case 74:
#line 1893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yyvsp[(1) - (3)].variable)->Pointer()) = (yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 75:
#line 1897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))++;
        ;}
    break;

  case 76:
#line 1901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))--;
        ;}
    break;

  case 77:
#line 1905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yyvsp[(1) - (3)].variable)->Pointer()) = (int) (yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 78:
#line 1909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yyvsp[(1) - (3)].variable)->Pointer()) = (unsigned char) (yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 79:
#line 1913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))++;
        ;}
    break;

  case 80:
#line 1917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))--;
        ;}
    break;

  case 81:
#line 1921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yyvsp[(3) - (3)].astring)));
          (yyvsp[(1) - (3)].variable)->SetString(newname);
        ;}
    break;

  case 82:
#line 1926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 83:
#line 1930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yyvsp[(2) - (2)].variable));
        ;}
    break;

  case 84:
#line 1939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yyvsp[(2) - (5)].variable)->Pointer());;
          int  i = (int) (yyvsp[(4) - (5)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        ;}
    break;

  case 85:
#line 1948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yyvsp[(2) - (2)].astring));
         gr_print(" command:  ASHELL ASTRING \n");

         delete [] (yyvsp[(2) - (2)].astring);
           ;}
    break;

  case 86:
#line 1955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
         gr_print("command : LS\n ");
           ;}
    break;

  case 87:
#line 1964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        res_print("Topics: \n");
        res_print("\t var:  variables                 \n");
            res_print("\t     image:     Help for image     variables\n");
            res_print("\t     imagedraw: Help for imagedraw variables\n");
        res_print("\t cmd:  commands                  \n");
        res_print("\t fnc:  functions                 \n");
        res_print("\t loop: loops                     \n");
        res_print("\t cond: conditions                \n");
            res_print("\t arit: arithmetical expressions  \n");

            gr_print("command : HELP\n ");
      ;}
    break;

  case 88:
#line 1978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       if (strcmp((yyvsp[(2) - (2)].ident),"var")==0) {
         res_print("var types: void image float int string imagedraw surface surfacedraw \n");
         res_print("\t del varname\n");
         res_print("\t\t\t - deletes a variable and frees its contents from memory \n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"cmd")==0) {
         res_print("commands:\n");
         res_print("\t sh Quit Image Show Help ls print func filter normgrad discnormgrad OpImage EDPdilate EDPerode EDPopen EDPclose\n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"fnc")==0) {
         res_print("functions:\n");
         res_print("\t  filter normgrad gradient OpImage secdergrad ");
             res_print("subimage putimage\n");
         res_print("\t       OpImage( var_image, string ) \n");
         res_print("\t       OpImage( var_image, var_image, string ) \n");
         res_print("\t       OpImage( var_image, var_image, var_image, string ) \n");
         res_print("\t       filter( var_image, expr, number, number, number ) \n");
         res_print("\t       normgrad(   var_image, expr ) \n");
         res_print("\t       discnormgrad(   var_image ) \n");
         res_print("\t       gradient(   var_image, expr ) \n");
         res_print("\t       secdergrad( var_image, expr ) \n");
         res_print("\t       subimage( var_image, expr, expr, expr, expr, expr, expr ) \n");
         res_print("\t       putimage( var_image, var_image, expr, expr, expr  ) \n");
         res_print("\t       EDPdilate( var_image, expr, expr) \n");
         res_print("\t       EDPerode(  var_image, expr, expr) \n");
         res_print("\t       EDPopen(   var_image, expr, expr) \n");
         res_print("\t       EDPclose(  var_image, expr, expr) \n");

         res_print("\t       AnisoGS(   var_image, expr, expr, expr, expr) \n");
         res_print("\t\t  expr 1: standard deviation of the Gaussian convolution  \n");
         res_print("\t\t  expr 2: threshold on the gradient norm \n");
         res_print("\t\t  expr 3: data attachment coefficient \n");
         res_print("\t\t  expr 4: number of iterations \n");
             res_print("\t       StructTensor( var_image, expr, expr ) \n");
             res_print("\t       Curvatures(   var_image, expr ) \n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"loop")==0) {
         res_print("loops:\n");
         res_print("\t  for var=expr to expr { instructions } \n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"cond")==0) {
         res_print("loops:\n");
         res_print("\t  if expr  { instructions } \n");
         res_print("\t\t  [ else { instructions } ]\n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"arit")==0) {
         res_print("arithmetical expressions:\n");
         res_print("\t  constants: Pi\n");
         res_print("\n");
         res_print("\t  functions:  cos()  sin()  tan() \n");
         res_print("\t             acos() asin() atan() \n");
         res_print("\t              exp()   ln()  log() \n");
         res_print("\t             sinh() cosh()        \n");
         res_print("\t  operators:\n");
         res_print("\t            *, /\n");
         res_print("\t            +, -\n");
         res_print("\t            <, >, <=, >=\n");
         res_print("\t            ==, != \n");
         res_print("\t            & \n");
         res_print("\t            ^ \n");
         res_print("\t            | \n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"image")==0) {
         res_print("variable Image\n");
         res_print(" Creation:\n");
         res_print("\t Image \"filename\"\n");
         res_print("\t\t\t - reads an image file \n");
         res_print("\t Image \n");
         res_print("\t\t\t -  open browsing window for choosing the image\n");
         res_print("\t Image(basic_type, size_x , size_y, size_z) \n");
         res_print("\t\t\t - create an image of a basic type and the given dimensions\n");
         res_print("\t\t\t - basic_type are CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR \n");
         res_print("\t\t\t - size_x, size_y, size_z: float expressions \n");
         res_print(" Functions that return a new image: \n");
         res_print("\t OpImage( var_image, string ) \n");
         res_print("\t\t\t - applies point to point operations to 1 image\n");
         res_print("\t OpImage( var_image, var_image, string ) \n");
         res_print("\t\t\t - applies point to point operations to 2 images\n");
         res_print("\t OpImage( var_image, var_image, var_image, string ) \n");
         res_print("\t\t\t - applies point to point operations to 3 images\n");
         res_print("\t filter( var_image, size, number, number, number ) \n");
         res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");
         res_print("\t\t\t - number represent the derivation order:\n");
         res_print("\t\t\t\t 0: no           derivation in this dimension\n");
         res_print("\t\t\t\t 1: first order  derivation in this dimension\n");
         res_print("\t\t\t\t 2: second order derivation in this dimension\n");
         res_print("\t normgrad(   var_image, expr ) \n");
         res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");

         res_print("\t discnormgrad(   var_image ) \n");
         res_print("\t\t\t - Discrete gradient norm without Gaussian convolution \n");

         res_print("\t gradient(   var_image, expr ) \n");
         res_print("\t\t\t - Gradient of the image using  Gaussian (and derivatives) convolution of sd size \n");

         res_print("\t secdergrad( var_image, expr ) \n");
             res_print("\t\t\t - Compute the second order derivative in the gradient direction.\n");


         res_print("\t subimage( var_image, expr, expr, expr,");
         res_print(" expr, expr, expr ) \n");
             res_print("\t\t\t - extract a subimage \n");

         res_print("\t AddGaussNoise( var_image, expr, expr) \n");
             res_print("\t\t\t - add a Gaussian noise to the image \n");
             res_print("\t\t\t - param 2: mean \n");
             res_print("\t\t\t - param 3: standard deviation \n");

         res_print("\t eccentricity( var_image) \n");
             res_print("\t\t\t - Compute a expression of eccentricity  \n");
             res_print("\t\t\t - of the image, returns an 'expr'  \n");

         res_print("\t isoarea2D( var_image, expr, expr, expr) \n");
             res_print("\t\t\t - Compute the surface area of the region\n");
             res_print("\t\t\t   of positive intensity containing the point\n");
             res_print("\t\t\t   (x,y)\n");
             res_print("\t\t\t expr 1: resolution  \n");
             res_print("\t\t\t expr 2: x  \n");
             res_print("\t\t\t expr 3: y  \n");

         res_print("\t EDPdilate( var_image, expr, expr) \n");
         res_print("\t EDPerode(  var_image, expr, expr) \n");
         res_print("\t EDPopen(   var_image, expr, expr) \n");
         res_print("\t EDPclose(  var_image, expr, expr) \n");

         res_print("\t AnisoGS(   var_image, expr, expr, expr, expr) \n");
         res_print("\t\t  expr 1: sigma     \n");
         res_print("\t\t  expr 2: threshold \n");
         res_print("\t\t  expr 3: data attachment coefficient \n");
         res_print("\t\t  expr 4: number of iterations \n");


         res_print("\t image = AnisoGS.init( var_image, expr, expr, expr )\n");
         res_print("\t\t  expr 1:    sigma  \n");
         res_print("\t\t  expr 2:    theshold  \n");
         res_print("\t\t  expr 3:    data attachment coeff  \n");
         res_print("\t AnisoGS.setcoeff( expr )\n");
         res_print("\t\t  expr 1:    tangential coeff  \n");
         res_print("\t AnisoGS.setcoeff( expr, expr )\n");
         res_print("\t\t  expr 1:    min curv coeff  \n");
         res_print("\t\t  expr 2:    max curv coeff  \n");
         res_print("\t AnisoGS.iterate\n");
         res_print("\t AnisoGS.end\n");

         res_print("\t image = AnisoWeickert.init( var_image, expr, expr, expr )\n");
         res_print("\t\t  expr 1:    sigma  \n");
         res_print("\t\t  expr 2:    theshold  \n");
         res_print("\t\t  expr 3:    evolution step dt  \n");
         res_print("\t AnisoWeickert.iterate\n");
         res_print("\t AnisoWeickert.end\n");

         res_print("\t image = AnisoCW.init( var_image, expr, expr, expr,expr, expr )\n");
         res_print("\t\t  expr 1:    sigma  first Gaussian convolution\n");
         res_print("\t\t  expr 2:    rho    second Gaussian convolution\n");
         res_print("\t\t  expr 2:    C      threshold for the coherence\n");
         res_print("\t\t  expr 2:    alpha  lowest diffusion coefficient\n");
         res_print("\t\t  expr 3:    dt     evolution step \n");
         res_print("\t AnisoCW.iterate\n");
         res_print("\t AnisoCW.end\n");

         res_print(" Operations: \n");

         res_print("\t Show var_image \n");
         res_print("\t\t\t - displays the image \n");

         res_print("\t var_image = var_image \n");
         res_print("\t\t\t - makes a copy \n");

         res_print("\t var_image.initvalue( expr ) \n");
             res_print("\t\t\t - initialize every point to a scalar value \n");

         res_print("\t var_image.initvalue( expr, expr, expr ) \n");
             res_print("\t\t\t - initialization every point to a vector or RGB value \n");

         res_print("\t var_image.set( expr ) \n");
         res_print("\t\t\t - change the value a the current point \n");

         res_print("\t var_image.set( expr, expr, expr ) \n");
         res_print("\t\t\t - change the value a the current point \n");
         res_print("\t\t\t - for RGB or VECTOR FIELD images \n");

         res_print("\t var_image.setpos(expr,expr,expr) \n");
         res_print("\t\t\t - set the current position \n");

         res_print("\t var_image.putimage(var_image,expr,expr,expr) \n");
         res_print("\t\t\t - put an image at the specified position \n");

         res_print("\t var_image(expr,expr) \n");
         res_print("\t\t\t - return the value at a 2D position \n");

         res_print("\t var_image(expr,expr,expr) \n");
         res_print("\t\t\t - return the value at a 3D position \n");

         res_print("\t var_image.tx \n");
         res_print("\t\t\t - return size in X \n");

         res_print("\t var_image.ty \n");
         res_print("\t\t\t - return size in Y \n");

         res_print("\t var_image.tz \n");
         res_print("\t\t\t - return size in Z \n");

         res_print("\t var_image.init \n");
         res_print("\t\t\t - init the current position to (0,0,0) \n");

         res_print("\t var_image.info \n");
         res_print("\t\t\t - print information on the image \n");

         res_print("\t var_image.save \"filename\" \n");
         res_print("\t\t\t - save the image \n");

         res_print("\t var_image.normalize \n");
         res_print("\t\t\t - normalizes a vector field image \n");
       }
       else
       if (strcmp((yyvsp[(2) - (2)].ident),"imagedraw")==0) {
         res_print("variable imagedraw\n");
         res_print(" Creation:");
         res_print("\t show var_image \n");
         res_print("\t\t\t - displays an image and creates a new variable\n");
         res_print("\t\t\t   of type imagedraw and the name ending by _draw \n");
         res_print(" Functions:\n");

         res_print(" var_imagedraw.setpos( expr, expr, expr) \n");
         res_print("\t\t\t   set the cursor position \n");

         res_print(" var_imagedraw.showcursor( expr) \n");
         res_print("\t\t\t   expr=1-->shows cursor   0-->hides cursor \n");

         res_print(" var_imagedraw.update \n");
         res_print("\t\t\t   update the displayed images \n");

         res_print(" var_imagedraw.compare(var_image) \n");
         res_print("\t\t\t   add a comparison image \n");

         res_print(" var_imagedraw.setvector( number, var_image) \n");
         res_print("\t\t\t   set var_image a the vector image with number \n");
         res_print("\t\t\t   between 1 and 3 \n");
       }
     ;}
    break;

  case 89:
#line 2226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string  help_cmd;
      string  help_file;


      // Check for directory
      help_file = str( format("%s/%s") % GB_help_dir.c_str() % (yyvsp[(2) - (2)].astring));

      Si GB_debug AlorsFait fprintf(stderr,"3\n");
          help_cmd = str(format("test -d %s") % help_file.c_str());
          Si (std::system(help_cmd.c_str()) == 0) Alors
            printf("\nAvailable help files in %s:\n",(yyvsp[(2) - (2)].astring));
            help_cmd = str( format("cd %s; ls *.amih ") % help_file.c_str());
            std::system(help_cmd.c_str());
          Sinon

         Si GB_debug AlorsFait fprintf(stderr,"4\n");
            // Check for file
            help_file = str( format("%s/%s.amih") % GB_help_dir.c_str() %(yyvsp[(2) - (2)].astring));

            help_cmd = str(format("test -r %s") % help_file.c_str());
            Si (std::system(help_cmd.c_str()) == 0) Alors
              help_cmd = str( format("more %s") % help_file.c_str());
              std::system(help_cmd.c_str());
            Sinon
              Si GB_debug AlorsFait fprintf(stderr,"5\n");
              // Try to find it in any subdirectory of the help dir
              help_cmd = str(format("test -r `find %s -name \"%s.amih\"` 2> /dev/null")
                            % GB_help_dir.c_str()
                            % (yyvsp[(2) - (2)].astring));
              Si std::system(help_cmd.c_str())==0 Alors
                help_cmd = str(format("find %s -name \"%s.amih\" -exec ls {} \\; -exec more {} \\;")
                  % GB_help_dir.c_str()
                  % (yyvsp[(2) - (2)].astring));
                std::system(help_cmd.c_str());
              Sinon
                fprintf(stderr,"\nNo help file (%s) found for this command \n",
            help_file.c_str());
            printf("\nAvailable help directories:\n");
            help_cmd = str(format("cd %s; find . -type d  ") % GB_help_dir.c_str());
                std::system(help_cmd.c_str());

                printf("\nAvailable help files:\n");
            help_cmd = str(format("ls *.amih ") %
                std::system(help_cmd.c_str()));
          FinSi
            FinSi

          FinSi

      Si GB_debug AlorsFait fprintf(stderr,"6\n");

        ;}
    break;

  case 90:
#line 2280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (4)].variable)->Pointer());

          fprintf(file.get(),"%s",(yyvsp[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yyvsp[(4) - (4)].astring);
        ;}
    break;

  case 91:
#line 2288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          res_print((yyvsp[(2) - (2)].astring));
          delete [] (yyvsp[(2) - (2)].astring);
        ;}
    break;

  case 92:
#line 2297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string and newline
          **/
        res_print((yyvsp[(2) - (2)].astring));
        res_print("\n");
        delete [] (yyvsp[(2) - (2)].astring);
          ;}
    break;

  case 93:
#line 2307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 94:
#line 2313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 95:
#line 2319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (4)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yyvsp[(4) - (4)].adouble));
          fflush(file.get());
        ;}
    break;

  case 96:
#line 2326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        ;}
    break;

  case 97:
#line 2332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value.
        **/
          string st;
          st = str(format("%5.10f") % (yyvsp[(2) - (2)].adouble));
          res_print(st.c_str());
        ;}
    break;

  case 98:
#line 2342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value and a newline.
        **/
          string st;
          st = str(format("%5.10f\n") %(yyvsp[(2) - (2)].adouble));
          res_print(st.c_str());
        ;}
    break;

  case 99:
#line 2352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (10)].variable)->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yyvsp[(5) - (10)].adouble);
          param->_pos._y = (int) (yyvsp[(7) - (10)].adouble);
          param->_pos._z = (int) (yyvsp[(9) - (10)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

          gr_print("command : VAR_IMAGEDRAW '.' SETPOS");
          gr_print("'(' expr ',' expr ',' expr ')'\n ");
        ;}
    break;

  case 100:
#line 2370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yyvsp[(5) - (6)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        ;}
    break;

  case 101:
#line 2382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        ;}
    break;

  case 102:
#line 2392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;
            InrImage::ptr im;
            char title[255];
            int i;
            Variable* var;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
            im   = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();

            sprintf(title,"%s_draw",(yyvsp[(5) - (6)].variable)->Name());

            if (Vars.GetCurrentContext()->GetVar(title,&var)) {
              DessinImage::ptr di;
              DessinImageParametres* param;
              di = *(DessinImage::ptr*) var->Pointer();
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();

/* already done at window creation
              std::string* varname = new std::string(title);
              di->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
*/
              draw->CreeCompare2Image(di);
            }
            else
            {
              DessinImage* di;
              std::string* varname = new std::string(title);
              di = CreateIDraw( *varname, im);

              i = Vars.AddVar(type_imagedraw,title, (void*) di);
              di->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) (varname));
              // get the pointer to the newly created
              // variable
              Variable* var;
              if (Vars.GetVar(title,&var))
                draw->CreeCompare2Image(*(DessinImage::ptr*)var->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        ;}
    break;

  case 103:
#line 2441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw1;
        DessinImage::ptr draw2;

          draw1 = *(DessinImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          draw2 = *(DessinImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();

/*          std::string* varname = new std::string($5->Name());
          draw2->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
*/
          draw1->CreeCompare2Image(draw2);
        ;}
    break;

  case 104:
#line 2456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (1) Image Draw Window
            (5)  comparison window
            (7) Vectorial image

        Description:
            Defines a displacement to apply to the cursor when
            comparing 2 image drawing windows
        **/
          DessinImage::ptr draw;
          DessinImage::ptr draw2;
          InrImage::ptr displ;

          draw  = *(DessinImage::ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
          draw2 = *(DessinImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer();
          displ = *(InrImage::ptr*)    (yyvsp[(7) - (8)].variable)->Pointer();
          draw->SetCompareDisplacement(draw2,displ);
        ;}
    break;

  case 105:
#line 2481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw;
        FloatMatrix* mat;

        draw = *(DessinImage::ptr*) ((yyvsp[(1) - (28)].variable)->Pointer());

        mat = new FloatMatrix(4,4);
        (*mat)[0][0] = (yyvsp[(5) - (28)].adouble);
        (*mat)[0][1] = (yyvsp[(7) - (28)].adouble);
        (*mat)[0][2] = (yyvsp[(9) - (28)].adouble);
        (*mat)[0][3] = (yyvsp[(11) - (28)].adouble);
        (*mat)[1][0] = (yyvsp[(13) - (28)].adouble);
        (*mat)[1][1] = (yyvsp[(15) - (28)].adouble);
        (*mat)[1][2] = (yyvsp[(17) - (28)].adouble);
        (*mat)[1][3] = (yyvsp[(19) - (28)].adouble);
        (*mat)[2][0] = (yyvsp[(21) - (28)].adouble);
        (*mat)[2][1] = (yyvsp[(23) - (28)].adouble);
        (*mat)[2][2] = (yyvsp[(25) - (28)].adouble);
        (*mat)[2][3] = (yyvsp[(27) - (28)].adouble);

            if (draw->GetCompareWindow(0)!=NULL)
          draw->GetCompareWindow(0)->SetTransformationMatrix(mat);
        // PB: the matrix is never freed from memory ...
        // TODO use smart pointer management !!!

        ;}
    break;

  case 106:
#line 2508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
          draw->LoadVectImage( (int) (yyvsp[(5) - (8)].adouble), (*(InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer()));
        ;}
    break;

  case 107:
#line 2523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yyvsp[(5) - (8)].adouble), (int) (yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 108:
#line 2530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        ;}
    break;

  case 109:
#line 2537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          DessinImage::ptr draw;
          float size    = (yyvsp[(5) - (8)].adouble);
          int   spacing = (int)(yyvsp[(7) - (8)].adouble);

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
          draw->SetVectParam( size, spacing);
        ;}
    break;

  case 110:
#line 2555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
            (5)  expression: vector id
            (7)  expression: red component (0-255)
            (9)  expression: green component (0-255)
            (11) expression: blue component (0-255)

            Description:
            Sets the color of the given vector field (given by vector id),
            the color is set as (R,G,B) components, each component has a value
            between 0 and 255.
          **/
          DessinImage::ptr draw;
          int vectid = (int) (yyvsp[(5) - (12)].adouble);
          unsigned char red   = (unsigned char) (yyvsp[(7) - (12)].adouble);
          unsigned char green = (unsigned char) (yyvsp[(9) - (12)].adouble);
          unsigned char blue  = (unsigned char) (yyvsp[(11) - (12)].adouble);

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (12)].variable)->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        ;}
    break;

  case 111:
#line 2578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          draw->SetVectType((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 112:
#line 2583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          draw->SetLineThickness((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 113:
#line 2588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int xmin = (int)  (yyvsp[(5) - (16)].adouble);
          int ymin = (int)  (yyvsp[(7) - (16)].adouble);
          int zmin = (int)  (yyvsp[(9) - (16)].adouble);
          int xmax = (int) (yyvsp[(11) - (16)].adouble);
          int ymax = (int) (yyvsp[(13) - (16)].adouble);
          int zmax = (int) (yyvsp[(15) - (16)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (16)].variable)->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        ;}
    break;

  case 114:
#line 2601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yyvsp[(5) - (8)].adouble);
          int height = (int) (yyvsp[(7) - (8)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        ;}
    break;

  case 115:
#line 2612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (16)].variable)->Pointer());
          c.FixeValeur((int)(yyvsp[(11) - (16)].adouble),(int)(yyvsp[(13) - (16)].adouble),(int)(yyvsp[(15) - (16)].adouble));
          draw->DessineCercle( (int) (yyvsp[(5) - (16)].adouble), (int) (yyvsp[(7) - (16)].adouble), (int) (yyvsp[(9) - (16)].adouble), c);
        ;}
    break;

  case 116:
#line 2621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (10)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yyvsp[(7) - (10)].adouble),  (yyvsp[(9) - (10)].adouble));
          //      delete colmap;
        ;}
    break;

  case 117:
#line 2630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yyvsp[(5) - (6)].variable)->Pointer()));

        ;}
    break;

  case 118:
#line 2638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (10)].variable)->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) (yyvsp[(7) - (10)].variable)->Pointer()), (yyvsp[(9) - (10)].adouble) , (int) (yyvsp[(5) - (10)].adouble) );
            draw->DrawIsoContour( (int) (yyvsp[(5) - (10)].adouble), true );
        ;}
    break;

  case 119:
#line 2655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer()), (yyvsp[(7) - (8)].adouble) , 0 );
            draw->DrawIsoContour( 0, true );
        ;}
    break;

  case 120:
#line 2671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) isocontour thickness
                (9) isocontour style

            Description:
                Sets the parameters (line style and thickeness)
                of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (10)].variable)->Pointer());
            draw->SetIsoContourParam( (int)(yyvsp[(5) - (10)].adouble), (int)(yyvsp[(7) - (10)].adouble), (int)(yyvsp[(9) - (10)].adouble) );
        ;}
    break;

  case 121:
#line 2688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5)  isocontour index (0,1 or 2)
                (7)  isocontour thickness
                (9)  isocontour style (0,1,2 for LineSolid, LineOnOffDash, or LineDoubleDash)
                (11) cap_style (0:CapNotLast, 1:CapButt, 2:CapRound, or 3:CapProjecting)
                (13) join_style (0:JoinMiter, 1:JoinRound, or 2:JoinBevel)

            Description:
                Sets the parameters (line style and thickeness)
                of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (14)].variable)->Pointer());
            draw->SetIsoContourParam( (int)(yyvsp[(5) - (14)].adouble), (int)(yyvsp[(7) - (14)].adouble), (int)(yyvsp[(9) - (14)].adouble) );
            draw->SetLineAttributes( (int)(yyvsp[(11) - (14)].adouble), (int)(yyvsp[(13) - (14)].adouble));
        ;}
    break;

  case 122:
#line 2708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
            draw->DrawIsoContour( (int) (yyvsp[(5) - (8)].adouble), (int) (yyvsp[(7) - (8)].adouble) );
        ;}
    break;

  case 123:
#line 2723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7)  Red   component in [0,255]
                (9)  Green component in [0,255]
                (11) Blue  component in [0,255]

            Description:
                Sets the color as RGB of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (12)].variable)->Pointer());
            draw->SetIsoContourColor( (int) (yyvsp[(5) - (12)].adouble), (unsigned char) (yyvsp[(7) - (12)].adouble),
                                                (unsigned char) (yyvsp[(9) - (12)].adouble),
                                                (unsigned char) (yyvsp[(11) - (12)].adouble));
        ;}
    break;

  case 124:
#line 2741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
            draw->SetDrawAllContours( (int) (yyvsp[(5) - (6)].adouble) );
        ;}
    break;

  case 125:
#line 2754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
            draw->AllContoursParam(  (yyvsp[(5) - (8)].adouble) , (yyvsp[(7) - (8)].adouble) );
        ;}
    break;

  case 126:
#line 2768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yyvsp[(5) - (6)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        ;}
    break;

  case 127:
#line 2777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          DessinImage::ptr draw;
          InrImage::ptr im;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          im = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();
          draw->SetVolRenOpacity( im.get());
        ;}
    break;

  case 128:
#line 2791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          (5) expr:  value to init the image

        description:
          Set the whole image to the same vector value .
        **/
          (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->InitImage((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 129:
#line 2802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        description:
          Set the whole image to the same value.
        **/
      (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->InitImage((yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble));
        ;}
    break;

  case 130:
#line 2815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          #1 expr:  scalar value

        description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        Others:
                setpos
        **/
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->FixeValeur((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 131:
#line 2833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        /**
        parameters:
          #1 expr:  X coord of the vector value
          #2 expr:  Y coord of the vector value
          #3 expr:  Z coord of the vector value

        description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        Others:
                setpos
        **/

      (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->VectFixeValeurs((yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble));
        ;}
    break;

  case 132:
#line 2855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X position
          (7) expr:  Y position
          (9) expr:  Z position

        Description:
          Set the current voxel (or pixel) of the image
          to the specified position.

        See Also:
          set
        **/
          Si (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->CoordOK( (int) (yyvsp[(5) - (10)].adouble),(int)(yyvsp[(7) - (10)].adouble),(int)(yyvsp[(9) - (10)].adouble))
          Alors
        (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->BufferPos((int)(yyvsp[(5) - (10)].adouble),(int)(yyvsp[(7) - (10)].adouble),(int)(yyvsp[(9) - (10)].adouble));
          Sinon
        sprintf(tmp_string,"coord = %f %f %f \n",(yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
        err_print(tmp_string);
          FinSi
        ;}
    break;

  case 133:
#line 2881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert
          (7)  expr:      X position of inserted image
          (9)  expr:      Y position
          (11) expr:      Z position

        description:
          Insert an image (#2) in a given image (#1)
          at the specified position in voxel coordinates,
          does not use the translation information from the image.

        Example:
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
       InrImage::ptr  i1;
       InrImage::ptr  i2;

       i1 = *(InrImage::ptr*) (yyvsp[(1) - (12)].variable)->Pointer();
       i2 = *(InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer();
       Func_PutImage( i1.get(), i2.get(), (int) (yyvsp[(7) - (12)].adouble), (int) (yyvsp[(9) - (12)].adouble), (int) (yyvsp[(11) - (12)].adouble));
        ;}
    break;

  case 134:
#line 2909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert

        description:
          Insert an image  in a given image,
          uses the translation and the voxel size information
          to calculate where to insert the image.

        Example:
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
      InrImage::ptr  i1;
      InrImage::ptr  i2;
      float tx1,ty1,tz1;
      float tx2,ty2,tz2;

          i1 = *(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          i2 = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();
      i1->GetTranslation(tx1,ty1,tz1);
      i2->GetTranslation(tx2,ty2,tz2);
      Func_PutImage( i1.get(), i2.get(),
             (int) round((tx2-tx1)/i1->VoxSizeX()),
             (int) round((ty2-ty1)/i1->VoxSizeY()),
             (int) round((tz2-tz1)/i1->VoxSizeZ()));
        ;}
    break;

  case 135:
#line 2940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->FixeNom( (yyvsp[(5) - (6)].astring));
      delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 136:
#line 2946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (5)  var_image: input image
            (7)  expr: sigma, standard deviation of the Gaussian smoothing used
                        to compute the gradient and principal curvature directions
            (9)  expr:  threshold on the magnitude of the gradient
            (11) expr: data attachment coefficient

        Description:
            Sets parameters for the anisotropic diffusion algorithm using
            Gauss-Seidel scheme.
        **/
        Func_InitAnisoGS( ((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get(),
                          (yyvsp[(7) - (12)].adouble),  (yyvsp[(9) - (12)].adouble), (yyvsp[(11) - (12)].adouble));
        ;}
    break;

  case 137:
#line 2964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 138:
#line 2969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 139:
#line 2974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 140:
#line 2979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 141:
#line 2984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 142:
#line 2989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Oriented Speckle Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Oriented Speckle Reducing Anisotropic Diffusion
         **/
          Func_AnisoGS_SetSRAD_ROI(((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 143:
#line 3003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Rician Noise Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Rician Noise Reducing Anisotropic Diffusion
            used to reduce noise in MRI data.
         **/
          Func_AnisoGS_SetRNRAD_ROI(((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 144:
#line 3018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Rician Noise Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Rician Noise Reducing Anisotropic Diffusion
            used to reduce noise in MRI data.
            New version of the filter, using local directional mean and variance
            for the diffusion matrix.
         **/
          Func_AnisoGS_SetRNRAD_ROI_NEW(((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 145:
#line 3035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (5) expr: determine the local structure description
              0 for smoothed gradient and principal curv. directions
              1 for the local structure tensor

          Description:
            Sets the local structure mode.
         **/
      Func_SetLocalStructureMode((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 146:
#line 3049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (5) expr: option for selecting the eigenvalues for the
              diffusion matrix
              0: sums the 3D, 2D and 1D diffusions
                - lambda1 will depend on a coefficient based on a
                    3D neighborhood
                - lambda2 will be the sum of lambda1 + a coeff based
                    on a 2D neighborhood
                - lambda3 = lambda2 + coeff based on a linear neigh.
              1: take the maximum instead of the sum

          Description:
            Choose a way to select the diffusion matrix eigenvalues.
         **/
      Func_SetEigenvaluesMode((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 147:
#line 3069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 148:
#line 3074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 149:
#line 3079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yyvsp[(5) - (8)].adouble),(yyvsp[(7) - (8)].adouble));

    ;}
    break;

  case 150:
#line 3086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

//    sprintf(tmp_string,"error = %f \n",error);
      res_print(tmp_string);
    ;}
    break;

  case 151:
#line 3096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    ;}
    break;

  case 152:
#line 3104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 153:
#line 3109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 154:
#line 3116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 155:
#line 3121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 156:
#line 3126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. number of iterations
    // 2. coefficient of the data attachment
    // 3. curvature coefficient
    // 4. reinitialization frequency for the distance map

    Func_LevelSets_InitParam(
                 0.8,
                 (int) (yyvsp[(5) - (12)].adouble),
                 (yyvsp[(7) - (12)].adouble),
                 (yyvsp[(9) - (12)].adouble),
                 1,
                 (int) (yyvsp[(11) - (12)].adouble)
                 );

        ;}
    break;

  case 157:
#line 3147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. threshold on the cumulative histo of the grad norm for data attachment
    // 2. number of iterations
    // 3. coefficient of the data attachment
    // 4. curvature coefficient
    // 5. evolution step dt
    // 6. reinitialization frequency for the distance map


      Func_LevelSets_InitParam(
                   (yyvsp[(5) - (16)].adouble),
                   (int) (yyvsp[(7) - (16)].adouble),
                   (yyvsp[(9) - (16)].adouble),
                   (yyvsp[(11) - (16)].adouble),
                   (yyvsp[(13) - (16)].adouble),
                   (int) (yyvsp[(15) - (16)].adouble)
                   );

        ;}
    break;

  case 158:
#line 3170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 159:
#line 3175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 160:
#line 3180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 161:
#line 3185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 162:
#line 3190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 163:
#line 3195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 164:
#line 3200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 165:
#line 3205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 166:
#line 3210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 167:
#line 3215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 168:
#line 3220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 169:
#line 3225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 170:
#line 3230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yyvsp[(5) - (14)].adouble), (int) (yyvsp[(7) - (14)].adouble), (int) (yyvsp[(9) - (14)].adouble), (int) (yyvsp[(11) - (14)].adouble), (int) (yyvsp[(13) - (14)].adouble));
    ;}
    break;

  case 171:
#line 3235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 172:
#line 3240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),(yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 173:
#line 3245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 174:
#line 3250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 175:
#line 3255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yyvsp[(5) - (8)].adouble),(int)(yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 176:
#line 3260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 177:
#line 3265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(7) - (10)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(9) - (10)].variable)->Pointer())->get());
        ;}
    break;

  case 178:
#line 3273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 179:
#line 3278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 180:
#line 3283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 181:
#line 3288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 182:
#line 3293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 183:
#line 3298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 184:
#line 3303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        ;}
    break;

  case 185:
#line 3308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        ;}
    break;

  case 186:
#line 3313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        ;}
    break;

  case 187:
#line 3318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 188:
#line 3323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 189:
#line 3328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    ;}
    break;

  case 190:
#line 3333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    ;}
    break;

  case 191:
#line 3337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          (4) expr_string:  image name

        Description:
          Save the image to the disk, using the specified
          image name.
          The output format depends on the image type
          and on the filename extension.
          For saving images with standard 2D image format
          (jpeg, gif, etc...) you need to have a RGB image.


        Example:

          rgb_im = (RGB) im
          im.save "image.jpg"


        See also:
          image_cast
        **/
      (*(InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->Sauve((yyvsp[(4) - (4)].astring));
      delete [] (yyvsp[(4) - (4)].astring);
        ;}
    break;

  case 192:
#line 3364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example:
          v1.normalize

        **/
      Func_Normalize((((InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->get()));
        ;}
    break;

  case 193:
#line 3377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->get() , ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );
        ;}
    break;

  case 194:
#line 3382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->get() , ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );
    ;}
    break;

  case 195:
#line 3386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->Write((yyvsp[(4) - (4)].astring));
      delete [] (yyvsp[(4) - (4)].astring);
    ;}
    break;

  case 196:
#line 3392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      SurfacePoly::ptr surf = (*(SurfacePoly::ptr*) (yyvsp[(1) - (4)].variable)->Pointer());
      Func_WriteCTALine(surf.get(),(yyvsp[(4) - (4)].astring));
      delete [] (yyvsp[(4) - (4)].astring);
    ;}
    break;

  case 197:
#line 3405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetOwnMaterial( (int) (yyvsp[(5) - (6)].adouble));

        ;}
    break;

  case 198:
#line 3411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 199:
#line 3417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 200:
#line 3423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 201:
#line 3430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->GetMaterial()._shininess= (yyvsp[(5) - (6)].adouble);

        ;}
    break;

  case 202:
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->GetMaterial()._opacity= (yyvsp[(5) - (6)].adouble);

        ;}
    break;

  case 203:
#line 3444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets the object visible or not visible in the scene.
        **/

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetVisible( (int) (yyvsp[(5) - (6)].adouble));

        ;}
    break;

  case 204:
#line 3455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yyvsp[(5) - (6)].adouble)>0.5);

        ;}
    break;

  case 205:
#line 3466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
         (1) surface object
         (5) alpha value

        Description:
         to define the transparency to the RGB color
         associated per each vertex (actived with Enable ColorMaterial)
        **/

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetColorOpacity((yyvsp[(5) - (6)].adouble));

        ;}
    break;

  case 206:
#line 3481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int n;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yyvsp[(5) - (10)].adouble),
                 (unsigned char) (yyvsp[(7) - (10)].adouble),
                 (unsigned char) (yyvsp[(9) - (10)].adouble));
      FinPour

          s->SetColorMaterial(true);
          s->GLRecomputeList(  );

        ;}
    break;

  case 207:
#line 3496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

        ;}
    break;

  case 208:
#line 3504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->SetColors( i , (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 209:
#line 3513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->SetColors( i );

        ;}
    break;

  case 210:
#line 3522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

        ;}
    break;

  case 211:
#line 3530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->MergePoints((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 212:
#line 3534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->Triangulate();
        ;}
    break;

  case 213:
#line 3538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      float        depth = (yyvsp[(5) - (6)].adouble);
      char         name[100];
      int          n;

      // param 1: depth (neighborhood)
      //

      // Create images for the curvatures and their directions
      InrImage* Icmin;
      InrImage* Icmax;
      InrImage* Idmin;
      InrImage* Idmax;

      n = surf->GetNumberOfPoints();

      Icmin = new InrImage(n,1,1,WT_FLOAT,"mincurv.ami.gz");
      Icmax = new InrImage(n,1,1,WT_FLOAT,"maxcurv.ami.gz");

      Idmin = new InrImage(n,1,1,3,WT_FLOAT,"mincurvdir.ami.gz");
      Idmax = new InrImage(n,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz");

      surf->ComputeCurvatures(Icmin,Icmax,Idmin,Idmax, (int) depth);

      sprintf(name,"%s_cmin",(yyvsp[(1) - (6)].variable)->Name());
      Vars.AddVar(type_image,name,Icmin);
      sprintf(name,"%s_cmax",(yyvsp[(1) - (6)].variable)->Name());
      Vars.AddVar(type_image,name,Icmax);
      sprintf(name,"%s_dmin",(yyvsp[(1) - (6)].variable)->Name());
      Vars.AddVar(type_image,name,Idmin);
      sprintf(name,"%s_dmax",(yyvsp[(1) - (6)].variable)->Name());
      Vars.AddVar(type_image,name,Idmax);

        ;}
    break;

  case 214:
#line 3575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        ;}
    break;

  case 215:
#line 3584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      s->Translate( (yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble) );

        ;}
    break;

  case 216:
#line 3591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      s->Scale( (yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble),0 );

        ;}
    break;

  case 217:
#line 3598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          int          w = (int) (yyvsp[(5) - (6)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        ;}
    break;

  case 218:
#line 3609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

      s->RemoveLine((int)(yyvsp[(5) - (6)].adouble));
          s->GLRecomputeList();

    ;}
    break;

  case 219:
#line 3617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
      InrImage* im = (InrImage*) im_stack.GetLastImage();

      s->SelectLines(im);
      s->GLRecomputeList();
      delete im;
    ;}
    break;

  case 220:
#line 3635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    ;}
    break;

  case 221:
#line 3645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GLRecomputeList();

        ;}
    break;

  case 222:
#line 3650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

      s->RecomputeNormals();

        ;}
    break;

  case 223:
#line 3657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

      s->InvertNormals();

        ;}
    break;

  case 224:
#line 3664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yyvsp[(5) - (6)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 225:
#line 3672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yyvsp[(5) - (6)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 226:
#line 3680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          SurfacePoly::ptr surf_init = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          SurfacePoly* surf;

          surf = Func_decimate(surf_init.get());
      Si surf != NULL Alors

        // Non correct: supprimer la variable et la re-creer:
        // car pb si la variable est deja utilisee ...
        //          $1->Init(type_surface,$1->Name(), surf);
        //      delete surf_init;
      Sinon
        fprintf(stderr,"improcess.y: var_surface.T_vtkDecimate \t error \n ");
          FinSi


    ;}
    break;

  case 227:
#line 3699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yyvsp[(5) - (6)].adouble));

        ;}
    break;

  case 228:
#line 3715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yyvsp[(5) - (6)].adouble));
            //          FinSi

        ;}
    break;

  case 229:
#line 3732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (8)].variable)->Pointer());
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yyvsp[(5) - (8)].adouble),(int) (yyvsp[(7) - (8)].adouble));
        //          FinSi

        ;}
    break;

  case 230:
#line 3749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());
      s->AddPoint((yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 231:
#line 3754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      s->NewLine();
    ;}
    break;

  case 232:
#line 3759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yyvsp[(5) - (6)].adouble) );
    ;}
    break;

  case 233:
#line 3764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      s->EndLine();
    ;}
    break;

  case 234:
#line 3769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yyvsp[(3) - (4)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yyvsp[(3) - (4)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yyvsp[(3) - (4)].astring);
        ;}
    break;

  case 235:
#line 3778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr di = *(DessinImage::ptr*) (yyvsp[(3) - (20)].variable)->Pointer();
      float minlat  = (yyvsp[(5) - (20)].adouble);
      float maxlat  = (yyvsp[(7) - (20)].adouble);
      float latstep = (yyvsp[(9) - (20)].adouble);
      float latsmallsteps = (yyvsp[(11) - (20)].adouble);
      float minlon  = (yyvsp[(13) - (20)].adouble);
      float maxlon  = (yyvsp[(15) - (20)].adouble);
      float lonstep = (yyvsp[(17) - (20)].adouble);
      float lonsmallsteps = (yyvsp[(19) - (20)].adouble);

      float  lat,lon;
      float  X,Y;
      float  posx1=0,posy1=0;
      int    pos1_OK,pos2_OK;
      float  posx2=0,posy2=0;
      int    len;
      AMIFluid::TNavig nav_params;
      int    i_offset, j_offset;
      int    type=1; // Africa
      char typestring[2][255] = {"NAtl","AfGG"};

      InrImage::ptr           im    = di->GetImage();
      DessinImageParametres* param = di->GetParam();

          AMIFluid::InitCoordinates(i_offset,j_offset,nav_params, typestring[type]);
      minlat  *= PI/180.0;
      maxlat  *= PI/180.0;
      minlon  *= PI/180.0;
      maxlon  *= PI/180.0;
      latstep *= PI/180.0;
      lonstep *= PI/180.0;

      latsmallsteps *= PI/180.0;
      lonsmallsteps *= PI/180.0;

      // Lattitude lines
      for(lat=minlat;lat<=maxlat;lat+=latstep) {
        pos1_OK=0;
        for(lon=minlon;lon<=maxlon;lon+=lonsmallsteps)
          {
        AMIFluid::COOCAR1(lat,lon,X,Y,len,nav_params);
        if (len==0) {
          //          printf("len==0\n");
          X=X-i_offset;
          Y=Y-j_offset;
          posx2=(X-im->TrX())/im->VoxSizeX();
          posy2=(Y-im->TrY())/im->VoxSizeY();

          pos2_OK =  ((posx2>=param->_Zoom._xmin)&&(posx2<=param->_Zoom._xmax)&&
                  (posy2>=param->_Zoom._ymin)&&(posy2<=param->_Zoom._ymax));
          if (pos1_OK&&pos2_OK) {
            if (fabsf(lat)>1E-5)
              di->FixeParametresLigne( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
            di->DrawLineZ(posx1,posy1,posx2,posy2);
          }
        }
        else pos2_OK=0;

        posx1=posx2;
        posy1=posy2;
        pos1_OK=pos2_OK;
          }
      }

      // Longitude Lines
      for(lon=minlon;lon<=maxlon;lon+=lonstep) {
        pos1_OK=0;
        for(lat=minlat;lat<=maxlat;lat+=latsmallsteps)
          {
        AMIFluid::COOCAR1(lat,lon,X,Y,len,nav_params);
        if (len==0) {
          //          printf("len==0\n");
          X=X-i_offset;
          Y=Y-j_offset;
          posx2=(X-im->TrX())/im->VoxSizeX();
          posy2=(Y-im->TrY())/im->VoxSizeY();

          pos2_OK =  ((posx2>=param->_Zoom._xmin)&&(posx2<=param->_Zoom._xmax)&&
                  (posy2>=param->_Zoom._ymin)&&(posy2<=param->_Zoom._ymax));
          if (pos1_OK&&pos2_OK) {
            if (fabsf(lon)>1E-5)
              di->FixeParametresLigne( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
            di->DrawLineZ(posx1,posy1,posx2,posy2);
          }
        }
        else pos2_OK=0;

        posx1=posx2;
        posy1=posy2;
        pos1_OK=pos2_OK;
          }
      }

        ;}
    break;

  case 236:
#line 3878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          ElevateMesh can have different behaviors depending on the type of
          the input image. In any case, it scans all the points of the mesh,
          and uses their 2 first coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - if the image is scalar, the value of the image at position
            (x,y) is used to set the elevation of the mesh (z coordinate).
            - if the image contains 2D vectors, the vectors are used to set
            the (x,y) coordinates of each vertex of the mesh.
            - if the image contains 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (1) input surface
        (5) input image

       Examples:
         s = CreateFlatMesh(i)
         ipos = Altitude2Postion(i,1)
         s.ElevateMesh(ipos)

       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      AMIFluid::Func_ElevateMesh(s.get(),im);
      delete im;
        ;}
    break;

  case 237:
#line 3912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 238:
#line 3919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 239:
#line 3927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yyvsp[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        ;}
    break;

  case 240:
#line 3933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yyvsp[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        ;}
    break;

  case 241:
#line 3940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yyvsp[(5) - (6)].variable)->Pointer());
          sdraw->Paint(false);
        ;}
    break;

  case 242:
#line 3950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        ;}
    break;

  case 243:
#line 3959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yyvsp[(5) - (6)].adouble) );
          sdraw->Paint();
        ;}
    break;

  case 244:
#line 3966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (8)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yyvsp[(5) - (8)].adouble), (int) (yyvsp[(7) - (8)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 245:
#line 3973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yyvsp[(5) - (6)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        ;}
    break;

  case 246:
#line 3983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yyvsp[(5) - (6)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        ;}
    break;

  case 247:
#line 3990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw;

      draw = *((Viewer3D_ptr*) (yyvsp[(1) - (8)].variable)->Pointer());
      switch ((int) (yyvsp[(5) - (8)].adouble)) {
      case 1:
        draw->GetCanvas()->SetVectors1( (*(InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer()));
        break;
      case 2:
        draw->GetCanvas()->SetVectors2( (*(InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer()));
        break;
      }
    ;}
    break;

  case 248:
#line 4004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yyvsp[(1) - (16)].variable)->Pointer());
      int num = (int) (yyvsp[(5) - (16)].adouble);
          InrImage* im = (InrImage*) im_stack.GetLastImage();
      int orientation = (int) (yyvsp[(9) - (16)].adouble);
          int pos = (int) (yyvsp[(11) - (16)].adouble);
          float Imin = (yyvsp[(13) - (16)].adouble);
          float Imax = (yyvsp[(15) - (16)].adouble);

      draw->GetCanvas()->ShowFreeSection(num,im,orientation,pos,Imin,Imax);

          delete im;
        ;}
    break;

  case 249:
#line 4018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
      int num = (int) (yyvsp[(5) - (6)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        ;}
    break;

  case 250:
#line 4026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        ;}
    break;

  case 251:
#line 4031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        ;}
    break;

  case 252:
#line 4039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yyvsp[(7) - (8)].adouble)>0.5) sdraw->Paint();
          delete tr;
        ;}
    break;

  case 253:
#line 4047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        ;}
    break;

  case 254:
#line 4058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (12)].variable)->Pointer();
          int lightnumber = (int) (yyvsp[(5) - (12)].adouble);
          int r = (int) (yyvsp[(7) - (12)].adouble);
          int g = (int) (yyvsp[(9) - (12)].adouble);
          int b = (int) (yyvsp[(11) - (12)].adouble);
      if (lightnumber<MAX_LIGHTS) {
            sdraw->GetCanvas()->GetLight(lightnumber)._ambient.FixeValeur(r,g,b);
        sdraw->Paint();
      }
    ;}
    break;

  case 255:
#line 4070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (12)].variable)->Pointer();
          int lightnumber = (int) (yyvsp[(5) - (12)].adouble);
          int r = (int) (yyvsp[(7) - (12)].adouble);
          int g = (int) (yyvsp[(9) - (12)].adouble);
          int b = (int) (yyvsp[(11) - (12)].adouble);
      if (lightnumber<MAX_LIGHTS) {
            sdraw->GetCanvas()->GetLight(lightnumber)._diffuse.FixeValeur(r,g,b);
        sdraw->Paint();
      }
    ;}
    break;

  case 256:
#line 4082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (12)].variable)->Pointer();
          int lightnumber = (int) (yyvsp[(5) - (12)].adouble);
          int r = (int) (yyvsp[(7) - (12)].adouble);
          int g = (int) (yyvsp[(9) - (12)].adouble);
          int b = (int) (yyvsp[(11) - (12)].adouble);
      if (lightnumber<MAX_LIGHTS) {
            sdraw->GetCanvas()->GetLight(lightnumber)._specular.FixeValeur(r,g,b);
        sdraw->Paint();
      }
    ;}
    break;

  case 257:
#line 4094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yyvsp[(5) - (10)].adouble),(int)(yyvsp[(7) - (10)].adouble),(int)(yyvsp[(9) - (10)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 258:
#line 4100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
          sdraw->SetSize((int) (yyvsp[(5) - (8)].adouble), (int) (yyvsp[(7) - (8)].adouble));
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        ;}
    break;

  case 259:
#line 4113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                   (yyvsp[(3) - (8)].variable)->Name(),
                   (yyvsp[(5) - (8)].adouble), (yyvsp[(7) - (8)].adouble), NULL);
        ;}
    break;

  case 260:
#line 4120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
            (yyvsp[(3) - (10)].variable)->Name(),
            (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), mask);
          delete mask;
        ;}
    break;

  case 261:
#line 4131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
        **/
          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
            (yyvsp[(3) - (8)].variable)->Name(),
            (yyvsp[(5) - (8)].adouble), (yyvsp[(7) - (8)].adouble), NULL);
        ;}
    break;

  case 262:
#line 4153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
            (9) IMAGE: mask of the places to compute the tensor
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
        **/
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
            (yyvsp[(3) - (10)].variable)->Name(),
            (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), mask);
          delete mask;
        ;}
    break;

  case 263:
#line 4179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
            (9) IMAGE: mask of the places to compute the tensor
            (11) NUM: boolean for saving the gradient vector
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
            i_STHgrad
        **/
      InrImage* mask = (InrImage*) im_stack.GetLastImage();
      int save_grad = (int) (yyvsp[(11) - (12)].adouble);

          Func_StructureTensorHessian(((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                   (yyvsp[(3) - (12)].variable)->Name(),
                   (yyvsp[(5) - (12)].adouble), (yyvsp[(7) - (12)].adouble), mask, save_grad);
      delete mask;
        ;}
    break;

  case 264:
#line 4207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                 (yyvsp[(3) - (6)].variable)->Name(),
                 (yyvsp[(5) - (6)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 265:
#line 4217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                 (yyvsp[(3) - (8)].variable)->Name(),
                 (yyvsp[(5) - (8)].adouble),   // sigma
                 0,   // gamma
                 mask  // mask
                 );
      delete mask;
        ;}
    break;

  case 266:
#line 4230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                 (yyvsp[(3) - (8)].variable)->Name(),
                 (yyvsp[(5) - (8)].adouble),   // sigma
                 (yyvsp[(7) - (8)].adouble),   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 267:
#line 4240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
                 (yyvsp[(3) - (10)].variable)->Name(),
                 (yyvsp[(5) - (10)].adouble),   // sigma
                 (yyvsp[(7) - (10)].adouble),   // gamma
                 mask  // mask
                 );
      delete mask;
        ;}
    break;

  case 268:
#line 4253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3)  input image
          (5)  expr: Gaussian standard deviation
          (7)  expr: normalization parameter gamma
          (9)  choose for 1st eigenvalue/eigenvector
          (11) choose for 1st eigenvalue/eigenvector
          (13) choose for 1st eigenvalue/eigenvector
          (15) choose for gradient vector


        Description:
            Compute information for local first and second order derivatives
         **/

          Func_Derivatives(((InrImage::ptr*) (yyvsp[(3) - (16)].variable)->Pointer())->get(),
               (yyvsp[(3) - (16)].variable)->Name(),
               (yyvsp[(5) - (16)].adouble),   // sigma
               (yyvsp[(7) - (16)].adouble),   // gamma
               NULL,
               (int)(yyvsp[(9) - (16)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yyvsp[(11) - (16)].adouble),  // 2nd eigenvalue | eigenvector?
               (int)(yyvsp[(13) - (16)].adouble),  // 3rd eigenvalue | eigenvector?
               (int)(yyvsp[(15) - (16)].adouble)  // Gradient vector?
               );
        ;}
    break;

  case 269:
#line 4282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_Derivatives(((InrImage::ptr*) (yyvsp[(3) - (18)].variable)->Pointer())->get(),
               (yyvsp[(3) - (18)].variable)->Name(),
               (yyvsp[(5) - (18)].adouble),   // sigma
               (yyvsp[(7) - (18)].adouble),   // gamma
               mask,  // mask
               (int)(yyvsp[(9) - (18)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yyvsp[(11) - (18)].adouble),   // 2nd eigenvalue | eigenvector?
               (int)(yyvsp[(13) - (18)].adouble),   // 3rd eigenvalue | eigenvector?
               (int)(yyvsp[(15) - (18)].adouble)   // Gradient vector?
               );
      delete mask;
        ;}
    break;

  case 270:
#line 4300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_HessianVap(((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
              (yyvsp[(3) - (12)].variable)->Name(),
              (yyvsp[(5) - (12)].adouble),   // sigma
              (yyvsp[(7) - (12)].adouble),   // gamma
              mask,
              (int) (yyvsp[(11) - (12)].adouble) // eigenvalue number
              );
      delete mask;
        ;}
    break;

  case 271:
#line 4314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
              (yyvsp[(3) - (6)].variable)->Name(),
              (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 272:
#line 4326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_Eigen3D(
               (char*) (yyvsp[(3) - (18)].astring),
               ((InrImage::ptr*) (yyvsp[(5) - (18)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(7) - (18)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(9) - (18)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(11) - (18)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(13) - (18)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(15) - (18)].variable)->Pointer())->get(),
               mask  // mask
               );
      delete mask;
        ;}
    break;

  case 273:
#line 4347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Func_Eigen3D(
               (char*) (yyvsp[(3) - (16)].astring),
               ((InrImage::ptr*) (yyvsp[(5) - (16)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(7) - (16)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(9) - (16)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(11) - (16)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(13) - (16)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(15) - (16)].variable)->Pointer())->get(),
               NULL
               );
        ;}
    break;

  case 274:
#line 4366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_Eigen2D(
               (char*) (yyvsp[(3) - (12)].astring),
               ((InrImage::ptr*) (yyvsp[(5) - (12)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(7) - (12)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(9) - (12)].variable) ->Pointer())->get(),
               mask  // mask
               );
      delete mask;
        ;}
    break;

  case 275:
#line 4383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Eigen2D(
               (char*) (yyvsp[(3) - (10)].astring),
               ((InrImage::ptr*) (yyvsp[(5) - (10)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(7) - (10)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yyvsp[(9) - (10)].variable) ->Pointer())->get(),
               NULL
               );
        ;}
    break;

  case 276:
#line 4394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get())->SetVoxelSize((yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 277:
#line 4399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->SetVoxelSize((yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 278:
#line 4404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    ;}
    break;

  case 279:
#line 4413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->SetTranslation((yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 280:
#line 4418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    ;}
    break;

  case 281:
#line 4427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      ((amimage*) (*(*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())) )->SetEndianness((AMIENDIANNESS)(int)(yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 282:
#line 4441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
    ;}
    break;

  case 283:
#line 4448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer())->get());
    ;}
    break;

  case 284:
#line 4455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
    /** ??? **/
      (yyval.aint)=1;
    ;}
    break;

  case 285:
#line 4461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatches the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<500) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    ;}
    break;

  case 286:
#line 4478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatch the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<500) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    ;}
    break;

  case 287:
#line 4494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) IMAGE: 1D image to plot, where the voxel size in X is used
            (5) String: plot title
            (7) NUM: delay
        Description:
            Plots a 1D image using gnuplot.
        **/
      InrImage*   image = (InrImage*) im_stack.GetLastImage();
      float* tabx;
      float* taby;
      GnuPlot   gnuplot;
      int x,num_courbe;
      char name[200];

          tabx = new float[image->_tx];
          taby = new float[image->_tx];

      Pour(x,0,image->_tx-1)
        tabx[x] = image->SpacePosX(x);
        taby[x] = (*image)(x,0,0);
      FinPour

          num_courbe = gnuplot.AddCourbe( image->_tx, tabx, taby, (yyvsp[(5) - (8)].astring));
      sprintf(name,"%s.gnuplot",(yyvsp[(5) - (8)].astring));
      gnuplot.XPlot(name,(int)(yyvsp[(7) - (8)].adouble));

      delete [] tabx;
      delete [] taby;
      delete image;
      delete [] (yyvsp[(5) - (8)].astring);
         ;}
    break;

  case 288:
#line 4528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
cerr << "Feature not available, needs to be updated ! " << endl;
/*
      InrImage::ptr   image = *(InrImage::ptr*) $3->Pointer();
      Histogramme* histo;

      histo = new Histogramme(GB_main_window,"histo",
                  image.get(),
                  CREATE_TOPLEVEL_SHELL);
*/
        ;}
    break;

  case 289:
#line 4545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3)  IMAGE1: image to change
            (5)  IMAGE2: input image
            (7)  expression: step x
            (9)  expression: position x
            (11) expression: step y
            (13) expression: position y
            (15) expression: step z
            (17) expression: position z

        Description:
            Pads the output image (IMAGE1) using the input image (IMAGE2),
            starting from position (posx,posy,posz) in IMAGE1,
            tries to fill all the values of IMAGE2 with a voxel lattice of size
            (step x, step y, step z).
            Works for scalar or vectorial images, both images must be of the same
            type (scalar or vectorial).
        **/

            int step_x = (int) (yyvsp[(7) - (18)].adouble);
            int step_y = (int) (yyvsp[(11) - (18)].adouble);
            int step_z = (int) (yyvsp[(15) - (18)].adouble);
        int pos_x  = (int) (yyvsp[(9) - (18)].adouble);
        int pos_y  = (int) (yyvsp[(13) - (18)].adouble);
        int pos_z  = (int) (yyvsp[(17) - (18)].adouble);

      // pad the first image with the second one
      //
      Func_Pad(
        ((InrImage::ptr*) (yyvsp[(3) - (18)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yyvsp[(5) - (18)].variable)->Pointer())->get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        ;}
    break;

  case 290:
#line 4585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yyvsp[(3) - (4)].astring));
        ;}
    break;

  case 291:
#line 4590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IP_time.Debut();
        ;}
    break;

  case 292:
#line 4595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IP_time.Fin();
      cout << "time spent = " << IP_time << endl;
        ;}
    break;

  case 293:
#line 4601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * pwptr;
          //    pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) $5);
          pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) (yyvsp[(5) - (6)].astring));
          GB_main_wxFrame->AddParamPage((wxWindow*)pwptr,GetwxStr((char*) (yyvsp[(5) - (6)].astring)));
          //GB_main_wxFrame->GetAuiManager().Update();
          if (pwptr != NULL)
        Vars.AddVar(type_paramwin,(yyvsp[(1) - (6)].ident),pwptr);
          else
        err_print("assignment of NULL parameter window\n");

          gr_print("command : identifier ASSIGN_OP T_ParamWin\n ");
              delete [] (yyvsp[(5) - (6)].astring);
        ;}
    break;

  case 294:
#line 4617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
    pw->BeginBox( (char*) (yyvsp[(5) - (6)].astring));
    delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 295:
#line 4624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->BeginBook();
    ;}
    break;

  case 296:
#line 4630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->EndBook();
    ;}
    break;

  case 297:
#line 4636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      pw->AddPage( (char*) (yyvsp[(5) - (6)].astring));
      delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 298:
#line 4643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      pw->BeginPanel( (char*) (yyvsp[(5) - (6)].astring));
      delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 299:
#line 4650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->EndPanel();
    ;}
    break;

  case 300:
#line 4656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->EndBox( );
    ;}
    break;

  case 301:
#line 4662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->BeginHorizontal( );
    ;}
    break;

  case 302:
#line 4668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
        pw->EndHorizontal( );
        ;}
    break;

  case 303:
#line 4674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          pw->CreeDialogue( );
        ;}
    break;

  case 304:
#line 4680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();

/* TODO
          GB_main_wxFrame->GetAuiManager().GetPane((wxWindow*) pw.get()).Show();
          //GB_main_wxFrame->GetAuiManager().GetPane((wxWindow*) pw.get()).Float();
          GB_main_wxFrame->GetAuiManager().Update();
*/
          //pw->AfficheDialogue();
        ;}
    break;

  case 305:
#line 4692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          pw->ReAfficheParametres();
        ;}
    break;

  case 306:
#line 4698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
          (5) parameter id
          (7) bool: 1/0 for show/hide
        Description:
          Show/hide the slider if there is one.
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
          int n = (int) (yyvsp[(5) - (8)].adouble);
          bool show = (bool) (yyvsp[(7) - (8)].adouble);

          pw->ParamShowSlider(n,show );
        ;}
    break;

  case 307:
#line 4715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yyvsp[(5) - (6)].variable)->Pointer() );
        ;}
    break;

  case 308:
#line 4722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      int n = pw->NbParameters();
      int i = (int) (yyvsp[(5) - (6)].adouble);
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d ) \t bad parameter number \n",i);
        ;}
    break;

  case 309:
#line 4733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yyvsp[(5) - (6)].astring));
          delete [] (yyvsp[(5) - (6)].astring);
        ;}
    break;

  case 310:
#line 4740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->Print();
        ;}
    break;

  case 311:
#line 4745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->get(),(yyvsp[(4) - (4)].astring));
          delete [] (yyvsp[(4) - (4)].astring);
        ;}
    break;

  case 312:
#line 4751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        ;}
    break;

  case 313:
#line 4756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 314:
#line 4761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        ;}
    break;

  case 315:
#line 4766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 316:
#line 4771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 317:
#line 4782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im1 = *(InrImage::ptr*) (yyvsp[(3) - (30)].variable)->Pointer();
    InrImage::ptr im2 = *(InrImage::ptr*) (yyvsp[(5) - (30)].variable)->Pointer();
    InrImage::ptr u = *(InrImage::ptr*) (yyvsp[(7) - (30)].variable)->Pointer();
    InrImage::ptr v = *(InrImage::ptr*) (yyvsp[(9) - (30)].variable)->Pointer();
    InrImage::ptr corr = *(InrImage::ptr*) (yyvsp[(11) - (30)].variable)->Pointer();
    InrImage::ptr conf_x = *(InrImage::ptr*) (yyvsp[(13) - (30)].variable)->Pointer();
    InrImage::ptr conf_y = *(InrImage::ptr*) (yyvsp[(15) - (30)].variable)->Pointer();
    int initx= (int) (yyvsp[(17) - (30)].adouble);
    int inity= (int) (yyvsp[(19) - (30)].adouble);
    int displx= (int) (yyvsp[(21) - (30)].adouble);
    int disply= (int) (yyvsp[(23) - (30)].adouble);
    int sizex= (int) (yyvsp[(25) - (30)].adouble);
    int sizey= (int) (yyvsp[(27) - (30)].adouble);
    int deform = (int) (yyvsp[(29) - (30)].adouble);

    amiOpticFlowCorrelation2D(
      im1.get(),
      im2.get(),
      u.get(),
      v.get(),
      corr.get(),
      conf_x.get(),
      conf_y.get(),
      initx,inity,
      displx,disply,sizex,sizey,deform);
        ;}
    break;

  case 318:
#line 4814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im1 = *(InrImage::ptr*) (yyvsp[(3) - (24)].variable)->Pointer();
        InrImage::ptr im2 = *(InrImage::ptr*) (yyvsp[(5) - (24)].variable)->Pointer();
        float     sigma = (yyvsp[(7) - (24)].adouble);
        float     T     = (yyvsp[(9) - (24)].adouble);
        float     alpha = (yyvsp[(11) - (24)].adouble);
        long      dtype = (long) (yyvsp[(13) - (24)].adouble);      /* type of smoothness term */
        float     quantile = (yyvsp[(15) - (24)].adouble);          /* isotropy fraction */
        float     ht       = (yyvsp[(17) - (24)].adouble);          /* time step size */
        InrImage::ptr u =  *(InrImage::ptr*) (yyvsp[(19) - (24)].variable)->Pointer();  /* x component of optic flow, changed */
        InrImage::ptr v =  *(InrImage::ptr*) (yyvsp[(21) - (24)].variable)->Pointer();  /* y component of optic flow, changed */
        int       Niter    = (int)  (yyvsp[(23) - (24)].adouble);   /* Number of Iterations for Gauss-Seidel */

        amiOpticFlowVariational2D(
          im1.get(),
          im2.get(),
          sigma,T,alpha,dtype,quantile,ht,
          u.get(),
          v.get(),
          Niter);

        ;}
    break;

  case 319:
#line 4838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yyvsp[(1) - (4)].variable);
          ParamList::ptr param((yyvsp[(3) - (4)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        ;}
    break;

  case 320:
#line 4845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) size of the 3D arrow basis (def: 0.05)
          (5) size of the 3D arrow head (def: 0.1)
          (7) position of the 3D arrow (def: 0.85)

        Description:
          Parameters for 3D arrows created by CreateVectors() when the vector style is 1.
          Each arrow is composed of 2 tetrahedra:
            - the basis size in proportion to the arrow size is given by the 1st parameter,
            - the head size by the 2nd parameter,
            - the lower position of the head along the arrow by the 3rd parameter.
        **/
          AMIFluid::Func_SetArrowParameters((float)(yyvsp[(3) - (8)].adouble),(float)(yyvsp[(5) - (8)].adouble),(float)(yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 321:
#line 4866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 322:
#line 4871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yyvsp[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 323:
#line 4878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yyvsp[(1) - (3)].paramlist);
          float_ptr* x= new float_ptr(new float((yyvsp[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 324:
#line 4885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yyvsp[(1) - (1)].astring)));
          delete [] (yyvsp[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         ;}
    break;

  case 325:
#line 4893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yyvsp[(1) - (3)].paramlist);
          string_ptr* x = new string_ptr(new string((yyvsp[(3) - (3)].astring)));
          delete [] (yyvsp[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 326:
#line 4901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yyvsp[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 327:
#line 4910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yyvsp[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 328:
#line 4917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yyvsp[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 329:
#line 4924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yyvsp[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 330:
#line 4931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 331:
#line 4938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (3)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 332:
#line 4945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yyvsp[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 333:
#line 4952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yyvsp[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 334:
#line 4959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yyvsp[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 335:
#line 4966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yyvsp[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 336:
#line 4973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yyvsp[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 337:
#line 4980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (3)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yyvsp[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 338:
#line 4989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 339:
#line 4995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 340:
#line 5001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 341:
#line 5007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 342:
#line 5013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 343:
#line 5019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 344:
#line 5025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 345:
#line 5031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 346:
#line 5037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 347:
#line 5043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 348:
#line 5049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 349:
#line 5056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yyvsp[(1) - (1)].astring);
        ;}
    break;

  case 350:
#line 5061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        ;}
    break;

  case 351:
#line 5073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->postfixE");
       fflush(stdout);
        ;}
    break;

  case 352:
#line 5079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      //printf("expr_string=%s*\n",$3);
      //printf("expr=%f*\n",$5);
      res = new char[strlen((yyvsp[(3) - (6)].astring))+20];
          sprintf(res,(yyvsp[(3) - (6)].astring),(yyvsp[(5) - (6)].adouble));
      //          res[strlen($3)]=0;
      delete [] (yyvsp[(3) - (6)].astring);
      //printf("res=%s*\n",res);
      (yyval.astring)=res;
        ;}
    break;

  case 353:
#line 5093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;
      long min,hour,sec;

      IP_time.Fin();
      IP_time.AddCumul();
      IP_time.GetCumul(hour,min,sec);
      res = new char[10];
          sprintf(res,"%03d:%02d:%02d",(int)hour,(int)min,(int)sec);
      (yyval.astring)=res;
        ;}
    break;

  case 354:
#line 5105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->Nom();
    ;}
    break;

  case 356:
#line 5114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char* res;
          res = new char[strlen((yyvsp[(1) - (3)].astring))+strlen((yyvsp[(3) - (3)].astring))+1];
          strcpy(res,(yyvsp[(1) - (3)].astring));
          strcat(res,(yyvsp[(3) - (3)].astring));
          delete [] (yyvsp[(1) - (3)].astring);
          delete [] (yyvsp[(3) - (3)].astring);
          (yyval.astring)=res;
        ;}
    break;

  case 357:
#line 5124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yyvsp[(1) - (3)].astring),(yyvsp[(3) - (3)].astring));
          (yyval.astring)=(yyvsp[(1) - (3)].astring);
        ;}
    break;

  case 358:
#line 5132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->expr_string\n");
        ;}
    break;

  case 359:
#line 5140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yyvsp[(2) - (3)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yyvsp[(2) - (3)].ablock)->GetBody()
                << endl;
          ;}
    break;

  case 362:
#line 5153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        gr_print("\n NUMBER");
    fflush(stdout);
    ;}
    break;

  case 363:
#line 5158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    ;}
    break;

  case 364:
#line 5166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=yyiplineno;
    ;}
    break;

  case 365:
#line 5174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
      gr_print("\n CONST_PI");
    ;}
    break;

  case 366:
#line 5184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get();
      gr_print("\n VAR_FLOAT");
    ;}
    break;

  case 367:
#line 5189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get();
      //sprintf(tmp_string,"\n VAR_INT %d ", (int)$1);
    gr_print(tmp_string);
    ;}
    break;

  case 368:
#line 5195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get();
      //sprintf(tmp_string,"\n VAR_INT %d ", (int)$1);
      gr_print(tmp_string);
    ;}
    break;

  case 369:
#line 5201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yyvsp[(2) - (3)].adouble);
      gr_print("\n(expr)");
      fflush(stdout);
    ;}
    break;

  case 370:
#line 5210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->postfixE");
       fflush(stdout);
        ;}
    break;

  case 371:
#line 5215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) input_image
        (3) x

        description:
        returns the image value at pixel (x,y=0,z=0).

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())((int) (yyvsp[(3) - (4)].adouble),0);
    ;}
    break;

  case 372:
#line 5230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) input_image
        (3) x
        (5) y

        description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())((int) (yyvsp[(3) - (6)].adouble),(int) ( (yyvsp[(5) - (6)].adouble)));
    ;}
    break;

  case 373:
#line 5246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (8)].variable)->Pointer())((int) (yyvsp[(3) - (8)].adouble),(int) ( (yyvsp[(5) - (8)].adouble)), (int) ((yyvsp[(7) - (8)].adouble)));
    ;}
    break;

  case 374:
#line 5250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 3D voxel position.
        same as image(expr,expr,expr;expr)
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
        Si im->CoordOK((int) (yyvsp[(3) - (10)].adouble), (int) (yyvsp[(5) - (10)].adouble), (int) (yyvsp[(7) - (10)].adouble))
           Et ((int) (yyvsp[(9) - (10)].adouble) >=0) Et ((int)(yyvsp[(9) - (10)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())((int) (yyvsp[(3) - (10)].adouble),(int) (yyvsp[(5) - (10)].adouble), (int) (yyvsp[(7) - (10)].adouble),
                      (int) (yyvsp[(9) - (10)].adouble) );
      Sinon
        err_print("var_image(expr,expr,expr,expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 375:
#line 5267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 3D voxel position.
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
        Si im->CoordOK((int) (yyvsp[(3) - (10)].adouble), (int) (yyvsp[(5) - (10)].adouble), (int) (yyvsp[(7) - (10)].adouble))
           Et ((int) (yyvsp[(9) - (10)].adouble) >=0) Et ((int)(yyvsp[(9) - (10)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())((int) (yyvsp[(3) - (10)].adouble),(int) (yyvsp[(5) - (10)].adouble), (int) (yyvsp[(7) - (10)].adouble),
                      (int) (yyvsp[(9) - (10)].adouble) );
      Sinon
        err_print("var_image(expr,expr,expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 376:
#line 5283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 2D  position. ( z component set to 0)
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
      Si (im->CoordOK((int) (yyvsp[(3) - (8)].adouble),   (int (yyvsp[(5) - (8)].adouble)),   0  )
        Et ((int) (yyvsp[(7) - (8)].adouble) >=0) Et ((int)(yyvsp[(7) - (8)].adouble) <im->GetVDim())) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (8)].variable)->Pointer())((int) (yyvsp[(3) - (8)].adouble),(int) (yyvsp[(5) - (8)].adouble),0, (int) (yyvsp[(7) - (8)].adouble) );
      Sinon
        err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 377:
#line 5297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 1D  position. (y and z components set to 0)
        **/
      Si (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->CoordOK((int) (yyvsp[(3) - (6)].adouble),   0,   0  )
        Et ((int) (yyvsp[(5) - (6)].adouble) >=0) Et ((int)(yyvsp[(5) - (6)].adouble) <3) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())((int) (yyvsp[(3) - (6)].adouble),0,0, (int) (yyvsp[(5) - (6)].adouble) );
      Sinon
        err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 378:
#line 5310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
        Init the image buffer to the first voxel or pixel:
        at coordinates (0,0,0).

        See Also:
                inc val

        Example(s):

        i.init
        for x=0 to i.tx-1 {
          print "value at x = "; print x; print ": ";
          print i.val; print "\n";
          i.inc
        }
        **/
        (*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->InitBuffer();
        ;}
    break;

  case 379:
#line 5331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strcmp((yyvsp[(3) - (3)].ident),"tx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_tx;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"ty")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_ty;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"tz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_tz;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"trx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_translation_x;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"vdim")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetVDim();
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"try")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_translation_y;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"trz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_translation_z;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"vx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_size_x;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"vy")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_size_y;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"vz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->_size_z;
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"inc")==0) {
        (*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->IncBuffer();
      }
      else
      if (strcmp((yyvsp[(3) - (3)].ident),"val")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->ValeurBuffer();
      }
      else
        {
          sprintf(tmp_string," %s.%s identifier not recognized \n",
              (yyvsp[(1) - (3)].variable)->Name(), (yyvsp[(3) - (3)].ident));
          strcat(tmp_string," known identifiers {tx, ty, tz, vdim, trx, try, trz, vx, vy, vz, init, inc, val, info} \n");
          err_print(tmp_string);
        }

      gr_print("\n var_image '.' identifier->postfixE");
        ;}
    break;

  case 380:
#line 5390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im;
        im=*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
        sprintf(tmp_string," format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
  translation =(%f,%f,%f) \n",
            im->FormatName().c_str(),
            im->_tx,
            im->_ty,
            im->_tz,
            im->GetVDim(),
            im->_size_x,
            im->_size_y,
            im->_size_z,
            im->_translation_x,
            im->_translation_y,
            im->_translation_z);
        res_print(tmp_string);
    ;}
    break;

  case 381:
#line 5409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();

      sprintf(tmp_string," %d points  %d polygons  \n",
          s->GetNumberOfPoints(),
          s->GetNumberOfPolys ()
          );
      res_print(tmp_string);
          sprintf(tmp_string," limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n",
          s->_xmin,s->_xmax,
          s->_ymin,s->_ymax,
          s->_zmin,s->_zmax);

      res_print(tmp_string);
    ;}
    break;

  case 382:
#line 5426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    ;}
    break;

  case 383:
#line 5433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    ;}
    break;

  case 384:
#line 5441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 385:
#line 5446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
        ;}
    break;

  case 386:
#line 5451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float   resolution = (yyvsp[(5) - (10)].adouble);
          int     cx = (int) (yyvsp[(7) - (10)].adouble);
          int     cy = (int) (yyvsp[(9) - (10)].adouble);
          float    surf_inf[1];
          float    surf_sup[1];
          float    surf_interp[1];
          Point3D point;
      Vect3D<float> v1,v2;
      CalculAireSection* compute_area;

          compute_area = new CalculAireSection( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
                        resolution);
      compute_area->InitImagesSurf((InrImage*) NULL, (InrImage*) NULL,
                       (InrImage*) NULL, (InrImage*) NULL);
      surf_inf[0]  = surf_sup[0] = surf_interp[0] = 0.0;
      v1.Init( 1.0, 0.0, 0.0);
      v2.Init( 0.0, 1.0, 0.0);
      point.Init( cx,cy,0);

      (yyval.adouble)=compute_area->Aire( 0, point, v1, v2,
                  surf_inf, surf_sup, surf_interp);

      delete compute_area;

        ;}
    break;

  case 387:
#line 5479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get() );
        ;}
    break;

  case 388:
#line 5485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yyvsp[(3) - (10)].adouble);
      val[1] = (yyvsp[(5) - (10)].adouble);
      val[2] = (yyvsp[(7) - (10)].adouble);
      val[3] = (yyvsp[(9) - (10)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        ;}
    break;

  case 389:
#line 5496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the of pixels (or voxels) with intensity higher than 0.5

             parameters:
               (3) image expression

            Keywords:

            Others:
                max, mean, min, median

        **/
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      (yyval.adouble)=Func_count( im );
      delete im;
        ;}
    break;

  case 390:
#line 5516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the average value of an image

             parameters:
               (3) image expression

            Keywords:

            Others:
                min, max, median

        **/
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      (yyval.adouble)=Func_mean( im);
      delete im;
        ;}
    break;

  case 391:
#line 5536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                min, mean, median

        **/
      (yyval.adouble)=Func_max( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get(),NULL);
        ;}
    break;

  case 392:
#line 5554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the position of the maximal value of an image

             parameters:
               (3) image expression

            Keywords:

            Others:
                min, mean, median, max

        **/
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      (yyval.adouble)=Func_argmax( im);
      delete im;
        ;}
    break;

  case 393:
#line 5574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the minimal value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                max, mean, median

        **/
      (yyval.adouble)=Func_min( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get(),NULL);
        ;}
    break;

  case 394:
#line 5592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the median value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                min, max, mean, count

        **/
      (yyval.adouble)=Func_med( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get(),0.5,NULL);
        ;}
    break;

  case 395:
#line 5610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_max( ((InrImage::ptr*) (yyvsp[(6) - (7)].variable)->Pointer())->get(),mask);
          delete mask;
        ;}
    break;

  case 396:
#line 5633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the minimal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_min( ((InrImage::ptr*) (yyvsp[(6) - (7)].variable)->Pointer())->get(),mask);
          delete mask;
        ;}
    break;

  case 397:
#line 5656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the median value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yyvsp[(6) - (7)].variable)->Pointer())->get(),0.5,mask);
          delete mask;
        ;}
    break;

  case 398:
#line 5679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yyvsp[(6) - (9)].variable)->Pointer())->get(),(float) (yyvsp[(8) - (9)].adouble),mask);
          delete mask;
        ;}
    break;

  case 399:
#line 5686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the average value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression: defines the Region of Interest
               (5) image expression: image from which to compute the mean intensity value.

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* input = (InrImage*) im_stack.GetLastImage();
          InrImage* mask  = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_mean( input,mask);
          delete mask;
          delete input;
        ;}
    break;

  case 400:
#line 5711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image in a region of
             interest

             parameters:
               (3) image variable
               (5) image expression: the pixels (or voxels) higher than 0.5
               define the Region of Interest

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) im_stack.GetLastImage();

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), mask);
          delete mask;
        ;}
    break;

  case 401:
#line 5734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yyvsp[(3) - (4)].astring));
        ;}
    break;

  case 402:
#line 5741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        ;}
    break;

  case 403:
#line 5751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        ;}
    break;

  case 404:
#line 5761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        ;}
    break;

  case 405:
#line 5771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        ;}
    break;

  case 406:
#line 5781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        ;}
    break;

  case 407:
#line 5791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        ;}
    break;

  case 408:
#line 5801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;
          string comment;
          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
          param = draw->GetParam();
          (yyval.adouble)=param->_pos._x;
          comment = str(format(" //  xpos=%3d") % param->_pos._x);
          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(comment.c_str()));
        ;}
    break;

  case 409:
#line 5815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (yy_num_buf==1)
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    ;}
    break;

  case 410:
#line 5832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (yy_num_buf==1)
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    ;}
    break;

  case 411:
#line 5848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    ;}
    break;

  case 412:
#line 5853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    ;}
    break;

  case 413:
#line 5858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    ;}
    break;

  case 414:
#line 5862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yyvsp[(1) - (6)].variable)->Pointer();
          int i = (int)(yyvsp[(3) - (6)].adouble);
          int j = (int)(yyvsp[(5) - (6)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    ;}
    break;

  case 415:
#line 5869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yyvsp[(1) - (8)].variable)->Pointer();
          int i = (int)(yyvsp[(3) - (8)].adouble);
          int j = (int)(yyvsp[(5) - (8)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yyvsp[(8) - (8)].adouble));
    ;}
    break;

  case 416:
#line 5877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
          description:
            Adds an interface for a floating point variable to the window of parameters.

          parameters:
            (1) variable of type window of parameters
            (5) float variable for which we want to create an interface
            (7) minimal value accepted
            (9) maximal value accepted

        Keywords:

        Others:
            ParamWin, AddInt, CreateWin, Display

        Example:
          a=1
          w1 = ParamWin("test")
          w1.AddFloat(a,1,100)
          w1.CreateWin
          w1.Display
      **/

      float* var = ((float_ptr*)(yyvsp[(5) - (10)].variable)->Pointer())->get();
      float min_value = (float)(yyvsp[(7) - (10)].adouble);
      float max_value = (float)(yyvsp[(9) - (10)].adouble);

    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
        int var_id = pw->AddFloat( var, (char*)(yyvsp[(5) - (10)].variable)->Name());
        pw->FloatConstraints( var_id, min_value, max_value, *var );
        (yyval.adouble) = var_id;
    ;}
    break;

  case 417:
#line 5912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Add interface to set an integer value between a minimal and a maximal value.
      **/
      int* var = ((int_ptr*)(yyvsp[(5) - (10)].variable)->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
      int var_id = pw->AddInteger( var, (char*)(yyvsp[(5) - (10)].variable)->Name());
          pw->IntegerConstraints( var_id, (int)(yyvsp[(7) - (10)].adouble), (int)(yyvsp[(9) - (10)].adouble), *var );
      (yyval.adouble) = var_id;
    ;}
    break;

  case 418:
#line 5925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
    pw->AddButton( &bid, (yyvsp[(5) - (8)].astring),
                (void*) CB_Button,
                (void*) (yyvsp[(7) - (8)].variable)->Pointer());
    (yyval.adouble) = bid;
    ;}
    break;

  case 419:
#line 5935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type UCHAR

    Description:
      Adds a boolean variable to the parameter window.
    **/
      unsigned char*   var = ((uchar_ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      int var_id;
      pw->AddBoolean( &var_id, var, (char*)(yyvsp[(5) - (6)].variable)->Name());
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    ;}
    break;

  case 420:
#line 5952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT
      (7) number of different values of the enumeration

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      int*   var = ((int_ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
      int size = (int) (yyvsp[(7) - (8)].adouble);
      int var_id;
      pw->AddEnumeration( &var_id, size, var, (char*)(yyvsp[(5) - (8)].variable)->Name());
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    ;}
    break;

  case 421:
#line 5971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      int*   var = ((int_ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      int var_id;
      pw->AddEnumeration( &var_id, var, (char*)(yyvsp[(5) - (6)].variable)->Name());
      (yyval.adouble) = var_id;
    ;}
    break;

  case 422:
#line 5987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) expression:        identificator of the enumeration parameter
      (7) string expression: text associated to this choice

    Description:
      Adds a choice for an enumeration created in the parameter window
    **/
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
      int id = (int) (yyvsp[(5) - (8)].adouble);
      int var_id;
      pw->AddEnumChoice( id, &var_id, (char*) (yyvsp[(7) - (8)].astring));
      (yyval.adouble) = var_id;
      delete [] (yyvsp[(7) - (8)].astring);
    ;}
    break;

  case 423:
#line 6005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label

    Description:
      Adds a string in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
        int var_id;
        pw->AjouteChaine( &var_id,
          ((string_ptr*)(yyvsp[(5) - (8)].variable)->Pointer())->get(),
          (char*) (yyvsp[(7) - (8)].astring));
        pw->ContraintesChaine(var_id,(char*) ((string_ptr*)(yyvsp[(5) - (8)].variable)->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
    ;}
    break;

  case 424:
#line 6025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label
      (9) default path
      (11) default mask

    Description:
      Adds a filename in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (12)].variable)->Pointer();
        int var_id;
        // passer AjouteNomFichier a std::string !!!!
        pw->AjouteNomFichier( &var_id, ((string_ptr*)(yyvsp[(5) - (12)].variable)->Pointer())->get(), (char*) (yyvsp[(7) - (12)].astring));
        pw->ContraintesNomFichier(var_id,(char*) (yyvsp[(9) - (12)].astring),(char*)"",(char*) (yyvsp[(11) - (12)].astring));
        (yyval.adouble)=var_id;
    ;}
    break;

  case 425:
#line 6046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window

    Description:
      update the display of all the parameters
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
        pw->MAJ();
    ;}
    break;

  case 426:
#line 6059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) parameter id

    Description:
      update the display of one parameter
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
        pw->UpdateParameter((int)(yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 427:
#line 6072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    ;}
    break;

  case 428:
#line 6080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    ;}
    break;

  case 429:
#line 6088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yyvsp[(1) - (1)].aint);
    ;}
    break;

  case 430:
#line 6092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yyvsp[(5) - (6)].astring),&res);
        (yyval.adouble) =  res;
    ;}
    break;

  case 431:
#line 6100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    ;}
    break;

  case 432:
#line 6110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->unaryE");
       fflush(stdout);
        ;}
    break;

  case 433:
#line 6115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("\n unary_operator castE->unaryE");
       fflush(stdout);
        ;}
    break;

  case 434:
#line 6119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 435:
#line 6120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 436:
#line 6121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 437:
#line 6122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 438:
#line 6123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 439:
#line 6124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 440:
#line 6125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 441:
#line 6126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 442:
#line 6128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yyvsp[(2) - (2)].adouble),(yyval.adouble))
        ;}
    break;

  case 443:
#line 6135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 444:
#line 6136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 445:
#line 6137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 446:
#line 6138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 447:
#line 6139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 448:
#line 6140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 449:
#line 6141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 452:
#line 6152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->castE");
       fflush(stdout);
        ;}
    break;

  case 453:
#line 6158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      switch((WORDTYPE) (yyvsp[(2) - (4)].aint)) {
      case WT_UNSIGNED_CHAR:  (yyval.adouble)=(unsigned char) (yyvsp[(4) - (4)].adouble); break;
      case WT_SIGNED_SHORT:   (yyval.adouble)=(short) (yyvsp[(4) - (4)].adouble);  break;
      case WT_UNSIGNED_SHORT: (yyval.adouble)=(unsigned short) (yyvsp[(4) - (4)].adouble);  break;
      case WT_SIGNED_INT:     (yyval.adouble)=(int) (yyvsp[(4) - (4)].adouble);  break;
      case WT_UNSIGNED_INT:   (yyval.adouble)=(unsigned int) (yyvsp[(4) - (4)].adouble);  break;
      case WT_FLOAT:          (yyval.adouble)=(float) (yyvsp[(4) - (4)].adouble);  break;
      default:
        fprintf(stderr,"Conversion not available\n");
      }
        ;}
    break;

  case 455:
#line 6174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yyvsp[(1) - (3)].adouble)*(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 456:
#line 6175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yyvsp[(1) - (3)].adouble)/(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 458:
#line 6180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yyvsp[(1) - (3)].adouble)+(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 459:
#line 6181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yyvsp[(1) - (3)].adouble)-(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 460:
#line 6186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("->shiftE");
    ;}
    break;

  case 462:
#line 6194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)<(yyvsp[(3) - (3)].adouble));  ;}
    break;

  case 463:
#line 6195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)>(yyvsp[(3) - (3)].adouble));  ;}
    break;

  case 464:
#line 6196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)<=(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 465:
#line 6197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)>=(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 467:
#line 6202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yyvsp[(1) - (3)].adouble)==(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 468:
#line 6203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yyvsp[(1) - (3)].adouble)!=(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 469:
#line 6204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yyvsp[(1) - (3)].astring),(yyvsp[(3) - (3)].astring))==0); ;}
    break;

  case 470:
#line 6205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yyvsp[(1) - (3)].astring),(yyvsp[(3) - (3)].astring))!=0); ;}
    break;

  case 471:
#line 6210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("->andE ");
    ;}
    break;

  case 472:
#line 6214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yyvsp[(1) - (3)].adouble)) & ((int)(yyvsp[(3) - (3)].adouble));
    ;}
    break;

  case 473:
#line 6222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("->xorE ");
    ;}
    break;

  case 474:
#line 6226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("\n xorE '^' andE->xorE");
    ;}
    break;

  case 475:
#line 6233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yyvsp[(1) - (1)].adouble);
        ;}
    break;

  case 476:
#line 6237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yyvsp[(1) - (3)].adouble)) | ((int)(yyvsp[(3) - (3)].adouble));
        ;}
    break;

  case 477:
#line 6244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yyvsp[(1) - (1)].adouble);
        ;}
    break;

  case 478:
#line 6248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yyvsp[(1) - (3)].adouble)&&(yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 479:
#line 6255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yyvsp[(1) - (1)].adouble);
    ;}
    break;

  case 480:
#line 6259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yyvsp[(1) - (3)].adouble)||(yyvsp[(3) - (3)].adouble);
    ;}
    break;

  case 482:
#line 6267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yyvsp[(1) - (5)].adouble)?(yyvsp[(3) - (5)].adouble):(yyvsp[(5) - (5)].adouble));
        ;}
    break;

  case 484:
#line 6278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->expr\n");
        ;}
    break;

  case 485:
#line 6287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 486:
#line 6292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 487:
#line 6296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 488:
#line 6300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 489:
#line 6304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 490:
#line 6308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 491:
#line 6312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 492:
#line 6316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 493:
#line 6320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 494:
#line 6324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 495:
#line 6328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetFormat();
      ;}
    break;

  case 496:
#line 6336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yyvsp[(1) - (1)].variable);
        ;}
    break;

  case 497:
#line 6341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yyvsp[(3) - (4)].adouble);

          array = *(VarArray::ptr*) ((yyvsp[(1) - (4)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // create a small image to avoid problems
            InrImage* im = new InrImage(1,1,1,WT_UNSIGNED_CHAR);
            string name = str(format("%s[%d]") % (yyvsp[(1) - (4)].variable)->Name() % i);
            array->InitElement(i,im,name.c_str());
          }
          (yyval.variable)=&(array->GetVar(i));
        ;}
    break;

  case 498:
#line 6358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     im_stack.AddImage((yyvsp[(2) - (2)].astring));
         gr_print("image : T_Image  ASTRING  \n ");
     delete [] (yyvsp[(2) - (2)].astring);
       ;}
    break;

  case 499:
#line 6365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     im_stack.AddImage((yyvsp[(3) - (4)].astring));
         gr_print("image : T_Image  ASTRING  \n ");
     delete [] (yyvsp[(3) - (4)].astring);
       ;}
    break;

  case 500:
#line 6373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB, FLOAT_VECTOR.
         (9)  endianess: 0 for little, 1 for big.
         (11) filename or file format
         (13) first slice number
         (15) last slice number

       Description:
         Read 2D raw data (or a sequence of 2D raw data) as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Examples:
          i = ReadRawImages(1024,1024,USHORT,0,"AfGG.%d",48,48)
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yyvsp[(3) - (16)].adouble);
     int dimy                    = (int)           (yyvsp[(5) - (16)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yyvsp[(7) - (16)].aint);
     int endianness              = (int)           (yyvsp[(9) - (16)].adouble);
     char* file_format           = (char*)         (yyvsp[(11) - (16)].astring);
     unsigned short first_slice  = (unsigned short)(yyvsp[(13) - (16)].adouble);
     unsigned short last_slice   = (unsigned short)(yyvsp[(15) - (16)].adouble);

         amim->SetDim(dimx,dimy,1);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

         im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;
     amim->first_slice = first_slice;
     amim->last_slice  =  last_slice;

     if (amim->readdata_ext()) {
       im->SetAMImage(amim);
       im_stack.AddImage(im);
     } else {
       // Error message
       sprintf(tmp_string,"ReadRawImages() failed ... \n");
       err_print(tmp_string);
       im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 501:
#line 6432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  dimension in Z
         (9)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB, FLOAT_VECTOR.
         (11)  endianess: 0 for little, 1 for big.
         (13) filename or file format

       Description:
         Read 3D raw data as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Examples:
          i = ReadRawImages(256,256,256,USHORT,0,"data.raw")
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yyvsp[(3) - (14)].adouble);
     int dimy                    = (int)           (yyvsp[(5) - (14)].adouble);
     int dimz                    = (int)           (yyvsp[(7) - (14)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yyvsp[(9) - (14)].aint);
     int endianness              = (int)           (yyvsp[(11) - (14)].adouble);
     char* file_format           = (char*)         (yyvsp[(13) - (14)].astring);

         amim->SetDim(dimx,dimy,dimz);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       im_stack.AddImage(im);
     } else {
       // Error message
       sprintf(tmp_string,"ReadRawImages() failed ... \n");
       err_print(tmp_string);
       im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 502:
#line 6487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  dimension in Z
         (9)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB,
         (11) Vectorial dimension
         (13)  endianess: 0 for little, 1 for big.
         (15) filename or file format

       Description:
         Read 3D raw data as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Examples:
          i = ReadRawImages(256,256,256,FLOAT,3,0,"3dvectorfielddata.raw")
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yyvsp[(3) - (16)].adouble);
     int dimy                    = (int)           (yyvsp[(5) - (16)].adouble);
     int dimz                    = (int)           (yyvsp[(7) - (16)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yyvsp[(9) - (16)].aint);
     int vdim                    = (int)           (yyvsp[(11) - (16)].adouble);
     int endianness              = (int)           (yyvsp[(13) - (16)].adouble);
     char* file_format           = (char*)         (yyvsp[(15) - (16)].astring);

     amim->SetDim(dimx,dimy,dimz);
     amim->SetVDim(vdim);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(vdim,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       im_stack.AddImage(im);
     } else {
       // Error message
       sprintf(tmp_string,"ReadRawImages() failed ... \n");
       err_print(tmp_string);
       im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 503:
#line 6543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: dicom directory

       Description:
         Reads a dicom file using VTK
       **/
            InrImage*  res;

            res = Func_vtkDicomRead( (char*) (yyvsp[(3) - (4)].astring));

            Si res==NULL Alors
                sprintf(tmp_string,"vtkDicomRead() error ... \n");
                err_print(tmp_string);
                im_stack.AddImage((InrImage*)NULL);
            FinSi

            im_stack.AddImage(res);
            delete [] (yyvsp[(3) - (4)].astring);
       ;}
    break;

  case 504:
#line 6565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: filename in minc format

       Description:
         Reads a file in minc format using vtk reader for MINC.
       **/
            InrImage*  res;

            res = Func_vtkMINCRead( (char*) (yyvsp[(3) - (4)].astring));

            Si res==NULL Alors
                sprintf(tmp_string,"vtkMINCRead() error ... \n");
                err_print(tmp_string);
                im_stack.AddImage((InrImage*)NULL);
            FinSi

            im_stack.AddImage(res);
            delete [] (yyvsp[(3) - (4)].astring);
       ;}
    break;

  case 505:
#line 6587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Variable*  var   = (yyvsp[(1) - (4)].variable);
       ParamList::ptr param((yyvsp[(3) - (4)].paramlist));
       InrImage*  im;

       im = ((InrImage* (*)(ParamList*)) var->Pointer())(param.get());
       if (!im) {
        yyiperror(" image function returns NULL \n");
        YYABORT;
       }
      im_stack.AddImage(im);
       ;}
    break;

  case 506:
#line 6601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            yyiperror(" Need Image \n");
            YYABORT;
          }
          im_stack.AddImage((char*)name.c_str());


          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          res_print(newname.mb_str());
          res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.c_str());

          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
          gr_print("image : T_Image  \n ");
      ;}
    break;

  case 507:
#line 6631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yyvsp[(3) - (10)].aint), (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
        im = new InrImage( (int) (yyvsp[(5) - (10)].adouble), (int) (yyvsp[(7) - (10)].adouble), (int) (yyvsp[(9) - (10)].adouble), (WORDTYPE) (yyvsp[(3) - (10)].aint));
        im_stack.AddImage(im);
        gr_print("image : T_Image ( basic_type, expr, expr, expr ) \n ");
      ;}
    break;

  case 508:
#line 6640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
    Parameters:
      (3)  image type
      (5)  dimension in X
      (7)  dimension in Y
      (9)  dimension in Z
      (11) dimension in V: size of the vectors

    Description:
      Creates a new image
      **/
    InrImage* im;
    printf(" ********** %d %f %f %f\n", (yyvsp[(3) - (12)].aint), (yyvsp[(5) - (12)].adouble), (yyvsp[(7) - (12)].adouble), (yyvsp[(9) - (12)].adouble));
    im = new InrImage( (int) (yyvsp[(5) - (12)].adouble), (int) (yyvsp[(7) - (12)].adouble), (int) (yyvsp[(9) - (12)].adouble), (int) (yyvsp[(11) - (12)].adouble), (WORDTYPE) (yyvsp[(3) - (12)].aint));
    im_stack.AddImage(im);
    gr_print("image : T_Image ( basic_type, expr, expr, expr ) \n ");
    ;}
    break;

  case 509:
#line 6660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) image type
      (5) dimension in V: size of the vectors
      (7) reference image variable for the size,
            translation and voxel size.

    Description:
      Creates a new image from a reference image
    **/
      InrImage* im;
      WORDTYPE imformat = (WORDTYPE) (yyvsp[(3) - (8)].aint);
      int vdim   = (int) (yyvsp[(5) - (8)].adouble);
      InrImage::ptr varim=*(InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer();
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % (yyvsp[(7) - (8)].variable)->Name());

      im = new InrImage(imformat,vdim,
                        imname.c_str(),varim.get());
      im_stack.AddImage(im);
    ;}
    break;

  case 510:
#line 6686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         InrImage::ptr varim;
         InrImage* im;
         char  imname[200];

         varim=*(InrImage::ptr*) (yyvsp[(1) - (1)].variable)->Pointer();
         sprintf(imname,"copy_%s",(yyvsp[(1) - (1)].variable)->Name());
         im = new InrImage(varim->_format,imname,varim.get());
         (*im)=(*varim);
          im_stack.AddImage(im);
         gr_print("image : var_image \n ");
       ;}
    break;

  case 511:
#line 6700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
        Description:
          Applied on RGB or vectorial images,
          returns one component of the image:
          expr=0 returns Red   if RGB or the X coordinate if vectorial
          expr=1 returns Green if RGB or the Y coordinate if vectorial
          expr=2 returns Blue  if RGB or the Z coordinate if vectorial

        Examples:
          i = Image "test.jpg"
          ired   = i[0]
          igreen = i[1]
          iblue  = i[2]

          print ired(i.tx/2,i.ty/2); print "\n"
          print i(i.tx/2,i.ty/2,0,0); print "\n"
       **/
         InrImage::ptr im1;
         InrImage* im;
          char  imname[200];
         int i;

         im1=*(InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer();

          i = (int) (yyvsp[(3) - (4)].adouble);
          Si i<0               AlorsFait i = 0;
          Si i>=im1->GetVDim() AlorsFait i = im1->GetVDim()-1;
          sprintf(imname,"C%d_%s",i,(yyvsp[(1) - (4)].variable)->Name());

         SelonQue im1->_format Vaut
          Valeur WT_RGB:
          Valeur WT_RGBA:
          Valeur WT_UNSIGNED_CHAR:
             im = new InrImage(WT_UNSIGNED_CHAR,1,imname,im1.get());
          FinValeur

          Valeur WT_UNSIGNED_INT:
             im = new InrImage(WT_UNSIGNED_INT,1,imname,im1.get());
          FinValeur

          Valeur WT_SIGNED_INT:
             im = new InrImage(WT_SIGNED_INT,1,imname,im1.get());
          FinValeur

          Valeur WT_UNSIGNED_SHORT:
             im = new InrImage(WT_UNSIGNED_SHORT,1,imname,im1.get());
          FinValeur

          Valeur WT_SIGNED_SHORT:
             im = new InrImage(WT_SIGNED_SHORT,1,imname,im1.get());
          FinValeur

          Valeur WT_FLOAT_VECTOR:
          Valeur WT_FLOAT:
             im = new InrImage(WT_FLOAT,1,imname,im1.get());
          FinValeur

          Valeur WT_DOUBLE:
             im = new InrImage(WT_DOUBLE,1,imname,im1.get());
          FinValeur

       Defaut:
        yyiperror(" operator [] does not handle this format \n");
        YYABORT;
         FinSelonQue

         im->InitBuffer();
         im1->InitBuffer();
         Repeter
           im->FixeValeur(im1->VectValeurBuffer(i));
               im1->IncBuffer();
         JusquA Non(im->IncBuffer()) FinRepeter
         im_stack.AddImage(im);

       ;}
    break;

  case 512:
#line 6778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the sum of the values of an image along the specified dimension
             0 for X, 1 for Y, 2 for Z

             parameters:
               (3) image expression
               (5) expr

            Keywords:

            Others:
                min, max, median

        **/
    InrImage* im = (InrImage*) im_stack.GetLastImage();
        InrImage* res = NULL;
        int dim = (int) (yyvsp[(5) - (6)].adouble);
        int i,j,k;
        double sum;
        // check that the image is scalar
        if (im->ScalarFormat()) {
        switch (dim) {
          case 0:
            res = new InrImage(1,im->DimY(),im->DimZ(),1,WT_FLOAT,"sumX.ami.gz");
            for(j=0;j<=im->DimY()-1;j++)
            for(k=0;k<=im->DimZ()-1;k++) {
              sum=0;
              for(i=0;i<=im->DimX()-1;i++)
        sum += (*im)(i,j,k);
              res->BufferPos(0,j,k);
              res->FixeValeur(sum);
            }
          break;
          case 1:
            res = new InrImage(im->DimX(),1,im->DimZ(),1,WT_FLOAT,"sumY.ami.gz");
            for(i=0;i<=im->DimX()-1;i++)
            for(k=0;k<=im->DimZ()-1;k++) {
              sum=0;
              for(j=0;j<=im->DimY()-1;j++)
        sum += (*im)(i,j,k);
              res->BufferPos(i,0,k);
              res->FixeValeur(sum);
            }
          break;
          case 2:
            res = new InrImage(im->DimX(),im->DimY(),1,1,WT_FLOAT,"sumZ.ami.gz");
            for(i=0;i<=im->DimX()-1;i++)
            for(j=0;j<=im->DimY()-1;j++) {
              sum=0;
              for(k=0;k<=im->DimZ()-1;k++)
        sum += (*im)(i,j,k);
              res->BufferPos(i,j,0);
              res->FixeValeur(sum);
            }
          break;
        }
        } else
        {
          err_print("sum operator only for scalar images ... \n");
        }
        im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 513:
#line 6845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yyvsp[(5) - (6)].adouble));
    im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 514:
#line 6853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yyvsp[(5) - (6)].adouble));
    im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 515:
#line 6861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) im_stack.GetLastImage();
    InrImage* im      = (InrImage*) im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yyvsp[(7) - (8)].adouble));
    im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 516:
#line 6871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) im_stack.GetLastImage();
    InrImage* im      = (InrImage*) im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yyvsp[(7) - (8)].adouble));
    im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 517:
#line 6881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      Returns the image corresponding to the pointwise maximum between 2 images.


      See Also:
              min, median
        **/
    InrImage* im1;
    InrImage* im2;
        float val1,val2;

    im2 = im_stack.GetLastImage();
    im1 = im_stack.GetLastImage();
    im1->InitBuffer();
    im2->InitBuffer();
    Repeter
          val1 = im1->ValeurBuffer();
      val2 = im2->ValeurBuffer();
      Si val2>val1 AlorsFait im1->FixeValeur(val2);
      im2->IncBuffer();
    JusquA Non(im1->IncBuffer())
    FinRepeter
    im_stack.AddImage(im1);
    delete im2;

      ;}
    break;

  case 518:
#line 6911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yyvsp[(5) - (6)].astring));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
    delete [] (yyvsp[(3) - (6)].variable);

      ;}
    break;

  case 519:
#line 6930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yyvsp[(5) - (8)].astring),
              (WORDTYPE) (yyvsp[(7) - (8)].aint));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);

    delete [] (yyvsp[(5) - (8)].astring);

      ;}
    break;

  case 520:
#line 6951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),
              NULL,
              (yyvsp[(7) - (8)].astring));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);

    delete [] (yyvsp[(7) - (8)].astring);
      ;}
    break;

  case 521:
#line 6970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get(),
              NULL,
              (yyvsp[(7) - (10)].astring),
              (yyvsp[(9) - (10)].aint));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);

    delete [] (yyvsp[(7) - (10)].astring);

      ;}
    break;

  case 522:
#line 6991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yyvsp[(7) - (10)].variable)->Pointer())->get(),
              (yyvsp[(9) - (10)].astring));
        Si res==NULL Alors
          sprintf(tmp_string,"OpImage() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
        FinSi
        im_stack.AddImage(res);

        delete [] (yyvsp[(9) - (10)].astring);
      ;}
    break;

  case 523:
#line 7011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yyvsp[(7) - (12)].variable)->Pointer())->get(),
              (yyvsp[(9) - (12)].astring),
              (yyvsp[(11) - (12)].aint));
        Si res==NULL Alors
          sprintf(tmp_string,"OpImage() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
        FinSi
        im_stack.AddImage(res);
        delete [] (yyvsp[(9) - (12)].astring);
      ;}
    break;

  case 524:
#line 7033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters
          #1 expr_image: input image for the filter
          #2 expr:     standard deviation of the Gaussian kernel
          #3 expr:     derivation order in X coordinates
          #4 expr:     derivation order in Y coordinates
          #5 expr:     derivation order in Z coordinates

        description:
        Apply a Gaussian filter of specified standard deviation to
        input image and returns a new image.

        Example(s):
        - Convolution with a Gaussian kernel:
        i = Image(FLOAT,10,10,10)
        j = filter(i,1,0,0,0)

     **/
        InrImage*  res;
        InrImage* im = (InrImage*) im_stack.GetLastImage();

        res = Func_Filter( im,
                  (yyvsp[(5) - (12)].adouble),
                  (int) (yyvsp[(7) - (12)].adouble),
                  (int) (yyvsp[(9) - (12)].adouble),
                  (int) (yyvsp[(11) - (12)].adouble));

        Si res==NULL Alors
          sprintf(tmp_string,"Filter() erreur ... \n");
          err_print(tmp_string);
          res=im;
        Sinon
          delete im;
        FinSi
        im_stack.AddImage(res);
      ;}
    break;

  case 525:
#line 7071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        float var           = (yyvsp[(7) - (10)].adouble);
        float lowthreshold  = (yyvsp[(9) - (10)].adouble);
        //float highthreshold = $11;
            res = Func_itkCannyEdgeDetector(  ((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get(), var, lowthreshold);
        Si res==NULL Alors
          sprintf(tmp_string,"itk.CannyEdgeDetector() error ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 526:
#line 7087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkDist( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

        Si res==NULL Alors
          sprintf(tmp_string,"vtkDist() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 527:
#line 7102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkMedianFilter3D(
            ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
            (int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        Si res==NULL Alors
          sprintf(tmp_string,"vtkMedian3D() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 528:
#line 7119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        err_print("The function AndreDist() has been removed for licence issues! \n");
/*
        InrImage::ptr  in = *(InrImage::ptr*) $3->Pointer();
        InrImage*  res;
        int ok;

        res = new InrImage(WT_FLOAT,"AndreDist.ami.gz", in.get());

        ok = dist_squared( in.get(),res);

        Si !ok Alors
          sprintf(tmp_string,"AndreDist() erreur ... \n");
          err_print(tmp_string);
          delete res;
          res=NULL;
        Sinon
          im_stack.AddImage(res);
        FinSi
*/
      ;}
    break;

  case 529:
#line 7142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_2DFlux( im_stack.GetLastImage(),(yyvsp[(5) - (6)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"2DFlux() error ... \n");
      err_print(tmp_string);
      res=NULL;
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 530:
#line 7157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFlux( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"OutFlux() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 531:
#line 7172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFluxScalar( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"OutFluxScalar() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 532:
#line 7187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OrientationRatio2D( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"OrientationRatio() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 533:
#line 7202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          (3) IMAGE: input image
          (5) IMAGE: criterion for thinning
          (7) NUM: minimal threshold
          (9) NUM: maximal threshold
          (11) NUM: endpoint type 1: line 2: surface 3: line&surface
        Description:
          Creates a skeleton of the input image,
          the input image is considered binary (positive or 0 values)
          The skeletonization uses simple points.
          Usually the criterion image is an Euclidean distance
          transform to the boundaries of the object, and we
          can set than any point at distance lower than the minimal
          threshold shoud be removed automatically and any point
          at distance higher than the maximum should be kept.
      **/
    InrImage*  res;

    res = Func_Thinning( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                 ((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get(),
                 (yyvsp[(7) - (12)].adouble),
                 (yyvsp[(9) - (12)].adouble),
                 (yyvsp[(11) - (12)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"Skeleton() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 534:
#line 7238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SimplePoints( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"SimplePoints() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 535:
#line 7254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_CircleIntegration(
          ((InrImage::ptr*) (yyvsp[(3) - (12)].variable) ->Pointer())->get(), // gradient
          ((InrImage::ptr*) (yyvsp[(5) - (12)].variable) ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) (yyvsp[(7) - (12)].variable) ->Pointer())->get(),  // second vector
          (float)     (yyvsp[(9) - (12)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          ((InrImage::ptr*) (yyvsp[(11) - (12)].variable)->Pointer())->get()); // mask

        Si res==NULL Alors
          sprintf(tmp_string,"CircleInt() error ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 536:
#line 7276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_CircleIntegration(
        ((InrImage::ptr*) (yyvsp[(3) - (12)].variable) ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) (yyvsp[(5) - (12)].variable) ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) (yyvsp[(7) - (12)].variable) ->Pointer())->get(),  // second vector
        (float)     (yyvsp[(9) - (12)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        ((InrImage::ptr*) (yyvsp[(11) - (12)].variable)->Pointer())->get()); // mask

      Si res==NULL Alors
        sprintf(tmp_string,"CircleInt() error ... \n");
        err_print(tmp_string);
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
      ;}
    break;

  case 537:
#line 7298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) gradient
          (5) first vector
          (7) second vector
          (9) radius
          (11) mask
          (13) threshold on standard deviation
          (15) threshold on excentricity

        Description:
          Compute integrations of the gradient vectors along circles
          in a plane defined by 2 vectors,
          with constraints on the standard deviation and the excentricity
          (see pub. Krissian et al. EMBS 2003)
        **/
        InrImage*  res;

        res = Func_CircleIntSdExc(
          ((InrImage::ptr*) (yyvsp[(3) - (16)].variable) ->Pointer())->get(),  // gradient
          ((InrImage::ptr*) (yyvsp[(5) - (16)].variable) ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) (yyvsp[(7) - (16)].variable) ->Pointer())->get(),  // second vector
          (float)     (yyvsp[(9) - (16)].adouble),              // radius
          ((InrImage::ptr*) (yyvsp[(11) - (16)].variable)->Pointer())->get(),
          (float) (yyvsp[(13) - (16)].adouble),
          (float) (yyvsp[(15) - (16)].adouble),
          2, // pairs mode MEAN
          100, // keeps all points
          CIRCLE_RESPONSE_MEAN);

        Si res==NULL Alors
          sprintf(tmp_string,"CircleIntSdExc() error ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yyvsp[(3) - (16)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 538:
#line 7340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (3) gradient
        (5) first vector
        (7) second vector
        (9) radius
        (11) mask
        (13) threshold on standard deviation
        (15) threshold on excentricity
        (17) Pairs mode (0: MIN,1: MAX or 2:MEAN)
        (19) Highest percentage (Keeps only a percentage of highest boundary values)

      Description:
        Compute integrations of the gradient vectors along circles
        in a plane defined by 2 vectors,
        with constraints on the standard deviation and the excentricity
        (see pub. Krissian et al. EMBS 2003)
        with an additional constraint:
        it integrates half of the circle and takes the
        minimum between opposite values.
      **/
      InrImage*  res;

      res = Func_CircleIntSdExc(
        ((InrImage::ptr*) (yyvsp[(3) - (20)].variable) ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) (yyvsp[(5) - (20)].variable) ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) (yyvsp[(7) - (20)].variable) ->Pointer())->get(),  // second vector
        (float)     (yyvsp[(9) - (20)].adouble),              // radius
        ((InrImage::ptr*) (yyvsp[(11) - (20)].variable)->Pointer())->get(),
        (float) (yyvsp[(13) - (20)].adouble),
        (float) (yyvsp[(15) - (20)].adouble),
        (int) (yyvsp[(17) - (20)].adouble),
        (int) (yyvsp[(19) - (20)].adouble),
        CIRCLE_RESPONSE_MEAN);

      Si res==NULL Alors
        sprintf(tmp_string,"CircleIntSdExc() error ... \n");
        err_print(tmp_string);
        res=((InrImage::ptr*) (yyvsp[(3) - (20)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
      ;}
    break;

  case 539:
#line 7386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_LocalExtrema( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yyvsp[(7) - (10)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yyvsp[(9) - (10)].variable)->Pointer())->get()); // mask

    Si res==NULL Alors
      sprintf(tmp_string,"LocalExtrema() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 540:
#line 7404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    int samples = (int) (yyvsp[(11) - (12)].adouble);

    res = Func_LocalExtrema( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yyvsp[(7) - (12)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yyvsp[(9) - (12)].variable)->Pointer())->get(),  // mask
                 samples);                   // number of sample points around the circle

    Si res==NULL Alors
      sprintf(tmp_string,"LocalExtrema() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 541:
#line 7424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"NormalField() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 542:
#line 7439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get() , ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"NormalField() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 543:
#line 7454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DirConnectivity( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get() , ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"DirConnectivity() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 544:
#line 7471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    InrImage*    input  = (InrImage*) im_stack.GetLastImage();

    res = Func_NormGrad( input, (yyvsp[(5) - (6)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"Filter() error ... \n");
      err_print(tmp_string);
      res=input;
    Sinon
      delete input;
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 545:
#line 7490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscNormGrad( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"discnormgrad() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 546:
#line 7506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscMeanCurvature( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"DiscMeanCurvature() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 547:
#line 7523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_Gradient( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                 (yyvsp[(5) - (6)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"Filter() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 548:
#line 7539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
    InrImage*  res;

    res = Func_Laplacian(((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
    Si res==NULL Alors
      sprintf(tmp_string,"Filter() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
        ;}
    break;

  case 549:
#line 7563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                 (yyvsp[(5) - (6)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 550:
#line 7580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad2( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                 (yyvsp[(5) - (6)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 551:
#line 7594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yyvsp[(5) - (6)].adouble));

        im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 552:
#line 7606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    ImageExtent* extent = (ImageExtent*) (yyvsp[(3) - (4)].imageextent);

    //  extent->print();
    extent->SetRelative(((InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->get());

    //  extent->print();

    res = Func_SubImage( ((InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->get(),
                 (int)  round(extent->Xmin()),
                 (int)  round(extent->Ymin()),
                 (int)  round(extent->Zmin()),
                 (int)  round(extent->Xmax()),
                 (int)  round(extent->Ymax()),
                 (int)  round(extent->Zmax())
                );
    delete extent;

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res= ((InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 553:
#line 7637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr  im = *(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
    InrImage*  res;

    res = Func_SubImage( im.get(),
                 0, 0,  (int) round((yyvsp[(7) - (10)].adouble)),
                 im->DimX()-1,  im->DimY()-1, (int) round((yyvsp[(9) - (10)].adouble)));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 554:
#line 7657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters
        #1 var_image: input image
        #2 expr:      X min
        #3 expr:      Y min
        #4 expr:      Z min
        #5 expr:      X max
        #6 expr:      Y max
        #7 expr:      Z max

      Extract a rectangular subimage from the input image, the subimage
      keeps the information of the translation and it can be put back
      at the same position using putimage command.
      The same operation can also be achieved using the [] operator.

      Example:

      - Extract a subimage of size 4x4x4

      i = Image(FLOAT,10,10,10)
      j = subimage(i,5,5,5,8,8,8)

      Others:
        putimage, []

      **/
    InrImage*  res;

    res = Func_SubImage( ((InrImage::ptr*) (yyvsp[(3) - (16)].variable)->Pointer())->get(),
                 (int) (yyvsp[(5) - (16)].adouble), (int) (yyvsp[(7) - (16)].adouble), (int) (yyvsp[(9) - (16)].adouble),
                 (int) (yyvsp[(11) - (16)].adouble),(int) (yyvsp[(13) - (16)].adouble),(int) (yyvsp[(15) - (16)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (16)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 555:
#line 7699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
                   (yyvsp[(5) - (10)].adouble),  (yyvsp[(7) - (10)].adouble), (int) (yyvsp[(9) - (10)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 556:
#line 7711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(), (yyvsp[(5) - (8)].adouble),  (yyvsp[(7) - (8)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 557:
#line 7722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yyvsp[(9) - (12)].adouble);
    float Imax = (yyvsp[(11) - (12)].adouble);
    res = Func_EDP_dilate( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(), (yyvsp[(5) - (12)].adouble),  (yyvsp[(7) - (12)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 558:
#line 7735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
                  (yyvsp[(5) - (10)].adouble),  (yyvsp[(7) - (10)].adouble), (int) (yyvsp[(9) - (10)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 559:
#line 7747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(), (yyvsp[(5) - (8)].adouble),  (yyvsp[(7) - (8)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 560:
#line 7758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
      (9)  minimal intensity
      (11) maximal intensity
    Description:
      Grayscale morphological erosion
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
      minimal and maximal intensities allow to speed up the process
    **/
    InrImage*  res;
    float Imin = (yyvsp[(9) - (12)].adouble);
    float Imax = (yyvsp[(11) - (12)].adouble);
    res = Func_EDP_erode( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(), (yyvsp[(5) - (12)].adouble),  (yyvsp[(7) - (12)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 561:
#line 7786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
    Description:
      Grayscale morphological opening
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
    **/
    InrImage*  res;

    res = Func_EDP_open( ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                    (yyvsp[(5) - (8)].adouble),  (yyvsp[(7) - (8)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 562:
#line 7813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
      (9)  minimal intensity
      (11) maximal intensity
    Description:
      Grayscale morphological opening
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
      minimal and maximal intensities allow to speed up the process
    **/
    InrImage*  res;
    float Imin = (yyvsp[(9) - (12)].adouble);
    float Imax = (yyvsp[(11) - (12)].adouble);

    res = Func_EDP_open( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                    (yyvsp[(5) - (12)].adouble),  (yyvsp[(7) - (12)].adouble), Imin, Imax);

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 563:
#line 7845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_EDP_close( ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                   (yyvsp[(5) - (8)].adouble),  (yyvsp[(7) - (8)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 564:
#line 7861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yyvsp[(9) - (12)].adouble);
    float Imax = (yyvsp[(11) - (12)].adouble);

    res = Func_EDP_close( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                   (yyvsp[(5) - (12)].adouble),  (yyvsp[(7) - (12)].adouble), Imin, Imax);

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 565:
#line 7878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 566:
#line 7891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 567:
#line 7904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. input image
    // 2. isosurface threshold on the input image

    InrImage*  res;

    res = Func_LevelSets_Init( ((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),
                   (yyvsp[(7) - (8)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 568:
#line 7924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. input image
    // 2. Initial position of the level set a the zero-crossing of
    //    this image

    InrImage*  res;

    res = Func_LevelSets_Init(
           ((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),
           ((InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer())->get()
                   );

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
    ;}
    break;

  case 569:
#line 7947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 570:
#line 7961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());

    Si res==NULL Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
      res=((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 571:
#line 7978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) input image
        (2) sigma: standard deviation of the Gaussian smoothing applied to compute the local structure orientations.
        (3) k: diffusion parameter that controls the diffusion depending on the local gradients.
        (4) beta: data attachment coefficient.
        (5) number of iterations
      Description: 
        Runs an anisotropic diffusion filter using Gauss-Seidel numerical scheme, based on the Flux-diffusion algorithm [Krissian,IEEE TMI 2002].
      **/
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                  (yyvsp[(5) - (12)].adouble),  (yyvsp[(7) - (12)].adouble), (yyvsp[(9) - (12)].adouble));

          nb_iter = (int) (yyvsp[(11) - (12)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

      im_stack.AddImage(Func_AnisoGS_GetOutput());

      Func_EndAnisoGS();


    ;}
    break;

  case 572:
#line 8011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //
      // param 1: input image
      // 2: vector field
      // 3: data attachment coeff
      // 4: diffusion coeff
      // 5: number of iterations
      //
      InrImage*  res;
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                  1,  1, (yyvsp[(7) - (12)].adouble));


          nb_iter = (int) (yyvsp[(11) - (12)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get(),(yyvsp[(9) - (12)].adouble));
      FinPour

          res = Func_AnisoGS_GetOutput();
      Si res==NULL Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      Func_EndAnisoGS();

      im_stack.AddImage(res);

    ;}
    break;

  case 573:
#line 8049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (3)  input image
            (5)  standard deviation for Gaussian smoothing sigma
            (7)  threshold on the gradient magnitude
            (9)  data attachment coefficient
            (11) number of iterations
            (13) number of threads

          Description:
            Anisotropic diffusion filter based on the Flux diffusion paper
            (Krissian, 2002, IEEE TMI).
        **/
      InrImage::ptr  in      = *(InrImage::ptr*) (yyvsp[(3) - (14)].variable)->Pointer();
      float      sigma   = (yyvsp[(5) - (14)].adouble);
      float      k       = (yyvsp[(7) - (14)].adouble);
      float      beta    = (yyvsp[(9) - (14)].adouble);
      int        nb_iter    = (int) (yyvsp[(11) - (14)].adouble);
      int        nb_threads = (int) (yyvsp[(13) - (14)].adouble);

          InrImage*  res = Func_vtkAnisoGS(  in.get(), sigma, k, beta, nb_iter, nb_threads);

      Si res==NULL Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi

          //      printf("5 \n");
      im_stack.AddImage(res);

    ;}
    break;

  case 574:
#line 8084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),
                  (yyvsp[(5) - (12)].adouble),  (yyvsp[(7) - (12)].adouble), (yyvsp[(9) - (12)].adouble));


          Func_SetSmoothedParam(1);

          nb_iter = (int) (yyvsp[(11) - (12)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

          res = Func_AnisoGS_GetOutput();
      Si res==NULL Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      Func_EndAnisoGS();

      im_stack.AddImage(res);

    ;}
    break;

  case 575:
#line 8117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickert( ((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get(),
                (yyvsp[(7) - (12)].adouble),  (yyvsp[(9) - (12)].adouble), (yyvsp[(11) - (12)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(5) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 576:
#line 8134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickertCoherence( ((InrImage::ptr*) (yyvsp[(5) - (16)].variable)->Pointer())->get(),
                (yyvsp[(7) - (16)].adouble),  (yyvsp[(9) - (16)].adouble), (yyvsp[(11) - (16)].adouble), (yyvsp[(13) - (16)].adouble), (yyvsp[(15) - (16)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(5) - (16)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 577:
#line 8149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_SRAD_qcoeff( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());

      Si res==NULL Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 578:
#line 8165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (8)].adouble);
      int numit = (int) (yyvsp[(7) - (8)].adouble);

      res = Func_SRAD( ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL); // no extent

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 579:
#line 8185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (10)].adouble);
      int numit = (int) (yyvsp[(7) - (10)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(9) - (10)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent);

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 580:
#line 8208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (12)].adouble);
      int numit = (int) (yyvsp[(7) - (12)].adouble);
      int neighborhood = (int) (yyvsp[(9) - (12)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(11) - (12)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent);

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 581:
#line 8232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (10)].adouble);
      int numit = (int) (yyvsp[(7) - (10)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(9) - (10)].imageextent);


      res = Func_SRAD2( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent
                );

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 582:
#line 8258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (12)].adouble);
      int numit = (int) (yyvsp[(7) - (12)].adouble);
      int neighborhood = (int) (yyvsp[(9) - (12)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(11) - (12)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent // bounding box
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 583:
#line 8281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (10)].adouble);
      int numit = (int) (yyvsp[(7) - (10)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(9) - (10)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent // constant region
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 584:
#line 8303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt         = (float) (yyvsp[(5) - (12)].adouble);
      int numit        = (int) (yyvsp[(7) - (12)].adouble);
      int neighborhood = (int) (yyvsp[(9) - (12)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(11) - (12)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent);
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 585:
#line 8326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (12)].adouble);
      int numit = (int) (yyvsp[(7) - (12)].adouble);
      int neighborhood = (int) (yyvsp[(9) - (12)].adouble);
      ImageExtent* extent = (ImageExtent*) (yyvsp[(11) - (12)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 586:
#line 8350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (3) var_image: input image
            (5) numerical expression: mode, 0 for Lee Filter, 1: Kuan Filter,
                 2: additive, 3: MRI denoising
            (7) numerical expression: dt, time step
            (9) numerical expression: numit, number of iterations
            (11) numerical expression: size of the neighborhood n, neighborhood is
                (2n+1)^N, where N is the dimension of the image domain.
            (13) image extent: area of interest to calculate the noise
                 standard deviation, usually a constant area, for MRI denoising: background area

         Description:
            Runs a noise reducing anisotropic diffusion, Lee and Kuan's mode are
            for speckle noise in ultrasound images, additive mode is for additive
            stationary noise and MRI is for MRI style noise. In the case of MRI,
            the filter is designed to run on the square of the image intensity.
         **/
            InrImage*  res;
            int mode = (int) (yyvsp[(5) - (14)].adouble);
            float dt = (float) (yyvsp[(7) - (14)].adouble);
            int numit = (int) (yyvsp[(9) - (14)].adouble);
            int neighborhood = (int) (yyvsp[(11) - (14)].adouble);
            ImageExtent* extent = (ImageExtent*) (yyvsp[(13) - (14)].imageextent);

            res = Func_SRAD2( ((InrImage::ptr*) (yyvsp[(3) - (14)].variable)->Pointer())->get(),dt,numit,
                        mode, // fiter mode
                        neighborhood, //  neighborhood size
                        extent
                        );
            delete extent;

            Si res==NULL Alors
                fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
                res=((InrImage::ptr*) (yyvsp[(3) - (14)].variable)->Pointer())->get();
            FinSi

            im_stack.AddImage(res);
        ;}
    break;

  case 587:
#line 8394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr  initim = *(InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer();
      InrImage*  res;
      float dt = (float) (yyvsp[(5) - (12)].adouble);
      int numit = (int) (yyvsp[(7) - (12)].adouble);
      int attach = (int) (yyvsp[(9) - (12)].adouble);
      int scheme = (int) (yyvsp[(11) - (12)].adouble);

      if (initim->DimZ()==1)
        res = Func_RudinMultiplicative2D( initim.get(),dt,numit,attach, scheme);
      else
        res = Func_RudinMultiplicative3D( initim.get(),dt,numit,attach, scheme);

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoRudinMult() erreur ... \n");
        res=((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 588:
#line 8418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

        AjouteBruit* addnoise;
        InrImage*    res;
        InrImage::ptr    in = *(InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer();
        float mean;
        float sd;
        char  resname[256];

      mean = (yyvsp[(5) - (8)].adouble);
      sd   = (yyvsp[(7) - (8)].adouble);

      sprintf(resname,"%s.noise",in->Nom());
      res = new InrImage(WT_FLOAT, resname, in.get());

      (*res)=(*in);

      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res,mean,sd);
      delete addnoise;

      im_stack.AddImage(res);

    ;}
    break;

  case 589:
#line 8449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        InrImage*    res;

          res = Func_rot2D( ((InrImage::ptr*) (yyvsp[(3) - (14)].variable)->Pointer())->get(),
                (yyvsp[(5) - (14)].adouble), (yyvsp[(7) - (14)].adouble),   // rotation center
                (yyvsp[(9) - (14)].adouble),       // angle of rotation
                (yyvsp[(11) - (14)].adouble), (yyvsp[(13) - (14)].adouble)  // dimension of the new image
                );

      im_stack.AddImage(res);
        ;}
    break;

  case 590:
#line 8462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the X coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in X coordinates at 0:

        x = Xpos(i)
        i = i * (x>2) * ( x < i.tx-3)

        Others:
                Ypos, Zpos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(x);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        im_stack.AddImage(res);
        ;}
    break;

  case 591:
#line 8499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the Y coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in X coordinates at 0:

        y = Ypos(i)
        i = i * (y>2) * ( y < i.tx-3)

        Others:
                Xpos, Zpos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(y);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        im_stack.AddImage(res);
        ;}
    break;

  case 592:
#line 8536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the Z coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in Z coordinates at 0:

        z = Zpos(i)
        i = i * (z>2) * ( z < i.tx-3)

        Others:
                Xpos, Ypos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(z);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        im_stack.AddImage(res);
        ;}
    break;

  case 593:
#line 8573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new FLOAT vectorial image that contains
        the coordinates of the voxels (/pixels) of the given image.
        The coordinates are given in Real Coordinates (world),
        and are saved as vectors.


        Others:
                Xpos, Ypos, Zpos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->VectFixeValeurs(res->SpacePosX(x),
                               res->SpacePosY(y),
                               res->SpacePosZ(z));
          res->IncBuffer();
        FinPour
        FinPour
        FinPour

        im_stack.AddImage(res);
        ;}
    break;

  case 594:
#line 8608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          im_stack.AddImage((*(Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetCanvas()->GetGLImage());
        ;}
    break;

  case 595:
#line 8613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          im_stack.AddImage((InrImage*)NULL);
/*
          im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    ;}
    break;

  case 596:
#line 8622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      im_stack.AddImage((*(DessinImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetInrImage());
    ;}
    break;

  case 597:
#line 8627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

          im_stack.AddImage(res);

    ;}
    break;

  case 598:
#line 8638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

      im_stack.AddImage(res);

    ;}
    break;

  case 599:
#line 8648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

          im_stack.AddImage(res);

    ;}
    break;

  case 600:
#line 8658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

          im_stack.AddImage(res);
    ;}
    break;

  case 601:
#line 8667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
            float   maxtime = (float) (yyvsp[(7) - (8)].adouble);

          res = Func_vtkFastMarching( input, init,  maxtime);

          im_stack.AddImage(res);
    ;}
    break;

  case 602:
#line 8690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
      (7) maximal time
      (9)  target point X coord
      (11)               Y
      (13)              Z
    Description:
      Runs the fast marching algorithm
     **/

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   maxtime = (float) (yyvsp[(7) - (14)].adouble);

        res = Func_vtkFastMarchingTarget( input, init,  maxtime,
                (int) round((yyvsp[(9) - (14)].adouble)),
                (int) round((yyvsp[(11) - (14)].adouble)),
                (int) round((yyvsp[(13) - (14)].adouble))
                );

        im_stack.AddImage(res);
    ;}
    break;

  case 603:
#line 8719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  mean
      (9)  standard deviation
      (11) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean    = (float) (yyvsp[(7) - (12)].adouble);
        float   sd      = (float) (yyvsp[(9) - (12)].adouble);
        float   maxtime = (float) (yyvsp[(11) - (12)].adouble);

          res = Func_vtkFastMarching( input, init, mean, sd, maxtime);

          im_stack.AddImage(res);
          delete init;
          delete input;
    ;}
    break;

  case 604:
#line 8747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  mean
      (9)  standard deviation
      (11) maximal time
      (13) initialization type
    Description:
      Runs the fast marching algorithm
     **/
      /* Version without initialization */

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean     = (float) (yyvsp[(7) - (14)].adouble);
        float   sd       = (float) (yyvsp[(9) - (14)].adouble);
        float   maxtime  = (float) (yyvsp[(11) - (14)].adouble);
        int     inittype = (int) (yyvsp[(13) - (14)].adouble);

      res = Func_vtkFastMarching( input, init, mean, sd, maxtime,inittype);

          im_stack.AddImage(res);
          delete init;
          delete input;
    ;}
    break;

  case 605:
#line 8780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  track image, must be of format unsigned int
      (9)  maximal time
      (11) initialization type
    Description:
      Runs the fast marching algorithm using Dijkstra
      algorithm and tracking back the trajectories
     **/
      /* Version without initialization */

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res   = NULL;
        float   maxtime    = (float) (yyvsp[(9) - (12)].adouble);
        int     inittype   = (int)   (yyvsp[(11) - (12)].adouble);

      res = Func_vtkFastMarching(
                  input,
                  init,
                  ((InrImage::ptr*) (yyvsp[(7) - (12)].variable)->Pointer())->get(),
                  maxtime,inittype);

      im_stack.AddImage(res);
      delete init;
      delete input;
    ;}
    break;

  case 606:
#line 8812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());

          im_stack.AddImage(res);

        ;}
    break;

  case 607:
#line 8823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        InrImage* mask = (InrImage*) im_stack.GetLastImage();
;

      res = Func_ConvolveMask(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),
                  mask);

          im_stack.AddImage(res);
      delete mask;

        ;}
    break;

  case 608:
#line 8839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(), (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));

          im_stack.AddImage(res);

        ;}
    break;

  case 609:
#line 8849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(), (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));

          im_stack.AddImage(res);

        ;}
    break;

  case 610:
#line 8859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float a = (yyvsp[(5) - (12)].adouble);
        float b = (yyvsp[(7) - (12)].adouble);
        float c = (yyvsp[(9) - (12)].adouble);
        float dmax = (yyvsp[(11) - (12)].adouble);

          res = Func_Chamfer2(((InrImage::ptr*) (yyvsp[(3) - (12)].variable)->Pointer())->get(), a,b,c,dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 611:
#line 8874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 612:
#line 8888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 613:
#line 8902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                    dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 614:
#line 8915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                     dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 615:
#line 8928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                      dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 616:
#line 8940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                      dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 617:
#line 8952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                       dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 618:
#line 8964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                       -dmax,dmax);
          im_stack.AddImage(res);
        ;}
    break;

  case 619:
#line 8975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yyvsp[(5) - (8)].adouble);
        float dmax = (yyvsp[(7) - (8)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                       dmin,dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 620:
#line 8988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) input image variable
          (5) threshold on the image intensity to define
              the object
          (7) minimal distance (<0)
          (9) maximal distance (>0)

        Description:
          Computes an Euclidean distance by propagation
          starting from the object, up to a given distance
          for positive and negative sides.
        **/
            InrImage* res;
        float threshold = (yyvsp[(5) - (10)].adouble);
        float dmin      = (yyvsp[(7) - (10)].adouble);
        float dmax      = (yyvsp[(9) - (10)].adouble);

        printf("threshold = %f \n",threshold);
      res = Func_vtkPropDaniel2(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
                    threshold,dmin,dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 621:
#line 9015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) image expression: input image
        Description:
            Computes the connected components of the input image,
            considering the isosurface (or isocontour) of intensity value
            0 as the serapation between the components.
            The image background is supposed to have intensity values of 0.
            Returns an image of type INTEGER, and
            creates the following new variables:
                - reorder   : 1D image of the position position of the component
                    if sorted by size. The image size in X is the number of
                    components.
                    You can use image composition to get the image of the biggest
                    component, for example: reorder(cc_result) == 0.
                - inclusion :
                - cc_size   :
                - cc_sign   :
        Example:
            To analyze connected component from an isocontour value n for an image i,
            you can call i_cc=CC((FLOAT)i-n)
        **/
       InrImage* im = (InrImage*) im_stack.GetLastImage();
           InrImage* res;

      res = Func_CC(im);

          im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 622:
#line 9048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     /**
       Parameters:
         (1) image1: image variable
         (3) image2: image expression

       Description:
        Image Composition
        Several Cases:
         - scalar to scalar: transforms the intensity values
            of image 2 using image1 as a lookup table
         - vectorial to scalar
         - scalar to vectorial: returns the values of image1
            at the positions pointed by image2 (positions are converted
            to spatial coordinates)
         - vectorial to vectorial
      **/
      // image composition
      // Initialy for applying a RGB colormap to an image
      InrImage::ptr im1;
      InrImage* im2 = (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      int pos;

      im1 = *(InrImage::ptr*) (yyvsp[(1) - (4)].variable)->Pointer();

      res = new InrImage(im1->_format,"ImComp.ami.gz",im2);

      // Several Cases:
      // 1. scalar to scalar
      // 2. scalar to vectorial
      // 3. vectorial to scalar
      // 4. vectorial to vectorial
      if (res->ScalarFormat())
        res->InitImage(0);
      else
        res->InitImage(0,0,0);

      // im1 is a 1D image (colormap)
      //
      if (im1->VectorialFormat()&&im2->ScalarFormat()) {
        res->InitBuffer();
        im2->InitBuffer();

        Repeter

          pos = (int) im2->ValeurBuffer();
          Si (pos<0) AlorsFait pos = 0;
          Si (pos>=im1->DimX()) AlorsFait pos = im1->DimX()-1;
          im1->BufferPos(pos,0,0);

          res->VectFixeValeurs(im1->VectValeurBuffer(0),
                   im1->VectValeurBuffer(1),
                   im1->VectValeurBuffer(2));

          im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
      } else
      // Greyscale colormap
      if (im1->ScalarFormat()&&im2->ScalarFormat()) {
        res->InitBuffer();
        im2->InitBuffer();
        Repeter
          pos = (int) im2->ValeurBuffer();
          Si (pos<0) AlorsFait pos = 0;
          Si (pos>=im1->DimX()) AlorsFait pos = im1->DimX()-1;
          im1->BufferPos(pos,0,0);
          res->FixeValeur(im1->ValeurBuffer());
          im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
      } else
      // Applying a transformation ...
      if (im1->VectorialFormat()&&im2->VectorialFormat()) {
        float posx, posy, posz;
        res->InitBuffer();
        im2->InitBuffer();
        Repeter
          // linear interpolation
          posx =  im1->SpaceToVoxelX(im2->VectValeurBuffer(0));
          posy =  im1->SpaceToVoxelY(im2->VectValeurBuffer(1));
          posz =  im1->SpaceToVoxelZ(im2->VectValeurBuffer(2));
          res->VectFixeValeurs(
            im1->InterpLinIntensite(posx,posy,posz,0),
            im1->InterpLinIntensite(posx,posy,posz,1),
            im1->InterpLinIntensite(posx,posy,posz,2));
          im2->IncBuffer();
        JusquA Non(res->IncBuffer()) FinRepeter
      } else
      // Applying a transformation ...
      if (im1->ScalarFormat()&&im2->VectorialFormat()) {
        float posx, posy, posz;
        res->InitBuffer();
        im2->InitBuffer();
        Repeter
          // linear interpolation
          posx =  im1->SpaceToVoxelX(im2->VectValeurBuffer(0));
          posy =  im1->SpaceToVoxelY(im2->VectValeurBuffer(1));
          posz =  im1->SpaceToVoxelZ(im2->VectValeurBuffer(2));
          res->FixeValeur(im1->InterpLinIntensite(posx,posy,posz));
          im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
      } else
        fprintf(stderr," Image Composition: type of composition not implemented \n");

          im_stack.AddImage(res);
      delete im2;
        ;}
    break;

  case 623:
#line 9156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
       Parameters:
         (3) image: image to compute the histogram
         (5) expr: minimal value
         (7) expr: maximal value
         (9) expr: number of intervals

       Description:
         Compute the histogram of an image and returns it
         as a 1D image
    **/
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      float vmin  = (yyvsp[(5) - (10)].adouble);
      float vmax  = (yyvsp[(7) - (10)].adouble);
      int   nint = (int) (yyvsp[(9) - (10)].adouble); // number of intervals

      InrImage* res;

      res = Func_Histogram(im,vmin,vmax,nint);
      im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 624:
#line 9180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      float vmin  = (yyvsp[(5) - (10)].adouble);
      float vmax  = (yyvsp[(7) - (10)].adouble);
      int   nint = (int) (yyvsp[(9) - (10)].adouble); // number of intervals

      int* numpts;
      int  n;
      InrImage* res;
      float v;
      double total = 0;

      res = new InrImage(nint,1,1,WT_SIGNED_INT);

      numpts = new int[nint];
      Pour(n,0,nint-1)
        numpts[n]=0;
      FinPour

        im->InitBuffer();
      Repeter
        v = im->ValeurBuffer();
        Si v>=vmin Et v<vmax Alors
          n = (int) ((v-vmin)/(vmax-vmin)*nint);
          Si n==nint AlorsFait n=nint-1;
          numpts[n]++;
        FinSi
          JusquA Non(im->IncBuffer()) FinRepeter

      res->InitBuffer();
      Pour(n,0,nint-1)
        total += numpts[n];
        res->FixeValeur(1.0*total/im->Size());
        res->IncBuffer();
          FinPour

      delete [] numpts;

      im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 625:
#line 9222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;

      InrImage* im = (InrImage*) im_stack.GetLastImage();
      if (im->DimZ()>1)
        res = Func_MeanHalfSize(im,3);
      else
        res = Func_MeanHalfSize(im,2);

      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 626:
#line 9235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yyvsp[(5) - (6)].adouble);

      InrImage* im = (InrImage*) im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 627:
#line 9246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yyvsp[(5) - (6)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            im_stack.AddImage(res);
        ;}
    break;

  case 628:
#line 9255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            image to resize
            new dimension in X
            new dimension in Y
            new dimension in Z
            interpolation: 0: nearest neighbor, 1:linear, 2:spline
        Description:
          Image resize
        **/
            InrImage* res;
            int sx = (int) (yyvsp[(5) - (12)].adouble);
            int sy = (int) (yyvsp[(7) - (12)].adouble);
            int sz = (int) (yyvsp[(9) - (12)].adouble);
            unsigned char interpolate=(unsigned char) (yyvsp[(11) - (12)].adouble);

            InrImage* im = (InrImage*) im_stack.GetLastImage();
            res = Func_Resize(im,sx,sy,sz,interpolate);

            if (res!=NULL) im_stack.AddImage(res);
            delete im;
        ;}
    break;

  case 629:
#line 9279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      FloatMatrix m(4,4);
      m[0][0] =  (yyvsp[(7) - (30)].adouble);
      m[0][1] =  (yyvsp[(9) - (30)].adouble);
      m[0][2] =  (yyvsp[(11) - (30)].adouble);
      m[0][3] =  (yyvsp[(13) - (30)].adouble);
      m[1][0] =  (yyvsp[(15) - (30)].adouble);
      m[1][1] =  (yyvsp[(17) - (30)].adouble);
      m[1][2] =  (yyvsp[(19) - (30)].adouble);
      m[1][3] =  (yyvsp[(21) - (30)].adouble);
      m[2][0] =  (yyvsp[(23) - (30)].adouble);
      m[2][1] =  (yyvsp[(25) - (30)].adouble);
      m[2][2] =  (yyvsp[(27) - (30)].adouble);
      m[2][3] =  (yyvsp[(29) - (30)].adouble);

      InrImage::ptr im1 = *(InrImage::ptr*) (yyvsp[(3) - (30)].variable)->Pointer();
      InrImage::ptr im2 = *(InrImage::ptr*) (yyvsp[(5) - (30)].variable)->Pointer();

      res = Func_ReSlice(im1.get(),im2.get(),m);

      if (res!=NULL) im_stack.AddImage(res);

        ;}
    break;

  case 630:
#line 9304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      int   order = (int) (yyvsp[(5) - (8)].adouble);
      float resolution = (yyvsp[(7) - (8)].adouble);
      InrImage* input=(InrImage*) im_stack.GetLastImage();

      res = Func_vtkConvexHull(input,
                   order,resolution);

      if (res!=NULL) im_stack.AddImage(res);
      delete input;
        ;}
    break;

  case 631:
#line 9317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (5)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 632:
#line 9327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (5)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 633:
#line 9337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (5)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 634:
#line 9347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 635:
#line 9357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yyvsp[(5) - (6)].adouble));
      if (res!=NULL) im_stack.AddImage(res);

      delete im;
        ;}
    break;

  case 636:
#line 9367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 637:
#line 9375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yyvsp[(5) - (6)].adouble));
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 638:
#line 9383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 639:
#line 9391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
          Compute the altitude to the sea level based on the
          infrared channel.

        parameters:
          (3) image containing the infrared channel
          (5) image containing 5 coefficients for the computation
              of the temperature and of the altitude,

        keywords:
          Fluid

        **/
      InrImage* coeff =  (InrImage*) im_stack.GetLastImage();
      InrImage* input =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input,coeff);
      if (res!=NULL) im_stack.AddImage(res);

      delete coeff;
      delete input;
        ;}
    break;

  case 640:
#line 9418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
        Compute the altitude to the sea level based on the
        temperature channel.

        params:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage* input =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Temp2Altitudes(input);
      if (res!=NULL) im_stack.AddImage(res);

      delete input;
        ;}
    break;

  case 641:
#line 9439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yyvsp[(3) - (4)].astring));
      if (res!=NULL) im_stack.AddImage(res);
      delete [] (yyvsp[(3) - (4)].astring);
    ;}
    break;

  case 642:
#line 9447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
    Trying the slicing procedure to incorporate into the
    image drawing class

        params:
        (3) image to slice
        (5) width orientation 1,2,3 for XY, XZ, ZY
        (7) height orientation
        (9,11,13) cursor position
        (15) expected width
        (17) expected height

        **/
        InrImage* im = (InrImage*) im_stack.GetLastImage();
        InrImage* res;

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
      imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
      imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yyvsp[(9) - (18)].adouble),(int)(yyvsp[(11) - (18)].adouble),(int)(yyvsp[(13) - (18)].adouble));
          imdraw.Apply((int)(yyvsp[(5) - (18)].adouble),(int)(yyvsp[(7) - (18)].adouble),(int)(yyvsp[(15) - (18)].adouble),(int)(yyvsp[(17) - (18)].adouble));
          // copy to RGB image
          res = new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB);
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
      im_stack.AddImage(res);

        } else
     fprintf(stderr,"only UCHAR format for now \n");

        delete im;

        ;}
    break;

  case 643:
#line 9485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input PolyData containing lines to reconstruct
      (5) reference image for reconstruction
      (7) image of the radii associated to each point of the input PolyData (1D image)
    Description:
      Tubular reconstruction based on a set of lines and an estimated radius
      size for each point
    **/
      InrImage*         res;

      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  (yyvsp[(3) - (8)].variable)->Pointer();
      InrImage::ptr ref = *(InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer();
      InrImage::ptr rad = InrImage::ptr(
                                im_stack.GetLastImage());

      res = LineRecons( surf.get(), ref.get(), rad.get());
      im_stack.AddImage(res);
    ;}
    break;

  case 644:
#line 9508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      InrImage*         res;

      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  (yyvsp[(3) - (6)].variable)->Pointer();

      res = Func_ReadCTALineRadii( surf.get(), (yyvsp[(5) - (6)].astring));
      im_stack.AddImage(res);
    ;}
    break;

  case 650:
#line 9533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               ;}
    break;

  case 652:
#line 9535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             ;}
    break;

  case 653:
#line 9536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             ;}
    break;

  case 654:
#line 9537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            ;}
    break;

  case 655:
#line 9538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            ;}
    break;

  case 656:
#line 9539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           ;}
    break;

  case 657:
#line 9540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           ;}
    break;

  case 658:
#line 9541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             ;}
    break;

  case 659:
#line 9542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            ;}
    break;

  case 660:
#line 9543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            ;}
    break;

  case 661:
#line 9544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            ;}
    break;

  case 662:
#line 9545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             ;}
    break;

  case 663:
#line 9546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) ;}
    break;

  case 664:
#line 9547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             ;}
    break;

  case 665:
#line 9549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* im1;
          InrImage* res;

          im1 = im_stack.GetLastImage();
          res = Norm(*im1);
          if (res!=NULL)
            im_stack.AddImage(res);
          else
            fprintf(stderr,"Error computing the norm |image| \n");
          delete im1;
        ;}
    break;

  case 667:
#line 9566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
                  The image conversion is done using the cast operator
                  where basic_type can be one of the basic type accepted,
                  currently:
                  CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR


                Example:
                  i = Image(FLOAT,10,10,10)
                  j = (RGB) i
        **/
            InrImage* im1;
            InrImage* im;
            im1 = im_stack.GetLastImage();
            im  = new InrImage( (WORDTYPE) (yyvsp[(2) - (4)].aint), "tmp.inr.gz", im1);
            (*im) = (*im1);
            im_stack.AddImage(im);
            delete im1;
          ;}
    break;

  case 669:
#line 9590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 670:
#line 9596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 671:
#line 9598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   ;}
    break;

  case 672:
#line 9599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   ;}
    break;

  case 673:
#line 9600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   ;}
    break;

  case 676:
#line 9609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 677:
#line 9610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 678:
#line 9611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   ;}
    break;

  case 679:
#line 9612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   ;}
    break;

  case 682:
#line 9620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    ;}
    break;

  case 683:
#line 9621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    ;}
    break;

  case 684:
#line 9622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   ;}
    break;

  case 685:
#line 9623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   ;}
    break;

  case 686:
#line 9624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 687:
#line 9625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 688:
#line 9626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 689:
#line 9627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 691:
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   ;}
    break;

  case 692:
#line 9633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   ;}
    break;

  case 693:
#line 9634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yyvsp[(3) - (3)].adouble))   ;}
    break;

  case 694:
#line 9635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yyvsp[(3) - (3)].adouble))   ;}
    break;

  case 709:
#line 9677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         gltransf_stack.AddMatrix(newglt);

           ;}
    break;

  case 710:
#line 9688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix glt;
         GLTransfMatrix* newglt;

         printf("GetTransform begin \n");
         newglt = new GLTransfMatrix();
             glt = (*(Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetCanvas()->GetObjectTransform();
         (*newglt) = (glt);
         gltransf_stack.AddMatrix(newglt);
         printf("GetTransform \n");
           ;}
    break;

  case 711:
#line 9701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yyvsp[(3) - (8)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yyvsp[(5) - (8)].variable)->Pointer();
         float coeff = (yyvsp[(7) - (8)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         gltransf_stack.AddMatrix(newglt);
       ;}
    break;

  case 712:
#line 9712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform((yyvsp[(3) - (4)].astring));
         if (newglt!=NULL)
           gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           sprintf(tmp_string,"TRANSFORM() Error reading file ...\n");
           err_print(tmp_string);
           gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
         delete [] (yyvsp[(3) - (4)].astring);
           ;}
    break;

  case 713:
#line 9730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yyvsp[(3) - (6)].adouble),(int)(yyvsp[(5) - (6)].adouble));
         matrix_stack.AddMatrix(m);
       ;}
    break;

  case 714:
#line 9737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          matrix_stack.AddMatrix(newmat);
       ;}
    break;

  case 715:
#line 9747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
        **/
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          matrix_stack.AddMatrix(res);
        ;}
    break;

  case 721:
#line 9767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               ;}
    break;

  case 723:
#line 9770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          matrix_stack.AddMatrix(res);
        ;}
    break;

  case 724:
#line 9778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             ;}
    break;

  case 725:
#line 9779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             ;}
    break;

  case 726:
#line 9780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            ;}
    break;

  case 727:
#line 9781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            ;}
    break;

  case 728:
#line 9782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           ;}
    break;

  case 729:
#line 9783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           ;}
    break;

  case 730:
#line 9784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             ;}
    break;

  case 731:
#line 9785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            ;}
    break;

  case 732:
#line 9786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            ;}
    break;

  case 733:
#line 9787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            ;}
    break;

  case 734:
#line 9788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             ;}
    break;

  case 735:
#line 9789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) ;}
    break;

  case 736:
#line 9790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             ;}
    break;

  case 739:
#line 9797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 740:
#line 9798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   ;}
    break;

  case 741:
#line 9800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           ;}
    break;

  case 743:
#line 9810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 744:
#line 9811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 745:
#line 9812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   ;}
    break;

  case 746:
#line 9813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   ;}
    break;

  case 758:
#line 9862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yyvsp[(1) - (1)].variable);
        ;}
    break;

  case 759:
#line 9867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yyvsp[(3) - (4)].adouble);

          array = *(VarArray::ptr*) ((yyvsp[(1) - (4)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            char name[256];
            sprintf(name,"%s[%d]",(yyvsp[(1) - (4)].variable)->Name(),i);
            array->InitElement(i,surf,name);
          }
          (yyval.variable)=&(array->GetVar(i));
        ;}
    break;

  case 760:
#line 9884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
          SurfacePoly* surf;
          surf = Func_isosurf(im,
                  (yyvsp[(5) - (6)].adouble),
                  NULL);
          Si surf != NULL Alors
            surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 761:
#line 9896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_isosurf((*(InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer()),
                  (yyvsp[(5) - (6)].adouble),
                  NULL,
                  2);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 762:
#line 9908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yyvsp[(5) - (8)].adouble),
                ((InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer())->get());
    Si surf != NULL Alors
        surf_stack.AddSurf(surf);
    FinSi
    ;}
    break;

  case 763:
#line 9920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
     Parameters:
        (3) input image
        (5) Gaussian standard deviation
        (7) mask

     Description:
        Computes the centerlines of bright tubular structures
        as zero-crossing of the gradient vector field in the planes
        of the 2 eigenvectors of the Hessian matrix that
        correspond to the lowest and negative eigenvalues
     **/
      InrImage::ptr mask = InrImage::ptr(im_stack.GetLastImage());
      InrImage::ptr im   = InrImage::ptr(im_stack.GetLastImage());
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yyvsp[(5) - (8)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines != NULL)
        surf_stack.AddSurf(lines);

      //vtklines->Delete();
      delete crestlines;

    ;}
    break;

  case 764:
#line 9953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 765:
#line 9962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble) );
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 766:
#line 9971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),(yyvsp[(5) - (6)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 767:
#line 9980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (int) (yyvsp[(5) - (6)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 768:
#line 9989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (int) (yyvsp[(5) - (6)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 769:
#line 9998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      surf_stack.AddSurf(surf);
          gr_print("image : T_Surface  ()  \n ");
        ;}
    break;

  case 770:
#line 10005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      surf_stack.AddSurf((yyvsp[(2) - (2)].astring));
          gr_print("surface : T_Surface  ASTRING  \n ");

      delete [] (yyvsp[(2) - (2)].astring);
        ;}
    break;

  case 771:
#line 10013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      surf_stack.AddSurf((yyvsp[(3) - (4)].astring));
          gr_print("image : T_Surface  expr_string  \n ");
      delete [] (yyvsp[(3) - (4)].astring);
        ;}
    break;

  case 772:
#line 10020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskSurface(name);
          if (!res) {
            yyiperror(" Need Surface \n");
            YYABORT;
          }
          surf_stack.AddSurf((char*)name.c_str());
          inc_cmd = str(format(" \"%1%\"  // from browser ") % name);
          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()->IncCommand(inc_cmd);
          gr_print("surface : T_Surface  \n ");
        ;}
    break;

  case 773:
#line 10038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
          SurfacePoly* surf;
          surf = Func_ReadCTALine((yyvsp[(3) - (4)].astring));
          surf_stack.AddSurf(surf);
        ;}
    break;

  case 774:
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
            (5) line type:  0: point + radius + standard dev
                            1: point
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
          SurfacePoly* surf;
          surf = Func_ReadCTALine((yyvsp[(3) - (6)].astring), (int) (yyvsp[(5) - (6)].adouble));
          surf_stack.AddSurf(surf);
        ;}
    break;

  case 775:
#line 10068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          surf_stack.AddSurf(newsurf);
    ;}
    break;

  case 776:
#line 10078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      surf = Func_Skeleton2lines( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get()  );

      Si surf==NULL Alors
        sprintf(tmp_string,"Skeleton2lines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 777:
#line 10097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input polydata
    Description:
      Smooth lines based on a simple scheme of heat diffusion
      with data attachment (applied to each coordinate)
      using default parameters of
        smoothing coeff 0.1
        data coeff      0.01
        iterations      10
    **/
          SurfacePoly* surf;

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get(),
                      0.1,
                      0.01,
                      10);

      Si surf==NULL Alors
        sprintf(tmp_string,"SmoothLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 778:
#line 10126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input polydata
      (5) smoothing coefficient
      (7) data attachment coefficient
      (9) number of iterations
    Description:
      Smooth lines based on a simple scheme of heat diffusion
      with data attachment
    **/
          SurfacePoly* surf;

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(),
                      (yyvsp[(5) - (10)].adouble),
                      (yyvsp[(7) - (10)].adouble),
                      (int) (yyvsp[(9) - (10)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"SmoothLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 779:
#line 10154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_ResampleLines( ((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                     (yyvsp[(5) - (6)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"ResampleLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 780:
#line 10171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_shortestpath( ((SurfacePoly::ptr*) (yyvsp[(3) - (16)].variable)->Pointer())->get(),
                      (yyvsp[(5) - (16)].adouble), (yyvsp[(7) - (16)].adouble), (yyvsp[(9) - (16)].adouble),
                      (yyvsp[(11) - (16)].adouble),(yyvsp[(13) - (16)].adouble),(yyvsp[(15) - (16)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_shortestpath () error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 781:
#line 10189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) threshold to discard voxels
      (7)  X position of the first point
      (9)  Y position of the first point
      (11) Z position of the first point
      (13) X position of the second point
      (15) Y position of the second point
      (17) Z position of the second point
    Description:
      Finds the shortest path within the image voxels
      where the image intensity values are used to weight the edges of the graph,
      voxels are linked if their intensities are lower than the given threshold
      creates a path between the first and the second points if it exists
    **/
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_shortestpath_image(  im.get(),(yyvsp[(5) - (18)].adouble),
                                      (yyvsp[(7) - (18)].adouble), (yyvsp[(9) - (18)].adouble), (yyvsp[(11) - (18)].adouble),
                                      (yyvsp[(13) - (18)].adouble),(yyvsp[(15) - (18)].adouble),(yyvsp[(17) - (18)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_shortestpath_image () error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 782:
#line 10223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image containing the tracks as indices:
          voxel index of the preceding voxel
      (5) X coord of the starting point
      (7) Y coord of the starting point
      (9) Z coord of the starting point

    Description:
      Creates a path starting at a point in voxel coordinates
      and following the (integer) displacements given by the input vector field
      image
    **/
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_path_from_displ(  im.get(),
          (int) round((yyvsp[(5) - (10)].adouble)),
          (int) round((yyvsp[(7) - (10)].adouble)),
          (int) round((yyvsp[(9) - (10)].adouble))
          );

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_path_from_displ() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 783:
#line 10260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image as a vector field in spatial coordinates
            or as a scalar potential
      (5) time step for the evolution
      (7) maximal Euclidean distance of the path
      (9)  X coord of the starting point (in spatial coord.)
      (11)  Y coord ---
      (13)  Z coord ---
      (15)  X coord of the expected end point (in spatial coord.)
      (17)  Y coord  ---
      (19)  Z coord  ---

    Description:
      Creates a path starting at a point in spatial coordinates
      and following the displacements given by the input vector field
      image
      if the input is scalar the corresponding vector field is computed
      from its gradient by local linear interpolation
      the tracking stops in one of the following cases:
        - the maximal distance is reached
        - the closest voxel to the current location has a negative intensity
        - the current gradient is very low
    **/
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yyvsp[(9) - (20)].adouble),(yyvsp[(11) - (20)].adouble),(yyvsp[(13) - (20)].adouble)};
      double end[3] = {(yyvsp[(15) - (20)].adouble),(yyvsp[(17) - (20)].adouble),(yyvsp[(19) - (20)].adouble)};
      surf = Func_path_from_vectfield(  im.get(),
                                        start,end,
                                        (yyvsp[(5) - (20)].adouble), (yyvsp[(7) - (20)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_path_from_vectfield() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 784:
#line 10303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) input polydata
      (5) maximal distance (square distance between extremities)
      (7) maximal angle (square length of the sum of the
                         normalized extremity vectors)
    Description:
      Connecting close lines
    **/
          SurfacePoly* surf;

      surf = Func_ConnectLines( ((SurfacePoly::ptr*) (yyvsp[(1) - (8)].variable)->Pointer())->get(),
                      (yyvsp[(5) - (8)].adouble),
                      (yyvsp[(7) - (8)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"ConnectLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi


    ;}
    break;

  case 785:
#line 10330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 786:
#line 10340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**

        description:
      creates a flat triangulates mesh from the image domain,
      discarding pixels with null intensity.

        parameters:
        (3) input image
        (5) triangle orientation:
            1: following X^Y
            other value: following -X^Y

          **/
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yyvsp[(5) - (6)].adouble) );
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 787:
#line 10363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      float minth = (yyvsp[(5) - (8)].adouble);
      float maxth = (yyvsp[(7) - (8)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 788:
#line 10375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yyvsp[(5) - (8)].adouble);
      float maxth = (yyvsp[(7) - (8)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im,minth,maxth);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete im;
        ;}
    break;

  case 789:
#line 10388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions

       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      InrImage* highpos = (InrImage*) im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) im_stack.GetLastImage();
      InrImage* input   = (InrImage*) im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yyvsp[(5) - (12)].adouble);
      float maxth = (yyvsp[(7) - (12)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        ;}
    break;

  case 790:
#line 10428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions
        (13) RGB image to color the top surface or NULL if not used
        (15) alpha opacity value (in [0,1], 0 is fully transparent)


       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      InrImage* colors  = (InrImage*) im_stack.GetLastImage();
      InrImage* highpos = (InrImage*) im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) im_stack.GetLastImage();
      InrImage* input   = (InrImage*) im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yyvsp[(5) - (16)].adouble);
      float maxth = (yyvsp[(7) - (16)].adouble);
      float alpha = (yyvsp[(15) - (16)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos, colors, alpha);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        ;}
    break;

  case 791:
#line 10473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type

        description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors
        - type:          0 for Altantic, 1 for Africa.

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3,1)


        See Also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/

      InrImage* alt2  = (InrImage*) im_stack.GetLastImage();
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yyvsp[(9) - (16)].adouble);
      int stepy   = (int) (yyvsp[(11) - (16)].adouble);
      float scale = (yyvsp[(13) - (16)].adouble);
      int   type  = (int) (yyvsp[(15) - (16)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 792:
#line 10523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type
          expr:                 vector_style (in {0,1})

        description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors
        - type:          0 for Altantic, 1 for Africa.
        - vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3,1,1)


        See Also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/

      InrImage* alt2  = (InrImage*) im_stack.GetLastImage();
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yyvsp[(9) - (18)].adouble);
      int stepy   = (int) (yyvsp[(11) - (18)].adouble);
      float scale = (yyvsp[(13) - (18)].adouble);
      int   type   = (int) (yyvsp[(15) - (18)].adouble);
      int   style  = (int) (yyvsp[(17) - (18)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type,style);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 793:
#line 10576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale

        description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3)


        See Also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      InrImage* alt2  = (InrImage*) im_stack.GetLastImage();
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yyvsp[(9) - (14)].adouble);
      int stepy   = (int) (yyvsp[(11) - (14)].adouble);
      float scale = (yyvsp[(13) - (14)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 794:
#line 10622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          (3) expr_image:        displacement field in voxel coordinates
          (5) expr:              spacing between vectors in X direction
          (7) expr:              spacing between vectors in Y direction
          (9) expr:              spacing between vectors in Z direction
          (11) expr:             scale
          (13) vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        description:
        Creates a 3D vector field for visualization.

      **/
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yyvsp[(5) - (14)].adouble);
      int stepy   = (int) (yyvsp[(7) - (14)].adouble);
      int stepz   = (int) (yyvsp[(9) - (14)].adouble);
      float scale = (yyvsp[(11) - (14)].adouble);
      int style = (int) (yyvsp[(13) - (14)].adouble);
      SurfacePoly* surf;

       surf = AMIFluid::Func_CreateVectors(displ, stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         surf_stack.AddSurf(surf);
       FinSi
       delete displ;
        ;}
    break;

  case 795:
#line 10651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (3)  First  vector field v1
        (5)  Second vector field v2
        (7)  Third  vector field v3
        (9)  step in X dimension
        (11) step in Y dimension
        (13) step in Z dimension
        (15) resolution

    Description:
        Create 3D ellipsoids based on 3 vector fields
    **/
      InrImage::ptr v3  = InrImage::ptr(im_stack.GetLastImage());
      InrImage::ptr v2  = InrImage::ptr(im_stack.GetLastImage());
      InrImage::ptr v1  = InrImage::ptr(im_stack.GetLastImage());
      int stepx   = (int) (yyvsp[(9) - (16)].adouble);
      int stepy   = (int) (yyvsp[(11) - (16)].adouble);
      int stepz   = (int) (yyvsp[(13) - (16)].adouble);
      int res     = (int) (yyvsp[(15) - (16)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1.get(),
              v2.get(),
              v3.get(),
              stepx,stepy,stepz,res);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 796:
#line 10684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (3)  First  vector field v1
        (5)  Second vector field v2
        (7)  Third  vector field v3
        (9)  step in X dimension
        (11) step in Y dimension
        (13) step in Z dimension
        (15) resolution
        (17) RGB image for the colors
        (19) mask image

    Description:
        Create 3D ellipsoids based on 3 vector fields
    **/
      InrImage* mask    = (InrImage*) im_stack.GetLastImage();
      InrImage* colors  = (InrImage*) im_stack.GetLastImage();
      InrImage* v3      = (InrImage*) im_stack.GetLastImage();
      InrImage* v2      = (InrImage*) im_stack.GetLastImage();
      InrImage* v1      = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yyvsp[(9) - (20)].adouble);
      int stepy   = (int) (yyvsp[(11) - (20)].adouble);
      int stepz   = (int) (yyvsp[(13) - (20)].adouble);
      int res     = (int) (yyvsp[(15) - (20)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1,v2,v3,stepx,stepy,stepz,res,colors,mask);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete v1;
     delete v2;
     delete v3;
        ;}
    break;

  case 798:
#line 10729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_INT \n ");         ;}
    break;

  case 799:
#line 10731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_FLOAT \n ");       ;}
    break;

  case 800:
#line 10733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_IMAGE \n ");
          (yyval.variable)=(yyvsp[(1) - (1)].variable);
        ;}
    break;

  case 801:
#line 10737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_IMAGEDRAW \n ");   ;}
    break;

  case 802:
#line 10739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_SURFACE \n ");     ;}
    break;

  case 803:
#line 10741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_SURFDRAW \n ");    ;}
    break;

  case 804:
#line 10743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_FILE \n ");        ;}
    break;

  case 805:
#line 10745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_FUNCTION \n ");  ;}
    break;

  case 806:
#line 10747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_PROCEDURE \n ");  ;}
    break;

  case 807:
#line 10749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_IMAGE_FUNCTION \n ");  ;}
    break;

  case 808:
#line 10751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_AMI_FUNCTION \n ");;}
    break;

  case 809:
#line 10753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_STRING \n ");      ;}
    break;

  case 810:
#line 10755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_MATRIX \n ");      ;}
    break;

  case 811:
#line 10757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_GLTRANSFORM \n "); ;}
    break;

  case 812:
#line 10759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_PARAMWIN \n ");    ;}
    break;

  case 813:
#line 10761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_ARRAY_SURFACE \n ");       ;}
    break;

  case 814:
#line 10763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_ARRAY_IMAGE \n ");       ;}
    break;

  case 815:
#line 10769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent( (float)(yyvsp[(1) - (11)].adouble),(float)(yyvsp[(3) - (11)].adouble),(float)(yyvsp[(5) - (11)].adouble),
                              (float)(yyvsp[(7) - (11)].adouble),(float)(yyvsp[(9) - (11)].adouble),(float)(yyvsp[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 816:
#line 10777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent((float)(yyvsp[(1) - (7)].adouble),(float)(yyvsp[(3) - (7)].adouble),(float)(yyvsp[(5) - (7)].adouble),(float)(yyvsp[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 817:
#line 10784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

          ImageExtent* extent=new ImageExtent();
          extent->SetMode(0); // absolute
          extent->SetXmin( im->SpacePosX(0));
          extent->SetXmax( im->SpacePosX(im->DimX()-1));
          extent->SetYmin( im->SpacePosY(0));
          extent->SetYmax( im->SpacePosY(im->DimY()-1));
          extent->SetZmin( im->SpacePosZ(0));
          extent->SetZmax( im->SpacePosZ(im->DimZ()-1));
          extent->print();
          (yyval.imageextent)=extent;
       ;}
    break;

  case 818:
#line 10800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw = *(DessinImage::ptr*) ((yyvsp[(1) - (1)].variable)->Pointer());

        int xmin,xmax;
        int ymin,ymax;
        int zmin,zmax;
        string comment;

        draw->GetZoom(xmin,ymin,zmin,xmax,ymax,zmax);
        ImageExtent* extent=new ImageExtent(xmin,xmax,ymin,ymax,zmin,zmax);
        extent->SetMode(1); // relative extent

        comment = str(format(" //  subvolume [%3d:%3d, %3d:%3d, %3d:%3d] ")
            % xmin % xmax % ymin % ymax % zmin % zmax);
        if (GB_debug) cerr << "********* extent ****" << endl;
        if (yy_num_buf==1) GB_main_wxFrame->GetConsole()->IncCommand(comment);

        (yyval.imageextent)=extent;
       ;}
    break;


/* Line 1267 of yacc.c.  */
#line 19307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 10819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

#include <stdio.h>

void yyiperror(const char *s) {
/*   ---------
 */
  string tmpstr;
  if (yyiplineno) {
    tmpstr = str(format("%s:%d\t %s \n\t ==> at '%s'  \n")
      %GB_current_file.c_str()
      %yyiplineno
      %s
      %yyiptext
    );
    err_print(tmpstr.c_str());
  } else {
    tmpstr = str(format("%s \n")%s);
    err_print(tmpstr.c_str());
  } /* end else */
  fflush(stdout);
  yyERROR = 1;
} /* end yyerror */


int yyip_switch_to_file(  const char* filename)
{
  YY_BUFFER_STATE b;
  string  fullname;

  GB_current_file = filename;

  cout << "yyip_switch_to_file(" << filename << ")" << endl;
  if (yy_num_buf>=YY_MAX_BUF)
    {
      sprintf(tmp_string,
          "yyip_switch_to_file(%s) \t Too many buffers \n",
          filename);
      err_print(tmp_string);
      return 0;
    }

  // Looking for the filename
  wxFileName currentname(GetwxStr(filename));
  wxFileName newname(GetwxStr(filename));

  if (!currentname.IsOk()) {
    sprintf(tmp_string,"Problem with the filename %s\n",
                        currentname.GetFullPath().c_str());
    err_print(tmp_string);
    return 0;
  }

  // could check first if there is another extension ...
  currentname.SetExt(_T("amil"));
  //  cout << "current working directory" << wxGetCwd() << endl;
  //  cout << "current name path" << currentname.GetPath() << endl;
  //  cout << "current name full path" << currentname.GetFullPath() << endl;

  //cout << "current wd = "  <<  wxGetCwd() << endl; 
  if (!currentname.DirExists(currentname.GetPath())) 
  {
    // try with current directory
    newname.Assign(
            wxGetCwd() 
            +
            currentname.GetPathSeparator()
            +
            currentname.GetPath(),
            currentname.GetName(),_T("amil"));
  }

  if (!newname.IsFileReadable()) 
  {
    // try with AMI_SCRIPTS environment variable
    newname.Assign(GB_scripts_dir
						+
						currentname.GetPathSeparator()
						+
						currentname.GetPath(),
						currentname.GetName(),_T("amil"));
  }

  if (!newname.IsFileReadable()) {
   string mess =  (format("Error in reading %s \n") % currentname.GetFullPath().c_str()).str();
   wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),GetwxStr("Error"),wxOK | wxICON_ERROR);
   err_msg->ShowModal();
   return 0;
  }

  cout << "current name " << newname.GetFullPath() << endl;
  yyipin=fopen(newname.GetFullPath().mb_str(),"r");
  if (!yyipin) {
    string mess =  (format("Error in reading %s \n") % newname.GetFullPath().c_str()).str();
    wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),wxT("Error"),wxOK | wxICON_ERROR);
    err_msg->ShowModal();
    return 0;
  }


  b = yyip_create_buffer(yyipin,YY_BUF_SIZE);
  yyip_switch_to_buffer(b);
  yy_buf_stack[yy_num_buf]=b;
  yy_num_buf++;

  //cout << "current wd = "  <<  wxGetCwd() << endl; 
  return 1;
}

void yyip_switch_to_string( const char* st)
{
  YY_BUFFER_STATE b;

  //  for(int i=0;i<yy_num_buf;i++) printf("  ");
  //  printf("yyip_switch_to_string() \n");

  if (yy_num_buf>=YY_MAX_BUF)
    {
      sprintf(tmp_string,
    "yyip_switch_to_string(%s) \t Too many buffers \n",
    st);
      err_print(tmp_string);
      return;
    }

  //  b = yyip_scan_string(st);

  //  printf("st=*%s*  length= %d\n",st,strlen(st));

  /*
  printf("yyip_switch_to_string(%s)",st);
  printf(" %3u %3u %3u %3u ",
     st[strlen(st)-1],st[strlen(st)],st[strlen(st)+1],st[strlen(st)+2]);
  */

   b = yyip_scan_buffer((char*)st,strlen(st)+2);

  if (b!= NULL) {
    yy_buf_stack[yy_num_buf]=b;
    yy_num_buf++;
  }
  else {
    err_print("yyip_switch_to_string() error in creating buffer \n");
    printf("st=\"%s\"  length= %d\n",st,(int)strlen(st));
    fflush(stdout);
  }
}

void yyip_reinit_current_buffer()
{
  YY_BUFFER_STATE b;

  b                   = yy_buf_stack[yy_num_buf-1];
  b->yy_buf_pos       = b->yy_ch_buf;
  b->yy_n_chars       = b->yy_buf_size;
  b->yy_at_bol        = 1;
  b->yy_fill_buffer   = 0;
  b->yy_buffer_status = YY_BUFFER_NEW;

  yyip_load_buffer_state();
}

void yyip_popup_buffer()
{

  //  for(int i=0;i<yy_num_buf;i++) printf("  ");
  //  printf("yyip_popup_buffer() \n");

  if (!yy_num_buf)
    {
      sprintf(tmp_string,"yyip_popup_buffer() \t empty stack\n");
      err_print(tmp_string);
      return;
    }
  yyip_delete_buffer( yy_buf_stack[yy_num_buf-1]);
  yy_num_buf--;
  if (yy_num_buf) {
    yyip_switch_to_buffer( yy_buf_stack[yy_num_buf-1]);
  }
}

void print_buf_info(YY_BUFFER_STATE b)
{
  int state;
  //int EOB; // end of buffer

  printf(" BUFFER INFO \n");
  printf("yy_ch_buf        = \"%s\" \n",  b->yy_ch_buf);
  printf("*yy_buf_pos      = '%c' \n",*(b->yy_buf_pos));
  //printf("yy_buf_pos-yy_ch_buf    = %d \n", b->yy_buf_pos-b->yy_ch_buf);
  printf("*yy_buf_size     = %d \n",  b->yy_buf_size);
  printf("yy_n_chars       = %d \n",  b->yy_n_chars);
  printf("yy_is_our_buffer = %d \n",  b->yy_is_our_buffer);
  printf("yy_is_interactive= %d \n",  b->yy_is_interactive);
  printf("yy_at_bol        = %d \n",  b->yy_at_bol);
  printf("yy_fill_buffer   = %d \n",  b->yy_fill_buffer);
  printf("yy_buffer_status = ");
  state = yy_buf_stack[yy_num_buf-1]->yy_buffer_status;
  switch (state) {
  case YY_BUFFER_NEW: printf("YY_BUFFER_NEW\n"); break;
  case YY_BUFFER_NORMAL: printf("YY_BUFFER_NORMAL\n"); break;
  case YY_BUFFER_EOF_PENDING: printf("YY_BUFFER_EOF_PENDING\n"); break;
  }
  printf("\n");
}

int is_space(char c)
{
  return ((c==' ')||(c=='\n')||(c=='\t'));
}

int continue_parse()
{
  int res=1;
  YY_BUFFER_STATE b;
  int not_only_spaces;
  char* buf_pos;

  b = yy_buf_stack[yy_num_buf-1];
  //  print_buf_info(b);

  buf_pos = b->yy_buf_pos;

  while (is_space(*buf_pos)) buf_pos++;
  not_only_spaces= ((*buf_pos)!='\0');

  if ((yy_num_buf)&&(not_only_spaces)) {
    res = yyipparse();
  }
  return res;
}

int yyip_parse()
{

  return yyipparse();
}

void init_gr_output()
{
  std::string filename(".improcess/improcess.gr");

  gr_output= FILE_ptr(fopen(filename.c_str(),"w"),file_deleter());

  if (!gr_output) {

    fprintf(stderr,"Error in opening %s\n",filename.c_str());
    FILE_ptr stdout_ptr(stdout);
    gr_output.swap(stdout_ptr);
  }
}
//void gr_print(char* st) { fprintf(gr_output,st); fflush(gr_output); }
void gr_print(const char* st) { }
//void () { fclose(gr_output); }


void init_err_output()
{
  //  char filename[100];

  err_output=&std::cerr;
  /*
  sprintf(filename,"improcess.err");
  err_output=fopen(filename,"w");
  if (!err_output) {
    fprintf(stderr,"Error in opening %s\n",filename);
    err_output=stderr;
  }
  */
}

void err_print(const char* st) {
  *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString::FromAscii(st);
  string mess =  (format("Error %s \n") % st).str();
  wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),GetwxStr("Error"),wxOK | wxICON_ERROR);
  err_msg->ShowModal();
}

void close_err_output(void)
{
 if (err_output!=&std::cerr) {}
 //fclose(err_output);
}

void init_res_output()
{
  //  char filename[100];

  res_output = &std::cout;
  /*
  sprintf(filename,"improcess.res");
  res_output=fopen(filename,"w");
  if (!res_output) {
    fprintf(stderr,"Error in opening %s\n",filename);
    err_output=stdout;
  }
  */
}
void res_print(const char* st) {
  *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString::FromAscii(st);
  printf(st);
}

void close_res_output() {
if (res_output!=&std::cout) {}
 //  fclose(res_output);
}

#include <sys/types.h>
#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif

void init_cmdhistory()
{
  std::string dirname;
  std::string filename;
  struct stat file_stat;
  int res,isdir;
  int  i;

  if (GB_nofile) return;

  // write in a local directory called .improcess
  // check if directory .improcess exists, otherwise create it
  dirname = ".improcess";
  res=stat(dirname.c_str(),&file_stat);
 	#ifndef S_ISDIR
		#define S_ISDIR(a) (a & _S_IFDIR)
	#endif
  isdir=S_ISDIR(file_stat.st_mode);
  if (!isdir)
    std::system("mkdir .improcess");

  i = 0;
  format ws_filename_format(".improcess/cmdhistory%03d");
  filename = str( ws_filename_format % i);
#ifndef F_OK
#define F_OK 0
#endif
  TantQue access( filename.c_str(), F_OK) == 0 Faire
    i++;
    filename = str( ws_filename_format % i);
  FinTantQue

  cout << format("Opening %1% \n") % filename;
  cmdhistory=FILE_ptr(fopen(filename.c_str(),"w"),file_deleter());

  // change properties to allow execution
  #ifndef WIN32
  chmod(filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
  #endif

  if (!cmdhistory) {
    cerr << format("Error in opening %s\n") % filename;
    FILE_ptr stdout_ptr = FILE_ptr(stdout);
    cmdhistory.swap(stdout_ptr);
  } else
    cmdhistory_filename = filename;
}


void ws_print(const char* st)
{
//printf("GB_nofile = %d \n",(int)GB_nofile);
  if (GB_nofile) return;
  fprintf(cmdhistory.get(),st);
  fflush(cmdhistory.get());
}

void close_cmdhistory()
{
  if (GB_nofile) return;
  if (cmdhistory.get()!=stdout) {
    cmdhistory.reset();
    // change properties to allow execution
    #ifndef WIN32
    chmod(cmdhistory_filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
    #endif
  }
}










