/**
    @filename   :   epd1in54b-demo.ino
    @brief      :   1.54inch e-paper display (B) demo
    @author     :   Yehui from Waveshare

    Copyright (C) Waveshare     August 7 2017

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documnetation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to  whom the Software is
   furished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

// Library adapted by Bodmer

// 1.54" 3 colour display to NodeMCU connections
// for overlap mode

// Display    NodeMCU
// BUSY    -> Not connected
// RST     -> RST pin
// DC      -> D4  (ESP8266 GPIO 2)
// CS      -> D3  (ESP8266 GPIO 0)
// CLK     -> CLK (EPS8266 GPIO 6)
// DIN     -> SD1 (ESP8266 GPIO 8)
// GND     -> GND
// 3.3V    -> 3V3

// Note: DC, RST and BUSY pins are defined in library epdif.h file


#include <SPI.h>
#include <epd1in54b.h>
#include "imagedata.h"

void setup() {

  //       Invoke overlap mode
  //       CLK   SD0   SD1  D3     NodeMCU pin names
  //      SCLK   MISO MOSI  SS     SPI signal names
  //       CLK         DIN  CS     ePaper signal names (MISO not connected
  //        6     7     8    0     ESP8266 GPIO numbers
  SPI.pins( 6,    7,    8,   0);

  Serial.begin(9600);
  Epd epd;
  if (epd.Init() != 0) {
    Serial.print("e-Paper init failed");
    return;
  }
  epd.DisplayFrame(IMAGE_BLACK, IMAGE_RED);
}

void loop() {
  // put your main code here, to run repeatedly:

}
