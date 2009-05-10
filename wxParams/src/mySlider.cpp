//
// C++ Implementation: mySlider
//
// Description: 
//
//
// Author: Karl Krissian  <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "mySlider.h"

BEGIN_EVENT_TABLE(mySlider, wxSlider)
  EVT_SCROLL    ( mySlider::OnSliderUpdate)
END_EVENT_TABLE()

