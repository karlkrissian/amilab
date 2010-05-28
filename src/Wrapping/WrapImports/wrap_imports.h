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

#include "paramlist.h"


/** function that adds an import object to import all the code wrapping
 */
void AddWrapImports();

/**
 * Adding wrapped classes from wxwidgets library.
 */
void AddWrapWxWidgets();

/**
 * Adding wrapped classes from amilab.
 */
void AddWrapAmilab();

/**
 * Adding wrapped classes and methods for IO.
 */
void AddWrapIO();

#endif //  _wrap_MainFrame_h_
