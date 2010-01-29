//
// C++ Interface: wrap_parampanel
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_parampanel_h_
#define _wrap_parampanel_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ParamPanel.hpp"

/** function that add wrapping of the Image Drawing window
 */
Variable::ptr wrap_ParamPanel( ParamList* p);

#define ADD_METHOD(methodname) \
class wrap_ParamPanel##methodname : public WrapClassMember { \
    ParamPanel::ptr _pp; \
  public: \
    wrap_ParamPanel##methodname(const ParamPanel::ptr& pp) : _pp(pp) {} \
    void CallProc(ParamList*); \
};


ADD_METHOD(BeginBook);
ADD_METHOD(EndBook);
ADD_METHOD(BeginHorizontal);
ADD_METHOD(EndHorizontal);
ADD_METHOD(BeginBoxPanel);
ADD_METHOD(EndBoxPanel);

ADD_METHOD(AddPage);

ADD_METHOD(AddFloat);
ADD_METHOD(AddInt);

ADD_METHOD(Display);


#endif
// _wrap_parampanel_h_
