//
// C++ Interface: wrap_wxfunctions
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxfunctions_h_
#define _wrap_wxfunctions_h_

#include "ami_object.h"
#include "BasicVariable.h"
class ParamList;

AMIObject::ptr      AddWrap_wxfunctions();
BasicVariable::ptr  wrap_wxfunctions( ParamList* p);


/**
 * Launch the default browser with the given web page.
 * @param p 
 */
BasicVariable::ptr wrap_LaunchDefaultBrowser( ParamList* p);

/**
 * Convert wxString to AMILab string.
 * @param p
 */
BasicVariable::ptr wrap_FromWxString( ParamList* p);

#endif // _wrap_wxfunctions_h_
