/*
	Advent of Code - Point Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __point_h_
#define __point_h_


/**
 * @brief a 2D coordinate point.
 * 
*/
class Point{
	public:
		//==================================================//
		//                   Constructors                   //
		//==================================================//
		/**
		 * @brief Constructs a Point with a coordinate of (x, y).
		 * 
		 * @param x  the x-coordinate of the point
		 * @param y  the y-coordinate of the point
		 * 
		*/
		Point(long long x=0, long long y=0): x_(x), y_(y) {}

		//==================================================//
		//                     Accessors                    //
		//==================================================//
		/**
		 * @return the x-coordinate of the point.
		 * 
		*/
		long long getX() const { return x_; }

		/**
		 * @return the y-coordinate of the point.
		 * 
		*/
		long long getY() const { return y_; }

		//==================================================//
		//                     Modifiers                    //
		//==================================================//
		/**
		 * @brief Translates the point by the deltas.
		 * 
		 * @param deltaX  the change in the x-coordinate
		 * @param deltaY  the change in the y-coordinate
		 * 
		*/
		void shift(long long deltaX, long long deltaY);
	private:
		long long x_;		/** The x-coordinate. */
		long long y_;		/** The y-coordinate. */
};

//==================================================//
//                     Operators                    //
//==================================================//
/**
 * @param p1  the first Point
 * @param p2  the second Point
 * 
 * @return true if p1 is before p2 in dictionary order, and false otherwise.
 * 
*/
bool operator<(const Point &p1, const Point &p2);

#endif
