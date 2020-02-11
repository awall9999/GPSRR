void GetGPRMC(){
   GPRMC="";
   char a = "";
   do {
   if (Serial1.available()) {                                                                     // Check if Data in Serial Buffer
                         
                          
                          a=Serial1.read();
                          if (a == '$') {                                                         // Check for the "$" char. Beginn of line
                                          GPRMC=Serial1.readStringUntil(',');}                    // Read Serial Data until "," and write it to Variable GPRMC
                                         }
       }while(GPRMC!="GPRMC");                                                                    // Check until GPRMC = "GPRMC" Code Line
       GPRMC=Serial1.readStringUntil('\r');                                                       // Read Serial Data until "," and write it to Variable GPRMC 
       GPRMC=("GPRMC," + GPRMC); //Add "GPRMC," Header to the GPRMC variable
       
}   
