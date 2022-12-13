/*
	Advent of Code - 2022: Day 06
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>


/**
 * @brief Parses the puzzle input.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInput(const std::vector<std::string> &input, std::string &parsed){
	parsed = input[0];
}


/**
 * @param buffer  the buffer of characters to check
 * @param start   the starting index of the potential marker
 * @param end     one past the ending index of the potential marker
 * 
 * @return true if all characters in the specified range are distinct, and false otherwise.
 * 
*/
bool allDistinct(const std::string &buffer, unsigned int start, unsigned int end){
	// Stores all the distinct characters in the range.
	std::set<char> s(buffer.begin() + start, buffer.begin() + end);

	// All characters are distinct if and only if all characters were stored in the set.
	return s.size() == end - start;
}


void partOne(const std::vector<std::string> &input){
	std::string buffer;
	parseInput(input, buffer);


	// Loops through the input until a marker is found.
	unsigned int marker = 0;
	for(unsigned int i = 3; i < buffer.size(); ++i){
		if(allDistinct(buffer, i - 3, i + 1)){
			marker = i + 1;
			break;
		}
	}


	std::cout << marker << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::string buffer;
	parseInput(input, buffer);
	

	// Loops through the input until a marker is found.
	unsigned int marker = 0;
	for(unsigned int i = 13; i < buffer.size(); ++i){
		if(allDistinct(buffer, i - 13, i + 1)){
			marker = i + 1;
			break;
		}
	}


	std::cout << marker << std::endl;
}
