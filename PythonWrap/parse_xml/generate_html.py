#
# Generates a HTML file with a list of the classes and methods that the Wrapping
# has been processed.
#
# The main functions are:
#
# - Initialization: Provides the values required for the generation of HTML
#   pages. This function must always be invoked before GenerateHTMLClassesFile
#   and GenerateHTMLClassFile.
#
# - GenerateHTMLClassesFile: Generates a file index.html that contains all the
#   appropriate classes wrapped target. If the classes appear without links it
#   is because the url is not found.
#
# - GenerateHTMLClassFile: Generates a HTML file for each class that contains a
#   list of its methods. If the methods appear without links it is because the
#   url is not found.
#
# These functions are invoked from the files:
#
# - parse_xml2.py: In the section of the generation of ancestors, it creates the
#   corresponding file index.html.
#
#   Note: In this file, makes the following call:
#
#   wrap_class.HTMLInitialization(args.val.generate_html,
#                                 args.val.templatefile_dir,
#                                 args.val.outputhtmldir,
#                                 "index.html",
#                                 args.val.url,
#                                 args.val.libname)
#
#   This function defined in the module wrap_class and internally invokes
#   function Initialization.
#
# - wrap_class.py: This module defines the function HTMLInitialization that
#   invokes the Initialization function to initialize the process. Since this
#   module is invoked the following functions:
#
#   - AddClassMethod: Add the object that represents a method to a list called
#     classmethods.
#
#   - GenerateHTMLStandardMethods: Calls the function GenerateHTMLClassFile in
#     the case of the standard methods of a class. It's a function temporary for
#     debugging and this call should be replaced by the function
#     GenerateHTMLClassFile.
#

#
# Import modules
#
import config
import hashlib
import shutil
import fileinput
import urllib2
import re

#
# Global variables
#
classes=[]          # Classes list
classmethods=[]     # Class methods
ignoremethods=[]    # List of methods to ignore
networking=True     # Determines if exists networking
pathtemplate=""     # Path to HTML template
filename=""         # HTML file name
outputdir=""        # HTML output directory
baseurl=""          # HTML base URL
libname=""          # Library name
createhtml=False    # Flag to generate html.

#
# Main functions of the generate_html module.
#

#-------------------------------------------------------------
def Initialization(templatedir,outputdirectory,outputfilename,url,libraryname):
  global networking
  global pathtemplate
  global outputdir
  global filename
  global baseurl
  global libname
  global createhtml
  global classmethods
  global ignoremethods
  networking=CheckURL(url)
  pathtemplate=templatedir+"wrap_templatehtmlhelp.html.in"
  outputdir=outputdirectory
  filename=outputdir+"/"+outputfilename
  baseurl=url
  libname=libraryname
  createhtml=True
  ResetIgnoreMethodList()
  ResetClassMethodList()
  #print "Debug:\n"
  #print "pathtemplate: {0}\n".format(pathtemplate)
  #print "filename: {0}\n".format(filename)
  #print "baseurl: {0}\n".format(baseurl)
  #print "libname: {0}\n".format(libname)

#-------------------------------------------------------------
def GenerateHTMLClassesFile(classlist):
  global pathtemplate
  global filename
  global classes

  if(createhtml):  
    htmltitle="AMILab-C++ Wrapping Class Reference"
    htmlbody="<h1>Class List</h1>"
    htmlbody+="Here are the classes with a link to the doxygen documentation:<br>"
    htmlbody+=GenerateList("Unordered","","begin")
    for classname in classlist:
      htmlbody+=GenerateListItem( GenerateClassFormat(classname, False) )
    htmlbody+=GenerateList("Unordered","","end")
    #print "Debug:\n"
    #print "pathtemplate: {0}\n".format(pathtemplate)
    #print "filename: {0}\n".format(filename)
    GenerateHTMLfile(pathtemplate, filename, htmltitle, htmlbody)

