void Maze_Optimize(){
    int DoOptimize=1;
    Len=stackpoint;
    Serial.println(100);
    while (DoOptimize){
        Serial.println(200);
        stackpoint=0;
        stackval=junctions[stackpoint];
        while (true){
            Serial.println(201);
            if(stackval==B){
                break;
            }    
            stackpoint++ ;
            stackval=junctions[stackpoint];
            if (stackpoint==Len){
                  DoOptimize=0;
                   break;
            }
        }
        if (stackval==B){
          Serial.println(202);
          shiftstack=stackpoint+2;
          if ((junctions[stackpoint-1]==L)&&(junctions[stackpoint]==B)&&(junctions[stackpoint+1]==L)){
              junctions[stackpoint-1]=S;
              Serial.println(203);
          }
          else if ((junctions[stackpoint-1]==S)&&(junctions[stackpoint]==B)&&(junctions[stackpoint+1]==S)){
              junctions[stackpoint-1]=B;
              Serial.println(204);

          }
          else if ((junctions[stackpoint-1]==S)&&(junctions[stackpoint]==B)&&(junctions[stackpoint+1]==L)){
              junctions[stackpoint-1]=R;
              Serial.println(205);

          }
          else if ((junctions[stackpoint-1]==R)&&(junctions[stackpoint]==B)&&(junctions[stackpoint+1]==L)){
              junctions[stackpoint-1]=B;
              Serial.println(206);

          }
          else if ((junctions[stackpoint-1]==L)&&(junctions[stackpoint]==B)&&(junctions[stackpoint+1]==S)){
              junctions[stackpoint-1]=R;
              Serial.println(207);

          }
          else if ((junctions[stackpoint-1]==L)&&(junctions[stackpoint]==B)&&(junctions[stackpoint+1]==R)){
              junctions[stackpoint-1]=B;
              Serial.println(208);

          }
          while(shiftstack<=Len){
              
              junctions[shiftstack-2]=junctions[shiftstack];
              shiftstack++;
          }
          Len-=2;
          for (int i=0;i<Len+1;i++){
            Serial.println(junctions[i]);
          }  
        }
        
    }
}


void detectjunction(){
  //sensor readings
  if (digitalRead(SLF)||digitalRead(SRF)){
    is_junction=1;
  }
  else if (n==0){
    is_junction=1; 
  }
  else{
      is_junction=0;
  }
}
void detectFront(){
    n=0;
    if (analogRead(S4)<wr) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
    if (analogRead(S3)<wr) {
            n++;
            lineout=0;            
            sum-=w1;            
    }
    if (analogRead(S6)<wr) {
            n++;
            lineout=0;            
            sum-=w1;            
    }

    if (analogRead(S5)<wr) {
            n++;
            lineout=0;            
            sum+=w1;            
    }
    
}
void junctiontype(){
    RedON();
  //sensor readings
  detectFront();
  if (Ltemp){
      temp=0;
  }
  else if (n>2){
      temp=1;
  }
  else if (Rtemp){
      temp=2;
  }
  else{
      temp=3;
  }
}
void maze_solve(){
    while(true){
        wlineFollowing();
        detectjunction();
        if (is_junction){
            break;
        }
    }
    Ltemp=false;
    Rtemp=false;
    if(digitalRead(SRF)||digitalRead(SLF)){
        if(digitalRead(SRF)){
            Rtemp=true;
        }
        if(digitalRead(SLF)){
            Ltemp=true;
        }
        RedON();
        drive(400,400);
        while(true){
            if(digitalRead(SRF)){
                Rtemp=true;
            }
            if(digitalRead(SLF)){
                Ltemp=true;
            }
            if (digitalRead(SRB) || digitalRead(SLB)){
                junctiontype();
                Int();
                countright=0;
                while(true){
                    if(countright>250){
                        brake();
                        break;
                    }
                }
                break;
            }   
        }
    }
    else{
        temp=3;
        brake();
    }
    RedOFF();
    buzzN(2);
    
    // junctiontype();
    // delay(2000);
    RedOFF();
    OLEDdisplay(String(temp));
    if (temp==0){
        turnL();
        stackpoint+=1;
        stackval=L;
        junctions[stackpoint]=stackval;
    }
    else if (temp==1)
    {
        stackpoint+=1;
        stackval=S;
        junctions[stackpoint]=stackval;
    }
    else if (temp==2)
    {
        turnR();
        stackpoint+=1;
        stackval=R;
        junctions[stackpoint]=stackval;
    }
    else if(temp==3){
        turn180();
        stackpoint+=1;
        stackval=B;
        junctions[stackpoint]=stackval;
    }
}
void maze_exit(){
    //to exit the maze
}

void shortPath(){
    stackpoint=Len;
    while(true){
        while(true){
            wlineFollowing();
            detectjunction();
            if(is_junction){
                break;
            }
        }
        if(stackpoint==-1){
            brake();
            break;
        }  
        if(digitalRead(SRF)||digitalRead(SLF)){
            drive(500,500);
            while(true){
                if (digitalRead(SRB) || digitalRead(SLB))
                {
                    brake();
                    break;
                }   
            }
        }
        if(junctions[stackpoint]==S){
            stackpoint--;
        }
        else if(junctions[stackpoint]==R){
            turnL();
            stackpoint--;
        }
        else{
            turnR();
            stackpoint--;
        }
            
    }
}

void mazeTraverse(){
    int stackcount=0;
    while(true){
        stackcount++;
        maze_solve();
        if(stackcount>7){
            brake();
            break;
        }
    }
    OLEDdisplay(String(junctions[0])+", "+String(junctions[1])+", "+String(junctions[2])+", "+String(junctions[3])+", "+String(junctions[4])+", "+String(junctions[5])+", "+String(junctions[5]));
    while(digitalRead(button1)){}
    buzzN(2);
}