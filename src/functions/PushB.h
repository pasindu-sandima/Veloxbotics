void pushButton(){
    turnLpushB();
    rspeed=300;
    lspeed=300;

    while(true){
        blineFollowing();
        if(n>=8){
            brake();
            break;
        }
    }

    turn180();
    drive(-350,-350);
    Int();
    countright=0;
    while(true){
        if(countright>1250){
            brake();
            break;
        }
    }
    brake();
}