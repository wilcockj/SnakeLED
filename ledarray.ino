 #include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    100
#define BRIGHTNESS 50
#define DELAY 100
CRGB leds[NUM_LEDS];
int potPin = 1;
int udPin = 3;
int lrPin = 4;
int val = 0;
int text_delay = analogRead(potPin);

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
//TODO use different numbers as different colors in order to keep a colored drawing constant
//RAINBOW snake
//use only the first 9 to output

//BIG
byte mytext[10][11]= {{1,0,0,0,0,0,1,1,1,1,0},{1,1,1,0,1,0,1,0,0,0,0},{1,0,1,0,1,0,1,0,1,1,0},{1,1,1,0,1,0,1,1,1,1,0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{1,0,0,0,0,0,1,1,1,1,0},{1,1,1,0,1,0,1,0,0,0,0},{1,0,1,0,1,0,1,0,1,1,0},{1,1,1,0,1,0,1,1,1,1,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void loop() {
  intro();
  FastLED.show();
  //spinningRainbow();
  FastLED.show();
  delay(1000);
  for(int x = 0; x < 1000; x++)
  {
    /*
    Serial.print(analogRead(lrPin));
    Serial.print('\n');
    Serial.print(analogRead(udPin));
    Serial.print('\n');
    */
    moveTest();
  }
  //Serial.println(leds[0]);
  for(int x = 0; x < 10; x++)
  {
    //for(int i = 0; i < 30; i++)
      //heart();
      //textbetter();
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
  //spinningRainbow();
  //spinningRainbow();
  FastLED.show();
  delay(1000);
}

void moveTest() {
  FastLED.clear();
  /*ud > 500 = up
  lr < 500 = left
  ud < 500 = down 
  lr > 500 = right*/
  int pos = 0;
  int prevpos = 0;
  int xdir = 0;
  int ydir = 0;
  //make dynamic array for tail of snake
  //or make it length 100 and if there is no tail set to -1
  //make tail by storing previous positions # tail length
  leds[pos] = CHSV(0, 255, 125);
  FastLED.show();
  int tail[99] = {0};
  int snakelen = 1;
  int fruitpos = -1;
  int snakedirection = 2; //0 = down 1 = up 2 =left 3 = right
  boolean fruitcollision = true;
  while(fruitcollision)
  {
    fruitpos = random(100);
    //Serial.println(fruitpos);
    if(!valinarray(tail,fruitpos,snakelen))
    {
      fruitcollision = false;
    }
  }
  
  
  /*for(int x = 0; x < 100; x++)
  {
    Serial.print('\n');
    Serial.print(tail[x]);
    Serial.print('\n');
  }*/
  
  while(true){
    /*fruitpos = random(0,100);
    Serial.print(fruitpos);*/
    fruitcollision = true;
      for(int x = 99; x > 0; x--)
      {
        tail[x]=tail[x-1];
      }
    prevpos = pos;
    FastLED.clear();
    xdir = analogRead(lrPin);
    ydir = analogRead(udPin);
    Serial.print(analogRead(lrPin));
    Serial.print('\n');
    Serial.print(analogRead(udPin));
    Serial.print('\n');
    //instead of current implementation set direction so if no more inputs the 
    //snake keeps travelling in a direction

    Serial.println(snakedirection);
    
    snakedirection = direction(xdir,ydir,snakedirection);
    
    if(snakedirection == 0)
    {
      
        if((pos+10) < 100)
          pos += 10;
        else if(pos + 10 > 100)
          pos -= 90;
        else if(pos = 90)
          pos = 0;
    }
    else if(snakedirection == 1)
    {
      
        if((pos-10) >= 0)
          pos -= 10;
        else if(pos-10 < 0)
          pos +=90;
      
    }
    else if(snakedirection == 2)
    { 
      
        if((pos+1) == 100)
            pos = 90;
        else if((pos+1)%10 == 0)
            pos-=9;
        else  
            pos++;
    }
    else if(snakedirection == 3)
    {
      
        if(((pos-1) % 10) == 9 || pos-1 == -1)
          pos+=9;
        else
          pos--;
   
    }
    
    if(pos != prevpos)
    {
      if(valinarray(tail,pos,snakelen))
      {
        Serial.println("You Lost");
        gameover();
        snakelen = 1;
        break;
      }
      tail[0] = pos;
      for(int x = 0; x < snakelen; x++)
      {
          //Serial.println(int(((255/25)*snakelen%25)));
          leds[tail[x]] = CHSV(int(((255/15)*(x%15))), 255, 125);
      }
      
      if(pos == fruitpos)
      {
        snakelen++;
        
        while(fruitcollision)
        {
          fruitpos = random(100);
          //Serial.println(fruitpos);
          if(!valinarray(tail,fruitpos,snakelen))
          {
            fruitcollision = false;
          }
        }
      }
      
      if(fruitpos != -1)
      {
        leds[fruitpos] = CHSV(122,255,180);
      }
      delay(150);
      FastLED.show();
    }
    
  }
}

int direction(int x, int y, int currdirection)
{
  if(x > 600 && x > y)
    { 
      if(currdirection != 2)
      { 
        currdirection = 3;
      }
      /*
      //30 instead of 29 we want 39
      if(((pos-1) % 10) == 9 || pos-1 == -1)
        pos+=9;
      else
        pos--;
      */
    }
    else if(x < 400 && x < y)
    {
      if(currdirection != 3)
      { 
        currdirection = 2;
      }
      /*
      //if((pos+1) < 100)
      if((pos+1) == 100)
          pos = 90;
      else if((pos+1)%10 == 0)
          pos-=9;
      else  
          pos++;
      */
    }
    else if(y < 400 && y < x)
    {
      if(currdirection != 1)
      {
        currdirection = 0;
      }
      /*
      if((pos+10) < 100)
        pos += 10;
      else if(pos + 10 > 100)
        pos -= 90;
      else if(pos = 90)
        pos = 0;
        */
      
    }
    else if(y > 600 && y > x)
    {
      if(currdirection != 0)
      {
        currdirection = 1;
      }
      /*
      if((pos-10) >= 0)
        pos -= 10;
      else if(pos-10 < 0)
        pos +=90;
      */
    }
    return currdirection;
}

void gameover()
{
  byte message[10][40] = {
{1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,0},
{1,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0},
{1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,0},
{1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0},
{1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0},
{1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};



 for(int x = 0; x < 30; x++)
 {
  textbetter(message);
 }
}

bool valinarray(int array[],int element,int len)
{
  for (int i = 0; i < len; i++) {
      if (array[i] == element) {
          return true;
      }
    }
  return false;
}
void intro(){
  FastLED.clear();
  byte mytext[10][10] = {
{1,1,1,0,0,0,0,1,0,0},
{0,1,0,0,1,0,0,1,1,1},
{0,1,0,1,0,1,0,1,0,1},
{1,1,0,1,1,1,0,1,0,1},
{0,0,0,1,0,1,0,0,0,0},
{1,1,1,0,0,0,0,1,0,1},
{1,0,1,0,0,0,0,1,1,1},
{1,1,1,0,1,1,1,0,1,0},
{1,0,1,0,1,0,1,0,1,0},
{1,1,1,0,1,1,1,0,1,0}
};

//got through all coloumns and set colors 
//yellow then redorange then pink/purple then green then blue
//change y value faster to overlap?
for(int y = 0; y < 5; y++)
{  
  for(int x = 0; x < 10; x++)
  {
    for(int i = 0; i < 10; i++)
    {
      if(y == 0)
        if(mytext[i][x] == 1) 
           leds[9-x+10*i] = CHSV(45,255,200);
      if(y == 1)
        if(mytext[i][x] == 1) 
           leds[9-x+10*i] = CHSV(14,255,200);
      if(y == 2)
        if(mytext[i][x] == 1) 
           leds[9-x+10*i] = CHSV(211,255,200);
      if(y == 3)
        if(mytext[i][x] == 1) 
           leds[9-x+10*i] = CHSV(125,255,200);
      if(y == 4)
        if(mytext[i][x] == 1) 
           leds[9-x+10*i] = CHSV(164,255,200);
    }
    delay(50);
    FastLED.show();
  }
}
delay(5000);
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
    delay(100);
    FastLED.show();
  }
  
}
void textbetter(byte text[][40]){
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
    if(text_delay < 0)
    {
      text_delay = 0;
    }
  }
  
  int array_diff = width-9;
  
  int arrayrealdiff = width-array_diff;
  
  for(int i = 0; i < 10; i++)
  {
    if (text[0][i]==1)
      leds[arrayrealdiff-i] = CHSV(0,255,200);//CRGB::Aquamarine;
    if (text[1][i]==1)
      leds[arrayrealdiff-i+10] = CHSV(0,255,200);//CRGB::DarkCyan;//Honeydew;
    if (text[2][i]==1)
      leds[arrayrealdiff-i+20] = CHSV(0,255,200);//CRGB::Fuchsia;
    if (text[3][i]==1)
      leds[arrayrealdiff-i+30] = CHSV(0,255,200);//CRGB::Navy;
    if (text[4][i]==1)
      leds[arrayrealdiff-i+40] = CHSV(0,255,200);//CRGB::DarkTurquoise;
    if (text[5][i]==1)
      leds[arrayrealdiff-i+50] = CHSV(0,255,200);//CRGB::LightSteelBlue;//Honeydew;
    if (text[6][i]==1)
      leds[arrayrealdiff-i+60] = CHSV(0,255,200);//CRGB::Fuchsia;
    if (text[7][i]==1)
      leds[arrayrealdiff-i+70] = CHSV(0,255,200);//CRGB::Navy;
    if (text[8][i]==1)
      leds[arrayrealdiff-i+80] = CHSV(0,255,200);//CRGB::BlueViolet;
    if (text[9][i]==1)
      leds[arrayrealdiff-i+90] = CHSV(0,255,200);//CRGB::LightSteelBlue;//Honeydew;
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
