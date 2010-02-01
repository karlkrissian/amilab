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
//#include "DessinImage.hpp"

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
  return Variable::ptr(); }

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
  return NULL; } \


/**
 * Function returns the number of parameters of the parameters list
 * if the pointer is NULL, returns -1 to allow display the documentation
 */
int get_num_param(ParamList* p);

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a smart pointer to the variable.
 */
template<class T>
bool get_var_param( Variable::ptr& var, 
                    ParamList*p, int& num);

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back its value.
 */
template<class T>
bool get_val_param( T& arg, 
                ParamList*p, int& num);


/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a pointer to its value.
 */
template<class T>
bool get_val_ptr_param( T*& arg, 
                    ParamList*p, int& num, 
                    bool required=false);

/**
 * Function used to parse a variable of generic type in a list of parameters, and to give back a smart pointer to its value.
 */
template<class T>
bool get_val_smtptr_param( boost::shared_ptr<T>& arg, 
                       ParamList*p, int& num, 
                       bool required=false);


/**
 * Function used to parse a several variables of the same generic type in a list of parameters, and to give back the values in the arg parameter which should be of type T[nb].
 */
template<class T, int nb>
bool get_several_params(T* arg, ParamList*p, int& num);

/**
 * Function used to parse an integer in a list of parameters
 */
bool get_int_param(int& arg, ParamList*p, int& num);


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
