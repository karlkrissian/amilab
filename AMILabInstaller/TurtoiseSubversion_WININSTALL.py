
import urllib,urllib2
import os,platform

download_dir = os.path.expanduser('~/Downloads')

if not(os.access(download_dir, os.R_OK):
  os.mkdir(download_dir)


# for the 32 bits version
url='http://downloads.sourceforge.net/tortoisesvn/TortoiseSVN-1.7.1.22161-win32-svn-1.7.1.msi?download'
filename=download_dir+'/'+'TortoiseSVN-1.7.1.22161-win32-svn-1.7.1.msi'

urllib.urlretrieve(url,filename)
os.system(filename)
