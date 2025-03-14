#include<IRremote.h>
const int chanRemote = 8;
int pin = 7;
IRsend irsend(pin);
IRrecv irrecv(chanRemote);
decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  char input = Serial.read();
  if(input == '1'){
    unsigned long tData = 0xFFA857;
    irsend.sendNEC(0xFFA857, 32);
    delay(2000);
  }
  
  if(irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    delay(200);
    irrecv.resume();
  }
}
