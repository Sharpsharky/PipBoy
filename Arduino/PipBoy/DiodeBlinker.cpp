#include "Arduino.h"
#include "Diode.h"
#include "DiodeBlinker.h"
#include "ScreenController.h"

const int blinkFrequency = 100; 

DiodeBlinker::DiodeBlinker(Diode* diodes, int diodeCount)
  : _diodes(diodes), _diodeCount(diodeCount) {}

void DiodeBlinker::Select(uint8_t diodePin){
  TurnOffAll();
  
  if(diodePin >= _diodeCount || diodePin < 0)
    return;

  _diodes[diodePin].SetActive(true);
}

void DiodeBlinker::Deselect(uint8_t diodePin){

  if(diodePin >= _diodeCount || diodePin < 0)
    return;

  _diodes[diodePin].SetActive(false);
}

void DiodeBlinker::Animate(int loopCount){
  TurnOffAll();
  _currentDiode = 0;
  _isAnimating = true;
  Serial.print("Hello, Arduino2! ");
  Serial.print(_diodeCount);

  if(loopCount < 0)
  {
    while(_isAnimating){
      AnimateSingleLoop(blinkFrequency);
    }
  }
  Serial.print("22 ");

  for (int i = 0; i < loopCount; i++) {
    AnimateSingleLoop(blinkFrequency);
  }

  _isAnimating = false;
}

void DiodeBlinker::StopAnimate(){
  _isAnimating = false;
  TurnOffAll();
}

void DiodeBlinker::AnimateSingleLoop(int frequency){
  for (int j = 0; j < _diodeCount; j++) {

      if(!_isAnimating)
        return;
  Serial.print("33 ");

      Deselect(_currentDiode);
      _currentDiode = j;
      Select(_currentDiode);

      delay(frequency);
    }
}

void DiodeBlinker::TurnOffAll(){
    for(int i = 0; i < _diodeCount; i++){
    _diodes[i].SetActive(false);
  }
}