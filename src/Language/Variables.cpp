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

#include "Variables.hpp"
#include <wx/arrstr.h>
#include "driver.h"

#include "amilab_messages.h"

//extern unsigned char       GB_debug;
extern yyip::Driver GB_driver;

//======================================================================
// PRIVATE METHODS
//======================================================================


/*
//--------------------------------------------------
unsigned char Variables::deleteVar(int i)
{

  if (GB_debug)
    fprintf(stderr,"Variables::deleteVar(%d)\n",i);

  if (i<_num) {
    if (GB_debug) fprintf(stderr,"Variables::deleteVar(%d) call to Delete()\n",i);
    _vars[i]->Delete();
    AddFreePosition(i);
  }
  else
    fprintf(stderr,"deleteVar(%i) variable not found \n", i);
  
  return true;
}
*/

//======================================================================
// PUBLIC METHODS
//======================================================================

//--------------------------------------------------
Variables::~Variables()
{
}


//--------------------------------------------------
std::string Variables::CheckVarName(const char* name)
{
  std::string resname(name);

  // Check if the variable exists,
  // if it exists try to delete it,
  // if it cannot be delete, change the name
  if (ExistVar(name)) {
    if (!deleteVar(name)) {
      // otherwise create a new name
      int i = 1;
      Repeter
        resname = (format("%s_%d") % name %i).str();
        i++;
      JusquA Non(ExistVar(resname.c_str())) FinRepeter
    }
  }
  return resname;
}

//--------------------------------------------------
Variable* Variables::AddVar(vartype type, 
		      const char* name, 
		      void* val)
{
  CLASS_MESSAGE(boost::format(" %s ") % name);

  string resname = this->CheckVarName(name);
  Variable* newvar = new Variable();
  newvar->Init(type,resname.c_str(),val);
  _vars.push_front(newvar);

  return newvar;
}

//--------------------------------------------------
// here val is a pointer to a smart pointer
//
Variable* Variables::AddVarPtr(vartype type, 
		      const char* name, 
		      void* val)
{
  CLASS_MESSAGE(boost::format(" %s ") % name);

  string resname = this->CheckVarName(name);
  Variable* newvar = new Variable();
  newvar->InitPtr(type,resname.c_str(),val);
  _vars.push_front(newvar);

  return newvar;
} // AddVarPtr()


//--------------------------------------------------
Variable* Variables::AddVar( Variable* var)
{
  CLASS_MESSAGE(boost::format(" %s ") % var->Name());

  string resname = this->CheckVarName(var->Name());
  Variable* newvar = new Variable();
  (*newvar) = (*var);
  newvar->Rename(resname.c_str());
  _vars.push_front(newvar);
  delete var; // ok not deleting the smart pointer inside, but not too clean ...

  return newvar;
}


//--------------------------------------------------
Variable* Variables::AddVar( const Variable::ptr& var)
{
  CLASS_MESSAGE(boost::format(" %s ") % var->Name());

  string resname = this->CheckVarName(var->Name());
  Variable* newvar = new Variable();
  // TODO: vars should use smart pointers to variables ... and we should avoid this kind of "copy", but now the variable inside contains a smart pointer ...
  (*newvar) = (*var);
  newvar->Rename(resname.c_str());
  _vars.push_front(newvar);

  return newvar;
}


//--------------------------------------------------
Variable* Variables::AddImage(char* name, void* val)
{
  return AddVar(type_image,name,val);
      
}
  
//--------------------------------------------------
void Variables::SearchCompletions(const wxString& varname, wxArrayString* completions)
{
  wxString name;
  std::list<Variable*>::iterator Iter;

  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    name = wxString::FromAscii((*Iter)->Name());
    if (name.First(varname) == 0) 
        completions->Add(name);
  }
}


//--------------------------------------------------
bool Variables::ExistVar(const char* varname)
{
  std::list<Variable*>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->HasName(varname)) return true;
  }

  return false;
}


//--------------------------------------------------
bool Variables::ExistVar(Variable* var)
{
  std::list<Variable*>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ( *(*Iter) == (*var)) return true;
  }
  return false;
}


//--------------------------------------------------
bool Variables::GetVar(const char* varname, Variable** var)
{
  std::list<Variable*>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->HasName(varname)) {
      *var= *Iter;
      return true;
    }
  }
  return false;
}

/*
//--------------------------------------------------
unsigned char Variables::GetVar(const char* varname, int* i)
{
  
  (*i)=0;
  while (((*i)<_num)&&(!_vars[*i]->HasName(varname)))
    {
      //	printf("%s %s\n",(char*) _vars[i]->Name(),varname);
      (*i)++;
      }
  if ((*i)<_num) {
    return 1;
  }
  else {
    return 0;
      }
} // Variables::GetVar()
*/

//--------------------------------------------------
bool Variables::deleteVar(const char* varname)
{
  if (GB_debug) cerr << format("Variables::deleteVar(%s) ") % varname << endl;

  std::list<Variable*>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->HasName(varname)) {
      (*Iter)->Delete();
      delete (*Iter);
      Iter = _vars.erase(Iter);
      return true;
    }
  }
  cerr << format("deleteVar(%s) variable not found \n") % varname;
  return false;

} // Variables::deleteVar()

//--------------------------------------------------
void Variables::display()
{
  printf("VARIABLES:\n");
  std::list<Variable*>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    (*Iter)->display();
    printf("\n");
  }
} // Variables::display()


//--------------------------------------------------
void Variables::EmptyVariables()
{
  std::list<Variable*>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->Type() == type_imagedraw) {
      if ((*Iter)->Pointer()!=NULL) {
        (*Iter)->Delete();
        Iter = _vars.erase(Iter);
      }
    }
  }

  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->Pointer()!=NULL) {
      (*Iter)->Delete();
      Iter = _vars.erase(Iter);
    }
  }

} // Variables::EmptyVariables()

