# Pinout contract

Библиотеки параметризованы, поэтому pinout задаётся consumer sketch. Для текущих Freenove4WDCar sketches используется:

| Pin | Role |
|---|---|
| D2 | Servo |
| D3 | Right motor direction |
| D4 | Left motor direction |
| D5 | Right motor PWM |
| D6 | Left motor PWM |
| D7 | HC-SR04 TRIG |
| D8 | HC-SR04 ECHO |
| A0 | Battery ADC + buzzer, намеренное multiplexing |
| A4/A5 | I2C RGB controller |

D0/D1 в FlySky consumer заняты `Serial`/iBus. D13 там используется как `LED_BUILTIN`, поэтому конфликтует с будущим SPI SCK.
