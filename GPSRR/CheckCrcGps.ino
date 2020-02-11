void CheckCRC(){
  CRC=false;
  if (GPRMC.indexOf(",A,") >= 0){                                         //",A," in GPRMC data If GPS data is valid 
                          byte CRC_Calculate=0;
                          String CRC_Hex;
                          String GPS_Data=GPRMC.substring(0,GPRMC.length()-3);
                          String GPS_Checksum=GPRMC.substring(GPRMC.length()-2,GPRMC.length());  
                          for (int i = 0; i < GPS_Data.length(); i++){ 
                                                                      CRC_Calculate = CRC_Calculate ^ (GPS_Data.charAt(i));
                                                                      }
    
                          CRC_Hex = String(CRC_Calculate,HEX);
                          CRC_Hex.toUpperCase();
                          if (CRC_Hex == GPS_Checksum) {CRC = true;}
                          
                           }
}
