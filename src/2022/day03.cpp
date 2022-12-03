/*
	Advent of Code - 2022: Day 03
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>


/**
 * @brief Separates a string into two equal (or close to equal) substrings.
 * 
 * @param input  the string to split
 * @param c1     the first half of the input string
 * @param c2     the second half of the input string
 * 
*/
void separate(const std::string &input, std::string &c1, std::string &c2){
	unsigned int midpoint = input.size() / 2;
	c1 = input.substr(0, midpoint);
	c2 = input.substr(midpoint);
}

/**
 * @param c1  a set of characters
 * @param c2  a set of characters
 * 
 * @return a set of characters that are in both input sets.
 * 
*/
std::set<char> getCommonTypes(const std::set<char> &c1, const std::set<char> &c2){
	// Stores the intersection in a vector.
	std::vector<char> commonTypes;
	std::set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), std::back_inserter(commonTypes));

	// Converts the vector into a set.
	std::set<char> commonTypesAsSet(commonTypes.begin(), commonTypes.end());

	return commonTypesAsSet;
}

/**
 * @param ch  an alphabetical character
 * 
 * @return the priority of the character.
 * 
*/
unsigned int getPriority(char ch){
	if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 27;
	else return ch - 'a' + 1;
}


void partOne(const std::vector<std::string> &input){
	// Sums the priority of each common item type.
	unsigned long long sum = 0;
	for(const std::string &line : input){
		// Separates the line (rucksack) into two compartments.
		std::string str1, str2;
		separate(line, str1, str2);

		std::set<char> c1(str1.begin(), str1.end());
		std::set<char> c2(str2.begin(), str2.end());

		// Gets the common item type.
		std::set<char> commonTypes = getCommonTypes(c1, c2);
		char commonType = *commonTypes.begin();

		// Adds the priority to the sum.
		sum += getPriority(commonType);
	}


	std::cout << sum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Sums the priority of each common item type across three rucksacks.
	unsigned long long sum = 0;
	for(unsigned int i = 0; i < input.size() / 3; ++i){
		// Constructs sets of characters representing the rucksacks.
		std::string str1 = input[3 * i];
		std::set<char> c1(str1.begin(), str1.end());

		std::string str2 = input[3 * i + 1];
		std::set<char> c2(str2.begin(), str2.end());

		std::string str3 = input[3 * i + 2];
		std::set<char> c3(str3.begin(), str3.end());

		// Gets the common item type.
		std::set<char> temp = getCommonTypes(c1, c2);
		std::set<char> commonTypes = getCommonTypes(temp, c3);
		char commonType = *commonTypes.begin();

		// Adds the priority to the sum.
		sum += getPriority(commonType);
	}


	std::cout << sum << std::endl;
}
