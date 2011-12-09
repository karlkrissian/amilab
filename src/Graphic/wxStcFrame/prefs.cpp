//////////////////////////////////////////////////////////////////////////////
// File:        contrib/samples/stc/prefs.cpp
// Purpose:     STC test Preferences initialization
// Maintainer:  Wyo
// Created:     2003-09-01
// RCS-ID:      $Id: prefs.cpp 37440 2006-02-10 11:59:52Z ABX $
// Copyright:   (c) wxGuide
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all 'standard' wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

//! wxWidgets headers

//! wxWidgets/contrib headers

//! application headers
#include "defsext.h"     // Additional definitions
#include "prefs.h"       // Preferences


//============================================================================
// declarations
//============================================================================

//----------------------------------------------------------------------------
//! language types
const CommonInfo g_CommonPrefs = {
    // editor functionality prefs
    true,  // syntaxEnable
    true,  // foldEnable
    true,  // indentEnable
    // display defaults prefs
    false, // overTypeInitial
    false, // readOnlyInitial
    false,  // wrapModeInitial
    false, // displayEOLEnable
    false, // IndentGuideEnable
    true,  // lineNumberEnable
    false, // longLineOnEnable
    false, // whiteSpaceEnable
};

//----------------------------------------------------------------------------
// keywordlists
// C++
const wxChar* CppWordlist1 =
    _T("asm auto bool break case catch char class const const_cast ")
    _T("continue default delete do double dynamic_cast else enum explicit ")
    _T("export extern false float for friend goto if inline int long ")
    _T("mutable namespace new operator private protected public register ")
    _T("reinterpret_cast return short signed sizeof static static_cast ")
    _T("struct switch template this throw true try typedef typeid ")
    _T("typename union unsigned using virtual void volatile wchar_t ")
    _T("while");
const wxChar* CppWordlist2 =
    _T("file");
const wxChar* CppWordlist3 =
    _T("a addindex addtogroup anchor arg attention author b brief bug c ")
    _T("class code date def defgroup deprecated dontinclude e em endcode ")
    _T("endhtmlonly endif std::endlatexonly std::endlink endverbatim enum example ")
    _T("exception f$ f[ f] file fn hideinitializer htmlinclude ")
    _T("htmlonly if image include ingroup internal invariant interface ")
    _T("latexonly li line link mainpage name namespace nosubgrouping note ")
    _T("overload p page par param post pre ref relates remarks return ")
    _T("retval sa section see showinitializer since skip skipline struct ")
    _T("subsection test throw todo typedef union until var verbatim ")
    _T("verbinclude version warning weakgroup $ @ \"\" & < > # { }");

// Python
const wxChar* PythonWordlist1 =
    _T("and assert break class continue def del elif else except exec ")
    _T("finally for from global if import in is lambda None not or pass ")
    _T("print raise return try while yield");
const wxChar* PythonWordlist2 =
    _T("ACCELERATORS ALT AUTO3STATE AUTOCHECKBOX AUTORADIOBUTTON BEGIN ")
    _T("BITMAP BLOCK BUTTON CAPTION CHARACTERISTICS CHECKBOX CLASS ")
    _T("COMBOBOX CONTROL CTEXT CURSOR DEFPUSHBUTTON DIALOG DIALOGEX ")
    _T("DISCARDABLE EDITTEXT END EXSTYLE FONT GROUPBOX ICON LANGUAGE ")
    _T("LISTBOX LTEXT MENU MENUEX MENUITEM MESSAGETABLE POPUP PUSHBUTTON ")
    _T("RADIOBUTTON RCDATA RTEXT SCROLLBAR SEPARATOR SHIFT STATE3 ")
    _T("STRINGTABLE STYLE TEXTINCLUDE VALUE VERSION VERSIONINFO VIRTKEY");

    
