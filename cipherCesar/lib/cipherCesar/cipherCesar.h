#ifndef CIPHERCESAR_H
#define CIPHERCESAR_H

#include <Arduino.h>

#define CLECESAR 6

String chiffrementCesar(String message, int cle);
String dechiffrementCesar(String message, int cle);

#endif // CIPHERCESAR_H
