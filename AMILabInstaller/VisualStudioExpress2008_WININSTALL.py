
# trying to install visual studio 2008 express

import urllib,urllib2
import os

download_dir = os.path.expanduser('~/Downloads')

if not(os.access(download_dir, os.R_OK):
  os.mkdir(download_dir)

# installing Visual Studio Express 2008 (if the link is still correct)
urllib.urlretrieve('http://go.microsoft.com/?linkid=7729279',download_dir+'/vcsetup.exe')
os.system(download_dir+'/vcsetup.exe')
