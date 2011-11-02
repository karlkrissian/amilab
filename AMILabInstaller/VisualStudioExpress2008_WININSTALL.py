
# trying to install visual studio 2008 express
print "**"

import urllib,urllib2
import os
from check_windows_installed_products import *

products = get_installed_products()
installed=False
for p in products:
    if p.ProductName.startswith('Microsoft Visual C++'):
        print "Found '"+p.ProductName+"'"
        installed=True

if not(installed):
    download_dir = os.path.expanduser('~/Downloads')
    if not(os.access(download_dir, os.R_OK)):
      os.mkdir(download_dir)
    # installing Visual Studio Express 2008 (if the link is still correct)
    urllib.urlretrieve('http://go.microsoft.com/?linkid=7729279',download_dir+'/vcsetup.exe')
    os.system(download_dir+'/vcsetup.exe')

    # Install the Windows SDK
    # to check
    urllib.urlretrieve('http://www.microsoft.com/download/en/confirmation.aspx?id=11310',download_dir+'/Setup.exe')
    os.system(download_dir+'/Setup.exe')
else:
    print "Microsoft Visual Studio seems already installed"

print "**"
