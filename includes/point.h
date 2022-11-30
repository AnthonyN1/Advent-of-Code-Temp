/*
	Advent of Code - Point Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __point_h_
#define __point_h_


class Point{
	public:
		// Constructors
		Point(long long x=0, long long y=0): x_(x), y_(y) {}

		// Accessors
		long long getX() const { return x_; }
		long long getY() const { return y_; }

		// Modifiers
		void shift(long long deltaX, long long deltaY);
	private:
		long long x_, y_;
};

// Operators
bool operator<(const Point &p1, const Point &p2);

#endif
