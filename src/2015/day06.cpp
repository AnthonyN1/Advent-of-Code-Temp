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
#include "../../includes/utils.h"


/*
	Parses one line of instructions into an operation and a pair of Points.
*/
void parseInstruction(const std::string &str, char &op, Point &start, Point &end){
	std::vector<std::string> parts = Utils::split(str, " ");

	// Determines the operation from the first 1-2 strings.
	if(parts.size() == 4){
		op = 'S';
	} else{
		if(parts[1] == "off") op = 'O';
		else op = 'I';
	}

	// Determines the start point using the next coordinate.
	std::vector<std::string> p1 = Utils::split(parts[parts.size() - 3], ",");
	start = Point(std::stoi(p1[0]), std::stoi(p1[1]));

	// Determines the end point using the last coordinate.
	std::vector<std::string> p2 = Utils::split(parts[parts.size() - 1], ",");
	end = Point(std::stoi(p2[0]), std::stoi(p2[1]));
}

/*
	Executes the instruction, following the interpretation of Part One.
*/
void executeInstruction(Grid<bool> &grid, char op, const Point &start, const Point &end){
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
void executeInstruction(Grid<unsigned long long> &grid, char op, const Point &start, const Point &end){
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
		executeInstruction(grid, op, start, end);
	}


	std::cout << grid.countMatching(true) << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	Grid<unsigned long long> grid(1000, 1000);
	for(const std::string &str : input){
		char op;
		Point start, end;
		parseInstruction(str, op, start, end);
		executeInstruction(grid, op, start, end);
	}

	
	std::cout << grid.sum() << std::endl;
}
