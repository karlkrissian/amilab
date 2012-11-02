
#pragma once

#include "wxAmiEventHandler.h"
#include <amiDataViewTreeList.h>
#include <wx/dataview.h>
#ifdef __GCCXML__
  template class wxVector<wxVariant>;
#endif

#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/arrstr.h>
#include <wx/artprov.h> 
#include <wx/aui/aui.h>
#include <wx/combobox.h>
#include <wx/ffile.h>
#include <wx/grid.h>
#include <wx/object.h>
#include <wx/platinfo.h>
#include <wx/regex.h> 
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/tipdlg.h>
#include <wx/utils.h>
#include <wx/variant.h>
#include <wx/collpane.h>
#include <wx/tokenzr.h>
#ifdef __GCCXML__
  // Instanciate for the case it depends on a template
  wxCollapsiblePane p;
#endif
