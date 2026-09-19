# RR_Arduino_Libraries

Набор Arduino-библиотек для проектов **Freenove 4WD Car for UNO**.

Репозиторий содержит собственные обёртки над аппаратными компонентами машины: двигателями, драйвером движения, батареей, сервоприводом, ультразвуковым датчиком, буззером и световой индикацией.

## Библиотеки

### [RR_Freenove4WDCar_Battery](RR_Freenove4WDCar_Battery)

Измерение напряжения батареи через ADC.

### [RR_Freenove4WDCar_Buzzer](RR_Freenove4WDCar_Buzzer)

Управление буззером, включая обычное включение/выключение и tone API.

### [RR_Freenove4WDCar_Motor](RR_Freenove4WDCar_Motor)

Низкоуровневое управление мотором:

- direction;
- PWM;
- ограничение диапазона скорости;
- компенсация по напряжению батареи;
- плавное изменение скорости.

### [RR_Freenove4WDCar_Driver](RR_Freenove4WDCar_Driver)

Высокоуровневое управление машиной:

- forward/backward;
- повороты;
- вращение на месте;
- остановка;
- управление RGB-индикацией.

### [RR_Freenove4WDCar_Servo](RR_Freenove4WDCar_Servo)

Управление сервоприводом.

### [RR_Freenove4WDCar_Sonar](RR_Freenove4WDCar_Sonar)

Работа с HC-SR04.

### [RR_Freenove4WDCar_TurnSignal](RR_Freenove4WDCar_TurnSignal)

Экспериментальная библиотека указателей поворота и LED-индикации.

## Документация

Репозиторий содержит AI-ready документацию:

- [AGENTS.md](AGENTS.md) — правила работы AI-агентов;
- [docs/hardware](docs/hardware) — аппаратная конфигурация и ограничения;
- [docs/architecture](docs/architecture) — архитектура и зависимости;
- [skills/board](skills/board) — знания о плате/MCU;
- [skills/components](skills/components) — Component Skills.

## Использование

Библиотеки предназначены прежде всего для проектов из:

[RomanRainov/Arduino-My-Sketches](https://github.com/RomanRainov/Arduino-My-Sketches)

Основной документированный проект:

[Arduino-My-Sketches/Freenove4WDCar_FIXED](https://github.com/RomanRainov/Arduino-My-Sketches/tree/main/Freenove4WDCar_FIXED)

## Важно: версии библиотек

Standalone-репозиторий и локальные копии библиотек внутри конкретного проекта могут различаться.

Например, `Freenove4WDCar_FIXED/Libraries` может содержать исправления, которых ещё нет здесь, или наоборот.

Поэтому правило простое:

```text
Project-local library
        ↓
compare with standalone
        ↓
merge intentionally
```

Не заменять библиотеку только потому, что каталог называется одинаково.

Для `Freenove4WDCar_FIXED` локальные библиотеки проекта имеют приоритет над этим репозиторием, пока изменения явно не синхронизированы.

## Целевая платформа

Текущая Freenove-конфигурация ориентирована на:

```text
Arduino Uno
ATmega328P
arduino:avr:uno
```

Не переносить GPIO, Timer, UART, PWM или ADC assumptions на другие платы без отдельной проверки.

## Аппаратные ограничения

При использовании библиотек необходимо учитывать ресурсы конкретного проекта:

- hardware `Serial` может быть занят FlySky iBus;
- Servo использует Timer1;
- `tone()` использует Timer2;
- PWM и Timer usage зависят от ATmega328P;
- один GPIO может намеренно использоваться несколькими функциями;
- электрические параметры нельзя выводить из программных констант.

Подробные ограничения должны проверяться по документации конкретного проекта и его `hardware-manifest.yaml`.
