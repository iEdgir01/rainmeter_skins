# Technical context

## Stack
These are pure Rainmeter `.ini` skins. They use no Lua and no external code. They require Rainmeter 4.5 or later. They require the third-party **PingPlugin**. InternetMonitor also uses the built-in **WebParser** plugin to read a JSON health feed.

## Structure
```
InternetMonitor/
  InternetStatus.ini      - skin: measures + meters
  Hist.inc                - 20 history cells, generated

ServerStatus/
  ServerState.ini         - skin: two-device ping monitor
  Online.png, Offline.png
```

## InternetMonitor logic

### Data model
The **router** is the source of truth for link state. It probes both WANs every
20 s, pinned to separate routing tables (`probe-fibre` / `probe-lte`). It can
therefore report "fibre is down" while LTE carries traffic. The skin sits behind
the router. It only ever sees the active path. It must not decide link state.

Never ping a WAN gateway to infer link state. The fibre ONT answers ICMP while
the line is dead. Measured: gateway 4/4 at 0.6 ms, `8.8.8.8` 0/4 at 100% loss.

### Feed
`[MeasureHealth]` (Plugin=WebParser) reads `net-health.json` from n8n at
`192.168.88.210:5678`, every 20 s. One parent `RegExp` captures 34 groups:
14 named fields, then the 20-character `hist` string as 20 single-char groups.

Fields: `wan`, `fibre_state`, `lte_state`, `both_down`, `score`, `probe_ok`,
`probe_fail`, `worst_streak`, `fallthrough`, `endpoint_issue`, `held_s`,
`router_fresh`, `dns_blocked_pct`, `dns_retry_pct`, `hist`.

### Local measures
- `[MeasurePing]` pings `1.1.1.1` (`UpdateRate=2`). This is **this PC's path**,
  not the WAN. The UI labels it as such.
- `[MeasurePingPrev]` uses `UpdateDivider=2` to lag by one sample. At `1` it read
  `MeasurePing` in the same cycle, so jitter always showed 0.0 ms.
- `[MeasureJitter]` / `[MeasureLoss]` derive from those samples.
- `[MeasureNetIn]` / `[MeasureNetOut]` use `Interface=Best`.

### History
`Hist.inc` holds 20 measure/meter pairs. Each measure reads one capture group
(`StringIndex` 15 to 34) and substitutes the character to a colour:
`F`=fibre, `L`=lte, `X`=down, `.`=no data.

Generate the file with a script. Do not hand-edit it.

### Layout
Every row exists in every state. Values and colours change. Nothing appears or
disappears, except one banner slot. A hover sets `Expanded=1`. Captions sit
**above** their data.

## ServerStatus logic
- `[MeasureConnectionDevice1]`/`Device2` (Plugin=PingPlugin) ping `Device1IP`/`Device2IP` every 1000ms. Each uses `IfBelowValue`/`IfAboveValue` against `#PingTimeout#` (1000ms default) to directly swap the meter's `ImageName` between `Online.png`/`Offline.png`. There is no intermediate Calc measure and no expand/collapse UI.
- This skin is purely a 2-device up/down badge. Device names and IPs are hardcoded placeholders (`192.168.1.100/101`, "Server 1/2"), meant for the user to edit per the README.

## Config knobs (per skin, in `[Variables]`)
- InternetMonitor: `HealthURL`, `PingTarget`, `PingWarning`, `PingTimeout`, `RetryWarn`, `LatCeiling`, colours, `W`/`Pad`/`Inner`, `HistY`, `HCollapsed`/`HExpanded`.
- ServerStatus: `Device1IP/Name`, `Device2IP/Name`, `FontName`, `PingTimeout`.

## Gotchas
- Both skins hard-depend on PingPlugin. Without it, the ping measures silently fail or error at Rainmeter load.
- A WebParser measure cannot chain off another **child** WebParser. It must chain off a parent that has a real `URL=`. A child-of-child silently returns nothing.
- `RegExp2` is **not** honoured on a child measure. Only the parent `RegExp` runs. Per-cell re-extraction silently substituted all 20 characters into one string.
- A `Calc` measure that reads a substituted WebParser evaluates to `0`. A Substitute produces a string, not a number.
- `!ShowMeter` overrides a `Hidden=` formula. Gate conditional meters with a variable instead.
- The latency graph needs a fixed ceiling (`LatCeiling`, 25 ms). `AutoScale` rescales to the window min/max, which makes a flat 2 ms line look like activity.
- InternetMonitor needs the n8n feed. Without it, link state shows "no data" rather than a false green.
- No test suite and no build step exist. This is config, verified by loading in Rainmeter, not by automated tests.
