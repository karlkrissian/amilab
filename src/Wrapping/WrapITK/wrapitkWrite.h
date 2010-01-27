#ifndef _wrapitkWrite_h_
#define _wrapitkWrite_h_

#include "paramlist.h"

bool itkWrite(InrImage* input, const std::string& fname);
void wrap_itkWrite(ParamList*);

#endif // _wrapitkWrite_h_