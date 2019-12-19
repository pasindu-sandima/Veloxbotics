void pushButton(){
    turnL();

    while(true){
        blineFollowing();
        if (n>=8){
            brake();
            break;
        }
    }

    turn180();
    countReverse(2000);
    blineFollowing();
    delay(3000);
    brake();
}