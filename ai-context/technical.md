# Technical context

## Stack
Pure Rainmeter `.ini` skins — no Lua, no external code. Rainmeter 4.5+, requires the third-party **PingPlugin** (bundled with Rainmeter or from the rainmeter-plugin-sdk repo). InternetMonitor's expand button also shells to a `.bat` via the built-in `RunCommand` plugin.

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
- `[MeasurePing]` (Plugin=PingPlugin) pings `DestAddress=8.8.8.8` every second (`UpdateRate=1`), `Timeout=#PingTimeout#` (3000ms default).
- `[MeasurePingStatus]` (Calc measure) branches on ping value via `IfCondition`/`IfConditionN` into 4 tiers: timeout/negative -> red "Disconnected"; <= PingGood(50ms) -> green; <= PingWarning(100ms) -> orange; else -> red but still "Disconnected" label at tier 4 despite having a real ping value (existing quirk, not something introduced this session).
- `[MeasurePacketLossRaw]`/`[MeasurePacketLoss]` derive a rolling % of timed-out pings over the last 20 samples (`AverageSize=20`, `Percentual=1`).
- `[MeasureNetIn]`/`[MeasureNetOut]` use Rainmeter's built-in `NetIn`/`NetOut` measures on `Interface=Best`.
- Hover over `[MeterTitle]` sets `Expanded=1`, revealing the ping graph + bandwidth + packet-loss meters (all `Hidden=(#Expanded#=0 ? 1 : 0)`).
- Clicking `[MeterStatusDot]` runs `RunInternetBatchFile` (Plugin=RunCommand) -> `InternetController.bat`.

## InternetController.bat logic
Single ping to `8.8.8.8 -n 1`; if it succeeds assumes "Connected" and runs `ipconfig /release`, else assumes "Disconnected" and runs `ipconfig /renew`. This is a naive toggle (doesn't read the skin's actual state) and needs admin rights to actually affect the adapter.

## ServerStatus logic
- `[MeasureConnectionDevice1]`/`Device2` (Plugin=PingPlugin) ping `Device1IP`/`Device2IP` every 1000ms with `IfBelowValue`/`IfAboveValue` against `#PingTimeout#` (1000ms default) to directly swap the meter's `ImageName` between `Online.png`/`Offline.png` — no intermediate Calc measure, no expand/collapse UI.
- Purely a 2-device up/down badge; device names/IPs are hardcoded placeholders (`192.168.1.100/101`, "Server 1/2") meant to be edited by the user per README.

## Config knobs (per skin, in `[Variables]`)
- InternetMonitor: `PingGood/Warning/Bad/Timeout`, colors, `Width`.
- ServerStatus: `Device1IP/Name`, `Device2IP/Name`, `FontName`, `PingTimeout`.

## Gotchas
- Both skins hard-depend on PingPlugin; without it the ping measures silently fail/error at Rainmeter load.
- InternetController.bat needs the skin (or Rainmeter itself) run as admin, else `ipconfig /release|/renew` no-ops.
- No test suite / build step exists — this is config, verified by loading in Rainmeter, not automated tests.
