//////////////////////////////////////////////////////////////////////
#include "Settings.h"
#include "Radio.h"


//////////////////////////////////////////////////////////////////////
void DebugMode_Setup();
void DebugMode_Msg(String text);
void DebugMode_Msg(String text, int valoare);
void DebugMode_Msg(String text, bool valoare);
void DebugMode_Msg(String text, char* valoare);
void DebugMode_Msg(String text, String valoare);
void DebugMode_Serial();

void Radio_Decode_Variable(String Variabila, bool Value);

void LEDs_Setup();
void Control_LED_Pozitii();
void Control_LED_FazaLunga();
void System_LED_LeftRight();
void Control_LED_Left();
void Control_LED_Right();
void Control_LED_Avarii();

void Motor_Setup();
void Control_Motor_Top();
void Control_Motor_Bottom();

void Buzzer_Setup();
void Control_Buzzer();
//////////////////////////////////////////////////////////////////////
void DebugMode_Setup(){
  if (DebugMode){
    Serial.begin(9600);
    DebugMode_Msg("DebugMode_Setup() ...");
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
void DebugMode_Msg(String text, bool valoare){
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
void DebugMode_Msg(String text, String valoare){
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

/** Radio Var/Val Received */
void Radio_Decode_Variable(String Variabila, bool Value){
  if (Variabila.equals(COD_LED_Pozitii)){
    LED_Pozitii = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_LED_Pozitii]", Value);
    
  }else if (Variabila.equals(COD_LED_FazaLunga)){
    LED_FazaLunga = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_LED_FazaLunga]", Value);
    
  }else if (Variabila.equals(COD_LED_Left)){
    LED_Left = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_LED_Left]", Value);
    
  }else if (Variabila.equals(COD_LED_Right)){
    LED_Right = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_LED_Right]", Value);
    
  }else if (Variabila.equals(COD_LED_Avarii)){
    LED_Avarii = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_LED_Avarii]", Value);

  }else if (Variabila.equals(COD_Motor_Top)){
    Motor_Top = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_Motor_Top]", Value);
    
  }else if (Variabila.equals(COD_Motor_Bottom)){
    Motor_Bottom = Value;
    DebugMode_Msg("Radio_Decode_Variable(...): [COD_Motor_Bottom]", Value);
    
  }else{
    DebugMode_Msg("Radio_Decode_Variable(...):", Variabila);
    
  }
}

/** Setup PIN Leds */
void LEDs_Setup(){
  pinMode(PIN_LED_PozitieFata, OUTPUT);  
  pinMode(PIN_LED_FazaLunga, OUTPUT); 
  pinMode(PIN_LED_GoDown, OUTPUT); 
  pinMode(PIN_LED_PozitieSpate, OUTPUT); 
  pinMode(PIN_LED_Stop, OUTPUT); 
  pinMode(PIN_LED_Stanga, OUTPUT); 
  pinMode(PIN_LED_Dreapta, OUTPUT); 
  DebugMode_Msg("LEDs_Setup() ...");
}

/** Control LED pozitii */
void Control_LED_Pozitii(){
  if (LED_Pozitii != oLED_Pozitii){
    digitalWrite(PIN_LED_PozitieFata, LED_Pozitii);
    digitalWrite(PIN_LED_PozitieSpate, LED_Pozitii);  
    oLED_Pozitii = LED_Pozitii;
  }
}

/** Control LED pozitii */
void Control_LED_FazaLunga(){
  if (oLED_FazaLunga != LED_FazaLunga){
    digitalWrite(PIN_LED_FazaLunga, LED_FazaLunga);
    oLED_FazaLunga = LED_FazaLunga;
  }
}

