[Setup]
AppName=AMILab
AppVerName=AMILab 2.0.3
AppCopyright=LGPL
DefaultDirName={pf}\AMILab
EnableDirDoesntExistWarning=True
OutputDir=K:\projects\Install\mingw-install\AMILab_build_release
OutputBaseFilename=amilab_2.0.3_setup
DefaultGroupName=AMILab
SourceDir=K:\projects\Install\mingw-install\
Compression=lzma/ultra
AllowNoIcons=True
AlwaysUsePersonalGroup=True
UsePreviousGroup=True
VersionInfoVersion=1.1
UninstallDisplayIcon=K:\projects\Sourceforge\amilab\trunk\Pixmaps\amilab_logo_new.ico,1
UninstallDisplayName=uninstall AMILab
UninstallFilesDir={group}
SolidCompression=True

[Languages]
Name: en; MessagesFile: compiler:Languages\English.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt
Name: en; MessagesFile: compiler:Default.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt
Name: de; MessagesFile: compiler:Languages\German.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt
Name: es; MessagesFile: compiler:Languages\Spanish.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt

[Dirs]
Name: {app}\Pixmaps; Flags: uninsalwaysuninstall
Name: {app}\bin; Permissions: admins-readexec; Flags: uninsalwaysuninstall
Name: {userprograms}\AMILab; Permissions: users-full; Flags: uninsalwaysuninstall

[Files]
Source: share\amilab-2.0.3\*; DestDir:  {app}; Flags: createallsubdirs recursesubdirs
Source: bin\*.dll; DestDir: {app}\bin; Permissions: everyone-readexec
Source: share\amilab-2.0.3\; DestDir:  {app}; Flags: createallsubdirs recursesubdirs
Source: bin\amilab_2.0.3_release.exe; DestDir: {app}\bin; Permissions: everyone-readexec; Flags: 32bit nocompression; MinVersion: 4.1.1998,4.0.1381
Source: K:\projects\Sourceforge\amilab\trunk\Pixmaps\amilab_logo_new.ico; DestDir: {app}\Pixmaps
Source: K:\projects\Sourceforge\amilab\\trunk\Pixmaps\amilab_logo_new.xpm; DestDir: {app}\Pixmaps; Permissions: users-full

[Icons]
Name: {userdesktop}\AMILab; Filename: {app}\bin\amilab_2.0.3_release.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new.ico
Name: {group}\AMILab; Filename: {app}\bin\amilab_2.0.3_release.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new.ico
