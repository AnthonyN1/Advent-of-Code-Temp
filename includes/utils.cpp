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
