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
     T_SetDebugOn = 258,
     T_SetDebugOff = 259,
     T_SetVerboseOn = 260,
     T_SetVerboseOff = 261,
     T_SetProgress = 262,
     T_argc = 263,
     T_emptyargs = 264,
     END_INSTRUCTION = 265,
     T_Image = 266,
     T_ReadRawImages = 267,
     T_Transform = 268,
     SHOW = 269,
     HELP = 270,
     QUIT = 271,
     T_HIDE = 272,
     PRINT = 273,
     PRINTN = 274,
     T_SPRINT = 275,
     ASHELL = 276,
     LS = 277,
     T_SetName = 278,
     T_GetName = 279,
     T_GetOutput = 280,
     T_GetDiffCoeff = 281,
     ASTRING = 282,
     ABLOCK = 283,
     NUMBER = 284,
     IDENTIFIER = 285,
     VAR_IMAGE = 286,
     VAR_FLOAT = 287,
     VAR_INT = 288,
     VAR_UCHAR = 289,
     VAR_STRING = 290,
     VAR_IMAGEDRAW = 291,
     VAR_SURFACE = 292,
     VAR_SURFDRAW = 293,
     VAR_MATRIX = 294,
     VAR_FILE = 295,
     VAR_C_FUNCTION = 296,
     VAR_C_PROCEDURE = 297,
     VAR_C_IMAGE_FUNCTION = 298,
     VAR_AMI_FUNCTION = 299,
     VAR_PARAMWIN = 300,
     VAR_GLTRANSFORM = 301,
     VAR_ARRAY_SURFACE = 302,
     VAR_ARRAY_IMAGE = 303,
     T_del = 304,
     ENDOP = 305,
     T_global = 306,
     T_local = 307,
     T_global_new = 308,
     T_local_new = 309,
     T_wait = 310,
     T_schedule = 311,
     T_ParamWin = 312,
     T_BeginPanel = 313,
     T_EndPanel = 314,
     T_BeginBook = 315,
     T_EndBook = 316,
     T_AddPage = 317,
     T_AddFloat = 318,
     T_AddInt = 319,
     T_CreateWin = 320,
     T_Display = 321,
     T_AddButton = 322,
     T_AddBoolean = 323,
     T_AddEnum = 324,
     T_AddEnumChoice = 325,
     T_AddString = 326,
     T_AddFilename = 327,
     T_ShowSlider = 328,
     T_SetCallback = 329,
     T_SetDragCallback = 330,
     T_BeginBox = 331,
     T_EndBox = 332,
     T_BeginHorizontal = 333,
     T_EndHorizontal = 334,
     T_redraw = 335,
     RIGHT_ASSIGN = 336,
     LEFT_ASSIGN = 337,
     ADD_ASSIGN = 338,
     SUB_ASSIGN = 339,
     MUL_ASSIGN = 340,
     DIV_ASSIGN = 341,
     MOD_ASSIGN = 342,
     AND_ASSIGN = 343,
     XOR_ASSIGN = 344,
     OR_ASSIGN = 345,
     RIGHT_OP = 346,
     INC_OP = 347,
     DEC_OP = 348,
     PTR_OP = 349,
     AND_OP = 350,
     OR_OP = 351,
     LE_OP = 352,
     GE_OP = 353,
     EQ_OP = 354,
     NE_OP = 355,
     TRANSPOSE_OP = 356,
     POINTWISE_MULT = 357,
     ASSIGN_OP = 358,
     T_COUNT = 359,
     T_MAX = 360,
     T_argmax = 361,
     T_MIN = 362,
     T_MEDIAN = 363,
     OpImage = 364,
     FILTER = 365,
     NormGrad = 366,
     T_DiscNormGrad = 367,
     T_gradient = 368,
     SecDerGrad = 369,
     SecDerGrad2 = 370,
     SubImage = 371,
     PutImage = 372,
     T_AutoCrop = 373,
     T_DiscSecDerGrad = 374,
     T_EDPdilate = 375,
     T_EDPerode = 376,
     T_EDPopen = 377,
     T_EDPclose = 378,
     AnisoGS = 379,
     AnisoSmoothGS = 380,
     T_vtkAnisoGS = 381,
     T_SetDistMap = 382,
     T_DiscMeanCurvature = 383,
     T_vtkMedian3D = 384,
     T_NULL = 385,
     T_InitTime = 386,
     T_TimeSpent = 387,
     T_EndTime = 388,
     T_LevelSetsCURV = 389,
     T_UpdateResult = 390,
     T_SetMeanCurv = 391,
     T_SetAffineCurv = 392,
     T_SetBalloonScheme = 393,
     T_SetVelocity = 394,
     T_SetExpansion = 395,
     T_SetExpansionImage = 396,
     T_SetAdvectionField = 397,
     T_SetCurvWeights = 398,
     T_GetAttachVect = 399,
     T_GetCurvature = 400,
     T_GetDistMap = 401,
     T_GetAdvection = 402,
     T_GetVelocity = 403,
     T_GetExpansion = 404,
     T_GetSkeleton = 405,
     T_SetDistMethod = 406,
     T_SetParam = 407,
     T_SetIsoContourBin = 408,
     T_SetBandTube = 409,
     T_SetThreads = 410,
     T_SaveDistMap = 411,
     T_SaveSecDerGrad = 412,
     T_SetNumGaussians = 413,
     T_SetGaussian = 414,
     T_SetProbThreshold = 415,
     T_SetILowTh = 416,
     T_SetIHighTh = 417,
     T_SetProbHighTh = 418,
     T_SetNumInitPoints = 419,
     T_SetInitPoint = 420,
     T_vtkFastMarching = 421,
     T_vtkFastMarchingTarget = 422,
     T_FluxDiffusion = 423,
     T_AnisoWeickert = 424,
     T_AnisoCW = 425,
     T_SRAD_qcoeff = 426,
     T_AnisoSRAD = 427,
     T_AnisoSRAD2 = 428,
     T_AnisoLeeAdd2 = 429,
     T_AnisoDPAD = 430,
     T_AnisoDPAD2 = 431,
     T_AnisoNRAD = 432,
     T_AnisoRudinMult = 433,
     TInit = 434,
     TSetCoeff = 435,
     TIterate = 436,
     TEnd = 437,
     TAddGaussNoise = 438,
     T_SNR = 439,
     T_SetNoiseType = 440,
     T_SetNoiseSD = 441,
     T_GetNoiseSD = 442,
     T_GetDAcoeff = 443,
     T_SetMask = 444,
     T_SetSRADROI = 445,
     T_SetRNRADROI = 446,
     T_SetRNRADROI_NEW = 447,
     T_SetLocalStruct = 448,
     T_SetEigenMode = 449,
     T_Setdt = 450,
     T_Setneighborhood = 451,
     T_info = 452,
     T_NbPoints = 453,
     T_NbPolys = 454,
     T_save = 455,
     T_normalize = 456,
     T_OrientField = 457,
     T_OrientPositive = 458,
     T_2DFlux = 459,
     T_OutFlux = 460,
     T_OutFluxScalar = 461,
     T_OrientationRatio = 462,
     T_Skeleton = 463,
     T_SimplePoints = 464,
     T_CircleIntegral = 465,
     T_CircleIntegralExc = 466,
     T_CircleIntSdExc = 467,
     T_CircleMinIntSdExc = 468,
     T_LocalExtrema = 469,
     T_NormalField = 470,
     T_DirConnectivity = 471,
     T_eccentricity = 472,
     T_rot2D = 473,
     T_mean = 474,
     T_SUM = 475,
     T_localmean = 476,
     T_localmean2 = 477,
     T_localSD = 478,
     T_localSD2 = 479,
     T_struct_tensor = 480,
     T_StructTensorH = 481,
     T_HessianMatrix = 482,
     T_HessianEVal = 483,
     T_Derivatives = 484,
     T_curvatures = 485,
     T_Laplacian = 486,
     T_setvoxelsize = 487,
     T_settranslation = 488,
     T_setendianness = 489,
     T_Skeleton2lines = 490,
     T_SmoothLines = 491,
     T_ResampleLines = 492,
     T_RemoveLine = 493,
     T_ConnectLines = 494,
     T_threscross = 495,
     T_IsocontourPoints = 496,
     T_IsosurfDist = 497,
     T_vtkIsoContourDist = 498,
     T_ShortestPath = 499,
     T_ShortestPathImage = 500,
     T_PathFromDispl = 501,
     T_PathFromVectField = 502,
     T_LineRecons = 503,
     T_ReadCTALine = 504,
     T_ReadCTALineRadii = 505,
     T_WriteCTALine = 506,
     T_SetIsoContour = 507,
     T_SetIsoContourParam = 508,
     T_DrawIsoContour = 509,
     T_SetIsoContourColor = 510,
     T_DrawAllContours = 511,
     T_AllContoursParam = 512,
     T_GetZmin = 513,
     T_GetZmax = 514,
     T_GetYmin = 515,
     T_GetYmax = 516,
     T_GetXmin = 517,
     T_GetXmax = 518,
     T_GetXPos = 519,
     T_GetYPos = 520,
     T_GetZPos = 521,
     T_vtkDicomRead = 522,
     T_vtkMINCRead = 523,
     T_Convolve = 524,
     T_ConvolveMask = 525,
     T_Pad = 526,
     T_Eigen2D = 527,
     T_Eigen3D = 528,
     T_ChamferDT = 529,
     T_Chamfer2DT = 530,
     T_BorgeforsDT = 531,
     T_BorgeforsSDT = 532,
     T_vtkSignedBorgefors = 533,
     T_vtkSignedFMDist = 534,
     T_PropagationDist = 535,
     T_PropagationDist2 = 536,
     T_PropDanielsson = 537,
     T_vtkPropDanielsson = 538,
     T_vtkPropDaniel2 = 539,
     T_CC = 540,
     T_ProcessXEvents = 541,
     T_ProcessEvents = 542,
     T_isoarea2D = 543,
     T_posarea = 544,
     T_isosurf = 545,
     T_isosurf_inv = 546,
     T_isosurf_ijk = 547,
     T_isosurf_ras = 548,
     T_vtkDecimate = 549,
     T_vtkMarchingCubes = 550,
     T_vtkSmooth = 551,
     T_Recompute = 552,
     T_vtkWindowedSinc = 553,
     T_isoline = 554,
     T_vtkDist = 555,
     T_AndreDist = 556,
     T_Surface = 557,
     T_getimage = 558,
     T_GetImageFromX = 559,
     T_rotate = 560,
     T_computeCC = 561,
     T_drawCC = 562,
     T_setminCC = 563,
     T_addobj = 564,
     T_setcurrentobj = 565,
     T_writeVRML = 566,
     T_writeVTK = 567,
     T_OwnMaterial = 568,
     T_SetColor = 569,
     T_SetColors = 570,
     T_SetColorOpacity = 571,
     T_Paint = 572,
     T_SetLight = 573,
     T_SetLightPos = 574,
     T_SetLightAmbient = 575,
     T_SetLightDiffuse = 576,
     T_SetLightSpecular = 577,
     T_SetBackground = 578,
     T_Remove = 579,
     T_SwapBuffers = 580,
     T_SetAmbient = 581,
     T_SetDiffuse = 582,
     T_SetSpecular = 583,
     T_SetShininess = 584,
     T_SetOpacity = 585,
     T_SetOpacityImage = 586,
     T_SetVisible = 587,
     T_SetColorMaterial = 588,
     T_penguin = 589,
     T_Statistics = 590,
     T_GetIntensities = 591,
     T_GetLinesLength = 592,
     T_GetLinesExtremities = 593,
     T_GetConnections = 594,
     T_SelectLines = 595,
     T_RemoveSelection = 596,
     T_mergepoints = 597,
     T_Triangulate = 598,
     T_Displace = 599,
     T_Normals = 600,
     T_InvertNormals = 601,
     T_Translate = 602,
     T_Scale = 603,
     T_SetPointsColors = 604,
     T_SetLineWidth = 605,
     T_AddPoint = 606,
     T_NewLine = 607,
     T_EndLine = 608,
     T_LineAddPointNumber = 609,
     T_GetTransform = 610,
     T_SetTransform = 611,
     T_Interpolate = 612,
     T_Matrix = 613,
     T_Invert = 614,
     T_PrintMatrices = 615,
     SET = 616,
     SETPOS = 617,
     SHOWCURSOR = 618,
     UPDATE = 619,
     COMPARE = 620,
     SETVECTOR = 621,
     T_SetCompareDisplacement = 622,
     T_DrawVector = 623,
     T_DisplayVectors = 624,
     T_SetVectParam = 625,
     T_SetVectColor = 626,
     T_SetVectStyle = 627,
     T_SetLineThickness = 628,
     T_SetZoom = 629,
     T_SetWindowSize = 630,
     T_SetColormap = 631,
     T_drawcircle = 632,
     T_setGLwin = 633,
     T_initvalue = 634,
     T_ShowSection = 635,
     T_HideSection = 636,
     T_Xpos = 637,
     T_Ypos = 638,
     T_Zpos = 639,
     T_SpacePos = 640,
     T_CHAR = 641,
     T_UCHAR = 642,
     T_SHORT = 643,
     T_USHORT = 644,
     T_INT = 645,
     T_UINT = 646,
     T_FLOAT = 647,
     T_DOUBLE = 648,
     T_RGB = 649,
     T_FLOAT_VECTOR = 650,
     T_GetFormat = 651,
     T_atof = 652,
     T_gnuplot = 653,
     T_histo = 654,
     T_cumhisto = 655,
     T_DisplayHisto = 656,
     T_OPEN = 657,
     T_CLOSE = 658,
     T_scan_float = 659,
     T_read = 660,
     T_rewind = 661,
     T_LineNumber = 662,
     CONST_PI = 663,
     SIN = 664,
     COS = 665,
     TAN = 666,
     ASIN = 667,
     ACOS = 668,
     ATAN = 669,
     SINH = 670,
     COSH = 671,
     EXP = 672,
     LN = 673,
     LOG = 674,
     SQRT = 675,
     ABS = 676,
     ROUND = 677,
     FLOOR = 678,
     NORM = 679,
     FOR = 680,
     TO = 681,
     STEP = 682,
     ENDFOR = 683,
     T_REPEAT = 684,
     T_UNTIL = 685,
     T_BREAK = 686,
     IF = 687,
     THEN = 688,
     ELSE = 689,
     VARIABLES = 690,
     FUNCTION = 691,
     T_exists = 692,
     T_slice = 693,
     T_GenRead = 694,
     T_IMAGE = 695,
     T_IMAGEDRAW = 696,
     T_SURFACE = 697,
     T_NUM = 698,
     T_STRING = 699,
     T_TRANSFORM = 700,
     T_PROC = 701,
     T_MeanHalfSize = 702,
     T_Resize = 703,
     T_ReSlice = 704,
     T_Flip = 705,
     T_SetCompTransf = 706,
     T_ConvexHull = 707,
     T_itk = 708,
     T_CannyEdgeDetector = 709,
     T_CreateFlatMesh = 710,
     T_CreateVolume = 711,
     T_vtkCreateFlatMesh = 712,
     T_Altitude2Position = 713,
     T_GeoCoordinates = 714,
     T_ElevateMesh = 715,
     T_CreateVectors = 716,
     T_Set3DArrowParam = 717,
     T_CreateEllipsoids = 718,
     T_ComputeAltitudes = 719,
     T_Temp2Altitudes = 720,
     T_ReadFlow = 721,
     T_SetFluidNavFile = 722,
     T_DrawEarthCoord = 723,
     T_PaintCallback = 724,
     T_SaveStructuredGrid = 725,
     T_import_ami = 726,
     T_import_vtk = 727,
     T_import_itk = 728,
     T_import_wii = 729,
     T_import_filters = 730,
     T_amiOFCorr2D = 731,
     T_amiOFVar2D = 732
   };
