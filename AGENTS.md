# RR_Arduino_Libraries — правила для AI-агентов

Этот репозиторий содержит аппаратно-зависимые библиотеки Freenove4WDCar для Arduino Uno/ATmega328P.

Перед изменением:
1. прочитать `docs/hardware/hardware-manifest.yaml`;
2. прочитать `skills/board/SKILL.md`;
3. прочитать Skill затрагиваемого компонента;
4. сверить API с фактическими `.h/.cpp`;
5. проверить потребителей в `RomanRainov/Arduino-My-Sketches`.

Критические правила:
- не менять GPIO assumptions без проверки consumer sketch;
- не использовать `Serial` debug вместе с FlySky iBus;
- не менять Timer0/Timer1/Timer2 assumptions без проверки Arduino AVR Core и Servo/tone;
- не исправлять электрические параметры по догадке;
- после изменения hardware API обновить manifest, interfaces, limitations и Component Skill.

Текущая важная реальность:
- RR Driver не имеет публичного `setAllLedsColor()`;
- RR Buzzer не имеет `toneOn()/toneOff()`;
- RR Sonar использует `pulseIn()` без timeout;
- Motor voltage compensation сейчас недостижим из-за раннего `return`;
- Battery header включает Serial debug macro.
