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
    moveServo(MainArm,MainDown);
    delay(1000);
    moveServo(Gripper,GripperNormal);
}