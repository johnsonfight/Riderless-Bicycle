void steer() {

//   cmdstr = midpoint ;                               //for testing
   cmdstr = 2.0*(midpoint-float(analogRead(A5)));
    if (abs(cmdstr)>900){
       analogWrite(steerRPWM, 0);
       analogWrite(steerLPWM, 0);
    }  
   
    else if (cmdstr > 0){
      analogWrite(steerRPWM, 0);
      analogWrite(steerLPWM, cmdstr);
    }  
    else {
      analogWrite(steerRPWM, abs(cmdstr));
      analogWrite(steerLPWM, 0);
    }  
 //   else {
 //     analogWrite(steerRPWM, 0);
 //     analogWrite(steerLPWM, 0);
 //   }
  
}  
