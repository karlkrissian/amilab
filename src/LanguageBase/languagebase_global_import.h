
#ifndef _language_global_import_h_
#define _language_global_import_h_

#include "LanguageBaseConfigure.h"
#include "DriverBase.h"
#include "VarContexts.hpp"

// Should use smart pointers here and point to a initial variable just in case.
LanguageBase_VAR_IMPORT DriverBase::ptr GB_DriverBase;
LanguageBase_VAR_IMPORT VarContexts Vars;

LanguageBase_VAR_IMPORT 
void AddClassMap(std::string classname, BasicVariable::wptr classvar);

LanguageBase_VAR_IMPORT 
BasicVariable::wptr GetClassVar(std::string classname);

#endif // define _language_global_import_h_
