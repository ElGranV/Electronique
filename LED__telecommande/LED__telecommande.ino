
#include <IRremote.h> // include the IRremote library
#define RECEIVER_PIN 3// define the IR receiver pin
#define LED_BLEUE 2
int type = 1;

void flash(int type)
{
  digitalWrite(LED_BLEUE, LOW);
  delay(type*500);
  digitalWrite(LED_BLEUE, HIGH);
  delay(type*500);
  
}
// create a results object of the decode_results class
void setup() {
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK); 
  Serial.begin(9600);
 pinMode(LED_BLEUE, OUTPUT);
  // begin serial communication with a baud rate of 9600
  // enable blinking of the built-in LED when an IR signal is received
}

void loop() {
  flash(type);
if (IrReceiver.decode()) { // decode the received signal and store it in results
      
      switch(IrReceiver.decodedIRData.decodedRawData)
      {
        case 4077715200:
        Serial.println(1);
        type = 1;
        break;
        
        case 3877175040:
        case 517763989:
        case 3458580836:
        Serial.println(2);
        type = 2;
        break;

        case 2707357440:
        Serial.println(3);
        type = 3;
        break;

        default:
        Serial.print("AUTRE : ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData);
        break;

      }
      
      
      //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      //IrReceiver.printIRResultShort(&Serial); // optional use new print version
      delay(50);
      IrReceiver.resume();
      
}

}
