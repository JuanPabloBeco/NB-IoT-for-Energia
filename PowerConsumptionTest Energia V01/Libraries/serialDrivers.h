#ifndef SERIALDRIVERS_H_
#define SERIALDRIVERS_H_

int reiniciar();
int getStatus();
void modemONOFF();

void serialSend2Modem(char* paraEnviar);

void initializePins();
void initializeModemPins();

void greenLedON();
void greenLedOFF();
void ledVerdeONOFF();
void redLedON();
void redLedOFF();
void ledRojoONOFF();
void PowerKeyON();
void PowerKeyOFF();
void PowerKeyONOFF();



#endif /* SERIALDRIVERS_H_ */

#define modemSerial Serial1
#define console Serial

// Set the pins in accordance with your hardware design

#define modemPowerKeyPin P4_3
#define modemResetPin P3_4
#define modemNetlightPin P1_5
#define modemStatusPin P1_4

#define rLED RED_LED
#define gLED GREEN_LED



int reiniciar(){
    int status;
    modemONOFF();
    sleep(4000);
    do{
        status=getStatus();
        sleep(500);
    }while(status!=0);
    //delay(500);
    modemONOFF();
    return status;
}

int getStatus(){
    return digitalRead(modemStatusPin);
}

int getNetworkStatus(){
    return digitalRead(modemNetlightPin);
}

void send2Modem(char* paraEnviar){
    modemSerial.print(paraEnviar);
}


void modemONOFF(){
    greenLedON();
    redLedON();
    PowerKeyOFF();

    sleep(2000);

    greenLedOFF();
    redLedOFF();
    PowerKeyON();
}

void initializePins(){
    pinMode(gLED, OUTPUT);
    pinMode(rLED, OUTPUT);
    initializeModemPins();
}

void initializeModemPins(){
    pinMode(modemPowerKeyPin, OUTPUT);
    pinMode(modemResetPin, OUTPUT);
    pinMode(modemNetlightPin, INPUT);
    pinMode(modemStatusPin, INPUT);

}

void greenLedON(){
    digitalWrite(gLED, HIGH);
}

void greenLedOFF(){
    digitalWrite(gLED, LOW);
}

void redLedON(){
    digitalWrite(rLED, HIGH);
}

void redLedOFF(){
    digitalWrite(rLED, LOW);
}

void PowerKeyON(){
    digitalWrite(modemPowerKeyPin, HIGH);
}

void PowerKeyOFF(){
    digitalWrite(modemPowerKeyPin, LOW);
}

void ResetON(){
    digitalWrite(modemResetPin, HIGH);
}

void ResetOFF(){
    digitalWrite(modemResetPin, LOW);
}
