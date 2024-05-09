/*
  RR_Freenove4WDCar_Motor.cpp - Library for Arduino Motor HC-SR04.
  Created by Roman Rainov, Janaury 29, 2024.
  Released into the private domain.
*/

#include "Arduino.h"
#include "RR_Freenove4WDCar_Motor.h"

RRFreenove4WDCarMotor::RRFreenove4WDCarMotor()
{
}

RRFreenove4WDCarMotor::RRFreenove4WDCarMotor(byte pinDirection = 4, byte pinMotorPwm = 6, byte pinBattery = A0)
	: _battery{RRFreenove4WDCarBattery(pinBattery)}
{
	_pinDirection = pinDirection;
	_pinMotorPwm = pinMotorPwm;
	_battery = RRFreenove4WDCarBattery(pinBattery);
}

void RRFreenove4WDCarMotor::setup()
{
	pinMode(_pinDirection, OUTPUT);
	pinMode(_pinMotorPwm, OUTPUT);
}

void RRFreenove4WDCarMotor::stop()
{
	_currentSpeed = 0;
	analogWrite(_pinMotorPwm, 0);
}

void RRFreenove4WDCarMotor::move(byte speed, bool motorDirection)
{
	byte fixedSpeed = getFixedSpeed(speed);
	//Serial.print("currentSpeed: ");
	//Serial.print(_currentSpeed);
	//Serial.print("\tfixedSpeed: ");
	//Serial.print(fixedSpeed);
	if(_currentSpeed == 0 && fixedSpeed > 0)
	{
		//Serial.print("\tSTART_SPEED");
		digitalWrite(_pinDirection, motorDirection);
		analogWrite(_pinMotorPwm, START_SPEED);
		delay(10);
	}
	digitalWrite(_pinDirection, motorDirection);
	analogWrite(_pinMotorPwm, fixedSpeed);
	_currentSpeed = fixedSpeed;
	//Serial.println();
}

byte RRFreenove4WDCarMotor::currentSpeed()
{
	return _currentSpeed;
}

byte RRFreenove4WDCarMotor::getFixedSpeed(byte speed)
{	
	if (speed < MIN_SPEED)
		return 0;

	return speed;

	float voltageOffset = getVoltageCompensation();
	byte speedFixed = constrain(speed + voltageOffset, MIN_SPEED, MAX_SPEED);

	#ifdef SERIAL_DEBUG_RRFreenove4WDCarMotor
	{
		//Serial.print("input speed: ");
		//Serial.print(speed);
		//Serial.print("\t voltageOffset: ");
		//Serial.print(voltageOffset);
		//Serial.print("\t speedFixed: ");
		//Serial.println(speedFixed);
	}
	#endif

	return speedFixed;
}

float RRFreenove4WDCarMotor::getVoltageCompensation()
{
	// The PWM value represents different speeds when the voltage of battery changes.
	// So we set a speedOffset to compensate the difference.
	float voltage = _battery.getBatteryVoltage();
	float voltageOffset = MAX_VOLTAGE - voltage;
	if(voltageOffset <= 0)
		return 0;

	return voltageOffset * SPEED_OFFSET_PER_V;
}