#include <Arduino.h>
//////////////////////////////////////////////////////////////////////////////////
#include "sensorPressure.h"
//////////////////////////////////////////////////////////////////////////////////

#define ENTREE PIN_INPUT_DISABLE
int mesure;
int resultat;
//////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  initialisationCapteurPression(CAPTEURPRESSION);
  Serial.println("SETUP OK");
}
//////////////////////////////////////////////////////////////////////////////////
void loop() {

  resultat = mesureCapteurPressionMoyenne(1000,0);
  affichageResultatTraite(resultat,DELAY0);
}