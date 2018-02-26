// Receptor

#include "Functions.h"


void setup(){
  DebugMode_Setup();
  Radio_Setup();
  pinMode(40, OUTPUT);
  Motor_Directie.attach(30);
}

TimedAction Timed_DebugMode_Serial = TimedAction(1, DebugMode_Serial);
TimedAction Timed_Radio_Receiver = TimedAction(1, Radio_Receiver);

TimedAction Timed_Device_Buzzer = TimedAction(250, Device_Buzzer);

void loop(){
  Timed_DebugMode_Serial.check();
  Timed_Radio_Receiver.check();

  Timed_Device_Buzzer.check();


}
