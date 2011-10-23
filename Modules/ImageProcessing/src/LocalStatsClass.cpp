
#include "LocalStatsClass.h"
#include "localstats.h"

//------------------------------------------------------------------------------
InrImage::ptr LocalStatsClass::localmean(InrImage::ptr input, int size)
{
  InrImage::ptr res( Func_localmean( input.get(), size));
  return res;
}
  
//------------------------------------------------------------------------------
InrImage::ptr LocalStatsClass::localmean2(
                                  InrImage::ptr input,
                                  int size )
{
  InrImage::ptr res( Func_localmean2( input.get(), size));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr LocalStatsClass::localSD(
                                  InrImage::ptr input,
                                  InrImage::ptr Imean,
                                  int size )
{
  InrImage::ptr res( Func_localSD( input.get(), Imean.get(), size));
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr LocalStatsClass::localSD2(
                                  InrImage::ptr input,
                                  InrImage::ptr Imean,
                                  int size )
{
  InrImage::ptr res( Func_localSD2( input.get(), Imean.get(), size));
  return res;
}
