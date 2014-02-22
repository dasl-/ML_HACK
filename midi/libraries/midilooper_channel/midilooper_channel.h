#ifndef MIDILOOPER_CHANNEL_H
#define MIDILOOPER_CHANNEL_H

#include "Midilooper_Loop.h"
#include "Midilooper_Instruction.h"

class Midilooper_Channel {
    public:
        static const int MAX_LOOPS = 5;
        
        Midilooper_Channel();
        void attach(int, int, byte, int);
        void update();
        void handleInstruction(Midilooper_Instruction);
    
        bool _recording;
        bool _start;
    
    private:
        void playback();
        void record();
        void switchRecording();
        void startRecording();
        void endRecording();
        int getRecordButtonState();
        
        int 
            _midi_channel, _analog_pin, _led_pin,
            _recording_control_state, _recording_control_bouncing_state;
        unsigned int 
            _target_length;
        byte
            _bit_pos,
            _current_recording_position;
        bool 
            _record_on_loop_start;
        unsigned long 
            _prev_recording_control_clock;
        Midilooper_Loop
            _loops[MAX_LOOPS];
};

#endif
