/*
	Advent of Code - 2015: Day 11
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <limits>
#include <string>
#include <vector>


/*
	Returns the next letter in the alphabet after ch.
*/
char nextLetter(char ch){
	if(ch != 'z') return ch + 1;
	else return 'a';
}

/*
	Returns true iff str is valid; that is:
	(1) str contains at least one increasing, non-skipping straight of at least three letters;
	(2) str does not contain the letters 'i', 'o', or 'l'; and
	(3) str contains two different, non-overlapping letter pairs.
*/
bool isValid(const std::string &str){
	// Condition (2)
	if(str.find('i') != std::string::npos) return false;
	if(str.find('o') != std::string::npos) return false;
	if(str.find('l') != std::string::npos) return false;

	// Condition (1)
	bool match = false;
	for(unsigned int i = 0; i < str.size() - 2; ++i){
		if(str[i] == 'y' || str[i] == 'z') continue;

		if(nextLetter(str[i]) == str[i + 1] && nextLetter(str[i + 1]) == str[i + 2]){
			match = true;
			break;
		}
	}

	if(!match) return false;

	// Condition (3)
	char firstPair = ' ';
	unsigned int i = 0;
	while(i < str.size() - 1){
		// If the letter is the same as the first letter pair, no need to check.
		if(str[i] == firstPair) ++i;

		else if(str[i] == str[i + 1]){
			if(firstPair == ' '){
				firstPair = str[i];
				i += 2;
			} else{
				// If a second letter pair is found, str is valid.
				return true;
			}
		}

		else ++i;
	}
}

/*
	Increments the password.
*/
void increment(std::string &str){
	unsigned int i = str.size() - 1;
	while(true){
		// Pushes an 'a' to the front of str in the event of overflow.
		if(i == std::numeric_limits<unsigned int>::max()){
			str.insert(str.begin(), 'a');
			break;
		}

		// Increments the letter, and moves on the the previous letter in the event of overflow.
		str[i] = nextLetter(str[i]);
		if(str[i]  == 'a') --i;
		else break;
	}
}


void partOne(const std::vector<std::string> &input){
	std::string password = input[0];
	while(!isValid(password))
		increment(password);


	std::cout << password << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::string password = input[0];
	while(!isValid(password))
		increment(password);
	
	increment(password);
	while(!isValid(password))
		increment(password);


	std::cout << password << std::endl;
}
