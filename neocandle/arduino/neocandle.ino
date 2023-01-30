/*

Imitation candle made of a ring of 12 NeoPixels (WS2812B's)
1. Adjustable hue limits to adjust colour
2. Adjustable brightness limits to adjust brightness
3. Two layers of brightness noise for better candle effect with adjustable timing for both

Default values are dialed in to my tastes, but adjust to your hearts content!

*/

#include <Adafruit_NeoPixel.h>
#define LED_COUNT 12
#define LED_PIN 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int fireHue[12], int fireVal[12];

// hue range
int minHue = 0; // minimum hue value
int maxHue = 3800; // maximum hue value

// brightness range
int minBright = 52; // minimum brightness value
int maxBright = 72; // minimum brightness value

// slow change duration range
int slowMinDelay = 600; // minimum slow change duration in milliseconds
int slowMaxDelay = 1000; // maximum slow change duration in milliseconds

// flicker duration range
int flickerMinDelay = 80; // minimum flicker duration in milliseconds
int flickerMaxDelay = 120; // maximum flicker duration in milliseconds

int flickerHue = 400; // Max change in hue value during flicker changes (note: values range +/- this value, so true deviation is double this amount)
int flickerBright = 6; // Max change in hue value during flicker changes (note: values range +/- this value, so true deviation is double this amount)

void setup() {
  strip.begin();
  strip.clear();
  strip.show(); // Initialize all pixels to 'off'

  // intialise set hue values for each neopixel, hue will only vary by +/- flickerHue around this value forever
  for (int i = 0; i <= LED_COUNT - 1; i++) {
    fireHue[i] = random(minHue, maxHue);
  }
}

void loop() {

  // initialise set brightness values for each neopixel, brightness will vary by +/- flickerBright around this value until this loop repeats
  for (int i = 0; i <= LED_COUNT - 1; i++) {
    fireVal[i] = random(minBright, maxBright);
  }

  int duration = random(slowMinDelay, slowMaxDelay); // generate random 'long term' duration between slowMinDelay and slowMaxDelay
  
  int startTime = millis();
  while (startTime - millis() > duration) { // repeat while loop for 'duration' amount of time
    strip.clear();
    for (int i = 0; i <= LED_COUNT - 1; i++) { // for all neopixels
      // generate RGB colour based on hue (with random deviation), full saturation and value (with random deviation) 
      uint32_t rgbcolor = strip.ColorHSV(fireHue[i] + random(-flickerHue, flickerHue), 255, fireVal[i] + random(-flickerBright,flickerBright)); 
      strip.setPixelColor(i, rgbcolor); // set neopixel colour
    }
    strip.show(); // display neopixel colours in array
    delay(random(flickerMinDelay,flickerMaxDelay)); // delay to keep this colour for a random amount of time
  }
}
