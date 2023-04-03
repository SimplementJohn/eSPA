#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "FS.h"
#include <Adafruit_GFX.h>
#include "Adafruit_ILI9341.h"   // gestion des images couleurs RGR565
//#include <Adafruit_ILI9341.h>
//#include <Adafruit_I2CDevice.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <TFT_eSPI.h>    

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 5     // Chip select control pin 15
#define TFT_DC 4     // Data Command control pin 2
#define TFT_RST 22   // Reset pin (could connect to RST pin) 4
#define TOUCH_CS 14

TFT_eSPI eTFT = TFT_eSPI();
Adafruit_ILI9341 ecranTft = Adafruit_ILI9341(TFT_CS,TFT_DC);

void setup() {
    Serial.begin(9600);
    ecranTft.begin();
    eTFT.init();
    eTFT.setRotation(0); 	// Rotation
    eTFT.setFreeFont(&FreeMonoBoldOblique12pt7b);  // configuration de la police
    eTFT.setTextSize(2);
    eTFT.fillScreen(ILI9341_WHITE); 	// Effacement de l'écran  
    eTFT.setTextColor(ILI9341_BLACK);
    eTFT.begin(); 				//Initialisation de l'écran
    eTFT.drawString(" vive le travail",0,0);
    Serial.println("Setup OK");
}
void loop() {
}
