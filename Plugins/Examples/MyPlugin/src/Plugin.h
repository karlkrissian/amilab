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
#include "wrap_Foo_L_int_10_G_.h"
#include "wrap_Foo2_L_int_float_bool_G_.h"

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

