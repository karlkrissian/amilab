
#pragma once
#ifndef _DownloadData_include_h_
#define _DownloadData_include_h_

#include <memory>

#include <wx/archive.h>
#include <wx/filedlg.h>
#include <wx/mstream.h>
#include <wx/sstream.h>
#include <wx/stream.h>
#include <wx/textfile.h>
#include <wx/url.h>
#include <wx/wfstream.h>

wxFFileInputStream* ptr;
std::auto_ptr<wxFFileInputStream> auto_ptr_wxFFileInputStream_obj(ptr);

#endif // _DownloadData_include_h_
