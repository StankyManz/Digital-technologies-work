//libraries
#include <SparkFun_TMP117.h>
#include <SparkFun_TMP117_Registers.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>


LPS25HB sensor;  // Create an object of the LPS25HB class

OpenLog SDcard; //creating a log of all our measurements
//constants

//objects like sdcard and sensor board
void setup() {

  Wire.begin();
  sensor.begin();  // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings

  Serial.begin (9600);//setting up serial monitor
  
}if(sensor.isConnected() == false) {
Serial.println("Sensor isn't reading.");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Current pressure : ");
  Serial.println(sensor.getPressure_hPa());  // Get the pressure reading in hPa
  Serial.print("Current Temperature : ");
  Serial.println(sensor.getTemperature_degC(°C));

  SDcard.print("Current pressure : ");
  SDcard.println(sensor.getPressure_hPa());  // Get the pressure reading in hPa
  SDcard.print("Current Temperature : ");
  SDcard.println(sensor.getTemperature_degC(°C));

  delay(100); //every 0.1 secounds the sensors take and record another reading
}