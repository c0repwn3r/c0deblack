@echo off
echo Updating module UEFIHack...
echo Resolving package
echo ml.coresdev.blackf8.blackf8_uefi returns module.plist version 4
echo CDN zipfile: https://drive.google.com/file/d/1PQM9FuXTHa5-yOjPgSAis983lYZeIloo/view?usp=sharing
echo Removing files
echo blackf8-update --clean --module=ml.coresdev.blackf8.blackf8_uefi ----keep=config.txt;LICENCE;module.plist;splash.bmp
echo Removing blackf8-1.5.1-1-g4cf12f2.zip
del /f blackf8-1.5.1-1-g4cf12f2.zip
echo Removing bootia32.efi
del /f bootia32.efi
echo Removing bootx64.efi
del /f bootx64.efi
echo Removing CHANGELOG.md
del /f CHANGELOG.md
echo KEEPING config.txt (--keep=config.txt;LICENCE;module.plist;splash.bmp)
echo KEEPING LICENCE
echo KEEPING module.plist
echo Removing README.efilib
del /f README.efilib
echo Removing README.md
del /f README.md
echo Removing setup.exe
del /f setup.exe
echo KEEPING splash.bmp
echo Clean completed
echo Press any key to continue
pause
echo Downloading file
curl https://drive.google.com/file/d/1PQM9FuXTHa5-yOjPgSAis983lYZeIloo/view?usp=sharing -o blackf8-1.5.1-1-g4cf12f2.zip
echo Extracting to C:\Temp
call :unzip "C:\Temp\" "%CD%\blackf8-1.5.1-1-g4cf12f2.zip"
xcopy /s C:\Temp %CD%
PAUSE

:unzip <ExtractTo> <newzipfile>
set vbs="%temp%\_.vbs"
if exist %vbs% del /f /q %vbs%
>%vbs%  echo Set fso = CreateObject("Scripting.FileSystemObject")
>>%vbs% echo If NOT fso.FolderExists(%1) Then
>>%vbs% echo fso.CreateFolder(%1)
>>%vbs% echo End If
>>%vbs% echo set objShell = CreateObject("Shell.Application")
>>%vbs% echo set FilesInZip=objShell.NameSpace(%2).items
>>%vbs% echo objShell.NameSpace(%1).CopyHere(FilesInZip)
>>%vbs% echo Set fso = Nothing
>>%vbs% echo Set objShell = Nothing
cscript //nologo %vbs%
if exist %vbs% del /f /q %vbs%