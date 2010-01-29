//
// C++ Implementation: wrapfunctions_draw
//
// Description: 
//
//
// Author: Karl krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrapfunctions.hpp"
#include "wrapfunctions_draw.h"
#include "DefineClass.hpp"
#include "amilab_messages.h"

#include <string>
using namespace std;

void test() {
}

/**
 * Function used to parse an imagedraw in a list of parameters
 */
bool get_imagedraw_param(DessinImage::ptr& arg, ParamList*p, int& num)
{
  if (!p) return false;
  DessinImage::ptr    temp;
  temp = p->GetParamPtr<DessinImage>(type_imagedraw,num++);
  if (temp.use_count()) {
    arg=temp;
    return true;
  }
  else
  {
    FILE_ERROR(boost::format("Error in the parameter %d")%num);
    return false;
  }
}


