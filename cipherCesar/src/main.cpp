#include "cipherCesar.h"
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  
  String message = "$SPA;35;26;7;0;1\r\n";
  
  //Message Normal
  Serial.println("Message original : " + message);

  //Message chiffré
  String message_decale = chiffrementCesar(message, CLECESAR);
  Serial.println("Message decale : " + message_decale);


  //Message dechiffré
  String message_dechiffre = dechiffrementCesar(message_decale,CLECESAR);
  Serial.println("Message dechiffre : " + message_dechiffre);
}

void loop() {
}
