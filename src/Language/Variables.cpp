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

extern unsigned char       GB_debug;
extern void err_print(const char* st);

//======================================================================
// PRIVATE METHODS
//======================================================================

void Variables::AddFreePosition( int i)
{
    if (_num_free<MAX_VARS) {
      _free_pos[_num_free]=i;
      _num_free++;
    }
}

//--------------------------------------------------
int Variables::GetFreePosition()
{
    if (_num_free>0) {
      _num_free--;
      return _free_pos[_num_free];
    }
    else
      return -1;
}


//--------------------------------------------------
int Variables::SearchFreePosition()
{
    int pos;
    if ((pos=GetFreePosition())!=-1) return pos;
    if (_num>=MAX_VARS-1) 
    {
      err_print("Variables::SearchFreePosition() too many variables.\n");
      return -1;
    }
    else 
    {
      _num++;
      return _num-1;
    }
}


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


//======================================================================
// PUBLIC METHODS
//======================================================================

//--------------------------------------------------
Variables::Variables()
{
  int i;
  _num = 0;
  _num_free=0;
  Pour(i,0,MAX_VARS-1)
    _vars[i] = new Variable();
  FinPour
  
//  _global_new = 0;
}

//--------------------------------------------------
Variables::~Variables()
{
  int i;
  
  Pour(i,0,MAX_VARS-1)
    delete _vars[i];
  FinPour
}

//--------------------------------------------------
int Variables::AddVar(vartype type, 
		      const char* name, 
		      void* val)
{
     int i,varnum=0;
     char   resname[100];
     int pos;

   if (GB_debug) fprintf(stderr,"AddVar %s \t\t",name);

   // Check if the variable exists,
   // if it exists try to delete it,
   // if it cannot be delete, change the name

   sprintf(resname,"%s",name);
   Si ExistVar(name,varnum) Alors
     // Try to delete the variable
     Si Non(deleteVar(varnum)) Alors
       // otherwise create a new name
       i = 1;
       Repeter
         sprintf(resname,"%s_%d",name,i);
         i++;
       JusquA Non(ExistVar(resname,varnum)) FinRepeter
     FinSi
   FinSi

   pos=SearchFreePosition();
   if (pos>=0)
    _vars[pos]->Init(type,resname,val);
     if (GB_debug) fprintf(stderr,"position %d, _num_free = %d ,_num = %d \n",pos,_num_free,_num);
   return pos;
}

//--------------------------------------------------
// here val is a pointer to a smart pointer
//
int Variables::AddVarPtr(vartype type, 
		      const char* name, 
		      void* val)
{
     int i,varnum=0;
     char   resname[100];
     int pos;

   if (GB_debug) fprintf(stderr,"AddVar %s \t\t",name);

   // Check if the variable exists,
   // if it exists try to delete it,
   // if it cannot be delete, change the name
   sprintf(resname,"%s",name);
   Si ExistVar(name,varnum) Alors
     // Try to delete the variable
     Si Non(deleteVar(varnum)) Alors
       // otherwise create a new name
       i = 1;
       Repeter
         sprintf(resname,"%s_%d",name,i);
         i++;
       JusquA Non(ExistVar(resname,varnum)) FinRepeter
     FinSi
   FinSi

   pos=SearchFreePosition();
   if (pos>=0)
    _vars[pos]->InitPtr(type,resname,val);
     if (GB_debug) fprintf(stderr,"position %d, _num_free = %d ,_num = %d \n",pos,_num_free,_num);
   return pos;
} // AddVarPtr()


//--------------------------------------------------
int Variables::AddVar( Variable* var)
{
     int i,varnum=0;
     char   resname[100];
     int pos;

   if (GB_debug) fprintf(stderr,"AddVar %s \t\t",var->Name());

   // Check if the variable exists,
   // if it exists try to delete it,
   // if it cannot be delete, change the name

   sprintf(resname,"%s",var->Name());
   Si ExistVar(var->Name(),varnum) Alors
     // Try to delete the variable
     Si Non(deleteVar(varnum)) Alors
       // otherwise create a new name
       i = 1;
       Repeter
         sprintf(resname,"%s_%d",var->Name(),i);
         i++;
       JusquA Non(ExistVar(resname,varnum)) FinRepeter
     FinSi
   FinSi

   pos=SearchFreePosition();
   if (pos>=0)
    var->Rename(resname);
    (*_vars[pos]) = (*var);
    delete var; // ok not deleting the smart pointer inside, but not too clean ...
    if (GB_debug) fprintf(stderr,"position %d, _num_free = %d ,_num = %d \n",pos,_num_free,_num);
   return pos;
}


