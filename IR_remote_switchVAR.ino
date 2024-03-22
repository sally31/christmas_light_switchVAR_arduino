#include <IRremote.h>

#define BUTTON_1 16753245
#define BUTTON_2 16736925
#define BUTTON_3 16769565
#define BUTTON_4 16720605
#define BUTTON_5 16712445
#define BUTTON_6 16761405
#define BUTTON_ok 16726215
#define BUTTON_7 16769055
#define BUTTON_8 16754775
#define BUTTON_9 16748655
#define BUTTON_0 16750695
#define BUTTON_ast 16738455
#define BUTTON_hash 16756815
#define BUTTON_up 16718055
#define BUTTON_down 16730805
#define BUTTON_right 16734885
#define BUTTON_left 16716015
#define state0 0
#define state1 1
#define state2 2
#define state3 3
#define state4 4
uint8_t state = 0;
uint16_t counter = 0;

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define yellow 6
#define blue 12
#define red 11
#define orange 10
#define green 9
#define clear 8
bool flashlightActive = false;
uint32_t g_currentButton = 0;
uint32_t g_newButton = 0;


void setup()
{
  Serial.begin(9600);

  // Enable IRremote control reception
  irrecv.enableIRIn();
 
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(clear, OUTPUT);
}

void loop()
{
  // If an IR signal is received
  if(irrecv.decode(&results))
  {
    g_newButton = results.value;

    //irrecv.resume();
    Serial.println(g_newButton);
    Serial.println("0");
    Serial.println(g_currentButton);
    Serial.println("state");
    Serial.println(state);
    Serial.println("couner");
    Serial.println(counter);
  }

  
  if(g_currentButton != g_newButton)
  {

    g_currentButton = g_newButton;
    
    // Execute different actions based on the received IR code
    switch(g_currentButton)
    {
      //if botton 1 is pressed
      
      case BUTTON_1:
        {
          Serial.println("00");
          illumiPattern1();
        }
        break;

      //if botton 2 is pressed
      case BUTTON_2:
        {
          illumiPattern2();
        }
        break;

      //if botton 3 is pressed
      case BUTTON_3:
        {
          illumiPattern3();
        }
        break;

      //if botton 4 is pressed
      case BUTTON_4:
        {
          illumiPattern4();
        }
        break;

      //if botton 5 is pressed
      case BUTTON_5:
        {
          illumiPattern5();
        }
        break;

      //if botton 6 is pressed
      case BUTTON_6:
        {
          illumiPattern6();
        }
        break;

      case BUTTON_7:
        Serial.println("key7");
        break;
      
      case BUTTON_8:
        Serial.println("key8");
        break;

      case BUTTON_9:
        Serial.println("key9");
        break;
      
      case BUTTON_0:
        Serial.println("key0");
        break;
      
      case BUTTON_ast:
        Serial.println("key*");
        break;
      
      case BUTTON_hash:
        Serial.println("key#");
        break;
      

      //if botton ok is pressed
      case BUTTON_ok:
        Serial.println("key ok");
        stopFlashlight();
        break;
      
      case BUTTON_up:
        Serial.println("key UP");
        break;

      case BUTTON_right:
        Serial.println("key RIGHT");
        break;

      case BUTTON_down:
        Serial.println("key DOWN");
        break;

      case BUTTON_left:
        Serial.println("key LEFT");
        break;

    }
  }
}

// different Flashlight pattern 1-6
void illumiPattern1()
{
  Serial.println("1");
  switch(state)
  {
    Serial.println("2");
    case state0:
    {
      Serial.println("3");
      counter = 0;
      state ++;
      Serial.println(state);
      break;
    }

    case state1:
    {
      Serial.println("4");
      counter ++;
      Serial.println(counter);
      if(counter >= 500)
      {
        counter = 0;
        state ++;
      }
      
      Serial.println(state);
      break;
    }

    case state2:
    {
      digitalWrite(yellow, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(red, HIGH);
      digitalWrite(orange, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(clear, HIGH);
      counter = 0;
      state ++;
      break;
    }

    case state3:
    {
      counter ++;
      if(counter >= 500)
      {
        counter = 0;
        state ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(yellow, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(green, LOW);
      digitalWrite(clear, LOW);
      state = 1;
      break;
    }
  }
}

void illumiPattern2()
{
  while (g_currentButton == g_newButton)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(orange, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(clear, HIGH);

    if(irrecv.decode(&results))
    {
      g_newButton = results.value;
      irrecv.resume();
    }
  }
}

void illumiPattern3()
{
  while (g_currentButton == g_newButton)
  {
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(clear, HIGH);
    delay(100);
    digitalWrite(clear, LOW);

    if(irrecv.decode(&results))
    {
      g_newButton = results.value;
      irrecv.resume();
    }
  }
}

void illumiPattern4()
{
  while (g_currentButton == g_newButton)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(orange, HIGH);
    digitalWrite(clear, HIGH);
    delay(1000);
    digitalWrite(blue, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(clear, LOW);

    if(irrecv.decode(&results))
    {
      g_newButton = results.value;
      irrecv.resume();
    }
  }
}

void illumiPattern5()
{
  while (g_currentButton == g_newButton)
  {
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(clear, HIGH);
    delay(100);
    digitalWrite(clear, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(orange, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);

    if(irrecv.decode(&results))
    {
      g_newButton = results.value;
      irrecv.resume();
    }
  }
}

void illumiPattern6()
{
  while (g_currentButton == g_newButton)
  {
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(orange, HIGH);
    delay(100);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(clear, HIGH);
    delay(100);
    digitalWrite(clear, LOW);
    delay(100);
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(orange, LOW);
    delay(100);
    digitalWrite(red, LOW);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(yellow, LOW);
    delay(100);


    if(irrecv.decode(&results))
    {
      g_newButton = results.value;
      irrecv.resume();
    }
  }
}



// Function to stop the flashlight
void stopFlashlight()
{
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(orange, LOW);
  digitalWrite(green, LOW);
  digitalWrite(clear, LOW);
}