#-------------------------------------------------------------
def GenerateHTMLClassFile(classname,methodslist):
  global pathtemplate
  global filename

  if(createhtml):
    filename=outputdir+"/"+GenerateLocalURL(classname)
    htmltitle="AMILab-C++ Wrapping Class Reference - "+classname
    htmlbody="<h1>"+GenerateClassFormat(classname, True)+"</h1>"
    htmlbody+="<h2>Methods List</h2>"
    htmlbody+="Here are the methods with a link to the doxygen documentation:<br>"
    htmlbody+=GenerateList("Unordered","","begin")
    # sort list of methods here
    for method in methodslist:
        if(method.iswrapped):
          if(not IsIgnored(method.usedname)):
            htmlbody+=ProcessClassMethods(classname,method.usedname,methodslist,method.GetDescription(classname,False))
    htmlbody+=GenerateList("Unordered","","end")
    GenerateHTMLfile(pathtemplate, filename, htmltitle, htmlbody)
    ResetClassMethodList()
    ResetIgnoreMethodList()    

#
# Functions for debugging of generate_html module.
#

#-------------------------------------------------------------
def GenerateHTMLStandardMethods(classname):
  global createhtml
  if(createhtml):
    global classmethods
    global ignoremethods
    GenerateHTMLClassFile(classname,classmethods)
    ResetClassMethodList()
    ResetIgnoreMethodList()
    
#
# Internal functions of the generate_html module.
#

#-------------------------------------------------------------
def CheckURL(url):
  res=True
  req = urllib2.Request(url)
  try: urllib2.urlopen(req)
  except urllib2.URLError:
    res=False
  return res

#-------------------------------------------------------------
def GenerateHTMLfile(htmltemplate,htmlfilename,htmltitle,htmlbody):
  shutil.copyfile(htmltemplate,htmlfilename)
  for line in fileinput.FileInput(htmlfilename,inplace=1):
    line = line.replace("__TITLE__", htmltitle)
    line = line.replace("__BODY__",  htmlbody)
    print line,  

#-------------------------------------------------------------
def ProcessClassMethods(classname,methodname,classmethods,signature):
  global ignoremethods
  if(IsOverloaded(methodname)):
    name=GetMethodName(methodname)
    ignoremethods.append(name)
    body=GenerateListItem(GenerateMethodFormat(classname,name,name,signature) )
    body+=GenerateList("Unordered","","begin")
    pos=2
    for m in classmethods:
      if m.usedname!=methodname:
        if(m.usedname==name):
          body+=GenerateListItem(GenerateMethodFormat(classname,name,name+"_1",m.GetDescription(classname,False)) )
          ignoremethods.append(name+"_1")
        else:
          if(m.usedname==name+"_{0}".format(pos)):
            body+=GenerateListItem(GenerateMethodFormat(classname,name,name+"_{0}".format(pos),m.GetDescription(classname,False)) )
            ignoremethods.append(name+"_{0}".format(pos))
            pos=pos+1
    body+=GenerateList("Unordered","","end")
    res=body
  else:
    res=GenerateListItem(GenerateMethodFormat(classname,methodname,methodname,signature) )
  return res

#-------------------------------------------------------------
def GenerateAnchor(htmlurl,htmltitle,htmlbody):
  res = "<a href=\"__URL__\" title=\"__TITLE__\">__BODY__</a>"
  res = res.replace('__URL__',htmlurl)
  res = res.replace('__TITLE__',htmltitle)
  res = res.replace('__BODY__',htmlbody)
  return res

#-------------------------------------------------------------
def GenerateLineBreak():
  return "<br />"

#-------------------------------------------------------------
def GenerateList(listtype,options,flag):
  if(listtype=="Unordered"):
    if(flag=="begin"):
      res="<UL "+options+">"
    else:
      res="</UL>"
  else: # Ordered
    if(flag=="begin"):
      res="<OL "+options+">"
    else:
      res="</OL>"
  return res
  
#-------------------------------------------------------------
def GenerateListItem(item):
  return "<LI> "+item

#-------------------------------------------------------------
def GenerateDoxygenFileName(classname):
  input = classname
  input = input.replace('_','__')
  input = input.replace(':','_1')
  input = input.replace('/','_2')
  input = input.replace('<','_3')
  input = input.replace('>','_4')  
  input = input.replace('*','_5')
  input = input.replace('&','_6')
  input = input.replace('|','_7')
  input = input.replace('.','_8')
  input = input.replace('!','_9')
  input = input.replace(',','_00')
  input = input.replace(' ','_01')
  input = input.replace('{','_02') 
  input = input.replace('}','_03')
  input = input.replace('?','_04')
  input = input.replace('^','_05')
  input = input.replace('%','_06')
  input = input.replace('(','_07')
  input = input.replace(')','_08')
  input = input.replace('+','_09')
  input = input.replace('=','_0A')
  i=0
  res=""
  while i < len(input):
    if(input[i].isupper()):
      res+="_"+input[i]
    else:
      res+=input[i]
    i=i+1
  res = res.lower()
  return res

