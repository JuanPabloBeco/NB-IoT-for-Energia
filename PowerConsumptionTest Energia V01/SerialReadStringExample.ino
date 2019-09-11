#include <Libraries\serialDrivers.h>

int a;

String incoming_message = "I'm listening!";

void setup() {
  // put your setup code here, to run once:
    initializePins();
    Serial.begin(9600);
    Serial.println("Hello World!");
    delay(25);
}

void loop() {
  // put your main code here, to run repeatedly:
    a = digitalRead(gLED);
    if (Serial.available() > 0) {
        do{
            incoming_message = Serial.readString();
            Serial.println(incoming_message);
        }while(incoming_message.equals("Response"));  //
        incoming_message = "Response arrived!!!";
        Serial.println(incoming_message);
        if (a == 0){
            greenLedON();
        } else{
            greenLedOFF();
        }
        delay(1000); //ms of delay
    }
}
