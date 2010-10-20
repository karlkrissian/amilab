//
// C++ Implementation: mySpinCtrl
//
// Description: 
//
//
// Author: Karl Krissian  <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "mySpinCtrl.h"

BEGIN_EVENT_TABLE(mySpinCtrl, wxSpinCtrl)
  EVT_SPINCTRL    (wxID_ANY,  mySpinCtrl::OnSpinCtrlUpdate)
END_EVENT_TABLE()
