//
// C++ Interface: ParamInfo
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ParamInfo_h_
#define _ParamInfo_h_

#include <wx/sizer.h>

class ParamInfo {
  int               _type;      // precise le type du n-ieme 
  wxGenericWidget*  _wxparam;     // list of wxwidgets used
  wxSizerItem*     _sizeritem; // sizer item

public:
  ParamInfo():  _type(0),
                _wxparam(NULL),
                _sizeritem(NULL)
  {}

  ParamInfo(int type, wxGenericWidget* w, wxSizerItem* s): 
                _type(type),
                _wxparam(w),
                _sizeritem(s)
  {}

  void Init(int type, wxGenericWidget* w, wxSizerItem* s)
  {
    _type      = type;
    _wxparam   = w;
    _sizeritem = s;
  }

  int GetType()                   { return _type;      }
  wxGenericWidget* GetWidget()    { return _wxparam;   }
  wxSizerItem*     GetSizerItem() { return _sizeritem; }
};


#endif // _ParamInfo_h_
