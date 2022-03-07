/*
	Advent of Code - 2015: Day 02
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/*
	Gets the length, width, height of a dimension string.
	str is of the form <l>x<w>x<h>.
*/
void getDimensions(const std::string &str, unsigned long long &l, unsigned long long &w, unsigned long long &h){
	unsigned int firstX = str.find_first_of('x');
	unsigned int lastX = str.find_last_of('x');

	l = std::stoi(str.substr(0, firstX));
	w = std::stoi(str.substr(firstX + 1, lastX - firstX - 1));
	h = std::stoi(str.substr(lastX + 1));
}


void partOne(const std::vector<std::string> &input){
	unsigned long long totalPaper = 0;
	for(const std::string &str : input){
		unsigned long long l, w, h;
		getDimensions(str, l, w, h);

		// Gathers the areas of the sides in an array.
		unsigned long long areas[] = {l * w, w * h, h * l};

		// Gets the minimum value in the array.
		unsigned long long smallest = *std::min_element(areas, areas + 3);

		// Computes the surface area of the box, plus some slack.
		totalPaper += 2 * (areas[0] + areas[1] + areas[2]) + smallest;
	}


	std::cout << totalPaper << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	unsigned long long totalRibbon = 0;
	for(const std::string &str : input){
		unsigned long long l, w, h;
		getDimensions(str, l, w, h);

		// Gets the longest dimension.
		unsigned long long largest = std::max({l, w, h});

		// Computes the perimeter of the smallest side, plus the volume of the box.
		totalRibbon += 2 * (l + w + h - largest) + (l * w * h);
	}


	std::cout << totalRibbon << std::endl;
}
