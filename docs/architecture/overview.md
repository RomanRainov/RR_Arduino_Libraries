# Architecture overview

```text
Consumer sketch
   ↓
RRFreenove4WDCarDriver
   ├─ RRFreenove4WDCarMotor (left)
   ├─ RRFreenove4WDCarMotor (right)
   └─ Freenove WS2812B controller over I2C

Consumer sketch
   ├─ RRFreenove4WDCarServo → Arduino Servo
   ├─ RRFreenove4WDCarSonar → HC-SR04
   ├─ RRFreenove4WDCarBuzzer → A0
   └─ RRFreenove4WDCarBattery → A0 ADC
```

RR libraries являются thin hardware wrappers. Pin ownership окончательно задаёт consumer sketch.
