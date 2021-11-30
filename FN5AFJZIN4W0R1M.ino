#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

// create file object
File myFile;

// keep track of time
unsigned long runMillis;

// for calculating voltage
int analogInput_vol = A1;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int svalue = 0;

#define SensorPin A0          // the pH meter Analog output is connected with the Arduino’s Analog
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;

SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
char appData;  
String inData = "";


void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate

  // initialize our SD card
  if(!SD.begin(4)){
    Serial.println("Initialization failed!");
    while(1);
    }
    Serial.println("Initialization done.");
    SD.remove("ph.txt");
    myFile = SD.open("ph.txt", FILE_WRITE);
    // open file and put in variables
    if(myFile){
      myFile.println("pH\tVoltage(V)\ttime(ms)");
      }
      else{
        Serial.println("Error opening file");
        }
        myFile.close();
}

void loop()
{
    for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //take the average value of 6 center sample
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
  phValue=3.5*phValue; 
  HM10.println(phValue);

  // find voltage
  svalue = analogRead(analogInput_vol);
  vout = (svalue * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));

  // write data to sd card
  myFile = SD.open("ph.txt", FILE_WRITE);
      if(myFile){
        myFile.print(phValue);
        myFile.print("\t");
        myFile.print(vin);
        myFile.print("\t");
        runMillis = millis();
        myFile.println(runMillis);
        }
        myFile.close();
  delay(10000);
 
}
