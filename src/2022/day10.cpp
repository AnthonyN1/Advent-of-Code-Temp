/*
	Advent of Code - 2022: Day 10
	Author: Anthony Nool (AnthonyN1)
*/

#include <cmath>
#include <iostream>
#include <string>
#include <vector>


void partOne(const std::vector<std::string> &input){
	long long sum = 0;
	long long x = 1;

	unsigned int cycleOfInterest = 20;
	unsigned int cycle = 1;

	// Loops through each instruction.
	unsigned int i = 0;
	bool adding = false;
	while(i != input.size()){
		// If the current cycle is {20, 60, 100, 140, 180, 220}, adds to the sum.
		if(cycle == cycleOfInterest){
			sum += x * cycle;
			if(cycleOfInterest < 220) cycleOfInterest += 40;
		}

		if(adding){
			// If the addx operation was executed last cycle, adds to the X register.
			x += std::stoi(input[i].substr(5));
			++i;
			adding = false;
		} else if(input[i] == "noop"){
			// If the operation is noop, no operation is performed.
			++i;
		} else{
			// If the operation is addx, adds to the X register on the next cycle.
			adding = true;
		}

		++cycle;
	}


	std::cout << sum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	long long x = 1;
	unsigned int cycle = 1;

	// Loops through each instruction.
	unsigned int i = 0;
	bool adding = false;
	while(i != input.size()){
		// If the CRT writes to a new line this cycle, prints a newline.
		// Prints a '#' if the CRT is writing to a pixel that overlaps with the 3-pixel wide sprite, and '.' otherwise.
		unsigned int cycleWriteIdx = (cycle - 1) % 40;
		if(cycleWriteIdx == 0 && cycle != 1) std::cout << std::endl;
		std::cout << ((abs(cycleWriteIdx - x) <= 1) ? "#" : ".");

		if(adding){
			// If the addx operation was executed last cycle, adds to the X register.
			x += std::stoi(input[i].substr(5));
			++i;
			adding = false;
		} else if(input[i] == "noop"){
			// If the operation is noop, no operation is performed.
			++i;
		} else{
			// If the operation is addx, adds to the X register on the next cycle.
			adding = true;
		}

		++cycle;
	}


	std::cout << std::endl;
}
