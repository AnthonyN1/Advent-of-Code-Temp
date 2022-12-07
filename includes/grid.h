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
		//==================================================//
		//                   Constructors                   //
		//==================================================//
		/**
		 * @brief Constructs a Grid with the r rows and c columns, filling the cells with an optional value init.
		 * 
		 * @param r     the number of rows in the grid
		 * @param c     the number of columns in the grid
		 * @param init  the initial value to fill the cells with
		 * 
		*/
		Grid(unsigned int rows=0, unsigned int cols=0, const T &init=T());

		/**
		 * @brief Constructs a Grid using g.
		 * 
		 * @param g  the grid to copy from
		 * 
		*/
		Grid(const Grid<T> &g){ copy(g); }
		
		/**
		 * @brief Assigns the current grid to g.
		 * 
		 * @param g  the grid to copy from
		 * 
		 * @return a reference to the current grid.
		 * 
		*/
		Grid<T> & operator=(const Grid<T> &g);

		/**
		 * @brief Destroys the grid.
		 * 
		*/
		~Grid(){ destroy(); }

		//==================================================//
		//                     Accessors                    //
		//==================================================//
		/**
		 * @param r  the index of the row of the grid cell
		 * @param c  the index of the column of the grid cell
		 * 
		 * @return the value of the grid cell at row r and column c.
		 * 
		*/
		const T & at(unsigned int r, unsigned int c) const { return grid_[r][c]; }

		/**
		 * @param val  the value to look for
		 * 
		 * @return the number of cells whose value matches val.
		 * 
		*/
		unsigned long long countMatching(const T &val) const;

		/**
		 * @return the number of columns in the grid.
		 * 
		*/
		unsigned int getCols() const { return cols_; }

		/**
		 * @return the number of rows in the grid.
		 * 
		*/
		unsigned int getRows() const { return rows_; }

		/**
		 * @return the sum of all values in the grid.
		 * 
		*/
		T sum() const;

		//==================================================//
		//                     Modifiers                    //
		//==================================================//
		/**
		 * @brief Updates the grid cell at row r and column c to val.
		 * 
		 * @param r    the index of the row of the grid cell
		 * @param c    the index of the column of the grid cell
		 * @param val  the value to insert into the grid
		 * 
		*/
		void update(unsigned int r, unsigned int c, const T &val){ grid_[r][c] = val; }
	private:
		/**
		 * @brief Constructs a Grid with the specified rows and columns, filling the cells with an optional value.
		 * 
		 * @param g  the graph to copy from
		 * 
		*/
		void copy(const Grid<T> &g);

		/**
		 * @brief Deletes all dynamically allocated memory.
		 * 
		*/
		void destroy();

		unsigned int rows_;		/** The number of rows in the grid. */
		unsigned int cols_;		/** The number of columns in the grid. */
		T** grid_;				/** A pointer representation of the grid. */
};

#include "grid.hpp"

#endif
