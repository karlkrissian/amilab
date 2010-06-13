//
// C++ Interface: wrap_FenetreDessin
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_FenetreDessin_h_
#define _wrap_FenetreDessin_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxWindow.h"

#include "FenetreDessin.hpp"

class WrapClass_FenetreDessin : public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_FenetreDessin);

  // for nested classes
  typedef WrapClass_FenetreDessin::ptr _parentclass_ptr;
  typedef FenetreDessin _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_FenetreDessin(boost::shared_ptr<FenetreDessin> si):  WrapClass_wxWindow(si), _obj(si)
    {}

    ADD_CLASS_METHOD(DrawingAreaDisplay, "Updates the display of the Drawing Area.");
    ADD_CLASS_METHOD(SetPenColor,        "Sets the color of the drawing pen.");
    ADD_CLASS_METHOD(SetLineParameters,  "Sets the parameters of the line.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_DrawingAreaDisplay(         this_ptr);
      AddVar_SetPenColor(                this_ptr);
      AddVar_SetLineParameters(          this_ptr);
    }

};


/**
 * Create a Wrapped object around FenetreDessin
 * @param objectptr input smart pointer to a WrapClass_FenetreDessin
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_FenetreDessin(  WrapClass_FenetreDessin::ptr& objectptr);

/**
 * Create a Wrapped object around FenetreDessin
 * @param si_ptr input smart pointer to a FenetreDessin
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_FenetreDessin( FenetreDessin* si);

/** Method that adds wrapping of FenetreDessin 
 */
ADD_CLASS_FUNCTION( FenetreDessin, "Wrapping of FenetreDessin." );

#endif // _wrap_FenetreDessin_h_
