void colourSetup(){
    digitalWrite(SC0,LOW);
    digitalWrite(SC1,LOW);
    delay(50);
    if (tcs.begin()) {
        Serial.println("Found sensor");
        OLEDdisplay("Found CS1");
    } 
    else {
        Serial.println("No TCS34725 found ... check your connections");
        OLEDdisplay("Not Found CS1");
        while (1);
    }
    //Settings for Calibration of CS1
    digitalWrite(SC1,HIGH);
    delay(50);
    if (tcs.begin()) {
        Serial.println("Found sensor");
        OLEDdisplay("Found CS2");
    } 
    else {
        Serial.println("No TCS34725 found ... check your connections");
        OLEDdisplay("Not Found CS2");
        while (1);
    }
    //Setting for CS2
    digitalWrite(SC0,HIGH);
    delay(50);
    if (tcs.begin()) {
        Serial.println("Found sensor");
        OLEDdisplay("Found CS3");
    } 
    else {
        Serial.println("No TCS34725 found ... check your connections");
        OLEDdisplay("Not Found CS3");
        while (1);
    }
    //Settings
    digitalWrite(SC1,LOW);
    delay(50);
    if (tcs.begin()) {
        Serial.println("Found sensor");
        OLEDdisplay("Found CS4");
    } 
    else {
        Serial.println("No TCS34725 found ... check your connections");
        OLEDdisplay("Not Found CS4");
        while (1);
    }
    //Settings
}


void getColours(){

    //Front Colour HIGH HIGH
    //Left Colour HIGH LOW
    //Back COlour LOW LOW
    digitalWrite(SC0,HIGH);
    digitalWrite(SC1,LOW);
    delay(100);
    tcs.getRawData(&r, &g, &b, &c);
    colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
    lux = tcs.calculateLux(r, g, b);
    colours[0][0]=r,colours[0][1]=g,colours[0][2]=b;
    OLEDdisplay(String(r)+", "+String(g)+", "+String(b));

    digitalWrite(SC0,LOW);
    digitalWrite(SC1,LOW);
    delay(100);
    tcs.getRawData(&r, &g, &b, &c);
    colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
    lux = tcs.calculateLux(r, g, b);
    colours[1][0]=r,colours[1][1]=g,colours[1][2]=b;
    OLEDdisplay(String(r)+", "+String(g)+", "+String(b));


    digitalWrite(SC0,LOW);
    digitalWrite(SC1,HIGH);
    delay(100);
    tcs.getRawData(&r, &g, &b, &c);
    colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
    lux = tcs.calculateLux(r, g, b);
    colours[2][0]=r,colours[2][1]=g,colours[2][2]=b;
    OLEDdisplay(String(r)+", "+String(g)+", "+String(b));

    digitalWrite(SC0,HIGH);
    digitalWrite(SC1,HIGH);
    delay(100);
    tcs.getRawData(&r, &g, &b, &c);
    colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
    lux = tcs.calculateLux(r, g, b);
    colours[3][0]=r,colours[3][1]=g,colours[3][2]=b;
    OLEDdisplay(String(r)+", "+String(g)+", "+String(b));

    for(int i=0;i<4;i++){
        r=colours[i][0],g=colours[i][1],b=colours[i][2];
        if((r>g)&&(r>b)) Color[i]=0;
        else if((g>r)&&(g>b)) Color[i]=1;
        else Color[i]=2;
    }

    OLEDdisplay(String(Color[0])+", "+String(Color[1])+", "+String(Color[2])+", "+String(Color[3]));





    // Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
    // Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
    // Serial.print("B: "); Serial.print(b, DEC); Serial.println(" ");


}