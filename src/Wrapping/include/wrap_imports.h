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
#include "ami_object.h"

/** function that adds an import object to import all the code wrapping
 */
void AddWrapImports();

/**
 * Adding wrapped classes from wxwidgets library.
 */
void AddWrapWxWidgets(AMIObject::ptr& obj);

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
void AddWrapAlgorithms(AMIObject::ptr& obj);

/**
 * Wraps a variable: Variable<T> to Variable<BasicVariable>.
 * @param p
 */
BasicVariable::ptr wrap_WrapVariable( ParamList* p);


/**
 * Adding wrapped classes from Language
 */
void AddWrapLanguage(AMIObject::ptr& obj);

/**
 * Adding wrapped classes from amilab.
 */
void AddWrapAmilab(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for IO.
 */
void AddWrapIO(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for Image.
 */
void AddWrapImage(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for Surfaces.
 */
void AddWrapSurface(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for DessinImage.
 */
void AddWrapDessinImage(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for Viewer3D.
 */
void AddWrapViewer3D(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for WrapGLTransfMatrix.
 */
void AddWrapGLTransfMatrix(AMIObject::ptr& obj);

/**
 * Adding wrapped classes and methods for basic types (VarVector, VarList, etc ..).
 */
void AddWrapBasicTypes(AMIObject::ptr& obj);


#endif //  _wrap_MainFrame_h_
