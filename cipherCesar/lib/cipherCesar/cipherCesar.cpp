#include "cipherCesar.h"
#include <Arduino.h>
#include <string>

#include "cipherCesar.h"



String chiffrementCesar(String message, int cle) {
  String message_chiffre = "";
  int longueur_message = message.length();
  
  for (int i = 0; i < longueur_message; i++) {
    char caractere = message.charAt(i);
    
    // Vérifier si le caractère est une lettre majuscule ou minuscule
    if (isAlpha(caractere)) {
      // Convertir le caractère en majuscule
      caractere = toupper(caractere);
      
      // Appliquer le décalage de César
      caractere = ((caractere - 'A') + cle) % 26 + 'A';
    }
    // Vérifier si le caractère est un chiffre
    else if (isdigit(caractere)) {
      // Appliquer le décalage de César
      caractere = ((caractere - '0') + cle) % 10 + '0';
    }
    
    message_chiffre += caractere;
  }
  
  return message_chiffre;
}


String dechiffrementCesar(String message, int cle) {
  String message_dechiffre = "";
  int longueur_message = message.length();
  
  for (int i = 0; i < longueur_message; i++) {
    char caractere = message.charAt(i);
    
    // Vérifier si le caractère est une lettre majuscule, minuscule ou un chiffre
    if (isAlphaNumeric(caractere)) {
      // Appliquer le décalage de César inversé pour les lettres
      if (isAlpha(caractere)) {
        // Convertir le caractère en majuscule
        caractere = toupper(caractere);
      
        // Appliquer le décalage de César inversé pour déchiffrer le message
        caractere = ((caractere - 'A') - cle + 26) % 26 + 'A';
      }
      // Appliquer le décalage de César inversé pour les chiffres
      else if (isdigit(caractere)) {
        caractere = ((caractere - '0') - 6 + 10) % 10 + '0';
      }
    }
    
    message_dechiffre += caractere;
  }
  
  return message_dechiffre;
}

