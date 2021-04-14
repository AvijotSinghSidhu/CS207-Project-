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
#define ZERO 0  


/************************************** IR Variabels ******************************************/
int IRpin = 13;
IRrecv IR (IRpin);


/**************************************** Variabels *******************************************/
int player = 1;
int a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int winner = 0;
int num;
int count;
int key;


/**************************************** void setup *******************************************/
void setup ()
{

  Serial.begin(115200);
  IR.enableIRIn();

  /******************************* Seting LED Pins to OUTPUT  **********************************/
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}


/**************************** void loop (repeat again and again) ******************************/
void loop ()
{
  /************************************** IR **************************************************/



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

      while (1)
      {

        digitalWrite(2,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(8,HIGH);

      }
    }
    player++;

  }


  /******************************** Condition for Player 2 **********************************/
  if (IRrr() &&  player == 2)
  {

    digitalWrite( convert(), LOW);
    num = convert() - 2;
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

      while (1)
      {

        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);

      }
    }
    count++;
    player--;

  }

  /******************************** Condition for Draw **********************************/
  if (count == 8)
  {

    Serial.println("Game Draw");

        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);

  }


}


/******************** Function to Convert Defined LEDs to LED Pins *********************/
/************************* Values are Defined at top of program **************************/
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

int IRrr()
{
  while (IR.decode() == 0)
  {

  }
  Serial.print("HEX val : ");
  Serial.print(IR.decodedIRData.decodedRawData, HEX);
  Serial.print("  ");
  delay(50);
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

