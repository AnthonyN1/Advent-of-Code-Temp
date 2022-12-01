/*
	Advent of Code - Utils Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __utils_h_
#define __utils_h_

#include <string>
#include <vector>


/**
 * @brief A collection of miscellaneous general utility functions.
 * 
*/
namespace Utils{
	bool isNumber(const std::string &str);
	std::string join(const std::vector<std::string> &strs, const std::string &delim);
	std::vector<std::string> split(const std::string &str, const std::string &delim);
}

#endif
