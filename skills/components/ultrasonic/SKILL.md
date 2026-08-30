# Ultrasonic Skill

Model: HC-SR04.
Known consumer pins: D7 TRIG, D8 ECHO.

Current `getDistance()` calls `pulseIn(_echoPin, HIGH)` **without timeout**, converts `pingTime / 58.2`, and returns `_maxDistance` if pulseIn returns 0.

For responsive RC/autonomous loops, a bounded timeout is required.
