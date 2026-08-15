@echo off
:: Toggle Steam access based on existing firewall rules

:: Define the Steam executable path (change if necessary)
set "APP_PATH=C:\Program Files (x86)\Steam\steam.exe"
set "RULE_NAME=BlockSteam"

:: Check if the outbound rule already exists for blocking internet access for the specified application
netsh advfirewall firewall show rule name="%RULE_NAME%" >nul 2>&1
if %errorlevel% equ 0 (
    echo Unblocking internet access for Steam...
    :: Delete the outbound rule from Windows Firewall to unblock internet traffic for the specified application
    netsh advfirewall firewall delete rule name="%RULE_NAME%" >nul
    echo Internet access unblocked for Steam.
) else (
    echo Blocking internet access for Steam...
    :: Add outbound rule to Windows Firewall to block internet traffic for the specified application
    netsh advfirewall firewall add rule name="%RULE_NAME%" dir=out action=block program="%APP_PATH%" enable=yes >nul
    echo Internet access blocked for Steam.
)