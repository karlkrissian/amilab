
#include "amiBackgroundComponents.h"
#include <iostream>
namespace ami {

bool BackgroundComponents::ComputeComponents()
{
  if (!input.get()) return false;
  
  // initialize component image
  components = InrImage::ptr(new InrImage(WT_UNSIGNED_INT,"components.ami.gz",
                                          input.get()));
  components->InitImage(0);
  ResetConnections();
  
  int last_comp = 0;
  int x,y,z;
  int xm,ym,zm;
  float currentval;
  int neighcomp[3]; 
  int comp;
  bool touches_limits_z = false;
  bool touches_limits_y = false;
  bool touches_limits_x = false;
  bool touches_limits = false;
  
  for(z=0;z<input->DimZ();z++) 
  {
    zm = (z==0?0:-1);
    touches_limits_z =  ((z==0)||(z==(input->DimZ()-1))) && (input->DimZ()>1);
    
    for(y=0;y<input->DimY();y++) 
    {
      touches_limits_y = ((y==0)||(y==(input->DimY()-1)));
      ym = (y==0?0:-1);
      for(x=0;x<input->DimX();x++)
      {
        touches_limits_x = ((x==0)||(x==(input->DimX()-1)));
        touches_limits = touches_limits_x || touches_limits_y || touches_limits_z;
        xm = (x==0?0:-1);
        comp   = 0;
        if ((*input)(x,y,z)==0) {
          // find components of previous neighbors
          neighcomp[0] = (*components)(x+xm, y,    z   );
          if (neighcomp[0]>0) {
            comp = neighcomp[0];
            component_toucheslimits[comp] = component_toucheslimits[comp] ||
                                            touches_limits;
          }
          neighcomp[1] = (*components)(x,    y+ym, z   );
          if (neighcomp[1]>0) {
            if ((comp>0)&&(comp!=neighcomp[1])) {
              comp = MergeComponents(comp,neighcomp[1],touches_limits);
            } else
              comp = neighcomp[1];
              component_toucheslimits[comp] = component_toucheslimits[comp] ||
                                              touches_limits;
          }
          neighcomp[2] = (*components)(x,    y,    z+zm);
          if (neighcomp[2]>0) {
            if ((comp>0)&&(comp!=neighcomp[2])) {
              comp = MergeComponents(comp,neighcomp[2],touches_limits);
            } else
              comp = neighcomp[2];
              component_toucheslimits[comp] = component_toucheslimits[comp] ||
                                              touches_limits;
          }
          
          // no neighbor found with component
          if (comp==0) {
            last_comp = AddComponent(touches_limits);
            components->SetValue(x,y,z,0,last_comp);
          } else
            components->SetValue(x,y,z,0,comp);
        }
      } // end for x
    } // end for y
  } // end for z

}

} // end namespace ami
