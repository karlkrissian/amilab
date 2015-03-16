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

#ifndef _itkRecGaussPlugin_h_
#define _itkRecGaussPlugin_h_

#include "wxPluginBase.h"

/**
 * @brief Plugin of ExamplePlugin class.
 **/
class WX_AMILAB_EXPORT itkRecGaussPlugin : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  itkRecGaussPlugin();

  ~itkRecGaussPlugin() 
  {
    this->Destroy();
  }
};

#endif // _itkRecGaussPlugin_h_

