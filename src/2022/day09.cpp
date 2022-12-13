/*
	Advent of Code - 2022: Day 09
	Author: Anthony Nool (AnthonyN1)
*/

#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../../includes/grid.h"
#include "../../includes/point.h"
#include "../../includes/utils.h"


/**
 * Associates character directions with delta offsets.
 * 
*/
const std::map<char, Point> dirToShift = {
	{'U', Point(0, 1)}, 
	{'D', Point(0, -1)}, 
	{'L', Point(-1, 0)}, 
	{'R', Point(1, 0)}
};


/**
 * @brief Parses the puzzle input.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInput(const std::vector<std::string> &input, std::vector<std::pair<char, unsigned int>> &parsed){
	for(const std::string &line : input){
		std::vector<std::string> parts = Utils::split(line, " ");
		char dir = parts[0][0];
		unsigned int numSpaces = std::stoi(parts[1]);

		parsed.push_back(std::make_pair(dir, numSpaces));
	}
}


/**
 * @param p1  the first Point
 * @param p2  the second Point
 * 
 * @return true if p1 and p2 are touching (diagonals included), and false otherwise.
 * 
*/
bool touching(const Point &p1, const Point &p2){
	return (abs(p1.getX() - p2.getX()) <= 1) && (abs(p1.getY() - p2.getY()) <= 1);
}

/**
 * @brief Moves currTail such that currHead and currTail become touching.
 * 
 * @param currHead  the head of the sub-rope with two knots
 * @param currTail  the tail of the sub-rope with two knots
 * 
*/
void moveTail(const Point &currHead, Point &currTail){
	// Calculates the horizontal and vertical distances between the head and tail.
	int xDistance = currHead.getX() - currTail.getX();
	int yDistance = currHead.getY() - currTail.getY();

	if(touching(currHead, currTail)){
		// If the head and tail are already touching, the tail doesn't need to be shifted.
		return;
	} else if(xDistance == 0){
		// If the head and tail are in the same column, the tail needs to shift vertically.
		currTail.shift(0, yDistance / abs(yDistance));
	} else if(yDistance == 0){
		// If the head and tail are in the same row, the tail needs to shift horizontally.
		currTail.shift(xDistance / abs(xDistance), 0);
	} else{
		// Else, the tail needs to shift diagonally in the direction of the head.
		currTail.shift(xDistance / abs(xDistance), yDistance / abs(yDistance));
	}
}

/**
 * @brief Moves a rope with multiple knots in the given direction.
 * 
 * @param knots      the vector of Points (knots) in the rope
 * @param dir        the direction to move the head in
 * @param visited    the grid that keeps track of the cells that the tail has visited
 * @param numSpaces  the number of spaces to move the head
 * 
*/
void move(std::vector<Point> &knots, char dir, Grid<char> &visited, unsigned int numSpaces){
	Point shift = dirToShift.at(dir);

	// Iteratively moves the rope.
	for(unsigned int i = 0; i < numSpaces; ++i){
		// Moves the head.
		knots[0].shift(shift.getX(), shift.getY());

		// Moves each knot in the rope that isn't the head.
		for(unsigned int j = 1; j < knots.size(); ++j)
			moveTail(knots[j - 1], knots[j]);
		
		// Keeps track of the possibly new location that the tail has visited.
		visited.update(knots[knots.size() - 1].getY(), knots[knots.size() - 1].getX(), '#');
	}
}


void partOne(const std::vector<std::string> &input){
	std::vector<std::pair<char, unsigned int>> instructions;
	parseInput(input, instructions);


	// Chooses a large enough grid size, and places the start position in the middle.
	Grid<char> visited(1001, 1001, '.');
	std::vector<Point> knots(2, Point(500, 500));

	// Updates the grid to note the position of the tail.
	visited.update(knots[knots.size() - 1].getY(), knots[knots.size() - 1].getX(), '#');

	// Follows each instruction.
	for(const std::pair<char, unsigned int> &instruction : instructions)
		move(knots, instruction.first, visited, instruction.second);

	// Counts the number of cells the tail has visited.
	unsigned long long numVisited = visited.countMatching('#');


	std::cout << numVisited << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<std::pair<char, unsigned int>> instructions;
	parseInput(input, instructions);


	// Chooses a large enough grid size, and places the start position in the middle.
	Grid<char> visited(1001, 1001, '.');
	std::vector<Point> knots(10, Point(500, 500));

	// Updates the grid to note the position of the tail.
	visited.update(knots[knots.size() - 1].getY(), knots[knots.size() - 1].getX(), '#');

	// Follows each instruction.
	for(const std::pair<char, unsigned int> &instruction : instructions)
		move(knots, instruction.first, visited, instruction.second);

	// Counts the number of cells the tail has visited.
	unsigned long long numVisited = visited.countMatching('#');


	std::cout << numVisited << std::endl;
}
