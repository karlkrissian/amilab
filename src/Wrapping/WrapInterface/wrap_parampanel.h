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
BasicVariable::ptr wrap_ParamPanel( ParamList* p);


ADD_METHOD(ParamPanel,BeginBook,        "Starts a notebook.");
ADD_METHOD(ParamPanel,EndBook,          "Ends a notebook.");
ADD_METHOD(ParamPanel,BeginHorizontal,  "Sets horizontal alignment for widgets.");
ADD_METHOD(ParamPanel,EndHorizontal,    "Ends horizontal alignment.");
ADD_METHOD(ParamPanel,BeginBoxPanel,    "Begins a Box around a Panel.");
ADD_METHOD(ParamPanel,EndBoxPanel,      "Ends a Box around a Panel.");

ADD_METHOD(ParamPanel,BeginPanel,       "Begins a Panel.");
ADD_METHOD(ParamPanel,EndPanel,         "Ends a Panel.");

ADD_METHOD(ParamPanel,AddPage,          "Begins a notebook page.");

ADD_METHOD(ParamPanel,SelectPage,       "Select the given page in the notebook.");


ADD_METHOD(ParamPanel,AddFloat,         "Adds a Float parameter.");
ADD_METHOD(ParamPanel,AddInt,           "Adds an Integer parameter.");
ADD_METHOD(ParamPanel,AddEnum,          "Adds an integer variable as an enumeration to the parameter window.");
ADD_METHOD(ParamPanel,AddEnumChoice,    "Adds a choice for an enumeration created in the parameter window.");
ADD_METHOD(ParamPanel,AddLabel,         "Adds a label display.");
ADD_METHOD(ParamPanel,AddFilename,      "Adds a filename selection.");
ADD_METHOD(ParamPanel,AddString,        "Adds a string selection.");
ADD_METHOD(ParamPanel,AddImageChoice,   "Allows the user to choose among the current image global variables available.");
ADD_METHOD(ParamPanel,AddBoolean,       "Adds a boolean selection.");
ADD_METHOD(ParamPanel,AddButton,        "Adds a button.");
ADD_METHOD(ParamPanel,SetCallback,      "Sets a callback on the last parameter.");
ADD_METHOD(ParamPanel,SetDragCallback,      "Activate/Desactivate the drag callback.");
ADD_METHOD(ParamPanel,EnablePanel,      "Enable/Disable a panel.");

//ADD_METHOD(ParamPanel,EnablePanel,      "Enable/Disable a panel.");


ADD_METHOD(ParamPanel,Display,          "Displays the parameters.");
ADD_METHOD(ParamPanel,Hide,             "Hides the parameters.");
ADD_METHOD(ParamPanel,Update,           "Updates the display of one or all the parameters.");

ADD_METHOD(ParamPanel,SetPositionProp,  "Sets the object position properties of the given widget.");
ADD_METHOD(ParamPanel,ShowSlider,       "Show/hide the slider if there is one.");
ADD_METHOD(ParamPanel,Enable,           "Enable/Disable a parameter.");

#endif
// _wrap_parampanel_h_
