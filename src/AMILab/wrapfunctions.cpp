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

#include <string>
using namespace std;

/**
 * Function used to parse a string in a list of parameters
 */
int get_string_param(std::string*& arg, ParamList*p, int& num)
{
  string_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    printf("get_string_param %d \t Using default value \n",num);
    return 1;
  }
  temp = p->GetParamPtr<string>(type_string,num++);
  if (temp.use_count()) {
    arg=temp.get();
    return 1;
  }
  else
  {
    fprintf(stderr, "get_string_param()\t Error in the parameter %d\n",num);
    return 0;
  }
}

/**
 * Function used to parse a float in a list of parameters
 */
int get_float_param(float& arg, ParamList*p, int& num)
{
  float_ptr   temp;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    printf("get_float_param %d \t Using default value \n",num);
    return 1;
  }
  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg=(*temp);
    return 1;
  }
  else
  {
    fprintf(stderr, "get_float_param()\t Error in the parameter %d\n",num);
    return 0;
  }
}

/**
 * Function used to parse a float in a list of parameters
 */
int get_floatvar_param(float*& arg, ParamList*p, int& num)
{
  float_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    printf("get_float_param %d \t Using default value \n",num);
    return 1;
  }
  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg=temp.get();
    return 1;
  }
  else
  {
    fprintf(stderr, "get_floatvar_param()\t Error in the parameter %d\n",num);
    return 0;
  }
}

/**
 * Function used to parse a 3d vector of float in a list of parameters
 */
int get_vect3d_float_param(float* arg, ParamList*p, int& num)
{
  float_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num+2>=p->GetNumParam()) {
    printf("get_vect3d_float_param %d \t Using default value \n",num);
    return 1;
  }

  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg[0]=*temp;
    temp = p->GetParamPtr<float>(type_float,num++);
    if (temp.use_count()) {
      arg[1]=*temp;
      temp = p->GetParamPtr<float>(type_float,num++);
      if (temp.use_count()) {
        arg[2]=*temp;
      }
    }
  }

  if (!temp.use_count())
  {
    fprintf(stderr, "get_float_param()\t Error in the parameter %d\n",num-1);
    return 0;
  }
  return 1;
}

/**
 * Function used to parse a 2d vector of float in a list of parameters
 */
int get_vect2d_float_param(float* arg, ParamList*p, int& num)
{
  float_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num+1>=p->GetNumParam()) {
    printf("get_vect2d_float_param %d \t Using default value \n",num);
    return 1;
  }

  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg[0]=(*temp);
    temp = p->GetParamPtr<float>(type_float,num++);
    if (temp.use_count()) {
      arg[1]=(*temp);
    }
  }

  if (!temp.use_count())
  {
    fprintf(stderr, "get_vect2d_float_param()\t Error in the parameter %d\n",num-1);
    return 0;
  }
  return 1;
}

/**
 * Function used to parse a 3d vector of int in a list of parameters
 */
int get_vect3d_int_param(int* arg, ParamList*p, int& num)
{
  float_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num+2>=p->GetNumParam()) {
    printf("get_vect3d_int_param %d \t Using default value \n",num);
    return 1;
  }

  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg[0]=(int)*temp;
    temp = p->GetParamPtr<float>(type_float,num++);
    if (temp.use_count()) {
      arg[1]=(int)*temp;
      temp = p->GetParamPtr<float>(type_float,num++);
      if (temp.use_count())
        arg[2]=(int)*temp;
    }
  }

  if (temp==NULL)
  {
    fprintf(stderr, "get_float_param()\t Error in the parameter %d\n",num-1);
    return 0;
  }
  return 1;
}

/**
 * Function used to parse a 2d vector of int in a list of parameters
 */
int get_vect2d_int_param(int* arg, ParamList*p, int& num)
{
  float_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num+1>=p->GetNumParam()) {
    printf("get_vect2d_int_param %d \t Using default value \n",num);
    return 1;
  }

  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg[0]=(int) *temp;
    temp = p->GetParamPtr<float>(type_float,num++);
    if (temp.use_count()) {
      arg[1]=(int) *temp;
    }
  }

  if (temp==NULL)
  {
    fprintf(stderr, "get_vect2d_int_param()\t Error in the parameter %d\n",num-1);
    return 0;
  }
  return 1;
}

/**
 * Function used to parse an integer in a list of parameters
 */
int get_int_param(int& arg, ParamList*p, int& num)
{
  float_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    printf("get_int_param %d \t Using default value \n",num);
    return 1;
  }
  temp = p->GetParamPtr<float>(type_float,num++);
  if (temp.use_count()) {
    arg=(int) (*temp);
//    printf("get_int_param() \t %f %d \n",*temp,arg);
    return 1;
  }
  else
  {
    fprintf(stderr, "get_int_param()\t Error in the parameter %d\n",num);
    return 0;
  }
}


/**
 * Function used to parse a integer variable in a list of parameters
 */
int get_intvar_param(int*& arg, ParamList*p, int& num)
{
  int_ptr    temp;
  // if the parameter number is too high, skip it (use default value)
  if (num>=p->GetNumParam()) {
    printf("get_intvar_param %d \t variable not available \n",num);
    return 0;
  }
  temp = p->GetParamPtr<int>(type_int,num++);
  if (temp.use_count()) {
    arg=temp.get();
    return 1;
  }
  else
  {
    fprintf(stderr, "get_intvar_param()\t Error in the parameter %d\n",num);
    return 0;
  }
}




/**
 * Function used to parse an image in a list of parameters
 */
int get_optionalimage_param(InrImage*& arg, ParamList*p, int& num)
{
  InrImage::ptr    temp;
  if (num>=p->GetNumParam()) {
    return 1; // using default parameter
  }
  temp = p->GetParamPtr<InrImage>(type_image,num++);
  if (temp.use_count()) {
    arg=temp.get();
    return 1;
  }
  else
  {
    fprintf(stderr, "get_optionalimage_param ()\t Error in the parameter %d\n",num);
    return 0;
  }
}

/**
 * Function used to parse an image in a list of parameters
 */
int get_image_param(InrImage*& arg, ParamList*p, int& num)
{
  InrImage::ptr    temp;
  temp = p->GetParamPtr<InrImage>(type_image,num++);
  if (temp.use_count()) {
    arg=temp.get();
    return 1;
  }
  else
  {
    fprintf(stderr, "get_image_param ()\t Error in the parameter %d\n",num);
    return 0;
  }
}


/**
 * Function used to parse a vectorial image in a list of parameters
 */
int get_vectimage_param(InrImage*& arg, ParamList*p, int& num)
{

printf("get_vectimage_param begin\n");
  InrImage::ptr    temp;
  temp = p->GetParamPtr<InrImage>(type_image,num++);
  if (temp.use_count()) {
    if (!temp->VectorialFormat()) {
      fprintf(stderr,"get_image_param()\t  param %d must be a vectorial image.\n",num);
      return 0;
    } else {
      arg=temp.get();
printf("get_vectimage_param ok\n");
      return 1;
    }
  }
  else
  {
    fprintf(stderr, "get_image_param ()\t Error in the parameter %d\n",num);
    return 0;
  }
}


/**
 * Function used to parse a polydata in a list of parameters
 */
int get_surface_param(SurfacePoly*& arg, ParamList*p, int& num)
{
  SurfacePoly::ptr    temp;
  temp = p->GetParamPtr<SurfacePoly>(type_surface,num++);
  if (temp.use_count()) {
    arg=temp.get();
    return 1;
  }
  else
  {
    fprintf(stderr, "get_surface_param ()\t Error in the parameter %d\n",num);
    return 0;
  }
}
