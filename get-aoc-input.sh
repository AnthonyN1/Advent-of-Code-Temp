#!/bin/bash

# Downloads an Advent of Code input file to a text file.
#
# Expects one command line argument: the day number of the requested input file.
# This argument must be a number between 1 and 25, with no padding.
#
# Additionally expects a .env file in the current directory.
# The .env file must have the following key-value pair:
# session=<session cookie from https://adventofcode.com/>


# If the number of command line arguments is wrong, exits.
if [[ $# -ne 1 ]]; then
	echo "ERROR: incorrect number of arguments"
	echo "USAGE: ./get-aoc-input.sh <day number>"
	exit
fi

# If the argument is invalid, exits.
re="^([1-9]|1[0-9]|2[0-5])$"
if [[ ! $1 =~ $re ]]; then
	echo "ERROR: argument must be an integer between 1 and 25, inclusive"
	exit
fi

# Makes the inputs sub-directory if it doesn't exist.
mkdir -p "inputs"

# Gets the Advent of Code session cookie.
source .env

# Specifies the output file.
padded_num=$(printf "%02d" $1)
out_file="inputs/day${padded_num}.txt"

# Gets the input file of the day, and stores it in the output file.
wget --no-cookies --header "Cookie: session=${session}" -O $out_file "https://adventofcode.com/2015/day/$1/input"
