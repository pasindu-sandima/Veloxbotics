#ifndef GLOBAL_SPACE_H
#define GLOBAL_SPACE_H

Adafruit_PWMServoDriver Servo;
uint16_t ServoCurPos[16] {0,0,0,0,0,0,0,0,0,0,0,0,0,170,0,0};
#define MainArm 13
#define ColourArm 12
#define Gripper 7


//motor_controlling
#define rm1 10
#define rm2 9
#define Rpwm 8
#define lm1 13
#define lm2 12
#define Lpwm 11
volatile uint16_t countleft=0, countright=0;
int phasecount=0;
int lspeed=300; int rspeed=300;



//Buttons
#define button1 41
#define button2 43
#define button3 45
#define buzzer 46


//line following
#define SLF 47//single line sensors
#define SLB 49
#define SRF 38
#define SRB 48
#define S1 A7 //leftmost
#define S2 A6
#define S3 A5
#define S4 A4
#define S5 A3
#define S6 A2
#define S7 A1
#define S8 A0 //rightmost


#define SC0 24        //S0
#define SC1 22       //s1
#define SC2 28
#define SC3 30
#define sensorOut 26





#define blueled 37
#define redled 33
#define greenled 35
#define whiteright 39
#define whiteleft 31


//OLED function
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);




//Line Following
int n=0; int sum=0;int lineout=0; float error=0; float last_error=0; float adj=0;
int Kd=115, Kp=15,w1=1, w2=3, w3=8, w4=20, W5=4,w5=2,w6=1; // w5 = error is devided by this and the substracted from rspeed
int wr = 75,br=34;
int Rspeed; int Lspeed;
int dKd=115, dKp=30;


volatile bool leftjunction=false,rightjunction=false;
bool junctionflag =  false;




int Mode=0;
int NModes=9;
String Modes[10] = {"VELOX","Main Arm","Colour Arm","Gripper","4","5","6","7","8","9"};
unsigned long time=0;


#define RedON() digitalWrite(redled,HIGH);
#define GreenON() digitalWrite(greenled,HIGH);
#define BlueON() digitalWrite(blueled,HIGH);
#define RedOFF() digitalWrite(redled,LOW);
#define GreenOFF() digitalWrite(greenled,LOW);
#define BlueOFF() digitalWrite(blueled,LOW);


#define IntMode CHANGE
#define NoInt() detachInterrupt(digitalPinToInterrupt(3)),detachInterrupt(digitalPinToInterrupt(2)),detachInterrupt(digitalPinToInterrupt(18)),detachInterrupt(digitalPinToInterrupt(19));
#define Int() attachInterrupt(digitalPinToInterrupt(3),rightcount,IntMode),attachInterrupt(digitalPinToInterrupt(2),rightcount,IntMode),attachInterrupt(digitalPinToInterrupt(18),leftcount,IntMode),attachInterrupt(digitalPinToInterrupt(19),leftcount,IntMode);

uint16_t r, g, b, c, colorTemp, lux;
uint16_t colours[4][3];
uint16_t Color[4];
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

#endif