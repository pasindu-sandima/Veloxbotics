void start(){
    while(n==8){
        blineFollowing();
    }
    while(true){
        blineFollowing();
        if(not(digitalRead(SRF))){
            brake();
            break;
        }
    }
    turnR();
    while(true){
        blineFollowing();
        if(n==8){
            brake();
            break;
        }
    }
        
}