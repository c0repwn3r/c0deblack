/*
                       .oodMMMMMMMMMMMMM
           ..oodMMM  MMMMMMMMMMMMMMMMMMM
     oodMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   **************************************
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   *       The C0deblack Project        *
                                           *    Made with <3 by coredoescode    *
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   *  Pioneering windows customization  *
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   **************************************
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM
     `^^^^^^MMMMMMM  MMMMMMMMMMMMMMMMMMM
           ````^^^^  ^^MMMMMMMMMMMMMMMMM
                          ````^^^^^^MMMM
*/

#include <iostream>
#include "Colors.h"
#include "WinReg.hpp"
#include <limits>

using namespace std;

namespace blackf8scan {
    bool SecureBootEnabled() {
        winreg::RegKey SecureBootState{ HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\SecureBoot\\State" };
        DWORD UEFISecureBootEnabled = SecureBootState.GetDwordValue(L"UEFISecureBootEnabled");
        if ((int)UEFISecureBootEnabled == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    int IsUEFIMachine() {
        FIRMWARE_TYPE FirmwareType;
        GetFirmwareType(&FirmwareType);
        if (FirmwareType == FirmwareTypeUnknown) {
            return -1;
        }
        else if (FirmwareType == FirmwareTypeMax) {
            return -2;
        }
        else if (FirmwareType == FirmwareTypeBios) {
            return 1;
        }
        else if (FirmwareType == FirmwareTypeUefi) {
            return 0;
        }
    }
    bool CLBModeFunctional() {
        winreg::RegKey blackf8keylocation{ HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control" };
        if (auto isClbDisabled = blackf8keylocation.TryGetDwordValue(L"BlackF8CLBDisabled")) {
            // Key exists, check its value
            if (isClbDisabled == 1) {
                // CLB mode is disabled or nonfunctional on this machine
            }
            else {
                // CLB mode is enabled
                return true;
            }
        }
        else {
            // Key does not exist
            return true;
        }
    }
    bool IsBlackF8Active() {
        winreg::RegKey blackf8keylocation{ HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control" };
        if (auto isExploitActive = blackf8keylocation.TryGetDwordValue(L"BlackF8Injected")) {
            // The key exists, check its value
            if (isExploitActive == 1) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            // Key does not exist
            return false;
        }
    }
}


int main()
{

    // Banner (but colored because it isnt in code)
    cout << BOLDBLUE << "                       .oodMMMMMMMMMMMMM" << endl;
    cout << "           ..oodMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     oodMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   " << RESET << "**************************************" << endl;
    cout << BOLDBLUE << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   " << RESET << "*       The C0deblack Project        *" << endl;
    cout << BOLDBLUE << "                                           " << RESET << "*    Made with <3 by coredoescode    *" << endl;
    cout << "     " << BOLDRED << "MMMMMMMMMMMMMM  " << BOLDBLUE << "MMMMMMMMMMMMMMMMMMM   " << RESET << "*  Pioneering windows customization  *" << endl;
    cout << "     " << BOLDRED << "MMMMMMMMMMMMMM  " << BOLDBLUE << "MMMMMMMMMMMMMMMMMMM   " << RESET << "**************************************" << endl;
    cout << "     " << BOLDRED << "MMMMMMMMMMMMMM  " << BOLDBLUE << "MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     " << RED << "MMMMMMMMMMMMMM  " << BOLDBLUE << "MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     " << RED << "MMMMMMMMMMMMMM  " << BOLDBLUE << "MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     " << RED << "`^^^^^^MMMMMMM  " << BOLDBLUE << "MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "           " << RED << "````^^^^  " << BOLDBLUE << "^^MMMMMMMMMMMMMMMMM" << endl;
    cout << "                          " << BOLDBLUE << "````^^^^^^MMMM" << RESET << endl;
    // Now that we are done with that absolute mess of code, lets get to the actual interface
    cout << RESET << endl;
    cout << "Welcome to C0deblack!" << endl;
    cout << "Please wait, scanning your device" << endl;
    cout << "[1/5] Scanning version information";
    winreg::RegKey CurrentVersion{ HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion" };
    const int MajorVersion = CurrentVersion.GetDwordValue(L"CurrentMajorVersionNumber");
    const int MinorVersion = CurrentVersion.GetDwordValue(L"CurrentMinorVersionNumber");
    const wstring BuildNumber = CurrentVersion.GetStringValue(L"CurrentBuildNumber");
    cout << LINERESET;
    Sleep(420);
    cout << "[2/5] Scanning boot information          ";
    const int uefiMode = blackf8scan::IsUEFIMachine();
    if (uefiMode == 0) {
        // UEFI is enabled, so we should check for secure boot]
        const bool isSecureBootEnabled = blackf8scan::SecureBootEnabled();
    }
    else {
        // UEFI is not enabled, this will throw a fail condition after the scan
    }
    cout << LINERESET;
    Sleep(420);
    cout << "[3/5] Checking to see if CLB mode will work";
    const bool CLBModeEnabled = blackf8scan::CLBModeFunctional();
    cout << LINERESET;
    Sleep(420);
    cout << "[4/5] Scanning product information             ";
    const wstring ProductName = CurrentVersion.GetStringValue(L"ProductName");
    cout << LINERESET;
    Sleep(420);
    cout << "[5/5] Scanning for existing blackf8 exploitation" << endl;
    const bool isBlackF8Active = blackf8scan::IsBlackF8Active();
    cout << "Scan completed" << endl;
    if (MajorVersion == 10) {
        string pname(ProductName.begin(), ProductName.end());
        string buildnum(BuildNumber.begin(), BuildNumber.end());
        cout << "NT " << MajorVersion << "." << MinorVersion << endl;
        cout << pname << " build " << buildnum << endl;
    }
    else {
        cout << "Sorry, NT " << MajorVersion << "." << MinorVersion << " is not supported." << endl;
        return -1;
    }
    if (uefiMode == -1) {
        cout << "Sorry, BIOS_FIRMWARE_UNKNOWN is not supported." << endl;
        return -1;
    }
    else if (uefiMode == -2) {
        cout << "Sorry, BIOS_FIRMWARE_MAX is not supported." << endl;
        return -1;
    }
    else if (uefiMode == 1) {
        cout << "Sorry, LEGACY BIOS is not supported." << endl;
        return -1;
    }
    else {
        cout << "[*] Running on UEFI BIOS - good" << endl;
        bool secure = blackf8scan::SecureBootEnabled();
        if (secure) {
            cout << "[x] Sorry, this exploit will not function with Secure Boot enabled. Please disable it and try again." << endl;
            return -1;
        }
        else {
            cout << "[*] Secure boot is disabled - good" << endl;
        }
    }
    if (CLBModeEnabled == false) {
        cout << "[x] Sorry, CLB mode is unsupported or disabled on your system." << endl;
        return -1;
    }
    else {
        cout << "[*] CLB mode is supported - good" << endl;
    }
    if (isBlackF8Active == true) {
        cout << "[-] Device is already c0deblacked - if you are re-blacking, you can keep going, but it is recommended that you remove the exploit before re-installing it." << endl;
    }
    else {
        cout << "[*] Device is not c0deblacked - everything looks good to exploit" << endl;
    }
    cout << "[-] Please DISABLE YOUR ANTIVIRUS. This exploit modifies system files and it is VERY COMMON for it to come up as a false positive. Continuing with an enabled antivirus could leave your system in an unusable state. Disable your antivirus and press enter to continue." << endl;
    cin.ignore();
    cout << "[*] Ready to exploit! Press enter to begin." << endl;
    cin.ignore();
    cout << endl;
    cout << "[1] Prepare your device for blackf8" << endl;
    cout << "[*] Please save all of your work and close all other programs. This will allow the exploit to modify system files as needed." << endl;
    cout << "[-] Once you have done this, press enter" << endl;
    cin.ignore();
    cout << "[2] Copy blackf8 files" << endl;
    cout << "[*] All files copied." << endl;
    cout << "[3] Run the exploit" << endl;
    cout << "[-] Enabling CLB mode" << endl;
    cout << "[*] Restarting in 5...\r";
    Sleep(1000);
    cout << "[*] Restarting in 4...\r";
    Sleep(1000);
    cout << "[*] Restarting in 3...\r";
    Sleep(1000);
    cout << "[*] Restarting in 2...\r";
    Sleep(1000);
    cout << "[*] Restarting in 1...\r";
    Sleep(1000);
}
