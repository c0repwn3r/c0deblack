# c0deblack
Windows exploit toolkit. Under construction.

## What is blackf8/c0deblack
Blackf8 is not an exploit. It is several. blackf8 is the core exploitation kit behind the c0deblack customization tool.

## Warning
Do **NOT** download blackf8 or c0deblack from **ANY** websiite or repository other then the two official ones located at:
- https://github.com/coredoescode/c0deblack

It is **EXTREMELY EASY** to create a rootkit from this software. ONLY TRUST OFFICIAL RELEASES, and don't even trust those, compile the program from source yourself.

## Disclaimer
blackf8 and c0deblack are inheritley dangerous. They modify system files and overwrite the bootloader, as well as hijack parts of the operating system. To the perspective of an antivirus, it looks like a rootkit, because thats exactly what blackf8 is. Blackf8 **IS** a rootkit, simply one without malicious intentions. Don't install things you dont trust, that is why the source code is provided. While data loss is unlikely, make a backup aynway, because stuff can go wrong with the things this tool does. We are **not** responsible for any data loss due to use of this tool.

## How it works
blackf8 contains several main exploits, known as modules:
(^ denotes an exploit that requires a reboot to setup or run, * denotes an exploit that requires CLB mode to setup or run)
- UEFIHack (ml.coresdev.blackf8.blackf8_uefi) ^
- SysModuleRunner (ml.coresdev.blackf8.blackf8_servicerun) \*
- WinFSMod (ml.coresdev.blackf8.blackf8_allfileaccess) \*
- Unremove (ml.coresdev.blackf8.blackf8_unremove)
- DiskEdit (ml.coresdev.blackf8.blackf8_diskmod) \*
- PkgLoader (ml.coresdev.blackf8.blackf8_pkgload) \*
- ProgramHider (ml.coresdev.blackf8.blackf8_semikit) \*
- Blackout (ml.coresdev.blackf8.blackf8_blackout) \* ^
- USBInterface (ml.coresdev.blackf8.blackf8_iusb) 
- CLBMode (ml.coresdev.blackf8.blackf8_clbexploit)
- uefiboot (ml.coresdev.blackf8.blackf8_uefiboot)

### Where is the soruce code for those?
Currently unavaliable, will be released once I figure out how to create symbolic links in Git.

## Requirements
- Any windows 10 version
- NT Kernel version 10.0 or above
- Secure boot **disabled** (unless you know how to sign EFI stuff)
- Antivirus should be disabled for installation of exploits, but can be re-enabled afterwards
- UEFI Boot scheme (for UEFIhack and kernel modifications)
