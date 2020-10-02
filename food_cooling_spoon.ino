#include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Servo myPointer;
float p;
float k;
Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(9600);
  myPointer.attach(9);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  

  // Try to initialize!
  if (!mpu.begin()) {
  
    while (1) {
      delay(10);
    }
  }
 

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
 
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
 
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  p=a.acceleration.y*5;
  Serial.println(p);
 k= map(p,-50,50,0,180);
   myPointer.write(k);
 delay(50);
}
