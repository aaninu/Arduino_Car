//////////////////////////////////////////////////////////////////////
#include "ServoTimer2.h"
#include "VirtualWire.h"
#include "TimedAction.h"


// Developer
boolean DebugMode = true;
int DebugSerialValue = 0;

// Radio
int Radio_Speed = 4000;
int PIN_tx = 10;
int PIN_rx = 11;
int Radio_Test_Value = 0;


// Device
boolean Status_Buzzer = false;
boolean Status_Buzzer_OLD = false;

// Servo
//int Servo_PIN = 7;
ServoTimer2 Motor_Directie;

