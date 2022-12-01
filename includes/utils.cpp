/*
	Advent of Code - Utils Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <cctype>
#include <string>
#include <vector>

#include "utils.h"

/**
 * @brief Decrypts a string using the Shift Cipher.
 * 
 * @param encrypted  the encrypted string
 * @param shift      the number of times to rotate each character
 * 
 * @return the decrypted string.
 * 
*/
std::string Utils::decryptShiftCipher(const std::string &encrypted, unsigned long long shift){
	unsigned int numToShift = shift % 26;
	
	std::vector<char> decrypted;
	for(char ch : encrypted){
		char chDecrypted = ch;
		for(unsigned int i = 0; i < numToShift; ++i){
			if(chDecrypted == 'z') chDecrypted = 'a';
			else chDecrypted += 1;
		}

		decrypted.push_back(chDecrypted);
	}

	return std::string(decrypted.begin(), decrypted.end());
}


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
 * @param strs   the collection of strings to join
 * @param delim  the delimiting character
 * 
 * @return a string comprising of the given strings separated by the delimiting string.
 * 
*/
std::string Utils::join(const std::vector<std::string> &strs, const std::string &delim){
	std::string str;
	for(unsigned int i = 0; i < strs.size(); ++i){
		str += strs[i];
		if(i != strs.size() - 1) str += delim;
	}

	return str;
}


/**
 * @param str    the string to split
 * @param delim  the delimiting character
 * 
 * @return a collection of substrings created by splitting the string by the delimiting string.
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
