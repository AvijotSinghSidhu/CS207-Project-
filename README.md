# IR-Remote Controlled Tic Tac Toe(CS 207 - Project)
![20210414_194931](https://user-images.githubusercontent.com/79728337/114802494-0700a680-9d5b-11eb-83ea-c05ecf62ecd3.jpg)

# Table of Content
**1 - Feature list**

**2 - Requirements and Materials**

**3 - Bilding Instructions**

**4 - Usage**

**5 - Planed Featuers**

**6 - Bug List**

**7 - Credits**

**8 - Thanks**
  
# Feature List


1. It is game controlled by IR Remote which send signal to IR sensor.
2. It is a game played bitween 2 players. player 1 have first turn and player 2 have second turn.
3. It is played in 3x3 grid.
4. It uses green LEDs for player 2 and red LEDs for player 1.
5. The player who suceeds in placing three of thir marks vertical, horizontal, or diagonal row is a winner
6. It can be updated and we can add more featues to the game.

# Requirements and Materials
Dependencies:
1. Arduino.IDE - It can be download from https://www.arduino.cc/en/software
2. IRremote.h Liberary - It can be download from [IRremote-3.0.1.zip](https://github.com/AvijotSinghSidhu/CS207-Project-/files/6314806/IRremote-3.0.1.zip)

Bill of Materials:
1. 1 x Arduino UNO
2. 1 x IR sensor
3. 1 x IR remote
4. 18 x Resistors(220 ohm)
5. 2 x Breadbord
6. 1 x Arduino to USB cable
7. 9 x Red LEDs
8. 9 x Green LEDs
9. wires
 


# Building Instructions
**Library Installing**
1. Open a Arduino software
2. Click on Sketch
3. Click on include Library
4. Click on Add.ZIP Library..
5. Open the ZIP ribrary which is provided in Requirements to download
6. Library is installed

**Building Circuit for IR sensor**

![arduino-wiring-an-ir-phototransistor-electrical-engineering](https://user-images.githubusercontent.com/79728337/114811054-9eb9c100-9d6a-11eb-939f-e52d01f3f9e5.jpg)
1. Connect ground terminal to ground of arduino.
2. Connect Signal wire to A0.
3. Connect 5v to the 5v of the ardiuno
4. IR sensor is ready to use

![Untitled](https://user-images.githubusercontent.com/79728337/114814415-61a4fd00-9d71-11eb-9cad-bc34dd4622b7.png)
**Building Circuit for RED LEDs**

1. we have to arrange LEDs in 3x3 grid
2. I have connected every LED with resistor to ground(Foe example LED1 with R1 to Ground and so on)  
3. I have connected LED1 to PIN2, LED2 to PIN3, LED3 to PIN4, LED4 to PIN5, LED5 to PIN6, LED6 to PIN7, LED7 to PIN8, LED8 to PIN9, LED9 to PIN10.
4. RED LEDS circuit is Competed

**Building Circuit for GREEN LEDs**

1. we have to arrange LEDs in 3x3 grid
2. I have connected every LED with resistor to ground(Foe example LED1 with R1 to Ground and so on)  
3. I have use some analog PIS beacuse i HAVE USED EVERY OTHER PNS.
4. I have connected LED10 to PINA5, LED11 to PINA4, LED12 to PINA3, LED13 to PINA2, LED14 to PINA1, LED15 to PIN11, LED16 to PIN12, LED17 to PIN13.
5. I connected positive of LED18 to 5v and negitive of LED18 to PIN10. (i will handel this in software)
6. GREEN LEDS circuit is Competed

**HOW to Uplode Sketch**
1. I have alreeady given link to downlode softwar in Requirements. you have to downloade it.
2. After oppening the softwere 
3. you have to choose the port in the Tools
4. After that you can uplode you scetch by clicking second button at the to bar.
5. Then you can open a serial MOniter and start palying game with remotre 


# Usage
1. It can be used to play game when you want.
2. It can be used to learn code Arduino UNO and C++.
3. It is a good timepass game as it is portable. 

# Planed Featuers
1. First i will fix all the bugs.
2. I want to add player vs computer feature to it.
3. I want to add computer vs computer feature to it. 
4. I want to reduse number of pin it use on arduino.
5. I want to add reset button to IR Remote.
6. I want to add Colour slecting feature.
7. I improve its physical design.
 

# Bug List
1. Some times IR sensor ditects 0 even if button is not pressed on Remote.
2. Now it is possible to rewrite (For example if RED LED1 is on when player 2 press 1 on remote Green LED10 wuill turn on, but it should not happen )

# Credits
1. I have taken help form this YouTube video https://www.youtube.com/watch?v=Y2HC3bdFoPw to set up IR sensor
2. I have taken help from this website https://www.instructables.com/Intelligent-Arduino-Tic-Tac-Toe-Noughts-and-Crosse/ with my code. But it is completely different think.


# Thanks
1. I would like to thank my class Instructor Trevor Tomesh 
2. I would like to thank my Lab Instructors Alex Clark and Levi Brown









