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

#ifdef _AMIPREC_
  #include "WrapInterface_header.h"
#else
  #include "wrapfunction_class.h"
  #include "Variable.hpp"
  #include "paramlist.h"
#endif

#include "ParamPanel.hpp"

#include "wrap_wxScrolledWindow.h"
#include "wrap_wxWindow.h"
#include "wrap_wxNotebook.h"

AMI_DECLARE_TYPE(ParamPanel)


class WrapClass_ParamPanel : public WrapClass<ParamPanel>, public WrapClass_wxScrolledWindow
{
  DEFINE_CLASS(WrapClass_ParamPanel);

  protected:  
    // needed to resolve ambiguity from multiple inheritance
    typedef boost::shared_ptr<WrapClass<ParamPanel> > _parentclass_ptr;
    typedef ParamPanel ObjectType;

  public:
    /// Constructor
    WrapClass_ParamPanel(boost::shared_ptr<ParamPanel> pp):  WrapClass<ParamPanel>(pp), WrapClass_wxScrolledWindow(pp)
    {}

    /// Constructor const
    WrapClass_ParamPanel(boost::shared_ptr<ParamPanel const> pp, bool):  
      WrapClass<ParamPanel>(pp,true), 
      WrapClass_wxScrolledWindow(pp,true)
    {}

    std::string ObjPointerAsString() { return "ParamPanel"; }

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( ParamPanel*);

    ADD_CLASS_CONSTRUCTOR( ParamPanel, "Wrapping of ParamPanel." );

    ADD_CLASS_METHOD(GetBookCtrl,      "Returns the notebook.");
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
    
    
    ADD_CLASS_METHOD(AddFloat,           "Adds a Float parameter.");
    ADD_CLASS_METHOD(FloatConstraints,   "Sets the limits of the parameter.");
    ADD_CLASS_METHOD(AddInt,             "Adds an Integer parameter.");
    ADD_CLASS_METHOD(IntegerConstraints, "Sets the limits of the parameter.");
    ADD_CLASS_METHOD(AddEnum,            "Adds an integer variable as an enumeration to the parameter window.");
    ADD_CLASS_METHOD(AddEnumChoice,      "Adds a choice for an enumeration created in the parameter window.");
    ADD_CLASS_METHOD(AddLabel,           "Adds a label display.");
    ADD_CLASS_METHOD(SetLabelValue,      "Changes a label display string.");
    ADD_CLASS_METHOD(AddFilename,        "Adds a filename selection.");
    ADD_CLASS_METHOD(AddDirname,         "Adds a directory selection.");
    ADD_CLASS_METHOD(AddString,          "Adds a string selection.");
    ADD_CLASS_METHOD(AddImageChoice,     "Allows the user to choose among the current image global variables available.");
    ADD_CLASS_METHOD(AddAMIObjectChoice, "Allows the user to choose a certain AMIObject from global variables available.");
    ADD_CLASS_METHOD(AddBoolean,         "Adds a boolean selection.");
    ADD_CLASS_METHOD(AddButton,          "Adds a button.");
    ADD_CLASS_METHOD(AddBitmapButton,    "Adds a bitmap button.");
    ADD_CLASS_METHOD(AddColor,           "Adds a color parameter.");
    ADD_CLASS_METHOD(SetCallback,        "Sets a callback on the last parameter.");
    ADD_CLASS_METHOD(SetDragCallback,    "Activate/Desactivate the drag callback.");
    ADD_CLASS_METHOD(EnablePanel,         "Enable/Disable a panel.");
    
    //ADD_CLASS_METHOD(EnablePanel,      "Enable/Disable a panel.");
    
    
    ADD_CLASS_METHOD(Display,          "Displays the parameters in a tab of the main notebook.");
    ADD_CLASS_METHOD(HidePanel,        "Hides the panel.");
    ADD_CLASS_METHOD(Update,           "Updates  the display of one or all the parameters.");
    ADD_CLASS_METHOD(ShowPanel,        "Fit and show the panel.");
    
