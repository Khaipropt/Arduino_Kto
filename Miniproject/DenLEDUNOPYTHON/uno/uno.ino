int val;
#define buld1  2
#define buld2  3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buld1, OUTPUT);
  pinMode(buld2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    val = Serial.read();
    if(val == '1'){
      digitalWrite(buld1,HIGH);
      digitalWrite(buld2,HIGH);
      Serial.println("BOTH BULB ON");
    } else if(val=='2'){
      digitalWrite(buld1,HIGH);
      digitalWrite(buld2,LOW);
      Serial.println("LEFT BULB ON");
    } else if(val == '3'){
      digitalWrite(buld1,LOW);
      digitalWrite(buld2,HIGH);
      Serial.println("RIGHT BULB ON");
    } else if(val == '4'){
      digitalWrite(buld1,LOW);
      digitalWrite(buld2,LOW);
      Serial.println("BOTH BULB OFF");
    }
  }
}