const wxChar* AMILabWordlist1 =
    _T("PathFromDispl InvertNormals sin GetObjectName end BorgeforsSDT tan ")
    _T("HessianMatrix Image DrawAllContours BrowseImage CircleInt AnisoWeickert ")
    _T("AddPoint vtkSignedFMDist SetIsoContourColor ConvexHull ")
    _T("vtkPropDanielsson SetWindowSize Transform SetVectParam subimage ")
    _T("LineAddPointNumber rewind secdergrad SelectLines SetLightSpecular CC ")
    _T("global CircleIntSdExc func EndLine PropagationDist2 StructTensorH ")
    _T("exists EDPdilate Convolve del PropagationDist GetXmax else OrientField ")
    _T("Normalize PaintCallback proc sh filter itk isosurf_inv AnisoSRAD ")
    _T("SetCompTransf Displace cosh vtkSmooth DisplayHisto TraceScanning ")
    _T("putimage TRANSFORM sum repeat PropDanielsson SetVerboseOff ")
    _T("import_filters read Quit step Comments TraceParsing HessianEVal ")
    _T("ResampleLines Paint amiOFCorr2D setvector vtkFastMarching asin DOUBLE ")
    _T("ln end-of-line discsecdergrad while ls MeanHalfSize GetName DrawVector ")
    _T("vtkIsoContourDist GetLinesLength ShortestPath ElevateMesh abs ")
    _T("LineNumber compare in WriteCTALine SetColorMaterial Eigen3D ")
    _T("GetNumberOfLines GetYmax TimeSpent vtkMINCRead autocrop median STRING ")
    _T("setGLwin eval AndreDist vtkDist NbPolys CannyEdgeDetector atan ")
    _T("localmean SRAD_qcoeff UINT IsosurfDist normgrad Set3DArrowParam Xpos ")
    _T("CreateVolume GenRead Pi Remove discnormgrad rotate break ")
    _T("SetPointsColors InitTime tz ty tx vtkAnisoGS ReadCTALine OBJECT ")
    _T("Center open vtkSignedBorgefors Laplacian Matrix Surface Chamfer2DT ")
    _T("SetStatusText ConnectLines PrintMatrices Ypos SetLightDiffuse ")
    _T("OutFlux set NUM SetColor global_new CreateVectorsFromField ")
    _T("AnisoSmoothGS SetIsoContourParam vtkDecimate SetGetExtent AnisoDPAD ")
    _T("trz save SetLight cumhisto SetSpecular SetShininess EDPclose inc ")
    _T("SetOpacity CreateVectors until CreateFlatMesh sprint sqrt sinh min ")
    _T("ProcessXEvents AnisoNRAD AddGaussNoise Eigen2D vtkPropDaniel2 ")
    _T("SetColorOpacity ConvolveMask UCHAR drawcircle OpImage AnisoRudinMult ")
    _T("setminCC trx try SURFACE drawCC GetLine import_wii FluxDiffusion exp ")
    _T("ReSlice DisplayVectors OwnMaterial AnisoCW Translate SNR ")
    _T("CircleMinIntSdExc InfoDialog IMAGE ShowSection ShortestPathImage ")
    _T("floor Triangulate local SetColors OrientationRatio isosurf_ras mean ")
    _T("IsocontourPoints NbPoints showcursor LineRecons norm SetLineWidth ")
    _T("Help count round SaveStructuredGrid SetFluidNavFile SetCurrentObj ")
    _T("SetZoom RemoveLine scan_float SetLightPos SpacePos for Zpos NULL ")
    _T("initvalue lininterp SetLineThickness GetZmin AddMenuScript ")
    _T("Curvatures emptyargs GetYmin update gradient SetProgress cos ")
    _T("setpos SetDiffuse isosurf EDPerode vars GetLinesExtremities val ")
    _T("SetVerboseOn endfor setvoxelsize init Skeleton Pad SetComponent ")
    _T("import_vtk rot2D Normals posarea AllContoursParam vtkCreateFlatMesh ")
    _T("getimage SetName printn boost_format EndTime vdim NewLine ")
    _T("Skeleton2lines log EDPopen SetLightAmbient Interpolate Statistics ")
    _T("ReadFlow DirConnectivity SetColormap AnisoLeeAdd2 GetImageFromX ")
    _T("SetBackground ChamferDT SetAmbient DrawEarthCoord if eccentricity ")
    _T("MergePoints ReadRawImages OrientPositive SetDebugOff SHORT ")
    _T("SetVisible DiscMeanCurvature schedule GetZPos Resize ")
    _T("vtkMarchingCubes Scale GetTransform SetVectStyle RGB delvars ")
    _T("FileExists local_new slice setendianness DrawIsoContour ")
    _T("ProcessEvents OutFluxScalar argmax close ComputeAltitudes ")
    _T("computeCC amiOFVar2D max SetCompareDisplacement GetScriptDir ")
    _T("threscross Recompute Hide wait SimplePoints localSD ")
    _T("vtkFastMarchingTarget GeoCoordinates FLOAT_VECTOR print ")
    _T("GetZmax INT LocalExtrema StructTensor localmean2 PathFromVectField ")
    _T("acos normalize vtkDicomRead settranslation SetVectColor Invert ")
    _T("GetConnections BorgeforsDT SmoothLines GetXmin CHAR GetYPos info ")
    _T("vy vx vz gnuplot secdergrad2 CreateEllipsoids GetIntensities ")
    _T("AddObject isoarea2D NormalField AnisoSRAD2 GetXPos Flip ")
    _T("SetIsoContour vtkWindowedSinc AnisoDPAD2 SetOpacityImage argc ")
    _T("SetDebugOn USHORT Derivatives vtkMedian3D Temp2Altitudes ")
    _T("HideSection IMAGEDRAW SetTransform Class GetFormat CircleIntExc ")
    _T("SwapBuffers ReadCTALineRadii iterate to Altitude2Position Show ")
    _T("RemoveSelection RestartTime histo isoline atof localSD2 isosurf_ijk ")
    _T("ParamWin FLOAT");
    

