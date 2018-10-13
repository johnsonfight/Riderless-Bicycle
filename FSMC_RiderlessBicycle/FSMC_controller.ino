double FSMC_Controller (double LeanAngle, double LeanRate , double FlyAngle)
{  
  int Output_motor;

  if (Start_CMD == true){  // start control  
    Output_motor = FSMC_calculate(LeanAngle,LeanRate,FlyAngle);  
  }
  else { 
    Output_motor = 0;
  }
  // saturate function  
  Output_motor = constrain(Output_motor, -PWM_max, PWM_max);
  Control_cmd(Output_motor);
  return Output_motor;
}

double FSMC_calculate (double LeanAngle,double LeanRate, double FlyAngle)
{
 double u,U;
  // Fuzzy input: Sliding surface and Sliding surface rate
  Surface = toS*( Lean_rate + 4*(LeanAngle-IMU_angle_offset) -0.2*FlyAngle);
  Surface_rate = (Surface - Surface_n1)/control_period;
    if (abs(Surface_rate) > 50){
      Surface_rate = Surface_n1;
    }
  Surface_rate = movingAvarageFilter.process(Surface_rate);
  Surface_n1 = Surface; 

  //fuzzy rule
  u = fuzzy_calculate(Surface, Surface_rate); 
  //Fuzzy output: scale
  U = toU *u;  

  return U; // control direction
}



void Control_cmd(int cmd){ 

  if(abs(Flywheel_angle) >= Motor_angle_limit ){  //angle limit protecting
    analogWrite(PWMpin1, 0);
    analogWrite(PWMpin2, 0);
  }
  else{
    if (cmd > 0){
      analogWrite(PWMpin1, 0);
      analogWrite(PWMpin2, cmd);
    }  
    else if (cmd < 0) {
      analogWrite(PWMpin1, -cmd);
      analogWrite(PWMpin2, 0);
    }  
    else {
      analogWrite(PWMpin1, 0);
      analogWrite(PWMpin2, 0);
    }  
  }
}



