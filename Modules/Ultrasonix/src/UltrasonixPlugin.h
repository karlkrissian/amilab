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

#ifndef _UltrasonixPlugin_h_
#define _UltrasonixPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT UltrasonixPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  UltrasonixPlugin();
};

#endif // _UltrasonixPlugin_h_

