/**********************************************************************************************
  Tic-Tac-Toe

  Writen by Avijot Singh Sidhu for CS207
**********************************************************************************************/
/******************************* IR Library to use IR Remote *********************************/
#include <IRremote.h>


/******************** Defined LEDs to Store HEX Values from IR Remote  ***********************/
#define LED1 0xF30CFF00  //When 1 is Preesed on Remote
#define LED2 0xE718FF00  //When 2 is Rreesed on Remote
#define LED3 0xA15EFF00  //When 3 is Rreesed on Remote
#define LED4 0xF708FF00  //When 4 is Rreesed on Remote
#define LED5 0xE31CFF00  //When 5 is Rreesed on Remote
#define LED6 0xA55AFF00  //When 6 is Rreesed on Remote
#define LED7 0xBD42FF00  //When 7 is Rreesed on Remote
#define LED8 0xAD52FF00  //When 8 is Rreesed on Remote
#define LED9 0xB54AFF00  //When 9 is Rreesed on Remote

#define ZERO 0  //this it to handel error. some time IR showes 0 without pressing any button


/************************************** IR Variabels ******************************************/
int IRpin = A0;
IRrecv IR (IRpin);


/**************************************** Variabels *******************************************/
int player = 1; // to hold player(program will strart from player 1)
int a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // array to store 'x' and 'o' while playing
int winner = 0; // to check winner
int num;
int count; // to count turns

/**************************************** void setup *******************************************/
void setup ()
{

  Serial.begin(115200); // For serial Moniter
  IR.enableIRIn(); // to enable IR sensor
  pinMode(A0, INPUT); // IR pin

  /******************************* Seting LED Pins to OUTPUT  **********************************/
  pinMode(2, OUTPUT); // FOR LED1 RED
  pinMode(3, OUTPUT); // FOR LED2 RED
  pinMode(4, OUTPUT); // FOR LED3 RED
  pinMode(5, OUTPUT); // FOR LED4 RED
  pinMode(6, OUTPUT); // FOR LED5 RED
  pinMode(7, OUTPUT); // FOR LED6 RED
  pinMode(8, OUTPUT); // FOR LED7 RED
  pinMode(9, OUTPUT); // FOR LED8 RED
  pinMode(10, OUTPUT);// FOR LED9 RED
  pinMode(A5, OUTPUT); // FOR LED1 GREEN
  pinMode(A4, OUTPUT); // FOR LED2 GREEN
  pinMode(A3, OUTPUT); // FOR LED3 GREEN 
  pinMode(A2, OUTPUT); // FOR LED4 GREEN
  pinMode(A1, OUTPUT); // FOR LED5 GREEN
  pinMode(11, OUTPUT); // FOR LED6 GREEN
  pinMode(12, OUTPUT); // FOR LED7 GREEN
  pinMode(13, OUTPUT); // FOR LED8 GREEN
  
}


