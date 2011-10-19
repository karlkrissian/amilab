
#include "NoiseAnalysisClass.h"

InrImage::ptr NoiseAnalysis::medialocal( InrImage::ptr input, int size)
{
  InrImage::ptr res( new InrImage(WT_FLOAT,"medialocal.ami.gz",input.get()));
  *res = *input;
  float* data0 = (float*) res->BufferPtr(0,0);
	float* data = data0;
	int x,y;
	int dx = res->DimX();
	int dy = res->DimY();
	for(y=0;y<dy;y++)
	for(x=1;x<dx-1;x++)
	{
		data = data0+dx*y+x;
		*data = (*(data-1)+*data+*(data+1))/3.0;
	}
	return res;
}