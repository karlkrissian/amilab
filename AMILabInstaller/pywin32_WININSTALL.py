
import urllib,urllib2
import os,platform

download_dir = os.path.expanduser('~/Downloads')

pywin_installed=True
try:
  import pywin
except:
  print "'import pywin' failed"
  pywin_installed=False
  

if not(pywin_installed):
  if not(os.access(download_dir, os.R_OK)):
    os.mkdir(download_dir)

  if platform.architecture()[0]=='32bit':
      # for the 32 bits version
      url='http://sourceforge.net/projects/pywin32/files/pywin32/Build216/pywin32-216.win32-py2.7.exe/download'
      filename=download_dir+'/'+'pywin32-216.win32-py2.7.exe/dow'
      
  if platform.architecture()[0]=='64bit':
      # for the 64 bits version
      url='http://sourceforge.net/projects/pywin32/files/pywin32/Build216/pywin32-216.win-amd64-py2.7.exe/download'
      filename=download_dir+'/'+'pywin32-216.win-amd64-py2.7.exe'

  print filename
  urllib.urlretrieve(url,filename)
  os.system(filename)
else:
  print "  pywin is already installed"
