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

#ifndef _ImageProcessingPlugin_h_
#define _ImageProcessingPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT ImageProcessingPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  ImageProcessingPlugin();
};

#endif // _ImageProcessingPlugin_h_

