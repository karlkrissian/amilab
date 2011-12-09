//
// C++ Interface: wrap_wxsamples
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxsamples_h_
#define _wrap_wxsamples_h_

#include "paramlist.h"


/** Wrapping of wxwidgets samples
 */
void AddWrapWXSamples(  AMIObject::ptr& obj);

void wrap_penguin(      ParamList* p);
//void wrap_wxStcFrame(   ParamList* p);

#endif //  _wrap_wxsamples_h_