// TODO: read xml description ...
// for the moment try to make it work with keywords ...
const wxChar* DOTWordlist1 =
    _T("node graph digraph strict edge subgraph");

const wxChar* DOTWordlist2 =
    _T("Mcircle Mdiamond Mrecord Msquare TRUE auto back bold both box circle ")
    _T("compress dashed diamond dot dotted doublecircle doubleoctagon egg ")
    _T("ellipse epsf false fill filled forward global hexagon house inv ")
    _T("invdot invhouse invis invodot invtrapezium invtriangle local max ")
    _T("min none normal octagon odot out parallelogram plaintext polygon ")
    _T("record same solid trapezium triangle tripleoctagon true");
    
const wxChar* DOTWordlist3 =
    _T("aliceblue antiquewhite aquamarine azure beige bisque black ")
    _T("blanchedalmond blue blueviolet brown burlywood cadetblue chartreuse ")
    _T("chocolate coral cornflowerblue cornsilk crimson cyan darkgoldenrod ")
    _T("darkgreen darkkhaki darkolivegreen darkorange darkorchid darksalmon ")
    _T("darkseagreen darkslateblue darkslategray darkturquoise darkviolet ")
    _T("deeppink deepskyblue dimgray dodgerblue firebrick forestgreen ")
    _T("gainsboro ghostwhite gold goldenrod gray green greenyellow honeydew ")
    _T("hotpink indianred indigo ivory khaki lavender lavenderblush ")
    _T("lawngreen lemonchiffon lightblue lightcyan lightgoldenrod ")
    _T("lightgoldenrodyellow lightgray lightpink lightsalmon lightseagreen ")
    _T("lightskyblue lightslateblue lightslategray lightyellow limegreen ")
    _T("linen magenta maroon mediumaquamarine mediumblue mediumorchid ")
    _T("mediumpurple mediumseagreen mediumslateblue mediumspringgreen ")
    _T("mediumturquoise mediumvioletred midnightblue mintcream mistyrose ")
    _T("moccasin navajowhite navy navyblue oldlace olivedrab oralwhite ")
    _T("orange orangered orchid palegoldenrod palegreen paleturquoise ")
    _T("palevioletred papayawhip peachpuff peru pink plum powderblue ")
    _T("purple red rosybrown royalblue saddlebrown salmon salmon2 sandybrown ")
    _T("seagreen seashell sienna skyblue slateblue slategray snow ")
    _T("springgreen steelblue tan thistle tomato turquoise violet violetred ")
    _T("wheat white whitesmoke yellow yellowgreen");
    
const wxChar* DOTWordlist4 =
    _T("URL arrowhead arrowsize arrowtail bb bgcolor bottomlabel center ")
    _T("clusterrank color comment constraint decorate dir distortion ")
    _T("fillcolor fixedsize fontcolor fontname fontsize group headclip ")
    _T("headlabel headport height id label labelangle labeldistance ")
    _T("labelfontcolor labelfontname labelfontsize layer layers margin ")
    _T("mclimit minlen nodesep nslimit ordering orientation page pagedir ")
    _T("peripheries port_label_distance quantum rank rankdir ranksep ratio ")
    _T("regular rotate samehead sametail searchsize shape shapefile ")
    _T("showboxes sides size skew style tailclip taillabel tailport ")
    _T("toplabel weight width");

