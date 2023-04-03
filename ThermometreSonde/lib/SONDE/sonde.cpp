#include "sonde.h"
#include <Arduino.h>

void affichageMoniteurSerieSonde(float temperature){
    Serial.print("Temp: ");
    Serial.println(temperature);
}