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

// teach how wxString use streams (operator<<)
ostream & operator<<(ostream & out, const wxString & str);
// {
//     out << str.c_str();
//     return out;
// }

#endif // _CoutwxString_h_
