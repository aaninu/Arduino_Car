//////////////////////////////////////////////////////////////////////
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

// PIin For Leds:
int PIN_LED_PozitieFata = 30;
int PIN_LED_FazaLunga = 31;
int PIN_LED_GoDown = 32;
int PIN_LED_PozitieSpate = 33;
int PIN_LED_Stop = 34;
int PIN_LED_Stanga = 35;
int PIN_LED_Dreapta = 36;
//

// Statusuri
bool LED_Pozitii = false;
bool oLED_Pozitii = false;
bool LED_FazaLunga = false;
bool oLED_FazaLunga = false;
bool LED_Left = false;
bool oLED_Left = false;
bool LED_Right = false;
bool oLED_Right = false;
bool LED_Avarii = false;
bool oLED_Avarii = false;

int LED_Semnal_Timer = 0;
//

// Comenzi Radio
String COD_LED_Pozitii = "APP_LED_Pos";
String COD_LED_FazaLunga = "APP_LED_Faz";
String COD_LED_Left = "APP_LED_Lef";
String COD_LED_Right = "APP_LED_Rig";
String COD_LED_Avarii = "APP_LED_LAR";
//

// PIN Motor 
int PIN_Motor_A_Top = 7;
int PIN_Motor_A_Bottom = 6;
int PIN_Motor_B_Top = 5;
int PIN_Motor_B_Bottom = 4;
//

// Comenzi Radio
String COD_Motor_Top = "APP_MOT_TOP";
String COD_Motor_Bottom = "APP_MOT_BOT";
//

// Statusuri
bool Motor_Top = false;
bool oMotor_Top = false;
bool Motor_Bottom = false;
bool oMotor_Bottom = false;
//



