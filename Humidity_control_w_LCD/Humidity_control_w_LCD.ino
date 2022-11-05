#include <dht.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



#define dht_apin A0 // Analog Pin sensor is connected to

int fog=6;
int fan=7;
int pwr=13;

int fogInd=9;
int fanInd=10;
int onInd=8;

int maxHumidity=80.00;
int minHumidity=71.00;

int maxTemp=22;
int fanOffTemp=20;

 
dht DHT;
 
void setup(){



  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  lcd.print("Initializing...");
  delay(1000);//Wait before accessing Sensor

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
     

      delay(1000);

       digitalWrite(fogInd, HIGH);
       delay(1000);
      digitalWrite(fanInd, HIGH);
      delay(1000);

      
       digitalWrite(fogInd, LOW);
      digitalWrite(fanInd, LOW);
      delay(1000);

      
       digitalWrite(fogInd, HIGH);
      digitalWrite(fanInd, HIGH);
      delay(500);
        
       digitalWrite(fogInd, LOW);
      digitalWrite(fanInd, LOW);

      lcd.clear();
 
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

        lcd.print("Humidity ");
    lcd.print(DHT.humidity);
    lcd.print("%  ");
  delay(5000);
    lcd.clear();
    lcd.print("Temp ");
    lcd.print(DHT.temperature);
    lcd.print(" C");
    


    if (DHT.humidity < minHumidity){
           
     
      digitalWrite(fog, LOW);
      digitalWrite(fogInd, HIGH);

    if (DHT.humidity > maxHumidity){

      digitalWrite(fog, HIGH);
      digitalWrite(fogInd, LOW);
    }
   if (DHT.temperature > maxTemp){
  
    digitalWrite(fan, LOW);
      digitalWrite(fanInd, HIGH);

   }

     if (DHT.temperature < fanOffTemp){
  
    digitalWrite(fan, HIGH);
      digitalWrite(fanInd, LOW);

   } 
    
    delay(5000);//Wait 5 seconds before accessing sensor again.

    lcd.clear();
 
  //Fastest should be once every two seconds.
 
    }}// end loop(
