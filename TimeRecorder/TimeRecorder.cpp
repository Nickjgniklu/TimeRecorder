#include <EEPROM.h>
#include "TimeRecorder.h"
#include "Arduino.h"
TimeRecorder::TimeRecorder(byte clrpin) {
    clearPin = clrpin; //pin to clear eeprom
    adrHours =0; // eeprom location of the hours
    adrMins =1;// eeprom loaction of the minutes
    adrSecs =2;//eeprom  location of the seconds

}
TimeRecorder::TimeRecorder(byte adr1,byte adr2,byte adr3,byte clrpin) {
    clearPin = clrpin; //pin to clear eeprom

    adrHours =adr1; // eeprom location of the hours
    adrMins =adr2;// eeprom loaction of the minutes
    adrSecs =adr3;//eeprom  location of the seconds

}
void TimeRecorder::initialize() { // intitize will reset the epprom if the chosen clear pin is grounded
    pinMode(clearPin, INPUT_PULLUP);//input pulllup inverts loggic
    if(digitalRead(clearPin)==0) {
        EEPROM.write(adrHours, 0);
        EEPROM.write(adrMins, 0);
        EEPROM.write(adrSecs, 0);
    }
}
void TimeRecorder::reset() {
    EEPROM.write(adrHours, 0);
    EEPROM.write(adrMins, 0);
    EEPROM.write(adrSecs, 0);
}
void TimeRecorder::record() {
    // since epprom only holds bit vaules and i want to know how many minute the battery lasted i will count in hours minutes and seconds.
    // This sketch wont cont more than 256 hours 59 minutes ant 59 seconds
    unsigned long time = millis();// so hours minutes and seconds all do there math on the same number
    byte hours = (((time/1000)/60)/60); // calculate time since arduino turned on in minutes
    byte minutes = (((time/1000)/60)%60); // calculate minutes past the hour.
    byte seconds = ((time/1000)%60);// calcuate reming seconds
    if(minutes > EEPROM.read(adrMins) || hours > EEPROM.read(adrHours) || seconds> EEPROM.read(adrSecs)) { // only write eprom if the time has increased by a second or more, helps protect eeprom from over writeing
        EEPROM.write(adrHours, hours); // store hours
        EEPROM.write(adrMins, minutes); // store minutes
        EEPROM.write(adrSecs, seconds); // store seconds
    }


}

