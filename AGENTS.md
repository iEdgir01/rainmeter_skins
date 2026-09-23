# AGENTS — Rainmeter Skins

## Project overview

This repository holds two standalone Rainmeter desktop skins.
Each skin is a single `.ini` config.
Neither skin uses Lua.

### InternetMonitor (`InternetStatus.ini` + `Hist.inc`)

- Reports dual-WAN status for a fibre primary and an LTE backup.
- Reads link state from a router health feed. It does not decide link state itself.
- The feed is `net-health.json`, served by n8n at `192.168.88.210:5678`.
- Pings `1.1.1.1` via `PingPlugin` for local latency, jitter and loss.
- Shows a status dot, latency, the active WAN name, and time held on that link.
- On hover, expands to show links, probe health, latency, throughput, DNS and 20-minute history.
- `Hist.inc` holds the 20 history cells. A script generates that file.
- The skin has no click actions. It is a display only.

### ServerStatus (`ServerState.ini`)

- Pings two configurable LAN IPs (`Device1IP`/`Device2IP`) once per second.
- Swaps an `Online.png`/`Offline.png` icon per device by ping vs `PingTimeout`.
- Has no expand/collapse and no bandwidth display.
- Pure up/down indicator (for example NAS or home server boxes).

Both skins depend on third-party **PingPlugin**.
This plugin is not bundled in this repo — see README Requirements.

## Current status

ServerStatus is complete and released.
InternetMonitor was rebuilt in PR #2 around router-sourced link state.
PR #4 fixed three latched-state bugs in InternetMonitor.
The link rows, the banner and the status word are now level-triggered.
No code changes are pending.

## Key decisions (the why)

- Skins use plain `.ini` plus built-in Rainmeter measures (`Plugin`, `Calc`, `NetIn`, `NetOut`) instead of Lua.
- Only PingPlugin is an external dependency.
- The router decides link state, not the skin. The skin sits behind the router. It sees only the active path.
- The router probes both WANs pinned to separate routing tables. It can report one link down while the other carries traffic.
- The skin never pings a WAN gateway. The fibre ONT answers ICMP while the line is dead.
- History reads one packed `hist` string as 20 capture groups in the parent regex.
- A child WebParser measure ignores `RegExp2`. Only the parent `RegExp` runs.
- The latency graph uses a fixed ceiling. `AutoScale` made a flat 2 ms line look like activity.
- ServerStatus uses `IfBelowValue`/`IfAboveValue` plugin actions directly (no separate Calc). It only needs binary online/offline state.

## To-do

- [x] Document each skin's purpose and dependencies in ai-context/. Done in this session. Verified by reading both `.ini` files and `README.md`. No runtime test was run (Rainmeter is not installed here).

## File map (ai-context/)

- `technical.md` — stack, file structure, plugin dependency, thresholds and config knobs
- `resume.md` — cold-start summary, plus a note on uncommitted AGENTS.md/ai-context
- `todo.md` — task list
- `build-plan.md` — milestone status (both skins already shipped)

## Rules for all agents working on this project

1. Read this file and all linked ai-context/ files before writing code or making a plan.
2. After completing any task, update the to-do list: mark it [x] complete with a one-line test result summary and any user feedback received.
3. If a design decision changes during implementation, update the relevant ai-context/ file immediately — do not leave it stale.
4. If you discover something important that is not documented (an undocumented constraint, a gotcha, a key dependency), add it to the relevant ai-context/ file before moving on.
5. Do not start the next sub-project until the current one is marked [x] complete with passing tests confirmed.
6. If the user provides feedback that changes scope or approach, update AGENTS.md and the relevant ai-context/ file before continuing.
7. At the end of every session, verify AGENTS.md and ai-context/ accurately reflect the current state of the project.
