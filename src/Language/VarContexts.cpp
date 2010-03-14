/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "VarContexts.hpp"
#include "amilab_messages.h"

#include <wx/arrstr.h>

extern unsigned char       GB_debug;

//======================================================================
// PUBLIC MEMBERS
//======================================================================

//--------------------------------------------------
VarContexts::VarContexts() {
  _context.push_back(Variables::ptr(new Variables()));
  _context[0]->SetName("Global context");
  _current_context = 0;
}

//--------------------------------------------------
VarContexts::~VarContexts() {
  CLASS_MESSAGE("");
  // no need to delete, smart pointers ...
  while (_context.size()>1) {
    DeleteLastContext();
  }
}

//--------------------------------------------------
void VarContexts::EmptyVariables() {
  CLASS_MESSAGE("");
  for (int i=_context.size()-1; i>=0; i--)
    _context[i]->EmptyVariables();
}

//--------------------------------------------------
bool VarContexts::NewContext(const char* name) {

  Variables::ptr newcontext = Variables::ptr(new Variables());
  newcontext->SetName(name);
  _context.push_back(newcontext);

  if (GB_debug) 
    cerr << "New context " << name << endl;

  return true;
}

//--------------------------------------------------
bool VarContexts::DeleteLastContext() {

  CLASS_MESSAGE("Removing last context")
  if (_context.size()>1) {
    // no need to delete, smart pointer
    //Variables::ptr last_context = _context.back();
    //last_context->EmptyVariables();
    // delete last_context;
    _context.pop_back();
    SetLastContext();
    return true;
  }
  else {
    CLASS_ERROR("Cannot remove the main context ");
    return false;
  }
}

//--------------------------------------------------
void VarContexts::display() {

  for (int i=_context.size()-1; i>=0; i--)
  {
    cout  << "\n"
          << "Context " << i 
          << " " << _context[i]->GetName()
          << "\n ------------- \n",
    _context[i]->display();
  }

}


//--------------------------------------------------
bool VarContexts::ExistVar(const char* varname) 
{
  for (int i=_context.size()-1; i>=0; i--)
    if (_context[i]->ExistVar(varname)) return true;
  return false;
}

//--------------------------------------------------
boost::shared_ptr<wxArrayString> VarContexts::SearchCompletions(const wxString& varname) 
{
  boost::shared_ptr<wxArrayString> completions;

  completions = boost::shared_ptr<wxArrayString>(new wxArrayString());

  for (int i=_context.size()-1; i>=0; i--)
    _context[i]->SearchCompletions(varname,completions);
  return completions;
}


//--------------------------------------------------
boost::shared_ptr<wxArrayString> VarContexts::SearchVariables(const vartype& type)
{
  boost::shared_ptr<wxArrayString> completions;
  completions = boost::shared_ptr<wxArrayString>(new wxArrayString());

  for (int i=_context.size()-1; i>=1; i--)
    _context[i]->SearchVariables(type,completions);

  // global context, prepend "global::"
  _context[0]->SearchVariables(type,completions,"global::");
  return completions;
}


//--------------------------------------------------
int VarContexts::GetNewVarContext()
{
  if (this->_context[_current_context]->GetGlobalNew())
    return 0; 
  else 
    return _current_context;
} // GetNewVarContext()




//--------------------------------------------------
BasicVariable::ptr VarContexts::AddVar(  
              const IdentifierInfo::ptr& info, 
              BasicVariable::ptr& val)
{
  int context;
  context = info->GetCreationContext();
  return AddVar(info->GetName().c_str(),val,context);
} // AddVar()

//--------------------------------------------------
BasicVariable::ptr VarContexts::AddVar(BasicVariable::ptr var, int context)
{

  if (context==OBJECT_CONTEXT_NUMBER) {
    CLASS_MESSAGE("object context");
    if (_object_context.get()) {
      CLASS_MESSAGE("adding variable reference into object context ");
      return _object_context->AddVar(var, _object_context);
    }
    else {
      CLASS_ERROR("Calling object variable without any object context");
      return BasicVariable::ptr();
    }
  }

  if (context==NEWVAR_CONTEXT) 
    context = GetNewVarContext();

  CLASS_MESSAGE(boost::format("Context number %d ")% context);
  return _context[context]->AddVar(var);
}

//--------------------------------------------------
BasicVariable::ptr VarContexts::GetVar(const char* varname, int context)
{
  if (context==-1) {
    // TODO: limit to last context, if nothing else is specified !!!
    //for(int i=_context.size()-1;i>=0;i--)
    //  if (_context[i]->GetVar(varname,var)) return true;
    return _context[_context.size()-1]->GetVar(varname);
  }
  else 
    if ((context>=0)&&(context<=_current_context))
      return _context[context]->GetVar(varname);
  else
    if ((context==OBJECT_CONTEXT_NUMBER)&&(_object_context.get())) {
      //CLASS_MESSAGE(boost::format("Looking in object context for %1% ... %2% ") % varname % res );
      //_object_context->display();
      return _object_context->GetVar(varname);
    }

  return BasicVariable::ptr();
}


//--------------------------------------------------
bool VarContexts::deleteVar(const char* varname)
{
  int i;
  for(i=_current_context;i>=0;i--)
    if (_context[i]->deleteVar(varname)) {
      if (GB_debug) 
        cerr << "Deleted Var in context number " << i << endl;
      return true;
    }
  return false;
}


//--------------------------------------------------
int VarContexts::GetContext(BasicVariable::ptr var)
{
  // check first for object context
  if (var->GetContext().get()) {
      return OBJECT_CONTEXT_NUMBER;
  }
  for(int i=_current_context;i>=0;i--)
    if (_context[i]->ExistVar(var)) 
      return i;
  return -1;
}


//--------------------------------------------------
bool VarContexts::deleteVar(BasicVariable::ptr var)
{

  // Check for object context
  if (var->GetContext().get()) {
    var->GetContext()->deleteVar(var->Name().c_str());
    return true;
  }

  for(int i=_current_context;i>=0;i--)
    if (_context[i]->ExistVar(var)) {
      if (GB_debug) 
        cerr << "Deleted Var in context number " << i << endl;
      // TODO: improve efficiency by not going twice through the variables
      _context[i]->deleteVar(var->Name().c_str());
      return true;
    }
  return false;
}

//--------------------------------------------------
bool VarContexts::deleteVar(BasicVariable* var)
{

  // Check for object context
  if (var->GetContext().get()) {
    var->GetContext()->deleteVar(var->Name().c_str());
    return true;
  }

  for(int i=_current_context;i>=0;i--)
    if (_context[i]->ExistVar(var)) {
      if (GB_debug) 
        cerr << "Deleted Var in context number " << i << endl;
      // TODO: improve efficiency by not going twice through the variables
      _context[i]->deleteVar(var->Name().c_str());
      return true;
    }
  return false;
}

//--------------------------------------------------
int VarContexts::deleteVars(const std::string& varmatch)
{
  int count =0;

  int i;
  for(i=_current_context;i>=0;i--)
    count += _context[i]->deleteVars(varmatch);

  return count;
  
}

//--------------------------------------------------
void VarContexts::SetGlobalContext() {
  _current_context = 0;
}


//--------------------------------------------------
void VarContexts::SetLastContext() {
  _current_context = _context.size()-1;
}
