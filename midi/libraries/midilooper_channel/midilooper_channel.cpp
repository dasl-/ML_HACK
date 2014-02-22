#include "Arduino.h"
#include "MIDI.h"
#include "Midilooper_Channel.h"
#include "Midilooper_Loop.h"
#include "Midilooper_Instruction.h"

const int Midilooper_Channel::MAX_LOOPS;

const int DEBOUNCE_LENGTH = 200;

/*
 * Constructor
 */
Midilooper_Channel::Midilooper_Channel() {
    _target_length = 0;
    _current_recording_position = 0;
    _recording = false;
    _record_on_loop_start = false;
    
    _start = false;
    _recording_control_bouncing_state = LOW;
}

/*
 * Initialize the Midi Channel
 */
void Midilooper_Channel::attach(int channel, int analog_pin, byte bit_pos, int led_pin) {
    _prev_recording_control_clock = 0;
    
    _midi_channel = channel;
    _analog_pin = analog_pin;
    _bit_pos = bit_pos;
    _led_pin = led_pin;
    
    pinMode(_led_pin, OUTPUT);
    digitalWrite(_led_pin, LOW);
}

/*
 * Update the Midi channel (should be run in loop)
 */
void Midilooper_Channel::update() {
     playback();
     record();
}

/*
 * Play all loops in this channel
 */
void Midilooper_Channel::playback() {
    for (int i = 0; i < _current_recording_position; i++) {
        _loops[i].play();
    }
}

/*
 * Check if we should be recording a new loop
 */
void Midilooper_Channel::record() {
    int debounced_record_state = getRecordButtonState();
    
    if (_start) {
        if (debounced_record_state != _recording_control_state) {
            _recording_control_state = debounced_record_state;
            
            //the button has been pressed successfully
            if (!_recording && _current_recording_position > 0) {
                //start recording at the beginning of the last loop
                _record_on_loop_start = true;
            } else {
                //start/stop recording now
                switchRecording();
            }

        }
    
        if (_record_on_loop_start) {
            unsigned int loop_zero_pos = _loops[0].playbackPosition();
            if (loop_zero_pos <= 5 || loop_zero_pos >= _loops[0].length - 5) {
                _record_on_loop_start = false;
                switchRecording();
            }
        }
    }
}

/*
 * Toggle the recording value
 */
void Midilooper_Channel::switchRecording() {
    _recording = !_recording;
    
    if (_recording) {
        startRecording();
    } else {
        endRecording();
    }
}

/*
 * Start recording a new loop
 */
void Midilooper_Channel::startRecording() {
    //create a new loop
    Midilooper_Loop midiloop = Midilooper_Loop(_target_length);
    midiloop.record();
    
    _loops[_current_recording_position] = midiloop;
    
    digitalWrite(_led_pin, HIGH);
}

/*
 * End recording of the current loop
 */
void Midilooper_Channel::endRecording() {
    //finalize the current loop
    _loops[_current_recording_position].finalize();
    
    if (_current_recording_position == 0) {
        _target_length = _loops[_current_recording_position].length;
    }

    //ready the next loop
    _current_recording_position++;
    
    digitalWrite(_led_pin, LOW);
}

/*
 * handle a midi instruction
 */
void Midilooper_Channel::handleInstruction(Midilooper_Instruction inst) {
    if (_recording) {
        _loops[_current_recording_position].recordInstruction(inst);
    }
}

/*
 * Get the debounced recording button state
 */
int Midilooper_Channel::getRecordButtonState() {
    unsigned long clock = millis();
    
    float sensor_val = (1022 - (float(analogRead(_analog_pin)))) / 10;
    int current_state = int(sensor_val + .5);
    int return_state;
    
    if (_recording_control_bouncing_state != current_state) {
        //new bouncing
        _prev_recording_control_clock = clock;
        return_state = _recording_control_state;
    } else if (clock - _prev_recording_control_clock >= DEBOUNCE_LENGTH) {
        //debounced
        return_state = bitRead(current_state, _bit_pos);
        if (!_start) {
            _recording_control_state = return_state;
        }
        _start = true;
    } else {
        //good bouncing
        return_state = _recording_control_state;
    }
    
    _recording_control_bouncing_state = current_state;
    
    return return_state;
}
