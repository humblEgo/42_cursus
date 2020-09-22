#! /bin/bash

Reset='\033[0m'

Black='\033[30m'
Red='\033[31m'
DarkRed='\033[1;31m'
Green='\033[32m'
BrownOrange='\033[33m'
Yellow='\033[1;33m'
Blue='\033[34m'
Purple='\033[0;35m'
DarkMargenta='\033[1;35m'
Cyan='\033[36m'
LightGray='\033[37m'

BW='\033[47m'

echo -e "${Red}${BW}Choose ${BrownOrange}1 ${Red}to ${BrownOrange}5${Reset}"

echo -e "${BrownOrange}1. List"
echo -e "${Yellow}2. Vector"
echo -e "${Purple}3. Stack"
echo -e "${Cyan}4. Queue"
echo -e "${Green}5. Map"

echo -en "${DarkMargenta}Input: "

read answer

while true;
do
	if [ $answer -gt 5 -o $answer -lt 0 ]; then
		echo -e "\n${DarkRed}${BW}Input again\n${Reset}"
		echo -e "${BrownOrange}1. List"
		echo -e "${Yellow}2. Vector"
		echo -e "${Purple}3. Stack"
		echo -e "${Cyan}4. Queue"
		echo -e "${Green}5. Map"
		echo -en "${DarkMargenta}Input: "
		read answer
	else
		break
	fi
done

if [ $answer -eq 1 ]; then
	test="list"
elif [ $answer -eq 2 ]; then
	test="vector"
elif [ $answer -eq 3 ]; then
	test="stack"
elif [ $answer -eq 4 ]; then
	test="queue"
elif [ $answer -eq 5 ]; then
	test="map"
fi;

make && ./container_tests $test &&make fclean