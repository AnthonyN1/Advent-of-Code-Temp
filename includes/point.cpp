/*
	Advent of Code - Point Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include "point.h"


void Point::shift(long long deltaX, long long deltaY){
	x_ += deltaX;
	y_ += deltaY;
}


bool operator<(const Point &p1, const Point &p2){
	return (p1.getX() != p2.getX()) ? p1.getX() < p2.getX() : p1.getY() < p2.getY();
}