#endif
/* Tokens.  */
#define T_SetDebugOn 258
#define T_SetDebugOff 259
#define T_SetVerboseOn 260
#define T_SetVerboseOff 261
#define T_SetProgress 262
#define T_argc 263
#define T_emptyargs 264
#define END_INSTRUCTION 265
#define T_Image 266
#define T_ReadRawImages 267
#define T_Transform 268
#define SHOW 269
#define HELP 270
#define QUIT 271
#define T_HIDE 272
#define PRINT 273
#define PRINTN 274
#define T_SPRINT 275
#define ASHELL 276
#define LS 277
#define T_SetName 278
#define T_GetName 279
#define T_GetOutput 280
#define T_GetDiffCoeff 281
#define ASTRING 282
#define ABLOCK 283
#define NUMBER 284
#define IDENTIFIER 285
#define VAR_IMAGE 286
#define VAR_FLOAT 287
#define VAR_INT 288
#define VAR_UCHAR 289
#define VAR_STRING 290
#define VAR_IMAGEDRAW 291
#define VAR_SURFACE 292
#define VAR_SURFDRAW 293
#define VAR_MATRIX 294
#define VAR_FILE 295
#define VAR_C_FUNCTION 296
#define VAR_C_PROCEDURE 297
#define VAR_C_IMAGE_FUNCTION 298
#define VAR_AMI_FUNCTION 299
#define VAR_PARAMWIN 300
#define VAR_GLTRANSFORM 301
#define VAR_ARRAY_SURFACE 302
#define VAR_ARRAY_IMAGE 303
#define T_del 304
#define ENDOP 305
#define T_global 306
#define T_local 307
#define T_global_new 308
#define T_local_new 309
#define T_wait 310
#define T_schedule 311
#define T_ParamWin 312
#define T_BeginPanel 313
#define T_EndPanel 314
#define T_BeginBook 315
#define T_EndBook 316
#define T_AddPage 317
#define T_AddFloat 318
#define T_AddInt 319
#define T_CreateWin 320
#define T_Display 321
#define T_AddButton 322
#define T_AddBoolean 323
#define T_AddEnum 324
#define T_AddEnumChoice 325
#define T_AddString 326
#define T_AddFilename 327
#define T_ShowSlider 328
#define T_SetCallback 329
#define T_SetDragCallback 330
#define T_BeginBox 331
#define T_EndBox 332
#define T_BeginHorizontal 333
#define T_EndHorizontal 334
#define T_redraw 335
#define RIGHT_ASSIGN 336
#define LEFT_ASSIGN 337
#define ADD_ASSIGN 338
#define SUB_ASSIGN 339
#define MUL_ASSIGN 340
#define DIV_ASSIGN 341
#define MOD_ASSIGN 342
#define AND_ASSIGN 343
#define XOR_ASSIGN 344
#define OR_ASSIGN 345
#define RIGHT_OP 346
#define INC_OP 347
#define DEC_OP 348
#define PTR_OP 349
#define AND_OP 350
#define OR_OP 351
#define LE_OP 352
#define GE_OP 353
#define EQ_OP 354
#define NE_OP 355
#define TRANSPOSE_OP 356
#define POINTWISE_MULT 357
#define ASSIGN_OP 358
#define T_COUNT 359
#define T_MAX 360
#define T_argmax 361
#define T_MIN 362
#define T_MEDIAN 363
#define OpImage 364
#define FILTER 365
#define NormGrad 366
#define T_DiscNormGrad 367
#define T_gradient 368
#define SecDerGrad 369
#define SecDerGrad2 370
#define SubImage 371
#define PutImage 372
#define T_AutoCrop 373
#define T_DiscSecDerGrad 374
#define T_EDPdilate 375
#define T_EDPerode 376
#define T_EDPopen 377
#define T_EDPclose 378
#define AnisoGS 379
#define AnisoSmoothGS 380
#define T_vtkAnisoGS 381
#define T_SetDistMap 382
#define T_DiscMeanCurvature 383
#define T_vtkMedian3D 384
#define T_NULL 385
#define T_InitTime 386
#define T_TimeSpent 387
#define T_EndTime 388
#define T_LevelSetsCURV 389
#define T_UpdateResult 390
#define T_SetMeanCurv 391
#define T_SetAffineCurv 392
#define T_SetBalloonScheme 393
#define T_SetVelocity 394
#define T_SetExpansion 395
#define T_SetExpansionImage 396
#define T_SetAdvectionField 397
#define T_SetCurvWeights 398
#define T_GetAttachVect 399
#define T_GetCurvature 400
#define T_GetDistMap 401
#define T_GetAdvection 402
#define T_GetVelocity 403
#define T_GetExpansion 404
#define T_GetSkeleton 405
#define T_SetDistMethod 406
#define T_SetParam 407
#define T_SetIsoContourBin 408
#define T_SetBandTube 409
#define T_SetThreads 410
#define T_SaveDistMap 411
#define T_SaveSecDerGrad 412
#define T_SetNumGaussians 413
#define T_SetGaussian 414
#define T_SetProbThreshold 415
#define T_SetILowTh 416
#define T_SetIHighTh 417
#define T_SetProbHighTh 418
#define T_SetNumInitPoints 419
#define T_SetInitPoint 420
#define T_vtkFastMarching 421
#define T_vtkFastMarchingTarget 422
#define T_FluxDiffusion 423
#define T_AnisoWeickert 424
#define T_AnisoCW 425
#define T_SRAD_qcoeff 426
#define T_AnisoSRAD 427
#define T_AnisoSRAD2 428
#define T_AnisoLeeAdd2 429
#define T_AnisoDPAD 430
#define T_AnisoDPAD2 431
#define T_AnisoNRAD 432
#define T_AnisoRudinMult 433
#define TInit 434
#define TSetCoeff 435
#define TIterate 436
#define TEnd 437
#define TAddGaussNoise 438
#define T_SNR 439
#define T_SetNoiseType 440
#define T_SetNoiseSD 441
#define T_GetNoiseSD 442
#define T_GetDAcoeff 443
#define T_SetMask 444
#define T_SetSRADROI 445
#define T_SetRNRADROI 446
#define T_SetRNRADROI_NEW 447
#define T_SetLocalStruct 448
#define T_SetEigenMode 449
#define T_Setdt 450
#define T_Setneighborhood 451
#define T_info 452
#define T_NbPoints 453
#define T_NbPolys 454
#define T_save 455
#define T_normalize 456
#define T_OrientField 457
#define T_OrientPositive 458
#define T_2DFlux 459
#define T_OutFlux 460
#define T_OutFluxScalar 461
#define T_OrientationRatio 462
#define T_Skeleton 463
#define T_SimplePoints 464
#define T_CircleIntegral 465
#define T_CircleIntegralExc 466
#define T_CircleIntSdExc 467
#define T_CircleMinIntSdExc 468
#define T_LocalExtrema 469
#define T_NormalField 470
#define T_DirConnectivity 471
#define T_eccentricity 472
#define T_rot2D 473
#define T_mean 474
#define T_SUM 475
#define T_localmean 476
#define T_localmean2 477
#define T_localSD 478
#define T_localSD2 479
#define T_struct_tensor 480
#define T_StructTensorH 481
#define T_HessianMatrix 482
#define T_HessianEVal 483
#define T_Derivatives 484
#define T_curvatures 485
#define T_Laplacian 486
#define T_setvoxelsize 487
#define T_settranslation 488
#define T_setendianness 489
#define T_Skeleton2lines 490
#define T_SmoothLines 491
#define T_ResampleLines 492
#define T_RemoveLine 493
#define T_ConnectLines 494
#define T_threscross 495
#define T_IsocontourPoints 496
#define T_IsosurfDist 497
#define T_vtkIsoContourDist 498
#define T_ShortestPath 499
#define T_ShortestPathImage 500
#define T_PathFromDispl 501
#define T_PathFromVectField 502
#define T_LineRecons 503
#define T_ReadCTALine 504
#define T_ReadCTALineRadii 505
#define T_WriteCTALine 506
#define T_SetIsoContour 507
#define T_SetIsoContourParam 508
#define T_DrawIsoContour 509
#define T_SetIsoContourColor 510
#define T_DrawAllContours 511
#define T_AllContoursParam 512
#define T_GetZmin 513
#define T_GetZmax 514
#define T_GetYmin 515
#define T_GetYmax 516
#define T_GetXmin 517
#define T_GetXmax 518
#define T_GetXPos 519
#define T_GetYPos 520
#define T_GetZPos 521
#define T_vtkDicomRead 522
#define T_vtkMINCRead 523
#define T_Convolve 524
#define T_ConvolveMask 525
#define T_Pad 526
#define T_Eigen2D 527
#define T_Eigen3D 528
#define T_ChamferDT 529
#define T_Chamfer2DT 530
#define T_BorgeforsDT 531
#define T_BorgeforsSDT 532
#define T_vtkSignedBorgefors 533
#define T_vtkSignedFMDist 534
#define T_PropagationDist 535
#define T_PropagationDist2 536
#define T_PropDanielsson 537
#define T_vtkPropDanielsson 538
#define T_vtkPropDaniel2 539
#define T_CC 540
#define T_ProcessXEvents 541
#define T_ProcessEvents 542
#define T_isoarea2D 543
#define T_posarea 544
#define T_isosurf 545
#define T_isosurf_inv 546
#define T_isosurf_ijk 547
#define T_isosurf_ras 548
#define T_vtkDecimate 549
#define T_vtkMarchingCubes 550
#define T_vtkSmooth 551
#define T_Recompute 552
#define T_vtkWindowedSinc 553
#define T_isoline 554
#define T_vtkDist 555
#define T_AndreDist 556
#define T_Surface 557
#define T_getimage 558
#define T_GetImageFromX 559
#define T_rotate 560
#define T_computeCC 561
#define T_drawCC 562
#define T_setminCC 563
#define T_addobj 564
#define T_setcurrentobj 565
#define T_writeVRML 566
#define T_writeVTK 567
#define T_OwnMaterial 568
#define T_SetColor 569
#define T_SetColors 570
#define T_SetColorOpacity 571
#define T_Paint 572
#define T_SetLight 573
#define T_SetLightPos 574
#define T_SetLightAmbient 575
#define T_SetLightDiffuse 576
#define T_SetLightSpecular 577
#define T_SetBackground 578
#define T_Remove 579
#define T_SwapBuffers 580
#define T_SetAmbient 581
#define T_SetDiffuse 582
#define T_SetSpecular 583
#define T_SetShininess 584
#define T_SetOpacity 585
#define T_SetOpacityImage 586
#define T_SetVisible 587
#define T_SetColorMaterial 588
#define T_penguin 589
#define T_Statistics 590
#define T_GetIntensities 591
#define T_GetLinesLength 592
#define T_GetLinesExtremities 593
#define T_GetConnections 594
#define T_SelectLines 595
#define T_RemoveSelection 596
#define T_mergepoints 597
#define T_Triangulate 598
#define T_Displace 599
#define T_Normals 600
#define T_InvertNormals 601
#define T_Translate 602
#define T_Scale 603
#define T_SetPointsColors 604
#define T_SetLineWidth 605
#define T_AddPoint 606
#define T_NewLine 607
#define T_EndLine 608
#define T_LineAddPointNumber 609
#define T_GetTransform 610
#define T_SetTransform 611
#define T_Interpolate 612
#define T_Matrix 613
#define T_Invert 614
#define T_PrintMatrices 615
#define SET 616
#define SETPOS 617
#define SHOWCURSOR 618
#define UPDATE 619
#define COMPARE 620
#define SETVECTOR 621
#define T_SetCompareDisplacement 622
#define T_DrawVector 623
#define T_DisplayVectors 624
#define T_SetVectParam 625
#define T_SetVectColor 626
#define T_SetVectStyle 627
#define T_SetLineThickness 628
#define T_SetZoom 629
#define T_SetWindowSize 630
#define T_SetColormap 631
#define T_drawcircle 632
#define T_setGLwin 633
#define T_initvalue 634
#define T_ShowSection 635
#define T_HideSection 636
#define T_Xpos 637
#define T_Ypos 638
#define T_Zpos 639
#define T_SpacePos 640
#define T_CHAR 641
#define T_UCHAR 642
#define T_SHORT 643
#define T_USHORT 644
#define T_INT 645
#define T_UINT 646
#define T_FLOAT 647
#define T_DOUBLE 648
#define T_RGB 649
#define T_FLOAT_VECTOR 650
#define T_GetFormat 651
#define T_atof 652
#define T_gnuplot 653
#define T_histo 654
#define T_cumhisto 655
#define T_DisplayHisto 656
#define T_OPEN 657
#define T_CLOSE 658
#define T_scan_float 659
#define T_read 660
#define T_rewind 661
#define T_LineNumber 662
#define CONST_PI 663
#define SIN 664
#define COS 665
#define TAN 666
#define ASIN 667
#define ACOS 668
#define ATAN 669
#define SINH 670
#define COSH 671
#define EXP 672
#define LN 673
#define LOG 674
#define SQRT 675
#define ABS 676
#define ROUND 677
#define FLOOR 678
#define NORM 679
#define FOR 680
#define TO 681
#define STEP 682
#define ENDFOR 683
#define T_REPEAT 684
#define T_UNTIL 685
#define T_BREAK 686
#define IF 687
#define THEN 688
#define ELSE 689
#define VARIABLES 690
#define FUNCTION 691
#define T_exists 692
#define T_slice 693
#define T_GenRead 694
#define T_IMAGE 695
#define T_IMAGEDRAW 696
#define T_SURFACE 697
#define T_NUM 698
#define T_STRING 699
#define T_TRANSFORM 700
#define T_PROC 701
#define T_MeanHalfSize 702
#define T_Resize 703
#define T_ReSlice 704
#define T_Flip 705
#define T_SetCompTransf 706
#define T_ConvexHull 707
#define T_itk 708
#define T_CannyEdgeDetector 709
#define T_CreateFlatMesh 710
#define T_CreateVolume 711
#define T_vtkCreateFlatMesh 712
#define T_Altitude2Position 713
#define T_GeoCoordinates 714
#define T_ElevateMesh 715
#define T_CreateVectors 716
#define T_Set3DArrowParam 717
#define T_CreateEllipsoids 718
#define T_ComputeAltitudes 719
#define T_Temp2Altitudes 720
#define T_ReadFlow 721
#define T_SetFluidNavFile 722
#define T_DrawEarthCoord 723
#define T_PaintCallback 724
#define T_SaveStructuredGrid 725
#define T_import_ami 726
#define T_import_vtk 727
#define T_import_itk 728
#define T_import_wii 729
#define T_import_filters 730
#define T_amiOFCorr2D 731
#define T_amiOFVar2D 732




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
#line 1508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#define YYNTOKENS  498
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  818
/* YYNRULES -- Number of states.  */
#define YYNSTATES  3254

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   732

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   489,     2,     2,     2,     2,   486,     2,
     479,   480,   490,   487,   481,   488,   484,   492,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   485,   478,
     493,     2,   494,   497,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   482,     2,   483,   495,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   496,     2,   491,     2,     2,     2,
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
     475,   476,   477
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
     499,     0,    -1,   500,    -1,   499,   500,    -1,   505,   500,
      -1,   499,   505,   500,    -1,   501,    -1,   499,   501,    -1,
     502,    -1,   499,   502,    -1,   504,    -1,   499,   504,    -1,
     503,    -1,   499,   503,    -1,    10,    -1,   478,    -1,   425,
     575,   103,   532,   426,   532,   512,   500,    -1,   425,   575,
     103,   532,   426,   532,   427,   532,   512,   500,    -1,   429,
     512,    -1,   432,   532,   512,   500,    -1,   432,   532,   512,
     434,   512,   500,    -1,   446,   575,   479,   507,   480,   512,
     500,    -1,   436,    27,   500,    -1,   436,    -1,    44,   479,
     506,   480,   500,    -1,    44,   500,    -1,     9,    -1,   431,
      -1,    51,    -1,    53,    -1,    54,    -1,    52,    -1,    55,
     479,   532,   480,    -1,    56,   479,   532,   481,    44,   480,
      -1,   575,   103,   302,   482,   532,   483,    -1,   575,    82,
     302,   482,   532,   483,    -1,   575,   103,    11,   482,   532,
     483,    -1,   575,   103,   553,    -1,   575,    82,   553,    -1,
     575,   103,    41,   479,   506,   480,    -1,    48,   482,   532,
     483,   103,   553,    -1,   575,   103,   572,    -1,   575,   103,
     554,    -1,    39,   103,   532,    -1,    39,   103,   572,    -1,
      47,   482,   532,   483,   103,   574,    -1,   575,   103,   574,
      -1,   573,    82,   574,    -1,    47,    82,   302,   482,   532,
     483,    -1,   575,   103,   390,   479,   532,   480,    -1,   575,
     103,   387,   479,   532,   480,    -1,   575,   103,   532,    -1,
     575,   103,   511,    -1,   575,   103,   402,   479,   511,   481,
      27,   480,    -1,    40,   103,   402,   479,   511,   481,    27,
     480,    -1,    40,   484,   406,    -1,     3,    -1,     4,    -1,
       5,    -1,     6,    -1,     7,   479,   532,   480,    -1,    16,
      -1,    14,   534,    -1,    17,   534,    -1,    14,   573,    -1,
     334,    -1,   534,   103,   553,    -1,   534,    82,   553,    -1,
     534,   103,   532,    -1,   534,   482,   532,   483,   103,   553,
      -1,   534,   482,   532,   483,   103,   532,    -1,   534,   479,
     532,   485,   532,   481,   532,   485,   532,   481,   532,   485,
     532,   480,   103,   553,    -1,    32,    92,    -1,    32,    93,
      -1,    32,   103,   532,    -1,    33,    92,    -1,    33,    93,
      -1,    33,   103,   532,    -1,    34,   103,   532,    -1,    34,
      92,    -1,    34,    93,    -1,    35,   103,   511,    -1,    14,
     435,    -1,    49,   576,    -1,    49,    47,   482,   532,   483,
      -1,    21,   511,    -1,    22,    -1,    15,    -1,    15,   575,
      -1,    15,    27,    -1,    40,   484,    18,   511,    -1,    18,
     511,    -1,    19,   511,    -1,    18,   572,    -1,   572,    -1,
      40,   484,    18,   532,    -1,    40,   484,   403,    -1,    18,
     532,    -1,    19,   532,    -1,    36,   484,   362,   479,   532,
     481,   532,   481,   532,   480,    -1,    36,   484,   363,   479,
     532,   480,    -1,    36,   484,   364,    -1,    36,   484,   365,
     479,   534,   480,    -1,    36,   484,   365,   479,    36,   480,
      -1,    36,   484,   367,   479,    36,   481,   534,   480,    -1,
      36,   484,   451,   479,   532,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   480,    -1,    36,
     484,   366,   479,    29,   481,   534,   480,    -1,    36,   484,
     368,   479,   532,   481,   532,   480,    -1,    36,   484,   369,
      -1,    36,   484,   370,   479,   532,   481,   532,   480,    -1,
      36,   484,   371,   479,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,    36,   484,   372,   479,   532,   480,    -1,
      36,   484,   373,   479,   532,   480,    -1,    36,   484,   374,
     479,   532,   481,   532,   481,   532,   481,   532,   481,   532,
     481,   532,   480,    -1,    36,   484,   375,   479,   532,   481,
     532,   480,    -1,    36,   484,   377,   479,   532,   481,   532,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
      36,   484,   376,   479,   553,   481,   532,   481,   532,   480,
      -1,    36,   484,   378,   479,    38,   480,    -1,    36,   484,
     252,   479,   532,   481,   534,   481,   532,   480,    -1,    36,
     484,   252,   479,   534,   481,   532,   480,    -1,    36,   484,
     253,   479,   532,   481,   532,   481,   532,   480,    -1,    36,
     484,   253,   479,   532,   481,   532,   481,   532,   481,   532,
     481,   532,   480,    -1,    36,   484,   254,   479,   532,   481,
     532,   480,    -1,    36,   484,   255,   479,   532,   481,   532,
     481,   532,   481,   532,   480,    -1,    36,   484,   256,   479,
     532,   480,    -1,    36,   484,   257,   479,   532,   481,   532,
     480,    -1,    36,   484,   469,   479,    44,   480,    -1,    36,
     484,   331,   479,   534,   480,    -1,   534,   484,   379,   479,
     532,   480,    -1,   534,   484,   379,   479,   532,   481,   532,
     481,   532,   480,    -1,   534,   484,   361,   479,   532,   480,
      -1,   534,   484,   361,   479,   532,   481,   532,   481,   532,
     480,    -1,   534,   484,   362,   479,   532,   481,   532,   481,
     532,   480,    -1,   534,   484,   117,   479,   534,   481,   532,
     481,   532,   481,   532,   480,    -1,   534,   484,   117,   479,
     534,   480,    -1,   534,   484,    23,   479,   511,   480,    -1,
     124,   484,   179,   479,   534,   481,   532,   481,   532,   481,
     532,   480,    -1,   124,   484,   180,   479,   532,   480,    -1,
     124,   484,   127,   479,   532,   480,    -1,   124,   484,   185,
     479,   532,   480,    -1,   124,   484,   186,   479,   532,   480,
      -1,   124,   484,   189,   479,   534,   480,    -1,   124,   484,
     190,   479,   534,   480,    -1,   124,   484,   191,   479,   534,
     480,    -1,   124,   484,   192,   479,   534,   480,    -1,   124,
     484,   193,   479,   532,   480,    -1,   124,   484,   194,   479,
     532,   480,    -1,   124,   484,   195,   479,   532,   480,    -1,
     124,   484,   196,   479,   532,   480,    -1,   124,   484,   180,
     479,   532,   481,   532,   480,    -1,   124,   484,   181,    -1,
     124,   484,   182,    -1,   169,   484,   181,    -1,   169,   484,
     182,    -1,   170,   484,   181,    -1,   170,   484,   182,    -1,
     134,   484,   152,   479,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   134,   484,   152,   479,   532,   481,   532,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     134,   484,   136,   479,   532,   480,    -1,   134,   484,   137,
     479,   532,   480,    -1,   134,   484,   138,   479,   532,   480,
      -1,   134,   484,   151,   479,   532,   480,    -1,   134,   484,
     155,   479,   532,   480,    -1,   134,   484,   160,   479,   532,
     480,    -1,   134,   484,   161,   479,   532,   480,    -1,   134,
     484,   162,   479,   532,   480,    -1,   134,   484,   163,   479,
     532,   480,    -1,   134,   484,   158,   479,   532,   480,    -1,
     134,   484,   159,   479,   532,   481,   532,   481,   532,   480,
      -1,   134,   484,   164,   479,   532,   480,    -1,   134,   484,
     165,   479,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   134,   484,   153,   479,   532,   480,    -1,
     134,   484,   139,   479,   534,   481,   532,   480,    -1,   134,
     484,   140,   479,   532,   480,    -1,   134,   484,   141,   479,
     534,   480,    -1,   134,   484,   154,   479,   532,   481,   532,
     480,    -1,   134,   484,   143,   479,   534,   480,    -1,   134,
     484,   142,   479,   534,   481,   534,   481,   534,   480,    -1,
     134,   484,   145,   479,   534,   480,    -1,   134,   484,   146,
     479,   534,   480,    -1,   134,   484,   147,   479,   534,   480,
      -1,   134,   484,   150,   479,   534,   480,    -1,   134,   484,
     148,   479,   534,   480,    -1,   134,   484,   149,   479,   534,
     480,    -1,   134,   484,   145,   479,   130,   480,    -1,   134,
     484,   147,   479,   130,   480,    -1,   134,   484,   148,   479,
     130,   480,    -1,   134,   484,   156,   479,   532,   480,    -1,
     134,   484,   157,   479,   532,   480,    -1,   134,   484,   181,
      -1,   134,   484,   182,    -1,   534,   484,   200,   511,    -1,
     534,   484,   201,    -1,   534,   484,   202,   479,   534,   480,
      -1,   534,   484,   203,   479,   534,   480,    -1,   573,   484,
     200,   511,    -1,   573,   484,   251,   511,    -1,   573,   484,
     313,   479,   532,   480,    -1,   573,   484,   326,   479,   532,
     481,   532,   481,   532,   480,    -1,   573,   484,   327,   479,
     532,   481,   532,   481,   532,   480,    -1,   573,   484,   328,
     479,   532,   481,   532,   481,   532,   480,    -1,   573,   484,
     329,   479,   532,   480,    -1,   573,   484,   330,   479,   532,
     480,    -1,   573,   484,   332,   479,   532,   480,    -1,   573,
     484,   333,   479,   532,   480,    -1,   573,   484,   316,   479,
     532,   480,    -1,   573,   484,   314,   479,   532,   481,   532,
     481,   532,   480,    -1,   573,   484,   349,   479,   534,   480,
      -1,   573,   484,   315,   479,   553,   481,   532,   481,   532,
     480,    -1,   573,   484,   315,   479,   553,   480,    -1,   573,
     484,   335,   479,   534,   480,    -1,   573,   484,   342,   479,
     532,   480,    -1,   573,   484,   343,    -1,   573,   484,   230,
     479,   532,   480,    -1,   573,   484,   344,   479,   553,   480,
      -1,   573,   484,   347,   479,   532,   481,   532,   481,   532,
     480,    -1,   573,   484,   348,   479,   532,   481,   532,   481,
     532,   480,    -1,   573,   484,   350,   479,   532,   480,    -1,
     573,   484,   238,   479,   532,   480,    -1,   573,   484,   340,
     479,   553,   480,    -1,   573,   484,   341,    -1,   573,   484,
     297,    -1,   573,   484,   345,    -1,   573,   484,   346,    -1,
     573,   484,   296,   479,   532,   480,    -1,   573,   484,   298,
     479,   532,   480,    -1,   573,   484,   294,    -1,   573,   484,
     308,   479,   532,   480,    -1,   573,   484,   307,   479,   532,
     480,    -1,   573,   484,   307,   479,   532,   481,   532,   480,
      -1,   573,   484,   351,   479,   532,   481,   532,   481,   532,
     480,    -1,   573,   484,   352,    -1,   573,   484,   354,   479,
     532,   480,    -1,   573,   484,   353,    -1,   467,   479,   511,
     480,    -1,   468,   479,    36,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   573,   484,   460,   479,   553,   480,    -1,
      38,   484,   305,   479,   532,   481,   532,   481,   532,   480,
      -1,    38,   484,   309,   479,   574,   480,    -1,    38,    83,
     573,    -1,    38,    84,   573,    -1,    38,   484,   324,   479,
     573,   480,    -1,    38,   484,   325,    -1,    38,   484,   307,
     479,   532,   480,    -1,    38,   484,   307,   479,   532,   481,
     532,   480,    -1,    38,   484,   310,   479,   532,   480,    -1,
      38,   484,   365,   479,    38,   480,    -1,    38,   484,   366,
     479,    29,   481,   534,   480,    -1,    38,   484,   380,   479,
     532,   481,   553,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,    38,   484,   381,   479,   532,   480,    -1,
      38,   484,   360,    -1,    38,   484,   356,   479,   554,   480,
      -1,    38,   484,   356,   479,   554,   481,   532,   480,    -1,
      38,   484,   317,    -1,    38,   484,   320,   479,   532,   481,
     532,   481,   532,   481,   532,   480,    -1,    38,   484,   321,
     479,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
      38,   484,   322,   479,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,    38,   484,   323,   479,   532,   481,   532,
     481,   532,   480,    -1,    38,   484,   375,   479,   532,   481,
     532,   480,    -1,   225,   479,   534,   481,   532,   481,   532,
     480,    -1,   225,   479,   534,   481,   532,   481,   532,   481,
     553,   480,    -1,   226,   479,   534,   481,   532,   481,   532,
     480,    -1,   226,   479,   534,   481,   532,   481,   532,   481,
     553,   480,    -1,   226,   479,   534,   481,   532,   481,   532,
     481,   553,   481,   532,   480,    -1,   227,   479,   534,   481,
     532,   480,    -1,   227,   479,   534,   481,   532,   481,   553,
     480,    -1,   227,   479,   534,   481,   532,   481,   532,   480,
      -1,   227,   479,   534,   481,   532,   481,   532,   481,   553,
     480,    -1,   229,   479,   534,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   480,    -1,   229,
     479,   534,   481,   532,   481,   532,   481,   532,   481,   532,
     481,   532,   481,   532,   481,   553,   480,    -1,   228,   479,
     534,   481,   532,   481,   532,   481,   553,   481,   532,   480,
      -1,   230,   479,   534,   481,   532,   480,    -1,   273,   479,
      27,   481,   534,   481,   534,   481,   534,   481,   534,   481,
     534,   481,   534,   481,   553,   480,    -1,   273,   479,    27,
     481,   534,   481,   534,   481,   534,   481,   534,   481,   534,
     481,   534,   480,    -1,   272,   479,    27,   481,   534,   481,
     534,   481,   534,   481,   553,   480,    -1,   272,   479,    27,
     481,   534,   481,   534,   481,   534,   480,    -1,   232,   479,
     534,   481,   532,   481,   532,   481,   532,   480,    -1,   534,
     484,   232,   479,   532,   481,   532,   481,   532,   480,    -1,
     534,   484,   232,   479,   534,   480,    -1,   534,   484,   233,
     479,   532,   481,   532,   481,   532,   480,    -1,   534,   484,
     233,   479,   534,   480,    -1,   534,   484,   234,   479,   532,
     480,    -1,   119,   479,   534,   481,   534,   480,    -1,   119,
     479,   534,   481,   534,   481,   534,   480,    -1,   532,    -1,
     286,   479,   532,   480,    -1,   287,   479,   532,   480,    -1,
     398,   479,   553,   481,   511,   481,   532,   480,    -1,   401,
     479,   534,   480,    -1,   271,   479,   534,   481,   534,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   439,   479,    27,   480,    -1,   131,    -1,
     133,    -1,   575,   103,    57,   479,   511,   480,    -1,    45,
     484,    76,   479,   511,   480,    -1,    45,   484,    60,    -1,
      45,   484,    61,    -1,    45,   484,    62,   479,   511,   480,
      -1,    45,   484,    58,   479,   511,   480,    -1,    45,   484,
      59,    -1,    45,   484,    77,    -1,    45,   484,    78,    -1,
      45,   484,    79,    -1,    45,   484,    65,    -1,    45,   484,
      66,    -1,    45,   484,    80,    -1,    45,   484,    73,   479,
     532,   481,   532,   480,    -1,    45,   484,    74,   479,    44,
     480,    -1,    45,   484,    75,   479,   532,   480,    -1,   470,
     479,   534,   481,   511,   480,    -1,    46,   484,    18,    -1,
      46,   484,   200,   511,    -1,   471,    -1,   472,    -1,   473,
      -1,   474,    -1,   475,    -1,   476,   479,   534,   481,   534,
     481,   534,   481,   534,   481,   534,   481,   534,   481,   534,
     481,   532,   481,   532,   481,   532,   481,   532,   481,   532,
     481,   532,   481,   532,   480,    -1,   477,   479,   534,   481,
     534,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   534,   481,   534,   481,   532,   480,
      -1,    42,   479,   506,   480,    -1,   462,   479,   532,   481,
     532,   481,   532,   480,    -1,    -1,   532,    -1,   506,   481,
     532,    -1,   511,    -1,   506,   481,   511,    -1,   486,    32,
      -1,   506,   481,   486,    32,    -1,   486,    33,    -1,   506,
     481,   486,    33,    -1,   553,    -1,   506,   481,   553,    -1,
     486,   534,    -1,   506,   481,   486,   534,    -1,   486,   573,
      -1,   506,   481,   486,   573,    -1,    36,    -1,   506,   481,
      36,    -1,    -1,   443,    30,    -1,   444,    30,    -1,   440,
      30,    -1,   441,    30,    -1,   442,    30,    -1,   507,   481,
     443,    30,    -1,   507,   481,   444,    30,    -1,   507,   481,
     440,    30,    -1,   507,   481,   441,    30,    -1,   507,   481,
     442,    30,    -1,    27,    -1,    35,    -1,   508,    -1,    20,
     479,   511,   481,   532,   480,    -1,   132,    -1,   534,   484,
      24,    -1,   509,    -1,   510,   487,   509,    -1,   510,   488,
     509,    -1,   510,    -1,   513,    28,   514,    -1,    -1,    -1,
      29,    -1,     8,    -1,   407,    -1,   408,    -1,    32,    -1,
      33,    -1,    34,    -1,   479,   532,   480,    -1,   515,    -1,
     534,   479,   532,   480,    -1,   534,   479,   532,   481,   532,
     480,    -1,   534,   479,   532,   481,   532,   481,   532,   480,
      -1,   534,   479,   532,   481,   532,   481,   532,   481,   532,
     480,    -1,   534,   479,   532,   481,   532,   481,   532,   478,
     532,   480,    -1,   534,   479,   532,   481,   532,   478,   532,
     480,    -1,   534,   479,   532,   478,   532,   480,    -1,   534,
     484,   179,    -1,   534,   484,   575,    -1,   534,   484,   197,
      -1,   573,   484,   197,    -1,   573,   484,   198,    -1,   573,
     484,   199,    -1,   184,   479,   534,   481,   534,   480,    -1,
     217,   479,   534,   480,    -1,   288,   479,   534,   481,   532,
     481,   532,   481,   532,   480,    -1,   289,   479,   534,   480,
      -1,   289,   479,   532,   481,   532,   481,   532,   481,   532,
     480,    -1,   104,   479,   553,   480,    -1,   219,   479,   553,
     480,    -1,   105,   479,   534,   480,    -1,   106,   479,   553,
     480,    -1,   107,   479,   534,   480,    -1,   108,   479,   534,
     480,    -1,   105,   482,   553,   483,   479,   534,   480,    -1,
     107,   482,   553,   483,   479,   534,   480,    -1,   108,   482,
     553,   483,   479,   534,   480,    -1,   108,   482,   553,   483,
     479,   534,   481,   532,   480,    -1,   219,   482,   553,   483,
     479,   553,   480,    -1,   219,   479,   534,   481,   553,   480,
      -1,   397,   479,    27,   480,    -1,    36,   484,   262,    -1,
      36,   484,   263,    -1,    36,   484,   260,    -1,    36,   484,
     261,    -1,    36,   484,   258,    -1,    36,   484,   259,    -1,
      36,   484,   264,    -1,    36,   484,   265,    -1,    36,   484,
     266,    -1,   124,   484,   187,    -1,   124,   484,   188,    -1,
     134,   484,   135,    -1,    39,   479,   532,   481,   532,   480,
      -1,    39,   479,   532,   481,   532,   480,   103,   532,    -1,
      45,   484,    63,   479,    32,   481,   532,   481,   532,   480,
      -1,    45,   484,    64,   479,    33,   481,   532,   481,   532,
     480,    -1,    45,   484,    67,   479,   511,   481,    44,   480,
      -1,    45,   484,    68,   479,    34,   480,    -1,    45,   484,
      69,   479,    33,   481,   532,   480,    -1,    45,   484,    69,
     479,    33,   480,    -1,    45,   484,    70,   479,   532,   481,
     511,   480,    -1,    45,   484,    71,   479,    35,   481,   511,
     480,    -1,    45,   484,    72,   479,    35,   481,   511,   481,
     511,   481,   511,   480,    -1,    45,   484,   364,    -1,    45,
     484,   364,   479,   532,   480,    -1,   437,   479,   575,   480,
      -1,   437,   479,   576,   480,    -1,   533,    -1,    40,   484,
     404,   479,   511,   480,    -1,    40,   484,   405,   479,    32,
     480,    -1,   516,    -1,   518,   519,    -1,   489,   519,    -1,
     488,   519,    -1,   487,   519,    -1,   409,   519,    -1,   410,
     519,    -1,   420,   519,    -1,   421,   519,    -1,   422,   519,
      -1,   423,   519,    -1,   411,   519,    -1,   412,   519,    -1,
     413,   519,    -1,   414,   519,    -1,   417,   519,    -1,   419,
     519,    -1,   418,   519,    -1,   490,    -1,   491,    -1,   517,
      -1,   479,   533,   480,   517,    -1,   519,    -1,   520,   490,
     519,    -1,   520,   492,   519,    -1,   520,    -1,   521,   487,
     520,    -1,   521,   488,   520,    -1,   521,    -1,   522,    -1,
     523,   493,   522,    -1,   523,   494,   522,    -1,   523,    97,
     522,    -1,   523,    98,   522,    -1,   523,    -1,   524,    99,
     523,    -1,   524,   100,   523,    -1,   511,    99,   511,    -1,
     511,   100,   511,    -1,   524,    -1,   525,   486,   524,    -1,
     525,    -1,   526,   495,   525,    -1,   526,    -1,   527,   496,
     526,    -1,   527,    -1,   528,    95,   527,    -1,   528,    -1,
     529,    96,   528,    -1,   529,    -1,   529,   497,   529,   485,
     530,    -1,   530,    -1,   531,    -1,   386,    -1,   387,    -1,
     388,    -1,   389,    -1,   390,    -1,   391,    -1,   392,    -1,
     393,    -1,   394,    -1,   395,    -1,   534,   484,   396,    -1,
      31,    -1,    48,   482,   532,   483,    -1,    11,    27,    -1,
      11,   479,   511,   480,    -1,    12,   479,   532,   481,   532,
     481,   533,   481,   532,   481,   511,   481,   532,   481,   532,
     480,    -1,    12,   479,   532,   481,   532,   481,   532,   481,
     533,   481,   532,   481,   511,   480,    -1,    12,   479,   532,
     481,   532,   481,   532,   481,   533,   481,   532,   481,   532,
     481,   511,   480,    -1,   267,   479,   511,   480,    -1,   268,
     479,   511,   480,    -1,    43,   479,   506,   480,    -1,    11,
      -1,    11,   479,   533,   481,   532,   481,   532,   481,   532,
     480,    -1,    11,   479,   533,   481,   532,   481,   532,   481,
     532,   481,   532,   480,    -1,    11,   479,   533,   481,   532,
     481,   534,   480,    -1,   534,    -1,   534,   482,   532,   483,
      -1,   220,   479,   553,   481,   532,   480,    -1,   221,   479,
     553,   481,   532,   480,    -1,   222,   479,   553,   481,   532,
     480,    -1,   223,   479,   553,   481,   553,   481,   532,   480,
      -1,   224,   479,   553,   481,   553,   481,   532,   480,    -1,
     105,   479,   553,   481,   553,   480,    -1,   109,   479,   534,
     481,    27,   480,    -1,   109,   479,   534,   481,    27,   481,
     533,   480,    -1,   109,   479,   534,   481,   534,   481,    27,
     480,    -1,   109,   479,   534,   481,   534,   481,    27,   481,
     533,   480,    -1,   109,   479,   534,   481,   534,   481,   534,
     481,    27,   480,    -1,   109,   479,   534,   481,   534,   481,
     534,   481,    27,   481,   533,   480,    -1,   110,   479,   553,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     453,   484,   454,   479,   534,   481,   532,   481,   532,   480,
      -1,   300,   479,   534,   480,    -1,   129,   479,   534,   481,
     532,   481,   532,   481,   532,   480,    -1,   301,   479,   534,
     480,    -1,   204,   479,   553,   481,   532,   480,    -1,   205,
     479,   534,   480,    -1,   206,   479,   534,   480,    -1,   207,
     479,   534,   480,    -1,   208,   479,   534,   481,   534,   481,
     532,   481,   532,   481,   532,   480,    -1,   209,   479,   534,
     480,    -1,   210,   479,   534,   481,   534,   481,   534,   481,
     532,   481,   534,   480,    -1,   211,   479,   534,   481,   534,
     481,   534,   481,   532,   481,   534,   480,    -1,   212,   479,
     534,   481,   534,   481,   534,   481,   532,   481,   534,   481,
     532,   481,   532,   480,    -1,   213,   479,   534,   481,   534,
     481,   534,   481,   532,   481,   534,   481,   532,   481,   532,
     481,   532,   481,   532,   480,    -1,   214,   479,   534,   481,
     534,   481,   534,   481,   534,   480,    -1,   214,   479,   534,
     481,   534,   481,   534,   481,   534,   481,   532,   480,    -1,
     215,   479,   534,   480,    -1,   215,   479,   534,   481,   534,
     480,    -1,   216,   479,   534,   481,   534,   480,    -1,   111,
     479,   553,   481,   532,   480,    -1,   112,   479,   534,   480,
      -1,   128,   479,   534,   480,    -1,   113,   479,   534,   481,
     532,   480,    -1,   231,   479,   534,   480,    -1,   114,   479,
     534,   481,   532,   480,    -1,   115,   479,   534,   481,   532,
     480,    -1,   118,   479,   553,   481,   532,   480,    -1,   534,
     482,   577,   483,    -1,   534,   482,   485,   481,   485,   481,
     532,   485,   532,   483,    -1,   116,   479,   534,   481,   532,
     481,   532,   481,   532,   481,   532,   481,   532,   481,   532,
     480,    -1,   120,   479,   534,   481,   532,   481,   532,   481,
     532,   480,    -1,   120,   479,   534,   481,   532,   481,   532,
     480,    -1,   120,   479,   534,   481,   532,   481,   532,   481,
     532,   481,   532,   480,    -1,   121,   479,   534,   481,   532,
     481,   532,   481,   532,   480,    -1,   121,   479,   534,   481,
     532,   481,   532,   480,    -1,   121,   479,   534,   481,   532,
     481,   532,   481,   532,   481,   532,   480,    -1,   122,   479,
     534,   481,   532,   481,   532,   480,    -1,   122,   479,   534,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     123,   479,   534,   481,   532,   481,   532,   480,    -1,   123,
     479,   534,   481,   532,   481,   532,   481,   532,   481,   532,
     480,    -1,   124,   484,    25,    -1,   124,   484,    26,    -1,
     134,   484,   179,   479,   534,   481,   532,   480,    -1,   134,
     484,   179,   479,   534,   481,   534,   480,    -1,   134,   484,
      25,    -1,   134,   484,   144,   479,   534,   480,    -1,   124,
     479,   534,   481,   532,   481,   532,   481,   532,   481,   532,
     480,    -1,   168,   479,   534,   481,   534,   481,   532,   481,
     532,   481,   532,   480,    -1,   126,   479,   534,   481,   532,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     125,   479,   534,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   169,   484,   179,   479,   534,   481,   532,
     481,   532,   481,   532,   480,    -1,   170,   484,   179,   479,
     534,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   171,   479,   534,   480,    -1,   172,   479,
     534,   481,   532,   481,   532,   480,    -1,   172,   479,   534,
     481,   532,   481,   532,   481,   577,   480,    -1,   172,   479,
     534,   481,   532,   481,   532,   481,   532,   481,   577,   480,
      -1,   173,   479,   534,   481,   532,   481,   532,   481,   577,
     480,    -1,   173,   479,   534,   481,   532,   481,   532,   481,
     532,   481,   577,   480,    -1,   174,   479,   534,   481,   532,
     481,   532,   481,   577,   480,    -1,   175,   479,   534,   481,
     532,   481,   532,   481,   532,   481,   577,   480,    -1,   176,
     479,   534,   481,   532,   481,   532,   481,   532,   481,   577,
     480,    -1,   177,   479,   534,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   577,   480,    -1,   178,   479,   534,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     183,   479,   534,   481,   532,   481,   532,   480,    -1,   218,
     479,   534,   481,   532,   481,   532,   481,   532,   481,   532,
     481,   532,   480,    -1,   382,   479,   534,   480,    -1,   383,
     479,   534,   480,    -1,   384,   479,   534,   480,    -1,   385,
     479,   534,   480,    -1,    38,   484,   303,    -1,    38,   484,
     304,    -1,    36,   484,   303,    -1,   240,   479,   534,   481,
     532,   480,    -1,   241,   479,   534,   481,   532,   480,    -1,
     242,   479,   534,   481,   532,   480,    -1,   243,   479,   534,
     481,   532,   480,    -1,   166,   479,   553,   481,   553,   481,
     532,   480,    -1,   167,   479,   553,   481,   553,   481,   532,
     481,   532,   481,   532,   481,   532,   480,    -1,   166,   479,
     553,   481,   553,   481,   532,   481,   532,   481,   532,   480,
      -1,   166,   479,   553,   481,   553,   481,   532,   481,   532,
     481,   532,   481,   532,   480,    -1,   166,   479,   553,   481,
     553,   481,   534,   481,   532,   481,   532,   480,    -1,   269,
     479,   534,   481,   534,   480,    -1,   270,   479,   534,   481,
     534,   481,   553,   480,    -1,   274,   479,   534,   481,   532,
     481,   532,   481,   532,   480,    -1,   275,   479,   534,   481,
     532,   481,   532,   481,   532,   480,    -1,   275,   479,   534,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     276,   479,   534,   481,   532,   480,    -1,   277,   479,   534,
     481,   532,   480,    -1,   278,   479,   534,   481,   532,   480,
      -1,   279,   479,   534,   481,   532,   480,    -1,   280,   479,
     534,   481,   532,   480,    -1,   281,   479,   534,   481,   532,
     480,    -1,   282,   479,   534,   481,   532,   480,    -1,   283,
     479,   534,   481,   532,   480,    -1,   283,   479,   534,   481,
     532,   481,   532,   480,    -1,   284,   479,   534,   481,   532,
     481,   532,   481,   532,   480,    -1,   285,   479,   553,   480,
      -1,   534,   479,   553,   480,    -1,   399,   479,   553,   481,
     532,   481,   532,   481,   532,   480,    -1,   400,   479,   553,
     481,   532,   481,   532,   481,   532,   480,    -1,   447,   479,
     553,   480,    -1,   447,   479,   553,   481,   532,   480,    -1,
     450,   479,   553,   481,   532,   480,    -1,   448,   479,   553,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     449,   479,   534,   481,   534,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   480,
      -1,   452,   479,   553,   481,   532,   481,   532,   480,    -1,
     573,   484,   337,   479,   480,    -1,   573,   484,   338,   479,
     480,    -1,   573,   484,   339,   479,   480,    -1,   573,   484,
     336,   479,   534,   480,    -1,   458,   479,   553,   481,   532,
     480,    -1,   458,   479,   553,   480,    -1,   459,   479,   553,
     481,   532,   480,    -1,   459,   479,   553,   480,    -1,   464,
     479,   553,   481,   553,   480,    -1,   465,   479,   553,   480,
      -1,   466,   479,   511,   480,    -1,   438,   479,   553,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   481,   532,   480,    -1,   248,   479,   573,   481,   534,
     481,   553,   480,    -1,   250,   479,   573,   481,   511,   480,
      -1,   535,    -1,   479,   553,   480,    -1,   536,    -1,   537,
      -1,   518,   539,    -1,   488,   539,    -1,   487,   539,    -1,
     409,   539,    -1,   410,   539,    -1,   420,   539,    -1,   421,
     539,    -1,   422,   539,    -1,   423,   539,    -1,   411,   539,
      -1,   412,   539,    -1,   413,   539,    -1,   414,   539,    -1,
     417,   539,    -1,   419,   539,    -1,   418,   539,    -1,   424,
     539,    -1,   538,    -1,   479,   533,   480,   538,    -1,   539,
      -1,   540,   490,   519,    -1,   540,   492,   519,    -1,   540,
     490,   539,    -1,   540,   492,   539,    -1,   540,   495,   539,
      -1,   540,    -1,   541,    -1,   542,   487,   520,    -1,   542,
     488,   520,    -1,   542,   487,   540,    -1,   542,   488,   540,
      -1,   542,    -1,   543,    -1,   544,   493,   543,    -1,   544,
     494,   543,    -1,   544,    97,   543,    -1,   544,    98,   543,
      -1,   544,   493,   522,    -1,   544,   494,   522,    -1,   544,
      97,   522,    -1,   544,    98,   522,    -1,   544,    -1,   545,
      99,   544,    -1,   545,   100,   544,    -1,   545,    99,   522,
      -1,   545,   100,   522,    -1,   545,    -1,   546,   486,   545,
      -1,   546,    -1,   547,    -1,   548,   496,   547,    -1,   548,
      -1,   549,    95,   548,    -1,   549,    -1,   550,    96,   549,
      -1,   550,    -1,   550,   497,   550,   485,   551,    -1,   551,
      -1,   538,   103,   552,    -1,   552,    -1,    46,    -1,    38,
     484,   355,    -1,   357,   479,    46,   481,    46,   481,   532,
     480,    -1,    13,   479,   511,   480,    -1,   358,   479,   532,
     481,   532,   480,    -1,    39,    -1,   359,   479,   572,   480,
      -1,   555,    -1,   479,   572,   480,    -1,   556,    -1,   557,
      -1,   518,   559,    -1,   488,   559,    -1,   487,   559,    -1,
     559,   101,    -1,   409,   559,    -1,   410,   559,    -1,   420,
     559,    -1,   421,   559,    -1,   422,   559,    -1,   423,   559,
      -1,   411,   559,    -1,   412,   559,    -1,   413,   559,    -1,
     414,   559,    -1,   417,   559,    -1,   419,   559,    -1,   418,
     559,    -1,   558,    -1,   559,    -1,   560,   490,   519,    -1,
     560,   102,   559,    -1,   560,   490,   559,    -1,   560,    -1,
     561,   487,   520,    -1,   561,   488,   520,    -1,   561,   487,
     560,    -1,   561,   488,   560,    -1,   561,    -1,   562,    -1,
     563,    -1,   564,    -1,   565,    -1,   566,    -1,   567,    -1,
     568,    -1,   569,    -1,   570,    -1,   571,    -1,    37,    -1,
      47,   482,   532,   483,    -1,   290,   479,   553,   481,   532,
     480,    -1,   293,   479,   534,   481,   532,   480,    -1,   290,
     479,   553,   481,   532,   481,   534,   480,    -1,   299,   479,
     553,   481,   532,   481,   553,   480,    -1,   294,   479,   573,
     480,    -1,   294,   479,   573,   481,   532,   480,    -1,   295,
     479,   534,   481,   532,   480,    -1,   296,   479,   573,   481,
     532,   480,    -1,   298,   479,   573,   481,   532,   480,    -1,
     302,   479,   480,    -1,   302,    27,    -1,   302,   479,   511,
     480,    -1,   302,    -1,   249,   479,   511,   480,    -1,   249,
     479,   511,   481,   532,   480,    -1,   573,    -1,   235,   479,
     534,   480,    -1,   236,   479,   573,   480,    -1,   236,   479,
     573,   481,   532,   481,   532,   481,   532,   480,    -1,   237,
     479,   573,   481,   532,   480,    -1,   244,   479,   573,   481,
     532,   481,   532,   481,   532,   481,   532,   481,   532,   481,
     532,   480,    -1,   245,   479,   553,   481,   532,   481,   532,
     481,   532,   481,   532,   481,   532,   481,   532,   481,   532,
     480,    -1,   246,   479,   553,   481,   532,   481,   532,   481,
     532,   480,    -1,   247,   479,   553,   481,   532,   481,   532,
     481,   532,   481,   532,   481,   532,   481,   532,   481,   532,
     481,   532,   480,    -1,   573,   484,   239,   479,   532,   481,
     532,   480,    -1,   455,   479,   553,   480,    -1,   455,   479,
     553,   481,   532,   480,    -1,   455,   479,   553,   481,   532,
     481,   532,   480,    -1,   457,   479,   553,   481,   532,   481,
     532,   480,    -1,   456,   479,   553,   481,   532,   481,   532,
     481,   553,   481,   553,   480,    -1,   456,   479,   553,   481,
     532,   481,   532,   481,   553,   481,   553,   481,   553,   481,
     532,   480,    -1,   461,   479,   553,   481,   553,   481,   553,
     481,   532,   481,   532,   481,   532,   481,   532,   480,    -1,
     461,   479,   553,   481,   553,   481,   553,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   480,    -1,   461,
     479,   553,   481,   553,   481,   553,   481,   532,   481,   532,
     481,   532,   480,    -1,   461,   479,   553,   481,   532,   481,
     532,   481,   532,   481,   532,   481,   532,   480,    -1,   463,
     479,   553,   481,   553,   481,   553,   481,   532,   481,   532,
     481,   532,   481,   532,   480,    -1,   463,   479,   553,   481,
     553,   481,   553,   481,   532,   481,   532,   481,   532,   481,
     532,   481,   553,   481,   553,   480,    -1,    30,    -1,    33,
      -1,    32,    -1,   534,    -1,    36,    -1,    37,    -1,    38,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,    44,
      -1,    35,    -1,    39,    -1,    46,    -1,    45,    -1,    47,
      -1,    48,    -1,   532,   485,   532,   481,   532,   485,   532,
     481,   532,   485,   532,    -1,   532,   485,   532,   481,   532,
     485,   532,    -1,   534,    -1,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   932,   932,   932,   933,   937,   941,   941,   942,   942,
     943,   943,   944,   944,   947,   951,   955,   984,  1010,  1035,
    1055,  1086,  1109,  1131,  1175,  1219,  1235,  1243,  1247,  1261,
    1275,  1289,  1299,  1311,  1330,  1340,  1350,  1360,  1372,  1383,
    1398,  1422,  1434,  1445,  1450,  1460,  1485,  1497,  1515,  1537,
    1545,  1553,  1561,  1570,  1601,  1617,  1622,  1626,  1630,  1635,
    1639,  1643,  1648,  1687,  1707,  1736,  1753,  1766,  1786,  1799,
    1834,  1864,  1882,  1886,  1890,  1894,  1898,  1902,  1906,  1910,
    1914,  1918,  1923,  1927,  1936,  1945,  1952,  1961,  1975,  2223,
    2277,  2285,  2294,  2304,  2310,  2316,  2323,  2329,  2339,  2349,
    2367,  2379,  2389,  2438,  2453,  2474,  2505,  2520,  2527,  2534,
    2552,  2575,  2580,  2585,  2598,  2609,  2618,  2627,  2635,  2652,
    2668,  2685,  2705,  2720,  2738,  2751,  2765,  2774,  2788,  2799,
    2812,  2830,  2852,  2876,  2906,  2938,  2943,  2961,  2966,  2971,
    2976,  2981,  2986,  3000,  3015,  3032,  3046,  3066,  3071,  3076,
    3083,  3093,  3101,  3106,  3113,  3118,  3123,  3143,  3167,  3172,
    3177,  3182,  3187,  3192,  3197,  3202,  3207,  3212,  3217,  3222,
    3227,  3232,  3237,  3242,  3247,  3252,  3257,  3262,  3270,  3275,
    3280,  3285,  3290,  3295,  3300,  3305,  3310,  3315,  3320,  3325,
    3330,  3334,  3361,  3374,  3379,  3383,  3389,  3402,  3408,  3414,
    3420,  3427,  3434,  3441,  3452,  3463,  3478,  3493,  3501,  3510,
    3519,  3527,  3531,  3535,  3572,  3581,  3588,  3595,  3606,  3614,
    3632,  3642,  3647,  3654,  3661,  3669,  3677,  3696,  3712,  3729,
    3746,  3751,  3756,  3761,  3766,  3774,  3875,  3909,  3916,  3924,
    3930,  3937,  3947,  3956,  3963,  3970,  3980,  3987,  4001,  4015,
    4023,  4028,  4036,  4044,  4055,  4067,  4079,  4091,  4097,  4110,
    4117,  4128,  4150,  4176,  4204,  4214,  4227,  4237,  4250,  4279,
    4296,  4311,  4318,  4340,  4359,  4377,  4391,  4396,  4401,  4410,
    4415,  4424,  4438,  4445,  4452,  4458,  4475,  4491,  4525,  4538,
    4582,  4587,  4592,  4598,  4614,  4621,  4627,  4633,  4640,  4647,
    4653,  4659,  4665,  4671,  4677,  4689,  4695,  4712,  4719,  4730,
    4737,  4742,  4748,  4753,  4758,  4763,  4768,  4773,  4808,  4835,
    4842,  4864,  4868,  4875,  4882,  4890,  4898,  4907,  4914,  4921,
    4928,  4935,  4942,  4949,  4956,  4963,  4970,  4977,  4987,  4992,
    4998,  5004,  5010,  5016,  5022,  5028,  5034,  5040,  5046,  5053,
    5058,  5070,  5076,  5090,  5103,  5110,  5111,  5121,  5129,  5135,
    5146,  5147,  5150,  5155,  5163,  5171,  5181,  5186,  5192,  5198,
    5207,  5212,  5227,  5243,  5247,  5264,  5280,  5294,  5307,  5328,
    5387,  5406,  5423,  5430,  5438,  5443,  5448,  5476,  5482,  5493,
    5513,  5533,  5551,  5571,  5589,  5607,  5630,  5653,  5676,  5683,
    5708,  5731,  5738,  5748,  5758,  5768,  5778,  5788,  5798,  5812,
    5829,  5845,  5850,  5855,  5859,  5866,  5874,  5909,  5922,  5932,
    5949,  5968,  5984,  6002,  6022,  6043,  6056,  6069,  6077,  6085,
    6089,  6097,  6107,  6112,  6117,  6118,  6119,  6120,  6121,  6122,
    6123,  6124,  6125,  6133,  6134,  6135,  6136,  6137,  6138,  6139,
    6144,  6145,  6149,  6155,  6171,  6172,  6173,  6177,  6178,  6179,
    6183,  6191,  6192,  6193,  6194,  6195,  6199,  6200,  6201,  6202,
    6203,  6207,  6211,  6219,  6223,  6230,  6234,  6241,  6245,  6252,
    6256,  6263,  6264,  6271,  6275,  6284,  6289,  6293,  6297,  6301,
    6305,  6309,  6313,  6317,  6321,  6325,  6333,  6338,  6355,  6362,
    6369,  6428,  6483,  6540,  6562,  6584,  6598,  6628,  6637,  6657,
    6683,  6697,  6775,  6842,  6850,  6858,  6868,  6878,  6908,  6927,
    6948,  6967,  6988,  7007,  7027,  7068,  7084,  7099,  7116,  7139,
    7154,  7169,  7184,  7199,  7235,  7250,  7272,  7294,  7336,  7383,
    7401,  7421,  7436,  7451,  7466,  7486,  7502,  7518,  7536,  7558,
    7575,  7591,  7603,  7631,  7651,  7696,  7708,  7719,  7732,  7744,
    7755,  7781,  7808,  7840,  7857,  7875,  7888,  7901,  7921,  7944,
    7958,  7973,  8007,  8044,  8079,  8112,  8129,  8146,  8160,  8181,
    8204,  8228,  8253,  8278,  8300,  8322,  8346,  8389,  8413,  8445,
    8459,  8496,  8533,  8570,  8605,  8610,  8619,  8624,  8635,  8645,
    8655,  8664,  8685,  8715,  8743,  8774,  8809,  8820,  8836,  8846,
    8856,  8871,  8885,  8899,  8912,  8925,  8937,  8949,  8961,  8972,
    8985,  9012,  9045,  9153,  9177,  9219,  9232,  9243,  9252,  9276,
    9301,  9314,  9324,  9334,  9344,  9354,  9364,  9372,  9380,  9388,
    9415,  9436,  9444,  9482,  9505,  9525,  9525,  9527,  9529,  9530,
    9531,  9532,  9533,  9534,  9535,  9536,  9537,  9538,  9539,  9540,
    9541,  9542,  9543,  9544,  9545,  9546,  9562,  9563,  9587,  9588,
    9594,  9596,  9597,  9598,  9601,  9606,  9607,  9608,  9609,  9610,
    9613,  9617,  9618,  9619,  9620,  9621,  9622,  9623,  9624,  9625,
    9629,  9630,  9631,  9632,  9633,  9637,  9638,  9643,  9647,  9648,
    9652,  9653,  9657,  9658,  9662,  9663,  9667,  9668,  9671,  9675,
    9685,  9698,  9709,  9727,  9734,  9744,  9759,  9759,  9761,  9763,
    9764,  9765,  9766,  9767,  9776,  9777,  9778,  9779,  9780,  9781,
    9782,  9783,  9784,  9785,  9786,  9787,  9788,  9792,  9794,  9795,
    9796,  9797,  9807,  9808,  9809,  9810,  9811,  9814,  9818,  9822,
    9826,  9831,  9835,  9839,  9843,  9847,  9851,  9854,  9859,  9864,
    9881,  9893,  9905,  9917,  9950,  9959,  9968,  9977,  9986,  9995,
   10002, 10010, 10017, 10035, 10049, 10065, 10075, 10094, 10123, 10151,
   10167, 10185, 10220, 10253, 10300, 10327, 10337, 10360, 10372, 10385,
   10425, 10470, 10520, 10573, 10619, 10648, 10681, 10722, 10726, 10728,
   10730, 10734, 10736, 10738, 10740, 10742, 10744, 10746, 10748, 10750,
   10752, 10754, 10756, 10758, 10760, 10766, 10774, 10781, 10797
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_SetDebugOn", "T_SetDebugOff",
  "T_SetVerboseOn", "T_SetVerboseOff", "T_SetProgress", "T_argc",
  "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_ReadRawImages",
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
     725,   726,   727,   728,   729,   730,   731,   732,    59,    40,
      41,    44,    91,    93,    46,    58,    38,    43,    45,    33,
      42,   126,    47,    60,    62,    94,   124,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   498,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   500,   500,   501,   501,   501,   502,
     502,   503,   504,   504,   504,   504,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   508,
     508,   509,   509,   509,   509,   510,   510,   510,   511,   512,
     513,   514,   515,   515,   515,   515,   515,   515,   515,   515,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     518,   518,   519,   519,   520,   520,   520,   521,   521,   521,
     522,   523,   523,   523,   523,   523,   524,   524,   524,   524,
     524,   525,   525,   526,   526,   527,   527,   528,   528,   529,
     529,   530,   530,   531,   532,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   534,   534,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   536,   536,   537,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   539,   539,   540,   540,
     540,   540,   540,   540,   541,   542,   542,   542,   542,   542,
     543,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     545,   545,   545,   545,   545,   546,   546,   547,   548,   548,
     549,   549,   550,   550,   551,   551,   552,   552,   553,   554,
     554,   554,   554,   555,   555,   555,   556,   556,   557,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   559,   560,   560,
     560,   560,   561,   561,   561,   561,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   573,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   575,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   577,   577,   577,   577
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
#define YYPACT_NINF -2408
static const yytype_int16 yypact[] =
{
    9381, -2408, -2408, -2408, -2408,  -443, -2408, -2408, -2408,    -2,
      96, -2408,    45,  3567,  5286,  -436,    74, -2408, -2408, -2408,
   -2408, -2408,    69,   127,   136,   -38,  -388, -2408,   -46,   -71,
     -75,  -270,     5,  -258,  -244,   -52,  -206,   625, -2408, -2408,
   -2408, -2408,  -182,  -178,  -172,  -283,  -167,  -204,    15,  -147,
    -144, -2408, -2408, -2408,  -101,   -94,   -77,   -69,   -47,    46,
     -14,    -6,    14,    16,    37,    47,    55,    57,    72,   107,
     112,   169,   197,   204, -2408,   219,   230, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, -2408,   240,   282,   293,
   -2408, -2408,  7057,  7057,  7057,  7057,  7057,  7057,  7057,  7057,
    7057,  7057,  7057,  7057,  7057,   445, -2408, -2408,  5286,   481,
     297,   311,   445,   346,   394,   412,   423, -2408, -2408, -2408,
   -2408, -2408,   436,   448, -2408,  3567,  7057,  7057,  8215, -2408,
   -2408,  8874, -2408, -2408, -2408, -2408, -2408,    11, -2408, -2408,
    -255,   227, -2408, -2408, -2408,  7057, -2408,   -92,    19, -2408,
     -48,   432,    38,    58,    51,   480,   -63, -2408, -2408, -2408,
   -2408,   -16, -2408, -2408, -2408, -2408,   615,   -54,    70, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
     -57,   -11,  5286,   310,   450, -2408, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408,   446,   478,   479,   488,   491,
     492,   227, -2408,  -395, -2408,   493,   478,  8215,  8215,  8215,
    8215,  8215,  8215,  8215,  8215,  8215,  8215,  8215,  8215,  8215,
    5286,  8215,  8215,   227,  8215, -2408,    74, -2408,   501, -2408,
   -2408,  5286, -2408, -2408,  5286, -2408, -2408,  5286,    74,  1147,
      80,    80,   702,  3567,  5286,   519,    52, 10829, 10829, -2408,
     289,    23,   662,  5286,  5286, -2408, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,   505,
     450, -2408, -2408,  5286,  5286, 14586,    45, 14586, 14586,    45,
   14586,    45, 14586,    45,   408,  1302,   392,   438,    45,    45,
   14586, 14586,    45,    45,    45,    45,    45,    45,    45,    45,
     962,   965,  5286,  5286,    45,  5286,  5286,    30,   971, 14586,
      45, -2408,  -389,   615, -2408,   615, -2408,   615, -2408,   615,
   -2408,   615, -2408,   615, -2408,   615, -2408,   615, -2408,   615,
   -2408,   615, -2408,   615, -2408,   615, -2408,   615,   896, -2408,
     972, -2408,    11,   649,   974,   529,  5286,    74,   978,    45,
      45,    45,   530,   535,   537, -2408,   615, -2408,   615, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408,    11, -2408,    74,    74,
      74,    74, -2408,   615,  8215,  8215,  8215,  8215,  8215,  8215,
    8215,  8215,  8215,  8215,  5286,  5286,  5286,  5286,  5286,  5286,
   14586, 11759,  5286,  5286,   520, -2408,    30,  7057,  7057,  7057,
      35,   596, 14192,  9899,   538,  5286,  5286,   442,   234,   106,
     459,   885,  5286,    89,   -18,   540,  1017, -2408, -2408, -2408,
   -2408,   565,   567,   568,   569,   570,   571, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408,   572,   573,   574, -2408,
     575,   576,   578,   580, -2408,   581,   582,   584,   585,   586,
     587,   590,   591,   593,   594,   595, -2408, -2408,   597,   599,
     600,   601, -2408,   602,   605,   606,   607,   608, -2408,   609,
   -2408,   610,   611,   612,   613,   614, -2408, -2408,   616,   617,
    5286, -2408,   619,   620, -2408,    -7,   634,   632,   635,   639,
      67,   642,   643,   644,   645,   646,   647,   648,   650,   652,
     653,   654,   655,   656,  -316,   657,   658,   659,   661,   660,
     664,   666,   667,   663,   665,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   691,   692,   694,   696,   698,   700,
     701,   703,   704,   705,   706,   707,   709,   710,   712,   713,
     715,   716,   718,   719,   720,   721,   723,   727,   728,   729,
     730,   738,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   764,   765,   766, 12685, 12685, 12685, 12685, 12685, 12685,
   12685, 12685, 12685, 12685, 12685, 12685, 12685, 14586,   767,   768,
     776,   777,   778,   779,   697,   780,   783,   785,   786,   787,
   11759,   267, 12685, 12685,   194,   227, 12685, -2408,  -343, -2408,
   -2408, -2408,   991, -2408,  -279, -2408,   237, -2408,   -12,   627,
     589, -2408,   771,  1000,   -28, -2408, -2408, -2408,   784,   248,
     790, -2408, -2408, -2408,   791,   792,   793, -2408, -2408,   794,
     795,   796,   797,   798,   799,   800,   801,   803,   805, -2408,
   -2408, -2408, -2408,   806, -2408,    74,   804,   808,   811,  5286,
     807,   814,   812,   809,  -277,   813, 14586, 14586, 14586, 14586,
   14586, 14586, 14586, 14586, 14586, 14586, 14586, 14586, 14586, 13798,
   14586, 14586, 14586,   236,   818,   815,   826,   827,   829,   831,
     832,   834,   835,   836,   810,   833,   841, -2408, -2408,   842,
     843, -2408, -2408,   845,   846,   847,   848,   849,   850,   860,
     869, -2408,   870,   872,   875,   879,   882,   883,   887,   890,
     891,   892,   893,   894,   895,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   908,   909,   910,   911,   912,   913,
     914, -2408, -2408, -2408, -2408, -2408, -2408,   915,   884,  -137,
     917,   931,   934,   935,   936,   937,   938,   939,   940,   941,
     942,   943,   945,   946,   947,   948,  -238,   949, -2408,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,   951,   952,   953,   955,
      90,  5286, -2408,     1, -2408, -2408,   988,   992,   994,   165,
     990,   995,   996,   998,   999,  1004, -2408, 13469, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408,   -92,   -92, -2408, -2408,
   -2408, -2408,   -48,   -48,   432,    38,    58,    51,   480,   -74,
   -2408,   632, -2408, -2408,  -314,   944,   916, -2408,   954, -2408,
   -2408,    74, -2408,   997,  1002,  1007,  1008,  1009,  1010,  1011,
    1012, -2408, -2408,   615, -2408,   615,   -92,   -54,   -92,   -54,
    1013,  1014,  1015,  1016,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,    -1,  1029,  1047,  1048,  1049,
    1050,  1046, -2408, -2408, -2408, -2408,    74,  1052,  1053,    74,
   -2408,  1054, -2408,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070, -2408,
    1071, -2408,  1072, -2408, -2408,  1073,  1074,  1075,  1076,  1077,
   -2408, -2408,  1078,  1079,  1080, -2408,   -15,  1081,  1082,  1084,
   -2408,  1085,    -8,  1086,  1088,  1089,  1090, 12222, 12222, 12222,
   12222, 12222, 12222, 12222, 12222, 12222, 12222, 12222, 12222, 12222,
   10364, 12222, 12222,   227, 12222, -2408, -2408, -2408, -2408,  1087,
   -2408, -2408,  1091,  1092,   -19,  5286,  5286,  5286,  5286,  5286,
    5286,  5286,    45,  5286,  5286,    94,  1099,  1151,  5286,  5286,
    5286,  5286,  5286,  5286,  5286, 14586,  5286,  1337,  5286,  1350,
    5286,  5286,    35,  5286,  5286,  5286,  5286,  5286,    80,    29,
    1458,  1530,  5286,  5286,  5286,  5286,    74,   227, -2408,    74,
    1529, -2408,   177,  5286,   352,   427, 10829, 14586,    45, 14586,
   14586,    45,    45,    45,    45,    45, 14586,    45,    45,    45,
      45,    45,   108,    45,    45,    45,    45,    66, 14586, 14586,
      45,  1391,  1393,    45,    45,    45,    45,    45,    45,    45,
      45,    45, 14586,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45, 14586, 14586, 14586, 14586,
   14586,    45,    45,    45,    45,    45,    80,    80,    74,    74,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45, 14586,    45,    45,    45,    45,    45,    45,
   14586, 14586,  -166, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408, 14586, 14586,
   14586,    45, 14586, 14586,  1122, 14586, 14586, 14586, 14586,    74,
    1097,  1098, -2408, -2408, -2408, -2408, -2408, -2408, -2408, 11294,
   -2408, 11759,  4790, 14586, 12685, 12685, 14586, 12685, 12685, 12685,
   12685, 12685, 12685, 12685, 12685, 14586, 14586, 14586, 14586, 14586,
     -87,    11,    74,    74,  1547,  1548,    74,  1546,  1549,  5286,
    1550,  1551,  5286,  1539,  5286,    74,  5286, -2408,  5286,  1481,
    1484,  1105, -2408,  1545,  1287, 14586,   708,    56,  1112,  -160,
   14586, -2408,   203, -2408,  1114, -2408, -2408,  1115, -2408,  1116,
      45,  5286,    45,  5286,  5286,  5286,    45,    45,    45,    45,
    5286,  5286,  5286,  5286,  5286,  5286,  5286,    45,  5286,    45,
      45,    45,    68,    45,    73,    84,    45,    45,  5286,  5286,
    5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286,
    5286,  5286,  5286,    45, -2408, 14586, -2408,  1117,  5286,  5286,
    5286,  5286,  5286,  5286,  5286,    45,    45,    45, -2408, -2408,
    5286,  5286, -2408,  5286, -2408, -2408,    74, -2408,  1171, -2408,
   -2408, -2408, -2408, -2408, -2408,  1569,  1570,  1571,  1573,  1574,
     255,  5286, -2408,  5286,    74,    45,    45,  5286, -2408,  5286,
    5286, -2408,  5286,  5286,  1502,    74,    45, -2408,    45,    45,
    5286,  5286,  5286,  5286,  5286,  5286,    45,    80,    80,    80,
   14586, 14586, 14586,    74, 14586,    45,    80,    45,    80,    80,
   14586, -2408,    -4, 14586, 14586, 14586, 14586, 14586,  1367, -2408,
    5286,  5286, -2408,  5286,  5286,  5286,  5286,  5286,  5286, 14586,
    5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286,    45, 14586,
    5286, 14586,  5286,  5286,    45,  5286,  5286,  5286, 14586,  5286,
    5286,    74,  -226, 10829,    74,  5286,  1561,  5286,  5286,    74,
     313, -2408, -2408,  1128,  1129,  -257,  1130,  1131,  1132,  1134,
    1136,  1135,  1137,  1139,  1141,  1142,  1143,  1144,  1145,  1146,
    1149,  1148,  1153,  1150,  1154,  1155,  1156,  1158,  1159,  1161,
    1162,   270,  1164,  1165,  1166,  1167,  1168,  1169,  1172,  1125,
     275,  1173,  1170,  1174,  1175,  1177,  1178,  1179,  1181,  1183,
    1184,  1185,  1188,  1186, -2408, -2408, -2408,   277,  -342,  1192,
    1193,  1194,  1196,  1189,  1197,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208, -2408, -2408,  1209,  1210,  1212,  1213,
   -2408,  1160,  1163,  1214,  1215,  1216,  1180,  1219,  1220,  1218,
    1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1230,  1231,
    1232,  1233,  1235,  1236,  1237,  1238,  1239,  1240,   279,  1241,
    1242,  1243,  1244,  1245,  1246,  1247,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1273,  1274,
    1275,  1276,  1281,  1283,  1285,  1286,  1288,  1292,   283,  1293,
    1298,  1300,  1304,  1234,   287,   290,  1305,  1303,  1311, 13148,
   -2408,   632,   482,   227, -2408, -2408,  1312,   446,  1314,   -81,
    -395,  1140, -2408, -2408, -2408, -2408, -2408, -2408,   -92,  -279,
     -92,  -279, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
   -2408,   -12, -2408,   -12,   627, -2408,   771,  1000,   -72,  1289,
    1317,  1319,  1320, -2408,  1313,  1321,  1322,  1323,  1325,  1328,
     294,  1329,  1332,  1345,  1347,  1349,  1351,  1352,  1353,  1182,
      35, 14586, -2408,  1354, 14980,  1297,    45,    45,    45,   303,
    1355,  1364,   305,  1366,  1368,  1369,  1370,  1371,  1372,  1373,
    1374,  1375,  1376,  1377,  1382,  1383,  1388,  1384,  1390,  1392,
    1394,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1416,  1419,
    1422,  1424,  1423,  1426,  1428,  1429,  1430,  1431,  1432,  1434,
    1435,  1436,  1437,  1438,  1439,  1441,  1442, 14586,  1443,  1444,
     317,  1445,  1446,  1450,  1451,  1453,  1454,  1455,  1457,  1459,
    1461,  1462,  5286,    11, -2408, -2408, -2408, -2408, -2408, -2408,
     201,  1463,  1464,  1466,  1467,  1468, -2408,  1470,    22,  1471,
   11759,  1474,   319,  1476,  1477,  1478,  -141,  1479,   -85,  1482,
     321,  1480,   323,  1483,   325,  1485,  1486,  1487,  1489,  1490,
     327,  1491,  1492,   329,  1493,  1494,  1495,  1496, -2408,  1498,
     331,  1499,  1500,  1501,  1504,  1330,  1503,  1508,  1509,  1510,
     333,  1512,  1513,  1514,   335,  1516,  1517,  1518,  1519,  1523,
    1527,  1531,  1534,  1536,  1537,  1538,  1540,  1541,  1542,  1554,
    1555,  1556,  1559,  1560,  1256,  1389,  1562, -2408,   337,  1564,
    1440,  1565,  1572,  1579,  1568, -2408,    45,  5286,  5286,  5286,
    5286, -2408,  5286, -2408,  5286, -2408, -2408, -2408,    45,    45,
    5286,  5286,  5286, -2408, -2408,  5286,  5286,  5286,  5286, -2408,
    5286, -2408,  5286, -2408,  5286, -2408, -2408,  5286,  5286,  5286,
    5286, -2408,  1279, -2408,  5286, -2408,    45,  5286, 14586, -2408,
    1543,  1627, -2408, -2408, -2408,  5286,    64,  5286, -2408, 14586,
      76,  5286,  5286, -2408,  5286,  5286,  5286,  5286,  5286,  5286,
    5286,  5286,  5286,  5286,  5286,  5286, -2408,  5286,    45,    45,
   14586, 14586,    45,    45,    45, -2408,  5286,  5286,  5286,  5286,
    5286,  5286,  5286,  5286,  5286, -2408, -2408, -2408,    45, -2408,
      45,    45,    45,    45,    45, -2408,    45,    45,  5286,  5286,
    5286,  5286, 14586, 14586, -2408,  5286,  5286,  5286,  5286,    45,
      74, -2408, -2408,    45,    45,  5286,  5286,  5286,  5286,  5286,
    5286,  5286,  5286,  5286,  5286,  5286, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408,  5286,  5286,  5286, -2408,  5286,  5286,    45,
    5286,  5286,    45, -2408,  5286, -2408,  5286, 14586, -2408, -2408,
   11759, -2408, -2408, -2408, -2408, -2408, -2408,  1315, -2408,  5286,
   -2408, 14586,    45,  1583,  1589,  1590, -2408, -2408,  5286,  5286,
    1657, -2408, -2408,  5286,    74,    74,    74,  5286, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, 14586,  1595,  1597,   339,
   -2408,    45, -2408,  5286, -2408,  5286, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,  5286,
   -2408, -2408,    45, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408,  5286, -2408,  5286, -2408, -2408, -2408,
   -2408,  5286, -2408, -2408, -2408, -2408, -2408,  5286, -2408, -2408,
    1598,  5286,  5286, -2408, 11759,  5286,  5286, -2408,  5286,  5286,
      45,    45,  5286,  5286, -2408,  5286,  1339, -2408,    11,  1686,
    1700,  1772,  1800,  1817,  5286,  5286, -2408,    45,  5286, -2408,
    5286, -2408,  5286,  5286, -2408, -2408, -2408, -2408,  5286, -2408,
   -2408,  5286, -2408,  5286, -2408, -2408, -2408,  5286,  5286, -2408,
    5286, -2408, -2408,  5286,  5286,  5286,  5286,  5286,  5286, -2408,
    5286,  5286,  5286, -2408,  5286,  5286,  5286,  5286,  5286, -2408,
   -2408,  5286,  5286,  5286, 11759, 14586,  5286, -2408, -2408, -2408,
   -2408, -2408,  5286, -2408, -2408,  5286, -2408,  5286, -2408,  5286,
    5286,  5286, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
    5286,  5286, -2408, -2408,  5286, -2408, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408,  1825, -2408, -2408,  1885,  1599,  1601,  1602,
    1604,  1605,  1608,  1611,  1613,  1614,  1615,  1617,  1618,  1621,
    1623,  1624,  1625,  1626,  1628,  1630,  1631,  1632,  1633,  1634,
    1636,  1637,  1638,  1639,  5286,  1641,  1642,  1643,  1645,   341,
    1646,  1647,  1649,  1650,  1651,  1652,  1654,  1653,  1655,  1656,
    1658,  1659,  1660,  1661,  1662,  1664,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680,  1682,  1683,  1684,  1685,  1687,  1688,  1689,  1691,  1692,
    1693,  1695,  1696,  1698,  1699,  1701,  1703,  1704,  1705,  1706,
    1707,  1709,  1724,  1725,  1726,  1727,  1729,  1730,  1731,  1732,
    1733,  1734,  1735,   343,  1736,  1739,  1740,  1742,  1744,  1745,
    1746,  1748,  1749,  1750,  1753,  1754,  1755,  1756,  1757, -2408,
    1760, -2408, -2408, -2408,  1763,  1765,  1767,  1768,  1769,  1770,
    1771,  1773, -2408, -2408, -2408,  5286,  1774,  1775,  1777,  1778,
    1779,  1780,  1782,  1783,  1784, -2408,   348,   350,   355,  1786,
    1787,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1797,  5286,
      11, -2408, -2408, -2408, -2408, -2408, -2408,  1798,  1799,  1814,
    1818,  1801,    81,  1473,  1819,  1820,  1821,  1822,  1823,  1824,
    1826,  1828,  1829,  1830,  1831,  1832,  1834,   357,  1835,  1836,
    1837,  1838,  1839,  1840,   359,  1842,  1844,  1846,  1848,  1849,
    1850,  1852,  1854,  1859,  1864,  1865,  1866,  1868,  1869,  1872,
    1873,  1875,  5286, -2408,  5286, -2408,  5286, -2408,  5286, -2408,
   -2408, -2408, -2408,  5286,  5286, -2408,  5286,  5286,  5286,  5286,
   -2408,  5286,  5286,  5286,  5286, -2408, -2408, -2408,  5286, -2408,
   -2408,  5286,  5286, -2408, -2408,   190,    87,  5286, -2408, -2408,
   -2408, -2408,  5286, -2408,  5286,  5286,  5286,  5286,  5286,  5286,
    5286,  5286, -2408,  5286,  5286,  5286,  5286,  5286,  5286,  5286,
    5286,  5286,  5286,  5286,  5286,  5286,  5286, -2408,  5286,    45,
      45,    45,    45,    45, -2408, -2408,  5286, -2408, -2408, -2408,
    5286,  5286, -2408, -2408, -2408, -2408, 14586, -2408, -2408, 14586,
    5286,  5286, -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
    5286,  5286,  5286,  5286,  5286, -2408,  5286,  5286, -2408,  5286,
    5286, -2408, -2408, -2408,  5286,  5286, -2408,  5286,  5286, -2408,
   -2408, -2408, -2408,    74, -2408,  1876, -2408,  5286, -2408, -2408,
      45,  5286, -2408,  5286,  5286, -2408, 14586, -2408, 14586, -2408,
   14586, -2408, 14586,  5286,  5286,  5286,    45,    45,  5286,  5286,
   -2408, -2408, -2408, -2408,  5286,    45,  5286, -2408,  5286, -2408,
    5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286, -2408,
    5286,  5286,  5286,  5286, -2408, -2408,    45, -2408, -2408, -2408,
   -2408, -2408, 14586, -2408,  5286,  5286,  5286,  5286, 14586, 14586,
    5286, -2408,  5286,  5286,  5286,  5286,  5286,  5286,  5286,  5286,
    5286, -2408,  1878,   361,  1879,  1881,  1882,  1891,  1907,  1908,
    1909,  1911,  1912,  1913,  1914,  1917,  1918,  1921,   -83,  1922,
    1923,  1925,  1447,   363,  1926,  1927,  1928,   365,   368,   370,
     372,  1931,  1932,  1933,  1934,  1936,    43,   374,  -196,  1937,
    1938,  1944,  1947,   376,  1950,  1951,  1952,  1955,  1958,  1959,
    1961,  1962,  1963,  1964,  1965,  1967,  1968,  1969,  1972,  1975,
    1976,  1977,  1978,  1979,  1981,  1985,  1986,  1989,  1990,  1991,
    1992,  1982,  1994,  1525,  1544,  1997,  1999,  2008, -2408,  2013,
    2015,  2016,  2018,  2019,  2021,   378,  2022,  2027,  2028,  2023,
    2030,   397,  2040,  2042,  2043,    11,  2044,  2045,  2046,  2048,
    2049,  2050,  2051,  2053,  2054,  2055,  2056,  2057,  2058,  2059,
    2060,  2061,  2062,  2064,  2065,  2067,  2068,  2071,  2085,  2088,
    2090,  2072,  2092,  2093,  2094,  2095,  2096,  2097,  2098,  2099,
    2100, -2408, -2408,  5286,  5286, -2408,  5286,  5286, -2408,  5286,
    5286, -2408,  5286,  5286,  5286, -2408,  5286,  5286, -2408,   190,
    5286, -2408, -2408,   190,  1915,  5286,  5286, -2408,  5286, -2408,
    5286, -2408,  5286, -2408,  5286,  5286,  5286,  5286,  5286, -2408,
   -2408, -2408,  5286,  5286,  5286,  5286,  5286,  5286, -2408,  6055,
    6055,  6055,  5286,  5286,  5286,  5286, -2408,  5286,  5286,  5286,
    5286,  5286,    45,  5286, -2408, -2408, -2408, -2408,  5286,  5286,
   -2408,  5286,  5286,  5286,  5286,  5286,  5286, -2408,  5286,  5286,
    5286, -2408, -2408,    74,  5286, -2408,  5286, -2408,  5286, -2408,
   -2408,  5286, -2408,  5286,  5286, -2408,  5286, -2408, 14586,    45,
   -2408, -2408, -2408,  5286,    45,  5286, -2408, -2408,  5286,  5286,
   -2408, -2408, -2408, -2408, -2408,  5286,  5286,  5286,  5286,  5286,
   -2408, -2408, -2408, 14586, -2408,  5286,  5286,  5286, -2408, -2408,
   -2408, -2408, -2408, -2408, -2408, -2408, -2408, -2408,  2101,  2103,
    2105,  2106,  2107,  2108,  2110,  2111,  2112,  2113,   399,  2114,
    2115,  2117,   403,  2118,  2119,   405,   407,  2120,  2121,  2122,
    2123,  2124,  2126,  2127,  2128,  2129,  2130,  2131,  2132,  -383,
    2134,  -325,  2135,  1566,  2136,  2137,  2138,  2139,  2140,  2141,
    2142,  2143,  2144,  2145,   415,  2146,  2148,   417,  2149,  2150,
    2151,  2152,  2153,  2154,  2156,  1456,  2157,  2159,  2160,   420,
    2161,  2163,  2164,  2165,  2166,  2168,  2169,  2170,  2171,  2174,
    1594,  2178,  2181,  2184,  2187,  2189,  2190,  2191,  2192,  2193,
    2196,  5286, -2408, -2408,  5286,  5286,  5286, -2408, -2408, -2408,
    5286, -2408,  5286,  5286,    74, -2408, -2408,   190,  5286,  5286,
   -2408,  5286, -2408,  5286,  5286,  5286,  5286,  5286,  5286, -2408,
    5286,  5286,  5286,  5286,  5286,  5286,  6055, -2408,  6055, -2408,
   -2408,  6055,  6055,  5286,  5286,  5286,    45,    45,    45,    45,
   -2408,  5286,  5286, -2408, -2408,  5286, -2408, -2408, -2408,  5286,
    5286,  5286, -2408, -2408,  5286, -2408, -2408, -2408,  5286,  5286,
   -2408, -2408,  5286,  5286, -2408,    45,  5286,    45,  5286,  5286,
   -2408, -2408,  5286,  5286, -2408,  5286, 14586,  5286,  5286,  5286,
    2199,  2200,  2202,  2208,  2209,  2211,  2217,  2225,  2232,  2234,
    2235,  2237,  2240,  2247,  2251,  2252,  2253,  2254,   425,  2257,
    2258,  2260,  2262,  2264,  2267,  2268,  2269,  2271,  2273,  2272,
    2276,  2277,  2283,  2289,  2290,  2292,  2293,  2298,  2299,  2301,
    2302,  1694,  2303,  2305,  2306,  2307,  2308,  2309,  2310,  2311,
    2313,  2314,  2315,  2316,   433,  2317,  2318,  2319, -2408,  5286,
    5286,  5286,  5286, -2408,  5286,  5286, -2408, -2408,  5286, -2408,
   -2408, -2408, -2408, -2408, -2408,  5286, -2408,  5286, -2408,  5286,
   -2408, -2408,  5286, -2408, -2408, -2408, -2408,  6055, -2408, -2408,
   -2408, -2408,  5286,  5286, -2408,  5286, -2408,  5286, -2408,  5286,
    5286,  5286, -2408,  5286,  5286,    45,  5286,    45,  5286,  1861,
    5286,  5286,  5286, -2408, 14586,  5286,  5286,  5286,  2321,  2322,
    2323,  2325,   -26,  2326,  2327,  2328,  2330,  2331,  2332,  2333,
    2335,  2336,  2337,  2339,  2340,  2341, -2408,  2343,   437,  2344,
     439,  2345,  2346,  2347, 14586,  2348,  2349,  2350,  2351,  2353,
     454,  2354, -2408, -2408,  5286, -2408, -2408,    74,  5286,  5286,
   -2408, -2408, -2408,  5286, -2408,  5286,  5286, -2408,  5286,  5286,
   -2408, -2408, 14586,  5286, -2408, 14586,  5286,  5286,  5286, -2408,
    5286,  5286,  5286,  5286, -2408, -2408,  5286,  5286,  2355,  2357,
    2358,  2359,  2360,  2361,  2362,  2363,  2364,  2366,  2367,  2368,
    2369,  2370,  2371,  2373,  2374,  2375,  2377,   471,   473,  5286,
   -2408, -2408, -2408, -2408, -2408,  5286,  5286,  5286, -2408, -2408,
   -2408,  5286,  5286,    45, -2408,  5286,  5286, -2408, -2408,  5286,
   -2408, 14586,  2378,  2379,  2381,  2382,  2384,  2385,  2386,  2388,
    2389,  2392,  2396,  5286,  5286, -2408,  5286, -2408,  5286,    45,
   -2408,  5286, -2408, 14586,  2397,  2393,  2398,  2400,  2403,  2405,
    2406,  5286, -2408,  5286,  5286,  5286, -2408, -2408,  2409,  2411,
    2418,  2407,  5286,  5286,  5286, -2408,  2426,  2428,  2429,  5286,
    5286,  5286,  2436,  2437,  2438, -2408,  5286,  5286,  2439,  2443,
    5286, -2408,  2444, -2408
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2408, -2408,   -31,  1816,  1863,  1888,  1890,  1895,  -243, -2408,
   -2408,   464, -2408,   307,  -337, -2408, -2408, -2408, -2408,  -797,
    5724,   163,  -359, -2408,  -372,   525,  1567,  1580,  1593,  1640,
    1648,  1719,   756, -2408,     0,  -123,  3162, -2408, -2408, -2408,
    -523,  1616,  -192, -2408, -2408,  -438,  -195,   876, -2408,   963,
     969,   964,   979,   175,   968,  6867,  1217, -2408, -2408, -2408,
   -2408,    91,   562, -2408, -2408, -2408, -2408, -2408, -2408, -2408,
   -2408, -2408, -2408, -2408,    34,  6710,  -400,   205,  1804, -2407
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     159,   249,   353,   960,   793,   629,   818,   819,   820,   821,
    1288,     8,  1011,   202,   225,     8,    15,   816,   817,  1321,
    1011,     8,   388,    18,  1158,   400,  1321,    21,   245,    21,
     252,   194,   243,   388,   179,    27,   182,   240,   241,   856,
     858,   654,   927,   226,   184,   183,   184,   204,   396,   378,
     379,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,   238,   390,  1409,  1158,   768,
     480,   402,    27,   370,   371,   930,    21,  1425,  1426,  1103,
    1103,  1450,   183,  1103,   412,  1149,  1150,   391,   837,   413,
     412,  1450,   403,   184,    15,   790,   239,   353,  2906,    21,
     361,    18,  1919,  2149,    21,    21,   367,    21,   341,   194,
     883,   884,   885,   837,  2543,    21,   184,    27,    21,    20,
      20,   184,   184,   188,   184,    21,    20,   183,    52,  1747,
    1384,   159,   184,  1444,  1445,   184,  1141,  1190,  1193,  1142,
    1142,   413,   184,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  2908,  1103,  1103,  1103,
    1919,   229,   230,  1031,  1290,   179,  1291,  1292,  1032,   635,
     636,  1293,   231,   639,   640,   641,   642,   643,   644,   883,
     884,   885,   404,   313,   315,   317,   319,   321,   323,   325,
     327,   329,   331,   333,   335,   337,   276,    15,  1621,   277,
    1451,   711,  1031,  1624,    18,   181,    52,  1186,    21,   247,
    1451,  1144,   194,  1145,  1626,   189,  1146,   356,   358,   232,
     233,    21,   412,   655,  1757,   184,   250,   413,   235,   236,
     234,   417,   368,   369,   418,  1452,   373,   419,   184,   237,
     251,   412,  1262,   476,   478,  1452,   413,   607,   607,  1569,
    1570,  1571,  1572,   657,   658,   311,   314,   316,   318,   320,
     322,   324,   326,   328,   330,   332,   334,   336,   839,   839,
     860,   861,   862,   660,   661,   279,   254,   477,   280,   863,
     864,   865,   866,   412,   867,  2693,   840,   840,   413,   355,
     357,   359,  2820,  2822,  2824,   701,   702,   273,    21,  1132,
    1133,   274,   762,   763,    27,   765,   767,   275,   372,    52,
     338,   794,   278,  1141,   183,   184,  1142,   345,   790,  1190,
     201,   223,  1142,   227,  1595,   868,   370,   371,   869,   870,
     871,   872,   283,   873,   874,   809,   181,   875,   412,  2042,
     284,   786,  1190,   413,  1245,  1142,   800,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     311,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   285,   355,   357,   933,   372,    75,    76,
     286,   832,   834,   835,   412,  2044,   412,  2668,   374,   413,
     375,   413,  1918,   955,  1919,   962,   963,   287,   244,   246,
     288,  1289,   964,  1921,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,   401,  1103,  1103,
     253,  1103,   289,   185,   389,  1270,   397,   958,   242,   769,
     770,   771,   772,   773,   774,   380,   381,   775,   776,   777,
     778,   779,   780,   781,  3116,   481,   482,   483,   484,  1290,
     851,  1291,  1292,   392,  1012,   292,   393,  1360,   394,  1159,
     653,  1322,  1012,   293,  1365,    20,  1708,  1130,  1322,   124,
    1008,  1151,  1152,   124,   248,   851,   851,   853,   855,   124,
     876,   877,   878,   294,   281,   295,   879,   282,   880,  2984,
    2030,  2985,  2031,  2032,  2986,  2987,   376,   377,   342,   782,
     883,   884,   885,    21,  1912,  1913,   296,   783,   784,    27,
     129,   130,   412,  2690,   384,   290,   297,   413,   291,   183,
     184,   382,   383,   415,   298,   694,   299,   814,   815,  1569,
    1570,  1571,  1572,   836,   837,   420,  1017,   386,   796,   277,
      20,   300,  1715,   385,   605,   605,  1188,   398,   399,  2478,
     854,  2479,  2480,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   743,   744,   387,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   301,   695,   696,   697,
     698,   302,  1402,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,  1275,  1276,  1277,  1278,  1279,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   745,
     746,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,   838,   482,   483,
    3090,  2019,  2020,  2021,  2022,  2023,   701,   702,   303,  1569,
    1570,  1571,  1572,   653,   801,  1424,    21,   255,   256,  1181,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,  1138,  1139,   304,   812,   813,    20,
      21,   255,   256,   305,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   795,   270,   306,   839,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   307,
     953,  1553,  1555,  1557,  1559,  1190,   395,   840,  1142,   308,
     841,   842,   843,   844,  1147,  1148,  1153,  1154,  1161,  1139,
    1425,  1426,  1288,  1444,  1445,  1669,  1670,   311,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   336,
    1783,  1784,   845,   846,   847,  1793,  1794,  1808,  1139,  1855,
    1856,   309,  1271,  1896,  1897,   355,   357,  1903,  1904,   372,
    1905,  1906,   310,  1427,  1932,  1933,   343,  1552,  1554,  1556,
    1558,  1560,  1562,  1950,  1951,  1954,  1955,  1007,  1548,  1550,
     344,  1268,   405,   883,   884,   885,   886,  2003,  2004,  2037,
    2038,  2046,  2047,  2049,  2050,  2052,  2053,  2059,  2060,  2063,
    2064,  2070,  2071,  2081,  2082,  2086,  2087,  2110,  1139,  2244,
    2245,  2354,  2355,  2419,  2420,   346,   887,  1130,  2455,  2456,
    2457,  2458,   810,   811,   888,  2459,  2460,  2495,  2496,  2503,
    2504,  2652,  2653,  2672,  2673,  2677,  2678,   889,  2679,  2680,
    2681,  2682,  2683,  2684,  2691,  2692,  2698,  2699,  2740,  2741,
     313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
     333,   335,   337,   347,   356,   358,   373,  2747,  2748,  2881,
    2882,   848,   849,  2886,  2887,  2890,  2891,  2892,  2893,  1421,
     890,   348,   891,   892,   893,  2920,  2921,  2924,  2925,   850,
    2937,  2938,   349,   894,   895,  3036,  3037,   822,   823,   896,
     897,   898,   899,  3073,  3074,   350,   851,  3131,  3132,  3134,
    3135,   479,   900,   901,   902,   903,   904,   351,   905,   906,
     407,   907,   406,  1663,  3145,  3146,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,  3188,  3189,  3190,  3191,  1549,  1551,   244,  1561,  1563,
     857,   859,  1177,   408,   656,  1373,  1374,  1376,  1377,  1378,
    1379,  1380,   409,  1382,  1383,   410,   411,   414,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,   416,  1396,   659,  1398,   760,
    1400,  1401,   761,  1403,  1404,  1405,  1406,  1407,   787,   791,
     792,   798,  1413,  1414,  1415,  1416,  1911,   458,   799,   459,
     806,   460,   461,  1423,   802,   807,   607,   808,   961,   462,
     711,   965,   463,   464,   465,   466,   467,   468,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   837,   356,   358,   966,   373,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   923,   977,   469,   978,
     979,   980,   470,   981,   982,   983,   984,   471,   472,   985,
     986,  1911,   987,   988,   989,  1155,   990,   473,   991,   992,
     993,   994,   474,   475,   995,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1143,  1157,  1006,  1005,  1009,  1010,
     311,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,  1013,   355,   357,  1014,   372,  1016,  1015,
    1748,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1386,  1025,
    1573,  1026,  1027,  1028,  1029,  1030,  1033,  1034,  1035,  1534,
    1036,   964,  1539,  1038,  1037,  1039,  1040,  1041,  1297,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1581,
    1062,  1063,  1584,  1064,  1586,  1065,  1588,  1066,  1589,  1067,
    1068,  1124,  1069,  1070,  1071,  1072,  1073,  1387,  1074,  1075,
    1943,  1076,  1077,  1329,  1078,  1079,  1332,  1080,  1081,  1082,
    1083,  1600,  1084,  1602,  1603,  1604,  1085,  1086,  1087,  1088,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1089,  1617,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1099,  1100,  1101,  1118,  1119,  1648,  1649,
    1650,  1651,  1652,  1653,  1654,  1120,  1121,  1122,  1123,  1125,
    1658,  1659,  1126,  1660,  1127,  1128,  1129,  1156,  1160,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1671,  1174,  1672,  1175,  1176,  1178,  1182,  1185,  1201,
    1677,  1179,  1678,  1679,  1180,  1183,  1184,  1187,  1191,  1192,
    1685,  1687,  1689,  1690,  1691,  1692,  1193,  1543,  1545,  1195,
    1194,  1196,  1202,  1417,  1198,  1197,  1418,  1200,  1199,  1420,
    1203,  1204,  1205,   605,  1206,  1207,  1208,  1209,  1210,  1211,
    1716,  1717,  2018,  1718,  1719,  1720,  1721,  1722,  1723,  1212,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1213,  1214,
    1735,  1215,  1737,  1738,  1216,  1740,  1741,  1742,  1217,  1744,
    1745,  1218,  1219,   607,  1244,  1750,  1220,  1752,  1753,  1221,
    1222,  1223,  1224,  1225,  1226,  1397,  1227,  1228,  1229,  1230,
    1231,  1232,  1233,  1234,  1235,  1493,  1494,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1399,  1295,  1243,  1246,  1103,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,  1247,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1294,  1260,  1261,
    1263,  1264,  1265,  1296,  1266,  1267,  1528,   711,   712,   713,
     714,   715,   716,   717,   718,   719,  1533,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   740,  1272,  1574,
    1575,  1281,  1273,  1578,  1274,  1282,  1298,  1283,   436,  1284,
    1285,  1299,  1587,   741,   742,  1286,  1300,  1301,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1411,  1310,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1323,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,  1324,  1325,  1326,  1327,
    1328,  1330,  1331,  1333,  1334,  1335,  1336,  1337,  1338,  1339,
    1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1412,
    1361,  1419,  1359,  1363,  1364,  1366,  1362,  1367,  1368,  1369,
    1456,  1370,  1457,  1661,  1371,  1372,  1523,  1529,  1530,  1576,
    1579,  1577,  1580,  1585,  1590,  1582,  1583,  1591,  1592,  1593,
    1424,  1673,  1594,  1596,  1597,  1598,  1647,  1662,   454,  1664,
    1665,  1666,  1681,  1667,  1668,  1680,  1715,  1751,  1755,  1792,
    1756,  1758,  1759,  1760,  1761,  1763,   455,  1762,  1764,  1765,
    1700,  1766,  1767,  1920,  1768,  1769,  1770,  1771,  1773,  1709,
    1772,  1775,  2017,  1774,  1747,  1776,  1777,  1778,  1779,  1828,
    1780,  1781,  1829,  1782,  1785,  1786,  2144,  1787,  1788,  1789,
    1790,  1796,  1791,  1795,  2145,  1797,  1798,  1799,  1800,  1833,
    1801,  1802,  2016,  1803,  1804,  1942,  1805,  1807,  1746,  1813,
     605,  1749,  1806,  1809,  1810,  1811,  1754,  1812,  1814,  2270,
    2034,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,
    1824,  1825,  1826,   851,  1827,  1830,  1831,  1832,  1834,  1836,
    1835,  2236,  1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1902,  1848,  1849,  2272,  1850,  1851,  1852,
    1853,  1854,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,
    2273,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  2107,
    1873,  1874,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,
    1883,  1884,  1885,  1886,  1887,  1888,  1889,  2118,  2119,  2120,
    2121,  1890,  2122,  1891,  2123,  1892,  2269,  1893,  1922,  1894,
    2126,  2127,  2128,  1895,  1898,  2129,  2130,  2131,  2132,  1899,
    2133,  1900,  2134,  1908,  2135,  1901,  1907,  2136,  2137,  2138,
    2139,  1909,  1916,  1926,  2140,  1917,  1923,  2142,  1924,  1925,
    2227,  1927,  2274,  1928,  1929,  2146,  1930,  2147,  1931,  2076,
    1934,  2151,  2152,  1935,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  1936,  2165,  1937,  1938,
    2275,  1939,  1940,  1941,  1945,  1952,  2173,  2174,  2175,  2176,
    2177,  2178,  2179,  2180,  2181,  1953,  1956,  2276,  1957,  1958,
    1959,  1960,  1961,  1962,  1963,  1964,  1965,  1966,  2190,  2191,
    2192,  2193,  1967,  1968,  1970,  2196,  2197,  2198,  2199,  1969,
    1971,  2320,  2108,  1972,  1973,  2204,  2205,  2206,  2207,  2208,
    2209,  2210,  2211,  2212,  2213,  2214,  1974,  1975,  1976,  1977,
    1978,  1979,  1980,  2215,  2216,  2217,  1981,  2218,  2219,  1982,
    2221,  2222,  1983,  1985,  2224,  1984,  2225,  1986,  1987,  1988,
    1989,  1990,  2321,  1991,  1992,  1993,  1994,  1995,  1996,  2228,
    1997,  1998,  1999,  2112,  2001,  2002,  2005,  2006,  2234,  2235,
    2007,  1595,  2008,  2237,  2009,  2010,  2011,  2241,  2012,  2933,
    2013,  2014,  2802,  2015,  2024,  2025,  2026,   362,  2027,  2028,
    2029,   824,  2033,  2247,  2036,  2248,  2039,  2040,  2481,  2041,
    2043,  2048,  2045,  2051,  3104,   825,  2054,  2055,  2056,  2249,
    2057,  2058,  2061,  2062,  2065,  2066,  2067,  2068,  2069,   826,
    2072,  2073,  2074,  2077,  2251,  2075,  2252,  2271,  2078,  2079,
    2080,  2253,  2083,  2084,   363,  2085,  2088,  2254,  2089,  2090,
    2091,  2256,  2257,  2092,  2258,  2260,  2261,  2093,  2262,  2263,
    2729,  2094,  2266,  2267,  2095,  2268,  2096,  2097,  2098,   364,
    2099,   365,  2100,  2101,  2277,  2278,   366,   827,  2280,  2730,
    2281,  1564,  2282,  2283,  2102,  2103,   828,  2104,  2284,  2105,
    2106,  2285,  2109,  2286,  2111,  1676,  2113,  2287,  2288,  2116,
    2289,  1919,  2114,  2290,  2291,  2292,  2293,  2294,  2295,  2115,
    2296,  2297,  2298,  2231,  2299,  2300,  2301,  2302,  2303,  2232,
    2233,  2304,  2305,  2306,  2307,  2242,  2310,  2243,  2255,  2949,
    2322,  2323,  2311,  2324,  2325,  2312,  2326,  2313,  2327,  2314,
    2315,  2316,  2328,  2329,  2330,  2331,  2229,  2332,     0,  2333,
    2317,  2318,  2334,  2335,  2319,  2336,  2337,  2338,   829,  2339,
    2340,  1542,  2341,  2342,  2343,  2344,  2345,  2346,  2347,  1565,
    2348,  2350,  1567,  2351,  2352,  2353,  1566,  2356,  2357,  2358,
    2359,  2360,  2361,  2363,  2615,  2362,  2364,  2365,  1568,  2366,
    2367,  2368,  2369,  2370,  2349,  2371,  2372,   797,  2373,  2374,
    2375,  2376,  2377,  2378,  2379,  2380,  2381,  2382,  2383,  2384,
    2385,  2386,  2387,     0,  2388,  2389,  2390,     0,  2391,  2392,
    2393,  2394,  2395,     0,  2396,  2397,  2398,  2201,  2399,  3060,
    2400,     0,  2401,  2402,  2403,  2404,  2405,     0,  2406,  2407,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  2408,     0,  2409,  2410,  2411,  2412,
    2413,  2414,  2415,  2416,  2417,  2418,  1410,  2421,  1136,  1137,
    2422,  2423,  1140,  2424,  2425,     0,  2426,  2427,  2428,  2540,
    2429,  2430,  2541,  2431,  2432,  2433,     0,  2434,  2435,  2472,
    2436,  2238,  2239,  2240,  2437,  2445,  2438,  2439,  2440,  2441,
    2442,     0,  2443,  2444,  2446,     0,  2447,  2448,  2449,     0,
    2450,  2451,  2452,     0,  2453,  2454,  2461,     0,  2462,  2471,
    2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2473,     0,
    2474,  2477,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,  1116,  2475,  1136,  1137,  1140,  2476,
    2482,  2483,  2484,  2485,  2486,  2487,     0,  2488,  2489,     0,
    2490,  2491,  2492,  2493,  2494,  2497,  2498,  2499,  2500,  2501,
       0,  2502,  2522,  2505,  2523,  2506,  2524,  2507,  2525,  2508,
    2509,  2510,  2511,  2526,  2527,  2512,  2528,  2529,  2530,  2531,
    2513,  2532,  2533,  2534,  2535,  2514,  2515,  2516,  2536,  2517,
    2518,  2537,  2539,  2519,  2520,  2521,  2598,  2545,  2651,     0,
    2654,  2655,  2546,  2656,  2547,  2548,  2549,  2550,  2551,  2552,
    2553,  2554,  2657,  2555,  2557,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,  2569,  2570,  2658,  2571,  2659,
    2660,  2661,     0,  2662,  2663,  2664,  2577,  2665,     0,  2666,
    2578,  2579,  2667,  2669,  2670,  2671,     0,  2674,  2675,  2676,
    2582,  2583,  2685,  2686,  2687,  2688,  2689,     0,  2694,  2695,
    2584,  2585,  2586,  2587,  2588,  2696,  2589,  2590,  2697,  2591,
    2592,  2700,  2701,  2702,  2593,  2594,  2703,  2595,  2596,  2704,
    2705,  2706,     0,  2707,  2708,  2709,  2710,  2599,  2711,  2712,
    2713,  2601,  2714,  2602,  2603,  2715,  2716,  2717,     0,  2718,
    2719,  2720,  2727,  2608,  2609,  2610,  2721,  2722,  2613,  2614,
    2723,  2724,  2725,  2726,  2616,  2728,  2618,  2731,  2619,  2732,
    2620,  2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,  2733,
    2629,  2630,  2631,  2632,  2734,  2735,     0,  2736,  2737,     0,
    2738,  2739,  2742,  2745,  2635,  2636,  2637,  2638,  2743,  2744,
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
       0,  2259,     0,     0,   360,     0,     0,     1,     2,     3,
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
     807,    10,    27,    13,    14,    10,    20,   376,   377,    27,
      27,    10,    96,    27,    96,    82,    27,    31,   103,    31,
      82,    35,   103,    96,     0,    37,   479,    83,    84,   398,
     399,    18,    13,   479,    48,    47,    48,    13,   102,    97,
      98,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   103,    82,    38,    96,    39,
      18,    82,    37,    99,   100,    46,    31,   303,   304,   602,
     603,    25,    47,   606,   479,    97,    98,   103,    24,   484,
     479,    25,   103,    48,    20,   484,   484,   220,   481,    31,
     131,    27,   485,    27,    31,    31,   137,    31,   108,    35,
     197,   198,   199,    24,    27,    31,    48,    37,    31,    30,
      30,    48,    48,    27,    48,    31,    30,    47,   132,   355,
      36,   131,    48,    25,    26,    48,   479,   479,   480,   482,
     482,   484,    48,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   481,   680,   681,   682,
     485,    92,    93,   479,   478,   131,   480,   481,   484,    63,
      64,   485,   103,    67,    68,    69,    70,    71,    72,   197,
     198,   199,   182,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   479,    20,   130,   482,
     144,   135,   479,   130,    27,     0,   132,   484,    31,   479,
     144,   490,    35,   492,   130,    10,   495,   126,   127,    92,
      93,    31,   479,   200,   481,    48,   484,   484,    92,    93,
     103,   231,   487,   488,   234,   179,   145,   237,    48,   103,
     484,   479,   480,   243,   244,   179,   484,   247,   248,   336,
     337,   338,   339,   253,   254,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   179,   179,
     235,   236,   237,   273,   274,   479,   482,   243,   482,   244,
     245,   246,   247,   479,   249,   481,   197,   197,   484,   126,
     127,   128,  2699,  2700,  2701,   187,   188,   479,    31,    32,
      33,   479,   302,   303,    37,   305,   306,   479,   145,   132,
     105,   342,   479,   479,    47,    48,   482,   112,   484,   479,
      13,    14,   482,    16,   484,   290,    99,   100,   293,   294,
     295,   296,   479,   298,   299,   366,   131,   302,   479,   480,
     484,   307,   479,   484,   481,   482,   346,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   484,   221,   222,   357,   224,   358,   359,
     484,   391,   392,   393,   479,   480,   479,   480,   490,   484,
     492,   484,   483,   403,   485,   405,   406,   484,   479,   484,
     479,   485,   412,   485,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   484,   951,   952,
     482,   954,   479,   435,   497,   434,   490,   403,   484,   409,
     410,   411,   412,   413,   414,   493,   494,   417,   418,   419,
     420,   421,   422,   423,   480,   403,   404,   405,   406,   478,
     396,   480,   481,   479,   479,   479,   482,   482,   484,   497,
     364,   479,   479,   479,   482,    30,   480,   600,   479,   478,
     480,   493,   494,   478,   479,   396,   396,   396,   397,   478,
     455,   456,   457,   479,   479,   479,   461,   482,   463,  2906,
     478,  2908,   480,   481,  2911,  2912,   487,   488,    27,   479,
     197,   198,   199,    31,    32,    33,   479,   487,   488,    37,
     490,   491,   479,   480,   486,   479,   479,   484,   482,    47,
      48,    99,   100,   226,   479,   127,   479,   374,   375,   336,
     337,   338,   339,    23,    24,   238,   479,   496,   343,   482,
      30,   479,   239,   495,   247,   248,   679,   487,   488,   478,
     397,   480,   481,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   181,   182,    95,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   479,   179,   180,   181,
     182,   479,   992,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   440,   441,   442,   443,   444,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   181,
     182,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,   117,   404,   405,
    3047,   440,   441,   442,   443,   444,   187,   188,   479,   336,
     337,   338,   339,   364,   347,   303,    31,    32,    33,   659,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   480,   481,   479,   370,   371,    30,
      31,    32,    33,   479,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   479,   179,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   479,
     403,  1149,  1150,  1151,  1152,   479,   101,   197,   482,   479,
     200,   201,   202,   203,   487,   488,    99,   100,   480,   481,
     303,   304,  1529,    25,    26,   480,   481,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     480,   481,   232,   233,   234,   480,   481,   480,   481,   480,
     481,   479,   793,   480,   481,   602,   603,   480,   481,   606,
     480,   481,   479,  1016,   480,   481,   479,  1149,  1150,  1151,
    1152,  1153,  1154,   480,   481,   480,   481,   480,  1147,  1148,
     479,   791,   482,   197,   198,   199,   200,   480,   481,   480,
     481,   480,   481,   480,   481,   480,   481,   480,   481,   480,
     481,   480,   481,   480,   481,   480,   481,   480,   481,   480,
     481,   480,   481,   480,   481,   479,   230,   950,   480,   481,
     480,   481,   368,   369,   238,   480,   481,   480,   481,   480,
     481,   480,   481,   480,   481,   480,   481,   251,   480,   481,
     480,   481,   480,   481,   480,   481,   480,   481,   480,   481,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   781,   479,   783,   784,   785,   480,   481,   480,
     481,   361,   362,   480,   481,   480,   481,   480,   481,  1012,
     294,   479,   296,   297,   298,   480,   481,   480,   481,   379,
     480,   481,   479,   307,   308,   480,   481,   382,   383,   313,
     314,   315,   316,   480,   481,   479,   396,   480,   481,   480,
     481,   402,   326,   327,   328,   329,   330,   479,   332,   333,
     484,   335,   482,  1270,   480,   481,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   480,   481,   480,   481,  1147,  1148,   479,  1153,  1154,
     398,   399,   655,   484,   302,   965,   966,   967,   968,   969,
     970,   971,   484,   973,   974,   484,   484,   484,   978,   979,
     980,   981,   982,   983,   984,   484,   986,   482,   988,    27,
     990,   991,    27,   993,   994,   995,   996,   997,    27,   103,
      28,    27,  1002,  1003,  1004,  1005,  1529,   305,   479,   307,
     480,   309,   310,  1013,    36,   480,  1016,   480,   480,   317,
     135,   481,   320,   321,   322,   323,   324,   325,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,    24,   951,   952,   479,   954,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   460,   479,   356,   479,
     479,   479,   360,   479,   479,   479,   479,   365,   366,   479,
     479,  1594,   479,   479,   479,   486,   479,   375,   479,   479,
     479,   479,   380,   381,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   103,    95,   479,   481,   479,   479,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,   479,   951,   952,   484,   954,   479,   484,
    1363,   479,   479,   479,   479,   479,   479,   479,    29,   479,
    1161,   479,   479,   479,   479,   479,   479,   479,   479,  1139,
     479,  1141,  1142,   479,   484,   479,   479,   484,   841,   484,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,  1169,
     479,   479,  1172,   479,  1174,   479,  1176,   479,  1178,   479,
     479,   484,   479,   479,   479,   479,   479,    36,   479,   479,
    1590,   479,   479,   886,   479,   479,   889,   479,   479,   479,
     479,  1201,   479,  1203,  1204,  1205,   479,   479,   479,   479,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,   479,  1218,   479,
     479,   479,   479,   479,   479,   479,   479,   479,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,   479,   479,   479,   479,   479,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,   479,   479,   479,   479,   479,
    1260,  1261,   479,  1263,   479,   479,   479,   496,   484,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,  1281,   479,  1283,   479,   479,   482,   480,   479,   479,
    1290,   483,  1292,  1293,   483,   481,   484,   484,   480,   484,
    1300,  1301,  1302,  1303,  1304,  1305,   480,  1144,  1145,   480,
     483,   480,   479,  1006,   480,   483,  1009,   481,   483,  1012,
     479,   479,   479,  1016,   479,   479,   479,   479,   479,   479,
    1330,  1331,  1669,  1333,  1334,  1335,  1336,  1337,  1338,   479,
    1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,   479,   479,
    1350,   479,  1352,  1353,   479,  1355,  1356,  1357,   479,  1359,
    1360,   479,   479,  1363,   480,  1365,   479,  1367,  1368,   479,
     479,   479,   479,   479,   479,    38,   479,   479,   479,   479,
     479,   479,   479,   479,   479,  1078,  1079,   479,   479,   479,
     479,   479,   479,   479,    44,   479,   481,   480,  1921,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   483,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   480,   480,   483,   481,   481,
     481,   480,   480,   479,   481,   480,  1129,   135,   136,   137,
     138,   139,   140,   141,   142,   143,  1139,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   480,  1162,
    1163,   481,   480,  1166,   480,   480,   479,   481,   331,   481,
     481,   479,  1175,   181,   182,   481,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,    38,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   479,   479,   479,   479,
     484,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,    29,
     479,    32,   482,   479,   479,   479,   484,   479,   479,   479,
     179,   484,   179,  1266,   483,   483,   454,   480,   480,    32,
      34,    33,    33,    44,   103,    35,    35,   103,   483,    44,
     303,  1284,   480,   479,   479,   479,   479,   426,   451,    30,
      30,    30,  1295,    30,    30,   103,   239,    46,   480,   484,
     481,   481,   481,   481,   480,   480,   469,   481,   481,   480,
    1313,   480,   480,   483,   481,   481,   481,   481,   480,  1322,
     481,   481,  1663,   480,   355,   481,   481,   481,   480,   479,
     481,   480,   479,   481,   480,   480,   103,   481,   481,   481,
     481,   481,   480,   480,    27,   481,   481,   480,   480,   479,
     481,   480,  1662,   480,   480,   483,   481,   481,  1361,   480,
    1363,  1364,   484,   481,   481,   481,  1369,   481,   481,  2016,
    1680,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   480,   396,   481,   481,   481,   481,   479,   481,
     480,    44,   481,   481,   481,   481,   481,   481,   481,   481,
     480,   480,   480,   479,   481,   480,    30,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   480,
      30,   481,   481,   481,   481,   481,   481,   480,   480,   483,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   480,   480,   480,   480,  1757,  1758,  1759,
    1760,   480,  1762,   480,  1764,   480,   427,   481,   479,   481,
    1770,  1771,  1772,   481,   481,  1775,  1776,  1777,  1778,   481,
    1780,   481,  1782,   480,  1784,   481,   481,  1787,  1788,  1789,
    1790,   480,   480,   480,  1794,   481,   479,  1797,   479,   479,
     485,   480,    30,   481,   481,  1805,   481,  1807,   480,   479,
     481,  1811,  1812,   481,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,   481,  1827,   481,   480,
      30,   480,   480,   480,   480,   480,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,   481,   480,    30,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,  1858,  1859,
    1860,  1861,   480,   480,   480,  1865,  1866,  1867,  1868,   481,
     480,    46,   483,   481,   480,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,   480,   480,   480,   480,
     480,   480,   480,  1893,  1894,  1895,   480,  1897,  1898,   480,
    1900,  1901,   480,   480,  1904,   481,  1906,   481,   480,   480,
     480,   480,    27,   481,   480,   480,   480,   480,   480,  1919,
     481,   480,   480,   483,   481,   481,   481,   481,  1928,  1929,
     480,   484,   481,  1933,   481,   481,   481,  1937,   481,   483,
     481,   480,    27,   481,   481,   481,   480,   131,   481,   481,
     480,   384,   481,  1953,   480,  1955,   480,   480,   485,   481,
     481,   481,   480,   480,   103,   385,   481,   481,   481,  1969,
     481,   481,   481,   481,   481,   481,   481,   481,   480,   386,
     481,   481,   481,   480,  1984,   481,  1986,  2018,   480,   480,
     480,  1991,   480,   480,   131,   481,   480,  1997,   481,   481,
     481,  2001,  2002,   480,  2004,  2005,  2006,   480,  2008,  2009,
     485,   480,  2012,  2013,   480,  2015,   480,   480,   480,   131,
     480,   131,   481,   481,  2024,  2025,   131,   387,  2028,   485,
    2030,  1155,  2032,  2033,   480,   480,   388,   481,  2038,   480,
     480,  2041,   480,  2043,   480,  1289,   481,  2047,  2048,   481,
    2050,   485,   480,  2053,  2054,  2055,  2056,  2057,  2058,   480,
    2060,  2061,  2062,   480,  2064,  2065,  2066,  2067,  2068,   480,
     480,  2071,  2072,  2073,  2074,   480,  2076,   480,   480,   485,
     481,   480,  2082,   481,   480,  2085,   481,  2087,   480,  2089,
    2090,  2091,   481,   480,   480,   480,  1921,   480,    -1,   481,
    2100,  2101,   481,   480,  2104,   481,   481,   481,   389,   481,
     480,  1143,   481,   481,   481,   481,   480,   480,   480,  1156,
     481,   480,  1158,   481,   481,   480,  1157,   481,   481,   480,
     480,   480,   480,   480,  2471,   481,   481,   481,  1159,   481,
     481,   481,   481,   481,  2144,   481,   480,   343,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   480,    -1,   481,   481,   481,    -1,   481,   481,
     481,   480,   480,    -1,   481,   480,   480,  1870,   480,   485,
     481,    -1,   481,   480,   480,   480,   480,    -1,   481,   480,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   480,    -1,   481,   481,   481,   480,
     480,   480,   480,   480,   480,   480,   999,   481,   602,   603,
     481,   481,   606,   481,   480,    -1,   481,   481,   480,  2352,
     481,   481,  2355,   480,   480,   480,    -1,   481,   481,  2270,
     480,  1934,  1935,  1936,   481,  2245,   481,   480,   480,   480,
     480,    -1,   481,   480,   480,    -1,   481,   480,   480,    -1,
     481,   481,   480,    -1,   481,   481,   480,    -1,   481,  2269,
     481,   481,   481,   481,   481,   481,   481,   480,   480,    -1,
     481,   480,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   481,   680,   681,   682,   481,
     481,   481,   481,   481,   481,   481,    -1,   481,   480,    -1,
     481,   481,   481,   481,   480,   480,   480,   480,   480,   480,
      -1,   481,  2322,   481,  2324,   481,  2326,   481,  2328,   481,
     481,   481,   480,  2333,  2334,   481,  2336,  2337,  2338,  2339,
     481,  2341,  2342,  2343,  2344,   481,   481,   481,  2348,   481,
     481,  2351,  2352,   481,   481,   480,   480,  2357,   480,    -1,
     481,   480,  2362,   481,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,   481,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,  2383,  2384,  2385,  2386,   480,  2388,   481,
     481,   480,    -1,   481,   481,   481,  2396,   480,    -1,   481,
    2400,  2401,   481,   481,   481,   480,    -1,   481,   481,   481,
    2410,  2411,   481,   481,   481,   481,   480,    -1,   481,   481,
    2420,  2421,  2422,  2423,  2424,   481,  2426,  2427,   481,  2429,
    2430,   481,   481,   481,  2434,  2435,   481,  2437,  2438,   481,
     481,   480,    -1,   481,   481,   481,   481,  2447,   481,   481,
     481,  2451,   480,  2453,  2454,   480,   480,   480,    -1,   481,
     481,   480,   480,  2463,  2464,  2465,   481,   481,  2468,  2469,
     481,   481,   481,   481,  2474,   481,  2476,   480,  2478,   480,
    2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,   481,
    2490,  2491,  2492,  2493,   481,   480,    -1,   481,   480,    -1,
     481,   480,   480,   480,  2504,  2505,  2506,  2507,   481,   481,
    2510,   481,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,
    2520,   481,   480,   480,    -1,   481,   481,   481,   480,   480,
      -1,   481,   481,   480,   480,   480,   480,   480,    -1,   481,
     481,   481,   481,   481,   480,   480,  2669,   480,    -1,   481,
    2673,   480,   480,   937,   938,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   481,   951,   952,   481,
     954,   481,   480,   480,   480,   480,   480,   480,   480,   480,
     480,    -1,   481,   480,  2615,   480,    -1,   481,   481,   481,
     480,   480,   480,    -1,   481,   481,   481,   480,    -1,   481,
     481,   481,   481,   481,   481,   481,   480,    -1,   481,   481,
     481,   481,   481,   481,   480,   480,   480,    -1,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   480,   480,
     480,   480,    -1,   481,   481,   481,   480,    -1,   481,   480,
     480,    -1,   481,   480,   480,    -1,   481,   481,   480,    -1,
     481,   481,   481,  2653,  2654,   481,  2656,  2657,   480,  2659,
    2660,   480,  2662,  2663,  2664,   481,  2666,  2667,   481,   480,
    2670,   481,   481,   481,   481,  2675,  2676,   481,  2678,   480,
    2680,   481,  2682,   481,  2684,  2685,  2686,  2687,  2688,   481,
     481,   480,  2692,  2693,  2694,  2695,  2696,  2697,   481,  2699,
    2700,  2701,  2702,  2703,  2704,  2705,   481,  2707,  2708,  2709,
    2710,  2711,   480,  2713,   480,    -1,   481,   480,  2718,  2719,
     480,  2721,  2722,  2723,  2724,  2725,  2726,   480,  2728,  2729,
    2730,   480,   480,   480,  2734,   481,  2736,   480,  2738,   481,
     480,  2741,   480,  2743,  2744,   481,  2746,   480,   480,   480,
    2443,   480,   480,  2753,   481,  2755,   480,   480,  2758,  2759,
    1144,  1145,  1146,   480,  2887,  2765,  2766,  2767,  2768,  2769,
     481,   481,   480,    -1,   481,  2775,  2776,  2777,   480,    -1,
     481,   480,    -1,   481,   481,   480,    -1,   481,   481,   481,
     481,   481,   481,   480,    -1,   481,   481,   481,   481,   481,
     481,   480,   480,    -1,   481,   480,    -1,   481,   481,   481,
     480,   480,   480,    -1,   481,   480,    -1,   481,   481,   480,
      -1,   481,   481,   480,    -1,   481,   481,   481,   481,   481,
     481,   481,   481,   480,    -1,   481,   481,   480,   480,   480,
     480,   480,    -1,   481,   481,   481,   480,   480,   480,    -1,
     481,   481,   481,   480,    -1,   481,   481,   480,    -1,   481,
     481,   480,    -1,   481,   480,    -1,   481,   481,   480,    -1,
     481,  2871,   480,   480,  2874,  2875,  2876,   481,   481,   481,
    2880,   481,  2882,  2883,   481,   480,   480,   480,  2888,  2889,
     481,  2891,   481,  2893,  2894,  2895,  2896,  2897,  2898,   481,
    2900,  2901,  2902,  2903,  2904,  2905,  2906,   481,  2908,   481,
     481,  2911,  2912,  2913,  2914,  2915,   480,    -1,   481,   481,
     481,  2921,  2922,   480,   480,  2925,    -1,    -1,    -1,  2929,
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
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
      -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   600,   601,   602,   603,    -1,    -1,   606,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,   359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,    -1,   397,    -1,    -1,    -1,    -1,   807,
      -1,    -1,    -1,    -1,   407,   408,   409,   410,   411,   412,
     413,   414,    -1,    -1,   417,   418,   419,   420,   421,   422,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   841,   437,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,   886,    -1,
      -1,   889,    -1,    -1,   487,   488,   489,   490,   491,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,  1756,    -1,
      -1,    -1,   132,    -1,   134,    -1,    -1,    -1,    -1,    -1,
    1768,  1769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1796,    -1,
    1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1809,  1810,    -1,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,   219,
    1848,    -1,  1850,  1851,  1852,  1853,  1854,    -1,  1856,  1857,
      -1,    -1,    -1,    -1,  1862,  1863,    -1,    -1,    -1,    -1,
      -1,  1869,  1870,    -1,    -1,  1873,  1874,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1899,    -1,    -1,  1902,    -1,    -1,    -1,    -1,  1907,
      -1,    -1,  1910,    -1,    -1,    -1,    -1,    -1,   288,   289,
      -1,    -1,    -1,  1921,  1922,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1934,  1935,  1936,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1946,    -1,
      -1,    -1,    -1,  1951,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1972,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2004,    -1,    -1,    -1,
      -1,    -1,  2010,  2011,    -1,    -1,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,    -1,   397,    -1,  2027,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,
     410,   411,   412,   413,   414,    -1,    -1,   417,   418,   419,
     420,   421,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2074,  2075,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,
      -1,    -1,    -1,    -1,    -1,   485,    -1,   487,   488,   489,
     490,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2351,    -1,    -1,    -1,  2355,  2356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2373,  2374,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2389,  2390,  2391,  2392,  2393,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2406,    -1,
      -1,  2409,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2443,    -1,    -1,    -1,    -1,
      -1,    -1,  2450,    -1,    -1,    -1,    -1,    -1,  2456,    -1,
    2458,    -1,  2460,    -1,  2462,    -1,    -1,    -1,  2466,  2467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2496,    -1,
      -1,    -1,    -1,    -1,  2502,    -1,    -1,    -1,    -1,    -1,
    2508,  2509,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,   418,   419,   420,   421,   422,   423,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   437,     0,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   487,   488,   489,   490,   491,    -1,    -1,
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
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,  2906,    -1,
    2908,    -1,    -1,  2911,  2912,    20,    -1,    -1,  2916,  2917,
    2918,  2919,    27,    -1,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    47,    48,    -1,    -1,    -1,  2945,    -1,  2947,
      -1,    -1,    -1,    -1,   390,   391,    -1,    -1,  2956,    -1,
     396,   397,   398,   399,    -1,    -1,   402,   403,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3047,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3065,    -1,  3067,
      -1,    -1,    -1,    -1,    -1,    -1,  3074,    -1,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3104,    -1,    -1,    -1,
      -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,  3117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3132,    -1,    -1,  3135,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   600,    -1,   602,   603,    -1,    -1,
     606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,   289,  3183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3209,    -1,    -1,    -1,  3213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   407,   408,   409,   410,   411,   412,   413,   414,
      -1,    -1,   417,   418,   419,   420,   421,   422,   423,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,   769,   770,   771,   772,   773,   774,   775,
     776,   777,   778,   779,   780,   781,   782,   783,   784,   785,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,   488,   489,   490,   491,    -1,    -1,    -1,
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
      -1,    -1,    -1,  1339,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1349,    -1,  1351,    -1,    -1,    -1,    -1,
      -1,    -1,  1358,    -1,    -1,    -1,    29,  1363,    31,    32,
      33,    34,    -1,    36,    37,    -1,    39,    40,    -1,    -1,
     390,   391,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,
     400,    -1,   402,   403,   247,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,   277,   278,    -1,   280,    -1,   282,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,   291,    -1,
      -1,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1529,    -1,    -1,    -1,   390,   391,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,
     403,    -1,    -1,    -1,   217,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,   601,   602,   603,    -1,  1591,   606,    -1,  1594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1647,    -1,    -1,    -1,    -1,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,   359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,    -1,   397,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,   408,   409,   410,   411,   412,
     413,   414,    -1,    -1,   417,   418,   419,   420,   421,   422,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1809,    -1,    -1,   479,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   487,   488,   489,   490,   491,    -1,
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
      -1,    -1,    -1,     8,    -1,  1358,  2502,    -1,    -1,    -1,
    1363,    -1,  2508,  2509,    -1,    -1,    -1,    -1,    -1,  1529,
      -1,    -1,  1532,    -1,    29,    -1,    31,    32,    33,    34,
      -1,    36,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1590,  1591,    -1,    -1,  1594,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2773,    -1,    -1,
      -1,    -1,    -1,   288,   289,    -1,    -1,    -1,  1798,    -1,
      -1,    -1,    -1,    -1,  1647,    -1,    -1,    -1,    -1,  1809,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1830,  1831,    -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1862,  1863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,    -1,   397,    -1,    -1,    -1,    -1,  1907,    -1,    -1,
    1910,    -1,   407,   408,   409,   410,   411,   412,   413,   414,
      -1,  1921,   417,   418,   419,   420,   421,   422,   423,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,    -1,    -1,    -1,  1946,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1798,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
    2956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,  1830,  1831,    -1,
      -1,    -1,   487,   488,   489,   490,   491,    -1,    -1,    -1,
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
      -1,  2004,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,  3191,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,  3213,    -1,    -1,
      -1,  2074,  2075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,   219,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2406,    -1,    -1,  2409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,   288,   289,    -1,    -1,  2456,    -1,  2458,    -1,
    2460,    -1,  2462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,
      -1,    -1,  2502,    -1,    -1,    -1,    -1,    -1,  2508,  2509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   358,   359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
      -1,   397,   398,  2406,    -1,   401,  2409,    -1,    -1,    -1,
      -1,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
      -1,   417,   418,   419,   420,   421,   422,   423,    -1,   425,
      -1,    -1,    -1,   429,    -1,   431,   432,    -1,    -1,    -1,
     436,   437,    -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,
     446,    -1,    -1,  2456,    -1,  2458,    -1,  2460,    -1,  2462,
      -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,
      -1,   467,   468,    -1,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   487,   488,   489,   490,   491,    -1,    -1,    -1,  2502,
      -1,    -1,    -1,    -1,    -1,  2508,  2509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2748,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2773,    -1,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
     219,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,  2748,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   271,   272,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2956,   286,   287,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,
     359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,    -1,   397,   398,
      -1,    -1,   401,    -1,  3074,    -1,    -1,    -1,   407,   408,
     409,   410,   411,   412,   413,   414,    -1,    -1,   417,   418,
     419,   420,   421,   422,   423,    -1,   425,    -1,    -1,    -1,
     429,    -1,   431,   432,  3104,    -1,    -1,   436,   437,    -1,
     439,    -1,    -1,  2956,    -1,    -1,    -1,   446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3132,   462,    -1,  3135,    -1,    -1,   467,   468,
      -1,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   488,
     489,   490,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3191,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,  3213,    -1,    -1,    27,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,  3074,    43,    -1,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3132,
      -1,    -1,  3135,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,    -1,
      -1,   132,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3191,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    -1,    -1,
    3213,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
      -1,    -1,    -1,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,    -1,    -1,   288,   289,   290,
      -1,    -1,   293,   294,   295,   296,    -1,   298,   299,   300,
     301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   357,   358,   359,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,    -1,   397,    -1,   399,   400,
      -1,   402,    -1,    -1,    -1,    -1,   407,   408,   409,   410,
     411,   412,   413,   414,    -1,    -1,   417,   418,   419,   420,
     421,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,
      -1,   452,   453,    -1,   455,   456,   457,   458,   459,    -1,
     461,    -1,   463,   464,   465,   466,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    12,    -1,   479,    -1,
      -1,    -1,    -1,    -1,    20,    -1,   487,   488,   489,   490,
     491,    27,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,    -1,    -1,   132,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    -1,    -1,    -1,    -1,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,    -1,    -1,    -1,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
      -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,   301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   358,   359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
      -1,   397,    -1,   399,   400,    -1,    -1,    -1,    -1,    -1,
      -1,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
      -1,   417,   418,   419,   420,   421,   422,   423,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   447,   448,   449,   450,    -1,   452,   453,    -1,    -1,
      -1,    -1,   458,   459,    -1,    -1,    -1,    -1,   464,   465,
     466,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      11,    12,    -1,   479,    -1,    -1,    -1,    -1,    -1,    20,
      -1,   487,   488,   489,   490,   491,    27,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,    -1,
      -1,   132,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
      -1,    -1,    -1,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,    -1,    -1,   288,   289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,    -1,   397,    -1,   399,   400,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,
     411,   412,   413,   414,    -1,    -1,   417,   418,   419,   420,
     421,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,
      -1,   452,   453,    -1,    -1,    -1,    -1,   458,   459,    -1,
      -1,    -1,    -1,   464,   465,   466,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    12,    -1,   479,    -1,
      -1,    -1,    -1,    -1,    20,   486,   487,   488,   489,   490,
     491,    27,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,    -1,    -1,   132,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    -1,    -1,    -1,    -1,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,    -1,    -1,    -1,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
      -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,   301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
      -1,   397,    -1,   399,   400,    -1,    -1,    -1,    -1,    -1,
      -1,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
      -1,   417,   418,   419,   420,   421,   422,   423,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   447,   448,   449,   450,    -1,   452,   453,    -1,    -1,
      -1,    -1,   458,   459,    -1,    -1,    -1,    -1,   464,   465,
     466,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      11,    12,    -1,   479,    -1,    -1,    -1,    -1,    -1,    20,
     486,   487,   488,   489,   490,   491,    27,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,    -1,
      -1,   132,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
      -1,    -1,    -1,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,    -1,    -1,   288,   289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,    -1,   397,    -1,   399,   400,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,
     411,   412,   413,   414,    -1,    -1,   417,   418,   419,   420,
     421,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,
      -1,   452,   453,    -1,    -1,    -1,    -1,   458,   459,    -1,
      -1,    -1,    -1,   464,   465,   466,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    12,    -1,    -1,    -1,   479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   487,   488,   489,   490,
     491,    29,    -1,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    45,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    -1,    -1,    -1,    -1,   183,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,    -1,    -1,    -1,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    -1,    -1,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,    -1,   397,
      -1,   399,   400,    -1,    -1,    -1,    -1,    -1,    -1,   407,
     408,   409,   410,   411,   412,   413,   414,    -1,    -1,   417,
     418,   419,   420,   421,   422,   423,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
     448,   449,   450,    -1,   452,   453,    -1,    -1,    -1,    -1,
     458,   459,    -1,    -1,    -1,    -1,   464,   465,   466,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    11,    12,    -1,    -1,
      -1,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,
     488,   489,   490,   491,    29,    -1,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    43,    -1,
      45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,   301,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,    -1,   397,    -1,   399,   400,    -1,    -1,    -1,    -1,
      -1,    -1,   407,   408,   409,   410,   411,   412,   413,   414,
      -1,    -1,   417,   418,   419,   420,   421,   422,   423,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   447,   448,   449,   450,    -1,   452,   453,    -1,
      -1,    -1,    -1,   458,   459,    -1,    -1,    -1,    -1,   464,
     465,   466,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,
      12,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,   488,   489,   490,   491,    29,    -1,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    45,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    -1,    -1,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,    -1,    -1,   288,   289,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    32,    33,    34,    -1,    36,    37,    -1,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,    -1,   397,    -1,   399,   400,    -1,
      -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,   411,
     412,   413,   414,    -1,    -1,   417,   418,   419,   420,   421,
     422,   423,   424,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   437,   438,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,   447,   448,   449,   450,    -1,
     452,   453,    -1,   134,    -1,    -1,   458,   459,    -1,    -1,
      -1,    -1,   464,   465,   466,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   487,   488,   489,   490,   491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,    -1,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,
     411,   412,   413,   414,    -1,    -1,   417,   418,   419,   420,
     421,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   437,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   487,   488,   489,   490,
     491,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,    -1,    -1,    -1,   399,   400,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,   409,   410,   411,
     412,   413,   414,    -1,    -1,   417,   418,   419,   420,   421,
     422,   423,   424,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    43,   438,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,   447,   448,   449,   450,    -1,
     452,   453,    -1,    -1,    -1,    -1,   458,   459,    -1,    -1,
      -1,    -1,   464,   465,   466,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   487,   488,    -1,   490,   491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,    -1,    -1,    -1,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   382,   383,   384,   385,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,   400,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,   409,   410,   411,   412,   413,   414,    -1,    -1,   417,
     418,   419,   420,   421,   422,   423,   424,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
     438,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,   447,
     448,   449,   450,    -1,   452,   453,    -1,    -1,    -1,    -1,
     458,   459,    -1,    -1,    -1,    -1,   464,   465,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,
     488,    -1,   490,   491,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,   383,
     384,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   399,   400,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,   418,   419,   420,   421,   422,   423,
     424,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,   438,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,   447,   448,   449,   450,    -1,   452,   453,
      -1,    -1,    -1,    -1,   458,   459,    -1,    -1,    -1,    -1,
     464,   465,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   487,   488,    -1,   490,   491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,    -1,    -1,    -1,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   382,   383,   384,   385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,
     400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
     410,   411,   412,   413,   414,    -1,    -1,   417,   418,   419,
     420,   421,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,
     450,    -1,   452,   453,    -1,    -1,    -1,    -1,   458,   459,
      -1,    -1,    -1,    -1,   464,   465,   466,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   488,    -1,
     490,   491
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    27,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    44,    45,    46,    47,    48,    49,    51,    52,
      53,    54,    55,    56,   104,   105,   106,   107,   108,   119,
     124,   131,   132,   133,   134,   169,   170,   184,   217,   219,
     225,   226,   227,   228,   229,   230,   232,   271,   272,   273,
     286,   287,   288,   289,   334,   358,   359,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   397,   398,   401,
     407,   408,   409,   410,   411,   412,   413,   414,   417,   418,
     419,   420,   421,   422,   423,   425,   429,   431,   432,   436,
     437,   439,   446,   462,   467,   468,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   487,   488,   489,   490,
     491,   499,   500,   501,   502,   503,   504,   505,   508,   509,
     510,   511,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   575,   479,    47,    48,   435,   534,   573,    27,   575,
     534,    32,    33,    34,    35,    36,    39,    40,    45,   124,
     134,   511,   532,   534,   572,   573,    39,   409,   410,   411,
     412,   413,   414,   417,   418,   419,   420,   421,   422,   423,
     479,   487,   488,   511,   518,   532,   479,   511,   534,    92,
      93,   103,    92,    93,   103,    92,    93,   103,   103,   484,
      83,    84,   484,   103,   479,   103,   484,   479,   479,   500,
     484,   484,    82,   482,   482,    32,    33,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   534,   576,   479,   479,   479,   479,   482,   479,   479,
     482,   479,   482,   479,   484,   484,   484,   484,   479,   479,
     479,   482,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   519,   534,   559,   519,   559,   519,   559,   519,   559,
     519,   559,   519,   559,   519,   559,   519,   559,   519,   559,
     519,   559,   519,   559,   519,   559,   519,   559,   575,   512,
     513,   532,    27,   479,   479,   575,   479,   479,   479,   479,
     479,   479,   532,   533,   572,   519,   559,   519,   559,   519,
       0,   500,   501,   502,   503,   504,   505,   500,   487,   488,
      99,   100,   519,   559,   490,   492,   487,   488,    97,    98,
     493,   494,    99,   100,   486,   495,   496,    95,    96,   497,
      82,   103,   479,   482,   484,   101,   102,   490,   487,   488,
      82,   484,    82,   103,   532,   482,   482,   484,   484,   484,
     484,   484,   479,   484,   484,   511,   484,   532,   532,   532,
     511,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   331,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   451,   469,   573,   573,   305,   307,
     309,   310,   317,   320,   321,   322,   323,   324,   325,   356,
     360,   365,   366,   375,   380,   381,   532,   572,   532,   402,
      18,   403,   404,   405,   406,    11,    12,    36,    38,    43,
     105,   109,   110,   111,   112,   113,   114,   115,   116,   118,
     120,   121,   122,   123,   124,   125,   126,   128,   129,   134,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   183,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   218,   220,   221,
     222,   223,   224,   231,   240,   241,   242,   243,   248,   250,
     267,   268,   269,   270,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   300,   301,   382,   383,
     384,   385,   399,   400,   409,   410,   411,   412,   413,   414,
     417,   418,   419,   420,   421,   422,   423,   424,   438,   447,
     448,   449,   450,   452,   453,   458,   459,   464,   465,   466,
     479,   486,   487,   488,   506,   511,   518,   532,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   573,   506,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   364,    18,   200,   302,   532,   532,   482,
     532,   532,    36,   105,   124,   134,   409,   410,   411,   412,
     413,   414,   417,   418,   419,   420,   421,   422,   423,   479,
     487,   488,   518,   534,   553,   573,   534,   553,   553,   534,
     553,   534,   553,   534,   127,   179,   180,   181,   182,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   181,   182,   181,   182,   181,   182,   534,   534,   534,
     553,   553,   534,   534,   534,   534,   534,   534,   534,   534,
      27,    27,   532,   532,   534,   532,   534,   532,    39,   409,
     410,   411,   412,   413,   414,   417,   418,   419,   420,   421,
     422,   423,   479,   487,   488,   518,   572,    27,   553,   534,
     484,   103,    28,   512,   500,    47,   575,   576,    27,   479,
     532,   511,    36,   534,   534,   534,   480,   480,   480,   500,
     509,   509,   511,   511,   519,   519,   520,   520,   522,   522,
     522,   522,   523,   523,   524,   525,   526,   527,   528,   529,
     553,    36,   532,   553,   532,   532,    23,    24,   117,   179,
     197,   200,   201,   202,   203,   232,   233,   234,   361,   362,
     379,   396,   575,   559,   519,   559,   520,   560,   520,   560,
     235,   236,   237,   244,   245,   246,   247,   249,   290,   293,
     294,   295,   296,   298,   299,   302,   455,   456,   457,   461,
     463,   573,   574,   197,   198,   199,   200,   230,   238,   251,
     294,   296,   297,   298,   307,   308,   313,   314,   315,   316,
     326,   327,   328,   329,   330,   332,   333,   335,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   460,   302,   553,    11,    13,    38,    41,
      46,    57,   302,   357,   387,   390,   402,   409,   410,   411,
     412,   413,   414,   417,   418,   419,   420,   421,   422,   423,
     479,   487,   488,   511,   518,   532,   553,   554,   572,   573,
     574,   480,   532,   532,   532,   481,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   481,   479,   511,   532,   479,
     479,    27,   479,   479,   484,   484,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   484,   479,   479,   479,   479,   484,   479,   479,
     479,   484,   484,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   534,   538,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   479,   479,
     479,   479,   479,   479,   484,   479,   479,   479,   479,   479,
     533,   553,    32,    33,   534,   573,   539,   539,   480,   481,
     539,   479,   482,   103,   490,   492,   495,   487,   488,    97,
      98,   493,   494,    99,   100,   486,   496,    95,    96,   497,
     484,   480,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   511,   482,   483,
     483,   532,   480,   481,   484,   479,   484,   484,   533,   534,
     479,   480,   484,   480,   483,   480,   480,   483,   480,   483,
     481,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   481,   480,   481,   480,   483,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   480,   480,
     481,   481,   480,   481,   480,   480,   481,   480,   532,   514,
     434,   500,   480,   480,   480,   440,   441,   442,   443,   444,
     507,   481,   480,   481,   481,   481,   481,   479,   517,   485,
     478,   480,   481,   485,   483,   479,   479,   511,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,    27,   479,   479,   479,   479,   479,   479,   484,   511,
     479,   479,   511,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   482,
     482,   479,   484,   479,   479,   482,   479,   479,   479,   479,
     484,   483,   483,   532,   532,   534,   532,   532,   532,   532,
     532,   534,   532,   532,    36,   534,    29,    36,   532,   532,
     532,   532,   532,   532,   532,   553,   532,    38,   532,    44,
     532,   532,   574,   532,   532,   532,   532,   532,   573,    38,
     554,    38,    29,   532,   532,   532,   532,   511,   511,    32,
     511,   533,   534,   532,   303,   303,   304,   506,   534,   553,
     534,   553,   553,   534,   534,   534,   534,   534,   553,   534,
     534,   534,   534,   534,    25,    26,   534,   534,   534,   534,
      25,   144,   179,   553,   553,   534,   179,   179,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   553,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   553,   553,   553,   553,   553,   534,   534,   534,   534,
     534,   573,   573,   511,   511,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   553,   534,
     534,   534,   534,   534,   534,   553,   553,   553,   553,   553,
     534,   553,   553,   454,   553,   553,   553,   553,   511,   480,
     480,    36,   486,   511,   532,   553,   553,    36,   485,   532,
     534,   577,   552,   519,   539,   519,   539,   539,   520,   540,
     520,   540,   522,   543,   522,   543,   522,   543,   522,   543,
     522,   544,   522,   544,   545,   547,   548,   549,   550,   336,
     337,   338,   339,   500,   511,   511,    32,    33,   511,    34,
      33,   532,    35,    35,   532,    44,   532,   511,   532,   532,
     103,   103,   483,    44,   480,   484,   479,   479,   479,   534,
     532,   534,   532,   532,   532,   534,   534,   534,   534,   532,
     532,   532,   532,   532,   532,   532,   534,   532,   534,   534,
     534,   130,   534,   534,   130,   534,   130,   534,   534,   534,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   534,   553,   479,   532,   532,
     532,   532,   532,   532,   532,   534,   534,   534,   532,   532,
     532,   511,   426,   512,    30,    30,    30,    30,    30,   480,
     481,   532,   532,   511,   534,   534,   530,   532,   532,   532,
     103,   511,   534,   534,   534,   532,   534,   532,   534,   532,
     532,   532,   532,   534,   573,   573,   573,   553,   553,   553,
     511,   553,   534,   573,   534,   573,   573,   553,   480,   511,
     553,   553,   553,   553,   553,   239,   532,   532,   532,   532,
     532,   532,   532,   532,   553,   532,   532,   532,   532,   532,
     532,   532,   532,   534,   553,   532,   553,   532,   532,   534,
     532,   532,   532,   553,   532,   532,   511,   355,   506,   511,
     532,    46,   532,   532,   511,   480,   481,   481,   481,   481,
     481,   480,   481,   480,   481,   480,   480,   480,   481,   481,
     481,   481,   481,   480,   480,   481,   481,   481,   481,   480,
     481,   480,   481,   480,   481,   480,   480,   481,   481,   481,
     481,   480,   484,   480,   481,   480,   481,   481,   481,   480,
     480,   481,   480,   480,   480,   481,   484,   481,   480,   481,
     481,   481,   481,   480,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   480,   481,   479,   479,
     481,   481,   481,   479,   479,   480,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   480,   480,   480,   481,   480,
     481,   481,   481,   481,   481,   480,   481,   481,   481,   481,
     481,   481,   481,   481,   480,   481,   481,   481,   481,   481,
     481,   480,   480,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   480,   480,   480,   480,
     480,   480,   480,   481,   481,   481,   480,   481,   481,   481,
     481,   481,   479,   480,   481,   480,   481,   481,   480,   480,
     479,   538,    32,    33,   534,   573,   480,   481,   483,   485,
     483,   485,   479,   479,   479,   479,   480,   480,   481,   481,
     481,   480,   480,   481,   481,   481,   481,   481,   480,   480,
     480,   480,   483,   574,   553,   480,   479,   534,   534,   534,
     480,   481,   480,   481,   480,   481,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   481,
     480,   480,   481,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   481,   480,   481,   480,   480,   480,
     480,   481,   480,   480,   480,   480,   480,   481,   480,   480,
     553,   481,   481,   480,   481,   481,   481,   480,   481,   481,
     481,   481,   481,   481,   480,   481,   532,   500,   512,   440,
     441,   442,   443,   444,   481,   481,   480,   481,   481,   480,
     478,   480,   481,   481,   532,   553,   480,   480,   481,   480,
     480,   481,   480,   481,   480,   480,   480,   481,   481,   480,
     481,   480,   480,   481,   481,   481,   481,   481,   481,   480,
     481,   481,   481,   480,   481,   481,   481,   481,   481,   480,
     480,   481,   481,   481,   481,   481,   479,   480,   480,   480,
     480,   480,   481,   480,   480,   481,   480,   481,   480,   481,
     481,   481,   480,   480,   480,   480,   480,   480,   480,   480,
     481,   481,   480,   480,   481,   480,   480,   483,   483,   480,
     480,   480,   483,   481,   480,   480,   481,   534,   532,   532,
     532,   532,   532,   532,   534,   534,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   534,   532,   553,   103,    27,   532,   532,   553,    27,
     534,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   534,   534,   553,   553,
     534,   534,   534,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   534,   534,   534,   534,   534,   534,   534,   534,
     532,   532,   532,   532,   553,   553,   532,   532,   532,   532,
     534,   511,   534,   534,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     534,   532,   532,   534,   532,   532,   553,   485,   532,   551,
     534,   480,   480,   480,   532,   532,    44,   532,   511,   511,
     511,   532,   480,   480,   480,   481,   534,   532,   532,   532,
     534,   532,   532,   532,   532,   480,   532,   532,   532,   553,
     532,   532,   532,   532,   534,   534,   532,   532,   532,   427,
     512,   500,    30,    30,    30,    30,    30,   532,   532,   534,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   553,   553,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
      46,    27,   481,   480,   481,   480,   481,   480,   481,   480,
     480,   480,   480,   481,   481,   480,   481,   481,   481,   481,
     480,   481,   481,   481,   481,   480,   480,   480,   481,   532,
     480,   481,   481,   480,   480,   481,   481,   481,   480,   480,
     480,   480,   481,   480,   481,   481,   481,   481,   481,   481,
     481,   481,   480,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   480,   481,   481,
     481,   481,   481,   481,   480,   480,   481,   480,   480,   480,
     481,   481,   480,   480,   480,   480,   481,   480,   480,   481,
     481,   481,   480,   480,   480,   480,   480,   480,   480,   480,
     481,   481,   481,   481,   481,   480,   481,   481,   480,   481,
     481,   480,   480,   480,   481,   481,   480,   481,   481,   480,
     480,   480,   480,   481,   480,   532,   480,   481,   480,   480,
     481,   481,   480,   481,   481,   480,   481,   480,   481,   480,
     481,   480,   481,   481,   481,   481,   481,   481,   481,   481,
     480,   532,   500,   480,   481,   481,   481,   480,   478,   480,
     481,   485,   481,   481,   481,   481,   481,   481,   481,   480,
     481,   481,   481,   481,   480,   480,   481,   480,   480,   480,
     480,   480,   481,   480,   481,   481,   481,   481,   481,   481,
     481,   480,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   480,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   534,   532,
     533,   533,   534,    27,   534,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   534,   532,   534,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   534,   534,   534,   534,   534,   532,   532,   532,
     553,   553,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   511,   480,   532,
     534,   532,   532,   532,   553,   553,   553,   553,   532,   532,
     532,   534,   534,   532,   532,   512,   532,   534,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   534,   553,   532,   532,   532,   532,   553,
     553,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   480,   480,   481,   481,   480,   481,   481,   480,   481,
     481,   480,   481,   481,   481,   480,   481,   481,   480,   481,
     481,   480,   480,   481,   481,   481,   481,   480,   481,   480,
     481,   480,   481,   480,   481,   481,   481,   481,   481,   480,
     480,   480,   481,   481,   481,   481,   481,   481,   480,   481,
     481,   481,   481,   481,   481,   481,   480,   481,   481,   481,
     481,   481,   481,   481,   480,   480,   480,   480,   481,   481,
     480,   481,   481,   481,   481,   481,   481,   480,   481,   485,
     485,   480,   480,   481,   481,   480,   481,   480,   481,   480,
     480,   481,   480,   481,   481,   480,   481,   480,   481,   481,
     480,   480,   500,   481,   481,   481,   480,   480,   481,   481,
     480,   480,   480,   480,   480,   481,   481,   481,   481,   481,
     480,   480,   480,   481,   480,   481,   481,   481,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   533,
     532,   533,    27,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     577,   532,   577,   532,   577,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   534,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   511,   532,   532,
     532,   532,   532,   532,   532,   553,   534,   532,   534,   532,
     532,   532,   532,   532,   532,   532,   532,   553,   532,   532,
     532,   481,   480,   480,   481,   481,   481,   480,   480,   480,
     481,   480,   481,   481,   481,   480,   480,   481,   481,   481,
     480,   481,   480,   481,   481,   481,   481,   481,   481,   480,
     481,   481,   481,   481,   481,   481,   481,   480,   481,   480,
     480,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     480,   481,   481,   480,   480,   481,   480,   480,   480,   481,
     481,   481,   480,   483,   481,   480,   480,   480,   481,   481,
     480,   480,   481,   481,   480,   481,   481,   481,   481,   485,
     480,   480,   481,   481,   480,   481,   481,   481,   481,   481,
     532,   532,   532,   532,   532,   532,   532,   511,   533,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   577,   577,   577,   577,   532,   532,
     532,   534,   534,   534,   534,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   534,   532,   534,   532,
     532,   532,   532,   532,   553,   532,   532,   532,   480,   481,
     481,   481,   481,   480,   481,   481,   480,   480,   481,   480,
     480,   480,   480,   480,   480,   481,   480,   481,   480,   481,
     480,   480,   481,   480,   480,   480,   480,   481,   480,   480,
     480,   480,   481,   481,   480,   481,   480,   481,   480,   481,
     485,   481,   480,   481,   481,   481,   481,   481,   481,   480,
     481,   481,   481,   480,   481,   481,   481,   481,   532,   532,
     532,   532,   511,   532,   532,   532,   532,   532,   532,   532,
     577,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     534,   532,   534,   532,   103,   532,   532,   532,   553,   532,
     532,   532,   480,   480,   481,   480,   480,   481,   481,   481,
     480,   480,   480,   481,   480,   481,   481,   480,   481,   481,
     480,   480,   481,   481,   480,   481,   481,   481,   481,   553,
     481,   481,   481,   481,   480,   480,   481,   481,   532,   511,
     532,   532,   532,   532,   532,   532,   532,   553,   532,   553,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   481,
     480,   480,   480,   480,   480,   481,   481,   481,   480,   480,
     480,   481,   481,   481,   480,   481,   481,   480,   480,   481,
     480,   481,   532,   532,   532,   532,   532,   532,   534,   532,
     532,   532,   553,   481,   481,   480,   481,   480,   481,   481,
     480,   481,   480,   481,   532,   532,   532,   532,   534,   532,
     553,   481,   480,   481,   481,   481,   480,   480,   532,   532,
     532,   532,   481,   481,   481,   480,   532,   532,   532,   481,
     481,   481,   532,   532,   532,   480,   481,   481,   532,   532,
     481,   480,   532,   480
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
#line 934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       gr_print("list_command : command\n ");
     ;}
    break;

  case 5:
