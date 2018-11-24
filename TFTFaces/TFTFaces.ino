#include <TFT.h>
#include <SPI.h>

// Define pins that will be used as parameters in the TFT constructor
#define cs   10 // add your own CS pin number
#define dc   9 // add your own DC pin number
#define rst  8 // add your own RS pin number

#define GRAY      0xFF7D
#define GREENISH  0x473A
#define BLUEISH   0x2986
#define BLACK     0x0000

// Instantiate the TFT constructor with the pin values defined above  
TFT tft = TFT(cs, dc, rst);

//shapes properties
uint16_t eyeSize;
uint16_t eyeIris;
uint16_t topSection;

uint16_t shapesYPos;
uint16_t irisRandomPos;

void setup() {

  //initialize the library
  tft.begin();

  //initialize shapes size
  initData();

  //tft orientation horizontal
  tft.setRotation(1);
  // background color (black in our case)
  tft.fillScreen(BLACK);

  delay(100);
}

//initialize propetries
void initData() {
  eyeSize = tft.width() / 6;
  eyeIris = eyeSize / 4;
  topSection = eyeSize * 2;

  shapesYPos = tft.height() / 3;
}

void loop() {
  randomIrisPosGenerate();
  baseEyes();
  delay(5000);
  
  randomIrisPosGenerate();
  angryEyes();
  randomIrisPosGenerate();
  suspiciousEyes();
  randomIrisPosGenerate();
  sadEyes();
  randomIrisPosGenerate();
  lookingAround();
  randomIrisPosGenerate();
  sleepyFace();
  randomIrisPosGenerate();
  angryEyes();
  randomIrisPosGenerate();
  sadEyes();
}

void randomIrisPosGenerate() {
  irisRandomPos = random(eyeIris, eyeSize * 2 - eyeIris);
}

void baseEyes() {
  //eyes
  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize, GRAY);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize, GRAY);
  //eye center
  tft.fillCircle(((tft.width() / 4) - eyeSize) + irisRandomPos, shapesYPos, eyeIris, BLUEISH);
  tft.fillCircle(((tft.width() - tft.width() / 4) - eyeSize) + irisRandomPos, shapesYPos, eyeIris, BLUEISH);
}

void lookingAround() {
  baseEyes();
  //lids
  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);

  delay(5000);
}

void sleepyFace() {
  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize, GRAY);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize, GRAY);

  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize - 2, BLACK);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize - 2, BLACK);

  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, 15, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, 15, BLACK);

  //mouth
  tft.fillRect((tft.width() / 2) - eyeSize / 2, tft.height() - eyeSize, eyeSize, eyeSize / 4, GRAY);

  delay(5000);
}

void angryEyes() {
  baseEyes();

  tft.fillTriangle(tft.width() / 4 - eyeSize ,tft.height() / 6, tft.width() / 2, 0, tft.width() / 2, shapesYPos, BLACK);
  tft.fillTriangle(tft.width() - tft.width() / 4 + eyeSize , tft.height() / 6, tft.width() / 2, 0, tft.width() / 2, shapesYPos, BLACK);

  delay(5000);
}

void sadEyes() {
  baseEyes();

  tft.fillTriangle(tft.width() / 4 - eyeSize , shapesYPos, tft.width() / 4 - eyeSize , 0, tft.width() / 2, 0, BLACK);
  tft.fillTriangle(tft.width() - tft.width() / 4 + eyeSize ,  shapesYPos, tft.width() - tft.width() / 4 + eyeSize, 0, tft.width() / 2, 0, BLACK);

  delay(5000);
}

void suspiciousEyes() {
  baseEyes();

  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2 , BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);

  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos + eyeSize / 2, topSection, eyeSize / 2 + eyeSize / 4, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos + eyeSize / 2, topSection, eyeSize / 2 + eyeSize / 4, BLACK);

  delay(5000);
}


