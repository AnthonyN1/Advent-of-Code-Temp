#!/bin/bash

# Downloads an Advent of Code input file to a text file.
#
# Expects one command line argument: the day number of the requested input file.
# This argument must be a number between 1 and 25, with no padding.
#
# Expects a .env file in the current directory.
# See .example_env.


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

# Gets the Advent of Code session cookie.
source .env

# Specifies the output file.
padded_num=$(printf "%02d" $1)
out_file="inputs/day${padded_num}.txt"

# Gets the input file of the day, and stores it in the output file.
curl "https://adventofcode.com/2015/day/$1/input" -b "session=${session}" --create-dirs -o $out_file