#line 938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       gr_print("list_command : list_commands command\n ");
     ;}
    break;

  case 14:
#line 948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
                      yyiplineno++;
        ;}
    break;

  case 16:
#line 957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 27:
#line 1243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         ;}
    break;

  case 28:
#line 1248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer()));
          (*m1) = (yyvsp[(3) - (3)].adouble);
       ;}
    break;

  case 44:
#line 1451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          varint = new int((int)(yyvsp[(5) - (6)].adouble));
          Vars.AddVar(type_int,(yyvsp[(1) - (6)].ident),(void*)varint);
          gr_print("command : identifier ASSIGN_OP T_INT(expr)\n ");
        ;}
    break;

  case 50:
#line 1546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        varuchar = new unsigned char((unsigned char)(yyvsp[(5) - (6)].adouble));
        Vars.AddVar(type_uchar,(yyvsp[(1) - (6)].ident),(void*)varuchar);
        gr_print("command : identifier ASSIGN_OP T_UCHAR(expr)\n ");
        ;}
    break;

  case 51:
#line 1554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          varfloat = new float((yyvsp[(3) - (3)].adouble));
          Vars.AddVar(type_float,(yyvsp[(1) - (3)].ident),(void*)varfloat);
          gr_print("command : identifier ASSIGN_OP expr\n ");
        ;}
    break;

  case 52:
