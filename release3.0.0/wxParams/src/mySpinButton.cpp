//
// C++ Implementation: mySpinButton
//
// Description: 
//
//
// Author: Karl Krissian  <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "mySpinButton.h"

BEGIN_EVENT_TABLE(mySpinButton, wxSpinButton)
  EVT_SPIN    (wxID_ANY,  mySpinButton::OnSpinCtrlUpdate)
END_EVENT_TABLE()
