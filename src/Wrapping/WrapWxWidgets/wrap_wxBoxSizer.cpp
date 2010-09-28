//
// C++ Implementation: wrap_wxBoxSizer
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxBoxSizer.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#include "wrap_wxWindow.h"

#include <wx/sizer.h>

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBoxSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxBoxSizer::wrap_wxBoxSizer construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxBoxSizer);
AMI_DEFINE_VARFROMSMTPTR(wxBoxSizer);



//---------------------------------------------------
// Method that adds wrapping of wxBoxSizer
//---------------------------------------------------

void WrapClass_wxBoxSizer::
      wrap_wxBoxSizer::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"Orientation");
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
      wrap_wxBoxSizer::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(int,orient,0);

  return AMILabType<wxBoxSizer>::CreateVar(
    new wxBoxSizer(orient));
}



//---------------------------------------------------
//  GetOrientation
//---------------------------------------------------
void WrapClass_wxBoxSizer::
      wrap_GetOrientation::SetParametersComments() 
{
  return_comments="orientation as integer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
      wrap_GetOrientation::CallMember( ParamList* p)
{
  // TODO
  return BasicVariable::ptr();
}

