#include <EEPROM.h>

// upload this sketch 
// open serial moniter
// press reset if data did not show

// make sure these adresses match the time record adresses
//0,1,2 are the defualt adress from the time record library.
byte adrHours =0; // eeprom location of the hours
byte adrMins =1;// eeprom loaction of the minutes
byte adrSecs =2;//eeprom  location of the seconds

void setup(){
  Serial.begin(9600); // begin serial connection
  // display time
  Serial.print("Your arduino was on for ");
  Serial.print(EEPROM.read(adrHours));
  Serial.print( " hours ");
  Serial.print(EEPROM.read(adrMins));
  Serial.print( " minutes and ");
  Serial.print(EEPROM.read(adrSecs));
  Serial.print(  " seconds.");
}
void loop(){
}
