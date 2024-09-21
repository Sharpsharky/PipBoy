#include "Arduino.h"
#include "Diode.h"

Diode::Diode(uint8_t pin){
  _pin = pin;
  pinMode(pin, OUTPUT);
}

void Diode::SetActive(bool isActive){
  digitalWrite(_pin, isActive);
}