# InternetStatus — Agent Index

## What this is

This folder holds one Rainmeter skin config file (`InternetStatus.ini`).
It is not a software project.
There is no source code, no build system, and no tests.

The config pings `8.8.8.8` every 5 seconds.
It tints an icon image (`internet_symbol.png`) blue when connected.
It tints the icon black when disconnected.
The image file is referenced but not present in this folder.

## Current status

The config is complete and static.
Nothing is pending.
This is a finished config, not active development.

## Key decisions

- The config uses the Rainmeter `Ping` plugin instead of a custom script.
- The ping target is Google DNS (`8.8.8.8`).
- `UpdateDivider=5` runs the ping every 5th update tick (5s at a 1000ms update rate).

## To-do list

None. No active work applies to this file.

## File map

| File | Purpose |
|---|---|
| `InternetStatus.ini` | Rainmeter skin config — the only real content |
| `ai-context/` | Minimal notes only |

## Agent rules for all agents working on this project

1. Read this file and all linked ai-context/ files before writing any code or making any plan.
2. After completing any task, update the to-do list: mark it [x] complete with a one-line test result summary and any user feedback received.
3. If a design decision changes during implementation, update the relevant ai-context/ file immediately — do not leave it stale.
4. If you discover something important that is not documented (an undocumented constraint, a gotcha, a key dependency), add it to the relevant ai-context/ file before moving on.
5. Do not start the next sub-project until the current one is marked [x] complete with passing tests confirmed.
6. If the user provides feedback that changes scope or approach, update AGENTS.md and the relevant ai-context/ file before continuing.
7. At the end of every session, verify AGENTS.md and ai-context/ accurately reflect the current state of the project.
