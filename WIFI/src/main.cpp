//Librarie par défault
#include <WiFi.h>
#include <Arduino.h>
//Librarie personnelles
//#include "WIFI_SPA.h"

const char* ssid = "HomeBox";
const char* password = "0686923466";
String usernameTelnet = "admin";
String passwordTelnet = "admin123";
WiFiServer server(2345); // Port sur lequel le serveur écoute

trameTest "$eSPA;35;26;7;0;1"

void setup() {
  
  Serial.begin(9600);

  // Connexion au réseau WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("");
    Serial.println("Connexion en cours au réseau WiFi...");
  }

  Serial.println("Connecté au réseau WiFi");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP()); 

  // Démarrage du serveur
  server.begin();
  Serial.println("Serveur démarré sur le port 2345");
  

}
void loop() {


WiFiClient client = server.available();
if (client) {
  Serial.println("Nouvelle connexion cliente");

  // Attente de la connexion du client et de l'authentification
  bool authenticated = false;
  while (!authenticated) {

    // Envoyer une invite de connexion
    client.println("");
    client.println("Entrez votre nom d'utilisateur :");
    delay(5000);
    String receivedUsername = client.readStringUntil('\r\n');

    client.println("");    
    client.println("Entrez votre mot de passe :");
    delay(5000);
    String receivedPassword = client.readStringUntil('\r\n');
    client.println("");    

    // Vérifier si les informations de connexion sont valides
    if (receivedUsername == usernameTelnet && receivedPassword == passwordTelnet) {
      authenticated = true;
      client.println("Connexion reussie !");
    } else {
      client.println("Nom d'utilisateur ou mot de passe incorrect. Réessayez.");
    }
  }

  // Envoi de données périodiques au client
  while (client.connected()) {
    client.println("Bienvenu sur l'esp32");
    delay(1000); // Attente de 1 seconde entre chaque envoi de données
    client.println("Envoie Trame de test");
    client.println(trameTest)
    delay(1000); // Attente de 1 seconde entre chaque envoi de données
  }

  // Fermeture de la connexion avec le client
  client.stop();
  Serial.println("Client déconnecte");
}









}