unsigned long instruction_start = 0;
unsigned long instruction_step = 0;
unsigned long instruction_length = 0;
unsigned long instruction_start_val = 0;

/**
 * 0: pitch
 * 1: velocity
 * 2: red
 * 3: green
 * 4: blue
 */
int instruction_args[5];
int pixels;

int red;
int green;
int blue;

float ramp_time = 50;
int base_pixel = 8;

/** @type {Number} control the delay() times */
<<<<<<< HEAD
int tempo = 400;
=======
int tempo = 500;
>>>>>>> 1ee3deb590dfec0865c8a1ed35b74e690f5ddf07

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
    // _eq();
    _flashColor();
    // _splitEq();
    // _doubleEq();
}

void _eq() {
    red = random(255);
    green = random(255);
    blue = random(255);

    eq_setStripInstruction(60, 127, red, green, blue);
    eq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       eq_runStripInstruction();
    }
    delay(tempo);

    eq_setStripInstruction(60, 100, red, green, blue);
    eq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       eq_runStripInstruction();
    }
    delay(tempo);

    eq_setStripInstruction(60, 64, red, green, blue);
    eq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       eq_runStripInstruction();
    }
    delay(tempo);

    eq_setStripInstruction(60, 1, red, green, blue);
    eq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       eq_runStripInstruction();
    }
    delay(tempo);
}

void _flashColor() {
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
    delay(tempo);

    flashColor_setStripInstruction(60, 100, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(tempo);

    flashColor_setStripInstruction(60, 64, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(tempo);

    flashColor_setStripInstruction(60, 30, red, green, blue);
    flashColor_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
        flashColor_runStripInstruction();
    }
    delay(tempo);
}

void _splitEq() {
    red = random(255);
    green = random(255);
    blue = random(255);

    splitEq_setStripInstruction(60, 127, red, green, blue);
    splitEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       splitEq_runStripInstruction();
    }
    delay(tempo);

    splitEq_setStripInstruction(60, 100, red, green, blue);
    splitEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       splitEq_runStripInstruction();
    }
    delay(tempo);

    splitEq_setStripInstruction(60, 82, red, green, blue);
    splitEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       splitEq_runStripInstruction();
    }
    delay(tempo);

    splitEq_setStripInstruction(60, 60, red, green, blue);
    splitEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       splitEq_runStripInstruction();
    }
    delay(tempo);
}

void _doubleEq() {
    red = random(255);
    green = random(255);
    blue = random(255);

    doubleEq_setStripInstruction(60, 127, red, green, blue);
    doubleEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       doubleEq_runStripInstruction();
    }
    delay(tempo);

    doubleEq_setStripInstruction(60, 100, red, green, blue);
    doubleEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       splitEq_runStripInstruction();
    }
    delay(tempo);

    doubleEq_setStripInstruction(60, 82, red, green, blue);
    doubleEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       doubleEq_runStripInstruction();
    }
    delay(tempo);

    doubleEq_setStripInstruction(60, 60, red, green, blue);
    doubleEq_runStripInstruction();
    while (instruction_step <= instruction_length + 10) {
       doubleEq_runStripInstruction();
    }
    delay(tempo);
}

float a = 3.351;
float b = 1.034;
unsigned long expScale(float val) {
    return a * (pow(b, val));
}
unsigned long invExpScale(float val) {
    return 255 - expScale(val);
}

