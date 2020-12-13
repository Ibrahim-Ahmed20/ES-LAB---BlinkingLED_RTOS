#include <Arduino.h>
#include <sensorDriver.h>
#include <motorDriver.h>

void taskOne( void * parameter); // Sensor Thread
#define LED_BOARD 2 //change here the pin of the board to V2


int16_t* a; // The sensor readings are recieved in this array

void setup(){

  pinMode(LED_BOARD, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  xTaskCreate(
                    taskOne,          
                    "Sensor",        
                    10000,              
                    NULL,             
                    1,                
                    NULL);

                      
}


void loop()
{
  vTaskDelay(1000);
  
  motorobject.SETUP();
  
  Serial.println("Motor Setup complete!");
  
  vTaskDelay(500);
  
  while(1){
    
    if (a[0]<200 || a[1]<200 || a[2]<200 ){
        motorobject.forward(0);
      }
    else {
      motorobject.forward(255);
      }
      vTaskDelay(200);
    }
}


void taskOne( void * parameter )
{
  sensorobject.SETUP();

  Serial.println("Sensor Setup complete!");

  while(1){
  a = sensorobject.reading();
  /*for (int i=0; i<=2 ; i++){
    Serial.println(a[i]);
    }
  Serial.println("------------------------------------");*/
  
  vTaskDelay(50); // till next reading 
  }
  
}





