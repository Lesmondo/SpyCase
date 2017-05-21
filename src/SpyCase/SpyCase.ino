/*
 * SpyCase code.
 * 
 * Runs on an Adafruit Feather M0 Express
 * See readme for deps.
 * 
 */

#include "NeoPatterns.h"
#include <Bounce2.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>
/*
 * Pins
 */
#define RING_PIN 12
#define RING_SIZE 16

#define PIXEL_PIN 8
#define PIXEL_SIZE 1

#define CITIES_PIN 13
#define CITIES_SIZE 6

//Buttons
#define TOGGLE_RED_PIN 15
#define TOGGLE_GREEN_PIN 16
#define TOGGLE_BLUE_PIN 17
#define TOGGLE_YELLOW_PIN 18

#define SWITCH_RED_PIN 10
#define SWITCH_GREEN_PIN 9 
#define SWITCH_BLUE_PIN 6
#define SWITCH_YELLOW_PIN 5
#define SWITCH_WHITE_PIN 22

//Meter
#define METER_PIN 14

//Cities Neopixel indexes
#define LONDON 0
#define NEWYORK 1
#define LIMA 2
#define PERTH 3
#define TOKYO 4 
#define NAIROBI 5



//Callbacks
void RingComplete();


// NEOPIXELS

// Neopixel 16 ring
NeoPatterns ring = NeoPatterns(RING_SIZE, RING_PIN, NEO_GRB + NEO_KHZ800, NULL);
//Onboard neopixel
NeoPatterns pixel = NeoPatterns(PIXEL_SIZE, PIXEL_PIN, NEO_GRB + NEO_KHZ800, NULL);
//City indicators
NeoPatterns cities = NeoPatterns(CITIES_SIZE, CITIES_PIN, NEO_GRB + NEO_KHZ800, NULL);


//BUTTONS

Bounce toggleRed;
Bounce toggleGreen;
Bounce toggleBlue;
Bounce toggleYellow;


Bounce switchRed;
Bounce switchGreen;
Bounce switchBlue;
Bounce switchYellow;
Bounce switchWhite;


//DISPLAY
Adafruit_AlphaNum4 alpha = Adafruit_AlphaNum4();

unsigned long lastUpdate;

void setup() {
    
    // Initialize all the pixels
    ring.begin();
    ring.ColorSet(NeoPatterns::Color(0,0,0));
    ring.show();

    //Turn off onboard pixel
    pixel.begin();
    pixel.ColorSet(NeoPatterns::Color(0,0,0));
    pixel.show();

    //Turn off all cities
    cities.begin(); 
    cities.ColorSet(NeoPatterns::Color(0,0,0));
    cities.show();

    //Initialise Buttons
    
    toggleRed = InitButton(TOGGLE_RED_PIN);
    toggleGreen = InitButton(TOGGLE_GREEN_PIN);
    toggleBlue = InitButton(TOGGLE_BLUE_PIN);
    toggleYellow = InitButton(TOGGLE_YELLOW_PIN);

    switchRed = InitButton(SWITCH_RED_PIN);
    switchGreen = InitButton(SWITCH_GREEN_PIN);
    switchBlue = InitButton(SWITCH_BLUE_PIN);
    switchYellow = InitButton(SWITCH_YELLOW_PIN);
    switchWhite = InitButton(SWITCH_WHITE_PIN);

    //Initialise display
    alpha.begin(0x70);
    alpha.clear();

    InitMeter();
    
    DoTestSetup();
}

Bounce InitButton(int pin) {
  pinMode(pin,INPUT_PULLUP);
  Bounce debouncer = Bounce(); 
  debouncer.attach(pin);
  debouncer.interval(5); 
  return debouncer;
}

void InitMeter() {
  analogWriteResolution(10);
  analogWrite(METER_PIN, 1024 );
  
}

void DoTestSetup() {

    //ring.ShowAll();
    //ring.Fade(NeoPatterns::Color(0, 0, 0),NeoPatterns::Color(255,0,0), 2, 500, FORWARD);
    
    alpha.writeDigitAscii(0,'0');
    alpha.writeDigitAscii(1,'0');
    alpha.writeDigitAscii(2,'0');
    alpha.writeDigitAscii(3,'0');
    alpha.writeDisplay();

}

void loop() {

  //Update everyone
  ring.update();
  cities.update();


  toggleRed.update();
  toggleGreen.update();
  toggleBlue.update();
  toggleYellow.update();
  
  switchRed.update();
  switchGreen.update();
  switchBlue.update();
  switchYellow.update();
  switchWhite.update();

  //TODO - Write wrapper class for alpha
  //alpha.update();
  
}


/*
 * Change Log
 * 
 * 20170510 - Initial sketch, try out neopixel code
 * 20170521 - Basic outline Neopixels, swtiches and meter
 */

