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

#include "surface.hpp"
#include "inrimage.hpp"
#include "paramlist.h"

#define HelpAndReturnVarPtr { \
  std::string mess; \
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();\
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); \
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); \
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),\
      wxString::FromAscii("Info"),wxOK | wxICON_QUESTION  );\
  msg->ShowModal();\
  return Variable::ptr(); }

#define HelpAndReturn { \
  std::string mess; \
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();\
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); \
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); \
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),\
      wxString::FromAscii("Info"),wxOK | wxICON_QUESTION  );\
  msg->ShowModal();\
  return; } \

#define HelpAndReturnNULL { \
  std::string mess; \
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();\
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); \
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); \
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),\
      wxString::FromAscii("Info"),wxOK | wxICON_QUESTION  );\
  msg->ShowModal();\
  return NULL; } \


/**
 * Function used to parse a string in a list of parameters
 */
bool get_string_param(string*& arg, ParamList*p, int& num);

/**
 * Function used to parse a float in a list of parameters
 */
bool get_float_param(float& arg, ParamList*p, int& num);

/**
 * Function used to parse a float in a list of parameters
 */
bool get_floatvar_param(float*& arg, ParamList*p, int& num);

/**
 * Function used to parse a 3d vector of float in a list of parameters
 */
bool get_vect3d_float_param(float* arg, ParamList*p, int& num);

/**
 * Function used to parse a 2d vector of float in a list of parameters
 */
bool get_vect2d_float_param(float* arg, ParamList*p, int& num);

/**
 * Function used to parse a 3d vector of int in a list of parameters
 */
bool get_vect3d_int_param(int* arg, ParamList*p, int& num);

/**
 * Function used to parse a 2d vector of int in a list of parameters
 */
bool get_vect2d_int_param(int* arg, ParamList*p, int& num);

/**
 * Function used to parse an integer in a list of parameters
 */
bool get_int_param(int& arg, ParamList*p, int& num);

/**
 * Function used to parse an integer variable in a list of parameters
 */
bool get_intvar_param(int*& arg, ParamList*p, int& num);

/**
 * Function used to parse an image in a list of parameters
 */
bool get_image_param(InrImage*& arg, ParamList*p, int& num);

/**
 * Function used to parse an image in a list of parameters
 */
bool get_optionalimage_param(InrImage*& arg, ParamList*p, int& num);

/**
 * Function used to parse a vectorial image in a list of parameters
 */
bool get_vectimage_param(InrImage*& arg, ParamList*p, int& num);


/**
 * Function used to parse a polydata in a list of parameters
 */
bool get_surface_param(SurfacePoly*& arg, ParamList*p, int& num);

#endif // _WRAPFUNCTIONS_HPP_
