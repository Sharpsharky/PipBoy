#ifndef ScreenController_h
#define ScreenController_h

#include "ScreenController.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Arduino.h"

class ScreenController{
  public:
    ScreenController();
    void PrintCenter(const char *buf);
    void ClearCenter();
  private:
    char* currentText;
    bool isTextDisplayed;

    void DisplayCenter(const char *text);
};

#endif