/*
	Advent of Code - Point Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __point_h_
#define __point_h_


class Point{
	public:
		// Constructor
		Point(long long x=0, long long y=0): x_(x), y_(y) {}

		// Mutator
		void shift(long long deltaX, long long deltaY);

		// Operator
		bool operator<(const Point &other) const { return (x_ != other.x_) ? x_ < other.x_ : y_ < other.y_; }
	private:
		long long x_, y_;
};

#endif
