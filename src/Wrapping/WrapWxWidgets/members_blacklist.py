
members_blacklist=[
  'wxCreateObject',
  #'wxCmdLineParser::wxCmdLineParser(wxCmdLineEntryDesc const*, int, wchar_t**)', # idem
  #'wxCmdLineParser::wxCmdLineParser(int, wchar_t**)', # idem
  #'wxWindowBase::GetToolTipText', # not implemented ...
  #'wxStringBase::copy',
  #'wxString::FormatV', 
  #'wxString::PrintfV', 
  'wxString::tchar_str', # not sure why it's failing: no matching function call ... 
  #'wxFont::Unshare', 
  #'wxStatusBar::SetBorderX', # not implemented ... 
  #'wxStatusBar::SetBorderY', # not implemented ...
  #'wxMenuBase::New',
  #'wxMenuItem::GetFactoryPath',
  #'wxMenuItemBase::GetAccelFromString',
  'wxColour::GetPixel', # problem with COLOREF on mac which is unsigned char[6]
  'wxColour::FromRGBColor', # pb with COLORREF
  'wxColour::m_pixel', # idem
  #'wxConfigBase::Read(wxString const&, wchar_t const*) const', # version 2.9.3: pb with wxFromString(...)
  #'wxConfigBase::Write(wxString const&, unsigned char const*)', # idem
  #'wxConfigBase::Write(wxString const&, wchar_t const*)', # idem
  #'wxAuiNotebook::InsertPage(unsigned long, wxWindow*, wxString const&, bool, wxBitmap const&)', # wx 2.9.3 ambiguity due to default param values
  #'wxAuiNotebook::InsertPage(unsigned long, wxWindow*, wxString const&, bool, int)', # ambiguity 
  'wxCursor::GetHCURSOR',           # linking pb on macros
  #'wxDateTime::IsGregorianDate',    # no implemented
  'wxToolBar::OnMouse',             # idem, MacOS linking error
  'wxStatusBarGeneric::SetBorderX', # idem, MacOS linking error
  'wxStatusBarGeneric::SetBorderY', # idem, MacOS linking error
  'wxArrayString::resize',          # no defined
  #'wxMenuBar::Create',              # idem
  'wxButtonBase::GetDefaultSize',   # idem, MacOS linking
  'wxIcon::SetOk',                  # idem
  'wxWindow::FindItem',             # idem, MacOS error
  'wxPoint2DDouble::SetPolarCoordinates', # idem
  'wxPoint2DInt::SetPolarCoordinates', # idem
  'wxGenericListCtrl::Update(long)', # linking problem, don't know why ...
  'wxBitmap::GetSelectedInto', # not included in windows in release mode
  'wxBitmap::SetSelectedInto', # not included in windows in release mode
  'wxWindow::HandleQueryDragIcon',  # not include in windows link error
  'wxWindowBase::GetAdjustedMinSize', # probably not implemented in wx 3.0.2
  'wxWindowList::front', # returning reference to pointer
  'wxListCtrl::ConvertToMSWStyle', # linking problem MacOS
  'wxListCtrl::ChangeCurrent',     # idem
  'wxListCtrl::ResetCurrent',      # idem
  'wxStyledTextCtrl::wxCreateObject', # bug in wxwidgets? declared with DECLARE_DYNAMIC_CLASS and implemented with IMPLEMENT_CLASS?
  'tchar_str', # this method gives problems with wxWidgets
  'wxDataViewCtrlBase::wxCreateObject',
  'wxURI::wxCreateObject', # bug in wxwidgets? declared with DECLARE_DYNAMIC_CLASS and implemented with IMPLEMENT_CLASS?
  # undefined methods at linking ...
  'wxMenuItemBase::GetAccelFromString',
  'wxButton::GTKPressed',
  'wxMenuBase::New',
  'wxButton::GTKMouseLeaves',
  'wxGenericListCtrl::Update',
  #'wxDC::DrawPolygon',
  'wxFont::Unshare',
  'wxButton::GTKReleased',
  'wxButton::GTKMouseEnters',
  #'wxDC::DrawLines',
  'wxWindowBase::GetAdjustedMinSize',
  'MacCreateUIFont',               #Mac problem
  'MacGetCTFont',                  #idem
  'wxApp::Initialize',               # double pointer pb
  'wxApp::InitialzeVisual',          # not implemented, static function
  'wxApp::InitRichEdit',             # not implemented, static function
  'wxAppBase::Initialize',           # double pointer pb
  'wxAppConsole::Initialize',        # double pointer pb
  'wxAppConsole::OnAssertFailure',   # error in windows, not a member
  'wxAppConsole::OnAssert',          # error in windows, not a member
  #'wxButton::GTKMouseEnters',    # not define with wx 2.9.2
  #'wxButton::GTKMouseLeaves',    # not define with wx 2.9.2
  #'wxButton::GTKPressed',        # not define with wx 2.9.2
  #'wxButton::GTKReleased',       # not define with wx 2.9.2
  'wxAppConsoleBase::HandleEvent', # *func ? type not recognized probably
]
