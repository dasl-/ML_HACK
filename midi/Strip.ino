//unsigned long instruction_start = 0;
//unsigned long instruction_step = 0;
//unsigned long instruction_length = 0;
//unsigned long start_val = 0;
//
//void setStripInstruction(byte pitch, byte velocity) {
//    instruction_start = millis();
//    instruction_length = 100;
//    
//    
//    //exponential scale
//    //val = a * b^velocity
//    //a = 3.531
//    //b = 1.034
//    start_val = 3.351 * (pow(1.034, velocity));
//    
//    uint32_t color = strip_1.Color(0, start_val, 0);
//    for(uint16_t i=0; i<strip_1.numPixels(); i++) {
//      strip_1.setPixelColor(i, color);
//      strip_1.show();
//  }
//}
//
//void runStripInstruction() {
//    unsigned long clock = millis();
//    instruction_step = clock - instruction_start;
//    
//    if (instruction_step <= instruction_length) {
//        //fade out
//        float fade_by = start_val / (float) instruction_length;
//        int set_green = start_val - (instruction_step * fade_by);
//        
//        uint32_t color = strip_1.Color(0, set_green, 0);
//        for(uint16_t i = 0; i < strip_1.numPixels(); i++) {
//            strip_1.setPixelColor(i, color);
//            strip_1.show();
//        }
//    } else {
//        uint32_t color = strip_1.Color(0, 0, 0);
//        for(uint16_t i = 0; i < strip_1.numPixels(); i++) {
//            strip_1.setPixelColor(i, color);
//            strip_1.show();
//        }
//    }
//}
