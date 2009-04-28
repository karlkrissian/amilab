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

#include <wx/arrstr.h>

extern unsigned char       GB_debug;

//======================================================================
// PUBLIC MEMBERS
//======================================================================

//--------------------------------------------------
VarContexts::VarContexts() {
  
  // TODO: create a stack or a vector ...
  _num_contexts_allocated = 20;
  _context      = new Variables[_num_contexts_allocated];
  _context_name = new Chaine[   _num_contexts_allocated];
  _global_new   = new unsigned char[_num_contexts_allocated];
  _current_context = 0;
  _context_depth   = 0;
  _context_name[0] = "global variables";
  
  
  for(int i=0; i<_num_contexts_allocated; i++) _global_new[i]=0;
  _next_variable_context = -1;
}

//--------------------------------------------------
VarContexts::~VarContexts() {
  delete [] _context;
  delete [] _context_name;
}


//--------------------------------------------------
int VarContexts::NewContext(const char* name) {

  _current_context = _context_depth;
  if (_current_context<_num_contexts_allocated-1) {
    _current_context++;
    _context_name[_current_context] = name;
  } else {
    if (DoubleContexts()) {
      _current_context++;
      _context_name[_current_context] = name;
    } else {
      fprintf(stderr,"VarContexts::NewContext() \t error, cannot increase the number of contexts \n");
      return -1;
    }
  }
  if (GB_debug) fprintf(stderr,"New context number %d \n",_current_context);
  _context_depth = _current_context;
  return _current_context;
}

//--------------------------------------------------
int VarContexts::DeleteLastContext() {

  _current_context = _context_depth;
  if (GB_debug) fprintf(stderr,"Removing context number %d \n",_current_context);
  if (_current_context>0) {
    _context_name[_current_context] = "";
    _context[_current_context].EmptyVariables();
    _current_context--;
    _context_depth--;
    return _current_context;
  }
  else {
    fprintf(stderr,"VarContexts::DeleteLastContext() \t cannot remove the main context \n");
    return -1;
  }
}

//--------------------------------------------------
void VarContexts::display() {
  int i;
  
  for(i=_current_context;i>=0;i--) {
      printf("\n Context %d %s \n ------------- \n",
	     i,(char*)_context_name[i]);
      _context[i].display();
  }
}


//--------------------------------------------------
unsigned char VarContexts::ExistVar(const char* varname) 
{
  int i,n; 
  for(i=_current_context;i>=0;i--)
    if (_context[i].ExistVar(varname,n)) return 1;
  return 0;
}

//--------------------------------------------------
wxArrayString* VarContexts::SearchCompletions(const wxString& varname) 
{
  int i; 
  wxArrayString* completions;

  completions = new wxArrayString();

  for(i=_current_context;i>=0;i--)
    _context[i].SearchCompletions(varname,completions);
  return completions;
}


//--------------------------------------------------
int VarContexts::GetNewVarContext()
{
  if ((_next_variable_context>=0)&&
      (_next_variable_context<=_current_context)) {
    int context = _next_variable_context;
    _next_variable_context=-1;
    return context;
  } else
    if (this->_global_new[this->_current_context]) 
      return 0; 
    else 
      return _current_context;
} // GetNewVarContext()


//--------------------------------------------------
int VarContexts::AddVar(vartype type, const char* name, void* val)
{
  int context = GetNewVarContext();
  if (GB_debug) fprintf(stderr,"AddVar in context number %d ",context);
  return _context[context].AddVar(type,name,val);
} // AddVar()


//--------------------------------------------------
// void* val is a pointer to a smart pointer of the type
//
int VarContexts::AddVarPtr(vartype type, const char* name, void* val)
{
  int context = GetNewVarContext();
  if (GB_debug) fprintf(stderr,"AddVar in context number %d ",context);
  return _context[context].AddVarPtr(type,name,val);

} // AddVarPtr()


//--------------------------------------------------
int VarContexts::AddVar(Variable* var)
{
  int context = GetNewVarContext();
  if (GB_debug) fprintf(stderr,"AddVar in context number %d ",context);
  return _context[context].AddVar(var);
}

//--------------------------------------------------
int VarContexts::AddVar(Variable::ptr var)
{
  int context = GetNewVarContext();
  if (GB_debug) fprintf(stderr,"AddVar in context number %d ",context);
  return _context[context].AddVar(var);
}

//--------------------------------------------------
unsigned char VarContexts::GetVar(const char* varname, Variable** var,
                                  int context)
{
  if (context==-1) {
    for(int i=_current_context;i>=0;i--)
      if (_context[i].GetVar(varname,var)) return 1;
  } else 
    if ((context>=0)&&(context<=_current_context))
      if (_context[context].GetVar(varname,var)) return 1;

  return 0;
}


//--------------------------------------------------
unsigned char VarContexts::deleteVar(const char* varname)
{
  int i,n;
  for(i=_current_context;i>=0;i--)
    if (_context[i].ExistVar(varname,n)) {
      if (GB_debug) fprintf(stderr,"Delete Var in context number %d \n",i);
      return _context[i].deleteVar(n);
    }
  return 0;
}


//--------------------------------------------------
int VarContexts::GetContext(Variable* var)
{
  int i,n;
  for(i=_current_context;i>=0;i--)
    if (_context[i].ExistVar(var,n)) 
      return i;
  return -1;
}


//--------------------------------------------------
unsigned char VarContexts::deleteVar(Variable* var)
{
  int i,n;
  for(i=_current_context;i>=0;i--)
    if (_context[i].ExistVar(var,n)) {
      if (GB_debug) fprintf(stderr,"Delete Var in context number %d \n",i);
      return _context[i].deleteVar(n);
    }
  return 0;
}


//--------------------------------------------------
void VarContexts::SetCurrentContext(int n) {
  if ((n>=0)&&(n<=_context_depth))
    _current_context = n;
}


//--------------------------------------------------
void VarContexts::SetLastContext() {
  _current_context = _context_depth;
}
