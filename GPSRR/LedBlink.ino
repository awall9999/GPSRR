void LedRedBlink (){
unsigned long time_now = 0;
time_now = millis();
do {
   digitalWrite(LedRed,HIGH); 
   } while ((unsigned long)(millis() - time_now) < 200); 

digitalWrite(LedRed,LOW);

}

void LedBlueBlink (){
unsigned long time_now = 0;
time_now = millis();
do {
   digitalWrite(LedBlue,HIGH); 
   } while ((unsigned long)(millis() - time_now) < 200); 

digitalWrite(LedBlue,LOW);

}
