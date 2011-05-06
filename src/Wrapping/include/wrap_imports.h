//
// C++ Interface: wrap_imports
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_imports_h_
#define _wrap_imports_h_

#include "AMILabConfig.h"
#include "paramlist.h"


/** function that adds an import object to import all the code wrapping
 */
void AddWrapImports();

/**
 * Adding wrapped classes from wxwidgets library.
 */
void AddWrapWxWidgets();

#ifdef AMI_WRAP_MICRONTRACKER
  void AddWrapMicronTracker();
  void AddWrapUltrasound();
#endif


#ifdef AMI_WRAP_ULTRASOUND
  //void AddWrapUltrasound();
#endif


/**
 * Adding wrapped classes from Algorithms
 */
void AddWrapAlgorithms();

/**
 * Adding wrapped classes from amilab.
 */
void AddWrapAmilab();

/**
 * Adding wrapped classes and methods for IO.
 */
void AddWrapIO();

/**
 * Adding wrapped classes and methods for Image.
 */
void AddWrapImage();

/**
 * Adding wrapped classes and methods for Surfaces.
 */
void AddWrapSurface();

/**
 * Adding wrapped classes and methods for DessinImage.
 */
void AddWrapDessinImage();

/**
 * Adding wrapped classes and methods for Viewer3D.
 */
void AddWrapViewer3D();

/**
 * Adding wrapped classes and methods for WrapGLTransfMatrix.
 */
void AddWrapGLTransfMatrix();

/**
 * Adding wrapped classes and methods for basic types (VarVector, VarList, etc ..).
 */
void AddWrapBasicTypes();

/**
 * Adding wrapped classes and methods for basic types (VarVector, VarList, etc ..).
 */
void AddWrapTestTemplateClass();

#endif //  _wrap_MainFrame_h_
