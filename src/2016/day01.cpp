/*
	Advent of Code - 2016: Day 01
	Author: Anthony Nool (AnthonyN1)
*/

#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "../../includes/point.h"
#include "../../includes/utils.h"


/**
 * @param input  the input sequence 
 * 
 * @return a sequence of instructions, where each instruction contains a direction to turn and the number of units to move.
 * 
*/
std::vector<std::pair<char, unsigned long long>> getSequence(const std::string &input){
	std::vector<std::string> sequence = Utils::split(input, ", ");

	std::vector<std::pair<char, unsigned long long>> sequencePairs;
	for(const std::string &seq : sequence){
		std::pair<char, unsigned long long> seqPair;
		seqPair.first = seq[0];
		seqPair.second = std::stoi(seq.substr(1));
		sequencePairs.push_back(seqPair);
	}

	return sequencePairs;
}

/**
 * @brief Turns to face in a new direction.
 * 
 * @param dir  The direction currently being faced.
 * @param way  The direction (left or right) to turn.
 * 
 * @return the new direction being faced.
 * 
*/
char turn(char dir, char way){
	if(way == 'L'){
		switch(dir){
			case 'n': return 'w';
			case 'w': return 's';
			case 's': return 'e';
			case 'e': return 'n';
		}
	} else{
		switch(dir){
			case 'n': return 'e';
			case 'e': return 's';
			case 's': return 'w';
			case 'w': return 'n';
		}
	}

	return ' ';
}


void partOne(const std::vector<std::string> &input){
	// Parses input.
	std::vector<std::pair<char, unsigned long long>> sequencePairs = getSequence(input[0]);

	// Initializes the position to the origin, and the direction to north.
	Point pos(0, 0);
	char dir = 'n';

	for(const std::pair<char, unsigned long long> &instruction : sequencePairs){
		// Turns in the specified direction.
		dir = turn(dir, instruction.first);

		// Moves the specified number of units.
		switch(dir){
			case 'n': pos.shift(0, instruction.second); break;
			case 's': pos.shift(0, -instruction.second); break;
			case 'e': pos.shift(instruction.second, 0); break;
			case 'w': pos.shift(-instruction.second, 0); break;
		}
	}

	// Calculates the Manhattan distance.
	long long dist = abs(pos.getX()) + abs(pos.getY());


	std::cout << dist << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Parses input.
	std::vector<std::pair<char, unsigned long long>> sequencePairs = getSequence(input);

	// Initializes the position to the origin, and the direction to north.
	Point pos(0, 0);
	char dir = 'n';

	// Keeps track of all visited locations.
	std::set<Point> visited;
	visited.insert(pos);

	for(const std::pair<char, unsigned long long> &instruction : sequencePairs){
		// Turns in the specified direction.
		dir = turn(dir, instruction.first);

		// Moves the specified number of units.
		int dx, dy;
		switch(dir){
			case 'n': dx = 0; dy = 1; break;
			case 's': dx = 0; dy = -1; break;
			case 'e': dx = 1; dy = 0; break;
			case 'w': dx = -1; dy = 0; break;
		}

		bool found = false;
		for(unsigned long long i = 0; i < instruction.second; ++i){
			pos.shift(dx, dy);

			// Attempts to insert the newly visited location.
			// If this location has been visited before, returns its Manhattan distance.
			std::pair<std::set<Point>::iterator, bool> inserted = visited.insert(pos);
			if(!inserted.second){
				found = true;
				break;
			}
		}

		if(found) break;
	}

	// Calculates the Manhattan distance.
	long long dist = abs(pos.getX()) + abs(pos.getY());


	std::cout << dist << std::endl;
}
