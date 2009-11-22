//
// C++ Interface: wrap_mainframe
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_mainframe_h_
#define _wrap_mainframe_h_

#include "paramlist.h"


/** function that add wrapping of the MainFrame window
 */
void AddWrapMainFrame();

void wrap_MainFrameDrawSetLimits( ParamList* p);
void wrap_MainFrameDrawSetCurve( ParamList* p);

#endif //  _wrap_mainframe_h_
