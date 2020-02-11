/*
  Get Gps Data from GPRMC Line
  Check if data is Valid and Crc is OK
  Recalculate Latitude and Longitude
  Change view for Date and Time
  
*/// Enter the GPS RR positions here.last one is "0"
float GpsDataBase [] = {5.94603,49.85609,
                        5.96015,49.90362,
                        6.10490,49.91461,
                        6.07876,50.04100, 
                        5.95277,50.08978,
                        6.10002,49.83419,
                        6.18874,49.82363,
                        6.32103,49.83841,
                        6.08665,49.76965,
                        6.07892,49.75241,
                        6.12421,49.75062,
                        6.48365,49.81353,
                        5.87390,49.73149,
                        6.00781,49.73125,
                        6.09063,49.71447,
                        6.23386,49.68838,
                        5.95641,49.62979,
                        6.01898,49.59348,
                        6.10132,49.60040,
                        6.27929,49.59043,
                        6.37353,49.58878,
                        5.96873,49.51144,
                        6.18004,49.53293,
                        6.28739,49.54202,
                        5.94351,49.49999,
                        0};
                         
String GPRMC;
String GPRMC_StringPart;
String GPSDate;
String GPSTime;
String Latitude;
String Longitude;
boolean CRC=false;
const int sound = 10;
const int LedRed = 4;
const int LedBlue= 3;
float CalcValue = 0;
int GPSFailCount = 0;
int GPSStatus = 0;
int LedRedCounter=0;
int LedBlueCounter=0;
int BeepCounter=0;
boolean Signal01 = false;
boolean Signal02 = false; 
unsigned long time_now = 0;
unsigned long Timer = 1000;






void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        Serial1.begin(9600);    // opens serial port 1, sets data rate to 9600 bps
        pinMode(LedRed,OUTPUT);
        pinMode(LedBlue,OUTPUT);
        // Init Sequenz
        
        
        do {
          GetGPRMC();
          CheckCRC();
          Serial.println("Wait for GPS signal");
          LedBlueBlink();
          
            }while(CRC != true);

        Beep(1);digitalWrite(LedBlue,LOW);
        
        }

void loop() {
 Timer=1000;
 GetGPRMC();
 
 CheckCRC();
 //CRC=false;
if (CRC == true) {
                   GPSFailCount = 0;
                   GPSStatus = 0;
                   LatitudeLongitude();
                   
                   Serial.print(Latitude);Serial.print(" ");Serial.print(Longitude);Serial.println(" ");
                   
                   CRC = false;
                   //Splitter(Longitude);
                   Calc();
                   
                   
                  } else {GPSFailCount++;Serial.print("No GPS ");Serial.println(GPSFailCount);if (GPSFailCount > 10){GPSStatus = 1;}
                         }
if (GPSStatus == 0) Nothing(); 
if (GPSStatus == 1) GPSFail();
if (GPSStatus == 2) Alarm01();
if (GPSStatus == 3) Alarm02(); 
//Serial.println(LedBlueCounter);
//Serial.println(LedRedCounter);
//Serial.println(BeepCounter);

  
                
// End Of Loop---------------------------------------------------    
}
