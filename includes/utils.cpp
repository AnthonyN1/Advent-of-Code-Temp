/*
	Advent of Code - Utils Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <cctype>
#include <string>
#include <vector>

#include "utils.h"


/*
	Returns true iff str is a number.
*/
bool Utils::isNumber(const std::string &str){
	for(char ch : str)
		if(!isdigit(ch))
			return false;
	
	return true;
}

/*
	Splits str with a delimiter of delim.
*/
std::vector<std::string> Utils::split(const std::string &str, const std::string &delim){
	std::vector<std::string> parts;
	std::string::size_type start = 0, end;
	while((end = str.find(delim, start)) != std::string::npos){
		parts.push_back(str.substr(start, end - start));
		start = end + delim.size();
	}

	parts.push_back(str.substr(start));

	return parts;
}

/*
	Returns all the distinct partitions of n with k parts. That is, the different ways n can be split into k addends (including 0).
	Uses the method of Stars and Bars from combinatorics.
*/
namespace{
	void starsAndBarsRecurse(unsigned long long numStarsLeft, unsigned long long numTotalBins, std::vector<unsigned long long> &currBin, std::vector<std::vector<unsigned long long>> &allBins){
		// Base case: no stars left.
		// Adds 0s to the rest of the bins, and adds the partition to allBins.
		if(numStarsLeft == 0){
			unsigned int prevSize = currBin.size();

			while(currBin.size() != numTotalBins) currBin.push_back(0);
			allBins.push_back(currBin);
			while(currBin.size() != prevSize) currBin.pop_back();

			return;
		}
		
		// Base case: one bin left to fill.
		// Fills the last bin with the remaining stars, and adds the partition to allBins.
		if(numTotalBins - currBin.size() == 1){
			currBin.push_back(numStarsLeft);
			allBins.push_back(currBin);
			currBin.pop_back();

			return;
		}

		// General case.
		// Iteratively fills the next bin with an appropriate number of stars, and recurrences to the next bins.
		for(unsigned long long numStarsNext = 0; numStarsNext <= numStarsLeft; ++numStarsNext){
			currBin.push_back(numStarsNext);
			starsAndBarsRecurse(numStarsLeft - numStarsNext, numTotalBins, currBin, allBins);
			currBin.pop_back();
		}
	}
}

std::vector<std::vector<unsigned long long>> Utils::starsAndBars(unsigned long long n, unsigned long long k){
	std::vector<unsigned long long> currBin;
	std::vector<std::vector<unsigned long long>> allBins;
	starsAndBarsRecurse(n, k, currBin, allBins);

	return allBins;
}
