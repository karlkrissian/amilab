
import wrap_class
import re
import sys
import string

# global dictionary of argument types
types      = dict()
classes    = dict()
typedefs   = dict()
variables  = dict()
enumvalues = dict()
files      = dict()


classes_blacklist=[
  'wxHtmlWindowMouseHelper', # pb: no public constructor, destructor: can't be used with boost smart pointers
  ]

# ignore specific members
members_blacklist=[
  'wxCreateObject',
  #'wxRect::Inside',
  #'wxString::Strip', 
  #'wxString::CompareTo',
  #'wxAuiManager::SetFrame', deprecated
  #'wxAuiManager::GetFrame', deprecated
  #'wxWindowBase::GetHelpTextAtPoint', 
  'wxCmdLineParser::SetCmdLine(int, wchar_t**)', # pb with wchar_t** ...
  'wxCmdLineParser::wxCmdLineParser(wxCmdLineEntryDesc const*, int, wchar_t**)', # idem
  'wxCmdLineParser::wxCmdLineParser(int, wchar_t**)', # idem
  'wxWindowBase::GetToolTipText', # not implemented ...
  'wxStringBase::copy',
#  'wxFileName::GetHumanReadableSize', #invalid cast
  'wxString::FormatV', 
  'wxString::PrintfV', 
  #'wxString::mb_str', # default const reference to abstract class 
  #'wxWindow::ScrollDirFromOrient',
  #'wxWindow::OrientFromScrollDir',
  #'wxSizerItem::SetOption',
  #'wxSizerItem::GetOption', 
  #'wxSizer::Remove(wxWindow*)',
  #'wxBitmapButtonBase::SetLabel(const wxBitmap&)',
  'wxFont::Unshare', 
  #'wxControlBase::GetLabelText', # problem with static and non-static methods
  'wxStatusBar::SetBorderX', # not implemented ... 
  'wxStatusBar::SetBorderY', # not implemented ...
  'wxMenuBase::New',
  'wxMenuItem::GetFactoryPath',
  'wxMenuItemBase::GetAccelFromString',
  'wxColour::GetPixel', # problem with COLOREF on mac which is unsigned char[6]
  'wxColour::FromRGBColor', # pb with COLORREF
  'wxColour::m_pixel', # idem
  'wxCursor::GetHCURSOR',           # linking pb on macros
  'wxDateTime::IsGregorianDate',    # no implemented
  'wxToolBar::OnMouse',             # idem, MacOS linking error
  'wxStatusBarGeneric::SetBorderX', # idem, MacOS linking error
  'wxStatusBarGeneric::SetBorderY', # idem, MacOS linking error
  'wxArrayString::resize',          # no defined
  'wxMenuBar::Create',              # idem
  'wxButtonBase::GetDefaultSize',   # idem, MacOS linking
  'wxIcon::SetOk',                  # idem
  'wxWindow::FindItem',             # idem, MacOS error
  'wxPoint2DDouble::SetPolarCoordinates', # idem
  'wxPoint2DInt::SetPolarCoordinates', # idem
  'wxGenericListCtrl::Update(long)', # linking problem, don't know why ...
  'wxBitmap::GetSelectedInto', # not included in windows in release mode
  'wxBitmap::SetSelectedInto', # not included in windows in release mode
  'wxWindowList::front', # returning reference to pointer
  'wxListCtrl::ConvertToMSWStyle', # linking problem MacOS
  'wxListCtrl::ChangeCurrent',     # idem
  'wxListCtrl::ResetCurrent',      # idem
  'InternalTransformDerivative', # VTK: pointer to array ...
  'vtkPolyData::GetPointCells', # reference to pointer as parameter
  'vtkPolyData::GetCellPoints',  # idem
  'vtkSource::GetOutputs',       # double pointer
  'vtkProcessObject::GetInputs', # idem
  'vtkPlot::GetProperty', # seems not implemented
  'vtkPlot::SetProperty', # seems not implemented
  ]


class_types = ['Class','Struct']

# amilab available_types
available_classes=[]
parsed_classes=[]
wrapped_classes=[]
incomplete_classes=[]
new_needed_classes=[]

# available builtin type
available_types       = [
  'int',
  'float',
  'double',
  'unsigned char',
  'long',
  'long int',
  'std::string',
  'bool',
  'void',
  'AMIFunction',
  'InrImage'
  ]
