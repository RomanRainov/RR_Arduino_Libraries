# Интерфейсы MCU

- Motor consumer использует PWM D5/D6. Не перенастраивать Timer0 registers: Arduino Core использует Timer0 для системного времени.
- `RR_Freenove4WDCar_Servo` использует Arduino Servo. На ATmega328P Servo использует Timer1; PWM D9/D10 нельзя считать независимым.
- В текущем RR Buzzer tone API отсутствует. Если `tone()` будет использован, Arduino AVR Core использует Timer2.
- Battery: A0, формула `ADC / 1023.0 * 5.0 * 4`.
- Driver создаёт RGB controller `0x20`, 10 LEDs, `TYPE_GRB`; Uno I2C A4/A5.
- Battery debug печатает в `Serial`, что конфликтует с FlySky consumer, где iBus владеет hardware Serial.
