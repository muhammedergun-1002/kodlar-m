#include <LCD5110_Graph.h>

LCD5110 myGLCD(7, 9, 10, 11, 12);

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
int esikDegeri = 150;              //Gaz eşik değerini belirliyoruz.    
int buzzerPin = 2;                  //Buzzerın takılacağı pin
int deger;                 
int sensor = A0;
int sensorValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);  
  myGLCD.InitLCD();

  myGLCD.clrScr();

}
void loop() {



  myGLCD.setFont(SmallFont);

  sensorValue = analogRead(sensor);
  Serial.println(sensorValue, DEC);
   deger = analogRead(A0);           //Sensörden analog değer okuyoruz.
  if(deger > esikDegeri){           //Sensörden okunan değer eşik değerinden büyükse çalışır.
    digitalWrite(buzzerPin, HIGH);
    delay(10);
    digitalWrite(buzzerPin, LOW);
    delay(10);
  }
  else{                             //Sensörden okunan değer eşik değerinin altındaysa çalışır.
    digitalWrite(buzzerPin, LOW);
  }

  myGLCD.print("sizingazinizin", CENTER, 8);
  myGLCD.print("normaldeger100", CENTER, 0);
  myGLCD.printNumI(sensorValue, CENTER, 24);
  myGLCD.print("degeri  ", CENTER, 40);
  myGLCD.update();
  myGLCD.clrScr();
delay(500);



}
