void Nothing(){
unsigned long time_now = 0;
time_now = millis();
digitalWrite(LedRed,LOW);
digitalWrite(LedBlue,LOW);
Signal01 = false;
Signal02 = false;
LedBlueCounter++;
if (LedBlueCounter > 6) {LedBlueCounter=0;LedBlueBlink ();}
do {
    
   } while ((unsigned long)(millis() - time_now) < Timer); 

  
}


void GPSFail(){
unsigned long time_now = 0;
time_now = millis();
BeepCounter++;
if (BeepCounter > 10) {BeepCounter=0;Beep(2);}
LedBlueBlink ();
do {
    
   } while ((unsigned long)(millis() - time_now) < Timer); 

    
}

void Alarm01(){
unsigned long time_now = 0;
time_now = millis();
if (Signal01 == false) {Beep(2);Signal01 = true;}
digitalWrite(LedBlue,HIGH);
do {
    
   } while ((unsigned long)(millis() - time_now) < Timer); 

  
}

void Alarm02(){
unsigned long time_now = 0;
time_now = millis();
if (Signal02 == false) {Beep(4);Signal02 = true;}
LedRedBlink ();LedBlueBlink ();LedRedBlink ();LedBlueBlink ();

do {
    
   } while ((unsigned long)(millis() - time_now) < Timer); 

  
}
