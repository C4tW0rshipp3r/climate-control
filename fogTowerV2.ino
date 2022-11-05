int fan=3;
int fog=4;
unsigned int x;
unsigned long minute=(60L*1000);


void setup() {
pinMode (fan, OUTPUT);
pinMode (fog, OUTPUT);
}

//times for the various parts of the fog cycle go here, in minutes

#define fogfanT (2*minute)   //fog with fan
#define fogT (10*minute)      //fog only
#define absorbT (10*minute)  //both off
#define clearT (1*minute)    //fan only



void loop() {

digitalWrite (fan, LOW);
digitalWrite (fog, LOW);
delay (fogfanT);

digitalWrite (fan, HIGH);
digitalWrite (fog, LOW);
delay (fogT);


digitalWrite (fan, LOW);
digitalWrite (fog, LOW);
delay (fogfanT);

digitalWrite (fan, HIGH);
digitalWrite (fog, LOW);
delay (fogT);

digitalWrite (fan, HIGH);
digitalWrite (fog, HIGH);
delay (absorbT);


  
}
