
#define state0 0
#define state1 1
#define state2 2
#define state3 3
#define state4 4

//uint8_t stateP1 = 0;
//uint8_t stateP2 = 0;
//uint8_t stateP3 = 0;
//uint8_t stateP4 = 0;
//uint8_t stateP5 = 0;
//uint8_t stateP6= 0;
//uint16_t counterP1 = 0;
//uint16_t counterP2 = 0;
//uint16_t counterP3 = 0;
//uint16_t counterP4 = 0;
//uint16_t counterP5 = 0;
//uint16_t counterP6 = 0;

#define yellow 6
#define blue 12
#define red 11
#define orange 10
#define green 9
#define clear 8


void setup()
{
  Serial.begin(9600);
 
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(clear, OUTPUT);
}

void loop()
{
  delay(1);
  illumiPattern1();

  illumiPattern2();

  illumiPattern3();

  illumiPattern4();

  illumiPattern5();

  illumiPattern6();

}

// different Flashlight pattern 1-6
void illumiPattern1()
{
  static uint8_t stateP1 = 0;
  static uint16_t counterP1 = 0;
  static int count3 = 3;
  static int count = 0;
  switch(stateP1)
  {
    case state0:
    {
      counterP1 = 0;
      stateP1 ++;
      break;
    }

    case state1:
    {
      counterP1 ++;
      if(counterP1 >= 100)
      {
        counterP1 = 0;
        stateP1 ++;
      }
      break;
    }

    case state2:
    {
      digitalWrite(yellow, HIGH);
      counterP1 = 0;
      stateP1 ++;
      break;
    }

    case state3:
    {
      counterP1 ++;
      if(counterP1 >= 100)
      {
        counterP1 = 0;
        stateP1 ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(yellow, LOW);

      stateP1 = 1;
      count ++;
      break;
      
    }
  }
  //Serial.println(count);
  if (count == count3 && counterP1 == 50)
  {
    stateP1 = 1;
    counterP1 = 0;
    count = 0;
  }
}

void illumiPattern2()
{
  static uint8_t stateP2 = 0;
  static uint16_t counterP2 = 0;
  switch(stateP2)
  {
    case state0:
    {
      counterP2 = 0;
      stateP2 ++;
      break;
    }

    case state1:
    {
      counterP2 ++;
      if(counterP2 >= 200)
      {
        counterP2 = 0;
        stateP2 ++;
      }
      break;
    }

    case state2:
    {
      digitalWrite(blue, HIGH);
      counterP2 = 0;
      stateP2 ++;
      break;
    }

    case state3:
    {
      counterP2 ++;
      if(counterP2 >= 200)
      {
        counterP2 = 0;
        stateP2 ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(blue, LOW);
      stateP2 = 1;
      break;
    }
  }
}

void illumiPattern3()
{
  static uint8_t stateP3 = 0;
  static uint16_t counterP3 = 0;
  switch(stateP3)
  {
    case state0:
    {
      counterP3 = 0;
      stateP3 ++;
      break;
    }

    case state1:
    {
      counterP3 ++;
      if(counterP3 >= 300)
      {
        counterP3 = 0;
        stateP3 ++;
      }
      break;
    }

    case state2:
    {
      digitalWrite(red, HIGH);
      counterP3 = 0;
      stateP3 ++;
      break;
    }

    case state3:
    {
      counterP3 ++;
      if(counterP3 >= 300)
      {
        counterP3 = 0;
        stateP3 ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(red, LOW);
      stateP3 = 1;
      break;
    }
  }
}


void illumiPattern4()
{
  static uint8_t stateP4 = 0;
  static uint16_t counterP4 = 0;
  switch(stateP4)
  {
    case state0:
    {
      counterP4 = 0;
      stateP4 ++;
      break;
    }

    case state1:
    {
      counterP4 ++;
      if(counterP4 >= 400)
      {
        counterP4 = 0;
        stateP4 ++;
      }
      break;
    }

    case state2:
    {
      digitalWrite(orange, HIGH);
      counterP4 = 0;
      stateP4 ++;
      break;
    }

    case state3:
    {
      counterP4 ++;
      if(counterP4 >= 400)
      {
        counterP4 = 0;
        stateP4 ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(orange, LOW);

      stateP4 = 1;
      break;
    }
  }
}

void illumiPattern5()
{
  static uint8_t stateP5 = 0;
  static uint16_t counterP5 = 0;
  switch(stateP5)
  {
    case state0:
    {
      counterP5 = 0;
      stateP5 ++;
      break;
    }

    case state1:
    {
      counterP5 ++;
      if(counterP5 >= 500)
      {
        counterP5 = 0;
        stateP5 ++;
      }
      break;
    }

    case state2:
    {
      digitalWrite(green, HIGH);
      counterP5 = 0;
      stateP5 ++;
      break;
    }

    case state3:
    {
      counterP5 ++;
      if(counterP5 >= 500)
      {
        counterP5 = 0;
        stateP5 ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(green, LOW);

      stateP5 = 1;
      break;
    }
  }
}

void illumiPattern6()
{
  static uint8_t stateP6= 0;
  static uint16_t counterP6 = 0;
  switch(stateP6)
  {
    case state0:
    {
      counterP6 = 0;
      stateP6 ++;
      break;
    }

    case state1:
    {
      counterP6 ++;
      if(counterP6 >= 600)
      {
        counterP6 = 0;
        stateP6 ++;
      }
      break;
    }

    case state2:
    {
      digitalWrite(clear, HIGH);
      counterP6 = 0;
      stateP6 ++;
      break;
    }

    case state3:
    {
      counterP6 ++;
      if(counterP6 >= 600)
      {
        counterP6 = 0;
        stateP6 ++;
      }
      break;
    }

    case state4:
    {
      digitalWrite(clear, LOW);

      stateP6 = 1;
      break;
    }
  }
}


