/*
	Advent of Code - 2022: Day 03
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <utility>
#include <vector>


/**
 * @brief Parses the puzzle input for part one.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInputPartOne(const std::vector<std::string> &input, std::vector<std::pair<std::set<char>, std::set<char>>> &parsed){
	// Separates each line (rucksack) into two compartments.
	for(const std::string &line : input){
		unsigned int midpoint = line.size() / 2;
		std::string str1 = line.substr(0, midpoint);
		std::string str2 = line.substr(midpoint);
		
		std::set<char> c1(str1.begin(), str1.end());
		std::set<char> c2(str2.begin(), str2.end());

		parsed.push_back(std::make_pair(c1, c2));
	}
}

/**
 * @brief Parses the puzzle input for part two.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInputPartTwo(const std::vector<std::string> &input, std::vector<std::vector<std::set<char>>> &parsed){
	// Constructs sets of characters representing the rucksacks.
	for(unsigned int i = 0; i < input.size() / 3; ++i){
		std::string str1 = input[3 * i];
		std::set<char> c1(str1.begin(), str1.end());

		std::string str2 = input[3 * i + 1];
		std::set<char> c2(str2.begin(), str2.end());

		std::string str3 = input[3 * i + 2];
		std::set<char> c3(str3.begin(), str3.end());

		parsed.push_back({c1, c2, c3});
	}
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
	std::vector<std::pair<std::set<char>, std::set<char>>> compartments;
	parseInputPartOne(input, compartments);


	// Sums the priority of each common item type.
	unsigned long long sum = 0;
	for(const std::pair<std::set<char>, std::set<char>> &rucksack : compartments){
		// Gets the common item type.
		std::set<char> commonTypes = getCommonTypes(rucksack.first, rucksack.second);
		char commonType = *commonTypes.begin();

		// Adds the priority to the sum.
		sum += getPriority(commonType);
	}


	std::cout << sum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<std::vector<std::set<char>>> groups;
	parseInputPartTwo(input, groups);


	// Sums the priority of each common item type across three rucksacks.
	unsigned long long sum = 0;
	for(const std::vector<std::set<char>> &group : groups){
		// Gets the common item type.
		std::set<char> temp = getCommonTypes(group[0], group[1]);
		std::set<char> commonTypes = getCommonTypes(temp, group[2]);
		char commonType = *commonTypes.begin();

		// Adds the priority to the sum.
		sum += getPriority(commonType);
	}


	std::cout << sum << std::endl;
}
