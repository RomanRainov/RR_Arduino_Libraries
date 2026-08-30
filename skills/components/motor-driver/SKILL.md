# Motor Driver Skill

Software: `RRFreenove4WDCarDriver` + `RRFreenove4WDCarMotor`.
Exact physical driver IC: UNKNOWN.

Known consumer pins:
- left DIR D4, PWM D6;
- right DIR D3, PWM D5.

Driver input scale: 5..100.
Motor constants: MIN 80, MAX 250, START 100.

Current implementation:
- start from zero writes `START_SPEED`, delays 10 ms, then writes target;
- no ramp/slew;
- voltage compensation code exists but is unreachable due early return.

Do not document compensation as active until code is fixed and tested.
