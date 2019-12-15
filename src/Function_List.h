void pinModes();



void moveServo(uint16_t Servo_Num,uint16_t angle,uint16_t dtime);
void servoInit();



void blineFollowing();
void wlineFollowing();
void dashedlineFollowing();
void reverselineFollowing();


void rightcount();
void leftcount();
void driveForward();
void brake();
void drive(int Lspeed1,int Rspeed1);
void turnR();
void turnL();
void turnRight();
void turnLeft();


void OLEDsetup();
void OLEDprint(int value);
void OLEDdisplay(String text);
void printVelox();
void buzz();
void buzzN(uint16_t n);

void colourSetup();
void getColours();
void getColourFront();











