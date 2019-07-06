#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 2

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(360, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 int x;
 int y;
  for(x = 0; x < 42; x++){
  for(y = 0; y < 9; y++){
      set(x,y,strip.Color(255,0,0));
  }
  }
//  set(41,0,strip.Color(255,255,255));
//  set(38,1,strip.Color(255,255,255));

  for(x = 0; x < 42; x++){
      set(x,4,strip.Color(255,255,255));
  }
  for(x = 12; x < 17; x++){
  for(y = 0; y < 9; y++){
      set(x,y,strip.Color(255,255,255));
  }
  }
    strip.show(); // Initialize all pixels to 'off'
}


void set(int x,int y, uint32_t color) {
    if(y%2 == 0){
      if((x/3)%2 == 1){
       strip.setPixelColor((y*21)+(x-((x/6)*3)-3),color);
      }
    }else {
      if((x/3)%2 == 0){
        strip.setPixelColor(20+(y*21)-(x-((x/6)*3)),color);
      }
    }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

//0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17
//0,1,2,n,n,n,3,4,5,n,n ,n ,6 ,7 ,8 ,n ,n ,n,
//
//0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17
//n,n,n,0,1,2,n,n,n,3,4 ,5 ,n ,n ,n ,6 ,7 , 8
