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
#include <filesystem>

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
    cout << "                       .oodMMMMMMMMMMMMM" << endl;
    cout << "           ..oodMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     oodMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   **************************************" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   *       The C0deblack Project        *" << endl;
    cout << "                                           *    Made with <3 by coredoescode    *" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   *  Pioneering windows customization  *" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM   **************************************" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "     `^^^^^^MMMMMMM  MMMMMMMMMMMMMMMMMMM" << endl;
    cout << "           ````^^^^  ^^MMMMMMMMMMMMMMMMM" << endl;
    cout << "                          ````^^^^^^MMMM" << endl;
    // Now that we are done with that absolute mess of code, lets get to the actual interface
    cout << endl;
    cout << "Welcome to C0deblack!" << endl;
    cout << "Running in " << filesystem::current_path();
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
    cout << "[2] Start UEFI exploit" << endl;
    cout << "[*] Please install blackf8_uefi by following the insturctions provided in the window." << endl;
    cout << "[*] Once finished, simply close the window." << endl;
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;
    CreateProcess(L".\\Modules\\blackf8_uefi\\setup.exe", NULL, 0, 0, 0, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    cout << "[*] blackf8_uefi installer closed. Prepping device for entry into DCL/CLB mode" << endl;
    cout << "[*] Copying files" << endl;
    cout << "[*] Setting flags for DCL mode" << endl;
    cout << "[*] Opening HKLM register" << endl;
    winreg::RegKey systemsetup{ HKEY_LOCAL_MACHINE, L"System\\Setup" };
    winreg::RegKey policies{ HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System" };
    cout << "[*] Changing system setup information" << endl;
    systemsetup.SetStringValue(L"CmdLine", L"cmd.exe /k C:\\blackf8\\stage4.bat");
    systemsetup.SetDwordValue(L"SystemSetupInProgress", 1);
    systemsetup.SetDwordValue(L"SetupType", 2);
    cout << "[*] Changing policies" << endl;
    policies.SetDwordValue(L"EnableCursorSuppression", 0);
    policies.SetDwordValue(L"EnableLUA", 0);
    policies.SetDwordValue(L"VerboseStatus", 1);
    /*
    systemsetup.SetStringValue(L"CmdLine", L"");
    systemsetup.SetDwordValue(L"SystemSetupInProgress", 0);
    systemsetup.SetDwordValue(L"SetupType", 0);
    cout << "[*] Changing policies" << endl;
    policies.SetDwordValue(L"EnableCursorSuppression", 1);
    policies.SetDwordValue(L"EnableLUA", 1);
    policies.SetDwordValue(L"VerboseStatus", 0);
    */
    cout << "[*] DCL mode is enabled, now we need to reboot" << endl;
    cout << "[*] Time to hope this works - rebooting in 5..." << endl;
    Sleep(1);
    cout << "[*] Time to hope this works - rebooting in 4..." << endl;
    Sleep(1);
    cout << "[*] Time to hope this works - rebooting in 3..." << endl;
    Sleep(1);
    cout << "[*] Time to hope this works - rebooting in 2..." << endl;
    Sleep(1);
    cout << "[*] Time to hope this works - rebooting in 1..." << endl;
    Sleep(1);
    cout << "[*] Trying to reboot" << endl;
    system("shutdown /f /r /t 0");
    Sleep(1);
    cout << "[*] Sent the reboot command, why are we still here?!" << endl;
    Sleep(5);
    cout << "[*] At this point we absolutely should have restarted, try disabling antivirus. -core" << endl;
    cout << "[*] If that dosn't work, make sure your binary version is supported." << endl;
    cout << "Press any key to exit." << endl;
    cin.ignore();
    
}