#-------------------------------------------------------------
def GenerateLocalURL(classname):
  cname = classname
  cname = cname.replace('::','_')
  cname = cname.replace('<','_')
  cname = cname.replace('>','_')
  return cname+".html"

#-------------------------------------------------------------
def GenerateClassFormat(classname, isexternalanchor):
  global networking
  global baseurl
  global libname
  #print "baseurl: {0}\n".format(baseurl)
  #print "libname: {0}\n".format(libname)  
  url=baseurl

  if(isexternalanchor):
    if libname=="wx":
      #Format for the version 2.8.x
      url+="wx_"+classname.lower()+".html#"+classname.lower()
    else:
      url+="class"+GenerateDoxygenFileName(classname)+".html"

    if(networking):
      if CheckURL(url):
        res = GenerateAnchor(url, classname, classname)
      else:
        res=classname
    else:
      res = GenerateAnchor(url, classname, classname)
  else:
    res = GenerateAnchor(GenerateLocalURL(classname), classname, classname)
  return res

#-------------------------------------------------------------
def GenerateMethodFormat(classname, methodname, body, signature):
  global baseurl
  global libname  
  url=baseurl
  if libname=="wx":
    #Format for the version 2.8.x
    methodname=methodname.replace('_','')
    #print "GenerateMethodFormat: methodname={0}\n".format(methodname)
    url+="wx_"+classname.lower()+".html#"+classname.lower()+methodname.lower()
  else:
    #Doxygen methodname format:
    # type classname::methodnamemethodname(parameters)
    #Example:
    # Input:  bool MyClass::Init(const std::string &InputFileName, const std::string &OutputFileName)
    # Output: bool MyClass::InitInit(const std::string &InputFileName, const std::string &OutputFileName)
    #
    # Version con clase metodos que apunten con wxwidgets2.8.
    #print signature
    posbegin=signature.find("::")+2
    posend=signature.find("(")
    themethodname=signature[posbegin:posend]
    themethodname=signature[:posend]+themethodname+signature[posend:]
    #print "GenerateMethodFormat: themethodname={0}\n".format(themethodname)

    txt=hashlib.md5()
    txt.update(themethodname)
    url+="class"+GenerateDoxygenFileName(classname)+".html#a"+txt.hexdigest()

  if(networking):
    if CheckURL(url):
      res = GenerateAnchor(url, methodname, body)
    else:
      res=methodname
  else:
    res = GenerateAnchor(url, methodname, methodname)
    
  res = res + " " + signature
  return res

#-------------------------------------------------------------
def IsClassProcessed(classname):
  global classes
  res=False
  for i in range(0,len(classes)):
    if(classes[i]==classname):
      res=True
      break
  return res

#-------------------------------------------------------------
def ResetIgnoreMethodList():
  global ignoremethods
  ignoremethods=[]

#-------------------------------------------------------------
def ResetClassMethodList():
  global classmethods
  classmethods=[]  

#-------------------------------------------------------------
def AddClassMethod(method):
  if(createhtml):
    global classmethods
    classmethods.append(method)

#-------------------------------------------------------------
def GetClassMethodList():
  return classmethods

#-------------------------------------------------------------
def IsOverloaded(methodname):
  pattern="_([0-9])+"
  if(re.search(pattern,methodname)):
    return True;
  else:
    return False;

#-------------------------------------------------------------
def IsIgnored(methodname):
  res=False
  for i in range(0,len(ignoremethods)):
    if(ignoremethods[i]==methodname):
      res=True
      break
  return res

#-------------------------------------------------------------
def GetMethodName(methodname):
  res=methodname
  pattern="_([0-9])+"
  isLocated=re.search(pattern,methodname)
  if(isLocated):
    pos=methodname.find(isLocated.group(0))
    res=methodname[0:pos]
  return res
