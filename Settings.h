//////////////////////////////////////////////////////////////////////
#include "VirtualWire.h"
#include "TimedAction.h"


// Developer
boolean DebugMode = true;
int DebugSerialValue = 0;

// Radio
int Radio_Speed = 4000;
int PIN_tx = 10;
int PIN_rx = 12;
int Radio_Test_Value = 0;

// PIin For Leds:
int PIN_LED_PozitieFata = 7;
int PIN_LED_FazaLunga = 8;
int PIN_LED_GoDown = 9;
int PIN_LED_PozitieSpate = 10;
int PIN_LED_Stop = 11;
int PIN_LED_Stanga = 6;
int PIN_LED_Dreapta = 5;
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
String COD_LED_Pozitii = "Av3_LED_Pos";
String COD_LED_FazaLunga = "Av3_LED_Faz";
String COD_LED_Left = "Av3_LED_Lef";
String COD_LED_Right = "Av3_LED_Rig";
String COD_LED_Avarii = "Av3_LED_LAR";
//

// PIN Motor 
int PIN_Motor_A_Top = 53;
int PIN_Motor_A_Bottom = 51;
int PIN_Motor_B_Top = 49;
int PIN_Motor_B_Bottom = 47;

int PIN_Motor_C_Top = 52;
int PIN_Motor_C_Bottom = 50;
int PIN_Motor_D_Top = 48;
int PIN_Motor_D_Bottom = 46;

//

// Comenzi Radio
String COD_Motor_Top = "Av3_MOT_TOP";
String COD_Motor_Bottom = "Av3_MOT_BOT";
//

// Statusuri
bool Motor_Top = false;
bool oMotor_Top = false;
bool Motor_Bottom = false;
bool oMotor_Bottom = false;
//


// PIN Buzzer
int PIN_Buzzer = 45;

bool Buzzer_Status = false;

int Buzzer_Timer = 0;