#line 1562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yyvsp[(3) - (3)].astring));
          Vars.AddVar(type_string,(yyvsp[(1) - (3)].ident),(void*)varstring);
              delete [] (yyvsp[(3) - (3)].astring);
          gr_print("command : identifier ASSIGN_OP expr_string\n ");
        ;}
    break;

  case 53:
#line 1571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
            rewind(file.get());
        ;}
    break;

  case 56:
#line 1623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 57:
#line 1627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        ;}
    break;

  case 58:
#line 1631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        ;}
    break;

  case 59:
#line 1636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        ;}
    break;

  case 60:
#line 1640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yyvsp[(3) - (4)].adouble)+0.5));
        ;}
    break;

  case 61:
#line 1643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        gr_print("command : QUIT\n ");

        GB_main_wxFrame->Close(true);
    ;}
    break;

  case 62:
#line 1649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))++;
        ;}
    break;

  case 73:
#line 1887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))--;
        ;}
    break;

  case 74:
#line 1891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yyvsp[(1) - (3)].variable)->Pointer()) = (yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 75:
#line 1895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))++;
        ;}
    break;

  case 76:
#line 1899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))--;
        ;}
    break;

  case 77:
#line 1903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yyvsp[(1) - (3)].variable)->Pointer()) = (int) (yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 78:
#line 1907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yyvsp[(1) - (3)].variable)->Pointer()) = (unsigned char) (yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 79:
#line 1911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))++;
        ;}
    break;

  case 80:
