
#include "LanguageBaseConfigure.h"

#include "DriverBase.h"
#include "VarContexts.hpp"

LanguageBase_VAR_EXPORT DriverBase::ptr GB_DriverBase;
LanguageBase_VAR_EXPORT VarContexts Vars;

LanguageBase_EXPORT
void AddClassMap(std::string classname, BasicVariable::wptr classvar) 
{
  Vars.AddClassMap(classname,classvar);
}


LanguageBase_EXPORT 
BasicVariable::wptr GetClassVar(std::string classname)
{ 
  return Vars.GetClassVar(classname);
}
