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

#ifndef PLUGIN_H
#define PLUGIN_H

#include "wxPluginBase.h"
#include "wrap_ExamplePlugin.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT Plugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  Plugin();
};

#endif // PLUGIN_H

