/*
  RGBWConverter.h - Hue preserving RGB to RGBW conversion library for Arduino! Optimized for RGBW NeoPixel white color temperatures.
  Created by Mehmet Bertan Tarakçıoğlu, November 8, 2021.
  Copyright (c) 2021 Mehmet Bertan Tarakçıoğlu. Licensed under the MIT License.
*/
#ifndef RGBWConverter_h
#define RGBWConverter_h
#include "Arduino.h"

class RGBWConverter
{
    public:
        struct RGBW {
          uint8_t r, g, b, w;
        };
    public:
        RGBWConverter(uint8_t wTempRed, uint8_t wTempGreen, uint8_t wTempBlue, bool blueCorrectionEnabled);
        RGBW RGBToRGBW(uint8_t r, uint8_t g, uint8_t b);
    private:
        uint8_t _wTempRed;
        uint8_t _wTempGreen;
        uint8_t _wTempBlue;
        bool _blueCorrectionEnabled;
};
#endif