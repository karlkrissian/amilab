//
// C++ Interface: wrapAMIFluid
//
// Description:
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrapfunctions.hpp"
#include "DefineClass.hpp"
#include "amilab_messages.h"
//#include "DessinImage.hpp"
#include "Variable.hpp"

#include <string>
//using namespace std;


/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a smart pointer to the variable.
 */
template<class T>
bool get_var_param( boost::shared_ptr<Variable<T> >& var, 
                    ParamList*p, int& num, bool required = false)
{
  if (!p) return false;
  if (num>=p->GetNumParam()) {
    if (required) {
      FILE_ERROR( boost::format("Wrong parameter number for parameter  %1%") % num);
    }
    return false;
  }
  // Getting the Variable and checking its type
  var = boost::dynamic_pointer_cast<Variable<T> >(p->GetParam(num++));
  if (var.get()) {
    if (var->Type()!=GetVarType<T>()) {
      FILE_ERROR(boost::format("Parameter %1% is of wrong type (%2% instead of %3%), you may be passing a value instead of a reference.")%num%var->Type()%GetVarType<T>());
      return false;
    }
    // check that the variable is not just local
    int var_count = var->Pointer().use_count();
    if (var_count<=1) {
      FILE_ERROR(boost::format("Parameter %1% is not passed as a reference ... (%2%)")%num%var->Name());
      return false;
    }

    return true;
  }
  else
  {
    if (required)
      FILE_ERROR(boost::format("Parameter %d not found ") % num);
    return false;
  }

}


/**
 * Function used to parse a variable of generic type and to give back its value.
 */
// template<class T>
// bool get_val(T& arg, BasicVariable::ptr var)
// {
//   if (var.get()) {
//     if (var->Type()!=GetVarType<T>()) {
//       // Try to convert to the requested type:
//       BasicVariable::ptr converted = var->TryCast(AMILabType<T>::name_as_string());
//       if (!converted.get()) {
//         FILE_ERROR(boost::format("Cannot not be converted to type %2%.") % AMILabType<T>::name_as_string());
//         return false;
//       } else
//         var = converted;
//     }
//     boost::shared_ptr<Variable<T> > temp1(
//       boost::dynamic_pointer_cast<Variable<T> >(var));
//     if (temp1.get()) {
//       arg= * (temp1->Pointer().get());
//       return true;
//     } 
//     else
//     {
//       FILE_ERROR(boost::format("Conversion to %1% problem ") % AMILabType<T>::name_as_string());
//       return false;
//     }
//   }
//   else
//   {
//     FILE_ERROR(boost::format("Variable not found "));
//     return false;
//   }
// }

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back its value.
 */
template<class T>
bool get_val_param(T& arg, ParamList*p, int& num, bool required, bool quiet)
{
  if (!p) return false;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    if (required)
      return false;
    else
    {
      if (!quiet) {
        FILE_MESSAGE( boost::format("Using default value for parameter %1%") % num);
      }
      return true;
    }
  }
  BasicVariable::ptr varparam( p->GetParam(num++));
  boost::shared_ptr<T> val_ptr = AMILabType<T>::GetValue(varparam);
  if (!val_ptr.get()) {
    if (!quiet) {
      FILE_ERROR(boost::format("Problem with %1% parameter.") % num);
    }
    return false;
  } else {
    arg = *val_ptr;
  }
  return true;
}

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a pointer to its value.
 */
template<class T>
bool get_val_ptr_param(T*& arg, ParamList*p, int& num, bool required, bool noconstr)
{
  if (!p) return false;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    if (!required) {
      FILE_MESSAGE( boost::format("Using default value for parameter %1%") % num);
      return true;
    } else {
      FILE_MESSAGE( boost::format("Missing required parameter number %1%") % num);
      return false;
    }
  }
  BasicVariable::ptr temp = p->GetParam(num++);
  if (temp.get()) {
    boost::shared_ptr<T> val_ptr = AMILabType<T>::GetValue(temp,noconstr);
    if (!val_ptr.get()) {
      FILE_ERROR(boost::format("Parameter %1% failed.") % num);
      return false;
    }
    arg= val_ptr.get();
    return true;
  }
  else
  {
    FILE_ERROR(boost::format("Parameter %d not found ") % num);
    return false;
  }
}


