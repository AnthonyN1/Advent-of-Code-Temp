/*
	Advent of Code - 2022: Day 05
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "../../includes/utils.h"


typedef std::vector<char> crate_stack;


/**
 * @brief Separates the puzzle input into a diagram of crate stacks and a vector of moving instructions.
 * 
 * @param input    the puzzle input
 * @param diagram  the diagram of crate stacks as a vector
 * @param moves    the moving instructions as a vector
 * 
*/
void separateInput(const std::vector<std::string> &input, std::vector<std::string> &diagram, std::vector<std::string> &moves){
	// Finds the end of the diagram of crate stacks.
	unsigned int crateIdx = 0;
	for(unsigned int i = 0; i < input.size(); ++i){
		if(input[i][0] != '['){
			crateIdx = i - 1;
			break;
		}
	}

	diagram = std::vector<std::string>(input.begin(), input.begin() + crateIdx + 1);
	moves = std::vector<std::string>(input.begin() + crateIdx + 3, input.end());
}

/**
 * @brief Parses a diagram of crate stacks.
 * 
 * @param input   the diagram of crate stacks as a vector
 * @param stacks  the collection of crate_stacks to populate
 * 
*/
void parseDiagram(const std::vector<std::string> &input, std::vector<crate_stack> &stacks){
	// Calculates the number of stacks.
	// The size of each line is equal to (3 characters per stack) * (number of stacks) + (1 character delimiter) * (number of stacks - 1).
	unsigned int numStacks = (input[0].size() + 1) / 4;
	stacks = std::vector<crate_stack>(numStacks);

	// Adds the crates to each stack from top to bottom.
	for(unsigned int i = 0; i < input.size(); ++i){
		// Iterates through each stack.
		for(unsigned int stackIdx = 1; stackIdx < input[i].size(); stackIdx += 4){
			char crateLabel = input[i][stackIdx];
			if(crateLabel != ' ') stacks[stackIdx / 4].push_back(crateLabel);
		}
	}

	// Reverses the stacks.
	for(crate_stack &cs : stacks)
		std::reverse(cs.begin(), cs.end());
}

/**
 * @brief Parses the puzzle input.
 * 
 * @param input      the puzzle input
 * @param parsedOne  the first half of the input, parsed into a convenient data structure
 * @param parsedTwo  the second half of the input, parsed into a convenient data structure
 * 
*/
void parseInput(const std::vector<std::string> &input, std::vector<crate_stack> &parsedOne, std::vector<std::string> &parsedTwo){
	std::vector<std::string> diagram;
	separateInput(input, diagram, parsedTwo);

	// Parses the diagram into a collection of stacks.
	parseDiagram(diagram, parsedOne);
}


/**
 * @brief Moves crates on stacks one by one.
 * 
 * @param stacks  the stacks of crates to move
 * @param input   the moving instructions
 * 
*/
void moveOneByOne(std::vector<crate_stack> &stacks, const std::string &input){
	// Extracts the important information from the input.
	std::vector<std::string> words = Utils::split(input, " ");
	unsigned int numToMove = std::stoi(words[1]);
	unsigned int source = std::stoi(words[3]) - 1;
	unsigned int dest = std::stoi(words[5]) - 1;

	// Moves each crate one by one.
	for(unsigned int i = 0; i < numToMove; ++i){
		char temp = stacks[source].back();
		stacks[source].pop_back();
		stacks[dest].push_back(temp);
	}
}

/**
 * @brief Moves crates on stacks as a group.
 * 
 * @param stacks  the stacks of crates to move
 * @param input   the moving instructions
 * 
*/
void moveTogether(std::vector<crate_stack> &stacks, const std::string &input){
	// Extracts the important information from the input.
	std::vector<std::string> words = Utils::split(input, " ");
	unsigned int numToMove = std::stoi(words[1]);
	unsigned int source = std::stoi(words[3]) - 1;
	unsigned int dest = std::stoi(words[5]) - 1;

	// Moves the crates as a group.
	stacks[dest].insert(stacks[dest].end(), (stacks[source].end() - numToMove), stacks[source].end());
	stacks[source].erase(stacks[source].end() - numToMove, stacks[source].end());
}


void partOne(const std::vector<std::string> &input){
	std::vector<crate_stack> stacks;
	std::vector<std::string> moves;
	parseInput(input, stacks, moves);


	// Moves the crates.
	for(const std::string &move : moves)
		moveOneByOne(stacks, move);

	// Collects the label of the crate at the top of each stack.
	std::vector<char> tops;
	for(const crate_stack &cs : stacks)
		tops.push_back(cs.back());

	std::string str(tops.begin(), tops.end());


	std::cout << str << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<crate_stack> stacks;
	std::vector<std::string> moves;
	parseInput(input, stacks, moves);
	

	// Moves the crates.
	for(const std::string &move : moves)
		moveTogether(stacks, move);

	// Collects the label of the crate at the top of each stack.
	std::vector<char> tops;
	for(const crate_stack &cs : stacks)
		tops.push_back(cs.back());

	std::string str(tops.begin(), tops.end());


	std::cout << str << std::endl;
}
