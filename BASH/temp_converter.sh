#!/bin/bash

# Author: Berk Topbas

# Created Date: 30.09.2021

# Last Modified Date: 30.09.2021

# Description: Converts the given temperature value(integer), which will be in fahrenheit or celcius, to other unit.

# Usage Information: ./temp_converter.sh <OPTION> <VALUE> . For example, "./temp_converter.sh -c 35" (convert 35 degrees celcius to fahrenheit)


getopts "f:c:" opt;
case "$opt" in

	c) result=$(echo "scale=2; ($OPTARG * (9 / 5)) + 32" | bc | xargs -I % echo "$OPTARG degrees celcius equals % degrees fahrenheit")
	;;
	
	f) result=$(echo "scale=2; ($OPTARG - 32) * (5/9)" | bc | xargs -I % echo "$OPTARG degrees fahrenheit equals % degrees celcius")
	;; 
	
	\?)
	;;

esac

echo "$result"
