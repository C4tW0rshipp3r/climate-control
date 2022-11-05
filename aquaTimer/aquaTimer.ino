
unsigned long h=12;     //Time that will be set upon powerup or reset aka current time
unsigned long m=28;
unsigned long s=00;
unsigned long flag=1; //PM

int on1hrs=8;      //event 1
int on1min=0;
  int off1hrs=8;
  int off1min=2;

   int on2hrs=10;      //event 2
int on2min=0;
  int off2hrs=10;
  int off2min=2; 

  int on3hrs=12;      //event 3
int on3min=0;
  int off3hrs=12;
  int off3min=2;

  int on4hrs=14;      //event 4
int on4min=0;
  int off4hrs=14;
  int off4min=2;

  int on5hrs=16;      //event 5
int on5min=0;
  int off5hrs=16;
  int off5min=2;

  int on6hrs=18;      //event 6
int on6min=0;
  int off6hrs=18;
  int off6min=2;

  


static uint32_t last_time, now = 0;

int relayPin=A1;  //signal pin to relay
int sPin=A3;      //seconds flashing indicator
int powerPin=A2;  //5v to relay
unsigned long pState;

void setup(){

  now=millis(); // read RTC initial value 
  Serial.begin(9600);

  pinMode (sPin, OUTPUT);
    pinMode (relayPin, OUTPUT);
        pinMode (powerPin, OUTPUT);
        

        digitalWrite (powerPin, HIGH);
        digitalWrite (relayPin, HIGH);

  
  pState=1;
  
}

void loop(){

  for ( int i=0 ;i<5 ;i++)// make 5 time 200ms loop, for faster Button response
{

  while ((now-last_time)<1000) //delay1s
  { 
    now=millis();
  }
 
 last_time=now; // prepare for next loop 




 Serial.print("Time ");
 if(h<10)Serial.print("0");// always 2 digits
 Serial.print(h);
 Serial.print(":");
 if(m<10)Serial.print("0");
 Serial.print(m);
 Serial.print(":");
 if(s<10)Serial.print("0");
 Serial.println(s);
 Serial.println(pState);

pState=pState+1;
 if (pState==3){
  pState=1;
 }

 if (pState==1){
  digitalWrite(sPin, HIGH);
 }

 if (pState==2){
  digitalWrite(sPin, LOW);
 }

 if (h==on1hrs and m==on1min
    or h==on2hrs and m==on2min
    or h==on3hrs and m==on3min
    or h==on4hrs and m==on4min
    or h==on5hrs and m==on5min
    or h==on6hrs and m==on6min)
    {
  digitalWrite(relayPin, LOW);
 }
else{
  digitalWrite(relayPin, HIGH);
 }

 


 // ---- manage seconds, minutes, hours am/pm overflow ----
 s=s+1;
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==24)
 {
  h=0;
  flag=flag;
 } 
  

  
  
}}
