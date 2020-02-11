void GetGPRMC_StringPart(int Selection){ //Select a String part beween "," out of the "GPRMC" and retuns the part as "GPRMC_StringPart" Example 0=Time, 8= Date
int result=0;
String GPRMC_Backup = GPRMC;
for (int i = 0; i <= Selection; i++) {
result =GPRMC_Backup.indexOf(",");
GPRMC_StringPart = GPRMC_Backup.substring(result+1,GPRMC_Backup.length());
GPRMC_Backup = GPRMC_StringPart;
result =GPRMC_Backup.indexOf(",");
GPRMC_StringPart = GPRMC_StringPart.substring(0,result);
                                      }
 
}


void LatitudeLongitude(){
GetGPRMC_StringPart(2); Latitude = GPRMC_StringPart;
GetGPRMC_StringPart(3); String LatSN = GPRMC_StringPart;
GetGPRMC_StringPart(4); Longitude = GPRMC_StringPart;
GetGPRMC_StringPart(5); String LongEW = GPRMC_StringPart;

// Calculate Latitude
long int LatA= Latitude.substring(0, 2).toInt(); // Get 2 first numbers from Latitude String
float LatB= Latitude.substring(2, 8).toFloat(); // Get 7 last numbers from Latitude String
if (LatSN == "N"){Latitude= String(((LatB/60)+LatA),6);} else {Latitude= String(((LatB/60)+LatA)*-1,6);} // if South Hemisphere : negative coordinates

// Calculate Longitude
long int LongA= Longitude.substring(0, 3).toInt(); // Get 3 first numbers from Longitude String
float LongB= Longitude.substring(3, 8).toFloat(); // Get 7 last numbers from Longitude String
if (LongEW == "E"){Longitude= String(((LongB/60)+LongA),6);} else {Longitude= String(((LongB/60)+LongA)*-1,6);} // if West : negative coordinates
}
