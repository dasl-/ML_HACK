#ifndef MIDILOOPER_BUS_H
#define MIDILOOPER_BUS_H

class Midilooper_Bus {
    public:
        Midilooper_Bus();
    
        void send(byte, byte[]);
        void get();
    
    private:
        int test;
    
};

#endif