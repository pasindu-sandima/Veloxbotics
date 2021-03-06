#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_TCS34725.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

#include "Global_Space.h"
#include "Function_List.h"

#include "functions\Servos.h"
#include "functions\LineFollowing.h"
#include "functions\Drive.h"
#include "functions\PinModes.h"
#include "functions\OLED.h"
#include "functions\Colour.h"
#include "functions\PushB.h"
#include "functions\LineMaze.h"
#include "functions\Sword.h"
#include "functions\task.h"
#include "functions\Gyro.h"





void setup() {
  // put your setup code here, to run once:
  TCCR1B &= ~(1<<CS11);//to set 7.5kHz f to pin 11
  TCCR1A |= (1<<WGM11); // resolution to 10 bits of pins 10,11
  TCCR4B &= ~(1<<CS41);//to set 7.5kHz f to pin 8
  TCCR4A |= (1<<WGM41); // resolution to 10 bits of pins 6,7,8
  pinModes();
  RedON();
  GreenON();
  BlueON();
  Serial.begin(250000);
  Wire.begin();
  Serial2.begin(115200);
  OLEDsetup();
  colourSetup();
  printVelox();
  servoInit();
  NoInt();
  buzzN(2);
  RedOFF();GreenOFF();BlueOFF();
}

void loop() {
  // put your main code here, to run repeatedly:
  Mode=0;
  while(digitalRead(button2)){
      Serial2.println("abcd");
      if(digitalRead(button3)){}
      else{
          buzzN(2);
          Mode+=1;
          if(Mode>NModes){
            Mode=0;
          }
      }
      if(digitalRead(button1)){
      }
      else{
          buzzN(2);
          Mode-=1;
          if(Mode<0){
            Mode=NModes;
          }
      }
      if(Mode==0){
        printVelox();
      }
      else{
        OLEDdisplay(Modes[Mode]);
      }
  }
  buzzN(5);


  linecount=0;
  while(digitalRead(button2)){
    
      if(Mode==1){
        roundonetask();
        break;
      }
      else if(Mode==2){
        pushb2maze();
        break;

      }
      else if(Mode==3){
        maze2releasesword();
        // pushButton();
        break;
      }
      else if(Mode==4){
          mazeTraverse();
          // turn180();
          while(digitalRead(button1)){}
          buzzN(2);
          Maze_Optimize();
          OLEDdisplay(String(junctions[0])+", "+String(junctions[1])+", "+String(junctions[2])+", "+String(junctions[3])+", "+String(junctions[4])+", "+String(junctions[5])+", "+String(junctions[6])+", "+String(junctions[7])+", "+String(junctions[8])+", "+String(junctions[9]));
          buzzN(2);
          turn180();
          while(digitalRead(button1)){}
          shortPath();
          brake();
          while(digitalRead(button1)){}
          buzzN(2);
          break;
      }
      else if(Mode==5){
          moveServo(MainArm,MainGrip);
          delay(500);
          rspeed=300;
          lspeed=300;
          while(true){
              blineFollowing();
              if(n==8){
                  brake();
                  break;
              }
          }
          drive(-200,-200);
          countright=0;
          Int();
          while(true){
            if(countright>100){
              brake();
              break;
            }
          }
          NoInt();
          brake();
          moveServo(Gripper,GripperGrip);
          delay(1000);
          moveServo(MainArm,MainNormal);
          delay(1000);
          brake();

          turn180();
          break;

      }
      else if(Mode==6){
          Serial.print(analogRead(S1));
          Serial.print(", ");
          Serial.print(analogRead(S2));
          Serial.print(", ");
          Serial.print(analogRead(S3));
          Serial.print(", ");
          Serial.print(analogRead(S4));
          Serial.print(", ");
          Serial.print(analogRead(S5));
          Serial.print(", ");
          Serial.print(analogRead(S6));
          Serial.print(", ");
          Serial.print(analogRead(S7));
          Serial.print(", ");
          Serial.println(analogRead(S8));
      }
      else if(Mode==7){
          dashline();
          break;
      }
      else if(Mode==8){
          pushButton();
          break;
      }
      else if(Mode==9){
        moveServo(Gripper,GripperGrip);
        releaseSwordBox();
        break;

      }
      else{
          break;
      }

  }
  buzzN(5);
  
}