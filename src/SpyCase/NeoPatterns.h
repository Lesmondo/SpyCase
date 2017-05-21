
#ifndef _NEOPATTERNS_H_
#define _NEOPATTERNS_H_

#include <Adafruit_NeoPixel.h>

// Pattern types supported:
enum  pattern { NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE };
// Patern directions supported:
enum  direction { FORWARD, REVERSE };


class NeoPatterns : public Adafruit_NeoPixel
{
  private:
    uint8_t *mask;
    void updateMaskLength(uint16_t length);



    void setPixelColorMasked(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColorMasked(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColorMasked(uint16_t n, uint32_t c);
    
    
  public:
    // Member Variables:  
    pattern  ActivePattern;  // which pattern is running
    direction Direction;     // direction to run the pattern
    
    
    uint16_t Interval;   // milliseconds between updates
    unsigned long lastUpdate; // last update of position
    uint32_t Color1, Color2;  // What colors are in use
    uint16_t TotalSteps;  // total number of steps in the pattern
    uint16_t Index;  // current step within the pattern
    
    void (*OnComplete)();  // Callback on completion of pattern
    
    
    NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type, void (*callback)());
    void update();
    void Increment();
    void Reverse();
    void RainbowCycle(uint16_t interval, direction dir = FORWARD);
    void RainbowCycleUpdate();
    void TheaterChase(uint32_t color1, uint32_t color2, uint16_t interval, direction dir = FORWARD);
    void TheaterChaseUpdate();
    void ColorWipe(uint32_t color, uint16_t interval, direction dir = FORWARD);
    void ColorWipeUpdate();
    void Scanner(uint32_t color1, uint16_t interval);
    void ScannerUpdate();
    void Fade(uint32_t color1, uint32_t color2, uint16_t steps, uint16_t interval, direction dir = FORWARD);
    void FadeUpdate();

    
    uint32_t DimColor(uint32_t color);
    void ColorSet(uint32_t color);
    uint8_t Red(uint32_t color);
    uint8_t Green(uint32_t color);
    uint8_t Blue(uint32_t color);
    uint32_t Wheel(byte WheelPos);
    void Show(uint16_t n);
    void ShowAll();
    void Hide(uint16_t n);
    void HideAll();
    

};

#endif