#line 1915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yyvsp[(1) - (2)].variable)->Pointer()))--;
        ;}
    break;

  case 81:
#line 1919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yyvsp[(3) - (3)].astring)));
          (yyvsp[(1) - (3)].variable)->SetString(newname);
        ;}
    break;

  case 82:
#line 1924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 83:
#line 1928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yyvsp[(2) - (2)].variable));
        ;}
    break;

  case 84:
#line 1937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yyvsp[(2) - (5)].variable)->Pointer());;
          int  i = (int) (yyvsp[(4) - (5)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        ;}
    break;

  case 85:
#line 1946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yyvsp[(2) - (2)].astring));
         gr_print(" command:  ASHELL ASTRING \n");

         delete [] (yyvsp[(2) - (2)].astring);
           ;}
    break;

  case 86:
#line 1953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
         gr_print("command : LS\n ");
           ;}
    break;

  case 87:
#line 1962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (4)].variable)->Pointer());

          fprintf(file.get(),"%s",(yyvsp[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yyvsp[(4) - (4)].astring);
        ;}
    break;

  case 91:
#line 2286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 94:
#line 2311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 95:
#line 2317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (4)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yyvsp[(4) - (4)].adouble));
          fflush(file.get());
        ;}
    break;

  case 96:
#line 2324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        ;}
    break;

  case 97:
