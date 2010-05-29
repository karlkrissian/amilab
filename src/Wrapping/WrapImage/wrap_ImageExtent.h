/**
 * C++ Interface: wrap_ImageExtent
 *
 * Description: wrapping ImageExtent\<float\>
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_ImageExtent_h_
#define _wrap_ImageExtent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "imageextent.h"

class WrapClass_ImageExtent : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_ImageExtent);

  // for nested classes
  typedef WrapClass_ImageExtent::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<ImageExtent<float> > _obj;

    /// Constructor
    WrapClass_ImageExtent(boost::shared_ptr<ImageExtent<float> > si): _obj(si)
    {}

    ADD_CLASS_METHOD(Xmin,    "Minimal position in X.");
    ADD_CLASS_METHOD(Xmax,    "Maximal position in X.");
    ADD_CLASS_METHOD(Ymin,    "Minimal position in Y.");
    ADD_CLASS_METHOD(Ymax,    "Maximal position in Y.");
    ADD_CLASS_METHOD(Zmin,    "Minimal position in Z.");
    ADD_CLASS_METHOD(Zmax,    "Maximal position in Z.");

    ADD_CLASS_METHOD(SetXmin, "Sets the minimal position in X.");
    ADD_CLASS_METHOD(SetXmax, "Sets the maximal position in X.");
    ADD_CLASS_METHOD(SetYmin, "Sets the minimal position in Y.");
    ADD_CLASS_METHOD(SetYmax, "Sets the maximal position in Y.");
    ADD_CLASS_METHOD(SetZmin, "Sets the minimal position in Z.");
    ADD_CLASS_METHOD(SetZmax, "Sets the maximal position in Z.");

    ADD_CLASS_METHOD(print, "Outputs the limits to the standard output.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      AddVar_Xmin( this_ptr);
      AddVar_Xmax( this_ptr);
      AddVar_Ymin( this_ptr);
      AddVar_Ymax( this_ptr);
      AddVar_Zmin( this_ptr);
      AddVar_Zmax( this_ptr);

      AddVar_SetXmin( this_ptr);
      AddVar_SetXmax( this_ptr);
      AddVar_SetYmin( this_ptr);
      AddVar_SetYmax( this_ptr);
      AddVar_SetZmin( this_ptr);
      AddVar_SetZmax( this_ptr);

      AddVar_print(   this_ptr, "_print"); // avoid pb with token 'print'
    }
};

/**
 * Create a Wrapped object around _ImageExtent
 * @param objectptr input smart pointer to a WrapClass_ImageExtent
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_ImageExtent(  WrapClass_ImageExtent::ptr& objectptr);

/**
 * Create a Wrapped object around _ImageExtent
 * @param si_ptr input smart pointer to a _ImageExtent
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_ImageExtent( ImageExtent<float>* si);

/** Method that adds wrapping of ImageExtent 
 */
ADD_CLASS_FUNCTION( ImageExtent, "Wrapping of ImageExtent<float>." );


#endif // _wrap_ImageExtent_h_
