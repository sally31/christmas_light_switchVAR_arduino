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
    illumiPattern1();

    //irrecv.resume();
    Serial.println("state");
    Serial.println(state);
    Serial.println("couner");
    Serial.println(counter);
  }

}

// different Flashlight pattern 1-6
void illumiPattern1()
{
  switch(state)
  {
    case state0:
    {
      counter = 0;
      state ++;
      break;
    }

    case state1:
    {
      counter ++;
      if(counter >= 50)
      {
        counter = 0;
        state ++;
      }
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
      if(counter >= 50)
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
