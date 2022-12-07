/*
	Advent of Code - Grid Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>


template <class T> Grid<T>::Grid(unsigned int r, unsigned int c, const T &init){
	rows_ = r;
	cols_ = c;

	grid_ = new T*[rows_];
	for(unsigned int r = 0; r < rows_; ++r){
		grid_[r] = new T[cols_];
		for(unsigned int c = 0; c < cols_; ++c)
			grid_[r][c] = init;
	}
}

template <class T> Grid<T> & Grid<T>::operator=(const Grid<T> &g){
	if(&g != this){
		destroy();
		copy(g);
	}

	return *this;
}


template <class T> unsigned long long Grid<T>::countMatching(const T &val) const {
	unsigned long long matching = 0;
	for(unsigned int r = 0; r < rows_; ++r)
		matching += std::count(grid_[r], grid_[r] + cols_, val);
	
	return matching;
}

template <class T> T Grid<T>::sum() const {
	T sum = T();
	for(unsigned int r = 0; r < rows_; ++r)
		for(unsigned int c = 0; c < cols_; ++c)
			sum += grid_[r][c];
	
	return sum;
}


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

template <class T> void Grid<T>::destroy(){
	// Deletes all row arrays.
	for(unsigned int r = 0; r < rows_; ++r)
		delete[] grid_[r];
	
	// Deletes the column array.
	delete[] grid_;
}
