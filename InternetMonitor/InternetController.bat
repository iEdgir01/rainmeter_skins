@echo off

rem Ping Google's public DNS server (8.8.8.8) to check network connectivity
ping 8.8.8.8 -n 1 > nul
if %errorlevel% equ 0 (
    set "connectionState=Connected"
) else (
    set "connectionState=Disconnected"
)

rem If the connection is currently connected, disconnect it; otherwise, reconnect it
if "%connectionState%"=="Connected" (
    ipconfig /release > nul
) else (
    ipconfig /renew > nul
)