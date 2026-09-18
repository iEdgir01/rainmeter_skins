# AGENTS — Rainmeter Skins

## Project overview

This repository holds two standalone Rainmeter desktop skins.
Each skin is a single `.ini` config.
Neither skin uses Lua.

### InternetMonitor (`InternetStatus.ini`)

- Pings `8.8.8.8` every second via `PingPlugin`.
- Shows a color-coded status dot (green/orange/red by latency threshold) and live ping in ms.
- On hover, expands to show a ping graph, NetIn/NetOut bandwidth, and rolling packet-loss %.
- A click on the status dot runs `InternetController.bat`.
- The script pings once to detect state, then calls `ipconfig /release` or `ipconfig /renew`.
- The script requires admin privileges.

### ServerStatus (`ServerState.ini`)

- Pings two configurable LAN IPs (`Device1IP`/`Device2IP`) once per second.
- Swaps an `Online.png`/`Offline.png` icon per device by ping vs `PingTimeout`.
- Has no expand/collapse and no bandwidth display.
- Pure up/down indicator (for example NAS or home server boxes).

Both skins depend on third-party **PingPlugin**.
This plugin is not bundled in this repo — see README Requirements.

## Current status

Both skins are functionally complete and released.
Single commit: `551427c` ("Initial public release").
No code changes are pending.
`AGENTS.md` and `ai-context/` exist locally but were never committed — see `ai-context/resume.md`.

## Key decisions (the why)

- Skins use plain `.ini` plus built-in Rainmeter measures (`Plugin`, `Calc`, `NetIn`, `NetOut`) instead of Lua.
- Only PingPlugin is an external dependency.
- InternetMonitor connect/disconnect shells out to a `.bat` file. `ipconfig` needs admin rights that Rainmeter may not have.
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
