#include "Arduino.h"
#include "Midilooper_Bus.h"
#include "Flash_Color.h"

Midilooper_Bus::Midilooper_Bus() {

}

/**
 * Called on every MIDI transmit signal
 * @param instruction_type Midilooper_Instruction::NOTE_ON
 * @param args             [
 */
void Midilooper_Bus::run(byte instruction_type, byte args[]) {
    red = random(8);
    green = random(8);
    blue = random(8);

    while (red + green + blue <= 2) {
        red = random(8);
        green = random(8);
        blue = random(8);
    }

    Flash_Color flash = Flash_Color();
    flash.flashColor_setStripInstruction(60, 127, red, green, blue);
    flash.flashColor_runStripInstruction();


    while (flash.instruction_step <= flash.instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    // delay(tempo);

    // flashColor_setStripInstruction(60, 100, red, green, blue);
    // flashColor_runStripInstruction();
    // while (instruction_step <= instruction_length + 10) {
    //     flashColor_runStripInstruction();
    // }
    // delay(tempo);

    // flashColor_setStripInstruction(60, 64, red, green, blue);
    // flashColor_runStripInstruction();
    // while (instruction_step <= instruction_length + 10) {
    //     flashColor_runStripInstruction();
    // }
    // delay(tempo);

    // flashColor_setStripInstruction(60, 30, red, green, blue);
    // flashColor_runStripInstruction();
    // while (instruction_step <= instruction_length + 10) {
    //     flashColor_runStripInstruction();
    // }
    // delay(tempo);
}
