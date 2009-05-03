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
#include "surface.hpp"

class SurfStack{

  std::stack<SurfacePoly*> _surf;

 public:

  SurfStack()    { }

  ~SurfStack()    { }

  void AddSurf( char* name)
  {
    SurfacePoly* surf_tmp;
    unsigned char      res;
    surf_tmp=new SurfacePoly;
    res = surf_tmp->Read(name);
    Si res Alors
      _surf.push(surf_tmp);
    Sinon
      fprintf(stderr,"SurfStack::AddSurf(%s) \t read failed.\n",name);
    FinSi
  }

  void AddSurf( SurfacePoly* surf)
  {
    _surf.push(surf);
    if (GB_debug) fprintf(stderr,"SurfStack::AddSurf() %p \n",surf);
  }

  SurfacePoly* GetLastSurf()
  {
    SurfacePoly* tmp;
    tmp=_surf.top();
    _surf.pop();
    return tmp;
  }

}; // SurfStack


#endif // _SurfStack_h_
