void Calc(){
/*************************************************************************
 * //Function to calculate the distance between two waypoints
 *************************************************************************/
int Counter = 0;
Splitter(Latitude);
float latFloat = CalcValue;
Splitter(Longitude);
float lonFloat = CalcValue;

float flon1 = 0;
float flat1 = 0;
float flon2 = 0;
float flat2 = 0;
float dist_calc=0;
float dist_calc2=0;
float diflat=0;
float diflon=0;

do{
flon1 = lonFloat;
flat1 = latFloat;
flon2 = GpsDataBase [Counter];
flat2 = GpsDataBase [Counter+1];
dist_calc=0;
dist_calc2=0;
diflat=0;
diflon=0;

//I've to spplit all the calculation in several steps. If i try to do it in a single line the arduino will explode.
diflat=radians(flat2-flat1);
flat1=radians(flat1);
flat2=radians(flat2);
diflon=radians((flon2)-(flon1));

dist_calc = (sin(diflat/2.0)*sin(diflat/2.0));
dist_calc2= cos(flat1);
dist_calc2*=cos(flat2);
dist_calc2*=sin(diflon/2.0);
dist_calc2*=sin(diflon/2.0);
dist_calc +=dist_calc2;

dist_calc=(2*atan2(sqrt(dist_calc),sqrt(1.0-dist_calc)));

dist_calc*=6371000.0; //Converting to meters
//Serial.println(dist_calc);

if (dist_calc < 700) GPSStatus = 2; 
if (dist_calc < 300) GPSStatus = 3;

//return dist_calc;
Counter=Counter+2;
}while (GpsDataBase [Counter] != 0);


}
