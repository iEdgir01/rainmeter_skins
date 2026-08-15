@echo off
rem Safe network toggle - only affects LAN adapter (connected to MikroTik)
rem Ping Google's public DNS server to check connectivity
ping 8.8.8.8 -n 1 > nul

if %errorlevel% equ 0 (
    rem Connected - release only LAN
    ipconfig /release "LAN" > nul
    timeout /t 2 /nobreak > nul
) else (
    rem Disconnected - renew only LAN
    ipconfig /renew "LAN" > nul
)