[Setup]
AppName=AMILab
AppVerName=AMILab ${version}
AppCopyright=LGPL
DefaultDirName={pf}\AMILab
EnableDirDoesntExistWarning=True
OutputDir=K:\projects\Install\mingw-install\AMILab_build
OutputBaseFilename=amilab_${version}_setup
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
Name: en; MessagesFile: compiler:Default.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt
Name: de; MessagesFile: compiler:Languages\German.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt
Name: es; MessagesFile: compiler:Languages\Spanish.isl; LicenseFile: K:\projects\Sourceforge\amilab\trunk\src\Copyright.txt

[Dirs]
Name: {app}\Pixmaps; Flags: uninsalwaysuninstall
Name: {app}\bin; Permissions: admins-readexec; Flags: uninsalwaysuninstall
Name: {app}\share\amilab-${version}; Flags: uninsalwaysuninstall
Name: {userprograms}\AMILab; Permissions: users-full; Flags: uninsalwaysuninstall

[Files]
Source: share\amilab-${version}\*; DestDir: {app}\share\amilab-${version}; Flags: createallsubdirs recursesubdirs
Source: bin\*.dll; DestDir: {app}\bin; Permissions: everyone-readexec
Source: bin\amilab_${version}_${buildtype}.exe; DestDir: {app}\bin; Permissions: everyone-readexec; Flags: 32bit nocompression; MinVersion: 4.1.1998,4.0.1381
Source: K:\projects\Sourceforge\amilab\trunk\Pixmaps\amilab_logo_new.ico; DestDir: {app}\Pixmaps
Source: K:\projects\Sourceforge\amilab\trunk\Pixmaps\amilab_logo_new.xpm; DestDir: {app}\Pixmaps; Permissions: users-full

[Icons]
Name: {userdesktop}\AMILab; Filename: {app}\bin\amilab_${version}_${buildtype}.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new.ico
Name: {group}\AMILab; Filename: {app}\bin\amilab_${version}_${buildtype}.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new.ico
