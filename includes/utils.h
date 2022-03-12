/*
	Advent of Code - Utils Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __utils_h_
#define __utils_h_

#include <string>
#include <vector>


namespace Utils{
	bool isNumber(const std::string &str);
	std::vector<std::string> split(const std::string &str, const std::string &delim);
	std::vector<std::vector<unsigned long long>> starsAndBars(unsigned long long n, unsigned long long k);
}

#endif
