
#include "amiFind.h"
#include <vector>

namespace ami {
  
  InrImage::ptr Find::Run(InrImage::ptr input)
  {
    std::vector<PositionClass> positions;
    
    for(int x=0; x<input->DimX()-1;x++)
    for(int y=0; y<input->DimY()-1;y++)
    for(int z=0; z<input->DimZ()-1;z++)
    {
      if ((*input)(x,y,z)>0) 
      {
        positions.push_back( PositionClass(x,y,z));
      }
    }
    
    InrImage::ptr res(new InrImage(positions.size(),1,1,3,WT_SIGNED_SHORT));
    res->InitBuffer();
    for(int n=0; n<positions.size(); n++) 
    {
      res->VectFixeValeur (0, positions[n]._x );
      res->VectFixeValeur (1, positions[n]._y );
      res->VectFixeValeur (2, positions[n]._z );
      res->IncBuffer();
    }
    return res;
  }


  InrImage::ptr Find::ApplyValues(   InrImage::ptr input,
                                     InrImage::ptr positions,
                                     InrImage::ptr values)
  {
    InrImage::ptr res(new InrImage(   input->GetFormat(),"applyval.ami.gz"
                                      ,input.get()));
    (*res) = (*input);
    for(int x=0; x<positions->DimX(); x++) {
      int px = (*positions)(x,0,0,0);
      int py = (*positions)(x,0,0,1);
      int pz = (*positions)(x,0,0,2);
      res->BufferPos(px,py,pz);
      res->FixeValeur((*values)(x,0,0));
    }
    return res;
  }

}