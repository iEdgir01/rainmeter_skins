# Resume guide

Read this first when opening the project from a new shell or agent session.

## One-line summary
This repository holds two Rainmeter skins. **InternetMonitor** reports dual-WAN status for a fibre primary and an LTE backup. It reads link state from a router health feed served by n8n. **ServerStatus** is a 2-device LAN ping up/down badge. Both are plain `.ini` configs, with no Lua.

## What exists today
- ServerStatus is complete and released (`551427c`).
- InternetMonitor was rebuilt in PR #2 around router-sourced link state.
- InternetMonitor needs the n8n `net-health.json` feed. Without it, link state shows "no data".
- No feature work is scoped. See `ai-context/build-plan.md` Phase 2.

## Next action
1. Read `AGENTS.md` and `ai-context/technical.md`.
2. Before you change skin behavior, read the specific `.ini` file directly. These docs summarize the logic, but the `.ini` file is the source of truth.
3. Mark `ai-context/todo.md` items `[x]` with a one-line test result when done.
