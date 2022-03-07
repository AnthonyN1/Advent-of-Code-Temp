#!/bin/bash

# Builds a C++ static library (archive).
# Expects one command line argument:
# (1) The name of the cpp file to compile (without the .cpp).


# If the number of command line arguments is wrong, exits.
if [[ $# -ne 1 ]]; then
	echo "ERROR: incorrect number of arguments"
	echo "USAGE: ./build.sh <file name>"
	exit
fi

# If the cpp file doesn't exist, exits.
if [[ ! -f "${1}.cpp" ]]; then
	echo "ERROR: cpp file not found"
	exit
fi

# Compiles the file into an object, and updates the archive.
g++ -c "${1}.cpp" -o "${1}.o"
ar -rvs "aoc.a" "${1}.o"
