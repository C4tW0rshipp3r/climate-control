// script to constantly measure temp and humidity, and irrigate on a timer
// fan turns on @ 27C and off @ 25CF
// Humidity and temp are constantly monitored and output in serial monitor
// Irrigation is turned on for 20 min every 24 hours

#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

int powerPin = 1; //5v to relay
int waterPin = 2;
int fanPin = 4;
const unsigned long waterTime = 600000;//1200000;                  //valve open time in millis
const unsigned long waterInterval = 900000;//86400000; //time between waterings
int maxTemp = 27;
int minTemp = 25;
int overTemp = 29;

//indicator lights
int yellowLED = 11;
int greenLED = 12;
int blueLED = 9;
int redLED = 10;

  // wait time between waterings
unsigned long previousTime = 0;


void setup() {

Serial.begin(9600);
dht.begin();


      pinMode(fanPin, OUTPUT);
      pinMode(waterPin, OUTPUT);
      
      pinMode(yellowLED, OUTPUT);
      pinMode(greenLED, OUTPUT);
      pinMode(blueLED, OUTPUT);
      pinMode(redLED, OUTPUT);

      digitalWrite(yellowLED, HIGH);
      delay(500);
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(blueLED, HIGH);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(1000);

      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(redLED, LOW);
      delay(500);

      
}

void loop() {
  


unsigned long currentTime = millis();
int temperature = dht.readTemperature();

      digitalWrite(yellowLED, HIGH);

if (previousTime == 0){

digitalWrite(waterPin, HIGH);
digitalWrite(blueLED, HIGH);

if (currentTime > waterTime){

  digitalWrite(waterPin, LOW);
digitalWrite(blueLED, LOW);

}
}

if (currentTime - previousTime >= waterInterval){

digitalWrite(waterPin, HIGH);
digitalWrite(blueLED, HIGH);

if (currentTime - previousTime >= waterInterval + waterTime){

digitalWrite(waterPin, LOW);
digitalWrite(blueLED, LOW);

 previousTime = currentTime;

}
}

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

if (t > maxTemp){
  digitalWrite (fanPin, HIGH);
  digitalWrite (greenLED, HIGH);
}

if (t < minTemp){
  digitalWrite (fanPin, LOW);
  digitalWrite (greenLED, LOW);
}

if (t > overTemp){
  digitalWrite (redLED, HIGH);
}
if (t < overTemp){
  digitalWrite (redLED, LOW);
}




  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    digitalWrite (fanPin, LOW);
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));




}
