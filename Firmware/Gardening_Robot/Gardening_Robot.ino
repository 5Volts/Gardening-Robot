const int M1A = 2;
const int M1B = 5;
const int M2A = 6;
const int M2B = 7;
const int pumpin = 8;
const int led1 = 9;
const int gnd = 10;
char input;
void setup() {
  // put your setup code here, to run once:
pinMode(M1A,OUTPUT);
pinMode(M1B,OUTPUT);
pinMode(M2A,OUTPUT);
pinMode(M2B,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(gnd,OUTPUT);
pinMode(pumpin,OUTPUT);
digitalWrite(pumpin,0);
digitalWrite(gnd,0);
digitalWrite(led1,1);
Serial.begin(9600);
}

void loop() { 
  if(Serial.available()){
    input = Serial.read();
    if(input == 'B'){
      backward();
    }
    else if(input == 'F'){
      forward();
    }
    else if(input == 'L'){
      left();     
    }
    else if(input == 'R'){
      right();
    }
    else if(input == 'X'){
      pump(true);    
    }
    else if(input == 'x'){
      pump(false);
    }
    delay(22);
  }
  else{
    stop_();
  }

}

void pump(bool in){
  if(in){
    digitalWrite(pumpin,0);
  }
  else{
    digitalWrite(pumpin,1);
  }
}

void stop_(){
  digitalWrite(M1A,0);
  digitalWrite(M1B,0);
  digitalWrite(M2A,0);
  digitalWrite(M2B,0);
}

void forward(){
  digitalWrite(M1A,0);
  analogWrite(M1B,200);
  digitalWrite(M2A,0);
  digitalWrite(M2B,1);
}
void backward(){
  digitalWrite(M1A,1);
  digitalWrite(M1B,0);
  digitalWrite(M2A,1);
  digitalWrite(M2B,0);
}
void left(){
  digitalWrite(M1A,1);
  digitalWrite(M1B,0);
  digitalWrite(M2A,0);
  digitalWrite(M2B,1);
}
void right(){
  digitalWrite(M1A,0);
  digitalWrite(M1B,1);
  digitalWrite(M2A,1);
  digitalWrite(M2B,0);
}
