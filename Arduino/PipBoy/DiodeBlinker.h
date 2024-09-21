#include <stdint.h>
#ifndef DiodeBlinker_h
#define DiodeBlinker_h

#include "Arduino.h"
#include "Diode.h"
#include "ScreenController.h"

class DiodeBlinker {
  public:
    DiodeBlinker(Diode* diodes, int diodeCount);
    void Select(uint8_t diodePin);
    void Deselect(uint8_t diodePin);
    void Animate(int loopCount);
    void StopAnimate();

  private:
    Diode* _diodes;
    int _diodeCount;
    int _currentDiode;
    bool _isAnimating;
    
    void TurnOffAll();
    void AnimateSingleLoop(int frequency);
};

#endif