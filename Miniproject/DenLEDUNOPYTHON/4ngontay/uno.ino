int val;
#define buld1  2
#define buld2  3
#define buld3  4
#define buld4  5
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buld1, OUTPUT);
  pinMode(buld2, OUTPUT);
  pinMode(buld3, OUTPUT);
  pinMode(buld4, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    val = Serial.read();
    if(val == '1'){
      digitalWrite(buld1,HIGH);
      digitalWrite(buld2,LOW);
      digitalWrite(buld3,LOW);
      digitalWrite(buld4,LOW);
      Serial.println("1 BULB ON");
    } else if(val=='2'){
      digitalWrite(buld1,HIGH);
      digitalWrite(buld2,HIGH);
      digitalWrite(buld3,LOW);
      digitalWrite(buld4,LOW);
      Serial.println("2 BULB ON");
    } else if(val == '3'){
      digitalWrite(buld1,HIGH);
      digitalWrite(buld2,HIGH);
      digitalWrite(buld3,HIGH);
      digitalWrite(buld4,LOW);
      Serial.println("3 BULB ON");
    } else if(val == '4'){
      digitalWrite(buld1,HIGH);
      digitalWrite(buld2,HIGH);
      digitalWrite(buld3,HIGH);
      digitalWrite(buld4,HIGH);
      Serial.println("4 BULB OFF");
    } else if(val == '5'){
      digitalWrite(buld1,LOW);
      digitalWrite(buld2,LOW);
      digitalWrite(buld3,LOW);
      digitalWrite(buld4,LOW);
      Serial.println("0 BULB ON");
    }
  }
}
