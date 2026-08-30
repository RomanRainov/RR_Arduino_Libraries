# Battery Skill

Pin default: A0. Shared with buzzer in Freenove hardware.

Formula: `batteryADC / 1023.0 * 5.0 * 4`.

Current defect: `SERIAL_DEBUG_RRFreenove4WDCarBattery` is enabled in header, so every library battery read prints to hardware Serial.

With FlySky iBus consumer this is a UART conflict.

Electrical limits beyond the ADC formula: NEEDS VERIFICATION from exact board revision.
