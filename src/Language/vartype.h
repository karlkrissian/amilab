//
// C++ Interface: vartype
//
// Description: 
//
//
// Author:  <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _vartype_h_
#define _vartype_h_

//! types of variables
typedef enum {
  type_void,             /**< no type */
  type_image,            /**< image */
  type_float,            /**< floating point number */
  type_int,              /**< integer number*/
  type_uchar,            /**< unsigned char number */
  type_string,           /**< string */
  type_imagedraw,        /**< image drawing window */
  type_surface,          /**< polydata structure, surface and/or lines */
  type_surfdraw,         /**< polydata drawing window */
  type_file,             /**< file */
  type_c_procedure,      /**< C wrapped procedure */
  type_class_member,  /**< wrapped C++ class procedure member */
  type_c_image_function, /**< C wrapped function that returns an image */
  type_c_function,       /**< C wrapped function that returns a variable */
  type_ami_function,     /**< AMI Language function */
  type_ami_class,        /**< AMI Language class */
  type_ami_object,       /**< AMI Language object (instance of a class, or namespace) */
  type_ami_cpp_object,   /**< AMI Language C++ object (instance of a class, or namespace) */
  type_paramwin,         /**< Parameter window */
  type_matrix,           /**< matrix */
  type_gltransform,      /**< OpenGL transformation */
  type_array,            /**< Array */
} vartype; //! types of variables
 

#endif 
// _vartype_h_
