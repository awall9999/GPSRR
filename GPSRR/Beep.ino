void Beep(int repeat){
  
     long int Timenow;
     
     noTone(sound);
     
     Timenow=millis();
     while (millis() - Timenow <= 200);
     for (int i = 0; i <= repeat-1; i++) {
                                     tone(sound, 2000);
                                     Timenow=millis();
                                     while (millis() - Timenow <= 70);
                                     noTone(sound);
                                     Timenow=millis();
                                     while (millis() - Timenow <= 130);
                                     }
  noTone(sound);
}
