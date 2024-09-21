#include "Arduino.h"
#include "ScreenController.h"
#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS    10 
#define TFT_DC    9
#define TFT_MOSI  11
#define TFT_SCK   13
#define TFT_RESET 8

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RESET);
char* currentText;
bool isTextDisplayed = false;

const uint16_t textColor = display.color565(0, 255, 0);
const uint16_t backgroundColor = display.color565(0, 0, 0);

ScreenController::ScreenController()
{
  display.initR(INITR_BLACKTAB); 
  display.setRotation(1);
  //display.fillRect(0, 0, 129, 132,display.color565(0, 0, 0));
  display.fillScreen(backgroundColor);
}

void ScreenController::PrintCenter(const char *text)
{
  ClearCenter();
  isTextDisplayed = true;
  currentText = text;
  display.setTextColor(textColor);
  DisplayCenter(text);
}

void ScreenController::ClearCenter()
{
  if(!isTextDisplayed)
    return;

  display.setTextColor(backgroundColor);
  DisplayCenter(currentText);
  isTextDisplayed = false;
}

void ScreenController::DisplayCenter(const char *text)
{
  int16_t x1, y1;
  uint16_t textWidth, textHeight;
  display.getTextBounds(text, 0, 0, &x1, &y1, &textWidth, &textHeight);

  int16_t x = (SCREEN_WIDTH - textWidth) / 2;
  int16_t y = (SCREEN_HEIGHT - textHeight) / 2;
  display.setCursor(x, y);
  
  display.print(text);
}
