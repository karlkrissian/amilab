//
// C++ Implementation: CoutwxString
//
// Description: 
//
//
// Author:  <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "CoutwxString.h"

#ifndef wxUSE_STD_IOSTREAM

ostream & operator<<(ostream & out, const wxString & str)
{
    out << str.c_str();
    return out;
}

#endif // #ifndef wxUSE_STD_IOSTREAM
