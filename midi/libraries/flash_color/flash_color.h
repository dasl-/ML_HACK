#ifndef FLASH_COLOR_H
#define FLASH_COLOR_H

#include "Adafruit_NeoPixel.h"

class Flash_Color {
    public:
        Flash_Color();

        void flashColor_setStripInstruction(byte, byte, byte, byte, byte);
        void flashColor_runStripInstruction();

        unsigned long instruction_step;
        unsigned long instruction_length;

    private:
        unsigned long expScale(float);

};

#endif