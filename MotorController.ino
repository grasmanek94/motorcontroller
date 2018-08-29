#include <avr/io.h>
#include "motorshield.h"

DualVNH5019MotorShield motorController;

const double MIN_POWER = 260.0;
const double MAX_POWER = 400.0;

int power_open = 275;
int power_close = 180;
String command = "";

void setup() 
{
    Serial.begin(9600);
    Serial.println("SOK");

    motorController.init();
    motorController.setSpeeds(70, 70);
    delay(50);
    motorController.setSpeeds(-70, -70);
    delay(50);
    motorController.setSpeeds(0,0);

    Serial.println("MOK");

    loop();
}

void loop() 
{
    while(Serial.available())
    {
        char read_char = Serial.read();
        if(read_char == '\n')
        {
            if(command == "OpenMainDoor4382")
            {
                Serial.println("Opening");
                motorController.setSpeeds(power_open, power_open);
                delay(3000);
                motorController.setSpeeds(-power_close, -power_close);
                delay(333);
                motorController.setSpeeds(0, 0);
                Serial.println("Open");
     
            }
            else if(command == "CloseMainDoor2834")
            {
                Serial.println("Closing");
                motorController.setSpeeds(-power_close, -power_close);
                delay(3000);
                motorController.setSpeeds(power_close, power_close);
                delay(333);
                motorController.setSpeeds(0, 0);   
                Serial.println("Closed");             
            }
            command = "";
        }
        else
        {
            command += read_char;
        }
    }
}

