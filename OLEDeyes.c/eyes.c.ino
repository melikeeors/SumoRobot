#include <Adafruit_GFX.h>  // Include core graphics library
#include <Adafruit_ST7735.h>  // Include Adafruit_ST7735 library to drive the display

// Declare pins for the display:
#define TFT_CS     10
#define TFT_RST    9  // You can also connect this to the Arduino reset in which case, set this #define pin to -1!
#define TFT_DC     8
// The rest of the pins are pre-selected as the default hardware SPI for Arduino Uno (SCK = 13 and SDA = 11)

// Create display:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
int counter = 0;


void squint_eyes(){
  int sq = 70;
  for(int i = 0; i < 20; i++){
    tft.fillTriangle(80,65, 80,150, sq,150, ST7735_BLACK);
    tft.fillTriangle(80, 160 - 65, 80, 160 - 150, sq, 160 - 150, ST7735_BLACK);
    sq--;
  }
  delay(2000);
  clear_screen();
}


void close_eyes(){
  int x = 76;
  int y = 45;
  int sizeX = 10; // Initial width
  int sizeY = 45;  // Initial height
  int radius = 10;
  for (int k = 0; k <= 25; k++){
    // Left eye
    tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX, sizeY, radius, ST7735_BLACK);

    // Right eye
    tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX, sizeY, radius, ST7735_BLACK);
    delay(50);
    x--;
  }
  delay(1000);
  clear_screen();
}

void draw_eyes(){
  int x = 55;
  int y = 45;
  int sizeX = 10; // Initial width
  int sizeY = 2;  // Initial height
  int radius = 10;

  if (counter == 0){
    // Open eyes on startup
    for (int i = 0; i <= 20 ; i++) {
      // Left eye
      tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX, sizeY, radius, 0x07FF);

      // Right eye
      tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX, sizeY, radius, 0x07FF);

      delay(50); // Adjust the delay to control the speed of the animation

      // Increase the size for the next frame
      sizeY += 2;
    }
    for (int j = 0; j <= 30; j++){
      // Left eye
      tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX, sizeY, radius, 0x07FF);

      // Right eye
      tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX, sizeY, radius, 0x07FF);
      delay(30);
      sizeX++;
    }
    counter++;
    delay(2000);
  }
  else{
    // Draw the eyes fully opened
    x = 55;  
    sizeX = 41;  
    sizeY = 44;  

    // Left eye
    tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX, sizeY, radius, 0x07FF);

    // Right eye
    tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX, sizeY, radius, 0x07FF);
    //delay(2000);
    //clear_screen();
  }
  delay(2000);
}


void move_eyes(){
  int x = 55;
  int y = 45;
  int sizeX = 41; // Initial width
  int sizeY = 44;  // Initial height
  int radius = 10;
  int exp = 0;
  int deltaY = -10; // Initial change in Y position

  // Loop for expanding the eyes(right side)
  for(int r = 0; r < 3; r++){
      // Draw a black rectangle to "clear" the screen
      tft.fillRect(0, 0, tft.width(), tft.height(), ST7735_BLACK);

      // Draw left eye with expanded size
      tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX + exp, sizeY + exp, radius, 0x07FF);

      // Draw right eye
      tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX, sizeY, radius, 0x07FF);

      // Move rectangles upwards
      y += deltaY;
      exp += 5; // Increase eye expansion
      delay(100);

      // Check if it's the last iteration
      if (r == 2) {
          // Delay before reverting to normal
          delay(1000);
      }
  }
  exp =0;
  // Loop for reverting eyes to normal size
  for(int m = 0; m < 3; m++){
      
      // Draw a black rectangle to "clear" the screen
      tft.fillRect(0, 0, tft.width(), tft.height(), ST7735_BLACK);

      // Draw left eye with reduced size
      tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX - exp, sizeY - exp, radius, 0x07FF);

      // Draw right eye
      tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX, sizeY, radius, 0x07FF);

      // Decrease eye expansion and move rectangles downwards
      exp -= 5;
      y += 15; // Adjust the y position accordingly
      delay(100);
  }
  exp =0;
  // Loop for expanding the eyes(left side)
    for(int l = 0; l < 2; l++){
      
      // Draw a black rectangle to "clear" the screen
      tft.fillRect(0, 0, tft.width(), tft.height(), ST7735_BLACK);

      // Draw left eye with expanded size
      tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX , sizeY , radius, 0x07FF);

      // Draw right eye
      tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX+ exp, sizeY+exp, radius, 0x07FF);

      // Move rectangles upwards
      y -= deltaY;
      exp += 5; // Increase eye expansion

      // Check if it's the last iteration
      if (l == 1) {
          // Delay before reverting to normal
          delay(1000);
      }
  }
  exp =0;
  // Loop for reverting eyes to normal size
  for(int m = 0; m < 3; m++){
      
      // Draw a black rectangle to "clear" the screen
      tft.fillRect(0, 0, tft.width(), tft.height(), ST7735_BLACK);

      // Draw left eye with reduced size
      tft.fillRoundRect(x - sizeX / 2, y - sizeY / 2, sizeX , sizeY , radius, 0x07FF);

      // Draw right eye
      tft.fillRoundRect(x - sizeX / 2, y + 65 - sizeY / 2, sizeX+ exp, sizeY+ exp, radius, 0x07FF);

      // Decrease eye expansion and move rectangles downwards
      exp -= 1;
      y -= 15; // Adjust the y position accordingly
      Serial.print(exp);
      Serial.print("\n");
      delay(100);
      delay(100);
  }
  delay(1000);
  clear_screen();
}

void clear_screen(){
  tft.fillScreen(ST7735_BLACK);  // Fill screen with black
}

void setup() {
  tft.initR(INITR_BLACKTAB);  // Initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);  // Fill screen with black
  Serial.begin(9600);

}

void loop() {
  draw_eyes();
  move_eyes();
  draw_eyes();
  close_eyes();
  draw_eyes();
  squint_eyes(); 
  delay(100);
}
