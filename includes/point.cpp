/*
	Advent of Code - Point Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <string>

#include "point.h"


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