//--------------------------------------------------
int Variables::AddVar( const Variable::ptr& var)
{
     int i,varnum=0;
     char   resname[100];
     int pos;

   if (GB_debug) fprintf(stderr,"AddVar %s \t\t",var->Name());

   // Check if the variable exists,
   // if it exists try to delete it,
   // if it cannot be delete, change the name

   sprintf(resname,"%s",var->Name());
   Si ExistVar(var->Name(),varnum) Alors
     // Try to delete the variable
     Si Non(deleteVar(varnum)) Alors
       // otherwise create a new name
       i = 1;
       Repeter
         sprintf(resname,"%s_%d",var->Name(),i);
         i++;
       JusquA Non(ExistVar(resname,varnum)) FinRepeter
     FinSi
   FinSi

   pos=SearchFreePosition();
   if (pos>=0)
    var->Rename(resname);
    // TODO: vars should use smart pointers to variables ... and we should avoid this kind of "copy"
    (*_vars[pos]) = var;
    if (GB_debug) fprintf(stderr,"position %d, _num_free = %d ,_num = %d \n",pos,_num_free,_num);
   return pos;
}


//--------------------------------------------------
int Variables::AddImage(char* name, void* val)
{
  return AddVar(type_image,name,val);
      
}
  
//--------------------------------------------------
void Variables::SearchCompletions(const wxString& varname, wxArrayString* completions)
{
  int i;
  wxString name;
  
  for(i=0;i<_num;i++) {
    name = wxString::FromAscii(_vars[i]->Name());
    if (name.First(varname) == 0) 
        completions->Add(name);
  }
}


//--------------------------------------------------
unsigned char Variables::ExistVar(const char* varname, int& varnum)
{
  int i;
  
  i=0;
  while ((i<_num)&&(!_vars[i]->HasName(varname)))
    {
      //	printf("%s %s\n",
      //         (char*) _vars[i]->Name(),varname);
      i++;
    }
  if (i<_num) {
    varnum = i;
    return 1;
      }
  else {
    return 0;
  }
}


//--------------------------------------------------
unsigned char Variables::ExistVar(Variable* var, int& varnum)
{
  int i;
  
  i=0;
  while ((i<_num)&&(! ((*_vars[i])==(*var)) ))
    {
      //	printf("%s %s\n",
      //         (char*) _vars[i]->Name(),varname);
      i++;
    }
  if (i<_num) {
    varnum = i;
    return 1;
      }
  else {
    return 0;
  }
}


//--------------------------------------------------
bool Variables::GetVar(const char* varname, Variable** var)
{
  int i;
  
  i=0;
  while ((i<_num)&&(!_vars[i]->HasName(varname)))
    {
      //	printf("%s %s\n",(char*) _vars[i]->Name(),varname);
      i++;
    }
  if (i<_num) {
    //        printf("GetVar()  %d \n \t",i);
    //    _vars[i]->display();
    //    printf("\n");
    //fflush(stdout);
    *var= _vars[i];
    return 1;
  }
  else {
    return 0;
  }
}

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

//--------------------------------------------------
unsigned char Variables::deleteVar(const char* varname)
{
  int i=0;
  
  fprintf(stderr,"Variables::deleteVar(%s) \n",varname);
  if (ExistVar(varname,i)) {
    return deleteVar(i);
      }
  else {
    fprintf(stderr,"deleteVar(%s) variable not found \n", varname);
    return false;
  }
  
} // Variables::deleteVar()

//--------------------------------------------------
void Variables::display()
{
  int i;
  printf("VARIABLES:\n");
  for(i=0;i<_num;i++) {
    printf(" %2d ",i);
    _vars[i]->display();
    printf("\n");
  }
} // Variables::display()


//--------------------------------------------------
void Variables::EmptyVariables()
{
  int i;

  for(i=0;i<_num;i++) {
    Si (_vars[i]->Type() == type_imagedraw) Alors
      if (_vars[i]->Pointer()!=NULL) {
	_vars[i]->Delete();
	AddFreePosition(i);
      }
    FinSi
  }

  for(i=0;i<_num;i++) {
    if (_vars[i]->Pointer()!=NULL) {
      _vars[i]->Delete();
      AddFreePosition(i);
    }
  }

} // Variables::EmptyVariables()

