int led1=12,led2=11,led3=10,led4=9,led5=8,led6=5;
int button=7;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(button,INPUT_PULLUP);
} 

int laststate=0,actualstate=0,counter=0;
void loop() {
  
  switch (counter) {
    case 0:
      digitalWrite(led6,LOW);
      digitalWrite(led1,HIGH);
      break;
    case 1:
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      break;
    case 2:
      digitalWrite(led2,LOW);
      digitalWrite(led3,HIGH);
      break;
    case 3:
      digitalWrite(led3,LOW);
      digitalWrite(led4,HIGH);
      break;
    case 4:
      digitalWrite(led4,LOW);
      digitalWrite(led5,HIGH);
      break;
    case 5:
      digitalWrite(led5,LOW);
      digitalWrite(led6,HIGH);
      break;
    default: 
      counter=-1;
     
      // if nothing else matches, do the default
      // default is optional
  }
  // put your main code here, to run repeatedly:
  laststate=actualstate;
  actualstate = digitalRead(button);
  if (actualstate==0 && laststate==1) {
     
    counter++;
  }
}
