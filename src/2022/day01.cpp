/*
	Advent of Code - 2022: Day 01
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/**
 * @param input  the collection of input strings
 * 
 * @return the input parsed as sums of the grouped integral types.
 * 
*/
std::vector<unsigned long long> parseElves(const std::vector<std::string> &input){
	std::vector<unsigned long long> elves;

	// Sums up the calories by elves.
	unsigned long long totalForOne = 0;
	for(const std::string &line : input){
		if(line == ""){
			elves.push_back(totalForOne);
			totalForOne = 0;
		} else{
			totalForOne += std::stoi(line);	
		}
	}

	// Sorts the calories in descending order.
	std::sort(elves.begin(), elves.end(), std::greater<>());

	return elves;
}


void partOne(const std::vector<std::string> &input){
	// Parses the input.
	std::vector<unsigned long long> elves = parseElves(input);

	// Gets the maximum element from the vector.
	unsigned long long maximum = elves[0];


	std::cout << maximum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Parses the input.
	std::vector<unsigned long long> elves = parseElves(input);

	// Sums the greatest three elements from the vector.
	unsigned long long sum = elves[0] + elves[1] + elves[2];


	std::cout << sum << std::endl;
}
