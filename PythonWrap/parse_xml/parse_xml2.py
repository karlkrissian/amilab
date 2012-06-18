#!/usr/bin/python
# -*- coding: utf-8 -*-

from xml.sax import saxutils,handler
from xml.sax import make_parser
from xml.sax.handler import feature_namespaces

import sys
import shutil
import fileinput
#import os
import glob
import re
import os.path
import datetime
import time

# configuration, containing the global variables
import config

# load command line arguments
import args

# type substitution
import typesubst

# type argument information
from argtypes import *

import utils

import findtypesvars
import findfiles
import wx_lib

import arginfo
import wrap_class
import parse_function
import wrap_function

import generate_html #HTML generate file functions
import pickle
  
def FindAvailableClasses():
  for dir in args.val.wrap_includes:
    utils.WarningMessage( "looking for classes in {0}".format(dir))
    # add files of type wx/wrap_wx**.h
    for name in glob.glob(dir+'/wrap_*.h'):
      #print name
      m = re.match(dir+r"wrap_(?P<class_name>\w+)\.h", name)
      if (m!=None):
        classname= m.group('class_name')
        if not(classname in config.available_classes):
          utils.WarningMessage("  adding {0}".format(classname))
          config.available_classes.append(classname)


#-------------------------------------------------------------
# Parse methods and field members
#-------------------------------------------------------------






#----------------------------------------------------------------------
#  WrapMethodTypePointer
#----------------------------------------------------------------------
def WrapMethodTypePointer(typedefname,include_file):
  #print "WrapMethodPointer({0},..)".format(typedefname)
  # Create the handler
  #dh = FindMethodTypePointer(typedefname)

  ## Tell the parser to use our handler
  #parser.setContentHandler(dh)
  ## Parse the input
  #inputfile.seek(0)
  #parser.parse(inputfile)

  #
  #if dh.found:
  #utils.WarningMessage( "{0} id= {1}".format(typedefname,dh.typedefid))

  # Create Header File
  header_filename=args.val.outputdir+"/wrap_{0}.h.new".format(typedefname)
  shutil.copyfile(args.val.templatefile_dir+"/wrap_class.h.in",header_filename)
  
  # should be named available typedefs or something like this?
  # add the class to the available ones
  if typedefname not in config.available_classes:
    config.available_classes.append(typedefname)


  implement_deleter = ", smartpointer_nodeleter<{0} >()".format(typedefname)
  implement_smart_pointer=  "boost::shared_ptr<{0} > res(sp {1});".\
        format(typedefname, implement_deleter)

  declare_type=''
  if typedefname in config.builtin_classes:
      declare_type='  AMI_DECLARE_WRAPPED_LIMITED_TYPE({0});'.format(\
        typedefname)
  else:
      declare_type='  AMI_DECLARE_TYPE({0});'.format(\
        typedefname)

  # now output the results:
  constructors_decl='\n'

  # Static Methods:
  staticmethods_decl='\n'

  class_decl='\n'

            
  # in place replace TEMPLATE by classname
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  includefiles = '#include "{0}"'.format(include_file)
  if args.val.dllname!='':
    export_macro = '{0}_EXPORT'.format(args.val.dllname)
  else:
    export_macro = ''
  for line in fileinput.FileInput(header_filename,inplace=1):
    line = line.replace("${EXPORT_MACRO}",     export_macro)
    line = line.replace("${INCLUDE_BASES}",     "")
    line = line.replace("${DECLARE_TYPE}",      declare_type)
    line = line.replace("${INHERIT_BASES}",     "")
    line = line.replace("${CONSTRUCTOR_BASES}", "")
    line = line.replace("${TEMPLATE}",          typedefname)
    line = line.replace("${INCLUDEFILES}",      includefiles)
    line = line.replace("${ADD_CLASS_CONSTRUCTORS}","")
    line = line.replace("${ADD_CLASS_STATIC_METHODS}","")
    line = line.replace("${ADD_CLASS_METHOD_ALL}",class_decl)
    print line,
        
  implement_type="\n"
  implement_type += "AMI_DEFINE_GETVALPARAM({0});\n".format(typedefname)
  implement_type += "AMI_DEFINE_WRAPPEDTYPE_NOCOPY({0});\n".format(typedefname)
  # need to implement CreateVar ...
  implement_type += "AMI_DEFINE_VARFROMSMTPTR({0});\n".format(typedefname)
  implement_type += "\n"
  implement_type += "// Implementing CreateVar for AMILabType\n"
  implement_type += "BasicVariable::ptr AMILabType<{0}>::CreateVar( {0}* val, bool nodeleter)\n".format(typedefname)
  implement_type += "{ \n"
  implement_type += "  boost::shared_ptr<{0}> obj_ptr(val,smartpointer_nodeleter<{0}>());\n".format(typedefname)
  implement_type += "  return AMILabType<{0}>::CreateVarFromSmtPtr(obj_ptr);\n".format(typedefname)
  implement_type += "}\n"
  
  # Implement CreateVar
  implement_createvar=''
  implement_createvar += "  // No variable creation for methodtype ...\n"
  implement_createvar += "  return BasicVariable::ptr();\n"

  # Create Implementation File
  impl_filename=args.val.outputdir+"/wrap_{0}.cpp.new".format(typedefname)
  shutil.copyfile(args.val.templatefile_dir+"wrap_class.cpp.in",impl_filename)
  
  # arguments
  impl = ""
  
  # in place replace TEMPLATE by classname
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  for line in fileinput.FileInput(impl_filename,inplace=1):
    line = line.replace("${TEMPLATE}",          typedefname)
    line = line.replace("${INCLUDES}",           "")
    #line = line.replace("${IMPLEMENT_DELETER}",  implement_deleter)
    line = line.replace("${IMPLEMENT_SMART_POINTER}", implement_smart_pointer)
    line = line.replace("${IMPLEMENT_TYPE}",     implement_type)
    line = line.replace("${IMPLEMENT_CREATEVAR}",implement_createvar)
    line = line.replace("${METHODS_BASES}",     "")
    line = line.replace("${AddVar_method_all}",  "")
    line = line.replace("${AddPublicFields}",    "")
    line = line.replace("${AddPublicEnums}",    "")
    line = line.replace("${AddVar_constructor}",  "")
    line = line.replace("${AddVar_static_methods}",  "")
    line = line.replace("${WRAP_PUBLIC_METHODS}",impl)
    line = line.replace("${AddPublicTypedefs}","")
    print line,
  wrap_class.BackupFile(header_filename)
  wrap_class.BackupFile(impl_filename)


