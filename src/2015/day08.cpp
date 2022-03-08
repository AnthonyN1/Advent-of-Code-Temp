/*
	Advent of Code - 2015: Day 08
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <vector>


/*
	Decodes str, returning the size of the actual string representation.
*/
unsigned int decodeSize(const std::string &str){
	unsigned int count = 0, i = 1;
	while(i < str.size() - 1){
		++count;

		if(str[i] == '\\' && str[i + 1] == '\\') i += 2;
		else if(str[i] == '\\' && str[i + 1] == '\"') i += 2;
		else if(str[i] == '\\' && str[i + 1] == 'x') i += 4;
		else ++i;
	}

	return count;
}

/*
	Encodes str, returning the size of the string representation.
*/
unsigned int encodeSize(const std::string &str){
	unsigned int count = 6, i = 1;
	while(i < str.size() - 1){
		if(str[i] == '\\') count += 2;
		else if(str[i] == '\"') count += 2;
		else ++count;

		++i;
	}

	return count;
}


void partOne(const std::vector<std::string> &input){
	unsigned long long total = 0;
	for(const std::string &str : input)
		total += str.size() - decodeSize(str);


	std::cout << total << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	unsigned long long total = 0;
	for(const std::string &str : input)
		total += encodeSize(str) - str.size();


	std::cout << total << std::endl;
}
