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