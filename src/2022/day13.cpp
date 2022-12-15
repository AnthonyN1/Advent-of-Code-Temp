/*
	Advent of Code - 2022: Day 13
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../../includes/nested_array.h"


typedef NestedArray<unsigned long long> NestedArr;


/**
 * @brief Parses the puzzle input for part one.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInputPartOne(const std::vector<std::string> &input, std::vector<std::pair<NestedArr, NestedArr>> &parsed){
	unsigned int i = 0;
	while(i < input.size()){
		parsed.push_back(std::make_pair(NestedArr(input[i]), NestedArr(input[i + 1])));

		i += 3;
	}
}

/**
 * @brief Parses the puzzle input for part two.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInputPartTwo(const std::vector<std::string> &input, std::vector<NestedArr> &parsed){
	for(const std::string &line : input)
		if(line != "")
			parsed.push_back(NestedArr(line));
}


void partOne(const std::vector<std::string> &input){
	std::vector<std::pair<NestedArr, NestedArr>> packets;
	parseInputPartOne(input, packets);


	// Sums the indices where the two packets are ordered correctly.
	unsigned long long sum = 0;
	for(unsigned int i = 0; i < packets.size(); ++i)
		if(packets[i].first < packets[i].second)
			sum += i + 1;


	std::cout << sum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<NestedArr> packets;
	parseInputPartTwo(input, packets);

	NestedArr divider1("[[2]]");
	NestedArr divider2("[[6]]");

	packets.push_back(divider1);
	packets.push_back(divider2);


	// Multiplies the indices of the divider packets.
	std::sort(packets.begin(), packets.end());
	unsigned long long mult = 1;
	for(unsigned int i = 0; i < packets.size(); ++i){
		if(packets[i] == divider1) mult *= i + 1;
		if(packets[i] == divider2) mult *= i + 1;
	}


	std::cout << mult << std::endl;
}
