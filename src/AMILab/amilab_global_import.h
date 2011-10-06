
#pragma once
#ifndef _amilab_global_import_h_
#define _amilab_global_import_h_

#include "AMILabConfigure.h"
#include "MainFrame.h"

AMILab_VAR_IMPORT int         GB_argc;
AMILab_VAR_IMPORT wxChar**    GB_argv;
AMILab_VAR_IMPORT int         GB_num_arg_parsed;
AMILab_VAR_IMPORT std::string GB_cmdline;
AMILab_VAR_IMPORT MainFrame*  GB_main_wxFrame;
AMILab_VAR_IMPORT wxApp*      GB_wxApp;
AMILab_VAR_IMPORT wxConfig*   GB_Config;
AMILab_VAR_IMPORT wxString    GB_help_dir;
AMILab_VAR_IMPORT wxString    GB_scripts_dir;

#endif // define _amilab_global_import_h_
