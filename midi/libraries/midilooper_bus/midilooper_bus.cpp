#include "Arduino.h"
#include "SoftwareSerial.h"
#include "Midilooper_Bus.h"

SoftwareSerial sendSerial(19, 18); // RX, TX
SoftwareSerial getSerial(10, 11); // RX, TX

Midilooper_Bus::Midilooper_Bus() {
    sendSerial.begin(115200);
    getSerial.begin(115200);
}
 
void Midilooper_Bus::send(byte instruction_type, byte args[]) {
    Serial.println("SEND");
    Serial.println(instruction_type);
    sendSerial.write(instruction_type);
}

void Midilooper_Bus::get() {
    Serial.println("GET");
    if (getSerial.available()) {
        Serial.println(getSerial.read());
    }
}
