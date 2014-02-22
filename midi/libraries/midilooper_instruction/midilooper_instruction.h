#ifndef MIDILOOPER_INSTRUCTION_H
#define MIDILOOPER_INSTRUCTION_H

class Midilooper_Instruction {
    public:
        static const int MAX_INSTRUCTION_ARGS = 2;
        static const byte NOTE_ON = 1;
        static const byte NOTE_OFF = 2;
        
        Midilooper_Instruction();
        Midilooper_Instruction(int, byte, byte[]);
        void run();
        
    private:
        void setArguments(byte[]);
        void sendNoteOn(byte, byte);
        void sendNoteOff(byte, byte);
        
        int
            _channel;
        byte 
            _instruction_type, _args[MAX_INSTRUCTION_ARGS];
};

#endif