    ADD_CLASS_METHOD(SetPositionProp,  "Sets the object position properties of the given widget.");
    ADD_CLASS_METHOD(ShowSlider,       "Show/hide the slider if there is one.");
    ADD_CLASS_METHOD(Enable,           "Enable/Disable a parameter.");

    ADD_CLASS_METHOD(CurrentParent,    "Gets the wxWindow that contains the current parameters.");
    ADD_CLASS_METHOD(GetCurrentSizer,  "Gets the wxBoxSizer that contains the current parameters.");
    ADD_CLASS_METHOD(AddWidget,        "Adds a wxWindow to the current sizer");


    void AddMethods(WrapClass<ParamPanel>::ptr this_ptr )
    {

      AddVar_GetBookCtrl(       this_ptr);
      AddVar_BeginBook(         this_ptr);
      AddVar_EndBook(           this_ptr);
      AddVar_BeginHorizontal(   this_ptr);
      AddVar_EndHorizontal(     this_ptr);
      AddVar_BeginBoxPanel(     this_ptr);
      AddVar_EndBoxPanel(       this_ptr);

      AddVar_BeginPanel(        this_ptr);
      AddVar_EndPanel(          this_ptr);

      AddVar_AddPage(           this_ptr);
      AddVar_SelectPage(        this_ptr);

      AddVar_AddFloat(          this_ptr);
      AddVar_FloatConstraints(  this_ptr);
      AddVar_AddInt(            this_ptr);
      AddVar_IntegerConstraints(this_ptr);
      AddVar_AddEnum(           this_ptr);
      AddVar_AddEnumChoice(     this_ptr);
      AddVar_AddLabel(          this_ptr);
      AddVar_SetLabelValue(     this_ptr);
      AddVar_AddFilename(       this_ptr);
      AddVar_AddDirname(        this_ptr);
      AddVar_AddString(         this_ptr);
      AddVar_AddImageChoice(    this_ptr);
      AddVar_AddAMIObjectChoice(this_ptr);
      AddVar_AddButton(         this_ptr);
      AddVar_AddBitmapButton(   this_ptr);
      AddVar_AddColor(          this_ptr);
      AddVar_AddBoolean(        this_ptr);
      AddVar_SetCallback(       this_ptr);
      AddVar_SetDragCallback(   this_ptr);
      AddVar_EnablePanel(       this_ptr);

      AddVar_Display(          this_ptr);
      AddVar_HidePanel(        this_ptr);
      AddVar_Update(           this_ptr);
      AddVar_ShowPanel(        this_ptr);

      AddVar_SetPositionProp(  this_ptr);
      AddVar_ShowSlider(       this_ptr);
      AddVar_Enable(           this_ptr);

      AddVar_CurrentParent(    this_ptr);
      AddVar_GetCurrentSizer(  this_ptr);
      AddVar_AddWidget(        this_ptr);

      // Adding Bases
//       // Add members from wxWindow
//       WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
//       parent_obj->AddMethods(parent_obj);

      // Add public fields 
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());

      // Add base parent wxScrolledWindow
      boost::shared_ptr<wxScrolledWindow > parent_wxScrolledWindow(  boost::dynamic_pointer_cast<wxScrolledWindow >(this_ptr->GetObj()));
      BasicVariable::ptr var_wxScrolledWindow = AMILabType<wxScrolledWindow>::CreateVarFromSmtPtr(parent_wxScrolledWindow);
      context->AddVar("wxScrolledWindow",var_wxScrolledWindow);
      // Set as a default context
      Variable<AMIObject>::ptr obj_wxScrolledWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxScrolledWindow);
      context->AddDefault(obj_wxScrolledWindow->Pointer()->GetContext());

      
    }

};



#endif
// _wrap_parampanel_h_
