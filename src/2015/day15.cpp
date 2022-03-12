/*
	Advent of Code - 2015: Day 15
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../../includes/utils.h"


struct Ingredient{
	Ingredient(long long cap, long long d, long long f, long long t, long long cal): capacity(cap), durability(d), flavor(f), texture(t), calories(cal) {}
	long long capacity, durability, flavor, texture, calories;
};


/*
	Parses an input line into an Ingredient.
*/
void parseInput(const std::string &str, std::vector<Ingredient> &ingreds){
	std::vector<std::string> parts = Utils::split(str, " ");
	for(unsigned int i = 2; i <= 8; i += 2)
		parts[i].pop_back();

	ingreds.push_back(Ingredient(std::stoi(parts[2]), std::stoi(parts[4]), std::stoi(parts[6]), std::stoi(parts[8]), std::stoi(parts[10])));
}

/*
	Gets the total score of the cookie made with ingreds, including only teaspoons amounts of each.
	If partTwo is true, any cookie that has a total calorie count other than 500 is rejected.
*/
long long getScore(const std::vector<Ingredient> &ingreds, const std::vector<unsigned long long> &teaspoons, bool partTwo){
	long long totalCap = 0, totalDur = 0, totalFla = 0, totalTex = 0, totalCal = 0;
	for(unsigned int i = 0; i < ingreds.size(); ++i){
		totalCap += teaspoons[i] * ingreds[i].capacity;
		totalDur += teaspoons[i] * ingreds[i].durability;
		totalFla += teaspoons[i] * ingreds[i].flavor;
		totalTex += teaspoons[i] * ingreds[i].texture;
		totalCal += teaspoons[i] * ingreds[i].calories;
	}

	// If any characteristic is negative, rejects the cookie.
	if(totalCap <= 0 || totalDur <= 0 || totalFla <= 0 || totalTex <= 0) return 0;

	// If partTwo is true, and the total number of calories isn't 500, rejects the cookies.
	if(partTwo && totalCal != 500) return 0;
	
	return totalCap * totalDur * totalFla * totalTex;
}


void partOne(const std::vector<std::string> &input){
	std::vector<Ingredient> ingreds;
	for(const std::string &str : input)
		parseInput(str, ingreds);
	
	std::vector<std::vector<unsigned long long>> splits = Utils::starsAndBars(100, ingreds.size());

	// Takes the maximum score of all the possible combination of Ingredients.
	long long score = 0;
	for(const std::vector<unsigned long long> split : splits)
		score = std::max(score, getScore(ingreds, split, false));


	std::cout << score << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<Ingredient> ingreds;
	for(const std::string &str : input)
		parseInput(str, ingreds);
	
	std::vector<std::vector<unsigned long long>> splits = Utils::starsAndBars(100, ingreds.size());

	// Takes the maximum score of all the possible combination of Ingredients.
	long long score = 0;
	for(const std::vector<unsigned long long> split : splits)
		score = std::max(score, getScore(ingreds, split, true));


	std::cout << score << std::endl;
}
