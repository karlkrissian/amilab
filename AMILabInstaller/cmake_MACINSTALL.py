
import urllib,urllib2
import os,platform


cmake_path1='/usr/share/cmake-2.8'
cmake_path2='/usr/local/share/cmake-2.8'
installed=False
if os.access(cmake_path1, os.R_OK) or os.access(cmake_path2, os.R_OK):
    installed=True

if not(installed):
    download_dir = os.path.expanduser('~/Downloads')
    if not(os.access(download_dir, os.R_OK)):
      os.mkdir(download_dir)
    url='http://www.cmake.org/files/v2.8/cmake-2.8.6-Darwin-universal.dmg'
    filename=download_dir+'/'+'cmake-2.8.6-Darwin-universal.dmg'
    print "downloading {0} to {1}".format(url,filename)
    urllib.urlretrieve(url,filename)
    os.system('sudo installer -pkg {0} -target /'.format(filename))
else:
    print "CMake 2.8 seems already installed"
