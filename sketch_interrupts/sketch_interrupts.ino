int led1= 12;
int led2 =11;
int button=7;
int counter=0;
boolean flag=false;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  cli();
    TCCR0A=0;
    TCCR0B=0;
    TCNT0=0;
    OCR0A=124;
    TCCR0A|=(1<<WGM01);
    TCCR0B|=(1<<CS01)|(1<<CS00);
    TIMSK0|=(1<<OCIE0A);
  sei();
}
int actual=0, last =0;

ISR(TIMER0_COMPA_vec){
  if(flag){
    counter=0;
    flag=false;  
  }
  if(actual==0){
    counter++;
  }
}


void loop() {
  last=actual;
  actual = digitalRead(button);
  
  if(actual == 0){
    digitalWrite(led1,HIGH);  
  }
  else{
    digitalWrite(led1,LOW);  
  }
  if(last == 0 && actual ==1){
    flag=true;
  }
  if(counter>200){
    digitalWrite(led2,HIGH);  
  }
  else{
    digitalWrite(led2,LOW);}
}
