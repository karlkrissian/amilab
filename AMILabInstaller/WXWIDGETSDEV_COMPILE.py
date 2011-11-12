# -*- coding: cp1252 -*-
#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the necessary commands are available
#

print "**"
import cpuinfo
import os
import platform

initdir=os.getcwd()

SITE="http://prdownloads.sourceforge.net/wxwindows/"
if platform.system()=='Windows':
  #FILE="wxMSW-2.8.12-Setup.exe"
  FILE="wxMSW-2.8.12.zip"
  DIR="wxMSW-2.8.12"
if platform.system()=='Linux':
  FILE="wxGTK-2.8.12.tar.gz"
  DIR="wxGTK-2.8.12"
print "**"

# TODO: move this command to python
#${INSTALLCMD} ${WXWIDGETSDEV_PRECOMP}

# if not already downloaded, compile it
print "**"

if not(os.access(FILE, os.R_OK)):
  import urllib2, urllib
  print "Dowloading {0}".format(FILE)
  urllib.urlretrieve(SITE+FILE, FILE)

if platform.system()=='Windows':
  if not(os.access(DIR, os.R_OK)):
    print "Extracting {0}".format(FILE)
    import zipfile
    f = zipfile.ZipFile(FILE)
    f.extractall()
    f.close()
    #extract_cmd = 'start "Extracting wxWidgets" wxMSW-2.8.12-Setup.exe'
    #res = os.popen(extract_cmd).read()
  
if platform.system()=='Linux':
  if not(os.access(DIR, os.R_OK)):
    print "Extracting {0}".format(FILE)
    import tarfile
    tar = tarfile.open(FILE)
    tar.extractall()
    tar.close()

os.chdir(DIR)
wx_path=os.getcwd()
if platform.system()=='Windows':
  print "Enabling OpenGL (GLCANVAS)"
  setup_file='{0}/include/wx/msw/setup.h'.format(wx_path)
  setup_file_bak='{0}/include/wx/msw/setup_bak.h'.format(wx_path)
  if os.access(setup_file_bak, os.R_OK):
    os.remove(setup_file_bak)
  os.rename(setup_file,setup_file_bak)
  import re
  o = open(setup_file,"w")
  data = open(setup_file_bak).read()
  o.write( re.sub(r"#define wxUSE_GLCANVAS(\s*)0",\
                  r"#define wxUSE_GLCANVAS   1",data) )
  o.close()
  os.chdir('build/msw')
  print "continue.."
  #os.putenv('PATH',"C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\vcpackages")
  #os.putenv('PATH',"C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\bin")
  #os.putenv('WXWIN',"{0}".format(wx_path))
  #res = os.popen('vcvarsall.bat').read()
  #res = os.popen(cmd_nmake).read()
  #start "Compiling WxWidgets with nmake"  
  #print "running {0}".format(cmd_nmake)

  # write command to a batch file
  c = open("run_nmake.bat", "wt")
  cmd_nmake = 'call "C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\vcvarsall.bat"'
  c.write(cmd_nmake+" \n ")
  cmd_nmake = 'set WXWIN="{0}"'.format(wx_path)
  c.write(cmd_nmake+" \n ")
  cmd_nmake = '"C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\bin\\nmake.exe" -f makefile.vc BUILD=release SHARED=0' #BUILD=release UNICODE=1 SHARED=0 RUNTIME_LIBS=static'
  print "adding command {0}".format(cmd_nmake)
  c.write(cmd_nmake+"\n")
  cmd_nmake = 'exit /b'
  c.write(cmd_nmake+"\n")
  c.close()

  print "running run_nmake.bat"
  #res = os.system('run_nmake.bat')
  res = os.popen('start "run_nmake" run_nmake.bat').read()
  print res
  print "--- Building stc ---"
  os.chdir("{0}/contrib/build/stc".format(wx_path))
  c = open("run_nmake.bat", "wt")
  cmd_nmake = 'call "C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\vcvarsall.bat"'
  c.write(cmd_nmake+" \n ")
  cmd_nmake = 'set WXWIN="{0}"'.format(wx_path)
  c.write(cmd_nmake+" \n ")
  cmd_nmake = '"C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\bin\\nmake.exe" -f makefile.vc BUILD=release SHARED=0' #BUILD=release UNICODE=1 SHARED=0 RUNTIME_LIBS=static'
  print "adding command {0}".format(cmd_nmake)
  c.write(cmd_nmake+"\n")
  cmd_nmake = 'exit /b'
  c.write(cmd_nmake+"\n")
  c.close()

  print "running run_nmake.bat"
  #res = os.system('run_nmake.bat')
  res = os.popen('start "run_nmake" run_nmake.bat').read()
  print res
else:
  os.mkdir(build_linux)
  #cd build_linux
  #../configure --with-opengl --enable-intl --enable-threads --enable-xpm
  #make -j ${numthreads} install
  #cd contrib/src/stc
  #make -j ${numthreads} install

os.chdir(initdir)
