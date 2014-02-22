#include "Arduino.h"
#include "MIDI.h"
#include "Midilooper_Instruction.h"

const int Midilooper_Instruction::MAX_INSTRUCTION_ARGS;
const byte Midilooper_Instruction::NOTE_ON;
const byte Midilooper_Instruction::NOTE_OFF;

/*
 * Empty Constructor
 */
Midilooper_Instruction::Midilooper_Instruction() {
    
}

/*
 * Constructor
 */
Midilooper_Instruction::Midilooper_Instruction(int channel, byte instruction_type, byte args[]) {
    _channel = channel;
    _instruction_type = instruction_type;
    setArguments(args);
}

/*
 * Run the instruction
 */
void Midilooper_Instruction::run() {
    if (_instruction_type == NOTE_ON) {
        sendNoteOn(_args[0], _args[1]);
    } else if (_instruction_type == NOTE_OFF) {
        sendNoteOff(_args[0], _args[1]);
    }
}

/*
 * Update the passed array to have NULL in non-used indexes
 */
void Midilooper_Instruction::setArguments(byte args[]) {
    int from_index = sizeof(args);
    for (int i = 0; i < MAX_INSTRUCTION_ARGS; i++) {
        if (i < from_index) {
            _args[i] = args[i];
        } else {
            _args[i] = NULL;
        }
    }
}

/*
 * Send the note on command to midi out
 */
void Midilooper_Instruction::sendNoteOn(byte pitch, byte velocity) {
    MIDI.sendNoteOn(pitch, velocity, _channel);
}

/*
 * Send the note off command to midi out
 */
void Midilooper_Instruction::sendNoteOff(byte pitch, byte velocity) {
    MIDI.sendNoteOff(pitch, velocity, _channel);
}
