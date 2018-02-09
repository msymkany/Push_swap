#!/bin/sh
COL="\033[;35m";
ESC="\033[33;0m";

echo "${COL}Type integers${ESC}"
read arg1
echo "${COL}Count numbers${ESC}"
echo $arg1 | wc -w
echo "${COL}push_swap invalid input${ESC}"
./push_swap $arg1 | grep "Error"
echo ""
echo "${COL}checker invalid input${ESC}"
./push_swap $arg1 | grep "Error"
echo ""
echo "${COL}number of operation${ESC}"
./push_swap $arg1 | wc -l
echo "${COL}push_swap | checker${ESC}"
./push_swap $arg1 | ./checker $arg1
