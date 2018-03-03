// Receptor

#include "Functions.h"


void setup(){
  DebugMode_Setup();
  Radio_Setup();
  
  LEDs_Setup();
  Motor_Setup();

  Buzzer_Setup();
}

TimedAction Timed_DebugMode_Serial = TimedAction(1, DebugMode_Serial);
TimedAction Timed_Radio_Receiver = TimedAction(1, Radio_Receiver);

TimedAction Timed_Control_LED_Pozitii = TimedAction(1, Control_LED_Pozitii);
TimedAction Timed_Control_LED_FazaLunga = TimedAction(1, Control_LED_FazaLunga);
TimedAction Timed_Control_LED_Left = TimedAction(1, Control_LED_Left);
TimedAction Timed_Control_LED_Right = TimedAction(1, Control_LED_Right);
TimedAction Timed_Control_LED_Avarii = TimedAction(1, Control_LED_Avarii);
TimedAction Timed_System_LED_LeftRight = TimedAction(1, System_LED_LeftRight);

TimedAction Timed_Control_Motor_Top = TimedAction(1, Control_Motor_Top);
TimedAction Timed_Control_Motor_Bottom = TimedAction(1, Control_Motor_Bottom);

TimedAction Timed_Control_Buzzer = TimedAction(1, Control_Buzzer);

void loop(){
  Timed_DebugMode_Serial.check();
  Timed_Radio_Receiver.check();

  Timed_Control_LED_Pozitii.check();
  Timed_Control_LED_FazaLunga.check();
  Timed_Control_LED_Left.check();
  Timed_Control_LED_Right.check();
  Timed_Control_LED_Avarii.check();
  Timed_System_LED_LeftRight.check();

  Timed_Control_Motor_Top.check();
  Timed_Control_Motor_Bottom.check();

  Timed_Control_Buzzer.check();
}
