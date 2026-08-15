@echo off
set "TaskName=ToggleSteamAccess"
C:\Windows\System32\schtasks.exe /Run /TN "%TaskName%"