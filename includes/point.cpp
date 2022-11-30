/*
	Advent of Code - Point Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include "point.h"


//==================================================//
//                     Modifiers                    //
//==================================================//
/**
 * @brief Translates the current point by the specified deltas.
 * 
 * @param deltaX  the change in the x-coordinate
 * @param deltaY  the change in the y-coordinate
 * 
*/
void Point::shift(long long deltaX, long long deltaY){
	x_ += deltaX;
	y_ += deltaY;
}


//==================================================//
//                     Operators                    //
//==================================================//
bool operator<(const Point &p1, const Point &p2){
	return (p1.getX() != p2.getX()) ? p1.getX() < p2.getX() : p1.getY() < p2.getY();
}
