# Validation rules

Будущий validator должен:
- сравнивать pin constants consumer sketches с manifest;
- разрешать A0 duplicate только как `intentional_multiplex`;
- искать `Serial.print*` при активном iBus;
- проверять `Servo` ↔ Timer1 и `tone()` ↔ Timer2;
- запрещать direct Timer0 reconfiguration при motor PWM D5/D6;
- flag `pulseIn()` без timeout;
- flag `while (!begin())` без timeout;
- сравнивать вызовы public API в sketches с заголовками RR libraries;
- flag unreachable hardware logic после unconditional `return`;
- компилировать consumer sketches с FQBN `arduino:avr:uno`.

Сам validator здесь не реализован.
