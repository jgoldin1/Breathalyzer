#include <Wire.h>
#include <Adafruit_AM2315.h>




Adafruit_AM2315 am2315;

const int JGPin = 13;
const int AHPin = 12;
const int alPin = 3;

void setup() {
  Serial.begin(57600);
  
  if (! am2315.begin()) {
     Serial.println("Sensor not found, check wiring & pullups!");
     while (1);
  }
  
  pinMode(JGPin, INPUT);
  pinMode(AHPin, INPUT);
  
  Serial.print("mils,Humidity,Temperature,A/J/N,Alcohol");
}

void loop() {
  Serial.print(millis());
  Serial.print(",");
  
  Serial.print(am2315.readHumidity()); Serial.print(",");
  Serial.print(am2315.readTemperature());Serial.print(",");
  
  if(digitalRead(JGPin)==1)
    Serial.print("J");
  if(digitalRead(AHPin)==1)
    Serial.print("A");
  if( (digitalRead(AHPin)==0) && (digitalRead(JGPin)==0) )
    Serial.print("N");
  Serial.print(",");
  
  Serial.print(analogRead(alPin));
  Serial.print("\n");
  
  delay(1000);
  
  //delay(1000);
}
