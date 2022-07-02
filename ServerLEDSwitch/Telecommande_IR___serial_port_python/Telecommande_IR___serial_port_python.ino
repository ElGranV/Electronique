#define LED_BLEUE 2
int x = 1;
void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
 pinMode(LED_BLEUE, OUTPUT);
}
void loop() {
 while (!Serial.available())
 {
 if (x==1) digitalWrite(LED_BLEUE, LOW);
  if (x==0) digitalWrite(LED_BLEUE, HIGH);
 }
 x = Serial.readString().toInt();
 Serial.print(x);
 
}
