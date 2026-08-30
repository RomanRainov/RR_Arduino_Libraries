# Buzzer Skill

Pin default: A0, shared with battery ADC.

Current public API:
- `on()`
- `off()`
- `beep(unsigned int delaySeconds)`

Despite the parameter name, `beep()` passes the value to Arduino `delay()`, therefore units are milliseconds.

There is **no** `toneOn()` or `toneOff()` in current repository version. Consumer calls to those methods are API drift.
