
#include "DHT.h"

#define DHTPIN 2  

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

int fog=6;
int fan=7;
int pwr=13;

int fogInd=9;
int fanInd=10;
int onInd=8;

int maxHumidity=90.00;
int minHumidity=20.00;


int maxTemp=27;
int minTemp=23;


// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT22 sensor online");

      pinMode (fan, OUTPUT);
    pinMode (fog, OUTPUT);
    pinMode (pwr, OUTPUT);

        pinMode (fanInd, OUTPUT);
    pinMode (fogInd, OUTPUT);
    pinMode (onInd, OUTPUT);

          digitalWrite(fan, HIGH);
      digitalWrite(fog, HIGH);
      digitalWrite(pwr, HIGH);
      digitalWrite(onInd, HIGH);

      delay(500);

       digitalWrite(fogInd, HIGH);
       delay(500);
      digitalWrite(fanInd, HIGH);
      delay(500);

      
       digitalWrite(fogInd, LOW);
      digitalWrite(fanInd, LOW);
      digitalWrite(onInd, LOW);
      delay(500);

      
       digitalWrite(fogInd, HIGH);
      digitalWrite(fanInd, HIGH);
      delay(200);
        
       digitalWrite(fogInd, LOW);
      digitalWrite(fanInd, LOW);
      digitalWrite(onInd, LOW);
      delay(200);
      digitalWrite(onInd,  HIGH);
  
  

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(3000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if(isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  //float hif = dht.computeHeatIndex(f, h);
// Compute heat index in Celsius (isFahreheit = false)
  //float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Hum: ");
  Serial.print(h);
  Serial.print(" %  ");
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println(" *C ");
  //Serial.print(f);
  //Serial.print(" *F\t");
  //Serial.print(F("HI: "));
  //Serial.print(hic);
  //Serial.print(" *C ");
  //Serial.print(hif);
  //Serial.println(" *F");

  
    if (h < minHumidity){
           
  
      digitalWrite(fog, LOW);
      digitalWrite(fogInd, HIGH);
      
    }

    if (h > maxHumidity){

      digitalWrite(fog, HIGH);
      digitalWrite(fogInd, LOW);
    }

        if (t > maxTemp){

      digitalWrite(fan, LOW);
      digitalWrite(fanInd, HIGH);
    }
    

        if (t < minTemp){
           
      digitalWrite(fan, HIGH);
      digitalWrite(fanInd, LOW);
      
    }


   
 
  //Fastest should be once every two seconds.
 
}
