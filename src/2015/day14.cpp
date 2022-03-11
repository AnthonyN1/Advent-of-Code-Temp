/*
	Advent of Code - 2015: Day 14
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../../includes/utils.h"


struct Reindeer{
	Reindeer(unsigned long long v, unsigned long long ft, unsigned long long rt): velocity(v), flyTime(ft), restTime(rt), distance(0), score(0) {}

	unsigned long long velocity, flyTime, restTime;
	unsigned long long distance;
	unsigned long long score;
};


/*
	Comparison functions for the Reindeer struct.
*/
bool byDistance(const Reindeer &r1, const Reindeer &r2){ return r1.distance < r2.distance; }
bool byScore(const Reindeer &r1, const Reindeer &r2){ return r1.score < r2.score; }


/*
	Calculates the distance traveled by each reindeer after time seconds.
*/
void runSeconds(unsigned long long time, std::vector<Reindeer> &reindeer){
	for(Reindeer &rd : reindeer){
		unsigned long long sections = time / (rd.flyTime + rd.restTime);
		unsigned long long leftover = time % (rd.flyTime + rd.restTime);

		// Calculates the distance traveled after all "complete" sections.
		rd.distance = sections * (rd.velocity * rd.flyTime);

		// Adds the leftover "incomplete" section.
		rd.distance += rd.velocity * std::min(leftover, rd.flyTime);
	}
}


void partOne(const std::vector<std::string> &input){
	// Parses the input into Reindeer.
	std::vector<Reindeer> reindeer;
	for(const std::string &str : input){
		std::vector<std::string> parts = Utils::split(str, " ");
		reindeer.push_back(Reindeer(std::stoi(parts[3]), std::stoi(parts[6]), std::stoi(parts[13])));
	}

	runSeconds(2503, reindeer);

	// Sorts the reindeer in order of the total distance traveled.
	std::sort(reindeer.begin(), reindeer.end(), byDistance);


	std::cout << reindeer[reindeer.size() - 1].distance << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Parses the input into Reindeer.
	std::vector<Reindeer> reindeer;
	for(const std::string &str : input){
		std::vector<std::string> parts = Utils::split(str, " ");
		reindeer.push_back(Reindeer(std::stoi(parts[3]), std::stoi(parts[6]), std::stoi(parts[13])));
	}

	for(unsigned long long i = 1; i <= 2503; ++i){
		runSeconds(i, reindeer);
		std::sort(reindeer.begin(), reindeer.end(), byDistance);

		// Increments the score of each reindeer with the top distance.
		unsigned long long topDistance = reindeer[reindeer.size() - 1].distance;
		unsigned int start = reindeer.size() - 1;
		while(reindeer[start].distance == topDistance){
			++reindeer[start].score;
			--start;
		}
	}

	// Sorts the reindeer in order of their score.
	std::sort(reindeer.begin(), reindeer.end(), byScore);


	std::cout << reindeer[reindeer.size() - 1].score << std::endl;
}
