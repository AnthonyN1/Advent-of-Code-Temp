/*
	Advent of Code - Grid Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>


//==================================================//
//                   Constructors                   //
//==================================================//
/**
 * @brief Constructs a Grid with the specified rows and columns, filling the cells with an optional value.
 * 
 * @param rows  the number of rows in the grid
 * @param cols  the number of columns in the grid
 * @param init  the initial value to fill the cells with
 * 
*/
template <class T> Grid<T>::Grid(unsigned int rows, unsigned int cols, const T &init){
	rows_ = rows;
	cols_ = cols;

	grid_ = new T*[rows_];
	for(unsigned int r = 0; r < rows_; ++r){
		grid_[r] = new T[cols_];
		for(unsigned int c = 0; c < cols_; ++c)
			grid_[r][c] = init;
	}
}

/**
 * @brief Assigns the current grid to the specified grid.
 * 
 * @param g  the grid to copy from
 * 
 * @return a reference to the current grid.
 * 
*/
template <class T> Grid<T> & Grid<T>::operator=(const Grid<T> &g){
	if(&g != this){
		destroy();
		copy(g);
	}

	return *this;
}


//==================================================//
//                     Accessors                    //
//==================================================//
/**
 * @param val  the value to look for
 * 
 * @return the number of cells whose value matches the specified value.
 * 
*/
template <class T> unsigned long long Grid<T>::countMatching(const T &val) const {
	unsigned long long matching = 0;
	for(unsigned int r = 0; r < rows_; ++r)
		matching += std::count(grid_[r], grid_[r] + cols_, val);
	
	return matching;
}

/**
 * @return the sum of all values in the grid.
 * 
*/
template <class T> T Grid<T>::sum() const {
	T sum = T();
	for(unsigned int r = 0; r < rows_; ++r)
		for(unsigned int c = 0; c < cols_; ++c)
			sum += grid_[r][c];
	
	return sum;
}


//==================================================//
//                  Private helpers                 //
//==================================================//
/**
 * @brief Constructs a Grid with the specified rows and columns, filling the cells with an optional value.
 * 
 * @param g  the graph to copy from
 * 
*/
template <class T> void Grid<T>::copy(const Grid<T> &g){
	rows_ = g.rows_;
	cols_ = g.cols_;

	grid_ = new T*[rows_];
	for(unsigned int r = 0; r < rows_; ++r){
		grid_[r] = new T[cols_];
		for(unsigned int c = 0; c < cols_; ++c)
			grid_[r][c] = g.grid_[r][c];
	}
}

/**
 * @brief Deletes all dynamically allocated memory.
 * 
*/
template <class T> void Grid<T>::destroy(){
	// Deletes all row arrays.
	for(unsigned int r = 0; r < rows_; ++r)
		delete[] grid_[r];
	
	// Deletes the column array.
	delete[] grid_;
}
