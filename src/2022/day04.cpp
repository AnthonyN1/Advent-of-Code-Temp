/*
	Advent of Code - 2022: Day 04
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <utility>
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


/**
 * @brief Parses the puzzle input.
 * 
 * @param input   the puzzle input
 * @param parsed  the input, parsed into a convenient data structure
 * 
*/
void parseInput(const std::vector<std::string> &input, std::vector<std::pair<Range, Range>> &parsed){
	// Separates each line into two ranges.
	for(const std::string &line : input){
		std::vector<std::string> pairs = Utils::split(line, ",");

		std::vector<std::string> r1Str = Utils::split(pairs[0], "-");
		Range r1(std::stoi(r1Str[0]), std::stoi(r1Str[1]));

		std::vector<std::string> r2Str = Utils::split(pairs[1], "-");
		Range r2(std::stoi(r2Str[0]), std::stoi(r2Str[1]));

		parsed.push_back(std::make_pair(r1, r2));
	}
}


void partOne(const std::vector<std::string> &input){
	std::vector<std::pair<Range, Range>> ranges;
	parseInput(input, ranges);


	// Counts the number of assignment pairs that are nested.
	unsigned long long count = 0;
	for(const std::pair<Range, Range> &rangePair : ranges)
		if(rangePair.first.contains(rangePair.second) || rangePair.second.contains(rangePair.first))
			++count;


	std::cout << count << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<std::pair<Range, Range>> ranges;
	parseInput(input, ranges);

	
	// Counts the number of assignment pairs that overlap.
	unsigned long long count = 0;
	for(const std::pair<Range, Range> &rangePair : ranges)
		if(rangePair.first.overlaps(rangePair.second))
			++count;


	std::cout << count << std::endl;
}
