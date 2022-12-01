/*
	Advent of Code - 2016: Day 02
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <string>
#include <vector>

#include "../../includes/grid.h"
#include "../../includes/point.h"


/**
 * @return a Grid that represents the keypad shown in Part 1.
 * 
*/
Grid<char> buildKeypadPart1(){
	Grid<char> keypad(3, 3);
	keypad.update(0, 0, '1'); keypad.update(0, 1, '2'); keypad.update(0, 2, '3');
	keypad.update(1, 0, '4'); keypad.update(1, 1, '5'); keypad.update(1, 2, '6');
	keypad.update(2, 0, '7'); keypad.update(2, 1, '8'); keypad.update(2, 2, '9');

	return keypad;
}

/**
 * @return a Grid that represents the keypad shown in Part 1.
 * 
*/
Grid<char> buildKeypadPart2(){
	Grid<char> keypad(5, 5, '-');
	keypad.update(0, 2, '1');
	keypad.update(1, 1, '2'); keypad.update(1, 2, '3'); keypad.update(1, 3, '4');
	keypad.update(2, 0, '5'); keypad.update(2, 1, '6'); keypad.update(2, 2, '7'); keypad.update(2, 3, '8'); keypad.update(2, 4, '9');
	keypad.update(3, 1, 'A'); keypad.update(3, 2, 'B'); keypad.update(3, 3, 'C');
	keypad.update(4, 2, 'D');

	return keypad;
}

/**
 * @brief Potentially shifts a point in the specified direction.
 * 
 * @param p       the point to modify
 * @param dx      the change in the x-coordinate
 * @param dy      the change in the y-coordinate
 * @param keypad  the grid that the point must be valid (not on a dash '-') on
 * 
*/
void maybeShift(Point &p, long long dx, long long dy, const Grid<char> &keypad){
	if(p.getX() + dx < 0 || p.getX() + dx >= keypad.getCols()) return;
	if(p.getY() + dy < 0 || p.getY() + dy >= keypad.getRows()) return;

	if(keypad.at(p.getX() + dx, p.getY() + dy) == '-') return;

	p.shift(dx, dy);
}

/**
 * @brief Constructs a grid that represents the keypad shown in Part 1.
 * 
 * @param prev    the location of the button to start on
 * @param moves   the instructions to follow
 * @param keypad  the grid that the point must be valid (not on a dash '-') on
 * 
 * @return the next button to press, starting at a specified button, and moving in a specfied way.
 * 
*/
Point getButton(const Point &prev, const std::string &moves, const Grid<char> &keypad){
	Point curr(prev);
	for(char dir : moves){
		switch(dir){
			case 'U': maybeShift(curr, 0, -1, keypad); break;
			case 'D': maybeShift(curr, 0, 1, keypad); break;
			case 'L': maybeShift(curr, -1, 0, keypad); break;
			case 'R': maybeShift(curr, 1, 0,keypad); break;
		}
	}

	return curr;
}


void partOne(const std::vector<std::string> &input){
	// Builds the keypad into a grid.
	Grid<char> keypad = buildKeypadPart1();
	
	// Iteratively finds the buttons to press.
	std::vector<char> buttons;
	Point prevButton(1, 1);
	for(const std::string &line : input){
		Point button = getButton(prevButton, line, keypad);
		prevButton = button;

		char b = keypad.at(button.getY(), button.getX());
		buttons.push_back(b);
	}

	// Converts the vector into a string.
	std::string full(buttons.begin(), buttons.end());


	std::cout << full << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Builds the keypad into a grid.
	Grid<char> keypad = buildKeypadPart2();
	
	// Iteratively finds the buttons to press.
	std::vector<char> buttons;
	Point prevButton(1, 1);
	for(const std::string &line : input){
		Point button = getButton(prevButton, line, keypad);
		prevButton = button;

		char b = keypad.at(button.getY(), button.getX());
		buttons.push_back(b);
	}

	// Converts the vector into a string.
	std::string full(buttons.begin(), buttons.end());


	std::cout << full << std::endl;
}
