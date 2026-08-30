# Подтверждённые ограничения и дефекты

1. **Battery Serial debug включён.** `RR_Freenove4WDCar_Battery.h` определяет `SERIAL_DEBUG_RRFreenove4WDCarBattery`; `getBatteryVoltage()` печатает в `Serial`.
2. **Voltage compensation недостижим.** `RR_Freenove4WDCar_Motor::getFixedSpeed()` возвращает `speed` сразу после проверки `MIN_SPEED`; код compensation ниже этого return не выполняется.
3. **Sonar без timeout.** `pulseIn(_echoPin, HIGH)` может блокировать loop.
4. **Driver startup может зависнуть.** `while (!_strip.begin());` не имеет timeout/fallback.
5. **Cross-repo API drift.** `FlySky_4WDCar_COMPLEX` вызывает `driver.setAllLedsColor(...)`, но текущий `RR_Freenove4WDCar_Driver.h` такого API не объявляет.
6. **Cross-repo API drift.** `FlySky_4WDCar_COMPLEX` вызывает `buzzer.toneOn(...)`, но текущий `RR_Freenove4WDCar_Buzzer.h` содержит только `on/off/beep`.
7. **Servo setup применяет offset повторно.** Consumer передаёт `SERVO_START_POS = 90 + offset`, а library setup выполняет `start + offset`.
8. A0 battery+buzzer требует последовательного доступа; это intentional hardware multiplex, не обычный duplicate-pin defect.
