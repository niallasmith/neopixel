#include <Adafruit_NeoPixel.h>
#define LED_COUNT 16
#define LED_PIN    0
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.clear();
  strip.show(); // Initialize all pixels to 'off'

  //  layers();
  //  float spiralMap[16] = {3, 2, 1, 0, 4, 8, 12, 13, 14, 15, 11, 7, 6, 5, 9, 10};
  //  for (int i = 0; i <= LED_COUNT - 1; i++) {
  //    strip.clear();
  //    uint32_t hue = 0;
  //    uint32_t value = 128;
  //    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
  //    strip.setPixelColor(spiralMap[i-1], rgbcolor);
  //    strip.show();
  //    delay(1000);
  //  }
}

void loop() {


  switch (random(11)) {
    case 0:
      {
        chase();
      }
    case 1:
      {
        RGBrandom();
      }
    case 2:
      {
        snake();
      }
    case 3:
      {
        snakeRandom();
      }
    case 4:
      {
        spinning(random(2));
      }
    case 5:
      {
        ripple(random(2));
      }
    case 6:
      {
        huefade();
      }
    case 7:
      {
        zigzag(random(2));
      }
    case 8:
      {
        spiral(random(2));
      }
    case 9:
      {
        wave();
      }
    case 10:
      {
        layers();
      }
  }
}


void ripple(int dir) {
  //float rowMap[16] = {0, 0, 0, 0, 1.57, 1.57, 1.57, 1.57, 3.14, 3.14, 3.14, 3.14, 4.71, 4.71, 4.71, 4.71};
  float rowMap[16] = {0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};
  strip.clear();
  int startTime = millis();
  float offset = 0;

  while (millis() - startTime <= 10000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = (65535 / 2) * (sin(0.52 * rowMap[i] + ((-1) ^ (dir)) * offset) + 1);
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
    offset = offset + 0.007;
    delay(5);
  }
}

void spinning(int dir) {
  int clockAngleMap[16] = {315, 338, 23, 45, 293, 315, 45, 68, 248, 225, 135, 113, 225, 203, 158, 135};
  strip.clear();
  int startTime = millis();
  int offset = 0;

  while (millis() - startTime <= 15000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = (65535 / 360) * clockAngleMap[i] - ((-1) ^ (dir)) * offset;
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
    offset = offset + 100;
    delay(10);
  }
}

void chase() {
  strip.clear();
  uint32_t hue1;
  uint32_t hue2;
  int wrap[16] = {0, 1, 2, 3, 7, 6, 5, 4, 8, 9, 10, 11, 15, 14, 13, 12};

  for (int i = LED_COUNT - 1; i >= 0; i--) {
    strip.clear();
    uint32_t hue = random(65536);
    uint32_t value = 128;
    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));

    uint32_t value1 = 96;
    uint32_t rgbcolor1 = strip.gamma32(strip.ColorHSV(hue1, 255, value1));

    uint32_t value2 = 64;
    uint32_t rgbcolor2 = strip.gamma32(strip.ColorHSV(hue2, 255, value2));

    strip.setPixelColor(wrap[i], rgbcolor);
    strip.setPixelColor(wrap[i + 1], rgbcolor1);
    strip.setPixelColor(wrap[i + 2], rgbcolor2);

    hue1 = hue;
    hue2 = hue1;

    strip.show();
    delay(250);
  }

  for (int i = 0; i <= LED_COUNT - 1; i++) {
    strip.clear();
    uint32_t hue = random(65536);
    uint32_t value = 128;
    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));

    uint32_t value1 = 96;
    uint32_t rgbcolor1 = strip.gamma32(strip.ColorHSV(hue1, 255, value1));

    uint32_t value2 = 64;
    uint32_t rgbcolor2 = strip.gamma32(strip.ColorHSV(hue2, 255, value2));

    strip.setPixelColor(wrap[i], rgbcolor);
    strip.setPixelColor(wrap[i - 1], rgbcolor1);
    strip.setPixelColor(wrap[i - 2], rgbcolor2);

    hue1 = hue;
    hue2 = hue1;

    strip.show();
    delay(250);
  }
}

void RGBrandom() {
  for (int i = 0; i <= 10; i++) {
    strip.clear();
    uint32_t hue = random(65536);
    uint32_t value = 128;
    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
    strip.fill(rgbcolor);
    strip.show();
    delay(500);
  }
}

