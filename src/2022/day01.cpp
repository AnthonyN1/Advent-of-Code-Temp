/*
	Advent of Code - 2022: Day 01
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/**
 * @brief Parses the puzzle input.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInput(const std::vector<std::string> &input, std::vector<unsigned long long> &parsed){
	// Sums up the calories by elves.
	unsigned long long totalForOne = 0;
	for(const std::string &line : input){
		if(line == ""){
			parsed.push_back(totalForOne);
			totalForOne = 0;
		} else{
			totalForOne += std::stoi(line);	
		}
	}

	// Sorts the calories in descending order.
	std::sort(parsed.begin(), parsed.end(), std::greater<>());
}


void partOne(const std::vector<std::string> &input){
	std::vector<unsigned long long> elves;
	parseInput(input, elves);


	// Gets the maximum element from the vector.
	unsigned long long maximum = elves[0];


	std::cout << maximum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<unsigned long long> elves;
	parseInput(input, elves);


	// Sums the greatest three elements from the vector.
	unsigned long long sum = elves[0] + elves[1] + elves[2];


	std::cout << sum << std::endl;
}
