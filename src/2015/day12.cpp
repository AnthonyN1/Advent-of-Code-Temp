/*
	Advent of Code - 2015: Day 12
	Author: Anthony Nool (AnthonyN1)
*/

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>


/*
	Skips the entire JSON object, and returns the index of the closing curly bracket.
*/
unsigned int skipObj(const std::string &str, unsigned int start){
	std::stack<char> brackets;
	brackets.push(str[start]);

	unsigned int end = start + 1;
	while(brackets.size() != 0){
		if(str[end] == '{') brackets.push(str[end]);
		else if(str[end] == '}') brackets.pop();
		
		++end;
	}

	return --end;
}

/*
	Returns true if str (a JSON object) has a property with value "red".
*/
bool objHasRed(const std::string &str, unsigned int openIdx){
	unsigned int i = openIdx + 4;
	while(i < str.size()){
		// The JSON object has been parsed, and no value of "red" has been found.
		if(str[i] == '}') return false;

		// Skips nested objects.
		if(str[i] == '{'){
			i = skipObj(str, i);
			++i;
		}

		// Skips anything that isn't the start of a value.
		else if(str[i] != ':'){
			++i;
		}

		// Checks if this value is red.
		else{
			if(str.substr(i, 6) == ":\"red\""){
				return true;
			} else{
				++i;
			}
		}
	}

	return false;
}

/*
	Sums the numbers in str.
	If redFlag is true, skips all objects that have a property with value "red".
*/
long long sumNums(const std::string &str, bool redFlag){
	long long count = 0;

	bool negate = false;
	unsigned long long currNum = 0;

	unsigned int i = 0;
	while(i < str.size()){
		// Skips red objects if redFlag is true.
		if(str[i] == '{' && redFlag && objHasRed(str, i)){
			i = skipObj(str, i);
			continue;
		}

		// Adds to currNum if the number is continuing.
		if(isdigit(str[i])){
			currNum *= 10;
			currNum += str[i] - '0';
		}

		// Negates the following number.
		else if(str[i] == '-' && currNum == 0){
			negate = true;
		}
		
		// Adds the previous number when it's done.
		else{
			count += negate ? -1 * currNum : currNum;
			currNum = 0;
			negate = false;
		}

		++i;
	}

	count += negate ? -1 * currNum : currNum;

	return count;
}


void partOne(const std::vector<std::string> &input){
	std::cout << sumNums(input[0], false) << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::cout << sumNums(input[0], true) << std::endl;
}
