# AGENTS — Rainmeter Skins

## Project overview
Two standalone Rainmeter desktop skins, each a single `.ini` config (no Lua):

- **InternetMonitor** (`InternetStatus.ini`): pings `8.8.8.8` every second via `PingPlugin`, shows a color-coded status dot (green/orange/red by latency threshold) and live ping ms. On hover, expands to show a ping graph, NetIn/NetOut bandwidth (Rainmeter's built-in `NetIn`/`NetOut` measures), and a rolling packet-loss %. Clicking the status dot runs `InternetController.bat`, which pings once to detect current state then calls `ipconfig /release` or `ipconfig /renew` — requires admin privileges.
- **ServerStatus** (`ServerState.ini`): pings two configurable LAN IPs (`Device1IP`/`Device2IP`) once per second, swaps an `Online.png`/`Offline.png` icon per device based on whether the ping is below/above `PingTimeout`. No expand/collapse, no bandwidth — pure up/down indicator for e.g. NAS/home server boxes.

Both depend on the third-party **PingPlugin** (not bundled in this repo — see README Requirements).

## Current status
Skins are functionally complete and released (single commit `551427c`, "Initial public release"). No code changes pending. `AGENTS.md`/`ai-context/` exist locally but were never committed — see `ai-context/resume.md`.

## Key decisions (the why)
- Plain `.ini` + built-in Rainmeter measures (`Plugin`, `Calc`, `NetIn`, `NetOut`) chosen over Lua scripting — keeps both skins dependency-light (only PingPlugin needed) and easy to hand-edit.
- InternetMonitor's connect/disconnect button shells out to a `.bat` rather than doing it in-skin, since `ipconfig` needs admin rights Rainmeter itself may not have.
- ServerStatus uses `IfBelowValue`/`IfAboveValue` plugin actions directly (no separate Calc measure) since it only needs a binary online/offline state, unlike InternetMonitor's 4-tier threshold logic.

## To-do
- [x] pending — document each skin's purpose + dependencies in ai-context/ — done via this session; verified by reading both `.ini` files and `README.md`, no runtime test (Rainmeter not installed here).

## File map (ai-context/)
- `technical.md` — stack, file structure, plugin dependency, thresholds/config knobs
- `resume.md` — cold-start summary + note on uncommitted AGENTS.md/ai-context
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
