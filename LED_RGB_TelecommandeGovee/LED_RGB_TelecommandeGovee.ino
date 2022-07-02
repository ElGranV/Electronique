
#include <IRremote.h> // include the IRremote library
#define RECEIVER_PIN 3
#define ROUGE 2807627520
#define VERT 2790915840
#define BLEU 3125149440
#define BLANC 3141861120

/*
 * Code d'exemple pour une LED RGB (8 couleurs).
 */
 
/* Couleurs (format RGB) */
/* Broches */
const byte PIN_LED_B = 9;
const byte PIN_LED_G = 10;
const byte PIN_LED_R = 11;

byte red = 0;
byte green = 0;
byte blue = 0;

// Fonction setup(), appelée au démarrage de la carte Arduino
void setup() {

  // Initialise les broches
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  displayColor(red, green, blue);
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK); 
}

// Fonction loop(), appelée continuellement en boucle tant que la carte Arduino est alimentée
void loop() {
  if (IrReceiver.decode())
  {
    switch(IrReceiver.decodedIRData.decodedRawData)
    {
      case ROUGE:
      displayColor(255,0,0);
      break;

      case VERT:
      displayColor(0,255,0);
      break;

      case BLEU:
      displayColor(0,0,255);
      break;

      case BLANC:
      displayColor(255,255,255);
      break;

      default:
      displayColor(0,0,0);
      break;
      
      
    }
    
    delay(1000);
    IrReceiver.resume();
    
  }
  
  /* Code de démonstration */

  /*displayColor(red, green, blue);

  delay(100);

  if (red < 255) red+=5;
  else if (green < 255) green+=5;
  else {
    if (blue < 255) blue+=5;
  else {
    red = 0;
    green =0;
    blue = 0;
  }
  }
  */
}

/** Affiche une couleur */
void displayColor(byte r, byte g, byte b) {

  // Assigne l'état des broches
  // Version cathode commune
  
  analogWrite(PIN_LED_R, r);
  analogWrite(PIN_LED_G, g);
  analogWrite(PIN_LED_B, b);
}
