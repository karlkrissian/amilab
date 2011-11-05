
# trying to install visual studio 2008 express
print "**"

import urllib,urllib2
import os
from check_windows_installed_products import *
#from Tkinter import *

products = get_installed_products()
installed_cpp=False
installed_sdk=False

#root = Tk()
#root.mainloop()

for p in products:
    #print p.ProductName
    if p.ProductName.startswith('Microsoft Visual C++'):
        print "Found '"+p.ProductName+"'"
        installed_cpp=True
    if p.ProductName.startswith('Microsoft Windows SDK for Visual Studio 2008'):
        print "Found '"+p.ProductName+"'"
        installed_sdk=True

#def MessageBox(mtext):
#    root.title('Message')
#    Message(root, text=mtext, bg='royalblue',
#          fg='ivory', relief=GROOVE).pack(padx=10, pady=10)
#installed=False
if not(installed_cpp):
    download_dir = os.path.expanduser('~/Downloads')
    if not(os.access(download_dir, os.R_OK)):
      os.mkdir(download_dir)
    # installing Visual Studio Express 2008 (if the link is still correct)
    urllib.urlretrieve('http://go.microsoft.com/?linkid=7729279',download_dir+'/vcsetup.exe')
    os.system(download_dir+'/vcsetup.exe')
else:
    print "** Microsoft Visual Studio seems already installed"

if not(installed_sdk):
    # Install the Windows SDK
    # to check
    print "You need to install Windows SDK from the browser ..."
    import webbrowser
    webbrowser.open('http://www.microsoft.com/download/en/confirmation.aspx?id=11310')
    #urllib.urlretrieve('http://www.microsoft.com/download/en/confirmation.aspx?id=11310',download_dir+'/Setup.exe')
    #os.system(download_dir+'/Setup.exe')
else:
    print "** Microsoft Windows SDK for Visual Studio 2008 seems already installed"

print "**"
