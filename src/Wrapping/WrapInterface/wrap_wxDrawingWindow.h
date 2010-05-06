//
// C++ Interface: wrap_wxDrawingWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxDrawingWindow_h_
#define _wrap_wxDrawingWindow_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>
#include "wrap_wxWindow.h"
#include "wxDrawingWindow.h"


class WrapClass_wxDrawingWindow : public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxDrawingWindow);

  // for nested classes
  typedef WrapClass_wxDrawingWindow::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxDrawingWindow> _drawingwin;

    /// Constructor
    WrapClass_wxDrawingWindow(boost::shared_ptr<wxDrawingWindow> w): WrapClass_wxWindow(w), _drawingwin(w)
    {}


    ADD_CLASS_METHOD(SetXLimits,         "Sets the limits along X axis.");
    ADD_CLASS_METHOD(SetYLimits,         "Sets the limits along Y axis.");
    ADD_CLASS_METHOD(SetCurve,           "Sets the curve to draw in the Main Frame based on the first line of the given image.");
    ADD_CLASS_METHOD(SetCurveProperties, "Sets the properties of the displayed curve: color, style, width.");

};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_wxDrawingWindow( ParamList* p);


#endif // _wrap_wxDrawingWindow_h_
