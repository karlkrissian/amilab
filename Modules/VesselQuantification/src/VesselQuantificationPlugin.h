//
// C++ File: Plugin.h
//
// Description:  A plugin example.
//
//
// Author: xXx <xXx@xXx.com>, (C) YYYY
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef _VesselQuantificationPlugin_h_
#define _VesselQuantificationPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT VesselQuantificationPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  VesselQuantificationPlugin();

  ~VesselQuantificationPlugin() 
  {
    this->Destroy();
  }
};

#endif // _VesselQuantificationPlugin_h_

