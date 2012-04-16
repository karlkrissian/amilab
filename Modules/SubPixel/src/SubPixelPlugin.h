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

#ifndef _SubPixelPlugin_h_
#define _SubPixelPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT SubPixelPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  SubPixelPlugin();

  ~SubPixelPlugin() 
  {
    this->Destroy();
  }
};

#endif // _SubPixelPlugin_h_

