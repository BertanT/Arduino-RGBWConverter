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
    // Set blue correctiion. If enabled, the blue color will be corrected to the white color temperature.
    _blueCorrectionEnabled = blueCorrectionEnabled;
}

// The  RGB to RGBW conversion function.
int* RGBWConverter::RGBToRGBW(uint8_t r, uint8_t g, uint8_t b)
{
    // Calculate all of the color's white values corrected taking into account the white color temperature.
    float wRed = r * (_wTempRed / 255);
    float wGreen = g * (_wTempGreen / 255);
    float wBlue = b * (_wTempBlue / 255);
    // Chose the smallest white value from above to be the output white value.
    uint8_t wOut = round(min(wRed, min(wGreen, wBlue)));
    // Calculate the output red, green and blue values, taking into account the white color temperature.
    uint8_t rOut = round(r - wOut * (_wTempRed / 255));
    uint8_t gOut = round(g - wOut * (_wTempGreen / 255));
    uint8_t bOut = round(b - wOut * ((_blueCorrectionEnabled ? 0.1 : 1) * (_wTempBlue / 255)));
    // Return the output values.
    static int output[4] = {rOut, gOut, bOut, wOut};
    return output;
}