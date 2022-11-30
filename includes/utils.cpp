/*
	Advent of Code - Utils Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <cctype>
#include <string>
#include <vector>

#include "utils.h"


/**
 * @param str  the string to parse
 * 
 * @return true if and only if the string can be parsed into a non-negative number.
 * 
*/
bool Utils::isNumber(const std::string &str){
	for(char ch : str)
		if(!isdigit(ch))
			return false;	
	return true;
}


/**
 * @param str    the string to split
 * @param delim  the delimiting character
 * 
 * @return a collection of substrings created by splitting the string by the delimiting string
 * 
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
