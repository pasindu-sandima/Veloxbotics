bool detectSword(){
    int value=0;
    for(int i=0;i<11;i++){

        if (digitalRead(metalDetect)){
            value+=1;
        }
        else{
            value-=1;
        }
    }
    if (value>0){
        return false;
    }
    else{
        return true;
    } 
}
void releaseSword(){
    moveServo(MainArm,MainGrip2);
    delay(1000);
    moveServo(Gripper,GripperNormal);
}

void grabSword(){
    moveServo(MainArm,MainGrip);
    delay(1000);
    moveServo(Gripper,GripperGrip);
    delay(1000);
    moveServo(MainArm,MainNormal);

}

void releaseSwordBox(){
    rspeed=300;
    lspeed=300;
    while(true){
        blineFollowing();
        if(n==0){
            brake();
            break;
        }
    }
    releaseSword();
}
