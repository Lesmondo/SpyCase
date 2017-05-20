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
#define CITIESPIN 13

/*
 * Globals
 */

//Callbacks
void RingComplete();

// Neopixel 16 ring
NeoPatterns ring = NeoPatterns(16, RINGPIN, NEO_GRB + NEO_KHZ800, &RingComplete);
//Onboard neopixel
NeoPatterns pixel = NeoPatterns(1, PIXELPIN, NEO_GRB + NEO_KHZ800, NULL);
//City indicators
NeoPatterns cities = NeoPatterns(6, CITIESPIN, NEO_GRB + NEO_KHZ800, NULL);



void setup() {
    
    // Initialize all the pixels
    ring.begin();
    ring.show();
    
    pixel.begin();
    pixel.RainbowCycle(2);
    //pixel.Color1 = NeoPatterns::Color(100,150,0);
    pixel.show();

    //Test Code - run a pattern
    ring.setBrightness(50);
    ring.RainbowCycle(2);

    cities.begin();
    cities.RainbowCycle(2);

    
    

    
}

void loop() {

  //Update everyone
  ring.Update();
  cities.Update();
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

