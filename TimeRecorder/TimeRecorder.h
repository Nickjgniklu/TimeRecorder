#ifndef TimeRecorder_h
#define TimeRecorder_h
#include "arduino.h"


class TimeRecorder
{
  public:
    TimeRecorder(byte,byte,byte,byte);
    TimeRecorder(byte);
    void reset();
    void record();
    void initialize();
  private:
    byte clearPin;
    byte adrHours; // eeprom location of the hours
    byte adrMins;// eeprom loaction of the minutes
    byte adrSecs;//eeprom  location of the seconds

};
#endif
