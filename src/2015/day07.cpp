/*
	Advent of Code - 2015: Day 07
	Author: Anthony Nool (AnthonyN1)
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../../includes/utils.h"


/*
	Generates a map of instructions and values for each wire.
*/
void generateMaps(std::map<std::string, std::string> &instructions, std::map<std::string, unsigned short> &values, const std::vector<std::string> &input){
	for(const std::string &str : input){
		// Separates the left and right hand sides.
		std::vector<std::string> sides = Utils::split(str, " -> ");

		// Either stores the instruction or the value of the wire.
		if(Utils::isNumber(sides[0])) values[sides[1]] = std::stoi(sides[0]);
		else instructions[sides[1]] = sides[0];
	}
}

/*
	Determines the value of wire using instructions and values.
	Recursive function.
*/
void evaluate(const std::map<std::string, std::string> &instructions, const std::string &wire, std::map<std::string, unsigned short> &values){
	// Base case: the wire has a numeric value.
	if(values.find(wire) != values.end()) return;

	// Base case: the wire is a number.
	if(Utils::isNumber(wire)){
		values[wire] = std::stoi(wire);
		return;
	}

	std::vector<std::string> instr = Utils::split(instructions.at(wire), " ");

	// Case: one term.
	if(instr.size() == 1){
		evaluate(instructions, instr[0], values);
		values[wire] = values[instr[0]];
	}

	// Case: two terms.
	else if(instr.size() == 2){
		evaluate(instructions, instr[1], values);
		values[wire] = ~(values[instr[1]]);
	}

	// Case: three terms, bit shift.
	else if(instr[1] == "LSHIFT"){
		evaluate(instructions, instr[0], values);
		values[wire] = values[instr[0]] << std::stoi(instr[2]);
	}

	else if(instr[1] == "RSHIFT"){
		evaluate(instructions, instr[0], values);
		values[wire] = values[instr[0]] >> std::stoi(instr[2]);
	}

	// Case: three terms, and/or.
	else{
		evaluate(instructions, instr[0], values);
		evaluate(instructions, instr[2], values);

		if(instr[1] == "AND") values[wire] = values[instr[0]] & values[instr[2]];
		else values[wire] = values[instr[0]] | values[instr[2]];
	}
}


void partOne(const std::vector<std::string> &input){
	// Pairs wires with their input instruction.
	std::map<std::string, std::string> instructions;

	// Keeps a record of known values.
	std::map<std::string, unsigned short> values;

	generateMaps(instructions, values, input);

	evaluate(instructions, "a", values);


	std::cout << values["a"] << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Pairs wires with their input instruction.
	std::map<std::string, std::string> instructions;

	// Keeps a record of known values.
	std::map<std::string, unsigned short> values;

	generateMaps(instructions, values, input);

	// Keeps the original copies of the maps.
	std::map<std::string, std::string> instructionsCopy = instructions;
	std::map<std::string, unsigned short> valuesCopy = values;

	evaluate(instructions, "a", values);

	// Re-wires the value of "a" to that of "b", and re-computes "a".
	instructionsCopy.erase("b");
	valuesCopy["b"] = values["a"];

	evaluate(instructionsCopy, "a", valuesCopy);


	std::cout << valuesCopy["a"] << std::endl;
}