void snake() {
  strip.clear();
  int wrap[16] = {0, 1, 2, 3, 7, 6, 5, 4, 8, 9, 10, 11, 15, 14, 13, 12};
  uint32_t hue = random(65536);

  for (int i = LED_COUNT - 1; i >= 0; i--) {
    uint32_t value = 128;
    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
    strip.setPixelColor(wrap[i], rgbcolor);
    strip.show();
    delay(250);
  }

  for (int i = 0; i <= LED_COUNT - 1; i++) {
    strip.setPixelColor(wrap[i], 0, 0, 0);
    strip.show();
    delay(250);
  }
}

void snakeRandom() {
  strip.clear();
  int wrap[16] = {0, 1, 2, 3, 7, 6, 5, 4, 8, 9, 10, 11, 15, 14, 13, 12};

  for (int i = LED_COUNT - 1; i >= 0; i--) {
    uint32_t hue = random(65536);
    uint32_t value = 128;
    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
    strip.setPixelColor(wrap[i], rgbcolor);
    strip.show();
    delay(250);
  }

  for (int i = 0; i <= LED_COUNT - 1; i++) {
    strip.setPixelColor(wrap[i], 0, 0, 0);
    strip.show();
    delay(250);
  }
}

void zigzag(int dir) {
  float zigzagMap[16] = {0, 1, 0, 1, 1, 2, 1, 2, 2, 3, 2, 3, 3, 4, 3, 4};
  strip.clear();
  int startTime = millis();
  float offset = 0;

  while (millis() - startTime <= 10000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = (65535 / 4) * zigzagMap[i] - (((-1) ^ (dir)) * offset);
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
    offset = offset + 50;
    delay(5);
  }
}

void huefade() {
  strip.clear();
  int startTime = millis();
  int offset = 0;

  while (millis() - startTime <= 10000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = 65535 + offset;
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
    offset = offset + 100;
    delay(5);
  }
}


void tetrisRain() {
  strip.clear();
  int startTime = millis();
  int offset = 0;

  while (millis() - startTime <= 10000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = 65535 + offset;
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
    offset = offset + 100;
    delay(5);
  }
  delay(250);
}

void spiral(int dir) {
  int spiralMap[16] = {3, 2, 1, 0, 4, 8, 12, 13, 14, 15, 11, 7, 6, 5, 9, 10};
  strip.clear();
  int startTime = millis();
  int offset = 0;

  while (millis() - startTime <= 15000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = (65535 / 15) * i - (((-1) ^ (dir)) * offset);
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(spiralMap[i], rgbcolor);
    }
    strip.show();
    offset = offset + 50;
    delay(5);
  }
}

void wave() {
  int waveMap[16] = {3, 2, 1, 0, 4, 8, 12, 13, 14, 15, 11, 7, 6, 5, 9, 10};
  strip.clear();
  int startTime = millis();
  int offset = 0;

  while (millis() - startTime <= 15000) {
    for (int i = 0; i <= LED_COUNT - 1; i++) {
      uint32_t hue = (65535 / 15) * waveMap[i] + offset;
      uint32_t value = 128;
      uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
      strip.setPixelColor(waveMap[i], rgbcolor);
    }
    strip.show();
    offset = offset + 100;
    delay(5);
  }
}

void layers() {
  uint32_t hue = random(65535);
  uint32_t value = 128;
  uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue, 255, value));
  strip.clear();
  int startTime = millis();

  while (millis() - startTime <= 10000) {
    strip.clear();
    for (int i = 0; i <= 4; i++) {
      strip.fill(rgbcolor, 4 * (i - 1), 4);
      strip.fill(0, 4 * (i - 2), 4);
      strip.show();
      delay(500);
    }

    for (int i = 0; i <= 3; i++) {
      strip.fill(rgbcolor, 4 * (i - 1), 4);
      strip.fill(0, 4 * (i - 2), 4);
      strip.show();
      delay(500);
    }

    for (int i = 0; i <= 2; i++) {
      strip.fill(rgbcolor, 4 * (i - 1), 4);
      strip.fill(0, 4 * (i - 2), 4);
      strip.show();
      delay(500);
    }

    strip.fill(rgbcolor, 0, 4);
    strip.show();
    delay(1000);
  }
}
