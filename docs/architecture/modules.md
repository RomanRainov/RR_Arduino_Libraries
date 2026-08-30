# Modules

| Module | Responsibility | Critical side effect |
|---|---|---|
| `RR_Freenove4WDCar_Battery` | read battery ADC | optional `Serial` debug |
| `RR_Freenove4WDCar_Buzzer` | on/off/beep | changes shared A0 mode |
| `RR_Freenove4WDCar_Driver` | high-level motion + LEDs | motor PWM/GPIO + I2C |
| `RR_Freenove4WDCar_Motor` | one logical motor side | direction/PWM; 10 ms start kick |
| `RR_Freenove4WDCar_Servo` | sonar pan servo | Servo/Timer1 |
| `RR_Freenove4WDCar_Sonar` | HC-SR04 distance | blocking `pulseIn()` |

Перед изменением API проверить оба consumers:
- `Arduino-My-Sketches/FlySky_4WDCar_COMPLEX`
- `Arduino-My-Sketches/FlySky_4WDCar_FreeDrive`
