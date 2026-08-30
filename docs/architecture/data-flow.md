# Data flow

```text
speed/turn from consumer
  → Driver mapping 5..100
  → Motor target 80..250
  → direction GPIO + PWM

battery read
  → A0 ADC
  → battery voltage
  → intended motor compensation
```

В текущем Motor коде последний шаг фактически не участвует в `getFixedSpeed()` из-за раннего `return`.

Sonar: `TRIG → echo pulseIn() → distance`.
Servo: `angle → Servo.write()`.
LED: `Driver → I2C 0x20 → external WS2812B controller`.
