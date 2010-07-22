/**
 * C++ Interface: wrap_ContinuousMorphology
 *
 * Description: wrapping ContinuousMorphology
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_ContinuousMorphology_h_
#define _wrap_ContinuousMorphology_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "ContinuousMorphology.h"

class WrapClass_ContinuousMorphology: public WrapClassBase
{
  DEFINE_CLASS(WrapClass_ContinuousMorphology);

  protected:
    // for nested classes
    typedef WrapClass_ContinuousMorphology::ptr _parentclass_ptr;
    typedef ContinuousMorphology _obj_type;

  public:
    /// Stores a pointer to an object of type ContinuousMorphology.
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_ContinuousMorphology(boost::shared_ptr<ContinuousMorphology > si):  _obj(si)
    {}

    ADD_CLASS_METHOD(SetScheme,  "Sets the scheme.");
    ADD_CLASS_METHOD(SetLimits,  "Sets the maximum and minimum of the image.");
    ADD_CLASS_METHOD(EDP,        "Partial Derivative Equation.");
    ADD_CLASS_METHOD(Dilate,     "Image morphological greyscale dilatation using Partial Derivative Equation and the scheme of Brockett and Maragos.");
    ADD_CLASS_METHOD(Erode,      "Image morphological greyscale erosion using Partial Derivative Equation and the scheme of Brockett and Maragos.");
    ADD_CLASS_METHOD(Open,       "Image morphological greyscale opening using Partial Derivative Equation and the scheme of Brockett and Maragos.");
    ADD_CLASS_METHOD(Close,      "Image morphological greyscale closing using Partial Derivative Equation and the scheme of Brockett and Maragos.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      AddVar_SetScheme(  this_ptr);
      AddVar_SetLimits(  this_ptr);
      AddVar_EDP(        this_ptr);
      AddVar_Dilate(     this_ptr);
      AddVar_Erode(      this_ptr);
      AddVar_Open(       this_ptr);
      AddVar_Close(      this_ptr);
    };

};

/**
 * Create a Wrapped object around ContinuousMorphology
 * @param objectptr input smart pointer to a WrapClass_ContinuousMorphology
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_ContinuousMorphology(  WrapClass_ContinuousMorphology::ptr& objectptr);

/**
 * Create a Wrapped object around ContinuousMorphology
 * @param si_ptr input smart pointer to a ContinuousMorphology
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_ContinuousMorphology( ContinuousMorphology* si);

/** Method that adds wrapping of ContinuousMorphology
 */
ADD_CLASS_FUNCTION( ContinuousMorphology, "Wrapping of ContinuousMorphology." );

#endif // _wrap_ContinuousMorphology_h