//
// C++ Interface: SurfStack
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _SurfStack_h_
#define _SurfStack_h_

#include <stack>

#include "DefineClass.hpp"
#include "amilab_messages.h"

#include "surface.hpp"
//using namespace amilab;

class SurfStack{

  DEFINE_CLASS(SurfStack);

  std::stack<amilab::SurfacePoly*> _surf;

 public:

  SurfStack()    { }

  ~SurfStack()    { }

  void AddSurf( const char* name)
  {
    amilab::SurfacePoly* surf_tmp;
    unsigned char      res;
    surf_tmp=new amilab::SurfacePoly;
    res = surf_tmp->Read(name);
    if (res) {
      _surf.push(surf_tmp);
    } else {
      CLASS_ERROR( boost::format("read of %1% failed.") % name);
      _surf.push(NULL);
    }
  }

  void AddSurf( amilab::SurfacePoly* surf)
  {
    _surf.push(surf);
    if (GB_debug) fprintf(stderr,"SurfStack::AddSurf() %p \n",surf);
  }

  amilab::SurfacePoly* GetLastSurf()
  {
    amilab::SurfacePoly* tmp;
    tmp=_surf.top();
    _surf.pop();
    return tmp;
  }

}; // SurfStack


#endif // _SurfStack_h_
