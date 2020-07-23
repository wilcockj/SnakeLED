#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    100
#define BRIGHTNESS 50
#define DELAY 100
CRGB leds[NUM_LEDS];
int potPin = 1;
int val = 0;
int text_delay = analogRead(potPin);
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
}
//TODO use different numbers as different colors in order to keep a colored drawing constant
//RAINBOW snake
//use only the first 9 to output
/*
byte text_r1[] = {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r2[] = {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r3[] = {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r4[] = {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r5[] = {1,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r6[] = {1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r7[] = {1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r8[] = {1,0,0,0,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

byte text_r9[] = {1,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0};

byte text_r10[] = {1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
*/

//BIG
byte text[10][11]= {{1,0,0,0,0,0,1,1,1,1,0},{1,1,1,0,1,0,1,0,0,0,0},{1,0,1,0,1,0,1,0,1,1,0},{1,1,1,0,1,0,1,1,1,1,0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{1,0,0,0,0,0,1,1,1,1,0},{1,1,1,0,1,0,1,0,0,0,0},{1,0,1,0,1,0,1,0,1,1,0},{1,1,1,0,1,0,1,1,1,1,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

byte text_r1[] = {1,0,0,0,0,0,1,1,1,1,0};
byte text_r2[] = {1,1,1,0,1,0,1,0,0,0,0};
byte text_r3[] = {1,0,1,0,1,0,1,0,1,1,0};
byte text_r4[] = {1,1,1,0,1,0,1,1,1,1,0};
byte text_r5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte text_r6[] = {1,0,0,0,0,0,1,1,1,1,0};
byte text_r7[] = {1,1,1,0,1,0,1,0,0,0,0};
byte text_r8[] = {1,0,1,0,1,0,1,0,1,1,0};
byte text_r9[] = {1,1,1,0,1,0,1,1,1,1,0};
byte text_r10[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};









/*
byte text_r1[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,0};
byte text_r2[] = {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0,0};
byte text_r3[] = {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,0};
byte text_r4[] = {1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,0};
byte text_r5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte text_r6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte text_r7[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte text_r8[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte text_r9[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte text_r10[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
*/


void loop() {
  FastLED.show();
  spinningRainbow();
  FastLED.show();
  delay(1000);
  //Serial.println(leds[0]);
  for(int x = 0; x < 1000; x++)
  {
    for(int i = 0; i < 30; i++)
      //heart();
      textbetter();
      //textscroll();
    //heart();
  }
  //Big();
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = CRGB::Blue;
    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    delay(30);
  }
  /*for(int i = 0; i < 30; i++)
  {
    leds[i] = CRGB((250-(3*i)),(60+3*i),(180-3*i));
    FastLED.show();
    delay(DELAY);
  }*/
  //spinningRainbow();
  spinningRainbow();
  FastLED.show();
  delay(2000);
}

void spinningRainbow() {
  // variable used for the initial hue of the rainbow
  // we start it out at 0
  // but since it's static, it'll keep it's value as we change it
  static byte initialHue = 0;
  
  // increase the hue by 1 each time
  initialHue = initialHue + 1;
  
  // the amount we want the hue to change between each LED
  // by dividing the number of hues (255), by the number of LEDs,
  // this code makes each LED a different color
  // and covers the entire rainbow spectrum (red, orange, yellow, green, blue, indigo, violet)
  byte changeInHue = 255 / NUM_LEDS;
  
  // use FastLED to fill the LEDs with a rainbow
  fill_rainbow(leds, NUM_LEDS, initialHue, changeInHue);
}

void Big()
{
  FastLED.clear ();
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[9] = CRGB::Red;
  leds[13] = CRGB::Red;
  leds[15] = CRGB::Red;
  leds[17] = CRGB::Red;
  leds[18] = CRGB::Red;
  leds[19] = CRGB::Red;
  leds[20] = CRGB::Red;
  leds[21] = CRGB::Red;
  leds[23] = CRGB::Red;
  leds[25] = CRGB::Red;
  leds[27] = CRGB::Red;
  leds[29] = CRGB::Red;
  leds[30] = CRGB::Red;
  leds[31] = CRGB::Red;
  leds[32] = CRGB::Red;
  leds[33] = CRGB::Red;
  leds[35] = CRGB::Red;
  leds[37] = CRGB::Red;
  leds[38] = CRGB::Red;
  leds[39] = CRGB::Red;
  
  FastLED.show();
  delay(5000);
  
  
  
  for(int x = 0; x < 1000; x++)
  {
    for(int x = 0; x < 40; x++)
    {
      if(leds[x])
      {
        leds[x] = CRGB::Black;
        if((x+1)%10 != 0)
        {
          leds[x+1] = CRGB::Red;
        }
        else
        {
          leds[x-9] = CRGB::Red;
        }
        FastLED.show();
      }
      delay(500);
    }
    delay(500);
  }
}
void heart(){
  
  byte heart_r1[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; 
  byte heart_r2[] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
  byte heart_r3[] = {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
  byte heart_r4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  
  for(int x = 0; x < 1000; x++)
  {
    FastLED.clear();
    int array_lenheart = sizeof(heart_r1)/sizeof(heart_r1[0]);
    int endstate1 = heart_r1[0];
    int endstate2 = heart_r2[0];
    int endstate3 = heart_r3[0];
    int endstate4 = heart_r4[0];
    for(int x = 0; x < array_lenheart-1; x++)
    {
      heart_r1[x] = heart_r1[x+1];
      heart_r2[x] = heart_r2[x+1];
      heart_r3[x] = heart_r3[x+1];
      heart_r4[x] = heart_r4[x+1];
    }
    
    heart_r1[array_lenheart-1] = endstate1;
    heart_r2[array_lenheart-1] = endstate2;
    heart_r3[array_lenheart-1] = endstate3;
    heart_r4[array_lenheart-1] = endstate4;
    int array_diff2 = array_lenheart-9;
    int arrayrealdiff2 = array_lenheart-array_diff2;
    for(int i = 0; i < 10; i++)
    {
      if(heart_r1[i]==1)
        leds[arrayrealdiff2-i] = CRGB::HotPink;
      if (heart_r2[i]==1)
        leds[arrayrealdiff2-i+10] = CRGB::HotPink;//Honeydew;
      if (heart_r3[i]==1)
        leds[arrayrealdiff2-i+20] = CRGB::HotPink;
      if (heart_r4[i]==1)
        leds[arrayrealdiff2-i+30] = CRGB::HotPink;
    }
    delay(200);
    FastLED.show();
  }
  
}
void textbetter(){
  int potenti = analogRead(potPin);
  Serial.print('\n');
  Serial.print(analogRead(potPin));
  Serial.print('\n');
  //TODO use potentionmeter to change delay and when goes to a certain point reverse direction
  int end = 10;
  int start = 0;
  int next = start;
  int i = 0;
  FastLED.clear();
  int endstatearray[10];
  int height = sizeof(text)/sizeof(text[0]);
  int width = sizeof(text[0])/sizeof(text[0][0]);
  Serial.print('\n');
  for(int x = 0; x < 10; x++)
  {
    Serial.print('\n');
    Serial.print(text[x][width-1]);
    endstatearray[x] = text[x][width-1];
  }
  /*
   * change 10 variables to one table with rows and coloumns
   */
  //left to right
  if(potenti < 500)
  {
    for(int x = 0; x < 10; x++)
    {
      for(int i = width-1; i > 0; i--)
      {  
        text[x][i] = text[x][i-1];
      }
    }
    for(int x = 0; x < 10; x++)
    {
      text[x][0] = endstatearray[x];
    }
    text_delay = potenti;
    Serial.print(text_delay);
    Serial.print('\n');
  }
  
  //right to left
  if(potenti >= 500)
  {
    for(int x = 0; x < 10; x++)
    {
      endstatearray[x] = text[x][0];
    }
    for(int x = 0; x < 10; x++)
    {
      for(int i = 0; i < width-1; i++)
      {  
        text[x][i] = text[x][i+1];
      }
    }
    for(int x = 0; x < 10; x++)
    {
      text[x][width-1] = endstatearray[x];
    }
    //text_delay = potenti;
    Serial.print(text_delay);
    Serial.print('\n');
    //Serial.print(potenti);
    //Serial.print('\n');
    text_delay = 960-potenti;
  }
  
  int array_diff = width-9;
  
  int arrayrealdiff = width-array_diff;
  
  for(int i = 0; i < 10; i++)
  {
    if (text[0][i]==1)
      leds[arrayrealdiff-i] = CRGB::Aquamarine;
    if (text[1][i]==1)
      leds[arrayrealdiff-i+10] = CRGB::DarkCyan;//Honeydew;
    if (text[2][i]==1)
      leds[arrayrealdiff-i+20] = CRGB::Fuchsia;
    if (text[3][i]==1)
      leds[arrayrealdiff-i+30] = CRGB::Navy;
    if (text[4][i]==1)
      leds[arrayrealdiff-i+40] = CRGB::DarkTurquoise;
    if (text[5][i]==1)
      leds[arrayrealdiff-i+50] = CRGB::LightSteelBlue;//Honeydew;
    if (text[6][i]==1)
      leds[arrayrealdiff-i+60] = CRGB::Fuchsia;
    if (text[7][i]==1)
      leds[arrayrealdiff-i+70] = CRGB::Navy;
    if (text[8][i]==1)
      leds[arrayrealdiff-i+80] = CRGB::BlueViolet;
    if (text[9][i]==1)
      leds[arrayrealdiff-i+90] = CRGB::LightSteelBlue;//Honeydew;
  } 
  delay(text_delay);
  FastLED.show();
}

void swap(int& x,int& y){
  int temp;
  temp = x;
  x = y;
  y = temp;
}
