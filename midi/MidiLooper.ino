
#include <MIDI.h>
#include <Bounce.h>
#include <Adafruit_NeoPixel.h>
#include <midilooper_channel.h>
#include <midilooper_loop.h>
#include <midilooper_instruction.h>

const int MIDI_CHANNEL = 10;
const int CHANNELS = 1;

Midilooper_Channel channel_one = Midilooper_Channel();
//Midilooper_Channel channel_two = Midilooper_Channel();

//Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(21, 6, NEO_GRB + NEO_KHZ800);

/*
 * Initialize the Arduino
 */
void setup(){
    MIDI.begin(MIDI_CHANNEL);
    MIDI.turnThruOn();
    
    MIDI.setHandleNoteOn(midi_NoteOn);
    MIDI.setHandleNoteOff(midi_NoteOff);
    
    channel_one.attach(MIDI_CHANNEL, A0, byte(0), 13);
    //channel_two.attach(MIDI_CHANNEL, A0, byte(1), 13);
    
//    strip_1.begin();
//    strip_1.show();
}

/*
 * The main execution loop
 */
void loop() {
    MIDI.read();
    
    channel_one.update();
//    channel_two.update();
    
//    updateStrip();
}

void sendInstruction(Midilooper_Instruction inst) {
    channel_one.handleInstruction(inst);
//    channel_two.handleInstruction(inst);
}

void midi_NoteOn(byte midi_channel, byte pitch, byte velocity) {
    byte args[Midilooper_Instruction::MAX_INSTRUCTION_ARGS];
    args[0] = pitch;
    args[1] = velocity;
    Midilooper_Instruction inst(MIDI_CHANNEL, Midilooper_Instruction::NOTE_ON, args);
    sendInstruction(inst);
//    noteOn_strip(pitch, velocity);
}

void midi_NoteOff(byte midi_channel, byte pitch, byte velocity) {
    byte args[Midilooper_Instruction::MAX_INSTRUCTION_ARGS];
    args[0] = pitch;
    args[1] = velocity;
    Midilooper_Instruction inst(MIDI_CHANNEL, Midilooper_Instruction::NOTE_OFF, args);
    sendInstruction(inst);
}

//void noteOn_strip(byte pitch, byte velocity) {
//    setStripInstruction(pitch, velocity);
//}
//
//void updateStrip() {
//    runStripInstruction();
//}
