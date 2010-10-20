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
  EVT_SCROLL_CHANGED    ( mySlider::OnSliderChanged)
  EVT_SCROLL_THUMBTRACK ( mySlider::OnThumbTrack)
END_EVENT_TABLE()

