
import urllib,urllib2
import os,platform
from check_windows_installed_products import *

products = get_installed_products()
installed=False
for p in products:
    if p.ProductName.startswith('TortoiseSVN 1.7'):
        print "Found '"+p.ProductName+"'"
        installed=True

if not(installed):
    download_dir = os.path.expanduser('~/Downloads')
    if not(os.access(download_dir, os.R_OK)):
      os.mkdir(download_dir)
    if platform.architecture()[0]=='32bit':
        # for the 32 bits version
        url='http://downloads.sourceforge.net/tortoisesvn/TortoiseSVN-1.7.1.22161-win32-svn-1.7.1.msi?download'
        filename=download_dir+'/'+'TortoiseSVN-1.7.1.22161-win32-svn-1.7.1.msi'
        if platform.architecture()[0]=='64bit':
        # for the 64 bits version
        url='http://downloads.sourceforge.net/tortoisesvn/TortoiseSVN-1.7.1.22161-x64-svn-1.7.1.msi?download'
        filename=download_dir+'/'+'TortoiseSVN-1.7.1.22161-x64-svn-1.7.1.msi'
    print filename
    urllib.urlretrieve(url,filename)
    os.system(filename)
else:
    print "TortoiseSVN 1.7 seems already installed"
