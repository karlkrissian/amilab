# -*- coding: cp1252 -*-
import urllib,urllib2
import os,platform
import zipfile

#from check_windows_installed_products import *

#products = get_installed_products()
#for p in products:
#    if p.ProductName.startswith('CMake 2.8'):
#        print "Found '"+p.ProductName+"'"
#        installed=True

installed=False

import subprocess
from subprocess import PIPE

def launchWithoutConsole(command, args):
    """Launches 'command' windowless and waits until finished"""
    #startupinfo = subprocess.STARTUPINFO()
    #startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    #return subprocess.Popen([command] + args, startupinfo=startupinfo).wait()
    proc= subprocess.Popen([command]+args,stdin=PIPE,stderr=subprocess.STDOUT)
    proc.communicate()
    #, stdin=PIPE, stdout=PIPE

if not(installed):
    # Download
    download_dir = os.path.expanduser('~/Downloads')
    if not(os.access(download_dir, os.R_OK)):
      os.mkdir(download_dir)
    url='http://www.vtk.org/files/release/5.8/vtk-5.8.0.zip'
    filename=download_dir+'/'+'vtk-5.8.0.zip'
    print " Downloading " + filename
    if os.access(filename, os.R_OK):
        print "File seems to be already downloaded"
    else:
        urllib.urlretrieve(url,filename)
    # Extract
    vtk_extractdir = download_dir+'/VTK'
    if not(os.access(vtk_extractdir, os.R_OK)):
      os.mkdir(vtk_extractdir)
      print " Extracting " + filename+" in "+vtk_extractdir
      vtkzip = zipfile.ZipFile(filename)
      vtkzip.extractall(vtk_extractdir)
    # Compile
    # find cmake binary
    cmake_dir = 'C:\Program Files (x86)\CMake 2.8/bin'
    if not(os.access(cmake_dir, os.R_OK)):
        cmake_dir = 'C:\Program Files\CMake 2.8/bin'
        if not(os.access(cmake_dir, os.R_OK)):
            print "ERROR: cmake directory not found"
    # create build dir
    vtk_build_dir = vtk_extractdir+'/builds'
    if not(os.access(vtk_build_dir, os.R_OK)):
      os.mkdir(vtk_build_dir)
    # running cmake
    os.chdir(vtk_build_dir)
    os.putenv('PATH',cmake_dir)
    cmake_cmd =  'start "Configuring VTK with CMake" cmake.exe'
    cmake_cmd += ' -DBUILD_EXAMPLES=OFF'
    cmake_cmd += ' -DBUILD_TESTING=OFF'
    cmake_cmd += ' -DCMAKE_CONFIGURATION_TYPES=Release;Debug;MinSizeRel;RelWithDebInfo'
    cmake_cmd += ' -G \"Visual Studio 9 2008\"'
    cmake_cmd += ' ..'
    #-DCMAKE_BUILD_TYPE=Release'
    # changed order of configuration to try to get Release as default
    print cmake_cmd
    #+vtk_extractdir
    print "Configuring VTK project"
    #res=launchWithoutConsole('cmake.exe',['..'])
    res = os.popen(cmake_cmd).read()
    # need to run configuration command twice ???
    print res
    print "Now Building"
    #
    cmake_cmd_cmake = 'start "Compiling VTK with CMake"'
    cmake_cmd_cmake += 'cmake.exe --build .'
    #
    os.putenv('PATH',"C:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\vcpackages")
    cmake_cmd_vcbuild = 'start "Compiling VTK with vcbuild" vcbuild.exe VTK.sln "Release|Win32"'
    print cmake_cmd_vcbuild
    # don´t compile yet
    res = os.popen(cmake_cmd_vcbuild).read()
    print res
    #os.popen(cmake_cmd,stderr=sys.stdout, stdout=PIPE) 
else:
    print "VTK 5.8 seems already installed"

