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

#ifndef _amiOpenCVPlugin_h_
#define _amiOpenCVPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT amiOpenCVPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  amiOpenCVPlugin();

  ~amiOpenCVPlugin() 
  {
    this->Destroy();
  }
};

#endif // _amiOpenCVPlugin_h_

