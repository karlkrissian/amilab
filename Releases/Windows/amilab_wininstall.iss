[Setup]
AppName=AMILab
AppVerName=AMILab 2.0.1
AppCopyright=LGPL
DefaultDirName={pf}\AMILab
EnableDirDoesntExistWarning=True
OutputDir=K:\projects\Install\mingw-install\AMILab_build
SignedUninstallerDir=C:\Devel\FLUID_REP\Karl
OutputBaseFilename=amilab_setup
DefaultGroupName=AMILab
SourceDir=K:\projects\Install\mingw-install\
Compression=lzma/normal
AllowNoIcons=True
AlwaysUsePersonalGroup=True
UsePreviousGroup=True
VersionInfoVersion=1.1
UninstallDisplayIcon=K:\projects\Sourceforge\amilab\Pixmaps\amilab_logo_new.ico,1
UninstallDisplayName=uninstall AMILab
UninstallFilesDir={group}

[Languages]
Name: en; MessagesFile: compiler:Languages\English.isl
Name: es; MessagesFile: compiler:Languages\Spanish.isl
Name: fr; MessagesFile: compiler:Languages\French.isl
Name: de; MessagesFile: compiler:Languages\German.isl

[Dirs]
Name: {app}\Pixmaps; Flags: uninsalwaysuninstall
Name: {app}\bin; Permissions: admins-readexec; Flags: uninsalwaysuninstall
Name: {userprograms}\AMILab; Permissions: users-full; Flags: uninsalwaysuninstall

[Files]
Source: bin\AMILab_scripts_doc\*; DestDir:  {app}; Flags: createallsubdirs recursesubdirs
Source: bin\*.dll; DestDir: {app}\bin; Permissions: everyone-readexec
Source: bin\AMILab_scripts_doc; DestDir:  {app}; Flags: createallsubdirs recursesubdirs
Source: bin\amilab_bin.exe; DestDir: {app}\bin; Permissions: everyone-readexec; Flags: 32bit nocompression; MinVersion: 4.1.1998,4.0.1381
Source: K:\projects\Sourceforge\amilab\Pixmaps\amilab_logo_new.ico; DestDir: {app}\Pixmaps
Source: K:\projects\Sourceforge\amilab\Pixmaps\amilab_logo_new.xpm; DestDir: {app}\Pixmaps; Permissions: users-full

[Icons]
Name: {userdesktop}\AMILab; Filename: {app}\bin\amilab_bin.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new.ico
Name: {group}\AMILab; Filename: {app}\bin\amilab_bin.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new.ico
