/*
	Advent of Code - 2015: Day 03
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../../includes/point.h"


/*
	Updates pt based on the direction ch is pointing.
	ch is either '^', 'v', '<', or '>'.
*/
void updatePoint(Point &pt, char ch){
	switch(ch){
		case '^': pt.shift(0, 1); break;
		case 'v': pt.shift(0, -1); break;
		case '<': pt.shift(-1, 0); break;
		case '>': pt.shift(1, 0); break;
	}
}


void partOne(const std::vector<std::string> &input){
	std::set<Point> visited;

	// The origin is visited.
	Point curr;
	visited.insert(curr);

	for(const std::string &str : input){
		for(char ch : str){
			// Keeps track of every visited point, and the number of times visited.
			updatePoint(curr, ch);
			visited.insert(curr);
		}
	}


	std::cout << visited.size() << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::set<Point> visited;

	// The origin is visited.
	Point santa, robot;
	visited.insert(santa);

	bool toggle = false;
	for(const std::string &str : input){
		for(char ch : str){
			// Keeps track of every visited point, and the number of times visited.
			// toggle switches after every char.
			// This represents Santa and Robo-Santa taking turns.
			if(!toggle){
				updatePoint(santa, ch);
				visited.insert(santa);
			} else{
				updatePoint(robot, ch);
				visited.insert(robot);
			}

			toggle = !toggle;
		}
	}

	std::cout << visited.size() << std::endl;
}
