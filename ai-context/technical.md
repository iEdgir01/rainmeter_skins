# Technical context

## Stack
These are pure Rainmeter `.ini` skins, with no Lua and no external code. They require Rainmeter 4.5 or later. They also require the third-party **PingPlugin** (bundled with Rainmeter, or available from the rainmeter-plugin-sdk repo). InternetMonitor's expand button also shells to a `.bat` file via the built-in `RunCommand` plugin.

## Structure
```
InternetMonitor/
  InternetStatus.ini      - skin: measures + meters
  InternetController.bat  - toggles ipconfig /release|/renew (needs admin)
  Background.png, Online.png, Offline.png

ServerStatus/
  ServerState.ini         - skin: two-device ping monitor
  Online.png, Offline.png
```

## InternetMonitor logic
- `[MeasurePing]` (Plugin=PingPlugin) pings `DestAddress=8.8.8.8` every second (`UpdateRate=1`). Its timeout is `Timeout=#PingTimeout#` (3000ms default).
- `[MeasurePingStatus]` (Calc measure) branches on the ping value via `IfCondition`/`IfConditionN`, into 4 tiers. Timeout or negative gives red "Disconnected". A value <= PingGood(50ms) gives green. A value <= PingWarning(100ms) gives orange. Any other value gives red, but keeps the "Disconnected" label at tier 4 even with a real ping value. This is an existing quirk, not something introduced this session.
- `[MeasurePacketLossRaw]`/`[MeasurePacketLoss]` derive a rolling % of timed-out pings over the last 20 samples (`AverageSize=20`, `Percentual=1`).
- `[MeasureNetIn]`/`[MeasureNetOut]` use Rainmeter's built-in `NetIn`/`NetOut` measures on `Interface=Best`.
- A hover over `[MeterTitle]` sets `Expanded=1`. This reveals the ping graph, the bandwidth meters, and the packet-loss meters (all use `Hidden=(#Expanded#=0 ? 1 : 0)`).
- A click on `[MeterStatusDot]` runs `RunInternetBatchFile` (Plugin=RunCommand), which calls `InternetController.bat`.

## InternetController.bat logic
The script sends a single ping to `8.8.8.8 -n 1`. If the ping succeeds, the script assumes "Connected" and runs `ipconfig /release`. If the ping fails, the script assumes "Disconnected" and runs `ipconfig /renew`. This is a naive toggle — it does not read the skin's actual state. It needs admin rights to affect the adapter.

## ServerStatus logic
- `[MeasureConnectionDevice1]`/`Device2` (Plugin=PingPlugin) ping `Device1IP`/`Device2IP` every 1000ms. Each uses `IfBelowValue`/`IfAboveValue` against `#PingTimeout#` (1000ms default) to directly swap the meter's `ImageName` between `Online.png`/`Offline.png`. There is no intermediate Calc measure and no expand/collapse UI.
- This skin is purely a 2-device up/down badge. Device names and IPs are hardcoded placeholders (`192.168.1.100/101`, "Server 1/2"), meant for the user to edit per the README.

## Config knobs (per skin, in `[Variables]`)
- InternetMonitor: `PingGood/Warning/Bad/Timeout`, colors, `Width`.
- ServerStatus: `Device1IP/Name`, `Device2IP/Name`, `FontName`, `PingTimeout`.

## Gotchas
- Both skins hard-depend on PingPlugin. Without it, the ping measures silently fail or error at Rainmeter load.
- InternetController.bat needs the skin, or Rainmeter itself, to run as admin. Otherwise `ipconfig /release|/renew` has no effect.
- No test suite and no build step exist. This is config, verified by loading in Rainmeter, not by automated tests.
