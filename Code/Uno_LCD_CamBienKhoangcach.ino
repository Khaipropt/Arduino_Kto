#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 if 0x3F not working

const int trig = 6;  
const int echo = 5;
unsigned long thoigian; 
int khoangcach;          
int khoangcachtrai, khoangcachphai;
int gioihan = 25;
int dem = 0;
void setup() {

  // khoi tao lcd
  lcd.init();                      
  lcd.backlight();
  

  // khoi tao cam bien khoang cach
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  khoangcach = 0;
  
  dokhoangcach();
  lcd.setCursor(3,0);
  {
    lcd.setCursor(1,0);
    lcd.print("Khoang cach : ");
    lcd.setCursor(3,1);

    //Chuyen doi so thanh chu va hien thi lcd
    lcd.print((char)('0' + khoangcach / 100) );
    lcd.print((char)('0' + (khoangcach / 10) % 10) );
    lcd.print((char)('0' + khoangcach % 10));
    
    lcd.setCursor(10, 1);
    lcd.print("cm");
    delay(1000);
  }
  Serial.println(khoangcach);
  
}

// Do khoang cach chuyen doi thanh cm
void dokhoangcach()
{

  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian = pulseIn(echo, HIGH);

  khoangcach = thoigian / 2 / 29.412;
}
