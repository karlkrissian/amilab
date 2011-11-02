
import urllib,urllib2
import os,platform

from check_windows_installed_products import *

products = get_installed_products()
installed=False
for p in products:
    if p.ProductName.startswith('CMake 2.8'):
        print "Found '"+p.ProductName+"'"
        installed=True

if not(installed):
    download_dir = os.path.expanduser('~/Downloads')
    if not(os.access(download_dir, os.R_OK)):
      os.mkdir(download_dir)
    url='http://www.cmake.org/files/v2.8/cmake-2.8.6-win32-x86.exe'
    filename=download_dir+'/'+'make-2.8.6-win32-x86.exe'
    print filename
    urllib.urlretrieve(url,filename)
    os.system(filename)
else:
    print "CMake 2.8 seems already installed"
