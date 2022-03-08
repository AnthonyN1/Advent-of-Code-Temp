/*
	Advent of Code - Point Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <string>

#include "point.h"


//==================================================//
//                   Constructor                    //
//==================================================//
/*
	Creates a Point from a string with the following format:
	<x>,<y>
*/
Point::Point(const std::string &coord){
	unsigned int commaPos = coord.find(',');

	x_ = std::stoi(coord.substr(0, commaPos));
	y_ = std::stoi(coord.substr(commaPos + 1));
}


//==================================================//
//                     Mutator                      //
//==================================================//
/*
	Translates the point with a specified change in x and y.
*/
void Point::shift(long long deltaX, long long deltaY){
	x_ += deltaX;
	y_ += deltaY;
}
