
// this sketch measures how long the arduino has been on and store to eeprom.
// use the time recover sketch to retive time from eeprom

// FOLLOW THESE INTRUCTIONS
// 1. Ground clearPin, by default this is pin 12
//     when this pin is grounded on boot the eeprom values used will be cleared
// 2. upload program that use time record
// 3. plug your arduino into what ever you will be measuring
// 4. When your arduino has booted disconnect your clearPin from ground!!!!!
//     if you forget step 4 when you go to upload the timerecover sketch you
//     will lose your recored time
// 5.when you are ready to see how long your arduino was on for, upload time recover sketch

#include <TimeRecorder.h>
#include <EEPROM.h>
byte led =13;

TimeRecorder clock1(12);//(clearpin) deafult epprom adress of 0,1,2 are used.
//chose your own epprom adresses
//TimeRecorder clock1(0,1,2,12);(eprom adress1,eprom adress2,eprom adress3,clearpin)
void setup() {
  clock1.initialize();//clears epprom if clear pin is grounded

  pinMode(led, OUTPUT);

}

// flash led and store time every 1/2 second
void loop() {

  clock1.record();//will record time to epprom only if it has been more than a second since it recorded last
//  you must call this function alteast once per second 
//  if you call the function more then once per second it will only right to eeprom once per second
  digitalWrite(led, HIGH);

  delay(500);
  digitalWrite(led, LOW);

  delay(500);
}


