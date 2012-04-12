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

#ifndef _PDIModule2Plugin_h_
#define _PDIModule2Plugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT PDIModule2Plugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  PDIModule2Plugin();
};

#endif // _PDIModule2Plugin_h_

