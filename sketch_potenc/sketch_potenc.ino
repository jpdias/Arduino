int led1= 9;
int analogPin = 2;

void setup() {
  Serial.begin(9600,SERIAL_8N1);
  pinMode(led1,OUTPUT);
}

int tension =0;
int lasttension =0;
float t;
void loop() {
  // put your main code here, to run repeatedly:
   lasttension = tension;
   tension = (analogRead(analogPin)+analogRead(analogPin)+analogRead(analogPin))/3;
   if(tension != lasttension){
     t=(float) tension*5.0/1023.0;
     Serial.println((int)tension);
   }
  
   analogWrite(led1,(int)(tension/4));
   
}