#----------------------------------------------------------------------
# main
#----------------------------------------------------------------------
if __name__ == '__main__':
  
    if (args.val.profile):
      t0 = time.clock()
    # add the user defined classes
    for cl in args.val.available_classes:
      config.available_classes.append(cl)

    if args.val.available_classes_file != '':
      # append list of classes from file
      classes_file = open(args.val.available_classes_file,'r')
      avail_classes = classes_file.read().split(';')
      for cl in avail_classes:
        if cl!='':
          config.available_classes.append(cl)
      classes_file.close()
      
    for cl in args.val.available_external_classes:
      config.available_classes.append(cl)
    for cl in args.val.available_external_classes2:
      config.available_classes.append(cl)
    for cl in config.available_builtin_classes:
      config.available_classes.append(cl)
    FindAvailableClasses()
    #print "available classes:", config.available_classes
    
    # create a list of available_classes with changed name to simplify further
    # search (and avoid differences like short int, short, etc ...)
    for c in config.available_classes:
      config.available_classes_usedname.append(config.ClassUsedName(c))
    
    if (args.val.profile):
      t1 = time.clock()
      print t1 - t0, "seconds process time"


    if not(os.path.exists(args.val.outputdir)):
      try:
        os.mkdir(args.val.outputdir)
      except:
        # create temporary directory
        prev = args.val.outputdir
        import tempfile
        args.val.outputdir=tempfile.mkdtemp("wrap")
        print "{0} failed: switch to temporary output directory {1}".format(prev,args.val.outputdir)

    # Create a parser
    parser = make_parser()

    config.libmodule = None
    if args.val.libname=="wx":
      import wx_lib
      config.libmodule = wx_lib.config
    if args.val.libname=="vtk":
      import vtk_lib
      config.libmodule = vtk_lib.config
    if args.val.libname=="itk":
      import itk_lib
      config.libmodule = itk_lib.config
    if args.val.libname=="mt":
      import mt_lib
      config.libmodule = mt_lib.config
    if args.val.libname=="us":
      import us_lib
      config.libmodule = us_lib.config

    headerfile="{0}_includes.h".format(args.val.libname)
    
    if config.libmodule!=None:
      args.val.filter = config.libmodule.get_var_filter()

    # Tell the parser we are not interested in XML namespaces
    parser.setFeature(feature_namespaces, 0)

    inputfile = open(args.val.xmlfilename,'r')
    
    # add classes from the corresponding file if any
    if args.val.classes_file != '':
      # append list of functions from file
      classes_file = open(args.val.classes_file,'r')
      classes = classes_file.read().split(';')
      n=0
      for cl in classes:
        if cl!='':
          args.val.classes.append(cl)
          n=n+1
      classes_file.close()
      if n>0 and args.val.addwrap:
        # remove the file to allow its new creation by cmake
        os.rename(args.val.classes_file,args.val.classes_file+".bak")
      
    # Create the handler
    # Get public members of available classes given in parameter
    config.parsed_classes = args.val.classes[:]

    print config.parsed_classes
    
    ft = findtypesvars.FindTypesAndVariables(config.parsed_classes)
    parser.setContentHandler(ft)
    # Parse the input
    inputfile.seek(0)
    parser.parse(inputfile)
    
    saveconf = open(args.val.outputdir+"/saveconfig.dat","w")
    pickle.dump(config.types,saveconf,-1)

    #print "wxConfig is available ? ", wrap_class.AvailableType("wxConfigBase",config.classes["wxConfigBase"],[])

    #print "Number of classes matching the filter : {0}".format(ft.number_of_libclasses)
    #print "BLACKLIST=", config.classes_blacklist

    if args.val.ancestors != []:

      # 1 create dictionnary of classes to speed-up ...
      print "Creating classes dict"
      classes_dict = dict()
      typedef_dict = dict()
      for f in config.types.keys():
        if config.types[f].GetType()=="Class":
          classes_dict[f] = config.types[f].GetFullString()
        if config.types[f].GetType()=="Typedef":
          typedef_dict[f] = config.types[f].GetFullString()
        #print "typedef : {0}".format(typedef_dict[f])
      #print typedef_dict
      
      #print "--------------------"
      #print classes_dict.values()
      #print "--------------------"
      
      print "Creating ancestors"
      # 2. create list of classes
      ancestors = args.val.ancestors[:]
      # 3. expand ancestor to classes within templates
      ancestors_templates = ancestors[:]
      for b in ancestors:
        if wrap_class.IsTemplate(b):
          #print "Looking for additional types in ", b
          ttypes=[]
          config.templatetypes(b,ttypes)
          #print ttypes
          for nt in ttypes:
            #print "  Searching for '{0}'".format(nt)
            if nt not in ancestors_templates:
              if nt in classes_dict.values() and \
                 nt not in config.classes_blacklist and\
                 (nt not in config.available_types) and \
                 (nt not in args.val.available_external_classes) and \
                 (nt not in args.val.available_external_classes2) and \
                 (nt not in config.available_builtin_classes):
                ancestors_templates.append(nt)
                #print "    added ..."
              #else:
                #print "    not in classes_dict.values()"
      #print "New ancestors list = ",ancestors_templates
      ancestors = ancestors_templates[:]
      for b in ancestors:
        #print "b=",b
        # find the class corresponding to typedefs
        #for k in typedef_dict.keys():
          #if typedef_dict[k].replace(' ','')==b.replace(' ',''):
            #print "Found typedef {0}".format(b)
            #tid = config.types[k].GetRefTypeId()
            #print "with type {0}, {1}: {2}".format(config.types[tid].GetFullString(),config.types[tid].GetString(),config.types[k].GetFullString())
            #newclass=config.types[tid].GetFullString()
            #ancestors.append(newclass)
            ##newlist.append(newclass)
        # find the id of the class
        for f in classes_dict.keys():
          if classes_dict[f] == b:
            #print "ancestors to add?"
            # recursively add the ancestors to the list
            bases=config.types[f].bases
            #print bases
            #if b=="wxTopLevelWindow":
              #print bases
            f_anc=[]
            if bases!=None:
              f_anc = bases
            newlist=[]
            while f_anc != []:
              anc_id = f_anc.pop()[0]
              #if b=="wxTopLevelWindow":
              #print anc_id
              if not(anc_id in classes_dict.keys()):
                print "not in classes_dict.keys() ..."
              if anc_id in classes_dict.keys():
                #if b=="wxTopLevelWindow":
                #print classes_dict[anc_id]," args.val.templates=",args.val.templates
                #print classes_dict[anc_id] not in ancestors
                #print classes_dict[anc_id] not in config.classes_blacklist
                if  classes_dict[anc_id] not in ancestors and  \
                    classes_dict[anc_id] not in config.classes_blacklist and\
                    (classes_dict[anc_id] not in config.available_types) and \
                    (classes_dict[anc_id] not in args.val.available_external_classes) and \
                    (classes_dict[anc_id] not in args.val.available_external_classes2) and \
                    (classes_dict[anc_id] not in config.available_builtin_classes) and\
                    ( (not wrap_class.IsTemplate(classes_dict[anc_id])) \
                      or args.val.templates ):
                  m = re.match(args.val.filter, classes_dict[anc_id])
                  #print "Check ancestor {0} to match filter".format(classes_dict[anc_id])
                  if m != None:
                    #print "OK"
                    ancestors.append(classes_dict[anc_id])
                    #print "adding {0}".format(classes_dict[anc_id])
                    newlist.append(classes_dict[anc_id])
                    bases=config.types[anc_id].bases
                    #if b.startswith("itk"):
                      #if b=="wxTopLevelWindow":
                      #print "**** bases=",bases
                    if bases!=None:
                      for newanc in bases:
                        if f_anc not in config.classes_blacklist:
                          f_anc.append(newanc)
                          #print "adding __ {0}".format(newanc)
            #print "New ancestors of {0} are {1}".format(b,newlist)
      #print "All ancestors are   {0} ".format(ancestors)
      # write ancestors file
      print args.val.ancestors_file
      print "ancestors={0}".format(ancestors)
      f = open (args.val.ancestors_file, "w")
      # ancestors dependencies
      ancestors_depfile = os.path.splitext(args.val.ancestors_file)[0]+\
                          "_depfile.txt"
      f1 = open(ancestors_depfile,"w")
      # first sort
      ancestors.sort()
      for a in ancestors:
        if a not in args.val.available_external_classes:
          f.write(a+"\n")
        else:
          print "Rejecting {0} from ancestors\n".format(a)
        print a
        #print config.types.values()
        if a in classes_dict.values():
          #print "*"
          pos = classes_dict.values().index(a)
          #print pos
          fid = config.types[classes_dict.keys()[pos]].fileid
          #print fid
          print config.files[fid]
          f1.write(a+" | "+config.files[fid]+"\n")
      
      if(args.val.generate_html):
        generate_html.obj.Initialization( args.val.templatefile_dir, \
                                          args.val.outputhtmldir,\
                                          "index.html",\
                                          args.val.url,\
                                          args.val.libname)
        generate_html.obj.GenerateHTMLClassesFile(ancestors)
      sys.exit(0)

    if (args.val.profile):
      t2 = time.clock()
      print t2 - t1, "seconds process time"
    
    # Parse the input again, TODO: avoid 2 parses here ...
    #inputfile.seek(0)
    #parser.parse(inputfile)

    # Create the handler
    #ff = findfiles.FindFiles()
    #parser.setContentHandler(ff)
    ## Parse the input
    #inputfile.seek(0)
    #parser.parse(inputfile)
    
    # now files are parsed in ft
    utils.WarningMessage( "Number of files found : {0}".format(ft.number_of_files))
    
    #for id in config.types.keys():
    #  print id,"\t",config.types[id].GetFullString()

    #include_file="wx/aui/aui.h"
    include_file=headerfile
    
    # add classes from the corresponding file if any
    if args.val.methodpointers_file != '':
      # append list of functions from file
      methodpointers_file = open(args.val.methodpointers_file,'r')
      methodpointers = methodpointers_file.read().split(';')
      n=0
      for cl in methodpointers:
        if cl!='':
          n=n+1
          args.val.methodpointers.append(cl)
      methodpointers_file.close()
      if n>0 and args.val.addwrap:
        # remove the file to allow its new creation by cmake
        os.remove(args.val.methodpointers_file)
      
    if args.val.methodpointers!=None:
      for mp in args.val.methodpointers:
        WrapMethodTypePointer(mp,include_file)
    #WrapMethodTypePointer("wxCommandEventFunction",include_file)
    #WrapMethodTypePointer("wxObjectEventFunction",include_file)
    
    config.needed_classes = []
    
    #if the needed class is already available, don't wrap it
    for cl in args.val.classes:
      if  (cl not in args.val.available_external_classes) and \
          (cl not in args.val.available_external_classes2) and \
          (cl not in config.available_builtin_classes):
        config.needed_classes.append(cl)
        #print "Adding class {0}".format(cl)
    
    # in case of update option, add all the classes found in the files
    # and that match the library filter
    if args.val.update:
      for cl in config.available_classes:
        m = re.match(args.val.filter, cl)
        if m != None:
          config.needed_classes.append(cl)
    
    number_of_newclasses = 0
    
    if (args.val.profile):
      t3 = time.clock()
      print t3 - t2, "seconds process time"
  
    n=0
    nmax=args.val.max
    #print "Maximum classes set to {0}".format(nmax)
    while (len(config.needed_classes)>0) and (n<nmax):
      #print "\n\n needed classes:", config.needed_classes, "\n\n"
      cl = config.needed_classes.pop()
      #print "Class: {0} \t usedname: {1}".format(cl,wrap_class.ClassUsedName(cl))
      config.include_list = []
      config.declare_list = []
      wrap_class.HTMLInitialization(  args.val.generate_html, \
                                      args.val.templatefile_dir, \
                                      args.val.outputhtmldir, \
                                      "index.html", \
                                      args.val.url, \
                                      args.val.libname)
      wrap_class.WrapClass(cl,include_file,inputfile)
      config.wrapped_classes.append(cl)
      if args.val.r:
        for c in config.new_needed_classes:
          # check if templates are discarded
          if (not wrap_class.IsTemplate(c)) or args.val.templates:
            if  (c != cl) and \
                (c not in config.incomplete_classes) and \
                (c not in config.needed_classes):
              m = re.match(args.val.filter, c)
              if m != None:
                if c not in config.available_classes: 
                  number_of_newclasses = number_of_newclasses + 1
                config.needed_classes.append(c)
        config.new_needed_classes=[]
      #print "*** "
      utils.WarningMessage( "*** Wrapped Class Number: {0}".format(n))
      #print "*** "
      n = n+1

    if n>=nmax:
      print "WARNING: Exceeding the maximum number of classes to wrap which is set to {0} !!\n".format(nmax)

    utils.WarningMessage( "new classes: {0}".format(number_of_newclasses))
    if number_of_newclasses > 0:
      if not args.val.update:
        # Re-wrap the wrapped classes to be sure to include all the members
        for cl in config.wrapped_classes:
          config.include_list = []
          config.declare_list = []
          wrap_class.HTMLInitialization(  args.val.generate_html,\
                                          args.val.templatefile_dir, \
                                          args.val.outputhtmldir, \
                                          "index.html", \
                                          args.val.url, \
                                          args.val.libname)
          wrap_class.WrapClass(cl,include_file,inputfile)

    utils.WarningMessage( "Wrapped classes: {0}".format(config.wrapped_classes))
    
    if (args.val.profile):
      t4 = time.clock()
      print t4 - t3, "seconds process time"
    
    # now create the library context
    if args.val.libname!=None and args.val.addwrap:
      # header
      createcontextname = args.val.outputdir+"/addwrap_{0}.h.new".format(args.val.libname)
      f = open (createcontextname, "w")
      # 1. write some doc
      f.write("/*\n")
      f.write(" * Automatic wrapping of '{0}' library for AMILab.\n".format(args.val.libname))
      f.write(" * File: {0}\n".format(createcontextname))
      f.write(" * Generated by the script '{0}'\n".format(sys.argv[0]))
      f.write(" * Date: '{0}'\n".format(datetime.date.today().strftime('%d-%m-%Y')))
      f.write(" */\n")
      f.write("\n")
      f.write("#ifndef _addwrap_{0}_h_\n".format(args.val.libname))
      f.write("#define _addwrap_{0}_h_\n".format(args.val.libname))
      f.write("\n")
      f.write('#include "Variables.hpp"\n')
      f.write("\n")
      f.write("void wrap_{0}_classes  ( Variables::ptr& context);\n".format(args.val.libname))
      f.write("void wrap_{0}_functions( Variables::ptr& context);\n".format(args.val.libname))
      f.write("\n")
      f.write("#endif // _addwrap_{0}_h_\n".format(args.val.libname))
      f.close()
      wrap_class.BackupFile(createcontextname)

      # implementation
      createcontextname = args.val.outputdir+"/addwrap_{0}.cpp.new".format(args.val.libname)
      f = open (createcontextname, "w")
      # 1. write some doc
      f.write("/*\n")
      f.write(" * Automatic wrapping of '{0}' library for AMILab.\n".format(args.val.libname))
      f.write(" * File: {0}\n".format(createcontextname))
      f.write(" * Generated by the script '{0}'\n".format(sys.argv[0]))
      f.write(" * Date: '{0}'\n".format(datetime.date.today().strftime('%d-%m-%Y')))
      f.write(" */\n")
      f.write("\n")

      f.write('#include "Variables.hpp"\n')
      f.write('#include "ami_object.h"\n')

      # 2. write all needed includes
      # -- list the library classes (based on the filter)
      lib_classes = []
      for cl in config.available_classes:
        if  (cl not in args.val.available_external_classes) and \
            (cl not in args.val.available_external_classes2) and \
            (cl not in config.available_builtin_classes):
          m = re.match(args.val.filter, cl)
          if m != None:
            lib_classes.append(cl)

      # sort alphabetically
      lib_classes.sort()
      f.write('#include "addwrap_{0}.h"\n'.format(args.val.libname))
      f.write('#include "{0}"\n'.format(include_file))

      f.write("\n")
      f.write("// Currently {0} objects (classes,structures,typedefs,...) are wrapped \n".format(len(lib_classes)))
      for cl in lib_classes:
        #f.write('#include "wrap_{0}.h"\n'.format(cl))
        f.write('extern void WrapClass{0}_AddStaticMethods( Variables::ptr&);\n'.format(config.ClassUsedName(cl)))
      f.write("\n")

      # -- list the library functions (based on the filter)
      lib_functions = []
      for func in  args.val.available_functions:
        # TODO: check that the function is valid
        lib_functions.append(func)

      if args.val.available_functions_file != '':
        # append list of functions from file
        functions_file = open(args.val.available_functions_file,'r')
        avail_functions = functions_file.read().split(';')
        for cl in avail_functions:
          if cl!='':
            lib_functions.append(cl)
        functions_file.close()

      # sort alphabetically
      lib_functions.sort()

      f.write('\n')
      f.write("// Currently {0} functions are wrapped \n".format(len(lib_functions)))
      for func in lib_functions:
        f.write('#include "wrap_{0}.h"\n'.format(config.ClassUsedName(func)))
        #f.write('extern void WrapClass{0}_AddStaticMethods( Variables::ptr&);\n'.format(config.ClassUsedName(cl)))
      f.write("\n")

      # Add an enumeration value
      f.write("/* Adding an enumeration value */\n")
      f.write("static void AddEnumVal( AMIObject::ptr& obj, const char* name, int val)\n")
      f.write("{\n")
      f.write("  BasicVariable::ptr var = AMILabType<int >::CreateVar(val);\n")
      f.write("  var->Rename(name);\n")
      f.write("  obj->GetContext()->AddVar(var,obj->GetContext());\n")
      f.write("}\n")
      f.write("\n")

      f.write("static void wrap_enums( Variables::ptr& context);\n".format(args.val.libname))
      f.write("static void wrap_vars( Variables::ptr& context);\n".format(args.val.libname))
      f.write("static void wrap_macros( Variables::ptr& context);\n".format(args.val.libname))
      
      # Wrap all classes in a context
      f.write("/*\n")
      f.write(" * Adding all the wrapped classes to the library context.\n")
      f.write(" * @param context the library context.\n")
      f.write(" */\n")
      f.write("void wrap_{0}_classes( Variables::ptr& context)\n".format(args.val.libname))
      f.write("{\n")
      f.write("\n")

      f.write("\n")
      for cl in lib_classes:
        f.write("  WrapClass{0}_AddStaticMethods( context);\n".format(config.ClassUsedName(cl)))
        
      f.write("\n")
      f.write("  wrap_enums (context);\n")
      f.write("  wrap_vars  (context);\n")
      f.write("  wrap_macros(context);\n")
      f.write("}\n")
      
      # Wrap all functions in a context
      f.write("/*\n")
      f.write(" * Adding all the wrapped functions to the library context.\n")
      f.write(" * @param context the library context.\n")
      f.write(" */\n")
      f.write("void wrap_{0}_functions( Variables::ptr& context)\n".format(args.val.libname))
      f.write("{\n")
      f.write("\n")

      f.write("\n")
      for cl in lib_functions:
        f.write("  AddVar_{0}( context);\n".format(config.ClassUsedName(cl)))
        
      f.write("\n")
      f.write("}\n")
      
      f.write("static void wrap_enums( Variables::ptr& context)\n".format(args.val.libname))
      f.write("{\n")
      # Add global enumerations
      for t in config.types.keys():
        if config.types[t].GetType()=="Enumeration":
          enumkeys=config.types[t]._values.keys()
          # check if values starts with libname to avoid adding everything (valid for wxWidgets I think), but must be changed
          if enumkeys[0].startswith(args.val.libname):
            # 1. add the context
            # 2. add the values
            # 3. set as default

            enum_usedname = config.types[t]._name.replace('.','enum')
            # Create an amiobject
            f.write( "\n")
            f.write( "  // New enumeration {0}\n".format(enum_usedname))
            f.write( "  AMIObject::ptr obj_{0}(new AMIObject);\n".format(enum_usedname))
            f.write( '  obj_{0}->SetName("{0}");\n'.format(enum_usedname))
            # add all the values
            f.write( "\n")
            for ev in enumkeys:
              f.write( '  AddEnumVal(obj_{0},"{1}",{2});\n'.format(\
                enum_usedname,ev,config.types[t]._values[ev]))
            f.write( "\n")
            f.write( "  // Add enum to context, and add to default contexts\n")
            f.write( "  context->AddVar<AMIObject>(obj_{0}->GetName().c_str(),obj_{0},context);\n".format(enum_usedname))
            f.write( "  context->AddDefault(obj_{0}->GetContext());\n".format(enum_usedname))
      f.write("}\n")
      f.write("\n")
            
      f.write("static void wrap_vars( Variables::ptr& context)\n".format(args.val.libname))
      f.write("{\n")
      # Add variables and macros
      if args.val.libname=="wx":
        wx_lib.create_variables.CreateVariables(f,config)
      f.write("}\n")
      f.write("\n")

      f.write("static void wrap_macros( Variables::ptr& context)\n".format(args.val.libname))
      f.write("{\n")
      # Add variables and macros
      if args.val.libname=="wx":
        wx_lib.create_macros.CreateMacros(inputfile,f)
      if args.val.libname=="vtk":
        vtk_lib.create_macros.CreateMacros(inputfile,f)
      f.write("}\n")
      f.write("\n")
      
      f.close()
      # intelligent copy only if modified
      wrap_class.BackupFile(createcontextname)
    
    # add functions from the corresponding file if any
    if args.val.functions_file != '':
      # append list of functions from file
      functions_file = open(args.val.functions_file,'r')
      functions = functions_file.read().split(';')
      n=0
      for cl in functions:
        if cl!='':
          n=n+1
          args.val.functions.append(cl)
      functions_file.close()
      if n>0 and args.val.addwrap:
        # remove the file to allow its new creation by cmake
        os.remove(args.val.functions_file)
      
    # deal with functions
    needed_functions = args.val.functions
    wrapped_functions=[]
    while len(needed_functions)>0:
      #print "\n\n needed functions:", needed_functions, "\n\n"
      func = needed_functions.pop()
      print "Function: {0} ".format(func)
      config.include_list = []
      config.declare_list = []
      wrap_function.WrapFunction(func,include_file,inputfile)
      wrapped_functions.append(func)
        
    if (args.val.profile):
      t5 = time.clock()
      print t5 - t4, "seconds process time"
    
    if (args.val.profile):
      t5 = time.clock()
      print "Total time is:",t5 - t0, "seconds process time"
