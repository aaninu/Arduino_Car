//////////////////////////////////////////////////////////////////////
#include "Settings.h"
#include "Radio.h"


//////////////////////////////////////////////////////////////////////
void DebugMode_Setup();
void DebugMode_Msg(String text);
void DebugMode_Msg(String text, int valoare);
void DebugMode_Msg(String text, char* valoare);
void DebugMode_Serial();
void Device_Buzzer();

//////////////////////////////////////////////////////////////////////
void DebugMode_Setup(){
  if (DebugMode){
    Serial.begin(9600);
    DebugMode_Msg("Telecomanda > Activa.");
  }
}

void DebugMode_Msg(String text){
  if (DebugMode){
    Serial.print("[DebugMode]: ");
    Serial.println(text);
  }
}
void DebugMode_Msg(String text, int valoare){
  if (DebugMode){
    Serial.print("[DebugMode]: ");
    Serial.print(text);
    Serial.print(" {");
    Serial.print(valoare);
    Serial.println("}");
  }
}
void DebugMode_Msg(String text, char* valoare){
  if (DebugMode){
    Serial.print("[DebugMode]: ");
    Serial.print(text);
    Serial.print(" {");
    Serial.print(valoare);
    Serial.println("}");
  }
}

void DebugMode_Serial(){
  if (Serial.available() > 0){
    DebugSerialValue = Serial.read();
    DebugMode_Msg("Serial.read():", DebugSerialValue);

  }
}

void Device_Buzzer(){
  if (Status_Buzzer_OLD != Status_Buzzer){
    Status_Buzzer_OLD = Status_Buzzer;
    digitalWrite(40, Status_Buzzer);  
  }
}


