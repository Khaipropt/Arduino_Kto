#include <TFT.h>  
#include <SPI.h>

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN  0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF


// pin definition for Arduino UNO
#define cs   10
#define dc   9
#define rst  8


// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);



void setup() {

  //initialize the library
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  //set the text size
  TFTscreen.setTextSize(2);
}

void loop() {

  //generate a random color
  int redRandom = random(0, 255);
  int greenRandom = random (0, 255);
  int blueRandom = random (0, 255);
  
  // set a random font color
  TFTscreen.stroke(redRandom, CYAN, blueRandom);
  
  // print Hello, World! in the middle of the screen
  // TFTscreen.text("Hello, World!", 6, 57);


  // draw bitmap link web : http://www.rinkydinkelectronics.com/_t_doimageconverter565.php
  TFTscreen.drawBitmap(2, 2, const uint8_t *bitmap, 80, 80)
  
  // wait 200 miliseconds until change to next color
  delay(200);
}