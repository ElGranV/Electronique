#include <IRremote.h>
#define RECEIVER_PIN 3// define the IR receiver pin
#define LED_BLEUE 2

int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 
int numberDisplayed = -1;
void display1(void) 
{ 
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
//display number2
void display2(void) 
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
} 
// display number3
void display3(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(g,HIGH);
} 
// display number4
void display4(void) 
{ 
    digitalWrite(f,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  
} 
// display number5
void display5(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
} 
// display number6
void display6(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
} 
// display number7
void display7(void) 
{   
   digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
// display number8
void display8(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);  
} 
void clearDisplay(void) 
{ 
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(g,LOW);
  digitalWrite(c,LOW);
    digitalWrite(d,LOW);  
    digitalWrite(e,LOW);  
  digitalWrite(f,LOW);  
} 
void display9(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
  digitalWrite(f,HIGH);  
} 
void display0(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);  
} 

int IR_Value(int number)
{
 
  if (IrReceiver.decode())
  {
  clearDisplay();
  switch(IrReceiver.decodedIRData.decodedRawData)
      {
        case 3910598400:
        number = 0;
        break;
        
        
        case 4077715200:
        number = 1;
        break;
        
        case 3877175040:
        case 517763989:
        case 3458580836:
        number = 2;
        break;

        case 2707357440:
        number = 3;
        break;
        

        case 4144561920:
        number = 4;
        break;

        case 3810328320:
        number = 5;
        break;

        case 2774204160:
        number = 6;
        break;

        case 3175284480:
        number = 7;
        break;

        case 2907897600:
        number = 8;
        break;
        
        case 3041591040:
        number =  9;
        break;
         
        
        default:
        Serial.print("AUTRE : ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData);
        break;

      }
      IrReceiver.resume();
  }return number;
}

//-------------------------------------
//-------------------------------------
//-------------------------------------
void setup() 
{ 
    int i;
    for(i=4;i<=11;i++) 
        pinMode(i,OUTPUT);
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK); 
  Serial.begin(9600);
  pinMode(LED_BLEUE, OUTPUT);
} 
void loop() 
{   
  numberDisplayed = IR_Value(numberDisplayed);
  switch(numberDisplayed)
  {
    case 0:
    display0();
    break;

    case 1:
    display1();
    break;

    case 2:
    display2();
    break;
    
    case 3:
    display3();
    break;

    case 4:
    display4();
    break;


    case 5:
    display5();
    break;

    case 6:
    display6();
    break;

    case 7:
    display7();
    break;

    case 8:
    display8();
    break;

    case 9:
    display9();
    break;

    default:
    display0();
    break;
  }
      
}
