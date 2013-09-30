
#pragma once

#ifndef _amiBackgroundComponents_h_
#define _amiBackgroundComponents_h_

#include "inrimage.hpp"
#include <vector>
#include <iostream>

namespace ami {

// compute the components of the background (intensity =0)
// can be used to fill the object holes
// the components are obtained in two image parses: the first one
// compute them with their connections, the second parse creates the final 
// result
  
class BackgroundComponents {

public:
  
  //----------------------------------------------------------------------------
  // constructor
  BackgroundComponents()
  {
    ResetConnections();
  }
  
  //----------------------------------------------------------------------------
  void ResetConnections()
  {
    component_connections  .clear();
    component_toucheslimits.clear();
    // component 0: object
    component_connections  .push_back(0);
    component_toucheslimits.push_back(0);
  }
  
  //----------------------------------------------------------------------------
  void SetInput(InrImage::ptr inp)
  {
    input = inp;
  }

  //----------------------------------------------------------------------------
  bool ComputeComponents();  
  
  //----------------------------------------------------------------------------
  InrImage::ptr GetComponents()
  {
    return components;
  }
  
  //----------------------------------------------------------------------------
  InrImage::ptr GetConnections()
  {
    InrImage::ptr res(
                new InrImage(component_connections.size(),1,1,WT_UNSIGNED_INT));
    
    for(int c=0;c<component_connections.size();c++)
      res->SetValue(c,0,0,0,GetComponentClass(c));
    return res;
  }

  //----------------------------------------------------------------------------
  InrImage::ptr GetCompressedConnections()
  {
    InrImage::ptr res(
                new InrImage(component_connections.size(),1,1,WT_UNSIGNED_INT));
    
    std::vector<int> newvalues(component_connections.size(),-1);
    newvalues[0] = 0;
    int num = 0;
    for(int c=1;c<component_connections.size();c++)
      if (c==GetComponentClass(c)) {
        num++;
        newvalues[c] = num;
      } else
        newvalues[c] = newvalues[GetComponentClass(c)];

      
    for(int c=0;c<component_connections.size();c++)
      res->SetValue(c,0,0,0,newvalues[c]);
    return res;
  }

  //----------------------------------------------------------------------------
  InrImage::ptr GetHoles()
  {
    InrImage::ptr res(
                new InrImage(component_connections.size(),1,1,WT_UNSIGNED_CHAR));
    
    res->SetValue(0,0,0,0,0);
    for(int c=1;c<component_connections.size();c++)
      if (component_toucheslimits[GetComponentClass(c)])
        res->SetValue(c,0,0,0,0);
      else
        res->SetValue(c,0,0,0,1);
    return res;
  }

private:
  InrImage::ptr input;
  InrImage::ptr components;

  std::vector<int>  component_connections;
  std::vector<bool> component_toucheslimits; // if touches image limits
  
  //----------------------------------------------------------------------------
  int AddComponent( bool toucheslimits = false)
  {
    component_connections  .push_back(component_connections.size());
    component_toucheslimits.push_back(toucheslimits);
//    std::cout << "new component " << component_connections.size()-1 
//              << "touches limits " << toucheslimits << std::endl;
    return component_connections.size()-1;
  }
  
  //----------------------------------------------------------------------------
  int GetComponentClass(int c1) {
    int c = c1;
    while (component_connections[c]!=c) {
      c = component_connections[c];
    }
    return c;
  }

  //----------------------------------------------------------------------------
  int MergeComponents(int c1, int c2, bool toucheslimits = false)
  {

    // point to the smallest one
    int cc1 = GetComponentClass(c1);
    int cc2 = GetComponentClass(c2);
    if (cc1==cc2) return cc1;
    if (cc1<cc2) {
      std::cout << "merge " << cc2 << " --> " << cc1 << std::endl;
      component_connections[cc2] = cc1;
      component_toucheslimits[cc1] =  component_toucheslimits[cc1]||
                                      component_toucheslimits[c2] ||
                                      toucheslimits;
      return cc1;
    }
    else {
      std::cout << "merge " << cc1 << " --> " << cc2 << std::endl;
      component_connections[cc1] = cc2;
      component_toucheslimits[cc2] =  component_toucheslimits[cc2]  ||
                                      component_toucheslimits[c1]   ||
                                      toucheslimits;
      return cc2;
    }
  }
};

  
}


#endif // _amiBackgroundComponents_h_