/*
	Advent of Code - 2016: Day 04
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "../../includes/utils.h"


/**
 * @brief A collection of information that either describe a real room or a decoy room.
 * 
*/
class MaybeRoom{
	public:
		MaybeRoom(const std::string &input);
		bool isRoom() const;
		void decrypt();
		std::string name_;
		unsigned long long id_;
		std::string checksum_;
		std::string decryptedName_;
};

/**
 * @brief Constructs a MaybeRoom uses a string of input.
 * 
 * @param input  the input string
 * 
*/
MaybeRoom::MaybeRoom(const std::string &input): decryptedName_("") {
	unsigned int dashIdx = input.find_last_of('-');
	unsigned int bracketIdx = input.find_first_of('[');

	name_ = input.substr(0, dashIdx);

	std::string idStr = input.substr(dashIdx + 1, bracketIdx - dashIdx - 1);
	id_ = std::stoi(idStr);

	checksum_ = input.substr(bracketIdx + 1, input.size() - bracketIdx - 2);
}

/**
 * @return true if the current MaybeRoom is a real room, or false otherwise.
 * 
*/
bool MaybeRoom::isRoom() const {
	// Maps the characters in the encrypted name to the number of times they occur.
	std::map<char, unsigned int> charToOcc;
	for(char ch : name_)
		if(ch != '-')
			++charToOcc[ch];
	
	// Sorts the characters by occurrence, then by alphabetical order.
	std::map<unsigned int, std::set<char>, std::greater<>> occToChars;
	for(const std::pair<char, unsigned int> &p : charToOcc)
		occToChars[p.second].insert(p.first);
	
	// Finds the five most common letters, breaking ties by taking the letters first in the alphabet.
	std::vector<char> commonLetters;
	for(const std::pair<unsigned int, std::set<char>> &p : occToChars){
		for(char ch : p.second){
			if(commonLetters.size() == 5) break;
			commonLetters.push_back(ch);
		}
	}

	return std::string(commonLetters.begin(), commonLetters.end()) == checksum_;
}

/**
 * @brief Decrypts the encrypted name of the current MaybeRoom using a Shift Cipher.
 * 
*/
void MaybeRoom::decrypt(){
	std::vector<std::string> words = Utils::split(name_, "-");
	
	// Decrypts each encrypted word using the Shift Cipher.
	std::vector<std::string> wordsDecrypted;
	for(const std::string &word : words)
		wordsDecrypted.push_back(Utils::decryptShiftCipher(word, id_));
	
	decryptedName_ = Utils::join(wordsDecrypted, " ");
}


void partOne(const std::vector<std::string> &input){
	// Parses the input into MaybeRooms.
	std::vector<MaybeRoom> rooms;
	for(const std::string &line : input)
		rooms.push_back(MaybeRoom(line));
	
	// Sums the IDs of the real rooms.
	unsigned long long sum = 0;
	for(const MaybeRoom &mr : rooms)
		if(mr.isRoom())
			sum += mr.id_;


	std::cout << sum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Parses the input into MaybeRooms.
	std::vector<MaybeRoom> rooms;
	for(const std::string &line : input)
		rooms.push_back(MaybeRoom(line));
	
	// Decrypts and prints the names of the real rooms.
	for(MaybeRoom &mr : rooms){
		if(mr.isRoom()){
			mr.decrypt();
			std::cout << mr.id_ << " " << mr.decryptedName_ << std::endl;
		}
	}
}
