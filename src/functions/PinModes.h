void pinModes(){
    //motor controlling pins
    pinMode(rm1,OUTPUT);
    pinMode(rm2,OUTPUT);
    pinMode(Rpwm,OUTPUT);
    pinMode(Lpwm,OUTPUT);
    pinMode(lm1,OUTPUT);
    pinMode(lm2,OUTPUT);

    //interrupts
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(18,INPUT_PULLUP);
    pinMode(19,INPUT_PULLUP);


    pinMode(SLF,INPUT);
    pinMode(SLB,INPUT);
    pinMode(SRF,INPUT);
    pinMode(SRB,INPUT);
    
    attachInterrupt(digitalPinToInterrupt(3),rightcount,IntMode); //junction detectors
    attachInterrupt(digitalPinToInterrupt(2),rightcount,IntMode);    //Junction detectors
    
    attachInterrupt(digitalPinToInterrupt(18),leftcount,IntMode);    //Junction detectors
    attachInterrupt(digitalPinToInterrupt(19),leftcount,IntMode);    //Junction detectors
    
    

    //Line Sensors
    pinMode(S1,INPUT);
    pinMode(S2,INPUT);
    pinMode(S3,INPUT);
    pinMode(S4,INPUT);
    pinMode(S5,INPUT);
    pinMode(S6,INPUT);
    pinMode(S7,INPUT);
    pinMode(S8,INPUT);

    //RGB sensor
    pinMode(SC0,OUTPUT);
    pinMode(SC1,OUTPUT);
    pinMode(SC2,OUTPUT);
    pinMode(SC3,OUTPUT);
    pinMode(sensorOut,INPUT);


    //buttons
    pinMode(button1,INPUT_PULLUP);
    pinMode(button2,INPUT_PULLUP);
    pinMode(button3,INPUT_PULLUP);
    pinMode(buzzer,OUTPUT);
    pinMode(whiteleft,OUTPUT);
    pinMode(greenled,OUTPUT);
    pinMode(redled,OUTPUT);
    pinMode(blueled,OUTPUT);
    pinMode(whiteright,OUTPUT);



}