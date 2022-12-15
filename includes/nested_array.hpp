/*
	Advent of Code - Nested Array Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <variant>
#include <vector>


template <class T> NestedArray<T>::NestedArray(const std::string &str){
	unsigned int i = 1;
	while(i < str.size() - 1){
		// If the next term is a NestedArray, recursively constructs it.
		if(str[i] == '['){
			unsigned int end = getEndOfArray(str, i);
			std::string term = str.substr(i, end - i + 1);

			arr_.push_back(NestedArray(term));

			i = end + 2;
		}

		// If the next term is a literal, parses it into the correct type.
		else{
			std::string::size_type comma = str.find_first_of(',', i);
			std::string term;

			// Stops at either the next comma, or the next closing square bracket.
			if(comma == std::string::npos){
				term = str.substr(i, str.size() - i - 1);
				i = str.size() - 1;
			} else{
				term = str.substr(i, comma - i);
				i = comma + 1;
			}

			std::stringstream ss(term);
			T termAsT;
			ss >> termAsT;

			arr_.push_back(termAsT);
		}
	}
}


template <class T> bool NestedArray<T>::operator<(const NestedArray<T> &other) const {
	// Loops through both nested arrays.
	unsigned int minSize = std::min(arr_.size(), other.arr_.size());
	for(unsigned int i = 0; i < minSize; ++i){
		std::pair<bool, bool> comp = std::visit(VisitLessThan(), arr_[i], other.arr_[i]);
		
		// If the elements aren't equal, returns either true or false.
		if(comp.first) return comp.second;
	}
	
	// If each element has been equal, returns true if the first array is shorter than the second, and false otherwise.
	return arr_.size() < other.arr_.size();
}


template <class T> unsigned int NestedArray<T>::getEndOfArray(const std::string &str, unsigned int i){
	unsigned int numOpen = 0;
	do{
		if(str[i] == '[') ++numOpen;
		if(str[i] == ']') --numOpen;
		++i;
	} while(numOpen != 0);

	return i - 1;
}