/** LED Left / Right Control Timed */
void System_LED_LeftRight(){
  if (LED_Avarii == true){
    if (LED_Semnal_Timer == 0){
      digitalWrite(PIN_LED_Stanga, true);
      digitalWrite(PIN_LED_Dreapta, true);  
    }else if (LED_Semnal_Timer == 500){
      digitalWrite(PIN_LED_Stanga, false);
      digitalWrite(PIN_LED_Dreapta, false);  
    }else if (LED_Semnal_Timer == 1000)
      LED_Semnal_Timer = -1;
    LED_Semnal_Timer += 1;
  }else if (LED_Left == true){
    if (LED_Semnal_Timer == 0){
      digitalWrite(PIN_LED_Stanga, true);
    }else if (LED_Semnal_Timer == 300){
      digitalWrite(PIN_LED_Stanga, false); 
    }else if (LED_Semnal_Timer == 600)
      LED_Semnal_Timer = -1;
    LED_Semnal_Timer += 1;
  }else if (LED_Right == true){
    if (LED_Semnal_Timer == 0){
      digitalWrite(PIN_LED_Dreapta, true);  
    }else if (LED_Semnal_Timer == 300){
      digitalWrite(PIN_LED_Dreapta, false);  
    }else if (LED_Semnal_Timer == 600)
      LED_Semnal_Timer = -1;
    LED_Semnal_Timer += 1;
  }else{
    LED_Semnal_Timer = 0;
  }
  
}

/** Control LED Left */
void Control_LED_Left(){
  if (oLED_Left != LED_Left){
    LED_Right = false;
    if (LED_Left == false) digitalWrite(PIN_LED_Stanga, false);
    oLED_Left = LED_Left;
  }
}

/** Control LED Right */
void Control_LED_Right(){
  if (oLED_Right != LED_Right){
    LED_Left = false;
    if (LED_Right == false) digitalWrite(PIN_LED_Dreapta, false);
    oLED_Right = LED_Right;
  }
}

/** Control LED Avarii */
void Control_LED_Avarii(){
  if (oLED_Avarii != LED_Avarii){
    LED_Left = false;
    LED_Right = false;
    if (LED_Avarii == false){
      digitalWrite(PIN_LED_Stanga, false);
      digitalWrite(PIN_LED_Dreapta, false);
    }
    oLED_Avarii = LED_Avarii;
  }
}

void Motor_Setup(){
  pinMode(PIN_Motor_A_Top, OUTPUT);
  pinMode(PIN_Motor_A_Bottom, OUTPUT);
  pinMode(PIN_Motor_B_Top, OUTPUT);
  pinMode(PIN_Motor_B_Bottom, OUTPUT);
  DebugMode_Msg("Motor_Setup() ...");
}

void Control_Motor_Top(){
  if (oMotor_Top != Motor_Top){
    digitalWrite(PIN_Motor_A_Top, Motor_Top);
    digitalWrite(PIN_Motor_B_Top, Motor_Top);

    // Set OFF Motor B*
    digitalWrite(PIN_Motor_A_Bottom, false);
    digitalWrite(PIN_Motor_B_Bottom, false);
    digitalWrite(PIN_LED_GoDown, false);
    Buzzer_Status = false;
    digitalWrite(PIN_Buzzer, false);
    oMotor_Top = Motor_Top;
  }
}

void Control_Motor_Bottom(){
  if (oMotor_Bottom != Motor_Bottom){
    digitalWrite(PIN_Motor_A_Bottom, Motor_Bottom);
    digitalWrite(PIN_Motor_B_Bottom, Motor_Bottom);
    digitalWrite(PIN_LED_GoDown, Motor_Bottom);
    Buzzer_Status = Motor_Bottom;

    // Set OFF Motor A*
    digitalWrite(PIN_Motor_A_Top, false);
    digitalWrite(PIN_Motor_B_Top, false);
    oMotor_Bottom = Motor_Bottom;
  }
}

void Buzzer_Setup(){
  pinMode(PIN_Buzzer, OUTPUT);
  DebugMode_Msg("Buzzer_Setup() ...");
}

void Control_Buzzer(){
  if (Buzzer_Status == true){
    if (Buzzer_Timer == 0){
      digitalWrite(PIN_Buzzer, true);
    }else if(Buzzer_Timer == 250){
      digitalWrite(PIN_Buzzer, false);
    }else if (Buzzer_Timer == 600){
      Buzzer_Timer = -1;  
    }
    Buzzer_Timer += 1;
  }else{
    Buzzer_Timer = 0;
  }
}

