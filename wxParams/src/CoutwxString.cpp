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

ostream & operator<<(ostream & out, const wxString & str)
{
    out << str.c_str();
    return out;
}
