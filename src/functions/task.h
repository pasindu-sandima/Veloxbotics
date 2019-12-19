void start(){
    while(true){
        digitalWrite(buzzer,HIGH);
        blineFollowing();
        if(n!=8){
            digitalWrite(buzzer,LOW);
            break;
        }
    }
    while(true){
        digitalWrite(buzzer,HIGH);
        blineFollowing();
        if(digitalRead(SRF)){
            digitalWrite(buzzer,LOW);
            break;
        }
    }
    while(true){
        GreenON();
        blineFollowing();
        if(not(digitalRead(SRF))){
            GreenOFF();
            break;
        }
    }
    while(true){
        BlueON();
        drive(400,400);
        if(not(digitalRead(SRB))){
            BlueOFF();
            break;
        }
    }
    while (true){
        drive(400,400);
        Int();
        RedON();
        if(countright>350){
            RedOFF();
            NoInt();
            break;
        }
    }
    turnR();
    buzzN(2);
    moveServo(MainArm,MainDown);
    int c = 0;
    while(true){
        blineFollowing();
        if(n==8){
            c++;
            if(c==5){
               brake();
                break; 
            }
            
        }
    }
    getColourFront();
    buzzN(2);
    // moveServo(MainArm,MainNormal);
    GreenOFF();BlueOFF();RedOFF();
    drive(-400,-400);
    while(true){
        if(not(digitalRead(SRB)&&digitalRead(SRB))){
            brake();
            break;
        }
    }
    drive(300,300);
    Int();
    countright=0;
    while (true){
        RedON();
        if(countright>250){
            RedOFF();
            NoInt();
            brake();
            break;
        }
    }
    turnL();
    buzzN(2);
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRB)&&digitalRead(SLB))){
            break;
        }
    }
    while(true){
        blineFollowing();
        if(n==8){
            brake();
            break;
        }
    }
    moveServo(ColourArm,ColourClose);
    buzzN(2);
    getColours();
}



void start2box(){
    Int();
    countright=0;
    rspeed=300;
    lspeed=rspeed;
    RedON();
    while(true){
        blineFollowing();
        rspeed=300+countright/24;
        lspeed=rspeed;
        if(countright>1200){
            break;
        }
    }
    BlueON();RedOFF();
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SRB))){
            drive(500,500);
            break;
        }
    }
    GreenON();BlueOFF();
    correctPos();
    GreenOFF();
    turnR();
    moveServo(MainArm,MainDown);
    rspeed=300;
    lspeed=rspeed;
    int c=0;
    while(true){
        blineFollowing();
        if(n==8){
            c++;
            if(c==1){
                brake();
                break;
            }
        }
    }
    getColourFront();
    buzzN(2);
    GreenOFF();BlueOFF();RedOFF();

    drive(-350,-340);
    while(true){
        if(not(digitalRead(SRB)&&digitalRead(SRB))){
            brake();
            break;
        }
    }
    drive(300,300);
    Int();
    countright=0;
    while (true){
        RedON();
        if(countright>250){
            RedOFF();
            NoInt();
            brake();
            break;
        }
    }
    turnL();
    buzzN(2);
    Int();
    countright=0;
    rspeed=300;
    lspeed=rspeed;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            NoInt();
            break;
        }
        if(rspeed<500){
            rspeed=300+countright/4;
            lspeed=rspeed;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB)&&digitalRead(SRB))){
            break;
        }
    }
    rspeed=500;
    lspeed=rspeed;
    c=0;
    countright=0;
    while(true){
        blineFollowing();
        if(n==8){
            c++;
            if(c==1){
                brake();
                break;
            }
        }
        if(rspeed>350){
            rspeed=500-countright/5;
            lspeed=rspeed;
        }
    }
    moveServo(ColourArm,ColourClose);
    buzzN(2);
    getColours();
    moveServo(ColourArm,ColourOpen);
    moveServo(MainArm,MainNormal);
    moveServo(ColourArm,ColourClose);
    turn180();
}

void box2indication(){
    rspeed=400;
    lspeed=400;
    countright=0;
    Int();
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            NoInt();
            break;
        }
        if(rspeed<500){
            rspeed=300+countright/5;
            rspeed=lspeed;
        }
    }
    correctPos();
    turnR();
    drive(-350,-340);
    countright=0;
    Int();
    while(true){
        if(countright>1000){
            break;
        }
    }
    while(true){
        if(not(digitalRead(SRB)&&digitalRead(SLB))){
            break;
        }
    }
    countright=0;
    while(true){
        if(countright>200){
            NoInt();
            break;
        }
    }
    brake();
    if(ColourOne==0) {RedON();}
    else if(ColourOne==1) {GreenON();}
    else{BlueON();}
    for(int i=0;i<4;i++){
        if(Color[i]==ColourOne){
            ColourSum++;
        }
    }
    OLEDdisplay(String(ColourSum));
    while(digitalRead(button1)){}
    buzzN(2);
}

