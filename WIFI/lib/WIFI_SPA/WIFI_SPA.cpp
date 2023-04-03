#include "WIFI_SPA.h"
#include <Arduino.h>
#include <WiFi.h>

void initialisationServeurSPA(char ssid, char password, String usernameTelnet, String passwordTelnet, int portServeur){
    
    Serial.begin(9600);
  // Connexion au réseau WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion en cours au réseau WiFi...");
  }

  Serial.println("Connecté au réseau WiFi");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP()); 

  // Démarrage du serveur
  server.begin();
  Serial.println("Serveur démarré sur le port 2345");
}