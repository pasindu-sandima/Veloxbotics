void blineFollowing(){
      n=0,sum=0,Rspeed=rspeed,Lspeed=lspeed;

      if (analogRead(S1)>br) {
            n++;
            sum-=w4;
            lineout=-1;            
      }
      if (analogRead(S2)>br) {
            n++;
            sum-=w3;   
            lineout=-1;            
      }
      if (analogRead(S3)>br) {
            n++;
            sum-=w2;   
            lineout=-1;            
      }
      if (analogRead(S6)>br) {
            n++;
            lineout=1;            
            sum+=w2;            
      }
      if (analogRead(S7)>br) {
            n++;
            lineout=1;            
            sum+=w3;            
      }
      if (analogRead(S8)>br) {
            n++;
            lineout=1;            
            sum+=w4;            
      }
      if (analogRead(S4)>br) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
      if (analogRead(S5)>br) {
            n++;
            lineout=0;            
            sum+=w1;            
      }
      if(n!=0){
            digitalWrite(rm1, HIGH);
            digitalWrite(rm2,LOW);
            digitalWrite(lm1, HIGH);
            digitalWrite(lm2,LOW);
            error = sum/n;
            adj = bKp*error + bKd*(error-last_error);
            last_error = error;
            if (adj>0) {      
                  Lspeed += adj/w6;
                  Rspeed -= adj/w5;
            }
            else{
                  Rspeed -= adj/w6;
                  Lspeed += adj/w5;
            }
            if (Rspeed>900){
                  Rspeed = 900;
            }
            if (Lspeed>900){
                  Lspeed = 900;
            }
            if (Rspeed<0){
                  digitalWrite(rm2,HIGH);
                  digitalWrite(rm1,LOW);
                  Rspeed = - Rspeed;
            }
            if (Lspeed<0){
                  digitalWrite(lm2,HIGH);
                  digitalWrite(lm1,LOW);
                  Lspeed = - Lspeed;
            }
            analogWrite(Rpwm, Rspeed);
            analogWrite(Lpwm, Lspeed);
      }
      else{
            brake();
      }
}


void wlineFollowing(){
      n=0,sum=0,Rspeed=rspeed,Lspeed=lspeed;

      if (analogRead(S1)<wr) {
            n++;
            sum-=w4;
            lineout=-1;            
      }
      if (analogRead(S2)<wr) {
            n++;
            sum-=w3;   
            lineout=-1;            
      }
      if (analogRead(S3)<wr) {
            n++;
            sum-=w2;   
            lineout=-1;            
      }
      if (analogRead(S6)<wr) {
            n++;
            lineout=1;            
            sum+=w2;            
      }
      if (analogRead(S7)<wr) {
            n++;
            lineout=1;            
            sum+=w3;            
      }
      if (analogRead(S8)<wr) {
            n++;
            lineout=1;            
            sum+=w4;            
      }
      if (analogRead(S4)<wr) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
      if (analogRead(S5)<wr) {
            n++;
            lineout=0;            
            sum+=w1;            
      }
      if(n!=0){
            digitalWrite(rm1, HIGH);
            digitalWrite(rm2,LOW);
            digitalWrite(lm1, HIGH);
            digitalWrite(lm2,LOW);
            error = sum/n;
            adj = Kp*error + Kd*(error-last_error);
            last_error = error;
            if (adj>0) {      
                  Lspeed += adj/w6;
                  Rspeed -= adj/w5;
            }
            else{
                  Rspeed -= adj/w6;
                  Lspeed += adj/w5;
            }
            if (Rspeed>900){
                  Rspeed = 900;
            }
            if (Lspeed>900){
                  Lspeed = 900;
            }
            if (Rspeed<0){
                  digitalWrite(rm2,HIGH);
                  digitalWrite(rm1,LOW);
                  Rspeed = - Rspeed;
            }
            if (Lspeed<0){
                  digitalWrite(lm2,HIGH);
                  digitalWrite(lm1,LOW);
                  Lspeed = - Lspeed;
            }
            analogWrite(Rpwm, Rspeed);
            analogWrite(Lpwm, Lspeed);
      }
      else{
            // drive(300,300);
            brake();
      }
}


