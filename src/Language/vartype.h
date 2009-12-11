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


//! types of variables
typedef enum {
  type_void,    /**< no type */
  type_image,   /**< image */
  type_float,   /**< floating point number */
  type_int,     /**< integer number*/
  type_uchar,   /**< unsigned char number */
  type_string,  /**< string */
  type_imagedraw,
  type_surface,
  type_surfdraw,
  type_file,
  type_c_procedure,
  type_c_image_function,
  type_c_function,
  type_ami_function,
  type_ami_class,
  type_ami_object,
  type_paramwin,
  type_parampanel,
  type_matrix,
  type_gltransform,
  type_array,
  type_context
} vartype; //! types of variables
 
