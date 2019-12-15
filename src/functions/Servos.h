void servoInit(){
  Servo.begin();
  Servo.setPWMFreq(60);
}

void moveServo(uint16_t Servo_Num,uint16_t angle,uint16_t dtime=5){
  uint16_t curpos = ServoCurPos[Servo_Num];
  ServoCurPos[Servo_Num] = angle;
  if(angle>curpos){
    for (uint16_t pos = curpos; pos <= angle; pos += 1){
      Servo.setPWM(Servo_Num,0,pos);
      delay(dtime);
    }
  }
  else{
    for (uint16_t pos = curpos; pos >= angle; pos -= 1){
      Servo.setPWM(Servo_Num,0,pos);
      delay(dtime);
    }
  }
}



