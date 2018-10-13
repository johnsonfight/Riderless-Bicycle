#define rad2deg 57.2958
#define deg2rad 0.017453
#define vol2PWM 170.6250

#include <FuzzyRule.h>
#include <FuzzyComposition.h>
#include <Fuzzy.h>
#include <FuzzyRuleConsequent.h>
#include <FuzzyOutput.h>
#include <FuzzyInput.h>
#include <FuzzyIO.h>
#include <FuzzySet.h>
#include <FuzzyRuleAntecedent.h>

#include <Wire.h>
#include <DueTimer.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
#include <MovingAvarageFilter.h>

MovingAvarageFilter movingAvarageFilter(15);  // 10 points

MPU6050 FlywheelIMU(0x68);
MPU6050 BikeIMU(0x69);

int16_t ax, ay, az, wx, wy, wz;
float ax_offset = 258.5, ay_offset = -86.5, az_offset = -1125;
float wx_offset = -422.40, wy_offset = 50.30, wz_offset = -236.90;
const int accel_factor = 16384, gyro_factor = 131 ;
float Lean_angle, Lean_rate, Lean_rate_mov;

int16_t ax1, ay1, az1, wx1, wy1, wz1;
float ax1_offset = 310, ay1_offset = -212.5, az1_offset = -822.5;
float wx1_offset = -112.74, wy1_offset = -105.60, wz1_offset = -115.04;
float Flywheel_rate, Flywheel_angle;
int Motor_angle_limit = 30;
// Encoder Motor_encoder(50, 51);
// int Motor_angle_limit = 135; //+-60 degree  (81*10*2)/6/2 = 135;

// Step 1 -  Instantiating an object library
Fuzzy* Bikefuzzy = new Fuzzy();

// SlidingSurface (Surface) = Lean_rate + 4*rate
// Surfacce_rate = 0.01 *(Surface - Surface_old)
// fuzzy input
double Surface, Surface_n1, Surface_rate; // SlidingSurface ,SlidingSurface rate
double toU = 4.5 * vol2PWM; //
double toS = 9.0 * deg2rad;  // scale

int Motor_cmd;
int Motor_enc;

// control flag
boolean Init_CMD = false;
boolean Start_CMD = false;
// send data state : ture = byte ,false = ascii
boolean datatype = false;

// motor pin
int PWMpin1 = 2;
int PWMpin2 = 3;
int steerLPWM = 6;
int steerRPWM = 7;
int ENPin = 41;

//forward motor
int speed = 0;

int wheel_velocity;
int PWM_max = 2200;
double control_period = 0.01;
double IMU_angle_offset = -0.78;

// handlebar
float handlebar_degree = 0;

float handlebar_rel_degree = 0;

//steer
float midpoint = 1780;    //1780 or 1920 for DUE
float cmdstr = 0;
float degree = 0;
float rel_degree = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Start_Control() {
  SensorFusion();
  Motor_cmd = FSMC_Controller(Lean_angle , Lean_rate, Flywheel_angle);
  PCSerial();
  steer();
  analogWrite(DAC0, speed );
//  Serial.print(analogRead(A5));
//  Serial.print("\t");
  
}

void setup()
{
  pinMode(ENPin, OUTPUT);
  digitalWrite(ENPin, LOW);
  Serial.begin(115200);             // Pc
  pinMode(DAC0, OUTPUT);           //wheelhub
  pinMode(A5, INPUT);              //steer angle read
  pinMode(steerLPWM, OUTPUT);      //steer motor
  pinMode(steerRPWM, OUTPUT);      //steer motor


  Wire.begin();
  FuzzySetup();

  FlywheelIMU.setSleepEnabled(false);
  BikeIMU.setSleepEnabled(false);
  Serial.println("Testing device connections...");
  int Flywheel_error = FlywheelIMU_Initial();
  //    while(!Flywheel_error){
  //      Serial.println("Flywheel MPU6050 connection failed");
  //      delay(1000);
  //    }

  int BikeIMU_error = BikeIMU_Initial();
  //    while(!BikeIMU_error){
  //      Serial.println("BikeIMU MPU6050 connection failed");
  //      delay(1000);
  //    }

  Timer5.attachInterrupt(Start_Control).setFrequency(100);
  analogReadResolution(12); //ADC 12bit
  analogWriteResolution(12);//PWM 12bit

}

void loop()
{
  degree = map(analogRead(A5), 0, 4095, 0, 359);
  rel_degree = degree -66 ;
  PC_Receive();
  
}
