
//
// C++ Implementation: wrap_stdvector
//
// Description: Wrapping of a vector of variables
//
//
// Author: Karl krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "wrap_stdvector.h"

/*
//
// static member for creating a variable from a ParamList
// need to instanciate for each type ...
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<int> >::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_StdVector<int>::wrap_StdVector construct;
  return construct.CallMember(p);
}

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<float> >::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_StdVector<float>::wrap_StdVector construct;
  return construct.CallMember(p);
}

 * template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<double> >::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_StdVector<double>::wrap_StdVector construct;
  return construct.CallMember(p);
}
*/