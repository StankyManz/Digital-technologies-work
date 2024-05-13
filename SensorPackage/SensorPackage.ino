// setting up library's for the code 
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SPI.h>
#include <SD.h>
#include <SparkFun_LPS25HB_Arduino_Library.h> 

//TEACHER COMMENTS what do these lines of code do?
LPS25HB Sensor;
Sd2Card card;// create instance 
SdVolume volume;// create instance 
SdFile root;// create instance 
OpenLog sdCard; // create instance 

//TEACHER COMMENTS what about this one?
const String Bottle_rocket_reading = "SD.sensor_reading_storage";

void setup() {
 Serial.begin(9600);
  Wire.begin();
Sensor.begin(); 
sdCard.begin();


 
 //TEACHER COMMENTS what does this chunk of code do? adjust its error message to something you would say
  if (Sensor.isConnected() == false) // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     // Alert the user that the device cannot be reached
    Serial.println("Are you using the right Wire port and I2C address?");      // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these."); // Suggest possible fixes
    Serial.println("");
    while (1)
      ;
  }
//TEACHER COMMENTS any sdcard checks to do?

 
}

void loop()
{
 //TEACHER COMMENTS what does this chunk of code do?
  Serial.print("current preassure: ");
  Serial.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.print(", Current tempature (C degrees): ");
  Serial.println(Sensor.getTemperature_degC()); // geting the tempature in degrees 

 //TEACHER COMMENTS what about these? check if they make a file that looks like the csv example on classroom
    sdCard.print("current preassure: ");
  sdCard.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.print(", Current tempature (C degrees): ");
  sdCard.println(Sensor.getTemperature_degC()); // geting the tempature in degrees 

delay(40); // waiting 40 miliseconds so that we can goet a good reading like 16, 14, 11, 9 insted of 16, 16, 16, 16, 14, 14, 14, 14, 14, 14, 
}

void launchDirectory