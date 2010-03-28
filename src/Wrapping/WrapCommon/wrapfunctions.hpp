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

#ifndef _WRAPFUNCTIONS_HPP_
#define _WRAPFUNCTIONS_HPP_


#include <wx/msgdlg.h>
#include "inrimage.hpp"
#include "paramlist.h"
#include <boost/shared_ptr.hpp>
#include "Variable.hpp"
//#include "DessinImage.hpp"

/// Specialization for C_wrap_varfunction
template<>
class CreateSmartPointer<C_wrap_varfunction>
{
  public:
  boost::shared_ptr<C_wrap_varfunction> operator() (C_wrap_varfunction* p) 
  {
    return boost::shared_ptr<C_wrap_varfunction>
            (p,smartpointer_nodeleter<C_wrap_varfunction>());
  }
};

/// Specialization for C_wrap_procedure
template<>
class CreateSmartPointer<C_wrap_procedure>
{
  public:
  boost::shared_ptr<C_wrap_procedure> operator() (C_wrap_procedure* p) 
  {
    return boost::shared_ptr<C_wrap_procedure>(p,
                  smartpointer_nodeleter<C_wrap_procedure>());
  }
};

/// Specialization for C_wrap_imagefunction
template<>
class CreateSmartPointer<C_wrap_imagefunction>
{
  public:
  boost::shared_ptr<C_wrap_imagefunction> operator() (C_wrap_imagefunction* p) 
  {
    return boost::shared_ptr<C_wrap_imagefunction>(p,
              smartpointer_nodeleter<C_wrap_imagefunction>());
  }
};


/*! \def ADDVAR
    \brief Add a C procedure variable with the given procedure
*/
#define ADDVAR(type,proc) \
  { \
  boost::shared_ptr<type> newvar(CreateSmartPointer<type>()(&proc)); \
  Vars.AddVar<type>( #proc, newvar); \
  }

/*! \def ADDVAR_NAME
    \brief Add a C procedure variable with the given name
*/
#define ADDVAR_NAME(type,stname,name) \
  { \
  boost::shared_ptr<type> newvar(CreateSmartPointer<type>()(&name)); \
  Vars.AddVar<type>( stname, newvar); \
  }

/*! \def ADDOBJECTVAR
    \brief Adds a variable of a given type with the given variable name to the current object context.
*/
#define ADDOBJECTVAR(type,obj) \
  { \
  boost::shared_ptr<type> newvar(CreateSmartPointer<type>()(&obj)); \
  Vars.AddVar<type>( #obj, newvar, OBJECT_CONTEXT_NUMBER); \
  }


/*! \def ADDOBJECTVAR_NAME
    \brief Add a C procedure variable with the given name to the current object context.
*/
// C_wrap_procedure
#define ADDOBJECTVAR_NAME(type,stname,name) \
  { \
  boost::shared_ptr<type> newvar(CreateSmartPointer<type>()(&name)); \
  Vars.AddVar<type>( stname, newvar, OBJECT_CONTEXT_NUMBER); \
  }


/*! \def ADDLOCAL_OBJECTVAR_NAME
    \brief Add a C procedure variable with the given name to the context of the given amiobject.
*/
// C_wrap_procedure
#define ADDLOCAL_OBJECTVAR_NAME(obj,type,stname,name) \
  { \
  boost::shared_ptr<type> newvar(CreateSmartPointer<type>()(&name)); \
  obj->GetContext()->AddVar<type>( stname, newvar); \
  }


/*! \def HelpAndReturnVarPtr
    \brief Shows help and return an empty smart pointer to a Variable
*/
#define HelpAndReturnVarPtr { \
  std::string mess; \
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();\
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); \
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); \
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),\
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION );\
  msg->ShowModal();\
  msg->Destroy();\
  return BasicVariable::ptr(); }

/*! \def HelpAndReturn
    \brief Shows help and returns
*/
#define HelpAndReturn { \
  std::string mess; \
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();\
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); \
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); \
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),\
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION  );\
  msg->ShowModal();\
  msg->Destroy();\
  return; } \




/*! \def HelpAndReturnNULL
    \brief Shows help and returns NULL pointer
*/
#define HelpAndReturnNULL { \
  std::string mess; \
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();\
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); \
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); \
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),\
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION  );\
  msg->ShowModal();\
  msg->Destroy();\
  return NULL; } \


/*! \def RETURN_VAR
    \brief returns a variable of the given type, after creating a new smart pointer to the given value
*/
#define RETURN_VAR(type,val)             \
  boost::shared_ptr<type> var(new type(val));\
  Variable<type>::ptr varres( new Variable<type>(var));\
  return varres;


/**
 * Function returns the number of parameters of the parameters list
 * if the pointer is NULL, returns -1 to allow display the documentation
 */
int get_num_param(ParamList* p);

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a smart pointer to the variable.
 */
bool get_generic_var_param( BasicVariable::ptr& var, ParamList*p, int& num);

/**
 * Function used to parse a variable of specified type in a list of parameters, and to give back a smart pointer to the variable.
 */
template<class T>
bool get_var_param( BasicVariable::ptr& var, 
                    ParamList*p, int& num, bool required = true);

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back its value.
 */
template<class T>
bool get_val_param( T& arg, 
                ParamList*p, int& num);


/**
 *  Function used to parse a variable of generic type in a list of parameters, and to give back a pointer to its value.
 * @param arg returned argument as a pointer to the type
 * @param p list of parameters
 * @param num integer variable containing the argument number, it is incremented by one
 * @param required  default is true
 * @return true/false for success/failure
 */
template<class T>
bool get_val_ptr_param( T*& arg, 
                    ParamList*p, int& num, 
                    bool required=true);


/**
 *  Function used to parse a variable of generic type in a list of parameters, and to give back a smart pointer to its value.
 * @param arg returned argument as a smart pointer to the type
 * @param p list of parameters
 * @param num integer variable containing the argument number, it is incremented by one
 * @param required  default is true
 * @return true/false for success/failure
 */
template<class T> bool get_val_smtptr_param( boost::shared_ptr<T>& arg, 
                       ParamList*p, int& num, 
                       bool required=true);


/**
 * Function used to parse a several variables of the same generic type in a list of parameters, and to give back the values in the arg parameter which should be of type T[nb].
 */
template<class T, int nb>
bool get_several_params(T* arg, ParamList*p, int& num);

/**
 * Function used to parse an integer in a list of parameters
 */
bool get_int_param(int& arg, ParamList*p, int& num, bool required = true);


/**
 * Function used to parse an array of integers each as a separated parameter
 */
template<int nb>
bool get_several_int_params(int* arg, ParamList*p, int& num);


/**
 * Function used to parse a vectorial image in a list of parameters
 */
bool get_vectimage_param(InrImage*& arg, ParamList*p, int& num);

#include "wrapfunctions.tpp"


#endif // _WRAPFUNCTIONS_HPP_
