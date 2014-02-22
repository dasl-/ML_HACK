void doubleEq_setStripInstruction(byte pitch, byte velocity, int red, int green, int blue) {
    instruction_start = millis();
    instruction_length = 200;
    instruction_start_val = (expScale(velocity) * pixels) / 255;
    
    instruction_args[0] = pitch;
    instruction_args[1] = velocity;
    instruction_args[2] = red;
    instruction_args[3] = green;
    instruction_args[4] = blue;
    
    uint32_t color = strip_1.Color(red, green, blue);
    
    for(uint16_t i=0; i < pixels; i++) {
        strip_1.setPixelColor(i, strip_1.Color(0, 0, 0));
    }
    strip_1.show();
}

void doubleEq_runStripInstruction() {
    unsigned long clock = millis();
    instruction_step = clock - instruction_start;
    
    if (instruction_step <= instruction_length) {
        byte pitch = instruction_args[0];
        byte velocity = instruction_args[1];
        byte red = instruction_args[2];
        byte green = instruction_args[3];
        byte blue = instruction_args[4];
        uint32_t color = strip_1.Color(red, green, blue);
        
        if (instruction_step <= ramp_time) {
            //go up in the first 100 ms
            float fade_by = instruction_start_val / (float) ramp_time;
            int set_val = (instruction_step * fade_by);
        
            for(uint16_t i=0; i < pixels / 2; i++) {
                if (i <= (set_val / 4) || i >= (pixels - (set_val / 4))){
                    strip_1.setPixelColor((i + base_pixel) % pixels, color);
                } else {
                    strip_1.setPixelColor((i + base_pixel) % pixels, strip_1.Color(0, 0, 0));
                }
            }
        } else {
            //go down after the first 100 ms
            float fade_by = instruction_start_val / (float) (instruction_length - ramp_time);
            int set_val = instruction_start_val - ((instruction_step - ramp_time) * fade_by);
            
            for(uint16_t i=0; i < pixels / 2; i++) {
                if (i <= (set_val / 4) || i >= (pixels - (set_val / 4))){
                    strip_1.setPixelColor((i + base_pixel) % pixels, color);
                } else {
                    strip_1.setPixelColor((i + base_pixel) % pixels, strip_1.Color(0, 0, 0));
                }
            }
        }
        strip_1.show();
    } else if (instruction_step <= instruction_length + 10) {
        uint32_t color = strip_1.Color(0, 0, 0);
        for(uint16_t i = 0; i < pixels; i++) {
            strip_1.setPixelColor(i, color);
        }
        strip_1.show();
    }
}
