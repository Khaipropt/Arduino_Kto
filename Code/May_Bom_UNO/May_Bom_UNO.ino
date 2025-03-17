int Relay = 8;
void setup() {
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()){
    char input = Serial.read();
    if(input == '1'){
      digitalWrite(Relay, LOW);
      Serial.println("BAT");
    }
    else if(input == '2') {
      digitalWrite(Relay, HIGH);
      Serial.println("TAT");
    }
  }
}