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

#define ADD_METHOD(classname,methodname,description_str) \
/**\
 * description_str\
 **/\
class wrap_##classname##methodname : public WrapClassMember { \
  protected:\
    classname::ptr _pp; \
  public: \
    wrap_##classname##methodname(const classname::ptr& pp) : \
      _pp(pp) { \
      functionname = #classname;\
      functionname += "::";\
      functionname += #methodname; \
      description=description_str; \
    } \
    void CallProc(ParamList*); \
};


ADD_METHOD(ParamPanel,BeginBook,        "Starts a notebook.");
ADD_METHOD(ParamPanel,EndBook,          "Ends a notebook.");
ADD_METHOD(ParamPanel,BeginHorizontal,  "Sets horizontal alignment for widgets.");
ADD_METHOD(ParamPanel,EndHorizontal,    "Ends horizontal alignment.");
ADD_METHOD(ParamPanel,BeginBoxPanel,    "Begins a Box around a Panel.");
ADD_METHOD(ParamPanel,EndBoxPanel,      "Ends a Box around a Panel.");

ADD_METHOD(ParamPanel,AddPage,          "Begins a notebook page.");

ADD_METHOD(ParamPanel,AddFloat,         "Adds a Float parameter.");
ADD_METHOD(ParamPanel,AddInt,           "Adds a Integer parameter.");

ADD_METHOD(ParamPanel,Display,          "Displays the parameters.");


#endif
// _wrap_parampanel_h_