available_builtin_classes     = ['amilab::SurfacePoly']

# not used
#available_pointertypes= ['int','float','double','unsigned char','long','long int','std::string','bool']

available_operators={ \
  '!=' : '__not_equal__', \
  '==' : '__equal__', \
  '[]' : '__at__', \
  '()' : '__parenthesis__', \
  '='  : '__assign__',\
  '-=' : '__sub_assign__', \
  '+'  : '__add__', \
  '+=' : '__add_assign__', \
  '*'  : '__mult__', \
  '*()': '__indirection__', \
  '*=' : '__mult_assign__', \
  '/'  : '__div__', \
  '/=' : '__div_assign__', \
  '-'  : '__substract__', \
  '++' : '__preinc__', \
  '--' : '__predec__', \
  '++(int)':'__postinc__', \
  '--(int)':'__postdec__', \
  }

include_list = []
declare_list = []

#-------------------------------------------------------------
def ClassUsedName(classname):
  res = classname
  res = res.replace('<','__LT__')
  res = res.replace('>','__GT__')
  res = res.replace(',','__COMMA__')
  res = res.replace('::','__NS__')
  res = res.replace(' ','__SPACE__')
  return res

#-------------------------------------------------------------
def ClassShortName(classname):
  res = classname
  # keep std::string as is
  if classname=="std::string":
    return res
  res = res.replace('<','_')
  res = res.replace('>','')
  res = res.replace(',','_')
  res = res.replace('::','_')
  res = res.replace(' ','')
  return res

#-------------------------------------------------------------
def IsMultipleTemplate(classname):
  res=False
  if( (classname.find('<')>=0) and (classname.find(',')>=0) ):
    res=True
  return res
  
#-------------------------------------------------------------
def ClassTypeDef(classname):
  return ClassShortName(classname)

#------------------------------------------------------------------
#  AddInclude
#------------------------------------------------------------------
def AddInclude(f):
  if not(f in include_list):
    # temporary fix for <list>
    if f=='#include "stl_list.h"':
      f= '#include <list>'
    #print "adding include file {0}".format(f)
    include_list.append(f)

#------------------------------------------------------------------
#  AddDeclare
#------------------------------------------------------------------
def AddDeclare(f):
  if not(f in declare_list):
    #print "*********** adding {0} to declare_list".format(f)
    declare_list.append(f)

#------------------------------------------------------------------
#  CreateIncludes
#------------------------------------------------------------------
def CreateIncludes():
  res='';
  for f in include_list:
    #res += '#include "{0}"\n'.format(f)
    res += '{0}\n'.format(f)
  
  for f in declare_list:
    # avoid inclusion, just declare the type ...
    res += '#ifndef {0}_declared\n'.format(ClassUsedName(f))
    res += '  #define {0}_declared\n'.format(ClassUsedName(f))
    if f.count(",")>0:
      res += '  typedef {0} {1};\n'.format(f,ClassTypeDef(f))
      res += '  AMI_DECLARE_TYPE({0})\n'.format(ClassTypeDef(f))
    else:
      res += '  AMI_DECLARE_TYPE({0})\n'.format(f)
    res += '#endif\n'
  return res


#------------------------------------------------------------------
#  Check for boost shared pointer type
#------------------------------------------------------------------
def IsSharedPtr(typename):
  res = re.match(r"boost::shared_ptr<(.*)>",typename)
  if res!=None:
    # get rid of spaces with strip ...
    return res.group(1).strip()
  else:
    return None

#-------------------------------------------
# Language tokens
#-------------------------------------------

improcess_flex_lpp      = sys.path[0]+"/../../src/Language/improcess_flex.lpp"

def get_tokens():
    lex_tokens={}
    f = open (improcess_flex_lpp, "r")
    fc = f.read()
    parse_token=re.compile('/\*\{(.+),(.*)\}\*/')
    f.seek(0)
    #
    lines=string.split(fc,'\n')
    #
    for l in lines:
        t=parse_token.search(l)
        if t:
            lex_tokens[t.group(2)]=t.group(1)
            # now split expression and lex token:
    return lex_tokens

ami_tokens = get_tokens()
#print ami_tokens
