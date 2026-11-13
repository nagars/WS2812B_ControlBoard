#include "neoMatrix.h"

#define D0PIN       0
#define D1PIN       1
#define D2PIN       2
#define D3PIN       21
#define D4PIN       22      // Pin D4 on XIAO ESP32C6
#define D5PIN       23      

#define NUMPIXELS 300//60        // Number of NeoPixels in your strip or ring 
#define LED_PIN   15        // On Board LED

//uint8_t stripPins [] = {D4PIN, D3PIN, D2PIN, D1PIN, D0PIN};

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number
// Parameter 3 = pixel type flags (e.g., NEO_GRB + NEO_KHZ800)
//Adafruit_NeoPixel pixels(NUMPIXELS, DPIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel ledArr[] = {
  Adafruit_NeoPixel (NUMPIXELS, D4PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel (NUMPIXELS, D3PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel (NUMPIXELS, D2PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel (NUMPIXELS, D1PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel (NUMPIXELS, D0PIN, NEO_GRB + NEO_KHZ800)
};

neoMatrix ledMatrix(ledArr, std::size(ledArr));

void setup() {
  ledMatrix.begin();
  ledMatrix.show();
  ledMatrix.setBrightness(50);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  ledMatrix.setMode(e_patterns::on);
  ledMatrix.executePattern();
  ledMatrix.setMode(e_patterns::off);
  ledMatrix.executePattern();
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  delay(1000);

}
