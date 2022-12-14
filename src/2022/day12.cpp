/*
	Advent of Code - 2022: Day 12
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

#include "../../includes/graph.h"
#include "../../includes/point.h"


/**
 * @brief Finds the start and end points in the puzzle input.
 * 
 * @param input  the puzzle input
 * @param start  the start point
 * @param end    the end point
 * 
*/
void findEndpoints(std::vector<std::string> &input, Point &start, Point &end){
	for(unsigned int r = 0; r < input.size(); ++r){
		for(unsigned int c = 0; c < input[r].size(); ++c){
			// Stores the start point and sets it to the lowest elevation.
			if(input[r][c] == 'S'){
				start = Point(r, c);
				input[r][c] = 'a';
			}

			// Stores the end point and sets it to the highest elevation.
			if(input[r][c] == 'E'){
				end = Point(r, c);
				input[r][c] = 'z';
			}
		}
	}
}

/**
 * @param curr   the current point
 * @param input  the puzzle input, with endpoints converted to elevations
 * 
 * @return a vector of all of the valid (in bounds, at most one elevation higher) neighbors (not including diagonals) of curr.
 * 
*/
std::vector<Point> getValidNeighbors(const Point &curr, const std::vector<std::string> &input){
	std::vector<Point> valid;

	// The top neighbor.
	if(curr.getX() != 0 && input[curr.getX() - 1][curr.getY()] <= input[curr.getX()][curr.getY()] + 1) valid.push_back(Point(curr.getX() - 1, curr.getY()));

	// The bottom neighbor.
	if(curr.getX() != static_cast<long long>(input.size() - 1) && input[curr.getX() + 1][curr.getY()] <= input[curr.getX()][curr.getY()] + 1) valid.push_back(Point(curr.getX() + 1, curr.getY()));

	// The neighbor to the left.
	if(curr.getY() != 0 && input[curr.getX()][curr.getY() - 1] <= input[curr.getX()][curr.getY()] + 1) valid.push_back(Point(curr.getX(), curr.getY() - 1));

	// The neighbor to the right.
	if(curr.getY() != static_cast<long long>(input[curr.getX()].size()) && input[curr.getX()][curr.getY() + 1] <= input[curr.getX()][curr.getY()] + 1) valid.push_back(Point(curr.getX(), curr.getY() + 1));

	return valid;
}

/**
 * @brief Parses the puzzle input.
 * 
 * @param input   the puzzle input, with endpoints converted to elevations
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInput(const std::vector<std::string> &input, Graph<Point> &parsed){
	for(unsigned int r = 0; r < input.size(); ++r){
		for(unsigned int c = 0; c < input[r].size(); ++c){
			Point curr(r, c);
			std::vector<Point> neighbors = getValidNeighbors(curr, input);

			for(const Point &neighbor : neighbors)
				parsed.addEdge(curr, neighbor);
		}
	}
}


void partOne(const std::vector<std::string> &input){
	std::vector<std::string> inputCopy = input;

	Point start, end;
	findEndpoints(inputCopy, start, end);

	Graph<Point> g;
	parseInput(inputCopy, g);


	// Calculates the distance between the start and end using BFS.
	std::map<Point, unsigned int> distance = g.bfs(start);
	unsigned int steps = distance[end];


	std::cout << steps << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<std::string> inputCopy = input;

	Point start, end;
	findEndpoints(inputCopy, start, end);

	Graph<Point> g;
	parseInput(inputCopy, g);


	// Calculates the distance between any low elevation point and the end point using BFS.
	unsigned int minSteps = std::numeric_limits<unsigned int>::max();
	for(unsigned int r = 0; r < inputCopy.size(); ++r){
		for(unsigned int c = 0; c < inputCopy[r].size(); ++c){
			if(inputCopy[r][c] == 'a'){
				std::map<Point, unsigned int> distance = g.bfs(Point(r, c));
				if(distance.find(end) != distance.end()){
					unsigned int steps = distance[end];
					if(steps < minSteps) minSteps = steps;
				}
			}
		}
	}


	std::cout << minSteps << std::endl;
}
