#!/bin/sh
COL="\033[;35m";
ESC="\033[33;0m";

echo "${COL}Type integers${ESC}"
read arg1
#read arg2
echo "${COL}Count numbers${ESC}"
echo $arg1 | wc -w
#echo $arg2 | wc
echo "${COL}push_swap invalid input${ESC}"
./push_swap $arg1 | grep "Error"
echo ""
echo "${COL}checker invalid input${ESC}"
./push_swap $arg1 | grep "Error"
echo ""
echo "${COL}number of operation${ESC}"
./push_swap $arg1 | wc -l
#echo "${COL}pb${ESC}"
#./pb $arg1 | wc -l
echo "${COL}push_swap | checker${ESC}"
./push_swap $arg1 | ./checker $arg1
#echo "${COL}pb | checker${ESC}"
#./pb $arg1 | ./checker $arg1