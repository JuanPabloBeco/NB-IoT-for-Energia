#include <Libraries\serialDrivers.h>

int a;

void setup() {
  // put your setup code here, to run once:
    initializePins();
    Serial.begin(9600);
    delay(25);
}

void loop() {
  // put your main code here, to run repeatedly:
    a = digitalRead(gLED);
    Serial.println(a);
    if (a == 0){
        greenLedON();
    } else{
        greenLedOFF();
    }
    delay(1000); //ms of delay
}
