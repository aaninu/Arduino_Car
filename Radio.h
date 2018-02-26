
using namespace std;
//////////////////////////////////////////////////////////////////////
void DebugMode_Msg(String text);
void DebugMode_Msg(String text, char* valoare);
void Radio_Setup();
void Radio_Receiver();
void Radio_Parsing(char Value[], int Len);

//////////////////////////////////////////////////////////////////////
void Radio_Setup(){
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(PIN_rx);
  vw_setup(Radio_Speed);
  vw_rx_start();
  DebugMode_Msg("Radio > Activ.");
}

void Radio_Receiver(){
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)){
    char Radio_Receive[buflen];
    for (int i = 0; i < buflen; i++){
      Radio_Receive[i] = char(buf[i]);
    }
    Radio_Parsing(Radio_Receive, buflen);
  }
}

void Radio_Parsing(char Value[], int Len){
  String Variabila;
  char vType[11];
  for (int i = 0; i < 11; i++){
    vType[i] = Value[i];
  }
  Variabila = (String)vType;
  int iStart = 0, iStop = 0;
  for (int i = 11; i < Len; i++){
    if (Value[i] == '{' && iStart == 0) iStart = i;
    if (Value[i] == '}' && iStart != 0) iStop = i;
    if (iStart != 0 && iStop != 0) break;
  }
  char vValue[6] = " ";
  int j = 0;
  for (int i = iStart + 1; i < iStop; i++){
    vValue[j] = Value[i];
    j++;
  }
  String Valoare = (String) vValue;

  
  Serial.println(Variabila);
  Serial.println(Valoare);

  if (Valoare == "True"){
    Serial.println("Este true");
   Status_Buzzer = true;

  }else if (Valoare == "False"){
    Serial.println("Este false");
    Status_Buzzer = false;

  }else{
    Serial.println("Trebuie sa fie INT");

    int iValoare = atoi(Valoare.c_str());
    Serial.println(iValoare);

    iValoare = map(iValoare, 0, 1023, 0, 180);
    Motor_Directie.write(iValoare);

  }
  
}
