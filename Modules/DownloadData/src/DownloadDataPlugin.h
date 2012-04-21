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

#ifndef _DownloadDataPlugin_h_
#define _DownloadDataPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT DownloadDataPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  DownloadDataPlugin();
  
  ~DownloadDataPlugin() 
  {
    this->Destroy();
  }
};

#endif // _DownloadDataPlugin_h_