void reverselineFollowing(){
      n=0,sum=0,Rspeed=rspeed,Lspeed=lspeed;

      if (analogRead(S1)<wr) {
            n++;
            sum-=w4;
            lineout=-1;            
      }
      if (analogRead(S2)<wr) {
            n++;
            sum-=w3;   
            lineout=-1;            
      }
      if (analogRead(S3)<wr) {
            n++;
            sum-=w2;   
            lineout=-1;            
      }
      if (analogRead(S6)<wr) {
            n++;
            lineout=1;            
            sum+=w2;            
      }
      if (analogRead(S7)<wr) {
            n++;
            lineout=1;            
            sum+=w3;            
      }
      if (analogRead(S8)<wr) {
            n++;
            lineout=1;            
            sum+=w4;            
      }
      if (analogRead(S4)<wr) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
      if (analogRead(S5)<wr) {
            n++;
            lineout=0;            
            sum+=w1;            
      }
      if(n!=0){
            digitalWrite(rm1, LOW);
            digitalWrite(rm2,HIGH);
            digitalWrite(lm1, LOW);
            digitalWrite(lm2,HIGH);
            error = sum/n;
            adj = Kp*error + Kd*(error-last_error);
            last_error = error;
            if (adj>0) {      
                  Lspeed += adj/w6;
                  Rspeed -= adj/w5;
            }
            else{
                  Rspeed -= adj/w6;
                  Lspeed += adj/w5;
            }
            if (Rspeed>900){
                  Rspeed = 900;
            }
            if (Lspeed>900){
                  Lspeed = 900;
            }
            if (Rspeed<0){
                  digitalWrite(rm2,LOW);
                  digitalWrite(rm1,HIGH);
                  Rspeed = - Rspeed;
            }
            if (Lspeed<0){
                  digitalWrite(lm2,LOW);
                  digitalWrite(lm1,HIGH);
                  Lspeed = - Lspeed;
            }
            analogWrite(Rpwm, Rspeed);
            analogWrite(Lpwm, Lspeed);
      }
      else{
            brake();
      }
}
void dashedlineFollowing(){
      n=0,sum=0;      
      if (analogRead(S1)>br) {
            n++;
            sum-=w4;
            lineout=-1;            
      }
      if (analogRead(S2)>br) {
            n++;
            sum-=w3;   
            lineout=-1;            
      }
      if (analogRead(S3)>br) {
            n++;
            sum-=w2;   
            lineout=-1;            
      }
      if (analogRead(S6)>br) {
            n++;
            lineout=1;            
            sum+=w2;            
      }
      if (analogRead(S7)>br) {
            n++;
            lineout=1;            
            sum+=w3;            
      }
      if (analogRead(S8)>br) {
            n++;
            lineout=1;            
            sum+=w4;            
      }
      if (analogRead(S4)>br) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
      if (analogRead(S5)>br) {
            n++;
            lineout=0;            
            sum+=w1;            
      }
      if(n!=0){
            Rspeed=rspeed,Lspeed=lspeed;
            digitalWrite(rm1, HIGH);
            digitalWrite(rm2,LOW);
            digitalWrite(lm1, HIGH);
            digitalWrite(lm2,LOW);
            error = sum/n;
            adj = dKp*error + dKd*(error-last_error);
            last_error = error;
            if (adj>0) {      
                  Lspeed += adj/w6;
                  Rspeed -= adj/w5;
            }
            else{
                  Rspeed -= adj/w6;
                  Lspeed += adj/w5;
            }
            if (Rspeed>550){
                  Rspeed = 550;
            }
            if (Lspeed>550){
                  Lspeed = 550;
            }
            
            if (Rspeed<150){
                  Rspeed = 150;
            }
            if (Lspeed<150){
                  Lspeed = 150;
            }
            if (dash_count<50){
                  l_pwm[dash_count]=Lspeed;
                  r_pwm[dash_count]=Rspeed;
                  dash_count++;
            }
            else dash_count=0;
            analogWrite(Rpwm, Rspeed);
            analogWrite(Lpwm, Lspeed);
            l_average=0;
            r_average=0;
            Serial.print(Rspeed);
            Serial.print(", ");
            Serial.println(Lspeed);

      }
      else{
            if(l_average==0){
                  for (int i=0;i<50;i++){
                        l_average+=l_pwm[i];
                        r_average+=r_pwm[i];
                  }
                  Lspeed=l_average/50;
                  Rspeed=r_average/50;
            }
            
            drive(Lspeed,Rspeed);
            // delay(5);
      }

}