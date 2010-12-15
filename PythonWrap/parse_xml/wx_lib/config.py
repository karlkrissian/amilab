# -*- coding: utf-8 -*-

# include everything here: difficult to sort
def get_include_file(classname, filename):
  last = filename.rfind('/wx/')
  incfile=filename[last+1:]
  print "including class {0} from file {1}".format(classname,incfile)
  #print "including class {0} from file {1}".format(classname,filename)
  #return incfile
  return "wx_includes.h"
 
def get_var_filter():
  return "wx*"

def wrap_public_fields(classname):
  # only wrap public fields for wxPoint
  return classname=="wxPoint"
