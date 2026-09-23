# Todo

## Active
- none — no feature work scoped
- [x] rebuild InternetMonitor around router-sourced link state (PR #2) — loaded in Rainmeter, verified across healthy and failover states; regex checked against the live feed (34 groups)

- [x] fix latched state in InternetMonitor (PR #3) — link rows, banner and status word were edge-triggered and stuck; bound rows to measures, added a banner arbiter with an explicit clear branch; verified against the live feed across all four states

## Done
- [x] document each skin's real purpose/logic in ai-context/technical.md and AGENTS.md — verified by reading README.md, both .ini files, and InternetController.bat; no code changed, no automated test applicable
- [x] commit AGENTS.md and ai-context/ (`747b3b7`)
