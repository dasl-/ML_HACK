
#include <SoftwareSerial.h>
#include <MIDI.h>
#include <midilooper_bus.h>
#include <midilooper_instruction.h>

Midilooper_Bus bus = Midilooper_Bus();

/*
 * Initialize the Arduino
 */
void setup(){
    
}

/*
 * The main execution loop
 */
void loop() {
    byte args[2];
    args[0] = (byte) 60;
    args[1] = (byte) 120;
    bus.run(Midilooper_Instruction::NOTE_ON, args);
    delay(1000);
}
