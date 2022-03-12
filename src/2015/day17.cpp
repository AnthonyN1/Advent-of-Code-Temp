/*
	Advent of Code - 2015: Day 17
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/*
	Finds all possible container combinations from containers containing exactly litersLeft, and storing them in containersUsed.
*/
void countCombos(unsigned long long litersLeft, const std::vector<unsigned long long> &containers, unsigned int currIdx, std::vector<unsigned int> &containersUsed, unsigned int numContainers){
	// Base case: there's no more containers needed.
	if(litersLeft == 0) containersUsed.push_back(numContainers);

	// General case: loops through all remaining usable containers.
	for(unsigned int i = currIdx; i < containers.size(); ++i){
		if(containers[i] <= litersLeft){
			countCombos(litersLeft - containers[i], containers, i + 1, containersUsed, numContainers + 1);
		}
	}
}


void partOne(const std::vector<std::string> &input){
	std::vector<unsigned long long> containers;
	for(const std::string &str : input)
		containers.push_back(std::stoi(str));
	
	// Counts the number of container combinations possible.
	std::vector<unsigned int> containersUsed;
	countCombos(150, containers, 0, containersUsed, 0);


	std::cout << containersUsed.size() << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<unsigned long long> containers;
	for(const std::string &str : input)
		containers.push_back(std::stoi(str));
	
	// Counts the number of container combinations possible.
	std::vector<unsigned int> containersUsed;
	countCombos(150, containers, 0, containersUsed, 0);

	// Finds the minimum number of containers possibly used.
	unsigned int minContainers = *std::min_element(containersUsed.begin(), containersUsed.end());


	std::cout << std::count(containersUsed.begin(), containersUsed.end(), minContainers) << std::endl;
}
