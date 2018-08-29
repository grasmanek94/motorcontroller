#!/bin/bash
stty -F /dev/ttyACM0 raw speed 9600 > /dev/null 2>&1
printf "OpenMainDoor4382\n" > /dev/ttyACM0
awk "/SOK/ {exit;} {print;}" < /dev/ttyACM0 > /dev/null
sleep 2
printf "Location: https://192.168.2.246\n\n";
