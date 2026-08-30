# RGB LED Controller Skill

Dependency: `Freenove_WS2812B_RGBLED_Controller`.
Driver constructs controller with I2C address `0x20`, 10 LEDs, `TYPE_GRB`.

Known Uno bus: A4 SDA, A5 SCL.

Current driver setup waits forever: `while (!_strip.begin());`

Exact external controller revision: UNKNOWN.
