#include <Libraries\serialDrivers.h>

int a;

String incoming_message;

void setup() {
    //initializePins();
    pinMode(modemPowerKeyPin, OUTPUT);

    pinMode(gLED, OUTPUT);
    pinMode(rLED, OUTPUT);

    pinMode(P2_6, INPUT_PULLUP); // set pin to input and enable internal pullup resistor

    //modemONOFF();
    console.begin(9600);
    modemSerial.begin(9600);

    pinMode(P2_6, INPUT_PULLUP); // set pin to input and enable internal pullup resistor
}


void loop() {
    if (console.available()) {      // If anything comes in Serial (USB),
      modemSerial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
    }

    if (modemSerial.available()) {     // If anything comes in Serial1 (pins 0 & 1)
      console.write(Serial1.read());   // read it and send it out Serial (USB)
    }
}
