/*
 * SpyCase code.
 * 
 * Runs on an Adafruit Feather M0 Express
 * See readme for deps.
 * 
 */

#include "NeoPatterns.h"

/*
 * Pins
 */
#define RINGPIN 12
#define PIXELPIN 8

/*
 * Globals
 */

//Callbacks
void RingComplete();

// Neopixel 16 ring
NeoPatterns ring = NeoPatterns(16, RINGPIN, NEO_GRB + NEO_KHZ800, &RingComplete);
//Onboard neopixel
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, PIXELPIN, NEO_GRB + NEO_KHZ800);


void setup() {
    
    // Initialize all the pixels
    ring.begin();
    ring.show();
    pixel.begin();
    pixel.show();

    //Test Code - run a pattern
    ring.setBrightness(50);
    ring.RainbowCycle(2);
}

void loop() {

  //Update everyone
  ring.Update();
}

void RingComplete()
{
    //Nothing for now
}

/*
 * Change Log
 * 
 * 20170510 - Initial sketch, try out neopixel code
 */

