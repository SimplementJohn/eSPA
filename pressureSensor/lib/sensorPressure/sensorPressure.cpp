#include "sensorPressure.h"
#include <Arduino.h>


void initialisationCapteurPression(int pin){
    pinMode(pin,OUTPUT);
    Serial.println("CapteurPression OK");
}

int mesureCapteurPressionMoyenne(int nbMesure, int tempsInterMesureMS){
    int mesure = 0;
  for (int i = 0; i < nbMesure; i++)
  {
    mesure = mesure + analogRead(CAPTEURPRESSION);
    Serial.print(i);
    delay(tempsInterMesureMS);
  }
  int resultat = mesure / nbMesure;
  return resultat;

}


void affichageResultatTraite(int resultat, int delayApresAffichage){
    Serial.print(" Résultat Traité capteur Pression: ");
    Serial.print(resultat);
    Serial.println();
    delay(500);
}