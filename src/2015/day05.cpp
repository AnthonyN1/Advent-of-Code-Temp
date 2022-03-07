/*
	Advent of Code - 2015: Day 05
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <vector>


/*
	Returns true iff str is nice.
	A string is nice iff:
	(1) it contains at least 3 vowels;
	(2) it contains at least one same-letter-pair; and
	(3) it does not contain 'ab', 'cd', 'pq', or 'xy'
*/
bool isNicePartOne(const std::string &str){
	// Condition (1)
	unsigned int countVowels = 0;
	for(char ch : str)
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			++countVowels;
	
	if(countVowels < 3) return false;

	// Condition (2)
	bool found = false;
	for(unsigned int i = 0; i < str.size() - 1; ++i){
		if(str[i] == str[i + 1]){
			found = true;
			break;
		}
	}

	if(!found) return false;

	// Condition (3)
	for(unsigned int i = 0; i < str.size() - 1; ++i){
		if(str[i] == 'a' && str[i + 1] == 'b') return false;
		if(str[i] == 'c' && str[i + 1] == 'd') return false;
		if(str[i] == 'p' && str[i + 1] == 'q') return false;
		if(str[i] == 'x' && str[i + 1] == 'y') return false;
	}

	return true;
}

/*
	Returns true iff str is nice.
	A string is nice iff:
	(1) it contains at least two any-letter-pairs, without overlap; and
	(2) it contains at least one letter which repeats with exactly one letter between them
*/
bool isNicePartTwo(const std::string &str){
	// Condition (1)
	bool found = false;
	for(unsigned int i = 0; i < str.size() - 3; ++i){
		std::string pair = str.substr(i, 2);
		if(str.find(pair, i + 2) != std::string::npos){
			found = true;
			break;
		}
	}

	if(!found) return false;

	// Condition (2)
	found = false;
	for(unsigned int i = 0; i < str.size() - 2; ++i){
		if(str[i] == str[i + 2]){
			found = true;
			break;
		}
	}

	if(!found) return false;

	return true;
}


void partOne(const std::vector<std::string> &input){
	// Counts the number of nice strings.
	unsigned int numNice = 0;
	for(const std::string &str : input)
		if(isNicePartOne(str))
			++numNice;
	

	std::cout << numNice << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Counts the number of nice strings.
	unsigned int numNice = 0;
	for(const std::string &str : input)
		if(isNicePartTwo(str))
			++numNice;
	

	std::cout << numNice << std::endl;
}
