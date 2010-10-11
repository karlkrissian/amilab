[Setup]
AppName=AMILab_3.0.0
AppVerName=AMILab 3.0.0
AppCopyright=LGPL
DefaultDirName={pf}\AMILab_3.0.0
EnableDirDoesntExistWarning=True
OutputDir=I:\AMILabCompilationWindows\Setup\
OutputBaseFilename=amilab_3.0.0_setup
DefaultGroupName=AMILab_3.0.0
SourceDir=I:\AMILabCompilationWindows\Install\
Compression=lzma/ultra
AllowNoIcons=True
AlwaysUsePersonalGroup=True
UsePreviousGroup=True
VersionInfoVersion=1.1
UninstallDisplayIcon=I:\AMILabCompilationWindows\Sourceforge\amilab_trunk\Pixmaps\amilab_logo_new_64x64_alpha.ico,1
UninstallDisplayName=uninstall AMILab
UninstallFilesDir={group}
SolidCompression=True

[Languages]
Name: en; MessagesFile: compiler:Default.isl; LicenseFile: I:\AMILabCompilationWindows\Sourceforge\amilab_trunk\src\Copyright.txt
Name: de; MessagesFile: compiler:Languages\German.isl; LicenseFile: I:\AMILabCompilationWindows\Sourceforge\amilab_trunk\src\Copyright.txt
Name: es; MessagesFile: compiler:Languages\Spanish.isl; LicenseFile: I:\AMILabCompilationWindows\Sourceforge\amilab_trunk\src\Copyright.txt

[Dirs]
Name: {app}\Pixmaps; Flags: uninsalwaysuninstall
Name: {app}\bin; Permissions: admins-readexec; Flags: uninsalwaysuninstall
Name: {app}\share\amilab-3.0.0; Flags: uninsalwaysuninstall
Name: {userprograms}\AMILab_3.0.0; Permissions: users-full; Flags: uninsalwaysuninstall

[Files]
Source: share\amilab-3.0.0\*; DestDir: {app}\share\amilab-3.0.0; Flags: createallsubdirs recursesubdirs
Source: bin\*.dll; DestDir: {app}\bin; Permissions: everyone-readexec
Source: bin\amilab_3.0.0.exe; DestDir: {app}\bin; Permissions: everyone-readexec; Flags: 32bit nocompression; MinVersion: 4.1.1998,4.0.1381
Source: I:\AMILabCompilationWindows\Sourceforge\amilab_trunk\Pixmaps\amilab_logo_new_64x64_alpha.ico; DestDir: {app}\Pixmaps

[Icons]
Name: {userdesktop}\AMILab_3.0.0; Filename: {app}\bin\amilab_3.0.0.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new_64x64_alpha.ico
Name: {group}\AMILab_3.0.0; Filename: {app}\bin\amilab_3.0.0.exe; WorkingDir: {app}; IconFilename: {app}\Pixmaps\amilab_logo_new_64x64_alpha.ico

