/*
	Advent of Code - 2015: Day 10
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <limits>
#include <string>
#include <vector>


/*
	Pushes the characters of count into vec.
*/
void pushCount(std::vector<char> &vec, unsigned int count){
	std::vector<char> temp;
	while(count != 0){
		temp.push_back('0' + (count % 10));
		count /= 10;
	}

	// Pushes the characters in reverse order (reading left to right).
	for(unsigned int i = temp.size() - 1; i != std::numeric_limits<unsigned int>::max(); --i)
		vec.push_back(temp[i]);
}

/*
	Generates the next string in the Look and Say Sequence.
*/
std::vector<char> generateLookSay(const std::vector<char> &vec){
	std::vector<char> output;

	char ch = vec[0];
	unsigned int count = 1;

	unsigned int i = 1;
	while(i < vec.size()){
		if(vec[i] == ch){
			// Continues counting if the number is the same.
			++count;
			++i;
		} else{
			// If the number changes, records the previous number, and resets counting.
			pushCount(output, count);
			output.push_back(ch);

			ch = vec[i];
			count = 1;

			++i;
		}
	}

	// Catches the last number recorded.
	pushCount(output, count);
	output.push_back(ch);

	return output;
}


void partOne(const std::vector<std::string> &input){
	std::vector<char> lsVec(input[0].begin(), input[0].end());
	for(unsigned int i = 0; i < 40; ++i)
		lsVec = generateLookSay(lsVec);
	

	std::cout << lsVec.size() << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<char> lsVec(input[0].begin(), input[0].end());
	for(unsigned int i = 0; i < 50; ++i)
		lsVec = generateLookSay(lsVec);
	
	
	std::cout << lsVec.size() << std::endl;
}
