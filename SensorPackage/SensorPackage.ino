// setting up library's for the code
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

#define STATUS_SD_INIT_GOOD 0
#define STATUS_LAST_COMMAND_SUCCESS 1
#define STATUS_LAST_COMMAND_KNOWN 2
#define STATUS_FILE_OPEN 3
#define STATUS_IN_ROOT_DIRECTORY 4

//Creating instances of Sensor and SD Card
LPS25HB Sensor;
OpenLog sdCard;

const String FILENAME = "sensorLogCG.txt";

void setup() {

  Serial.begin(9600);
  Wire.begin();
  Sensor.begin();
  sdCard.begin();

  sdCard.append(FILENAME);

  Serial.println("Pressure , Temperature");
  sdCard.println("Pressure , Temperature");
  //TEACHER COMMENTS what does this chunk of code do? adjust its error message to something you would say
  if (Sensor.isConnected() == false) {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");      // Alert the user that the device cannot be reached
    Serial.println("Are you using the right Wire port and I2C address?");       // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these.");  // Suggest possible fixes
    Serial.println("");
  }

  byte status = sdCard.getStatus();
  //TEACHER COMMENTS any sdcard checks to do? too dooo
Serial.print("Status byte: 0x");
  if(status < 0x10) { 
  Serial.print("0");
  Serial.println(status, HEX);
  }
  if(status == 0xFF) {
    Serial.println("OpenLog failed to respond. Freezing.");
    while(1); //Freeze!
  }

  if(status & 1<<STATUS_SD_INIT_GOOD) {
    Serial.println("SD card is good");
   } else {
    Serial.println("SD init failure. Is the SD card present? Formatted?");
   }
  if(status & 1<<STATUS_IN_ROOT_DIRECTORY) {
    Serial.println("Root directory open");
   } else {
    Serial.println("Root failed to open. Is SD card present? Formatted?");
   }
  if(status & 1<<STATUS_FILE_OPEN) {
    Serial.println("Log file open and ready for recording");
   } else {
    Serial.println("No log file open. Use append command to start a new log.");
   }
   Serial.println("NEW Temperature and Pressure readings");
} 

void loop() {

  byte status = sdCard.getStatus();

  if (status != 0xFF) {
  launchSD(true); //true = SDcard is connected
  } else {
  launchSD(false); //false = SDcard is not connected
  }
}

void launchSD(bool launchSD) {

  if (launchSD == true){
  delay(200);
  Serial.println("SDcard Printing");
  sdCard.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.print (", (C)");
  sdCard.println(Sensor.getTemperature_degC());  // geting the tempature in degrees
  sdCard.syncFile();
  } else {
    //TEACHER COMMENTS what does this chunk of code do?
    Serial.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
    Serial.print (", (C)");
    Serial.println(Sensor.getTemperature_degC());  // geting the tempature in degrees
    delay(200);
  }
}