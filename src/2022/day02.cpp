/*
	Advent of Code - 2022: Day 02
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <vector>


/**
 * @brief Defines enumerators for a game of Rock, Paper, Scissors.
 * 
*/
enum RPS{ rock = 1, paper = 2, scissors = 3 };

/**
 * @brief Defines enumerators for the status of games endings.
 * 
*/
enum Result { win = 6, draw = 3, lose = 0 };


/**
 * @param p1  the move of the first player
 * @param p2  the move of the second player
 * 
 * @return the outcome of the game of Rock, Paper, Scissors from the perspective of the first player.
 * 
*/
Result playRPS(RPS p1, RPS p2){
	if(p1 == p2) return draw;

	if(
		(p1 == rock && p2 == scissors) || 
		(p1 == paper && p2 == rock) || 
		(p1 == scissors && p2 == paper)
	) return win;

	return lose;
}

/**
 * @param p2   the move of the second player
 * @param res  the outcome of the game of Rock, Paper, Scissors from the perspective of the first player.
 * 
 * @return the move of the first player.
 * 
*/
RPS deduceMove(RPS p2, Result res){
	if(res == draw) return p2;

	if(res == win){
		switch(p2){
			case rock: return paper;
			case paper: return scissors;
			case scissors: return rock;
		}
	}

	else{
		switch(p2){
			case rock: return scissors;
			case paper: return rock;
			case scissors: return paper;
		}
	}

	// The function should never get here.
	return rock;
}


void partOne(const std::vector<std::string> &input){
	// Converts the input strings to Rock, Paper, Scissors turns.
	std::vector<std::pair<RPS, RPS>> turns;
	for(const std::string &line : input){
		std::pair<RPS, RPS> p;
		p.first = static_cast<RPS>(line[0] - 'A' + 1);
		p.second = static_cast<RPS>(line[2] - 'X' + 1);
		turns.push_back(p);
	}

	// Sums the turns.
	unsigned long long sum = 0;
	for(const std::pair<RPS, RPS> &turn : turns){
		sum += turn.second;
		sum += playRPS(turn.second, turn.first);
	}


	std::cout << sum << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Converts the input strings to Rock, Paper, Scissors turns.
	std::vector<std::pair<RPS, Result>> turns;
	for(const std::string &line : input){
		std::pair<RPS, Result> p;
		p.first = static_cast<RPS>(line[0] - 'A' + 1);
		p.second = static_cast<Result>((line[2] - 'X') * 3);
		turns.push_back(p);
	}

	// Sums the turns.
	unsigned long long sum = 0;
	for(const std::pair<RPS, Result> &turn : turns){
		sum += turn.second;
		sum += deduceMove(turn.first, turn.second);
	}


	std::cout << sum << std::endl;
}
