
# global dictionary of argument types
types      = dict()
classes    = dict()
variables  = dict()
enumvalues = dict()
files      = dict()

classes_blacklist=[
  'wxHtmlWindowMouseHelper', # pb: no public constructor, destructor: can't be used with boost smart pointers
  ]

# ignore specific members
members_blacklist=['wxCreateObject','wxRect::Inside',\
  'wxString::Strip', 'wxString::CompareTo',\
  'wxAuiManager::SetFrame', 'wxAuiManager::GetFrame',\
  'wxWindowBase::GetBestFittingSize', 'wxWindowBase::SetBestFittingSize', 'wxWindowBase::GetAdjustedMinSize', 'wxWindowBase::GetToolTipText', \
  'wxStringBase::copy',\
  'wxString::FormatV', \
  'wxString::PrintfV', \
  'wxWindow::ScrollDirFromOrient','wxWindow::OrientFromScrollDir',\
  'wxSizerItem::SetOption','wxSizerItem::GetOption', \
  'wxSizer::Remove(wxWindow*)',\
  'wxBitmapButtonBase::SetLabel(const wxBitmap&)',\
  'wxWindowBase::Navigate', # missing IsForward (enum) deal with enums ...
  'wxWindowBase::GetHelpTextAtPoint', 
  'wxFont::Unshare', 
  'wxControlBase::GetLabelText', # problem with static and non-static methods
  'wxStatusBar::SetBorderX', 'wxStatusBar::SetBorderY',
  'wxMenuBase::New',
  'wxMenuItem::GetFactoryPath',
  'wxMenuItemBase::GetAccelFromString',
  'wxColour::GetPixel', # problem with COLOREF on mac which is unsigned char[6]
  'wxColour::FromRGBColor', # pb with COLORREF
  'wxColour::m_pixel', # idem
  'wxCursor::GetHCURSOR',           # linking pb on macros
  'wxDateTime::IsGregorianDate',    # idem
  'wxToolBar::OnMouse',             # idem
  'wxStatusBarGeneric::SetBorderX', # idem
  'wxStatusBarGeneric::SetBorderY', # idem
  'wxArrayString::resize',          # idem
  'wxMenuBar::Create',              # idem
  'wxButtonBase::GetDefaultSize',   # idem
  'wxIcon::SetOk',                  # idem
  'wxWindow::FindItem',             # idem
  'wxPoint2DDouble::SetPolarCoordinates', # idem
  'wxPoint2DInt::SetPolarCoordinates', # idem
  'wxGenericListCtrl::Update(long)', # linking problem, don't know why ...
  'wxBitmap::GetSelectedInto', # not included in windows in release mode
  'wxBitmap::SetSelectedInto', # not included in windows in release mode
  'InternalTransformDerivative', # VTK: pointer to array ...
  'vtkPolyData::GetPointCells', # reference to pointer as parameter
  'vtkPolyData::GetCellPoints', # idem
  ]


class_types = ['Class','Struct']

# amilab available_types
available_classes=[]
parsed_classes=[]
wrapped_classes=[]
incomplete_classes=[]
new_needed_classes=[]

# available builtin type
available_types       = ['int','float','double','unsigned char','long','long int','std::string','bool','void', 'AMIFunction', 'InrImage']

# not used
#available_pointertypes= ['int','float','double','unsigned char','long','long int','std::string','bool']

available_operators={ \
  '!=':'__not_equal__', \
  '==':'__equal__', \
  '[]':'__at__', \
  '=':'__assign__',\
  '-=':'__sub_assign__', \
  '+=':'__add_assign__', \
  '+':'__add__', \
  '-':'__substract__'
  }

include_list = []
declare_list = []

#------------------------------------------------------------------
#  AddInclude
#------------------------------------------------------------------
def AddInclude(f):
  if not(f in include_list):
    include_list.append(f)

#------------------------------------------------------------------
#  AddDeclare
#------------------------------------------------------------------
def AddDeclare(f):
  if not(f in declare_list):
    declare_list.append(f)

#------------------------------------------------------------------
#  CreateIncludes
#------------------------------------------------------------------
def CreateIncludes():
  res='';
  for f in include_list:
    res += '#include "{0}"\n'.format(f)
  
  for f in declare_list:
    # avoid inclusion, just declare the type ...
    res += '#ifndef {0}_declared\n'.format(f)
    res += '  #define {0}_declared\n'.format(f)
    res += '  AMI_DECLARE_TYPE({0})\n'.format(f)
    res += '#endif\n'.format(f)
  return res
