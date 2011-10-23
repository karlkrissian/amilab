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

#ifndef _OpenGLPlugin_h_
#define _OpenGLPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT OpenGLPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  OpenGLPlugin();
};

#endif // _OpenGLPlugin_h_

