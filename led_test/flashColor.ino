
void flashColor_setStripInstruction(byte pitch, byte velocity, byte red, byte green, byte blue) {
    instruction_start = millis();
    instruction_length = 200;
    instruction_start_val = expScale(velocity);

    instruction_args[0] = pitch;
    instruction_args[1] = velocity;
    instruction_args[2] = red;
    instruction_args[3] = green;
    instruction_args[4] = blue;

    // uint32_t color = strip_1.Color(
    //     ((red)   ? instruction_start_val * (float(red)   / 8) : 0),
    //     ((green) ? instruction_start_val * (float(green) / 8) : 0),
    //     ((blue)  ? instruction_start_val * (float(blue)  / 8) : 0)
    // );
    // for(uint16_t i=0; i < pixels; i++) {
    //     strip_1.setPixelColor(i, color);
    // }
    // strip_1.show();
}

void flashColor_runStripInstruction() {
    unsigned long clock = millis();
    instruction_step = clock - instruction_start;

    if (instruction_step <= instruction_length) {
        //fade out
        float fade_by = instruction_start_val / (float) instruction_length;
        int set_val = instruction_start_val - (instruction_step * fade_by);

        byte pitch = instruction_args[0];
        byte velocity = instruction_args[1];
        byte red = instruction_args[2];
        byte green = instruction_args[3];
        byte blue = instruction_args[4];

        uint32_t color = strip_1.Color(
            ((red)   ? set_val * (float(red)   / 8) : 0),
            ((green) ? set_val * (float(green) / 8) : 0),
            ((blue)  ? set_val * (float(blue)  / 8) : 0)
        );

        for(uint16_t i = 0; i < pixels; i++) {
            strip_1.setPixelColor(i, color);
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
