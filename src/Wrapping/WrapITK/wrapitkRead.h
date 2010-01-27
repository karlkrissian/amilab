#ifndef _wrapitkRead_h_
#define _wrapitkRead_h_

#include "paramlist.h"

InrImage* itkRead(const std::string& fname);
InrImage* wrap_itkRead(ParamList*);

#endif // _wrapitkRead_h_