//----------------------------------------------------------------------------
//! languages
const LanguageInfo g_LanguagePrefs [] = {
    // C++
    {_T("C++"),
     _T("*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma"),
     wxSTC_LEX_CPP,
     {{mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_COMMENT, NULL},
      {mySTC_TYPE_COMMENT_LINE, NULL},
      {mySTC_TYPE_COMMENT_DOC, NULL},
      {mySTC_TYPE_NUMBER, NULL},
      {mySTC_TYPE_WORD1, CppWordlist1}, // KEYWORDS
      {mySTC_TYPE_STRING, NULL},
      {mySTC_TYPE_CHARACTER, NULL},
      {mySTC_TYPE_UUID, NULL},
      {mySTC_TYPE_PREPROCESSOR, NULL},
      {mySTC_TYPE_OPERATOR, NULL},
      {mySTC_TYPE_IDENTIFIER, NULL},
      {mySTC_TYPE_STRING_EOL, NULL},
      {mySTC_TYPE_DEFAULT, NULL}, // VERBATIM
      {mySTC_TYPE_REGEX, NULL},
      {mySTC_TYPE_COMMENT_SPECIAL, NULL}, // DOXY
      {mySTC_TYPE_WORD2, CppWordlist2}, // EXTRA WORDS
      {mySTC_TYPE_WORD3, CppWordlist3}, // DOXY KEYWORDS
      {mySTC_TYPE_ERROR, NULL}, // KEYWORDS ERROR
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     mySTC_FOLD_COMMENT | mySTC_FOLD_COMPACT | mySTC_FOLD_PREPROC},
    // Python
    {_T("Python"),
     _T("*.py;*.pyw"),
     wxSTC_LEX_PYTHON,
     {{mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_COMMENT_LINE, NULL},
      {mySTC_TYPE_NUMBER, NULL},
      {mySTC_TYPE_STRING, NULL},
      {mySTC_TYPE_CHARACTER, NULL},
      {mySTC_TYPE_WORD1, PythonWordlist1}, // KEYWORDS
      {mySTC_TYPE_DEFAULT, NULL}, // TRIPLE
      {mySTC_TYPE_DEFAULT, NULL}, // TRIPLEDOUBLE
      {mySTC_TYPE_DEFAULT, NULL}, // CLASSNAME
      {mySTC_TYPE_DEFAULT, PythonWordlist2}, // DEFNAME
      {mySTC_TYPE_OPERATOR, NULL},
      {mySTC_TYPE_IDENTIFIER, NULL},
      {mySTC_TYPE_DEFAULT, NULL}, // COMMENT_BLOCK
      {mySTC_TYPE_STRING_EOL, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     mySTC_FOLD_COMMENTPY | mySTC_FOLD_QUOTESPY},
    // AMILab
    {_T("AMILab"),
     _T("*.amil"),
     wxSTC_LEX_CPP,
     {{mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_COMMENT, NULL},
      {mySTC_TYPE_COMMENT_LINE, NULL},
      {mySTC_TYPE_COMMENT_DOC, NULL},
      {mySTC_TYPE_NUMBER, NULL},
      {mySTC_TYPE_WORD1, AMILabWordlist1}, // KEYWORDS
      {mySTC_TYPE_STRING, NULL},
      {mySTC_TYPE_CHARACTER, NULL},
      {mySTC_TYPE_UUID, NULL},
      {mySTC_TYPE_PREPROCESSOR, NULL},
      {mySTC_TYPE_OPERATOR, NULL},
      {mySTC_TYPE_IDENTIFIER, NULL},
      {mySTC_TYPE_STRING_EOL, NULL},
      {mySTC_TYPE_DEFAULT, NULL}, // VERBATIM
      {mySTC_TYPE_REGEX, NULL},
      {mySTC_TYPE_COMMENT_SPECIAL, NULL}, // DOXY
      {mySTC_TYPE_WORD2, CppWordlist2}, // EXTRA WORDS
      {mySTC_TYPE_WORD3, CppWordlist3}, // DOXY KEYWORDS
      {mySTC_TYPE_ERROR, NULL}, // KEYWORDS ERROR
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     mySTC_FOLD_COMMENT | mySTC_FOLD_COMPACT | mySTC_FOLD_PREPROC},
    // AMILab
    {_T("dot"),
     _T("*.dot"),
     wxSTC_LEX_CPP,
     {{mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_COMMENT, NULL},
      {mySTC_TYPE_COMMENT_LINE, NULL},
      {mySTC_TYPE_COMMENT_DOC, NULL},
      {mySTC_TYPE_NUMBER, NULL},
      {mySTC_TYPE_WORD1, DOTWordlist1}, // KEYWORDS
      {mySTC_TYPE_STRING, NULL},
      {mySTC_TYPE_CHARACTER, NULL},
      {mySTC_TYPE_UUID, NULL},
      {mySTC_TYPE_PREPROCESSOR, NULL},
      {mySTC_TYPE_OPERATOR, NULL},
      {mySTC_TYPE_IDENTIFIER, NULL},
      {mySTC_TYPE_STRING_EOL, NULL},
      {mySTC_TYPE_DEFAULT, NULL}, // VERBATIM
      {mySTC_TYPE_REGEX, NULL},
      {mySTC_TYPE_COMMENT_SPECIAL, NULL}, // DOXY
      {mySTC_TYPE_WORD2, DOTWordlist2}, // EXTRA WORDS
      {mySTC_TYPE_WORD3, DOTWordlist3}, // DOXY KEYWORDS
      {mySTC_TYPE_ERROR, NULL}, // KEYWORDS ERROR
      {mySTC_TYPE_WORD4, DOTWordlist4}, // DOXY KEYWORDS
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     mySTC_FOLD_COMMENT | mySTC_FOLD_COMPACT | mySTC_FOLD_PREPROC},
    // * (any)
    {(const wxChar *)DEFAULT_LANGUAGE,
     _T("*.*"),
     wxSTC_LEX_PROPERTIES,
     {{mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_DEFAULT, NULL},
      {mySTC_TYPE_DEFAULT, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     0},
    };

const int g_LanguagePrefsSize = WXSIZEOF(g_LanguagePrefs);

//----------------------------------------------------------------------------
//! style types
const StyleInfo g_StylePrefs [] = {
    // mySTC_TYPE_DEFAULT
    {_T("Default"),
     _T("BLACK"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_WORD1
    {_T("Keyword1"),
     _T("BLUE"), _T("WHITE"),
     _T(""), 10, mySTC_STYLE_BOLD, 0},

    // mySTC_TYPE_WORD2
    {_T("Keyword2"),
     _T("DARK BLUE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_WORD3
    {_T("Keyword3"),
     _T("CORNFLOWER BLUE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_WORD4
    {_T("Keyword4"),
     _T("CYAN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_WORD5
    {_T("Keyword5"),
     _T("DARK GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_WORD6
    {_T("Keyword6"),
     _T("GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_COMMENT
    {_T("Comment"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_COMMENT_DOC
    {_T("Comment (Doc)"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_COMMENT_LINE
    {_T("Comment line"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_COMMENT_SPECIAL
    {_T("Special comment"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, mySTC_STYLE_ITALIC, 0},

    // mySTC_TYPE_CHARACTER
    {_T("Character"),
     _T("KHAKI"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_CHARACTER_EOL
    {_T("Character (EOL)"),
     _T("KHAKI"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_STRING
    {_T("String"),
     _T("BROWN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_STRING_EOL
    {_T("String (EOL)"),
     _T("BROWN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_DELIMITER
    {_T("Delimiter"),
     _T("ORANGE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_PUNCTUATION
    {_T("Punctuation"),
     _T("ORANGE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_OPERATOR
    {_T("Operator"),
     _T("BLACK"), _T("WHITE"),
     _T(""), 10, mySTC_STYLE_BOLD, 0},

    // mySTC_TYPE_BRACE
    {_T("Label"),
     _T("VIOLET"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_COMMAND
    {_T("Command"),
     _T("BLUE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_IDENTIFIER
    {_T("Identifier"),
     _T("BLACK"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_LABEL
    {_T("Label"),
     _T("VIOLET"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_NUMBER
    {_T("Number"),
     _T("SIENNA"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_PARAMETER
    {_T("Parameter"),
     _T("VIOLET"), _T("WHITE"),
     _T(""), 10, mySTC_STYLE_ITALIC, 0},

    // mySTC_TYPE_REGEX
    {_T("Regular expression"),
     _T("ORCHID"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_UUID
    {_T("UUID"),
     _T("ORCHID"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_VALUE
    {_T("Value"),
     _T("ORCHID"), _T("WHITE"),
     _T(""), 10, mySTC_STYLE_ITALIC, 0},

    // mySTC_TYPE_PREPROCESSOR
    {_T("Preprocessor"),
     _T("GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_SCRIPT
    {_T("Script"),
     _T("DARK GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_ERROR
    {_T("Error"),
     _T("RED"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // mySTC_TYPE_UNDEFINED
    {_T("Undefined"),
     _T("ORANGE"), _T("WHITE"),
     _T(""), 10, 0, 0}

    };

const int g_StylePrefsSize = WXSIZEOF(g_StylePrefs);
