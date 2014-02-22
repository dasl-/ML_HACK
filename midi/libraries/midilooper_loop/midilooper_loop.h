#ifndef MIDILOOPER_LOOP_H
#define MIDILOOPER_LOOP_H

#include "Midilooper_Instruction.h"

class Midilooper_Loop {
    public:
        static const int MAX_INSTRUCTIONS = 40;
        
        Midilooper_Loop();
        Midilooper_Loop(int);
        void start();
        void play();
        void deleteLoop();
        void record();
        void recordInstruction(Midilooper_Instruction);
        void finalize();
        unsigned int playbackPosition();
        
        unsigned int length;
        
    private:
        unsigned long
            _start, _play_start;
        unsigned int
            _target_length, _last_position, _instruction_times[MAX_INSTRUCTIONS];
        byte
            _current_instruction_position;
        Midilooper_Instruction
            _instructions[MAX_INSTRUCTIONS];
};

#endif
