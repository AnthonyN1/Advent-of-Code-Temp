/*
	Advent of Code - 2015: Day 04
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <vector>

#include "../../includes/md5.h"


/*
	Returns the lowest number that produces a hex digest with n leading zeros.
	The string is composed of keyStr, followed by a number.
	The hash is generated using MD5.
*/
unsigned long long hashNLeadingZeros(const std::string &keyStr, unsigned int n){
	unsigned long long num = 1;
	while(true){
		// Gets the hex digest of the MD5 hash.
		std::string key = keyStr + std::to_string(num);
		std::string hex = MD5(key).hexdigest();

		// Returns when the first n hex digits are 0.
		if(hex.substr(0, n) == std::string(n, '0')) return num;

		++num;
	}
}


void partOne(const std::vector<std::string> &input){
	std::cout << hashNLeadingZeros(input[0], 5) << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::cout << hashNLeadingZeros(input[0], 6) << std::endl;
}
