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

#ifndef _ITKFiltersPlugin_h_
#define _ITKFiltersPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT ITKFiltersPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  ITKFiltersPlugin();
};

#endif // _ITKFiltersPlugin_h_

