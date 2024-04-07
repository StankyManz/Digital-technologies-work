//libraries
 //TEACHER COMMENTS I would have expected the openlog library as well so you could have your SDcard object work
#include <SparkFun_TMP117.h>
#include <SparkFun_TMP117_Registers.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

//objects like sdcard and sensor board
LPS25HB sensor;  // Create an object of the LPS25HB class
OpenLog SDcard; //creating a log of all our measurements
//constants


void setup() {

  Wire.begin();
  sensor.begin();  // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  Serial.begin (9600);//setting up serial monitor
   //TEACHER COMMENTS might want that SDcard to begin hereish
  
 //TEACHER COMMENTS what is this chunk of code doing?  
if(sensor.isConnected() == false) {
Serial.println("Sensor isn't reading.");

}
}
void loop() {
 //TEACHER COMMENTS so what does this chunk of code do?
  Serial.print("Current pressure : ");
  Serial.println(sensor.getPressure_hPa());  // Get the pressure reading in hPa
  Serial.print("Current Temperature : ");
  Serial.println(sensor.getTemperature_degC(°C));

   //TEACHER COMMENTS what about these lines of code?
  SDcard.print("Current pressure : ");
  SDcard.println(sensor.getPressure_hPa());  // Get the pressure reading in hPa
  SDcard.print("Current Temperature : ");
  SDcard.println(sensor.getTemperature_degC(°C));

  delay(100); //every 0.1 secounds the sensors take and record another reading
}
