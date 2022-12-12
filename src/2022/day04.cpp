/*
	Advent of Code - 2022: Day 04
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <vector>

#include "../../includes/utils.h"


class Range{
	public:
		//==================================================//
		//                   Constructors                   //
		//==================================================//
		/**
		 * @brief Constructs a Range with start and end values of start and end, respectively.
		 * 
		 * @param start  the start of the range
		 * @param end    the end of the range
		 * 
		*/
		Range(unsigned long long start, unsigned long long end): start_(start), end_(end) {}


		//==================================================//
		//                     Accessors                    //
		//==================================================//
		/**
		 * @param r  the other range
		 * 
		 * @return true if the current range contains the other range, and false otherwise.
		 * 
		*/
		bool contains(const Range &r) const { return start_ <= r.start_ && r.end_ <= end_; }

		/**
		 * @param r  the other range
		 * 
		 * @return true if the current and other range overlap, and false otherwise.
		 * 
		*/
		bool overlaps(const Range &r) const { return (r.start_ <= start_ && start_ <= r.end_) || (r.start_ <= end_ && end_ <= r.end_) || contains(r); }
	private:
		unsigned long long start_;		/** The start of the range. */
		unsigned long long end_;		/** The end of the range. */
};


void partOne(const std::vector<std::string> &input){
	// Counts the number of assignment pairs that are nested.
	unsigned long long count = 0;
	for(const std::string &line : input){
		std::vector<std::string> pairs = Utils::split(line, ",");

		// Constructs the two assignment ranges.
		std::vector<std::string> r1Str = Utils::split(pairs[0], "-");
		Range r1(std::stoi(r1Str[0]), std::stoi(r1Str[1]));

		std::vector<std::string> r2Str = Utils::split(pairs[1], "-");
		Range r2(std::stoi(r2Str[0]), std::stoi(r2Str[1]));

		// Checks if one range is contained in the other.
		if(r1.contains(r2) || r2.contains(r1)) ++count;
	}


	std::cout << count << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Counts the number of assignment pairs that overlap.
	unsigned long long count = 0;
	for(const std::string &line : input){
		std::vector<std::string> pairs = Utils::split(line, ",");

		// Constructs the two assignment ranges.
		std::vector<std::string> r1Str = Utils::split(pairs[0], "-");
		Range r1(std::stoi(r1Str[0]), std::stoi(r1Str[1]));

		std::vector<std::string> r2Str = Utils::split(pairs[1], "-");
		Range r2(std::stoi(r2Str[0]), std::stoi(r2Str[1]));

		// Checks if the two ranges overlap.
		if(r1.overlaps(r2)) ++count;
	}


	std::cout << count << std::endl;
}
