The C0deBlack Project
By @coredoescode

--- Welcome to C0deBlack! ---

 -- What is C0deBlack --
C0deBlack (Abbreviated as C0B) is a tweak tool designed to allow you mostly complete control
of your Windows System. It provides a way to modify system files, run code files mid-boot,
and enter CLB mode.

 -- How it works --
C0deBlack is based off of the blackf8 (pronounced 'blackfate') tool. A detailed explanation can be found in the 'Magic hax (or blackf8)' section below, but here is a basic overview:

- User starts the c0deblack.exe file
- c0deblack installs the blackf8 files to C:\Windows\System32\blackf8
- c0deblack prepares the device for entry into CLB mode, then restarts the device
- CLB mode is enabled automatically
- CLB mode reads C:\Windows\System32\clb.inf, which instructs the shell to run C:\Windows\System32\blackf8\startup.bat
- Startup.bat prints the following message to the screen:
+--------------------------------+
|      The C0deblack Project     |
|  Run blackf8\exploit to start  |
+--------------------------------+
- The user types in blackf8\exploit then hits enter
- At this point, the exploit is automatic
- UEFI data is changed to a custom UEFI file
- Checkmate. We have complete control over the system now.
- Boot image is changed to the c0deblack logo
- Some registry modifications
- Blackf8 service is created but not started
- The c0deblack loader is placed on the desktop
- The blackf8 controller is placed on the desktop
- CLB mode is disabled by blackf8
- The device restarts, c0deblacked

 -- What are "modules"? --
Modules are different pieces of code that can be loaded either A) during the c0deblacking process B) during the boot sequence of a c0deblacked machine or C) after boot. There are four core modules, which cannot be removed:
- UEFIMod (Source coredoescode, by coredoescode) - This module modifies the UEFI firmware to allow custom UEFI plugins.
- c0deblack (Source coredoescode, by coredoescode) - This module provides a frontend to the blackf8 exploit tool.
- blackf8 (Source coredoescode, by coredoescode) - This is the blackf8 windows exploitation tool.
- LoaderController (Source coredoescode, by coredoescode) - This is the module loader and exploit controller applications for c0deblack and blackf8 respectivley.
Each module has a repository file, which is a .bf8 file containing all the information for the module. The core module repository files can be found below:
https://repo.coresdev.ml/c0deblack/module/uefimod.bf8
https://repo.coresdev.ml/c0deblack/module/c0deblack.bf8
https://repo.coresdev.ml/c0deblack/module/blackf8.bf8
https://repo.coresdev.ml/c0deblack/module/loadercontroller.bf8
These modules are always included by the blackf8 exploit, in this order:
- Upon UI start:
* Load c0deblack.bf8 (Already installed on system)
- Upon exploit start:
* Load blackf8.bf8 (Already installed on system)
- Upon boot into CLB mode:
* Load UEFIMod.bf8 (Already installed on system)
- Upon reboot after c0deblacking:
* Load LoaderController.bf8 (Already installed on system)

 -- How to use --