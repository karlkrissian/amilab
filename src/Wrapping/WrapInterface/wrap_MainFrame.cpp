//
// C++ Implementation: wrap_MainFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_MainFrame.h"
#include "wrap_wxStcFrame.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_MainFrame(  MainFrame* mf)
{
  // here MainFrame cannot be deleted
  boost::shared_ptr<MainFrame> mf_ptr( 
        mf,
        wxwindow_nodeleter<MainFrame>() // deletion will be done by wxwidgets
      );

  WrapClass_MainFrame::ptr objectptr( new WrapClass_MainFrame(mf_ptr) );

  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("MainFrame");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_MainFrame( MainFrame* si)
{
  AMIObject::ptr amiobject(AddWrap_MainFrame(si));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  MainFrame Constructor
//---------------------------------------------------
void  wrap_MainFrame::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr wrap_MainFrame::CallMember( ParamList* p)
{
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  GetAmilabEditor
//---------------------------------------------------
void WrapClass_MainFrame::
      wrap_GetAmilabEditor::SetParametersComments() 
{
  return_comments = "The current editor as a wxStcFrame object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_MainFrame::
      wrap_GetAmilabEditor::CallMember( ParamList* p)
{
  wxStcFrame* editor = this->_objectptr->_obj->GetAmilabEditor();
  return CreateVar_wxStcFrame(editor);
}

