#include "Diode.h"
#include "DiodeBlinker.h"
#include "ScreenController.h"

const int led_pin1 = 3; 
const int led_pin2 = 4; 
const int led_pin3 = 5; 

const int buttonPin = 2; 

DiodeBlinker* diodeBlinker;
ScreenController* screenController;

Diode diodes[] = { Diode(led_pin1), Diode(led_pin2), Diode(led_pin3) };

int buttonState = 0;

void setup() {
  Serial.begin(9600);

  screenController = new ScreenController();
  screenController->PrintCenter("Loading...");

  SetUpDiodeBlinker();
  diodeBlinker->Animate(3);

  screenController->PrintCenter("Hello Vault Dweller!");

  pinMode(2, INPUT);

}
 
void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    diodeBlinker->Animate(1);
  } else {
    // turn LED off:
    //diodeBlinker->Deselect(0);
  }

}

void SetUpDiodeBlinker(){
  uint8_t numDiodes = sizeof(diodes) / sizeof(diodes[0]);
  diodeBlinker = new DiodeBlinker(diodes, numDiodes);  
}




