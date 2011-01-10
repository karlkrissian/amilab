//
// C++ Interface: wxMediaCtrlPlugin
//
// Description:  A plugin that wrapper the wxMediaCtrl class of wxWidgets 2.8
//               version and adds it in AMILAB.
//
//
// Author: xXx <xXX>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef WXMEDIACTRLPLUGIN_H
#define WXMEDIACTRLPLUGIN_H

#include "wxPluginBase.h"
#include "AMILabConfig.h"
#include "wrap_wxMediaCtrl.h"

/**
 * @brief Class that contains a plugins that wrapper the wxMediaCtrl class.
 **/
class WX_AMILAB_EXPORT wxMediaCtrlPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  wxMediaCtrlPlugin();
};

#endif // WXMEDIACTRLPLUGIN_H
