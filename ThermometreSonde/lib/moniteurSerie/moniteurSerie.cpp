#include "moniteurSerie.h"
#include <Arduino.h>

void initialisationMoniteurSerie(void){
    Serial.begin(BAUD);
}

void confirmationFonctionementSetup(void){
    Serial.println("Setup OK");
}