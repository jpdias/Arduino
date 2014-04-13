int led1 = 12;
int led2 = 11;
int button = 7;
int state;
int laststate;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  laststate= state;
  state = digitalRead(button);
  if ((state ^ laststate) && !state) {
    Serial.println("Hello world!"); 
    Serial.flush(); 
  }
  if(state==HIGH){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
  }
  else{
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
  }
}
