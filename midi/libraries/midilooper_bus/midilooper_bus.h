#ifndef MIDILOOPER_BUS_H
#define MIDILOOPER_BUS_H

class Midilooper_Bus {
    public:
        Midilooper_Bus();
    
        void run(byte, byte[]);
    
    private:
        int test;
    
};

#endif