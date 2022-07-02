//numéro de pin de la led
#define PIN_LED 2
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  //allumer la led
  digitalWrite(PIN_LED, LOW);
  delay(500);//attendre 500ms
  
  //éteindre la led
  digitalWrite(PIN_LED, HIGH);
  delay(500);
}
