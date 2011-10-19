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

#ifndef _NoiseAnalysisPlugin_h_
#define _NoiseAnalysisPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT NoiseAnalysisPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  NoiseAnalysisPlugin();
};

#endif // _NoiseAnalysisPlugin_h_

