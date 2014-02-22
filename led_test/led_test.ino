unsigned long instruction_start = 0;
unsigned long instruction_step = 0;
unsigned long instruction_length = 0;
unsigned long instruction_start_val = 0;
int instruction_args[5];
int pixels;

int red;
int green;
int blue;

float ramp_time = 50;
int base_pixel = 8;

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(21, 6, NEO_GRB + NEO_KHZ800);

/*
 * Initialize the Arduino
 */
void setup(){
    Serial.begin(9600);
    pixels = strip_1.numPixels();
    
    strip_1.begin();
    strip_1.show();
}

/*
 * The main execution loop
 */
void loop() {
//    //EQ
//    red = random(255);
//    green = random(255);
//    blue = random(255);
//    
//    eq_setStripInstruction(60, 127, red, green, blue);
//    eq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        eq_runStripInstruction();
//    }
//    delay(500);
//    
//    eq_setStripInstruction(60, 100, red, green, blue);
//    eq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        eq_runStripInstruction();
//    }
//    delay(500);
//    
//    eq_setStripInstruction(60, 64, red, green, blue);
//    eq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        eq_runStripInstruction();
//    }
//    delay(500);
//    
//    eq_setStripInstruction(60, 1, red, green, blue);
//    eq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        eq_runStripInstruction();
//    }
//    delay(500);
//    
//    
//    
//    
//    
    //Flash Color
    red = random(8);
    green = random(8);
    blue = random(8);
    
    while (red + green + blue <= 2) {
        red = random(8);
        green = random(8);
        blue = random(8);
    }
    
    flashColor_setStripInstruction(60, 127, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(500);
    
    flashColor_setStripInstruction(60, 100, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(500);
    
    flashColor_setStripInstruction(60, 64, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(500);
    
    flashColor_setStripInstruction(60, 30, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(500);






//
//    //SPLIT EQ
//    red = random(255);
//    green = random(255);
//    blue = random(255);
//    
//    splitEq_setStripInstruction(60, 127, red, green, blue);
//    splitEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        splitEq_runStripInstruction();
//    }
//    delay(500);
//    
//    splitEq_setStripInstruction(60, 100, red, green, blue);
//    splitEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        splitEq_runStripInstruction();
//    }
//    delay(500);
//    
//    splitEq_setStripInstruction(60, 82, red, green, blue);
//    splitEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        splitEq_runStripInstruction();
//    }
//    delay(500);
//    
//    splitEq_setStripInstruction(60, 60, red, green, blue);
//    splitEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        splitEq_runStripInstruction();
//    }
//    delay(500);







    //DOUBLE EQ
//    red = random(255);
//    green = random(255);
//    blue = random(255);
//    
//    doubleEq_setStripInstruction(60, 127, red, green, blue);
//    doubleEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        doubleEq_runStripInstruction();
//    }
//    delay(500);
//    
//    doubleEq_setStripInstruction(60, 100, red, green, blue);
//    doubleEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        splitEq_runStripInstruction();
//    }
//    delay(500);
//    
//    doubleEq_setStripInstruction(60, 82, red, green, blue);
//    doubleEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        doubleEq_runStripInstruction();
//    }
//    delay(500);
//    
//    doubleEq_setStripInstruction(60, 60, red, green, blue);
//    doubleEq_runStripInstruction();
//    while (instruction_step <= instruction_length + 10) {
//        doubleEq_runStripInstruction();
//    }
//    delay(500);
}

float a = 3.351;
float b = 1.034;
unsigned long expScale(float val) {
    return a * (pow(b, val));
}
unsigned long invExpScale(float val) {
    return 255 - expScale(val);
}

