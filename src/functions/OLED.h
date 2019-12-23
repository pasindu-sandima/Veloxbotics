void OLEDsetup(){
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void OLEDdisplay(String text){
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(4, 4);
    display.println(text);
    display.display(); // Show initial text
    //delay(100);
}

void OLEDdisplaySum(String text){
    display.clearDisplay();
    display.setTextSize(4); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(4, 4);
    display.println(text);
    display.display(); // Show initial text
    //delay(100);
}

void OLEDprint(int value){
  String text= String(value);
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(2, 2);
  display.println(text);
  display.display();
}
void printVelox(){
  display.clearDisplay();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print("VELOX"); 
  display.display();

}


void buzz(){
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
}

void buzzN(uint16_t n){
  for(uint16_t i=0;i<n;++i){
    buzz();
    delay(30);
  }
}




