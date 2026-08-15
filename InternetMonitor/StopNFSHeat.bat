@echo off

set "APP_NAME=F:\SteamLibrary\steamapps\common\Need for Speed Heat\NeedForSpeedHeat.exe"
set "RULE_NAME=Block Internet Access for %APP_NAME%"

rem Check if the outbound rule already exists for blocking internet access for the specified application
netsh advfirewall firewall show rule name="%RULE_NAME%" >nul 2>&1
if %errorlevel% equ 0 (
    echo Unblock internet access for %APP_NAME%...
    rem Delete the outbound rule from Windows Firewall to unblock internet traffic for the specified application
    netsh advfirewall firewall delete rule name="%RULE_NAME%" >nul
    echo Internet access unblocked for %APP_NAME%.
) else (
    echo Block internet access for %APP_NAME%...
    rem Add outbound rule to Windows Firewall to block internet traffic for the specified application
    netsh advfirewall firewall add rule name="%RULE_NAME%" dir=out action=block program="%APP_NAME%" enable=yes >nul
    echo Internet access blocked for %APP_NAME%.
)

pause