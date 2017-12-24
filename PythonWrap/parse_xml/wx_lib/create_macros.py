#
# Create macro variables
#

import re
# load command line arguments
import args

# 1. find the event.h file

#-------------------------------------------------------------
# Find file
#-------------------------------------------------------------
#-------------------------------------------------------------
class FindFile():
  def __init__(self, filename):
    self.search_filename = filename
    self.found=False
    self.name=""

  #---------------------------------------------
  def parse(self, xmltree):
    # go through elements
    root = xmltree.getroot()
    self.parseElt(root)

  #---------------------------------------------
  def parseElt(self,elt):
    self.startElement(elt.tag, elt.attrib)
    for child in list(elt):
      self.parseElt(child)
    #self.endElement(elt.tag)

  #---------------------------------------------
  def startElement(self, name, attrs):
    if not (name == "File"): return
    name = attrs.get('name', None)
    if name.find("wx/"+self.search_filename)!=-1:
      self.name=name
      found = True


# 2. register event macros

# 3. add event macros


def CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,headerfilename):
  # Create the handler
  if (headerfilename=="version"):
    dh = FindFile("string.h")
  else:
    dh = FindFile(headerfilename+".h")

  # Parse the input
  dh.parse(xmltree)

  res = ""
  if dh.name != "":
    if headerfilename=="version":
      dh.name=dh.name.replace("string","version")
    print "file is: ", dh.name
    headerfile = open(dh.name, 'r')
    found_macros=[]
    for line in headerfile:
      ok=False
      #print line
      # limited to macros of type #define wxXXXX 0x9999 for the moment
      findmacro = re.match(r"^\s*#define\s+(wx[_0-9a-zA-Z]+)\s*((0x[0-9]+)|([0-9]+))\s*(//.*)*$",line)
      if (findmacro!=None):
        found_macros.append(findmacro.group(1))
        all_found_macros.append(findmacro.group(1))
        #print "Found macro : ", findmacro.group(1), " = ", findmacro.group(2)
        ok=True
      #else:
        #print "direct not found"
      # allow macro defined from a previous one
      if not ok:
        findmacro = re.match(r"^\s*#define\s+(wx[_0-9a-zA-Z]+)\s*(wx[_0-9a-zA-Z]+)\s*(//.*)*$",line)
        if (findmacro!=None):
          #print "indirect found ", findmacro.group(2)
          if findmacro.group(2) in all_found_macros:
            #print "OK"
            ok=True
            found_macros.append(findmacro.group(1))
            all_found_macros.append(findmacro.group(1))
      if not ok:
        # special treatment for event, since it is quite complicated:
        # the macro defines a template type that can cast to int
        #wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CORE, wxEVT_MENU, wxCommandEvent);
        findmacro = re.match(r"^\s*wxDECLARE_EXPORTED_EVENT\(\s*([_0-9a-zA-Z]+)\s*,\s*(wx[_0-9a-zA-Z]+)\s*,\s*(wx[_0-9a-zA-Z]+)\s*\);\s*(//.*)*$",line)
        if (findmacro!=None):
          #print "****",findmacro.group(2)
          # add to macros
          found_macros.append(findmacro.group(2))
          all_found_macros.append(findmacro.group(2))
          ok=True
    
    if len(found_macros)>0:
      # add all the values
      res += "\n"
      res += "  // MACROS from file {0}.h\n".format(headerfilename)
      for m in found_macros:
        res += "  #ifdef {0}\n".format(m)
        res += "    ADD_{0}_MACRO({1});\n".format(args.val.libname.upper(), m)
        res += "  #endif\n"
      res += "\n"
    else:
      res += "  // No macro found in file {0}.h\n".format(headerfilename)
    print " all_found_macros size = ", len(all_found_macros)
  return res


def CreateMacros(xmltree,outputfile):
  all_found_macros=[]
  wrapped_macros=""
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"defs")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"version")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"toplevel")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"valtext")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"types")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"treebase")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"textctrl")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"statusbr")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"listbase")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"slider")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"dataview")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextctrl")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextformatdlg")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextindentpage")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextliststylepage")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextprint")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextstyledlg")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextstylepage")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextsymboldlg")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"richtext/richtextstyles")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"event")
  wrapped_macros += CreateHeaderFileMacros(all_found_macros,xmltree,outputfile,"notebook")

  if wrapped_macros!="":
    # Create the macros context
    outputfile.write("\n")
    outputfile.write( "  #define ADD_{0}_MACRO(name) \\\n".format(args.val.libname.upper()))
    outputfile.write( "    {\\\n")
    outputfile.write( "      BasicVariable::ptr var = AMILabType<int >::CreateVar(name);\\\n")
    outputfile.write( "      if (var.get()) {\\\n")
    outputfile.write( '        var->Rename(#name);\\\n')
    outputfile.write( '        macros_context->AddVar(var,macros_context);\\\n')
    outputfile.write( "      }\\\n")
    outputfile.write( "    }\\\n")
    outputfile.write("\n")

    # Create an amiobject
    outputfile.write( "\n")
    outputfile.write( "  // Macros context\n")
    outputfile.write( "  AMIObject::ptr obj_macros(new AMIObject);\n")
    outputfile.write( '  obj_macros->SetName("_wx_macros");\n')
    outputfile.write( '  Variables::ptr macros_context = obj_macros->GetContext();\n')

    outputfile.write( wrapped_macros)
    
    outputfile.write( "  // Add macros to context, and add to default contexts\n")
    outputfile.write( "  context->AddVar<AMIObject>(obj_macros->GetName().c_str(),obj_macros,context);\n")
    outputfile.write( "  context->AddDefault(macros_context);\n")
    
    outputfile.write("  #undef ADD_{0}_MACRO\n".format(args.val.libname.upper()))