void indi2dash(){
    
    rspeed=300;
    lspeed=300;
    countright=0;
    Int();
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
        if(rspeed<500){
            rspeed=300+countright/5;
            lspeed=rspeed;
        }
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRB)&&digitalRead(SLB))){
            NoInt();
            break;
        }
        if(rspeed<500){
            rspeed=300+countright/5;
            lspeed=rspeed;
        }
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SRB)&&digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnR();
    rspeed=300;
    lspeed=rspeed;
    countright=0;
    Int();
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
        if(rspeed<500){
            rspeed=300+countright/5;
            lspeed=rspeed;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SRB)&&digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();


}


void dashline(){
    rspeed=300;
    lspeed=300;
    while(true){
        dashedlineFollowing();
        if(n==8){
            // brake();
            break;
        }
    }
    correctPos2();
    brake();
}

void maze2sword(){
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();



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
    brake();
    moveServo(Gripper,GripperGrip);
    delay(1000);
    moveServo(MainArm,MainNormal);
    delay(1000);
    brake();

    turn180();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    correctPos();
    turnR();//
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    correctPos();
    turnR();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    correctPos();




}



void maze2sword2(){
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();



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
    brake();
    moveServo(Gripper,GripperGrip);
    if(detectSword()){
        moveServo(MainArm,MainNormal);
        delay(1000);
        turn180();
        rspeed=500;
        lspeed=500;
        while(true){
            blineFollowing();
            if(not(digitalRead(SRF)&&digitalRead(SLF))){
                break;
            }
        }
        correctPos();
        turnR();
    }
    else{
        moveServo(Gripper,GripperNormal);
        moveServo(MainArm,MainNormal);
        turn180();
        rspeed=500;
        lspeed=500;
        while(true){
            blineFollowing();
            if(not(digitalRead(SRF)&&digitalRead(SLF))){
                break;
            }
        }
        correctPos();
        turnL();
        rspeed=500;
        lspeed=500;
        while(true){
            blineFollowing();
            if(not(digitalRead(SRF)&&digitalRead(SLF))){
                break;
            }
        }
        correctPos();
        turnL();
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
        brake();
        moveServo(Gripper,GripperGrip);
        if(detectSword()){
            moveServo(MainArm,MainNormal);
            delay(1000);
            turn180();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
            turnR();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
        }
        else
        {
            moveServo(Gripper,GripperNormal);
            moveServo(MainArm,MainNormal);
            turn180();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
            turnL();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
            turnL();
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
            brake();
            moveServo(Gripper,GripperGrip);
            moveServo(MainArm,MainNormal);
            delay(1000);
            turn180();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
            turnR();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
            rspeed=500;
            lspeed=500;
            while(true){
                blineFollowing();
                if(not(digitalRead(SRF)&&digitalRead(SLF))){
                    break;
                }
            }
            correctPos();
        }   
    }
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    correctPos();
    turnR();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
            break;
        }
    }
    correctPos();
}


void pushb2maze(){
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF))){
            break;
        }
    }
    drive(500,500);
    Int();
    countright=0;
    while(true){
        if(countright>700){
            break;
        }
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF))){
            break;
        }
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRB))){
            break;
        }
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SRB))){
            break;
        }
    }
    correctPos();
    turnR();
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF)&&digitalRead(SLF))){
        break;
        }
    }
    correctPos();
}

void maze2releasesword(){
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SLF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SLB))){
            break;
        }
    }
    correctPos();
    turnL();
    rspeed=500;
    lspeed=500;
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF))){
            break;
        }
    }
    drive(500,500);
    while(true){
        if(not(digitalRead(SRB))){
            break;
        }
    }
    correctPos();
    
    if(ColourSum==2){
        turnR();
        rspeed=500;
        lspeed=500;
        while(true){
            blineFollowing();
            if(not(digitalRead(SLF))){
                break;
            }
        }
        drive(500,500);
        while(true){
            if(not(digitalRead(SLB))){
                break;
            }
        }
        correctPos();
        turnL();
        releaseSwordBox();
    }
    else if(ColourSum==3){
        turnR();
        rspeed=500;
        lspeed=500;
        while(true){
            blineFollowing();
            if(not(digitalRead(SLF))){
                break;
            }
        }
        drive(500,500);
        while(true){
            if(not(digitalRead(SLB))){
                break;
            }
        }
        correctPos();
        rspeed=500;
        lspeed=500;
        while(true){
            blineFollowing();
            if(not(digitalRead(SLF))){
                break;
            }
        }
        drive(500,500);
        while(true){
            if(not(digitalRead(SLB))){
                break;
            }
        }
        correctPos();
        turnL();
        releaseSwordBox();
    }
    else{
        releaseSwordBox();
    }
}



