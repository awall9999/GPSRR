void Splitter(String Valuesplitt){ //Select a String part beween "," out of the "GPRMC" and retuns the part as "GPRMC_StringPart" Example 0=Time, 8= Date
int result=0;
String PartOne;
String PartTwo;



for (int i = 0; i <= 0; i++) {
result =Valuesplitt.indexOf(".");

//Part = Valuesplitt.substring(result+1,Valuesplitt.length()); // after .
PartOne = Valuesplitt.substring(0,result); // before 
PartTwo = Valuesplitt.substring(result+1,Valuesplitt.length()); // after .





CalcValue = (PartOne.toInt()* 1000000) + (PartTwo.toInt());
CalcValue = CalcValue / 1000000;



}
 
}
