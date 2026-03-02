char direction;
int SL = 5;                // speed LEFT motor (PWM)
int LMP = 8;               // left motor +
int LMN = 9;               // left motor -
int SR = 6;                // speed right motor (PWM)
int RMP = 10;              // right motor +
int RMN = 11;              // right motor -

void setup() {
  pinMode(SL, OUTPUT);     // setup left motor speed
  pinMode(LMP, OUTPUT);    // setup left motor +
  pinMode(LMN, OUTPUT);    // setup left motor -
  pinMode(SR, OUTPUT);     // setup right motor speed
  pinMode(RMP, OUTPUT);    // setup right motor +
  pinMode(RMN, OUTPUT);    // setup right motor -
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    direction = Serial.read();
    Serial.println(direction);
  }
  
  if (direction == 'f') {        // Forward
    digitalWrite(LMP, HIGH);
    digitalWrite(LMN, LOW);      
    analogWrite(SL, 128);
    
    digitalWrite(RMP, HIGH);
    digitalWrite(RMN, LOW);
    analogWrite(SR, 128);
  }
  else if (direction == 'b') {   // Backward
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, HIGH);
    analogWrite(SL, 128);
    
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, HIGH);
    analogWrite(SR, 128);        
  }
  else if (direction == 'r') {   // Turn Right
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, HIGH);
    analogWrite(SL, 128);
    
    digitalWrite(RMP, HIGH);      
    digitalWrite(RMN, LOW);
    analogWrite(SR, 128);        
  }
  else if (direction == 'l') {   // Turn Left
    digitalWrite(LMP, HIGH);      
    digitalWrite(LMN, LOW);
    analogWrite(SL, 128);
    
    digitalWrite(RMP, LOW);     
    digitalWrite(RMN, HIGH);
    analogWrite(SR, 128);
  }
  else if (direction == 's') {   // Stop 
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, LOW);
    analogWrite(SL, 0);
    
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, LOW);
    analogWrite(SR, 0);
  }
  else if (direction == 'z') {    //forward right
    digitalWrite(LMP, HIGH);     
    digitalWrite(LMN, LOW);
    analogWrite(SL, 64);      
    
    digitalWrite(RMP, HIGH);     
    digitalWrite(RMN, LOW);
    analogWrite(SR, 128);        
  }
  else if (direction == 'x') {    //forward left 
    digitalWrite(LMP, HIGH);     
    digitalWrite(LMN,LOW  );
    analogWrite(SL, 128);       
    
    digitalWrite(RMP, HIGH);     
    digitalWrite(RMN, LOW);
    analogWrite(SR, 64);       
  }
  else if (direction == 'c') {    //backward left
    digitalWrite(LMP, LOW);     
    digitalWrite(LMN, HIGH);
    analogWrite(SL, 128);      
    
    digitalWrite(RMP, LOW);     
    digitalWrite(RMN, HIGH);
    analogWrite(SR, 64);        
  }
  else if (direction == 'v') {    //backward right 
    digitalWrite(LMP, LOW);     
    digitalWrite(LMN,HIGH);
    analogWrite(SL, 64);       
    
    digitalWrite(RMP, LOW);     
    digitalWrite(RMN, HIGH);
    analogWrite(SR, 128);       
  }
}


