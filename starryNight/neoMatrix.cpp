#include "neoMatrix.h"
#include <Arduino.h>

neoMatrix::neoMatrix(Adafruit_NeoPixel* _ledMatrix, size_t _numCols):
        ledMatrix(_ledMatrix),
        numCols(_numCols){}

void neoMatrix::begin(){
    for(size_t n = 0; n < numCols; n++){
        ledMatrix[n].begin();
    }
}

void neoMatrix::show(){
    for(size_t n = 0; n < numCols; n++){
        ledMatrix[n].show();
    }
}

void neoMatrix::setBrightness(uint8_t brightness){
    if(brightness >= MAX_BRIGHTNESS)
        brightness = MAX_BRIGHTNESS;

    for(size_t n = 0; n < numCols; n++){
        ledMatrix[n].setBrightness(brightness);
    }
}

void neoMatrix::setMode(e_patterns modeSetting){
    if((modeSetting >= off) && (modeSetting < PATTERN_NUM)){
        mode = modeSetting;
    } else{
        mode = off;
    }
}

void neoMatrix::executePattern(){
    switch(mode){
        case off:
            offPattern();
            break;
        case on:
            onPattern();
            break;
        case starryNight:

            break;
        case rain:

            break;
        case wave:

            break;
        case droplet:

            break;
        default:

            break;
    }
}

void neoMatrix::starryNight(){
    
}

void neoMatrix::offPattern(){
    for(uint16_t n = 0; n < ledMatrix[0].numPixels(); n++){
        for(uint8_t col = 0; col < numCols; col++){
            ledMatrix[col].gamma32(Adafruit_NeoPixel::ColorHSV(0, 0, 0))
            ledMatrix[col].show();
        }
        delay(10);
    }
}

void neoMatrix::onPattern(s_hsv hsv={0, 0, MAX_BRIGHTNESS}){
    for(uint16_t n = 0; n < ledMatrix[0].numPixels(); n++){
        for(uint8_t col = 0; col < numCols; col++){
            ledMatrix[col].Adafruit_NeoPixel::ColorHSV(hsv.hue , hsv.saturation, hsv.value);
            ledMatrix[col].show();
        }
        delay(10);
    }
}
