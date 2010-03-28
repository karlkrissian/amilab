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


class WrapClass_parampanel : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_parampanel);

  // for nested classes
  typedef WrapClass_parampanel::ptr _parentclass_ptr;

  public:
    ParamPanel::ptr _parampanel;

  ADD_CLASS_METHOD(BeginBook,        "Starts a notebook.");
  ADD_CLASS_METHOD(EndBook,          "Ends a notebook.");
  ADD_CLASS_METHOD(BeginHorizontal,  "Sets horizontal alignment for widgets.");
  ADD_CLASS_METHOD(EndHorizontal,    "Ends horizontal alignment.");
  ADD_CLASS_METHOD(BeginBoxPanel,    "Begins a Box around a Panel.");
  ADD_CLASS_METHOD(EndBoxPanel,      "Ends a Box around a Panel.");
  
  ADD_CLASS_METHOD(BeginPanel,       "Begins a Panel.");
  ADD_CLASS_METHOD(EndPanel,         "Ends a Panel.");
  
  ADD_CLASS_METHOD(AddPage,          "Begins a notebook page.");
  
  ADD_CLASS_METHOD(SelectPage,       "Select the given page in the notebook.");
  
  
  ADD_CLASS_METHOD(AddFloat,         "Adds a Float parameter.");
  ADD_CLASS_METHOD(AddInt,           "Adds an Integer parameter.");
  ADD_CLASS_METHOD(AddEnum,          "Adds an integer variable as an enumeration to the parameter window.");
  ADD_CLASS_METHOD(AddEnumChoice,    "Adds a choice for an enumeration created in the parameter window.");
  ADD_CLASS_METHOD(AddLabel,         "Adds a label display.");
  ADD_CLASS_METHOD(AddFilename,      "Adds a filename selection.");
  ADD_CLASS_METHOD(AddDirname,       "Adds a directory selection.");
  ADD_CLASS_METHOD(AddString,        "Adds a string selection.");
  ADD_CLASS_METHOD(AddImageChoice,   "Allows the user to choose among the current image global variables available.");
  ADD_CLASS_METHOD(AddBoolean,       "Adds a boolean selection.");
  ADD_CLASS_METHOD(AddButton,        "Adds a button.");
  ADD_CLASS_METHOD(SetCallback,      "Sets a callback on the last parameter.");
  ADD_CLASS_METHOD(SetDragCallback,  "Activate/Desactivate the drag callback.");
  ADD_CLASS_METHOD(EnablePanel,      "Enable/Disable a panel.");
  
  //ADD_CLASS_METHOD(EnablePanel,      "Enable/Disable a panel.");
  
  
  ADD_CLASS_METHOD(Display,          "Displays the parameters in a tab of the main notebook.");
  ADD_CLASS_METHOD(HidePanel,        "Hides the panel.");
  ADD_CLASS_METHOD(Update,           "Updates  the display of one or all the parameters.");
  ADD_CLASS_METHOD(ShowPanel,        "Fit and show the panel.");
  
  ADD_CLASS_METHOD(SetPositionProp,  "Sets the object position properties of the given widget.");
  ADD_CLASS_METHOD(ShowSlider,       "Show/hide the slider if there is one.");
  ADD_CLASS_METHOD(Enable,           "Enable/Disable a parameter.");

  ADD_CLASS_METHOD(CurrentParent,    "Get the wxWindow that contains the current parameters.");
  ADD_CLASS_METHOD(AddWidget,         "Adds a wxWindow to the current sizer");

};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_ParamPanel( ParamList* p);



#endif
// _wrap_parampanel_h_
