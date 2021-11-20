# Arduino RGBW Converter Library
## 👀 Overview
A simple library with one job: converting RGB colors to RGBW! Optimized for RGBW NeoPixel white color temperatures. Just enter the RGB correspondent of the white LEDs, and you are good to go! In addition, it has the option to correct the blue light tone, which is crucial to get an accurate color output on some RGBW LEDs.
## 🚀 Installation
You can get this library on the Arduino library manager, or download this repository as a `zip` archive and install it to Arduino IDE. For further details on Arduino library installation, please check out this [great guide on the Arduino website!](https://www.arduino.cc/en/guide/libraries#toc4)
## 💻 Usage and Features
In addition to the documentation here, be sure to check out the [example sketch](https://github.com/BertanT/Arduino-RGBWConverter/blob/42ad1b3f1cf55be85637c7fa38100ea5955f903c/examples/RGBW_Converter_Demo/RGBW_Converter_Demo.ino) to learn how the library works!
### Initialization
```cpp
RGBWConverter converter(240, 215, 200, true);
```
Initializes an `RGBWConverter` object with the name `converter` with the *neutral white values* being 240, 215, 200; as well as enabling *blue correction*.
#### Arguments
1. Integer between 0-255. Sets the **red** value for the *neutral white* color of the RGBW NeoPixels.
2. Integer between 0-255. Sets the **green** value for the *neutral white* color of the RGBW NeoPixels.
3. Integer between 0-255. Sets the **blue** value for the *neutral white* color of the RGBW NeoPixels.
4. Boolean. If set to `true`, enables the *blue correction* feature.

*Neutral white values* refer to the RGB value correspondent of the maximum white (W) setting on the RGBW NeoPixels. This is used to correct the color temperature while performing the color conversion, as the white (W) is often not a pure white color. The example values work pretty well for [RGBW NeoPixel strips from Adafruit](https://www.adafruit.com/product/2824?length=1).

On some RGBW NeoPixels like the RGBW NeoPixel strips from Adafruit, the blue color is not pure blue and contains a little bit of white. The *blue correction* feature is used to correct the color on these NeoPixel LEDs.
### Converting RGB to RGBW!
```cpp
converter.RGBToRGBW(53, 42, 153);
```
Uses the `RGBToRGBW`method of the library to convert a given RGB color input to RGBW color in the form of a 4-element integer array.
#### Arguments
1. Integer between 0-255. Specifies the **red** value of the color you are willing to convert.
2. Integer between 0-255. Specifies the **green** value of the color you are willing to convert.
3. Integer between 0-255. Specifies the **blue** value of the color you are willing to convert.
#### Return Value
Returns a 4-element integer array containing the converted RGBW values, each being between 0-255 and ordered as follows:
```cpp
{R, G, B, W}
```
## 📃 License
Licensed under the MIT License

Copyright (c) 2021 M. Bertan Tarakçıoğlu
