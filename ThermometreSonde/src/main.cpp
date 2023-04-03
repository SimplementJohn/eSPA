/*
Programme DS18B20, ce programme sert à récuperer la temperature d'un capteur sonde
Créer par ROSA John
Version 1.0
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Librairie Publique
#include <Arduino.h>
#include <OneWire.h>
#include <DS18B20.h>
//Libraire Perssonelles
#include "moniteurSerie.h"
#include "sonde.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OneWire oneWire(pinSonde);                        //Création de l'objet oneWire 
DS18B20 SONDE(&oneWire);                          //Création de l'objet SONDE avec la librairie OneWire et DS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  initialisationMoniteurSerie();                  //initialisation du moniteur Serie à 9600 baud
  SONDE.begin();                                  //Initialisation de l'objet sonde
  confirmationFonctionementSetup();               //Confirmation de sortie du setup dans le moniteur serie
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() { 
  SONDE.requestTemperatures();                    //On demmande les temperature
  while (!SONDE.isConversionComplete());          //Attente que le capteur soit pret 
  affichageMoniteurSerieSonde(SONDE.getTempC());  //On affiche dans le moniteur serie les temperature
}