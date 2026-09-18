# Resume guide

Read this first when opening the project from a new shell or agent session.

## One-line summary
This repository holds two Rainmeter skins. **InternetMonitor** is a ping-latency/bandwidth/packet-loss monitor for `8.8.8.8`, with a connect/disconnect toggle. **ServerStatus** is a 2-device LAN ping up/down badge. Both are plain `.ini` configs, with no Lua.

## What exists today
- Both skins are complete and released (`551427c`, "Initial public release"). `AGENTS.md` and `ai-context/` are tracked in git as of `747b3b7`.
- No feature work is scoped. See `ai-context/build-plan.md` Phase 2.

## Next action
1. Read `AGENTS.md` and `ai-context/technical.md`.
2. Before you change skin behavior, read the specific `.ini` file directly. These docs summarize the logic, but the `.ini` file is the source of truth.
3. Mark `ai-context/todo.md` items `[x]` with a one-line test result when done.
