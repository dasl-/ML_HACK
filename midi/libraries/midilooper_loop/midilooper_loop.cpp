#include "Arduino.h"
#include "MIDI.h"
#include "Midilooper_Loop.h"

const int Midilooper_Loop::MAX_INSTRUCTIONS;

const unsigned int TARGET_LENGTH_MARGIN = 300;

/*
 * Empty Constructor
 */
Midilooper_Loop::Midilooper_Loop() {
    
}

/*
 * Constructor
 */
Midilooper_Loop::Midilooper_Loop(int target_length) {
    _target_length = target_length;
    _last_position = 0;
    _current_instruction_position = 0;
}

/*
 * Start the playback
 */
void Midilooper_Loop::start() {
    _last_position = 0;
    _play_start = millis();
}

/*
 * Play the current position of the loop
 */
void Midilooper_Loop::play() {
    unsigned int _position = playbackPosition();
    
    if (_position != _last_position) {
        for (int i = 0; i < _current_instruction_position; i++) {
            unsigned int check_time = _instruction_times[i];
            if (check_time >= _last_position && check_time < _position) {
                 _instructions[i].run();
            }
        }
        
        _last_position = _position;
    }
}

/*
 * Delete this loop
 */
void Midilooper_Loop::deleteLoop() {

}

/*
 * Start recording
 */
void Midilooper_Loop::record() {
    _current_instruction_position = 0;
    _start = millis();
}

/*
 * Record the supplied instruction
 */
void Midilooper_Loop::recordInstruction(Midilooper_Instruction inst) {
    _instruction_times[_current_instruction_position] = (millis() - _start);
    _instructions[_current_instruction_position] = inst;
    _current_instruction_position++;
}

/*
 * Finalize the loop
 */
void Midilooper_Loop::finalize() {
    long loop_end = millis();
    length = loop_end - _start;
    
    if (length >= _target_length - TARGET_LENGTH_MARGIN && length <= _target_length + TARGET_LENGTH_MARGIN) {
        //exact length
        length = _target_length;
    } else if (length >= (_target_length / 2) - TARGET_LENGTH_MARGIN && length <= (_target_length / 2) + TARGET_LENGTH_MARGIN) {
        //half length
        length = (_target_length / 2);
    } else if (length >= (_target_length * 2) - TARGET_LENGTH_MARGIN && length <= (_target_length * 2) + TARGET_LENGTH_MARGIN) {
        //double length
        length = (_target_length * 2);
    }

    start();
}

/*
 * Get the current position within the loop
 */
unsigned int Midilooper_Loop::playbackPosition() {
    return (millis() - _start) % length;
}
