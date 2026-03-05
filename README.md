# Rainmeter Skins

A collection of lightweight Rainmeter skins for monitoring network connectivity and local server status.

---

## Skins

### InternetMonitor

A compact network monitor that displays real-time connection status, ping latency, upload/download speeds, and packet loss. Hover to expand and see detailed graphs and stats.

**Features:**
- Live ping to a configurable host (default: `8.8.8.8`)
- Color-coded status dot (green / orange / red) based on latency thresholds
- Expandable panel with ping graph, download/upload speeds, and packet loss %
- One-click connect/disconnect (runs `ipconfig /release` or `/renew`)

**Files:**
- `InternetStatus.ini` — main skin file
- `InternetController.bat` — toggles network connection (requires running as administrator)

---

### ServerStatus

A minimal skin that pings up to two local network devices and shows online/offline status with an icon indicator. Useful for monitoring home servers, NAS devices, or any LAN host.

**Features:**
- Pings two configurable IP addresses
- Shows Online/Offline image per device
- Fully configurable device names and IPs via variables

**Files:**
- `ServerState.ini` — main skin file

---

## Requirements

- [Rainmeter](https://www.rainmeter.net/) 4.5 or later
- **PingPlugin** — bundled with Rainmeter or available from the [Rainmeter plugins repository](https://github.com/rainmeter/rainmeter-plugin-sdk)

---

## Installation

1. Copy the `InternetMonitor` and/or `ServerStatus` folders into your Rainmeter skins directory:
   ```
   %USERPROFILE%\Documents\Rainmeter\Skins\
   ```
2. Open Rainmeter, right-click the tray icon → **Refresh All**
3. Load the skins from the Rainmeter manager

---

## Configuration

### InternetMonitor

Open `InternetMonitor\InternetStatus.ini` and edit the `[Variables]` section at the top:

```ini
[Variables]
; Ping thresholds in milliseconds
PingGood=50
PingWarning=100
PingBad=200
PingTimeout=3000

; Colors (hex, no #)
ColorGood=00FF00
ColorWarning=FFA500
ColorBad=FF0000
ColorText=FFFFFF
ColorCyan=00FFFF
ColorBackground=0,0,0,180

; Skin dimensions
Width=240
```

The default ping target is Google's public DNS (`8.8.8.8`). To change it, find `[MeasurePing]` and update `DestAddress`.

> **Note:** The connect/disconnect button runs `InternetController.bat`, which calls `ipconfig /release` or `/renew`. This requires Rainmeter (or the bat file) to be run with administrator privileges to work correctly.

---

### ServerStatus

Open `ServerStatus\ServerState.ini` and edit the `[Variables]` section:

```ini
[Variables]
Device1IP=192.168.1.100
Device1Name=Server 1

Device2IP=192.168.1.101
Device2Name=Server 2

FontName=Segoe UI
PingTimeout=1000
```

Replace the IP addresses and names with your own devices. The skin will show `Online.png` or `Offline.png` next to each device name based on ping response.

---

## License

MIT — free to use, modify, and distribute.
