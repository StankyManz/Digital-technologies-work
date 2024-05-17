 //setting up library's for the code:
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

 //suppling constant values with names for SDcard debugging purposes:
#define STATUS_SD_INIT_GOOD 0
#define STATUS_LAST_COMMAND_SUCCESS 1
#define STATUS_LAST_COMMAND_KNOWN 2
#define STATUS_FILE_OPEN 3
#define STATUS_IN_ROOT_DIRECTORY 4

 //creating instances of Sensor and SD Card:
LPS25HB Sensor;
OpenLog sdCard;

const String FILENAME = "sensorReading.txt"; //naming file on SDcard

void setup() { //setup

  Serial.begin(9600);//setting up serial monitor

 //setting up sensor and SDcard:
  Wire.begin();
  Sensor.begin();
  sdCard.begin();

  sdCard.append(FILENAME); // naming file on SDcard
  
  sdCard.println("NEW Temperature and Pressure readings"); //setting a checkmark so that new readings can be identified from older readings
  Serial.println("NEW Temperature and Pressure readings"); //setting a checkmark so that new readings can be identified from older readings
 //creating headers for the temperature and pressure values:
  Serial.println("Pressure , Temperature"); //print for serial monitor
  sdCard.println("Pressure , Temperature"); //print for SDcard

 //testing if sensor is connected/working:
  if (Sensor.isConnected() == false) { //if the sensor is not connected
    Serial.println("sensor is disconnected"); //print in the serial monitor that the sensor is disconnected
  }

  byte sdStatus = sdCard.getStatus(); //getting the status from sdCard and giving it to the variable sdStatus
  if(sdStatus < 0x10) { //if the sdcard status meets a certain criteria
  Serial.println(sdStatus, HEX); //print the SDcard status as a hexidecimal into serial monitor
  }
  if(sdStatus == 0xFF) { //if the sdcard status meets a certain criteria
    Serial.println("SDcard not responding"); //print the SDcard is not responding into serial monitor
    while(1);
  }

  if(sdStatus & 1<<STATUS_SD_INIT_GOOD) { //if the sdcard status meets a certain criteria
    Serial.println("SD card is working"); //print the SDcard is working into serial monitor
   } else { //if the sdcard status does not meet criteria
    Serial.println("SDcard Failiure"); //print SDcard Failiure into serial monitor
   }
  if(sdStatus & 1<<STATUS_IN_ROOT_DIRECTORY) { //if the sdcard status meets a certain criteria
    Serial.println("Root directory is open"); //print the Root directory is open into serial monitor
   } else { //if the sdcard status does not meet criteria
    Serial.println("Root has failed to open"); //print the Root has failed to open into serial monitor
   }
  if(sdStatus & 1<<STATUS_FILE_OPEN) { //if the sdcard status meets a certain criteria
    Serial.println("File is open"); //print the file is open into serial monitor
   } else { //if the sdcard status does not meet criteria
    Serial.println("file cannot be opened"); //print the file cannot be opened into serial monitor
   }
} 

void loop() { //main loop that determines whether the data is printed to SDcard or serial monitor

  byte sdStatus = sdCard.getStatus(); //getting the status from sdCard and giving it to the variable sdStatus
  if (sdStatus != 0xFF) { //if the SDcard status does not meet a certain criteria meaning SDcard is connected
  launchSD(true); //go to LaunchSD with true = SDcard is connected
  } else { //if the sdcard status meets criteria meaning SDcard is not connected
  launchSD(false); //go to LaunchSD with false = SDcard is not connected
  }
}

void launchSD(bool launchSD) { //method recieving a boolean value(true or false)

  if (launchSD == true){ //if recieved true
  //SDcard printing:
  Serial.println("SDcard Printing"); //print SDcard printing into serial monitor
  sdCard.print("(hPa)"); //labelling value as hPa
  sdCard.print(Sensor.getPressure_hPa()); //printing pressure in hPa to SDcard
  sdCard.print (" , "); //dividing the two values
  sdCard.print("(C)"); //labelling value as degrees C
  sdCard.println(Sensor.getTemperature_degC()); //printing Temperature in degrees C to SDcard
  sdCard.syncFile(); //sending information to SDcard
  delay(200); //delaying by 200ms to get a more controllable amount of variables
  } else { //if recieved false
  //Serial monitor printing:
    Serial.print("(hPa)"); //labelling value as hPa
    Serial.print(Sensor.getPressure_hPa()); //printing pressure in hPa to serial monitor
    Serial.print (" , "); //dividing the two values
    Serial.print("(C)"); //labelling value as degrees C
    Serial.println(Sensor.getTemperature_degC()); //printing Temperature in degrees C to serial monitor
    delay(200); //delaying by 200ms to get a more controllable amount of variables
  }
}