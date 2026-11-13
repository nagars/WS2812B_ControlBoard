#ifndef NEOMATRIX_H
#define NEOMATRIX_H

#include <Adafruit_NeoPixel.h>

// Brightness ranges from 0 to 255
#define MAX_BRIGHTNESS 127

#define MAX_SATURATION  255
#define MAX_HUE         65535

// Different lighting patterns
typedef enum {
off,
on,
starryNight,
rain,
wave,
dropplet,
PATTERN_NUM,
}e_patterns;

typedef struct {
    uint16_t hue;
    uint8_t saturation;
    uint8_t value;
}s_hsv;

class neoMatrix{
    public:
    neoMatrix(Adafruit_NeoPixel* _ledMatrix, size_t _numCols);

    void begin();
    void show();
    void setBrightness(uint8_t brightness);
    void setMode(e_patterns);

    void executePattern();

    private:
    Adafruit_NeoPixel* ledMatrix;
    size_t numCols;
    uint8_t mode;

    void offPattern();
    void onPattern(s_hsv hsv);
};

#endif
