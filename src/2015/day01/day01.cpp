/*
	Advent of Code - 2015: Day 01
	Author: Anthony Nool (AnthonyN1)
*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>


/*
	Returns true iff str only contains '(' and ')' characters.
*/
bool onlyParens(const std::string &str){
	for(char ch : str)
		if(ch != '(' && ch != ')')
			return false;
	
	return true;
}


void partOne(const std::vector<std::string> &input){
	assert(input.size() == 1);
	assert(onlyParens(input[0]));


	long long floor = 0;
	for(char ch : input[0])
		// An open parenthesis represents an increment of the current floor, and vice versa.
		floor += (ch == '(') ? 1 : -1;
	

	std::cout << floor << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	assert(input.size() == 1);
	assert(onlyParens(input[0]));


	long long floor = 0;
	unsigned int basementPos = -1;
	for(unsigned int i = 0; i < input[0].size(); ++i){
		// An open parenthesis represents an increment of the current floor, and vice versa.
		floor += (input[0][i] == '(') ? 1 : -1;

		// If the current floor is negative (in the basement), the answer has been found.
		if(floor < 0){
			basementPos = i + 1;
			break;
		}
	}


	std::cout << basementPos << std::endl;
}
