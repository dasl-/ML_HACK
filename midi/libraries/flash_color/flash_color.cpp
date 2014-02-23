#include "Arduino.h"
#include "Flash_Color.h"
#include "Adafruit_NeoPixel.h"

unsigned long instruction_start = 0;
unsigned long instruction_step = 0;
unsigned long instruction_length = 0;
unsigned long instruction_start_val = 0;

/**
 * 0: pitch
 * 1: velocity
 * 2: red
 * 3: green
 * 4: blue
 */
int instruction_args[5];
int pixels;

int red;
int green;
int blue;

float ramp_time = 50;
int base_pixel = 8;

/** @type {Number} control the delay() times */
int tempo = 400;




Flash_Color::Flash_Color() {

}

void Flash_Color::flashColor_setStripInstruction(byte pitch, byte velocity, byte red, byte green, byte blue) {
    // instruction_start = millis();
    // instruction_length = 200;
    // instruction_start_val = expScale(velocity);

    // instruction_args[0] = pitch;
    // instruction_args[1] = velocity;
    // instruction_args[2] = red;
    // instruction_args[3] = green;
    // instruction_args[4] = blue;
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(21, 6, NEO_GRB + NEO_KHZ800);
        uint32_t color = strip_1.Color(
            128,
            128,
            128
        );

        for(uint16_t i = 0; i < 21; i++) {
            strip_1.setPixelColor(i, color);
        }
        strip_1.show();

        Serial.println("asd");
}

void Flash_Color::flashColor_runStripInstruction() {
//     unsigned long clock = millis();
//     instruction_step = clock - instruction_start;

//     if (instruction_step <= instruction_length) {
//         //fade out
//         float fade_by = instruction_start_val / (float) instruction_length;
//         int set_val = instruction_start_val - (instruction_step * fade_by);

//         byte pitch = instruction_args[0];
//         byte velocity = instruction_args[1];
//         byte red = instruction_args[2];
//         byte green = instruction_args[3];
//         byte blue = instruction_args[4];

//         uint32_t color = strip_1.Color(
//             ((red)   ? set_val * (float(red)   / 8) : 0),
//             ((green) ? set_val * (float(green) / 8) : 0),
//             ((blue)  ? set_val * (float(blue)  / 8) : 0)
//         );

//         for(uint16_t i = 0; i < pixels; i++) {
//             strip_1.setPixelColor(i, color);
//         }
//         strip_1.show();
//     } else if (instruction_step <= instruction_length + 10) {
//         uint32_t color = strip_1.Color(0, 0, 0);
//         for(uint16_t i = 0; i < pixels; i++) {
//             strip_1.setPixelColor(i, color);
//         }
//         strip_1.show();
//     }

}

float a = 3.351;
float b = 1.034;
unsigned long Flash_Color::expScale(float val) {
    return a * (pow(b, val));
}