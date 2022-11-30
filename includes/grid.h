/*
	Advent of Code - Grid Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __grid_h_
#define __grid_h_


/**
 * @brief A 2D grid.
 * 
 * @tparam T  the type of the cell contents
 * 
*/
template <class T> class Grid{
	public:
		// Constructors
		Grid(unsigned int rows=0, unsigned int cols=0, const T &init=T());
		Grid(const Grid<T> &g){ copy(g); }
		Grid<T> & operator=(const Grid<T> &g);
		~Grid(){ destroy(); }

		// Accessors
		const T & at(unsigned int r, unsigned int c) const { return grid_[r][c]; }
		unsigned long long countMatching(const T &val) const;
		T sum() const;

		// Modifiers
		void update(unsigned int r, unsigned int c, const T &val){ grid_[r][c] = val; }
	private:
		void copy(const Grid<T> &g);
		void destroy();

		unsigned int rows_, cols_;
		T** grid_;
};

#include "grid.hpp"

#endif
