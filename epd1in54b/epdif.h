/**
 *  @filename   :   epdif.h
 *  @brief      :   Header file of epdif.cpp providing EPD interface functions
 *                  Users have to implement all the functions in epdif.cpp
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef EPDIF_H
#define EPDIF_H

#include <Arduino.h>

// Pin definition for ESP8266 (e.g. NodeMCU)
// Connect display CLK signal to GPIO 14 (Node MCU pin D5)
// Connect display DIN signal to GPIO 13 (Node MCU pin D7)
// Connect display 3.3V to NodeMCU 3V3
// Connect display GND to NodeMCU GND
// Connect other pins as follows:
//      Display       GPIO   NodeMCU pin
#define BUSY_PIN        5 // D1
#define RST_PIN         4 // D2
#define DC_PIN          0 // D3
#define CS_PIN          2 // D4

// ESP32 pin definition example
//#define RST_PIN          4
//#define DC_PIN           2
//#define CS_PIN          15
//#define BUSY_PIN        21

// ESP8266 Overlap mode pin definition
// Do not use GPIO0 or GPIO2 for Busy line, they set the boot mode!

//#define RST_PIN         -1 // Connect EPD RST pin to ESP6266 RST
//#define DC_PIN           2 // NodeMCU pin D4
//#define CS_PIN          -1 // Defined in sketch in overlap mode as D3 (GPIO 0)
//#define BUSY_PIN         4 // Shared with DC, add 2K2 series resistor
//#define BUSY_PIN       255 // No busy pin connected, use delays in sketch



class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value); 
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
};

#endif
