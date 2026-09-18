# Rainmeter Skins

A collection of lightweight Rainmeter skins for monitoring network connectivity and local server status.

---

## Skins

### InternetMonitor

A compact dual-WAN monitor for a fibre primary with an LTE backup. It shows which link is carrying traffic, how long it has held, and the state of both links. Hover to expand for probe health, latency, throughput, DNS and a 20-minute history.

**Features:**
- Per-link up/down state for both WANs, sourced from the router
- Colour-coded status dot and live latency to a configurable host (default: `1.1.1.1`)
- Expandable panel with probe health, latency, throughput, DNS and a 20-minute history strip
- A single banner surfaces failover, degradation and endpoint outages

**Files:**
- `InternetStatus.ini` — main skin file
- `Hist.inc` — 20 history cells (generated; do not hand-edit)

**Requires a health feed.** The skin reads `net-health.json` from an n8n
endpoint set by `HealthURL` in `[Variables]`. The router publishes per-link
state to that workflow; the skin renders it and never probes the WANs itself.
Without the feed, link state shows "no data" rather than a false "healthy".

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

The default ping target is Cloudflare (`1.1.1.1`). To change it, update `PingTarget` in `[Variables]`. This measures **this PC's** path, not the WAN; WAN health comes from the feed.

> **Note:** The skin has no click actions. A status indicator that also
> released the DHCP lease was removed — it was a 7px target in the hover path,
> with no confirmation and inverted logic.

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
