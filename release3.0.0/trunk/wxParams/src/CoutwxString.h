//
// C++ Interface: CoutwxString
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _CoutwxString_h_
#define _CoutwxString_h_

#include <iostream>
#include "wx/wx.h"
using namespace std;

#ifndef wxUSE_STD_IOSTREAM

ostream & operator<<(ostream & out, const wxString & str);

#endif // #ifndef wxUSE_STD_IOSTREAM


#endif // _CoutwxString_h_
