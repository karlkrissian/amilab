
#include "AMILabConfigure.h"

#include "driver.h"
#include "VarContexts.hpp"
#include <wx/config.h>
#include "MainFrame.h"

AMILab_VAR_EXPORT int         GB_argc;
AMILab_VAR_EXPORT wxChar**    GB_argv;
AMILab_VAR_EXPORT int         GB_num_arg_parsed;
AMILab_VAR_EXPORT std::string GB_cmdline;
AMILab_VAR_EXPORT MainFrame*  GB_main_wxFrame;
AMILab_VAR_EXPORT wxApp*      GB_wxApp;
AMILab_VAR_EXPORT wxConfig*   GB_Config;
AMILab_VAR_EXPORT wxString    GB_help_dir;
AMILab_VAR_EXPORT wxString    GB_scripts_dir;