/**************************** void loop (repeat again and again) ******************************/
void loop ()
{

  /******************************** Condition for Player 1 **********************************/
  if (IRrr() && player == 1)
  {

    digitalWrite(convert(), HIGH);
    num = convert() - 2;
    a[num] = 'X';
    Serial.print("Player : ");
    Serial.print('X');
    Serial.println("  ");
    winner = check(a, num);
    if (convert() == 12 || convert() == 0)
    {
      player == 0;
    }
    if (winner == 1)
    {
      Serial.println("Player 1 Wins!");
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);

     // to make 'X' with LEDS
      while (1)
      {
        
        digitalWrite(2,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(8,HIGH);

      }
    }
    count++;
    player++;

  }


  /******************************** Condition for Player 2 **********************************/
  if (IRrr() &&  player == 2)
  {

    digitalWrite(con(), HIGH);
    num = co(con());
    a[num] = 'O';
    Serial.print("Player : ");
    Serial.print('O');
    Serial.println("  ");
    winner = check(a, num);
    if (convert() == 12 || convert() == 0)
    {
      player == 3;
      count--;
    }
    if (winner == 2)
    {
      Serial.println("Player 2 Wins!");
        digitalWrite(A5,LOW);
        digitalWrite(A4,LOW);
        digitalWrite(A3,LOW);
        digitalWrite(A2,LOW);
        digitalWrite(A1,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,HIGH);

      // to make 'O' with LEDS
      while (1)
      {

        digitalWrite(A5,HIGH);
        digitalWrite(A4,HIGH);
        digitalWrite(A3,HIGH);
        digitalWrite(A2,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(10,LOW);

      }
    }
    count++;
    player--;

  }

  
  /******************************** Condition for Draw **********************************/
  if (count == 8)
  {

    Serial.println("Game Draw");
           // set all to low
         digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(A5,LOW);
        digitalWrite(A4,LOW);
        digitalWrite(A3,LOW);
        digitalWrite(A2,LOW);
        digitalWrite(A1,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
  

  }

}


/******************** Function to Convert Defined LEDs to LED Pins *********************/
/************************* Values are Defined at top of program **************************/
/************************************ FOR RED LEDS *******************************************/
int convert()
{

  switch (IR.decodedIRData.decodedRawData)
  {
    case LED1: return 2; break;
    case LED2: return 3; break;
    case LED3: return 4; break;
    case LED4: return 5; break;
    case LED5: return 6; break;
    case LED6: return 7; break;
    case LED7: return 8; break;
    case LED8: return 9; break;
    case LED9: return 10; break;
    case ZERO: return 0; break;
    default : return 12; break;
  }

}

/******************** Function to Convert Defined LEDs to LED Pins *********************/
/************************* Values are Defined at top of program **************************/
/************************************ FOR GREEN LEDS *******************************************/
int con()
{

  switch (IR.decodedIRData.decodedRawData)
  {
    case LED1: return A5; break;
    case LED2: return A4; break;
    case LED3: return A3; break;
    case LED4: return A2; break;
    case LED5: return A1; break;
    case LED6: return 11; break;
    case LED7: return 12; break;
    case LED8: return 13; break;
    case LED9: return 10; break;
    case ZERO: return 0; break;
    default : return 12; break;
  }

}

// to convert avobe values to store in array
int co(char a)
{

  switch (a)
  {
    case A5: return 1; break;
    case A4: return 2; break;
    case A3: return 3; break;
    case A2: return 4; break;
    case A1: return 5; break;
    case 11: return 6; break;
    case 12: return 7; break;
    case 13: return 8; break;
    case 10: return 9; break;
  }

}

 /************************************** IR function**************************************************/
int IRrr()
{
  while (IR.decode() == 0)
  {

  }
  Serial.print("HEX val : ");
  Serial.print(IR.decodedIRData.decodedRawData, HEX);
  Serial.print("  ");
  delay(1000);
  IR.resume();

}

/******************************* Function to Check winner *********************************/
int check(int a[9], int n)
{

  if (a[0] == 'X' && a[1] == 'X' && a[2] == 'X')
    return 1;
  if (a[0] == 'O' && a[1] == 'O' && a[2] == 'O')
    return 2;
  if (a[0] == 'X' && a[4] == 'X' && a[8] == 'X')
    return 1;
  if (a[0] == 'O' && a[4] == 'O' && a[8] == 'O')
    return 2;
  if (a[0] == 'X' && a[3] == 'X' && a[6] == 'X')
    return 1;
  if (a[0] == 'O' && a[3] == 'O' && a[6] == 'O')
    return 2;
  if (a[1] == 'X' && a[4] == 'X' && a[7] == 'X')
    return 1;
  if (a[1] == 'O' && a[4] == 'O' && a[7] == 'O')
    return 2;
  if (a[2] == 'X' && a[5] == 'X' && a[8] == 'X')
    return 1;
  if (a[2] == 'O' && a[5] == 'O' && a[8] == 'O')
    return 2;
  if (a[2] == 'X' && a[4] == 'X' && a[6] == 'X')
    return 1;
  if (a[2] == 'O' && a[4] == 'O' && a[6] == 'O')
    return 2;
  if (a[3] == 'X' && a[4] == 'X' && a[5] == 'X')
    return 1;
  if (a[3] == 'O' && a[4] == 'O' && a[5] == 'O')
    return 2;
  if (a[6] == 'X' && a[7] == 'X' && a[8] == 'X')
    return 1;
  if (a[6] == 'O' && a[7] == 'O' && a[8] == 'O')
    return 2;

}

