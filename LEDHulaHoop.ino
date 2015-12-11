#include <Adafruit_NeoPixel.h>

#define PIN 11

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ800);
int buttonPin = 12;
int curState = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  buttonState = digitalRead(buttonPin);
  if(buttonState != lastButtonState){
    if(buttonState ==LOW){
        curState++;
      }
  }
  lastButtonState = buttonState;
  cases();
}
void cases(){
    int tstate;
    tstate = curState % 7;
    switch(tstate){
    case 0 :
      for(int i=0;i<10;i++){
        strip.setPixelColor(i,255, 0, 0);
        strip.show();
        delay(100);
        buttonState = digitalRead(buttonPin);
        if(buttonState ==LOW){
          break;
        }
      }
      for(int i=0;i<10;i++){
        strip.setPixelColor(i,0, 255, 0);
        strip.show();
        delay(100);
        buttonState = digitalRead(buttonPin);
        if(buttonState ==LOW){
          break;
        }
      }
      for(int i=0;i<10;i++){
        strip.setPixelColor(i,0, 0, 255);
        strip.show();
        delay(100);
        buttonState = digitalRead(buttonPin);
        if(buttonState ==LOW){
          break;
        }
      }
      break;
    case 1 :
      for (int i =0;i<10;i++){
       strip.setPixelColor(i,0,0,0); 
      }
      strip.show();
      for(int i=0;i<10;i++){
        strip.setPixelColor(i,128, 128, 128);
        if (i==0){
         strip.setPixelColor(9,0,0,0); 
        }else{
          strip.setPixelColor(i-1,0, 0, 0);
        }
        strip.show();
        delay(50);
        buttonState = digitalRead(buttonPin);
        if(buttonState ==LOW){
          break;
        }
      }
      break;
      case 2:
      for (int i=0;i<10;i++){
        if(i%2 ==0){
           strip.setPixelColor(i,255,0,0); 
        }else{
          strip.setPixelColor(i,0,0,0); 
        }
      }
      strip.show();
      delay(500);
      for (int i=0;i<10;i++){
        if(i%2 ==1){
           strip.setPixelColor(i,255, 0, 0);
        }else{
          strip.setPixelColor(i,0,0,0); 
        }
      }
      strip.show();
      delay(500);
      break;
      case 3:
        strip.setPixelColor(0, 255,0,0);
        strip.setPixelColor(1, 255,127,0);
        strip.setPixelColor(2, 255,255,0);
        strip.setPixelColor(3, 0,255,0);
        strip.setPixelColor(4, 0,255,127);
        strip.setPixelColor(5, 0,255,255);
        strip.setPixelColor(6, 0,127,255);
        strip.setPixelColor(7, 0,0,255);
        strip.setPixelColor(8, 127,0,255);
        strip.setPixelColor(9, 255,0,127);
        strip.show();
        break;
      case 4:
        for(int i = 0;i<10;i++){
          for(int j = 0;j<10;j++){
            strip.setPixelColor(j, 0,0,0);
          }
          strip.setPixelColor(i, 0,0,255);
          if(i==0){
            strip.setPixelColor(9,0,0,64);          
          }else{
            strip.setPixelColor(i-1,0,0,64);
          }
          if(i==0){
            strip.setPixelColor(8,0,0,16);          
          }if(i==1){
            strip.setPixelColor(9,0,0,16);  
          }else{
            strip.setPixelColor(i-2,0,0,16);
          }
          strip.show();
          delay(100);
        }
        break;
      case 5:
        for(int i = 0;i<10;i++){
           strip.setPixelColor(i,0,204,204); 
        }
        strip.show();
        break;
      case 6:
      int r;
      int g;
      int b;
      r = random(255);
      g = random(255);
      b = random(255);
        for(int i = 0;i<10;i++){
          strip.setPixelColor(i,g,r,b);
          strip.show();
          delay(25);
        }
        break;
              
//    case 2:
//      for(int j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//        for(int i=0; i< strip.numPixels(); i++) {
//          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//            buttonState = digitalRead(buttonPin);
//            if(buttonState ==LOW){
//                break;
//            }
//        strip.show();
//        delay(25);
//        }
//      }
//      break;
    }
}
//void rainbow(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256; j++) {
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

