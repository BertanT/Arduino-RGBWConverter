/*
	RGBW Converter Test

	This code shows a given RGB color value and its RGBW conversion with an interval of  1 second
  on RGBW NeoPixel LEDs. Check out the line comments to adjust the settings to your liking!
  RGBW NeoPixel hardware and the Adafruit Neopixel Library are required for this example.

  If this is your first time using NeoPixles, check out the guide below from Adafruit!
  https://learn.adafruit.com/adafruit-neopixel-uberguide


	Circuitry - Using an Arduino Uno & Not a Large Number of NeoPixels:
	* NeoPixel PWR +5V    -> Arduino 5V Pin
	* NeoPixel GND        -> Arduino GND Pin
  * NeoPixel Data Input -> Arduino Digital Pin 10 (Add a 470 Ohm resistor if your NeoPixels don't have one built-in!)

	Created and modified on November 14, 2021.
	By M. Bertan Tarakçıoğlu.

  For more in-depth library documentation, see the GitHub repo below.  
	https://github.com/BertanT/Arduino-RGBWConverter

  Copyright (c) 2021 M. Bertan Tarakçıoğlu, Licensed under the MIT License.

*/

// Include the NeoPixel and RGBW Converter libraries.
#include <Adafruit_NeoPixel.h>
#include <RGBWConverter.h>

// Which pin are the NeoPixels connected to?
#define LED_PIN 10

// How many NeoPixels are you using?
#define LED_COUNT 8

// How bright do you want your NeoPixels to be? Values between 0-255.
#define LED_BRIGHTNESS 150

// Define the RGB values to be converted to RGBW.
#define R 153
#define G 42
#define B 53

// Declare the NeoPixels...
// Change the "NEO_GRBW" argument to "NEO_RGBW" if you are getting unexpected results!
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

// Converter object initialization:
// * The first three arguments define the RGB correspondent of RGBW NeoPixels' white(W) color temperature (Values between 0-255).
// In my case the values below worked pretty well. Try adjusting them for yourself to get the best results!
// * The fourth argument is a boolean which enables blue tone correction when set to true. In some RGBW NeoPixels, the blue color
//   is mixed with white. Thus enabling blue correction is crucial for color accuracy.
RGBWConverter converter(255, 255, 255, true);

// Initialize the global variables, their values to be set later inside the setup function.
uint32_t rgbColor;
uint32_t rgbwColor;

void setup() {
  // Start the NeoPixels, set the brightness, and turn them all off.
  pixels.begin();
  pixels.setBrightness(LED_BRIGHTNESS);
  pixels.show();

  // Create the RGB Color object using the defined RGB values above and assign it to rgbColor. White value is 0.
  rgbColor = pixels.Color(R, G, B, 0);

  // Convert the RGB color values to RGBW - results returned in an integer array as follows: {R, G, B, W}
  int* c = converter.RGBToRGBW(R, G, B);

  // Create the RGBW Color object using the converted values and assign it to rgbwColor.
  rgbwColor = pixels.Color(c[0], c[1], c[2], c[3]);
}

void loop() {
  // Set all pixels to show the RGB color.
  pixels.fill(rgbColor);
  pixels.show();
  // Wait 1 second
  delay(1000);
  // This time, set all pixels to show the RGBW color.
  pixels.fill(rgbwColor);
  pixels.show();
  // Wait another second before repeating.
  delay(1000);
}