/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a smart pointer to its value.
 */
template<class T>
bool get_val_smtptr_param(boost::shared_ptr<T>& arg, ParamList*p, int& num, 
                          bool required, bool noconstr, bool quiet)
{
  if (!p) return false;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    if (!required) {
      if (!quiet) {
        FILE_MESSAGE( boost::format("Using default value for parameter %1%") % num);
      }
      return true;
    } else {
      if (!quiet) {
        FILE_MESSAGE( boost::format("Missing required parameter number %1%") % num);
      }
      return false;
    }
  }
  BasicVariable::ptr temp = p->GetParam(num++);
  if (temp.get()) {
    boost::shared_ptr<T> val_ptr = AMILabType<T>::GetValue(temp,noconstr);
    if (!val_ptr.get()) {
      if (!quiet) {
        FILE_ERROR(boost::format("Parameter %1% failed.") % num);
      }
      return false;
    }
    /*
    boost::shared_ptr<Variable<T> > temp1(
      boost::dynamic_pointer_cast<Variable<T> >(temp));
    if (!temp1.get()) {
      FILE_ERROR(boost::format("Parameter %1% is dynamic cast failed.")%num);
      return false;
    }
    */
    arg= boost::shared_ptr<T>(val_ptr);
    return true;
  }
  else
  {
    if (required) {
      if (!quiet) {
        FILE_ERROR(boost::format("Parameter %d not found ") % num);
      }
      return false;
    } else
      return true;
  }
}


/**
 * Returning the wrapped object of the given type and its corresponding variable
 */
template<class T> bool get_obj_param( Variable<AMIObject>::ptr& var, boost::shared_ptr<T>& arg, 
                       ParamList*p, int& num)
{
  bool ok = false; 
  ok = get_var_param<AMIObject>(var, p, num);  
  if (!ok) { 
    num--;
    BasicVariable::ptr genericvar;
    if (get_generic_var_param(genericvar,p,num)) { 
      ParamList::ptr param(new ParamList()); 
      param->AddParam(genericvar); 
      /* Call the constructor */ 
      BasicVariable::ptr constr_res = WrapClass<T>::CreateVar(param.get());
      var = boost::dynamic_pointer_cast<Variable<AMIObject> >(constr_res);
      ok = var.get(); 
    } 
  } 
  if (ok) { 
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    boost::shared_ptr<WrapClass<T> > wc( boost::dynamic_pointer_cast<WrapClass<T> >(object));
    if (wc.get()) {
      arg = wc->GetObj();
    } else {
      FILE_ERROR("Could not cast dynamically the variable.")
    }
  }  else {
    /*FILE_ERROR("Need a wrapped object or compatible variable as parameter.")*/;
  }
  return ok;
}


/**
 * Function used to parse a several variables of the same generic type in a list of parameters, and to give back the values in the arg parameter which should be of type T[nb].
 */
template<class T, int nb>
bool get_several_params(T* arg, ParamList*p, int& num)
{
  if (!p) return false;
  int i;
  bool OK;
  for(i=0;i<nb;i++) {
    OK = get_val_param<T>(arg[i],p,num);
    if (!OK) return false;
  }
  return true;
}



/**
 * Function used to parse a 3d vector of int in a list of parameters
 */
template<int nb>
bool get_several_int_params(int* arg, ParamList*p, int& num)
{
  if (!p) return false;
  int i;
  float val[nb];
  for(i=0;i<nb;i++) 
    val[i] = arg[i];

  bool OK = get_several_params<float,nb>(val,p,num);
  if (!OK) return false;
  for(i=0;i<nb;i++) 
    arg[i] = round(val[i]);

  return true;
}



