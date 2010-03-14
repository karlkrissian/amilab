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
#include "style.hpp"
#include <wx/arrstr.h>
//#include "driver.h"

#include "amilab_messages.h"

//extern unsigned char       GB_debug;
//extern yyip::Driver GB_driver;

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
  CLASS_MESSAGE("");
  EmptyVariables();
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
      JusquA Non(ExistVar(resname.c_str())) FinRepeter;
    }
  }
  return resname;
}

//--------------------------------------------------
BasicVariable::ptr Variables::AddVar( 
          const std::string& name, 
          BasicVariable::ptr& val, 
          boost::shared_ptr<Variables> context)
{
  CLASS_MESSAGE(boost::format(" %1%, in %2% ") % name % GetName());

  std::string resname = this->CheckVarName(name.c_str());
  BasicVariable::ptr newvar(val);
  //std::cout << "  **  newvar =  " << newvar << endl;

  newvar->Rename(resname.c_str());
  newvar->SetContext(context);
  _vars.push_front(newvar);

  return newvar;
}



//--------------------------------------------------
BasicVariable::ptr Variables::AddVar( BasicVariable::ptr& var, Variables::ptr context )
{

  CLASS_MESSAGE(boost::format(" %s ") % var->Name());

  string resname = this->CheckVarName(var->Name().c_str());
  // TODO: fix the following code, maybe not so easy ...
  // should we copy the contents here ??
  BasicVariable::ptr newvar(var->NewReference());
  newvar->Rename(resname.c_str());
  newvar->SetContext(context);
  _vars.push_front(newvar);

  return newvar;
}


//--------------------------------------------------
void Variables::SearchCompletions(const wxString& varname, 
    boost::shared_ptr<wxArrayString>& completions)
{
  wxString name;
  std::list<BasicVariable::ptr>::iterator Iter;

  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    name = wxString::FromAscii((*Iter)->Name().c_str());
    if (name.First(varname) == 0) 
        completions->Add(name);
  }
}


//--------------------------------------------------
void Variables::SearchVariables( const vartype& type,
                      boost::shared_ptr<wxArrayString>& varlist,
                      const std::string& prepend)
{
  wxString name;
  std::list<BasicVariable::ptr>::iterator Iter;

  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->Type()==type) {
      name = wxString::FromAscii((prepend+(*Iter)->Name()).c_str());
      varlist->Add(name);
    }
  }
} // SearchVariables()


//--------------------------------------------------
bool Variables::ExistVar(const char* varname)
{
  std::list<BasicVariable::ptr>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->HasName(varname)) return true;
  }

  return false;
}


//--------------------------------------------------
bool Variables::ExistVar(BasicVariable::ptr& var)
{
  std::list<BasicVariable::ptr>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ( *(*Iter) == var ) return true;
  }
  return false;
}

//--------------------------------------------------
bool Variables::ExistVar(BasicVariable* var)
{
  std::list<BasicVariable::ptr>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ( *(*Iter) == var ) return true;
  }
  return false;
}


//--------------------------------------------------
BasicVariable::ptr Variables::GetVar(const char* varname)
{
  std::list<BasicVariable::ptr>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->HasName(varname)) {
      return BasicVariable::ptr(*Iter);
    }
  }
  return BasicVariable::ptr();
}

/*
//--------------------------------------------------
unsigned char Variables::GetVar(const char* varname, int* i)
{
  
  (*i)=0;
  while (((*i)<_num)&&(!_vars[*i]->HasName(varname)))
    {
      //  printf("%s %s\n",(char*) _vars[i]->Name(),varname);
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
  CLASS_MESSAGE( format("Variables::deleteVar(%s) for %s") % varname % GetName());

  std::list<BasicVariable::ptr>::iterator Iter;
  for (Iter  = _vars.begin();
       Iter != _vars.end()  ; Iter++ )
  {
    if ((*Iter)->HasName(varname)) {
      //delete (*Iter); // not needed anymore
      //(*Iter)->Delete();

      CLASS_MESSAGE( boost::format("removing variable from the list (use_count = %1%)") %  (*Iter).use_count());
      Iter = _vars.erase(Iter);
      return true;
    }
  }
  CLASS_ERROR( format("deleteVar(%s) variable not found") % varname);
  return false;

} // Variables::deleteVar()


//--------------------------------------------------
int Variables::deleteVars(const std::string& varmatch)
{
  // convert string to wxString
  wxString wxvarmatch(varmatch.c_str(), wxConvUTF8);
  int count=0;

  std::list<BasicVariable::ptr>::iterator Iter;
  Iter  = _vars.begin();
  while(Iter != _vars.end())
  {
    // convert name to wxString
    wxString wxvarname((*Iter)->Name().c_str(), wxConvUTF8);
    if (wxvarname.Matches(wxvarmatch)) {
      // why seg fault ??
      // delete *Iter; // try to delete the variable here // not needed anymore
      //(*Iter)->Delete();
      Iter = _vars.erase(Iter);
      count++;
    } else
      Iter++;
  }
  return count;
} // Variables::deleteVars()


//--------------------------------------------------
void Variables::display()
{
  printf("VARIABLES:\n");
  std::list<BasicVariable::ptr>::iterator Iter;
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
  CLASS_MESSAGE(boost::format("  in %1% ") % GetName());
  std::list<BasicVariable::ptr>::iterator Iter;
  Iter  = _vars.begin();
  while (Iter != _vars.end() )
  {
    if (((*Iter)->Type() == type_imagedraw)||
        ((*Iter)->Type() == type_surfdraw )) {
      Iter = _vars.erase(Iter);
      continue;
    }
    Iter++;
  }

  Iter  = _vars.begin();
  while ( Iter != _vars.end())
  {
    Iter = _vars.erase(Iter);
  }

} // Variables::EmptyVariables()

