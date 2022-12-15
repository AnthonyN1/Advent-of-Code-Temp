/*
	Advent of Code - Nested Array Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __nested_array_h_
#define __nested_array_h_

#include <string>
#include <utility>
#include <variant>
#include <vector>


/**
 * @brief An arbitrarily nested array of elements.
 * 
 * @tparam T  the type of array elements
 * 
*/
template <class T> class NestedArray{
	public:
		//==================================================//
		//                   Constructors                   //
		//==================================================//
		/**
		 * @brief Constructs a NestedArray with one element.
		 * 
		 * @param elem  the element to insert into the NestedArray
		 * 
		*/
		NestedArray(const T &elem){ arr_.push_back(elem); }

		/**
		 * @brief Constructs a NestedArray by parsing a string.
		 * 
		 * @param str  the string to parse
		 * 
		*/
		NestedArray(const std::string &str);


		//==================================================//
		//                     Operators                    //
		//==================================================//
		/**
		 * @param other  the other NestedArray
		 * 
		 * @return true if the two nested arrays contain the same elements, and false otherwise.
		 * 
		*/
		bool operator==(const NestedArray<T> &other) const { return !this->operator<(other) && !other.operator<(*this); }

		/**
		 * @param other  the other NestedArray
		 * 
		 * @return true if the two nested arrays do not contain the same elements, and false otherwise.
		 * 
		*/
		bool operator!=(const NestedArray<T> &other) const { return !operator==(other); }

		/**
		 * @param other  the other NestedArray
		 * 
		 * @return true if the current NestedArray comes before other, and false otherwise.
		 * 
		*/
		bool operator<(const NestedArray<T> &other) const;
	private:
		/**
		 * @param str  the nested array, as a string
		 * @param i    the start index of the sub-array
		 * 
		 * @return the end index of the sub-array that starts at i
		 * 
		*/
		unsigned int getEndOfArray(const std::string &str, unsigned int i);


		/**
		 * @brief Provides a Callable that accepts every combination of T and NestedArray from a variant.
		 * 
		*/
		struct VisitLessThan{
			/**
			 * @param arg1  the first variant term
			 * @param arg2  the second variant term
			 * 
			 * @return a pair of booleans. The first boolean is true if arg1 != arg2, and false otherwise. The second boolean is true if arg1 < arg2, and false otherwise.
			 * 
			*/
			std::pair<bool, bool> operator()(const NestedArray<T> &arg1, const NestedArray<T> &arg2){ return std::make_pair(arg1 != arg2, arg1 < arg2); }

			/**
			 * @param arg1  the first variant term
			 * @param arg2  the second variant term
			 * 
			 * @return a pair of booleans. The first boolean is true if arg1 != arg2, and false otherwise. The second boolean is true if arg1 < arg2, and false otherwise.
			 * 
			*/
			std::pair<bool, bool> operator()(const T &arg1, const NestedArray<T> &arg2){ return std::make_pair(NestedArray(arg1) != arg2, NestedArray(arg1) < arg2); }

			/**
			 * @param arg1  the first variant term
			 * @param arg2  the second variant term
			 * 
			 * @return a pair of booleans. The first boolean is true if arg1 != arg2, and false otherwise. The second boolean is true if arg1 < arg2, and false otherwise.
			 * 
			*/
			std::pair<bool, bool> operator()(const NestedArray<T> &arg1, const T &arg2){ return std::make_pair(arg1 != NestedArray(arg2), arg1 < NestedArray(arg2)); }

			/**
			 * @param arg1  the first variant term
			 * @param arg2  the second variant term
			 * 
			 * @return a pair of booleans. The first boolean is true if arg1 != arg2, and false otherwise. The second boolean is true if arg1 < arg2, and false otherwise.
			 * 
			*/
			std::pair<bool, bool> operator()(const T &arg1, const T &arg2){ return std::make_pair(arg1 != arg2, arg1 < arg2); }
		};


		std::vector<std::variant<T, NestedArray<T>>> arr_;		/** An arbitrarily nested vector of T elements. */
};

#include "nested_array.hpp"

#endif

