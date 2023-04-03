#ifndef SENSORPRESSURE_H
#define SENSORPRESSURE_H

#define CAPTEURPRESSION 32
#define NOMBREMESURE 20
#define TEMPSINTERMESUREMS 200
#define DELAY0 0

void initialisationCapteurPression(int pin);
int mesureCapteurPressionMoyenne(int nbMesure, int tempsInterMesureMS);
void affichageResultatTraite(int resultat, int delayApresAffichage);


#endif //CAPTEUR_H