#line 2330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yyvsp[(5) - (8)].adouble), (int) (yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 108:
#line 2528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        ;}
    break;

  case 109:
#line 2535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          draw->SetVectType((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 112:
#line 2581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          draw->SetLineThickness((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 113:
#line 2586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yyvsp[(5) - (8)].adouble);
          int height = (int) (yyvsp[(7) - (8)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yyvsp[(1) - (8)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        ;}
    break;

  case 115:
#line 2610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (16)].variable)->Pointer());
          c.FixeValeur((int)(yyvsp[(11) - (16)].adouble),(int)(yyvsp[(13) - (16)].adouble),(int)(yyvsp[(15) - (16)].adouble));
          draw->DessineCercle( (int) (yyvsp[(5) - (16)].adouble), (int) (yyvsp[(7) - (16)].adouble), (int) (yyvsp[(9) - (16)].adouble), c);
        ;}
    break;

  case 116:
#line 2619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (10)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yyvsp[(7) - (10)].adouble),  (yyvsp[(9) - (10)].adouble));
          //      delete colmap;
        ;}
    break;

  case 117:
#line 2628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yyvsp[(5) - (6)].variable)->Pointer()));

        ;}
    break;

  case 118:
#line 2636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yyvsp[(5) - (6)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        ;}
    break;

  case 127:
