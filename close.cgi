#!/bin/bash
stty -F /dev/ttyACM0 -hupcl raw speed 9600 > /dev/null 2>&1
printf "\nCloseMainDoor2834\n" > /dev/ttyACM0
printf "Location: https://door.fiber.gz0.nl\n\n";
