/*
	Advent of Code - 2015: Day 16
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

#include "../../includes/utils.h"


typedef std::map<std::string, unsigned long long> description;

const description TAPE{
	{"children", 3}, {"cats", 7}, {"samoyeds", 2}, {"pomeranians", 3}, 
	{"akitas", 0}, {"vizslas", 0}, {"goldfish", 5}, {"trees", 3}, 
	{"cars", 2}, {"perfumes", 1}
};


/*
	Adds the description of a Sue from sue to sues.
*/
void addSue(const std::string &sue, std::vector<description> &sues){
	std::vector<std::string> parts = Utils::split(sue, " ");
	description sueMap;

	for(unsigned int i = 2; i < parts.size(); i += 2){
		parts[i].pop_back();
		if(i + 1 != parts.size() - 1) parts[i + 1].pop_back();

		sueMap[parts[i]] = std::stoi(parts[i + 1]);
	}

	sues.push_back(sueMap);
}

/*
	Returns true iff sue matches the description given by TAPE.
*/
bool isMatchPartOne(const description &sue){
	for(description::const_iterator itr = sue.begin(); itr != sue.end(); ++itr)
		if(TAPE.at(itr->first) != itr->second)
			return false;
	
	return true;
}

/*
	Returns true iff sue matches the description given by TAPE, adjusting for ranged values.
*/
bool isMatchPartTwo(const description &sue){
	for(description::const_iterator itr = sue.begin(); itr != sue.end(); ++itr){
		std::string key = itr->first;

		if(key == "cats" || key == "trees"){
			// For cats and trees, sue must have greater than the recorded number.
			if(TAPE.at(key) >= itr->second) return false;
		} else if(key == "pomeranians" || key == "goldfish"){
			// For pomeranians and goldfish, sue must have less than the recorded number.
			if(TAPE.at(key) <= itr->second) return false;
		} else{
			if(TAPE.at(key) != itr->second) return false;
		}
	}
	
	return true;
}


void partOne(const std::vector<std::string> &input){
	std::vector<description> sues;
	for(const std::string &str : input)
		addSue(str, sues);
	
	unsigned int i;
	for(i = 0; i < sues.size(); ++i)
		if(isMatchPartOne(sues[i]))
			break;
	

	std::cout << i + 1 << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<description> sues;
	for(const std::string &str : input)
		addSue(str, sues);
	
	unsigned int i;
	for(i = 0; i < sues.size(); ++i)
		if(isMatchPartTwo(sues[i]))
			break;
	

	std::cout << i + 1 << std::endl;
}