#line 2775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->FixeNom( (yyvsp[(5) - (6)].astring));
      delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 136:
#line 2944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 138:
#line 2967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 139:
#line 2972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 140:
#line 2977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 141:
#line 2982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 142:
#line 2987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 148:
#line 3072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 149:
#line 3077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yyvsp[(5) - (8)].adouble),(yyvsp[(7) - (8)].adouble));

    ;}
    break;

  case 150:
#line 3084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

//    sprintf(tmp_string,"error = %f \n",error);
      res_print(tmp_string);
    ;}
    break;

  case 151:
#line 3094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    ;}
    break;

  case 152:
#line 3102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 153:
#line 3107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 154:
#line 3114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 155:
#line 3119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 156:
#line 3124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 159:
#line 3173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 160:
#line 3178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 161:
#line 3183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 162:
#line 3188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 163:
#line 3193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 164:
#line 3198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 165:
#line 3203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 166:
#line 3208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 167:
#line 3213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 168:
#line 3218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 169:
#line 3223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yyvsp[(5) - (6)].adouble));
    ;}
    break;

  case 170:
#line 3228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yyvsp[(5) - (14)].adouble), (int) (yyvsp[(7) - (14)].adouble), (int) (yyvsp[(9) - (14)].adouble), (int) (yyvsp[(11) - (14)].adouble), (int) (yyvsp[(13) - (14)].adouble));
    ;}
    break;

  case 171:
#line 3233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 172:
#line 3238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),(yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 173:
#line 3243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 174:
#line 3248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 175:
#line 3253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yyvsp[(5) - (8)].adouble),(int)(yyvsp[(7) - (8)].adouble));
        ;}
    break;

  case 176:
#line 3258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 177:
#line 3263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yyvsp[(5) - (10)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(7) - (10)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(9) - (10)].variable)->Pointer())->get());
        ;}
    break;

  case 178:
#line 3271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 179:
#line 3276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 180:
#line 3281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 181:
#line 3286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 182:
#line 3291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 183:
#line 3296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 184:
#line 3301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        ;}
    break;

  case 185:
#line 3306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        ;}
    break;

  case 186:
#line 3311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        ;}
    break;

  case 187:
#line 3316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 188:
#line 3321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 189:
#line 3326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    ;}
    break;

  case 190:
#line 3331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    ;}
    break;

  case 191:
#line 3335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->get() , ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );
        ;}
    break;

  case 194:
#line 3380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->get() , ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );
    ;}
    break;

  case 195:
#line 3384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->Write((yyvsp[(4) - (4)].astring));
      delete [] (yyvsp[(4) - (4)].astring);
    ;}
    break;

  case 196:
#line 3390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetOwnMaterial( (int) (yyvsp[(5) - (6)].adouble));

        ;}
    break;

  case 198:
#line 3409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 199:
#line 3415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 200:
#line 3421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yyvsp[(5) - (10)].adouble),(int) (yyvsp[(7) - (10)].adouble),(int) (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 201:
#line 3428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->GetMaterial()._shininess= (yyvsp[(5) - (6)].adouble);

        ;}
    break;

  case 202:
#line 3435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->GetMaterial()._opacity= (yyvsp[(5) - (6)].adouble);

        ;}
    break;

  case 203:
