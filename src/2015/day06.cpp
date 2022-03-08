/*
	Advent of Code - 2015: Day 06
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../../includes/grid.h"
#include "../../includes/point.h"


/*
	Parses one line of instructions into an operation and a pair of Points.
*/
void parseInstruction(const std::string &str, char &op, Point &start, Point &end){
	// Instantiates a stringstream to parse the instruction.
	std::stringstream ss(str);

	// Determines the operation from the first 1-2 strings.
	std::string opStr;
	ss >> opStr;

	if(opStr == "toggle"){
		op = 'S';
	} else{
		std::string opStr2;
		ss >> opStr2;

		if(opStr2 == "off") op = 'O';
		else op = 'I';
	}

	// Determines the start point using the next coordinate.
	std::string p1;
	ss >> p1;
	start = Point(p1);

	// Throws away the "through".
	std::string through;
	ss >> through;

	// Determines the end point using the last coordinate.
	std::string p2;
	ss >> p2;
	end = Point(p2);
}

/*
	Executes the instruction, following the interpretation of Part One.
*/
void executeInstructionPartOne(Grid<bool> &grid, char op, const Point &start, const Point &end){
	for(unsigned int r = start.getX(); r <= end.getX(); ++r){
		for(unsigned int c = start.getY(); c <= end.getY(); ++c){
			switch(op){
				case 'S': grid.update(r, c, !grid.at(r, c)); break;
				case 'I': grid.update(r, c, true); break;
				case 'O': grid.update(r, c, false); break;
			}
		}
	}
}

/*
	Executes the instruction, following the interpretation of Part Two.
*/
void executeInstructionPartOne(Grid<unsigned long long> &grid, char op, const Point &start, const Point &end){
	for(unsigned int r = start.getX(); r <= end.getX(); ++r){
		for(unsigned int c = start.getY(); c <= end.getY(); ++c){
			switch(op){
				case 'S': grid.update(r, c, grid.at(r, c) + 2); break;
				case 'I': grid.update(r, c, grid.at(r, c) + 1); break;
				case 'O':
					if(grid.at(r, c) >= 1){
						grid.update(r, c, grid.at(r, c) - 1);
						break;
					}
			}
		}
	}
}


void partOne(const std::vector<std::string> &input){
	Grid<bool> grid(1000, 1000);
	for(const std::string &str : input){
		char op;
		Point start, end;
		parseInstruction(str, op, start, end);
		executeInstructionPartOne(grid, op, start, end);
	}


	std::cout << grid.countMatching(true) << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	Grid<unsigned long long> grid(1000, 1000);
	for(const std::string &str : input){
		char op;
		Point start, end;
		parseInstruction(str, op, start, end);
		executeInstructionPartOne(grid, op, start, end);
	}

	
	std::cout << grid.sum() << std::endl;
}
