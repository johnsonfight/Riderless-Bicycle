int FlywheelIMU_Initial(){
  FlywheelIMU.setRate(0x7); //1000Hz
  FlywheelIMU.setFullScaleGyroRange(MPU6050_GYRO_FS_250);//+-250 degree/sec
  FlywheelIMU.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);//+-2 g
  FlywheelIMU.setDLPFMode(MPU6050_DLPF_BW_20); //BW = 20 Hz
  return FlywheelIMU.testConnection();
}

int BikeIMU_Initial(){
  BikeIMU.setRate(0x7); //1000Hz
  BikeIMU.setFullScaleGyroRange(MPU6050_GYRO_FS_250);//+-250 degree/sec
  BikeIMU.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);//+-2 g
  BikeIMU.setDLPFMode(MPU6050_DLPF_BW_20); //BW = 20 Hz
  return BikeIMU.testConnection();
}

void SensorFusion(){
  BikeIMU.getMotion6(&ax, &ay, &az, &wx, &wy, &wz);
  Lean_rate = (wx-wx_offset)/gyro_factor;
  Lean_rate_mov = movingAvarageFilter.process(Lean_rate);  
  float Lean_accel = atan2(ay-ay_offset,az-az_offset)*57.2957; //PitchAngle by accel. 180/3.14159265359 = 57.2957795131
  float Lean_gyro = Lean_angle + Lean_rate*control_period; //control_period = 0.01 second = 10ms
  Lean_angle = 0.98*Lean_gyro + 0.02*Lean_accel; //accel & gyro DataFusion 

  
  FlywheelIMU.getMotion6(&ax1, &ay1, &az1, &wx1, &wy1, &wz1);
    Flywheel_rate = (wx1-wx1_offset)/gyro_factor;
  float Flywheel_accel = atan2(ay1-ay1_offset,az1-az1_offset)*57.2957; //PitchAngle by accel. 180/3.14159265359 = 57.2957795131
  float Flywheel_gyro = Flywheel_angle + (wx1-wx1_offset)/gyro_factor*control_period; // control_period = 0.01 second = 10ms
  Flywheel_angle = 0.98*Flywheel_gyro + 0.02*Flywheel_accel; //accel & gyro DataFusion 

}
