/*
	Advent of Code - Grid Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __grid_h_
#define __grid_h_


template <class T> class Grid{
	public:
		// Constructors
		Grid(unsigned int rows=0, unsigned int cols=0, const T &init=T());
		Grid(const Grid &g);
		~Grid();

		// Observers
		const T & at(unsigned int r, unsigned int c) const { return grid_[r][c]; }
		unsigned long long countMatching(const T &val) const;
		T sum() const;

		// Mutator
		void update(unsigned int r, unsigned int c, const T &val){ grid_[r][c] = val; }
	private:
		unsigned int rows_, cols_;
		T** grid_;
};


//==================================================//
//                   Constructors                   //
//==================================================//
/*
	Creates a Grid with rows rows and cols columns, with each element initialized to init.
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

/*
	Copies the grid_ over from g.
*/
template <class T> Grid<T>::Grid(const Grid &g){
	rows_ = g.rows_;
	cols_ = g.cols_;

	grid_ = new T*[rows_];
	for(unsigned int r = 0; r < rows_; ++r){
		grid_[r] = new T[cols_];
		for(unsigned int c = 0; c < cols_; ++c)
			grid_[r][c] = g.grid_[r][c];
	}
}

/*
	Deletes all dynamically allocated memory.
*/
template <class T> Grid<T>::~Grid(){
	// Deletes all row arrays.
	for(unsigned int r = 0; r < rows_; ++r)
		delete[] grid_[r];
	
	// Deletes the column array.
	delete[] grid_;
}


//==================================================//
//                    Observers                     //
//==================================================//
/*
	Counts the number of cells that match the value of val.
*/
template <class T> unsigned long long Grid<T>::countMatching(const T &val) const {
	unsigned long long matching = 0;
	for(unsigned int r = 0; r < rows_; ++r)
		for(unsigned int c = 0; c < cols_; ++c)
			if(grid_[r][c] == val)
				++matching;
	
	return matching;
}

/*
	Sums up all the elements in grid_.
	T must be a type that supports the += operator.
*/
template <class T> T Grid<T>::sum() const {
	T sum = T();
	for(unsigned int r = 0; r < rows_; ++r)
		for(unsigned int c = 0; c < cols_; ++c)
			sum += grid_[r][c];
	
	return sum;
}

#endif
