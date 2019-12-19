void rightcount(){
    countright++;
}
void leftcount(){
    countleft++;
}
void brake(){
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,HIGH);
    digitalWrite(Rpwm,HIGH);
    digitalWrite(Lpwm,HIGH);
}
void drive(int Lspeed1,int Rspeed1){
    if(Rspeed1>0){
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
    }
    else{
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,HIGH);
        Rspeed1=-Rspeed1;
    }
    if(Lspeed1>0){
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
    }
    else{
        digitalWrite(lm1,LOW);
        digitalWrite(lm2,HIGH);
        Lspeed1=-Lspeed1;
    }
    analogWrite(Lpwm,Lspeed1);
    analogWrite(Rpwm,Rspeed1);
}
void driveForward(){
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Lpwm,lspeedF);
    analogWrite(Rpwm,rspeedF);
}

void turnR(){
    brake();
    buzzN(2);
    countright=0;
    countleft=0;
    Int();
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    uint16_t speed;
    while(countleft<400){
        speed=300+countleft;
        analogWrite(Lpwm,speed);
        analogWrite(Rpwm,speed);
    }
    while(countleft<900){
        speed=700;
        analogWrite(Lpwm,speed);
        analogWrite(Rpwm,speed);
    }
    while(countleft<1130){
        speed=1600-countleft;
        analogWrite(Lpwm,speed);
        analogWrite(Rpwm,speed);
    }
    brake();
    buzzN(2);
    NoInt();
}

void turnL(){
    brake();
    buzzN(2);
    countright=0;
    countleft=0;
    Int();
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    uint16_t speed;
    while(countright<400){
        speed=300+countright;
        analogWrite(Lpwm,speed);
        analogWrite(Rpwm,speed);
    }
    while(countright<900){
        speed=700;
        analogWrite(Lpwm,speed);
        analogWrite(Rpwm,speed);
    }
    while(countright<1150){
        speed=1600-countright;
        analogWrite(Lpwm,speed);
        analogWrite(Rpwm,speed);
    }
    brake();
    buzzN(2);
    NoInt();
}

void turnLpushB(){
    brake();
    buzzN(2);
    countright=0;
    countleft=0;
    Int();
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Lpwm,400);
    analogWrite(Rpwm,400);
    while(true){
        if((analogRead(S3)>br)&&(analogRead(S4>br))){
            brake();
            break;
        }
    }
    buzzN(2);
    NoInt();
}

void turn180(){
    brake();
    delay(200);
    phasecount=0;
    countright=0;
    Int();
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,505);
    analogWrite(Lpwm,505);
    while(phasecount<57){
        countright=0;
        while(countright<49){}
        phasecount++;
    }
    brake();
    buzzN(2);
    NoInt();
}

void TurnLeft(){
    brake();
    delay(200);
    //delay(1300);//time calculation
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<25){
        countright=0;
        while(countright<51){}
        phasecount++;
    }  
    brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(3));
    detachInterrupt(digitalPinToInterrupt(2));
}
void TurnRight(){
    brake();
    delay(200);//time calculation
    phasecount=0;
    countleft=0;
    Int();
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<25){
        countleft=0;
        while(countleft<52){}
        phasecount++;
    }
    brake();
    leftjunction=false;
    rightjunction=false;
    NoInt();
}

void correctPos(){
    Int();
    countright=0;
    while(true){
        if(not(digitalRead(SRB)==HIGH&&(digitalRead(SLB)==HIGH))){
            break;
        }
        if(rspeed>150){
            rspeed=500-countright;
            lspeed=rspeed;
            drive(lspeed,rspeed);
        }        
    }
    countright=0;
    while (true){
        if(countright>200){
            break;
        }
    }
    brake();
    NoInt();
}

void correctPos2(){
    rspeed=300;
    lspeed=300;
    Int();
    countright=0;
    while(true){
        if(not(digitalRead(SRB)==HIGH&&(digitalRead(SLB)==HIGH))){
            break;
        }
        if(rspeed>150){
            rspeed=300-countright;
            lspeed=rspeed;
            drive(lspeed,rspeed);
        }        
    }
    countright=0;
    while (true){
        if(countright>300){
            break;
        }
    }
    brake();
    NoInt();
}
