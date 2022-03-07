#!/bin/bash

# Creates subdirectories and a starter file for an Advent of Code day.
# Expects two command line arguments:
# (1) The event year of the requested challenge. Must be a number between 2015 and 2021, with no padding.
# (2) The day number of the requested challenge. Must be a number between 1 and 25, with no padding.


# If the number of command line arguments is wrong, exits.
if [[ $# -ne 2 ]]; then
	echo "ERROR: incorrect number of arguments"
	echo "USAGE: ./start-day.sh <year> <day>"
	exit
fi

# If the year is invalid, exits.
re="^20(1[5-9]|2[0-1])$"
if [[ ! $1 =~ $re ]]; then
	echo "ERROR: <year> must be an integer between 2015 and 2021, inclusive"
	exit
fi

# If the day is invalid, exits.
re="^([1-9]|1[0-9]|2[0-5])$"
if [[ ! $2 =~ $re ]]; then
	echo "ERROR: <day> must be an integer between 1 and 25, inclusive"
	exit
fi

# Create the subdirectories.
padded_day=$(printf "%02d" $2)
path_to_dir="src/$1/day${padded_day}"

mkdir -p $path_to_dir

# Creates a start file from the template.
path_to_file="${path_to_dir}/day${padded_day}.cpp"
cp "template.cpp" $path_to_file
sed -i -e "s/<year>/$1/g" $path_to_file
sed -i -e "s/<day>/${padded_day}/g" $path_to_file
