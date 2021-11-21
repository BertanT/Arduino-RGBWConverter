/*
  RGBWConverter.cpp - Hue preserving RGB to RGBW conversion library for Arduino! Optimized for RGBW NeoPixel white color temperatures.
  Created by Mehmet Bertan Tarakçıoğlu, November 8, 2021.
  Copyright (c) 2021 Mehmet Bertan Tarakçıoğlu. Licensed under the MIT License.
*/
#include "Arduino.h"
#include "RGBWConverter.h"

// Constructor
RGBWConverter::RGBWConverter(uint8_t wTempRed = 255, uint8_t wTempGreen = 255, uint8_t wTempBlue = 255, bool blueCorrectionEnabled = false)
{
    // Set white color temperature values
    _wTempRed = wTempRed;
    _wTempGreen = wTempGreen;
    _wTempBlue = wTempBlue;
    // Set blue correctiion. If enabled, the blue color will be corrected for RGBW LEDs that mix white to the blue color.
    _blueCorrectionEnabled = blueCorrectionEnabled;
}

// The  RGB to RGBW conversion function.
int* RGBWConverter::RGBToRGBW(uint8_t r, uint8_t g, uint8_t b)
{
    // Calculate all of the color's white values corrected taking into account the white color temperature.
    float wRed = r * (255 / _wTempRed);
    float wGreen = g * (255 / _wTempGreen);
    float wBlue = b * (255 / _wTempBlue);
    
    // Determine the smallest white value from above.
    uint8_t wMin = round(min(wRed, min(wGreen, wBlue)));
    
    // Make the color with the smallest white value to be the output white value
    uint8_t wOut;
    if (wMin == wRed) {
        wOut = r;
    } else if (wMin == wGreen) {
        wOut = g;
    }else {
        wOut =  b;
    }
    
    // Calculate the output red, green and blue values, taking into account the white color temperature.
    uint8_t rOut = round(r - wOut * (_wTempRed / 255));
    uint8_t gOut = round(g - wOut * (_wTempGreen / 255));
    uint8_t bOut = round(b - wOut * (_wTempBlue / 255));
    
    // Apply the blue correction in enabled.
    //This is required on some RGBW NeoPixels which have a little bit of mixed into the blue color.
    if (_blueCorrectionEnabled)
    {
        wOut -= bOut * 0.2;
    }
    
    // Return the output values.
    static int output[4] = {rOut, gOut, bOut, wOut};
    return output;
}
