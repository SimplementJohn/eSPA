#include "capteurPH.h"
#include <Arduino.h>

int lireCapteurPH(void){
    int valeurBrutePH = analogRead(PINCAPTEURPH);
    int valeurTraitePH = valeurBrutePH;
    //Serial.println("Voici la valeure Brute du capteur PH : ", valeurBrutePH); 
    //Serial.println("Voici la valeure Traite du capteur de PH : ", valeurTraitePH);

    if (valeurBrutePH >= PH7 - MARGE || valeurBrutePH <= PH7 + MARGE )
    {
        valeurTraitePH = 7;
    }
    
    return valeurTraitePH;
}



void initialisationCapteurPH(int pinCapteurPH){
    pinMode(pinCapteurPH,ENTREE);
}