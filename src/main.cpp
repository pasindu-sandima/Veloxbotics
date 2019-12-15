#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_TCS34725.h>
#include <Wire.h>

#include "Global_Space.h"
#include "Function_List.h"



#include "functions\Servos.h"
#include "functions\LineFollowing.h"
#include "functions\Drive.h"
#include "functions\PinModes.h"
#include "functions\OLED.h"
#include "functions\Colour.h"






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
  Serial.begin(9600);
  Wire.begin();
  Serial2.begin(115200);
  OLEDsetup();
  colourSetup();
  printVelox();
  servoInit();
  // NoInt();
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



  while(digitalRead(button2)){
      if(Mode==1){

        // while(true){
        //   blineFollowing();
        //   if(not(digitalRead(SLF))){
        //     brake();
        //     break;
        //   }
        // }
        // moveServo(MainArm,420);

        // Servo.setPWM(MainArm,0,420);
        while(true){
          blineFollowing();
          if(n==8){
            brake();
            break;
          }
        }

        while(true){
        getColours();

        }
      }
      else if(Mode==2){
          // Servo.setPWM(ColourArm,0,150);
          Servo.setPWM(ColourArm,0,450);

          break;  
      }
      else if(Mode==3){
          // Servo.setPWM(ColourArm,0,300);
          // Servo.setPWM(Gripper,0,120);
          Servo.setPWM(MainArm,0,430);

          break;
      }
      else if(Mode==4){
          dashedlineFollowing();
          if(n==8){
            brake();
            break;
          }
      }
      else if(Mode==5){
          wlineFollowing();
          if(n==0){
            break;
          }
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
          blineFollowing();
          if(not(digitalRead(SRF)&&digitalRead(SLF))){
            brake();
            break;
          }
      }
      else{
          break;
      }

  }
  buzzN(5);
  
}