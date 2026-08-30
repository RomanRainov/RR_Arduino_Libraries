# Servo Skill

Software: `RRFreenove4WDCar_Servo` + Arduino Servo.
Known consumer signal pin: D2.
On ATmega328P Servo uses Timer1.

Current setup: `_servo.attach(pin); setPosition(_startPosition + _offset);`

Consumers already define `SERVO_START_POS = 90 + SERVO_OFFSET`, so initial setup command applies offset twice. Physical correct center: NEEDS VERIFICATION before changing behavior.
