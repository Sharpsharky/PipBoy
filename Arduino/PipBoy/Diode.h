#ifndef Diode_h
#define Diode_h

#include "Arduino.h"

class Diode {
  public:
    Diode(uint8_t pin);
    void SetActive(bool isActive);
  private:
    int _pin;
    char* currentText;
};

#endif