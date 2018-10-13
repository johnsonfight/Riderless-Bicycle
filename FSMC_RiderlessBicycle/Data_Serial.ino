void PCSerial() {

  if (datatype == true) {
    Serial.print("!");
    //       Serial.write( highByte(Motor_cmd) );
    //       Serial.write( lowByte( Motor_cmd) );
    //       Serial.write( highByte(Motor_enc) );
    //       Serial.write( lowByte( Motor_enc) );
    //       Serial.write( highByte(wheel_velocity) );
    //       Serial.write( lowByte( wheel_velocity) );
    Serial.println();
  }

  else {

    Serial.print(Lean_angle);            // angle
    Serial.print("\t");
    Serial.print(Lean_rate);            // gyro
    Serial.print("\t");
//    Serial.print(Surface);            // gyro
//    Serial.print("\t");
//    Serial.print(Surface_rate);            // gyro
//    Serial.print("\t");
    Serial.print(Motor_cmd);
    Serial.print("\t");
//    Serial.print(Flywheel_angle);
//    Serial.print("\t");
//    Serial.print(Flywheel_rate);
//    Serial.print("\t");
    Serial.print(analogRead(A5));
    Serial.print("\t");
    Serial.print(rel_degree);


    //       Serial.print(",");
    //       Serial.print(Kp_angle);
    //       Serial.print(",");
    //       Serial.print(Kp_gyro);
    Serial.println();
  }
}



void PC_Receive() {
  while (Serial.available() > 0 ) {
    // get the new byte:
    char inCharPC = (char)Serial.read();

    if (inCharPC == 'o') {
      Init_CMD = true;
      Serial.println("Init");
      Timer5.start();
    }

    else if (inCharPC == 'v') {
      Init_CMD = false;
      Start_CMD = false;
      analogWrite(PWMpin1, 0);
      analogWrite(PWMpin2, 0);
      Motor_cmd = 0;
      digitalWrite(ENPin, LOW);
      Timer5.stop();
    }

    else if (inCharPC == 'b') {
      Start_CMD = true;
      digitalWrite(ENPin, HIGH);

    }

    else if (inCharPC == 'n') {
      if (datatype == true) {
        datatype = false;
      }
      else {
        datatype = true;
      }
    }

    ////////////////////wheel////////////////////////////////////////////////////////////////////////////

    else if (inCharPC == 's') {
      speed = 1650;
      Serial.println("1650");
    }

    else if (inCharPC == 'd') {
      speed = 1750;
      Serial.println("1750");
    }

    else if (inCharPC == 'f') {
      speed = 1850;
      Serial.println("1850");
    }

    else if (inCharPC == 'a') {
      speed = 0;
    }
    //////////////////steer////////////////////////////////////////////////////////////////////////////////

    else if (inCharPC == 'q') {
      midpoint = 1380;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    else if (inCharPC == 'w') {
      midpoint = 1580;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    else if (inCharPC == 'e') {
      midpoint = 1780;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    else if (inCharPC == 'r') {
      midpoint = 1980;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    else if (inCharPC == 't') {
      midpoint = 2180;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    else if (inCharPC == 'u') {
      analogWrite(6, 0);
      analogWrite(5, 0);
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }

    else if (inCharPC == 'x') {
      midpoint = midpoint + 10;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    else if (inCharPC == 'z') {
      midpoint = midpoint - 10;
//      Serial.print(midpoint);
//      Serial.print("\t");
//      Serial.print(analogRead(A5));
//      Serial.print("\t");
//      Serial.print(degree);
//      Serial.print("\t");
//      Serial.print(rel_degree);
//      Serial.println();
    }
    
    else if (inCharPC == 'c') {
      midpoint = 1780;
      Serial.print(midpoint);
      Serial.print("\t");
      Serial.print(analogRead(A5));
      Serial.print("\t");
      Serial.print(degree);
      Serial.print("\t");
      Serial.print(rel_degree);
      Serial.println();
    }
    
    //    else {}
  }
}