#line 3442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets the object visible or not visible in the scene.
        **/

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetVisible( (int) (yyvsp[(5) - (6)].adouble));

        ;}
    break;

  case 204:
#line 3453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yyvsp[(5) - (6)].adouble)>0.5);

        ;}
    break;

  case 205:
#line 3464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

        ;}
    break;

  case 208:
#line 3502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->SetColors( i , (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));

        ;}
    break;

  case 209:
#line 3511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->SetColors( i );

        ;}
    break;

  case 210:
#line 3520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

        ;}
    break;

  case 211:
#line 3528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->MergePoints((yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 212:
#line 3532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->Triangulate();
        ;}
    break;

  case 213:
#line 3536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        ;}
    break;

  case 215:
#line 3582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      s->Translate( (yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble) );

        ;}
    break;

  case 216:
#line 3589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

      s->Scale( (yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble),0 );

        ;}
    break;

  case 217:
#line 3596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          int          w = (int) (yyvsp[(5) - (6)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        ;}
    break;

  case 218:
#line 3607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

      s->RemoveLine((int)(yyvsp[(5) - (6)].adouble));
          s->GLRecomputeList();

    ;}
    break;

  case 219:
#line 3615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GLRecomputeList();

        ;}
    break;

  case 222:
#line 3648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

      s->RecomputeNormals();

        ;}
    break;

  case 223:
#line 3655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

      s->InvertNormals();

        ;}
    break;

  case 224:
#line 3662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yyvsp[(5) - (6)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 225:
#line 3670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yyvsp[(5) - (6)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 226:
#line 3678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (10)].variable)->Pointer());
      s->AddPoint((yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 231:
#line 3752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      s->NewLine();
    ;}
    break;

  case 232:
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yyvsp[(5) - (6)].adouble) );
    ;}
    break;

  case 233:
#line 3762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      s->EndLine();
    ;}
    break;

  case 234:
#line 3767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yyvsp[(3) - (4)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yyvsp[(3) - (4)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yyvsp[(3) - (4)].astring);
        ;}
    break;

  case 235:
#line 3776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (10)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yyvsp[(5) - (10)].adouble),(yyvsp[(7) - (10)].adouble),(yyvsp[(9) - (10)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 238:
#line 3917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 239:
#line 3925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yyvsp[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        ;}
    break;

  case 240:
#line 3931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yyvsp[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        ;}
    break;

  case 241:
#line 3938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        ;}
    break;

  case 243:
#line 3957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yyvsp[(5) - (6)].adouble) );
          sdraw->Paint();
        ;}
    break;

  case 244:
#line 3964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yyvsp[(1) - (8)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yyvsp[(5) - (8)].adouble), (int) (yyvsp[(7) - (8)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 245:
#line 3971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yyvsp[(5) - (6)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        ;}
    break;

  case 247:
#line 3988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer());
      int num = (int) (yyvsp[(5) - (6)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        ;}
    break;

  case 250:
#line 4024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        ;}
    break;

  case 251:
#line 4029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        ;}
    break;

  case 252:
#line 4037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (8)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yyvsp[(7) - (8)].adouble)>0.5) sdraw->Paint();
          delete tr;
        ;}
    break;

  case 253:
#line 4045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yyvsp[(1) - (10)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yyvsp[(5) - (10)].adouble),(int)(yyvsp[(7) - (10)].adouble),(int)(yyvsp[(9) - (10)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 258:
#line 4098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                   (yyvsp[(3) - (8)].variable)->Name(),
                   (yyvsp[(5) - (8)].adouble), (yyvsp[(7) - (8)].adouble), NULL);
        ;}
    break;

  case 260:
#line 4118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
              (yyvsp[(3) - (6)].variable)->Name(),
              (yyvsp[(5) - (6)].adouble));
        ;}
    break;

  case 272:
#line 4324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get())->SetVoxelSize((yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 277:
#line 4397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->SetVoxelSize((yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 278:
#line 4402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    ;}
    break;

  case 279:
#line 4411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yyvsp[(1) - (10)].variable)->Pointer())->SetTranslation((yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
    ;}
    break;

  case 280:
#line 4416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer();
      (*(InrImage::ptr*) (yyvsp[(1) - (6)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    ;}
    break;

  case 281:
#line 4425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
    ;}
    break;

  case 283:
#line 4446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yyvsp[(3) - (8)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(5) - (8)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yyvsp[(7) - (8)].variable)->Pointer())->get());
    ;}
    break;

  case 284:
#line 4453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
    /** ??? **/
      (yyval.aint)=1;
    ;}
    break;

  case 285:
#line 4459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yyvsp[(3) - (4)].astring));
        ;}
    break;

  case 291:
#line 4588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IP_time.Debut();
        ;}
    break;

  case 292:
#line 4593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IP_time.Fin();
      cout << "time spent = " << IP_time << endl;
        ;}
    break;

  case 293:
#line 4599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
    pw->BeginBox( (char*) (yyvsp[(5) - (6)].astring));
    delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 295:
#line 4622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->BeginBook();
    ;}
    break;

  case 296:
#line 4628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->EndBook();
    ;}
    break;

  case 297:
#line 4634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      pw->AddPage( (char*) (yyvsp[(5) - (6)].astring));
      delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 298:
#line 4641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
      pw->BeginPanel( (char*) (yyvsp[(5) - (6)].astring));
      delete [] (yyvsp[(5) - (6)].astring);
    ;}
    break;

  case 299:
#line 4648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->EndPanel();
    ;}
    break;

  case 300:
#line 4654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->EndBox( );
    ;}
    break;

  case 301:
#line 4660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
      pw->BeginHorizontal( );
    ;}
    break;

  case 302:
#line 4666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
        pw->EndHorizontal( );
        ;}
    break;

  case 303:
#line 4672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          pw->CreeDialogue( );
        ;}
    break;

  case 304:
#line 4678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (3)].variable)->Pointer();
          pw->ReAfficheParametres();
        ;}
    break;

  case 306:
#line 4696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yyvsp[(1) - (6)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yyvsp[(5) - (6)].variable)->Pointer() );
        ;}
    break;

  case 308:
#line 4720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yyvsp[(5) - (6)].astring));
          delete [] (yyvsp[(5) - (6)].astring);
        ;}
    break;

  case 310:
#line 4738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->Print();
        ;}
    break;

  case 311:
#line 4743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yyvsp[(1) - (4)].variable)->Pointer())->get(),(yyvsp[(4) - (4)].astring));
          delete [] (yyvsp[(4) - (4)].astring);
        ;}
    break;

  case 312:
#line 4749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        ;}
    break;

  case 313:
#line 4754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 314:
#line 4759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        ;}
    break;

  case 315:
#line 4764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 316:
#line 4769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 317:
#line 4780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yyvsp[(1) - (4)].variable);
          ParamList::ptr param((yyvsp[(3) - (4)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        ;}
    break;

  case 320:
#line 4843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 322:
#line 4869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yyvsp[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 323:
#line 4876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yyvsp[(1) - (3)].paramlist);
          float_ptr* x= new float_ptr(new float((yyvsp[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 324:
#line 4883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yyvsp[(1) - (1)].astring)));
          delete [] (yyvsp[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         ;}
    break;

  case 325:
#line 4891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yyvsp[(1) - (3)].paramlist);
          string_ptr* x = new string_ptr(new string((yyvsp[(3) - (3)].astring)));
          delete [] (yyvsp[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 326:
#line 4899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yyvsp[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 327:
#line 4908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yyvsp[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 328:
#line 4915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yyvsp[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 329:
#line 4922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yyvsp[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 330:
#line 4929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 331:
#line 4936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (3)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 332:
#line 4943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yyvsp[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 333:
#line 4950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yyvsp[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 334:
#line 4957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yyvsp[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 335:
#line 4964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (4)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yyvsp[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 336:
#line 4971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yyvsp[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 337:
#line 4978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yyvsp[(1) - (3)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yyvsp[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 338:
#line 4987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 339:
#line 4993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 340:
#line 4999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 341:
#line 5005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 342:
#line 5011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 343:
#line 5017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yyvsp[(2) - (2)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 344:
#line 5023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 345:
#line 5029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 346:
#line 5035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 347:
#line 5041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 348:
#line 5047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yyvsp[(1) - (4)].paramlistdecl);
      pl->AddParam((yyvsp[(4) - (4)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 349:
#line 5054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yyvsp[(1) - (1)].astring);
        ;}
    break;

  case 350:
#line 5059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        ;}
    break;

  case 351:
#line 5071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->postfixE");
       fflush(stdout);
        ;}
    break;

  case 352:
#line 5077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->Nom();
    ;}
    break;

  case 356:
#line 5112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yyvsp[(1) - (3)].astring),(yyvsp[(3) - (3)].astring));
          (yyval.astring)=(yyvsp[(1) - (3)].astring);
        ;}
    break;

  case 358:
#line 5130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->expr_string\n");
        ;}
    break;

  case 359:
#line 5138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yyvsp[(2) - (3)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yyvsp[(2) - (3)].ablock)->GetBody()
                << endl;
          ;}
    break;

  case 362:
#line 5151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        gr_print("\n NUMBER");
    fflush(stdout);
    ;}
    break;

  case 363:
#line 5156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    ;}
    break;

  case 364:
#line 5164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=yyiplineno;
    ;}
    break;

  case 365:
#line 5172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get();
      gr_print("\n VAR_FLOAT");
    ;}
    break;

  case 367:
#line 5187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get();
      //sprintf(tmp_string,"\n VAR_INT %d ", (int)$1);
    gr_print(tmp_string);
    ;}
    break;

  case 368:
#line 5193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yyvsp[(1) - (1)].variable)->Pointer())->get();
      //sprintf(tmp_string,"\n VAR_INT %d ", (int)$1);
      gr_print(tmp_string);
    ;}
    break;

  case 369:
#line 5199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yyvsp[(2) - (3)].adouble);
      gr_print("\n(expr)");
      fflush(stdout);
    ;}
    break;

  case 370:
#line 5208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->postfixE");
       fflush(stdout);
        ;}
    break;

  case 371:
#line 5213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yyvsp[(1) - (8)].variable)->Pointer())((int) (yyvsp[(3) - (8)].adouble),(int) ( (yyvsp[(5) - (8)].adouble)), (int) ((yyvsp[(7) - (8)].adouble)));
    ;}
    break;

  case 374:
#line 5248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    ;}
    break;

  case 383:
#line 5431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yyvsp[(1) - (3)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    ;}
    break;

  case 384:
#line 5439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());
        ;}
    break;

  case 385:
#line 5444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
        ;}
    break;

  case 386:
#line 5449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get() );
        ;}
    break;

  case 388:
#line 5483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yyvsp[(6) - (9)].variable)->Pointer())->get(),(float) (yyvsp[(8) - (9)].adouble),mask);
          delete mask;
        ;}
    break;

  case 399:
#line 5684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yyvsp[(3) - (4)].astring));
        ;}
    break;

  case 402:
#line 5739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        ;}
    break;

  case 403:
#line 5749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        ;}
    break;

  case 404:
#line 5759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        ;}
    break;

  case 405:
#line 5769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        ;}
    break;

  case 406:
#line 5779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        ;}
    break;

  case 407:
#line 5789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yyvsp[(1) - (3)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        ;}
    break;

  case 408:
#line 5799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    ;}
    break;

  case 412:
#line 5851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    ;}
    break;

  case 413:
#line 5856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    ;}
    break;

  case 414:
#line 5860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yyvsp[(1) - (6)].variable)->Pointer();
          int i = (int)(yyvsp[(3) - (6)].adouble);
          int j = (int)(yyvsp[(5) - (6)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    ;}
    break;

  case 415:
#line 5867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yyvsp[(1) - (8)].variable)->Pointer();
          int i = (int)(yyvsp[(3) - (8)].adouble);
          int j = (int)(yyvsp[(5) - (8)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yyvsp[(8) - (8)].adouble));
    ;}
    break;

  case 416:
#line 5875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    ;}
    break;

  case 428:
#line 6078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    ;}
    break;

  case 429:
#line 6086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yyvsp[(1) - (1)].aint);
    ;}
    break;

  case 430:
#line 6090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yyvsp[(5) - (6)].astring),&res);
        (yyval.adouble) =  res;
    ;}
    break;

  case 431:
#line 6098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yyvsp[(1) - (6)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    ;}
    break;

  case 432:
#line 6108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->unaryE");
       fflush(stdout);
        ;}
    break;

  case 433:
#line 6113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("\n unary_operator castE->unaryE");
       fflush(stdout);
        ;}
    break;

  case 434:
#line 6117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 435:
#line 6118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 436:
#line 6119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 437:
#line 6120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 438:
#line 6121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 439:
#line 6122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 440:
#line 6123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 441:
#line 6124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 442:
#line 6126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yyvsp[(2) - (2)].adouble),(yyval.adouble))
        ;}
    break;

  case 443:
#line 6133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 444:
#line 6134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 445:
#line 6135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 446:
#line 6136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 447:
#line 6137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 448:
#line 6138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 449:
#line 6139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yyvsp[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 452:
#line 6150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->castE");
       fflush(stdout);
        ;}
    break;

  case 453:
#line 6156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yyvsp[(1) - (3)].adouble)*(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 456:
#line 6173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yyvsp[(1) - (3)].adouble)/(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 458:
#line 6178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yyvsp[(1) - (3)].adouble)+(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 459:
#line 6179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yyvsp[(1) - (3)].adouble)-(yyvsp[(3) - (3)].adouble); ;}
    break;

  case 460:
#line 6184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("->shiftE");
    ;}
    break;

  case 462:
#line 6192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)<(yyvsp[(3) - (3)].adouble));  ;}
    break;

  case 463:
#line 6193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)>(yyvsp[(3) - (3)].adouble));  ;}
    break;

  case 464:
#line 6194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)<=(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 465:
#line 6195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yyvsp[(1) - (3)].adouble)>=(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 467:
#line 6200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yyvsp[(1) - (3)].adouble)==(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 468:
#line 6201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yyvsp[(1) - (3)].adouble)!=(yyvsp[(3) - (3)].adouble)); ;}
    break;

  case 469:
#line 6202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yyvsp[(1) - (3)].astring),(yyvsp[(3) - (3)].astring))==0); ;}
    break;

  case 470:
#line 6203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yyvsp[(1) - (3)].astring),(yyvsp[(3) - (3)].astring))!=0); ;}
    break;

  case 471:
#line 6208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("->andE ");
    ;}
    break;

  case 472:
#line 6212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yyvsp[(1) - (3)].adouble)) & ((int)(yyvsp[(3) - (3)].adouble));
    ;}
    break;

  case 473:
#line 6220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("->xorE ");
    ;}
    break;

  case 474:
#line 6224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      gr_print("\n xorE '^' andE->xorE");
    ;}
    break;

  case 475:
#line 6231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yyvsp[(1) - (1)].adouble);
        ;}
    break;

  case 476:
#line 6235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yyvsp[(1) - (3)].adouble)) | ((int)(yyvsp[(3) - (3)].adouble));
        ;}
    break;

  case 477:
#line 6242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yyvsp[(1) - (1)].adouble);
        ;}
    break;

  case 478:
#line 6246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yyvsp[(1) - (3)].adouble)&&(yyvsp[(3) - (3)].adouble);
        ;}
    break;

  case 479:
#line 6253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yyvsp[(1) - (1)].adouble);
    ;}
    break;

  case 480:
#line 6257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yyvsp[(1) - (3)].adouble)||(yyvsp[(3) - (3)].adouble);
    ;}
    break;

  case 482:
#line 6265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yyvsp[(1) - (5)].adouble)?(yyvsp[(3) - (5)].adouble):(yyvsp[(5) - (5)].adouble));
        ;}
    break;

  case 484:
#line 6276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           gr_print("->expr\n");
        ;}
    break;

  case 485:
#line 6285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 486:
#line 6290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 487:
#line 6294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 488:
#line 6298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 489:
#line 6302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 490:
#line 6306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 491:
#line 6310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 492:
#line 6314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 493:
#line 6318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 494:
#line 6322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 495:
#line 6326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetFormat();
      ;}
    break;

  case 496:
#line 6334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yyvsp[(1) - (1)].variable);
        ;}
    break;

  case 497:
#line 6339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     im_stack.AddImage((yyvsp[(2) - (2)].astring));
         gr_print("image : T_Image  ASTRING  \n ");
     delete [] (yyvsp[(2) - (2)].astring);
       ;}
    break;

  case 499:
#line 6363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     im_stack.AddImage((yyvsp[(3) - (4)].astring));
         gr_print("image : T_Image  ASTRING  \n ");
     delete [] (yyvsp[(3) - (4)].astring);
       ;}
    break;

  case 500:
#line 6371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yyvsp[(3) - (10)].aint), (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));
        im = new InrImage( (int) (yyvsp[(5) - (10)].adouble), (int) (yyvsp[(7) - (10)].adouble), (int) (yyvsp[(9) - (10)].adouble), (WORDTYPE) (yyvsp[(3) - (10)].aint));
        im_stack.AddImage(im);
        gr_print("image : T_Image ( basic_type, expr, expr, expr ) \n ");
      ;}
    break;

  case 508:
#line 6638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yyvsp[(5) - (6)].adouble));
    im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 514:
#line 6851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yyvsp[(5) - (6)].adouble));
    im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 515:
#line 6859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yyvsp[(5) - (6)].adouble));

        im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 552:
#line 7604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          im_stack.AddImage((*(Viewer3D_ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetCanvas()->GetGLImage());
        ;}
    break;

  case 595:
#line 8611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          im_stack.AddImage((InrImage*)NULL);
/*
          im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    ;}
    break;

  case 596:
#line 8620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      im_stack.AddImage((*(DessinImage::ptr*) (yyvsp[(1) - (3)].variable)->Pointer())->GetInrImage());
    ;}
    break;

  case 597:
#line 8625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

          im_stack.AddImage(res);

    ;}
    break;

  case 598:
#line 8636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

      im_stack.AddImage(res);

    ;}
    break;

  case 599:
#line 8646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

          im_stack.AddImage(res);

    ;}
    break;

  case 600:
#line 8656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble));

          im_stack.AddImage(res);
    ;}
    break;

  case 601:
#line 8665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get());

          im_stack.AddImage(res);

        ;}
    break;

  case 607:
#line 8821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(), (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));

          im_stack.AddImage(res);

        ;}
    break;

  case 609:
#line 8847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yyvsp[(3) - (10)].variable)->Pointer())->get(), (yyvsp[(5) - (10)].adouble), (yyvsp[(7) - (10)].adouble), (yyvsp[(9) - (10)].adouble));

          im_stack.AddImage(res);

        ;}
    break;

  case 610:
#line 8857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                    dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 614:
#line 8913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                     dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 615:
#line 8926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                      dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 616:
#line 8938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                      dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 617:
#line 8950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                       dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 618:
#line 8962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yyvsp[(5) - (6)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),
                       -dmax,dmax);
          im_stack.AddImage(res);
        ;}
    break;

  case 619:
#line 8973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yyvsp[(5) - (6)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            im_stack.AddImage(res);
        ;}
    break;

  case 628:
#line 9253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (5)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 632:
#line 9325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (5)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 633:
#line 9335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (5)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 634:
#line 9345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yyvsp[(1) - (6)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yyvsp[(5) - (6)].variable)->Pointer())->get() );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 635:
#line 9355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yyvsp[(5) - (6)].adouble));
      if (res!=NULL) im_stack.AddImage(res);

      delete im;
        ;}
    break;

  case 636:
#line 9365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 637:
#line 9373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yyvsp[(5) - (6)].adouble));
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 638:
#line 9381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 639:
#line 9389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yyvsp[(3) - (4)].astring));
      if (res!=NULL) im_stack.AddImage(res);
      delete [] (yyvsp[(3) - (4)].astring);
    ;}
    break;

  case 642:
#line 9445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               ;}
    break;

  case 652:
#line 9533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             ;}
    break;

  case 653:
#line 9534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             ;}
    break;

  case 654:
#line 9535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            ;}
    break;

  case 655:
#line 9536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            ;}
    break;

  case 656:
#line 9537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           ;}
    break;

  case 657:
#line 9538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           ;}
    break;

  case 658:
#line 9539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             ;}
    break;

  case 659:
#line 9540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            ;}
    break;

  case 660:
#line 9541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            ;}
    break;

  case 661:
#line 9542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            ;}
    break;

  case 662:
#line 9543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             ;}
    break;

  case 663:
#line 9544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) ;}
    break;

  case 664:
#line 9545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             ;}
    break;

  case 665:
#line 9547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 670:
#line 9594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 671:
#line 9596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   ;}
    break;

  case 672:
#line 9597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   ;}
    break;

  case 673:
#line 9598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   ;}
    break;

  case 676:
#line 9607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 677:
#line 9608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 678:
#line 9609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   ;}
    break;

  case 679:
#line 9610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   ;}
    break;

  case 682:
#line 9618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    ;}
    break;

  case 683:
#line 9619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    ;}
    break;

  case 684:
#line 9620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   ;}
    break;

  case 685:
#line 9621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   ;}
    break;

  case 686:
#line 9622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 687:
#line 9623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 688:
#line 9624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 689:
#line 9625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 691:
#line 9630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   ;}
    break;

  case 692:
#line 9631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   ;}
    break;

  case 693:
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yyvsp[(3) - (3)].adouble))   ;}
    break;

  case 694:
#line 9633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yyvsp[(3) - (3)].adouble))   ;}
    break;

  case 709:
#line 9675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         gltransf_stack.AddMatrix(newglt);

           ;}
    break;

  case 710:
#line 9686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yyvsp[(3) - (6)].adouble),(int)(yyvsp[(5) - (6)].adouble));
         matrix_stack.AddMatrix(m);
       ;}
    break;

  case 714:
#line 9735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          matrix_stack.AddMatrix(newmat);
       ;}
    break;

  case 715:
#line 9745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               ;}
    break;

  case 723:
#line 9768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             ;}
    break;

  case 725:
#line 9777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             ;}
    break;

  case 726:
#line 9778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            ;}
    break;

  case 727:
#line 9779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            ;}
    break;

  case 728:
#line 9780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           ;}
    break;

  case 729:
#line 9781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           ;}
    break;

  case 730:
#line 9782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             ;}
    break;

  case 731:
#line 9783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            ;}
    break;

  case 732:
#line 9784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            ;}
    break;

  case 733:
#line 9785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            ;}
    break;

  case 734:
#line 9786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             ;}
    break;

  case 735:
#line 9787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) ;}
    break;

  case 736:
#line 9788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             ;}
    break;

  case 739:
#line 9795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 740:
#line 9796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   ;}
    break;

  case 741:
#line 9798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 744:
#line 9809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yyvsp[(3) - (3)].adouble)) ;}
    break;

  case 745:
#line 9810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   ;}
    break;

  case 746:
#line 9811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   ;}
    break;

  case 758:
#line 9860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yyvsp[(1) - (1)].variable);
        ;}
    break;

  case 759:
#line 9865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yyvsp[(3) - (4)].variable)->Pointer())->get());
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 765:
#line 9960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (yyvsp[(5) - (6)].adouble) );
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 766:
#line 9969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(),(yyvsp[(5) - (6)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 767:
#line 9978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (int) (yyvsp[(5) - (6)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 768:
#line 9987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yyvsp[(3) - (6)].variable)->Pointer())->get(), (int) (yyvsp[(5) - (6)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 769:
#line 9996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      surf_stack.AddSurf(surf);
          gr_print("image : T_Surface  ()  \n ");
        ;}
    break;

  case 770:
#line 10003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      surf_stack.AddSurf((yyvsp[(2) - (2)].astring));
          gr_print("surface : T_Surface  ASTRING  \n ");

      delete [] (yyvsp[(2) - (2)].astring);
        ;}
    break;

  case 771:
#line 10011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      surf_stack.AddSurf((yyvsp[(3) - (4)].astring));
          gr_print("image : T_Surface  expr_string  \n ");
      delete [] (yyvsp[(3) - (4)].astring);
        ;}
    break;

  case 772:
#line 10018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yyvsp[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          surf_stack.AddSurf(newsurf);
    ;}
    break;

  case 776:
#line 10076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_INT \n ");         ;}
    break;

  case 799:
#line 10729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_FLOAT \n ");       ;}
    break;

  case 800:
#line 10731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_IMAGE \n ");
          (yyval.variable)=(yyvsp[(1) - (1)].variable);
        ;}
    break;

  case 801:
#line 10735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_IMAGEDRAW \n ");   ;}
    break;

  case 802:
#line 10737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_SURFACE \n ");     ;}
    break;

  case 803:
#line 10739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_SURFDRAW \n ");    ;}
    break;

  case 804:
#line 10741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_FILE \n ");        ;}
    break;

  case 805:
#line 10743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_FUNCTION \n ");  ;}
    break;

  case 806:
#line 10745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_PROCEDURE \n ");  ;}
    break;

  case 807:
#line 10747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_IMAGE_FUNCTION \n ");  ;}
    break;

  case 808:
#line 10749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_AMI_FUNCTION \n ");;}
    break;

  case 809:
#line 10751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_STRING \n ");      ;}
    break;

  case 810:
#line 10753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_MATRIX \n ");      ;}
    break;

  case 811:
#line 10755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_GLTRANSFORM \n "); ;}
    break;

  case 812:
#line 10757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_PARAMWIN \n ");    ;}
    break;

  case 813:
#line 10759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_ARRAY_SURFACE \n ");       ;}
    break;

  case 814:
#line 10761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_ARRAY_IMAGE \n ");       ;}
    break;

  case 815:
#line 10767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent( (float)(yyvsp[(1) - (11)].adouble),(float)(yyvsp[(3) - (11)].adouble),(float)(yyvsp[(5) - (11)].adouble),
                              (float)(yyvsp[(7) - (11)].adouble),(float)(yyvsp[(9) - (11)].adouble),(float)(yyvsp[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 816:
#line 10775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent((float)(yyvsp[(1) - (7)].adouble),(float)(yyvsp[(3) - (7)].adouble),(float)(yyvsp[(5) - (7)].adouble),(float)(yyvsp[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 817:
#line 10782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 19305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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


#line 10817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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










