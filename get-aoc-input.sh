#!/bin/bash

# Downloads an Advent of Code input file to a text file.
#
# Expects two command line arguments:
# (1) The event year of the requested input file. Must be a number between 2015 and 2021, with no padding.
# (2) The day number of the requested input file. Must be a number between 1 and 25, with no padding.
#
# Expects a .env file in the current directory.
# See .example_env.


# If the number of command line arguments is wrong, exits.
if [[ $# -ne 2 ]]; then
	echo "ERROR: incorrect number of arguments"
	echo "USAGE: ./get-aoc-input.sh <year> <day>"
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

# Gets the Advent of Code session cookie.
source .env

# Specifies the output file.
padded_day=$(printf "%02d" $2)
out_file="inputs/$1/day${padded_day}.txt"

# Gets the input file of the day, and stores it in the output file.
curl "https://adventofcode.com/$1/day/$2/input" -b "session=${session}" --create-dirs -o $out_file
