/*
	Advent of Code - 2022: Day 11
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../../includes/utils.h"


class Monkey{
	public:
		Monkey(unsigned int id, const std::function<unsigned long long(unsigned long long)> &operation, const std::function<unsigned int(unsigned long long)> &test): id_(id), operation_(operation), test_(test), numInspected_(0) {}

		unsigned int numItems() const { return items_.size(); }
		unsigned long long numInspected() const { return numInspected_; }

		void addItem(unsigned long long item){ items_.push(item); }
		unsigned long long throwItem(unsigned int &nextMonkey);

		bool operator<(const Monkey& other) const;
	private:
		unsigned int id_;
		std::queue<unsigned long long> items_;
		std::function<unsigned long long(unsigned long long)> operation_;
		std::function<unsigned int(unsigned long long)> test_;
		unsigned long long numInspected_;
};

unsigned long long Monkey::throwItem(unsigned int &nextMonkey){
	unsigned long long currItem = items_.front();
	items_.pop();
	++numInspected_;

	currItem = operation_(currItem);
	// currItem /= 3;
	currItem %= 9699690;
	// currItem %= 96577;

	nextMonkey = test_(currItem);

	return currItem;
}

bool Monkey::operator<(const Monkey &other) const {
	return numInspected_ < other.numInspected_;
}




std::function<unsigned long long(unsigned long long)> parseOperation(const std::string &opStr){
	std::vector<std::string> terms = Utils::split(opStr, " ");
	assert(terms[0] == "new");
	assert(terms[1] == "=");
	assert(terms[2] == "old");

	if(terms[3] == "*" && terms[4] == "old"){
		return [](unsigned long long x){ return x * x; };
	} else if(terms[3] == "*"){
		unsigned long long factor = std::stoi(terms[4]);
		return [factor](unsigned long long x){ return x * factor; };
	} else if(terms[3] == "+" && terms[4] == "old"){
		return [](unsigned long long x){ return x + x; };
	} else{
		unsigned long long addend = std::stoi(terms[4]);
		return [addend](unsigned long long x){ return x + addend; };
	}
}

std::function<unsigned int(unsigned long long)> parseTest(const std::string &testStr, const std::string &ifTrue, const std::string &ifFalse){
	unsigned long long divisor = std::stoi(testStr.substr(21));
	unsigned int trueMonkey = std::stoi(ifTrue.substr(29));
	unsigned int falseMonkey = std::stoi(ifFalse.substr(30));

	return [divisor, trueMonkey, falseMonkey](unsigned long long x){ return (x % divisor == 0) ? trueMonkey : falseMonkey; };
}



/**
 * @brief Helper function.
 * 
 * @param abc  param 1
 * @param 123  param 2
 * 
 * @return something.
 * 
*/
void parseMonkey(const std::vector<std::string> &input, unsigned int i, std::vector<Monkey> &monkeys){
	unsigned int id = std::stoi(input[i].substr(7, input[i].size() - 1 - 7));
	std::function<unsigned long long(unsigned long long)> operation = parseOperation(input[i + 2].substr(13));
	std::function<unsigned int(unsigned long long)> test = parseTest(input[i + 3], input[i + 4], input[i + 5]);
	Monkey m(id, operation, test);

	std::vector<std::string> items = Utils::split(input[i + 1].substr(18), ", ");
	for(const std::string &item : items)
		m.addItem(std::stoi(item));
	
	monkeys.push_back(m);
}


void runRound(std::vector<Monkey> &monkeys){
	for(Monkey &m : monkeys){
		while(m.numItems() != 0){
			unsigned int nextMonkey;
			unsigned long long item = m.throwItem(nextMonkey);
			monkeys[nextMonkey].addItem(item);
		}
	}
}


void partOne(const std::vector<std::string> &input){
	std::vector<Monkey> monkeys;

	unsigned int i = 0;
	while(i < input.size()){
		parseMonkey(input, i, monkeys);
		i += 7;
	}

	for(unsigned int rounds = 0; rounds < 20; ++rounds){
		runRound(monkeys);
	}

	std::sort(monkeys.begin(), monkeys.end());
	std::reverse(monkeys.begin(), monkeys.end());

	unsigned long long monkeyBusiness = monkeys[0].numInspected() * monkeys[1].numInspected();


	std::cout << monkeyBusiness << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	std::vector<Monkey> monkeys;

	unsigned int i = 0;
	while(i < input.size()){
		parseMonkey(input, i, monkeys);
		i += 7;
	}

	for(unsigned int rounds = 1; rounds <= 10000; ++rounds){
		runRound(monkeys);

		if(rounds == 1000){
			for(Monkey m : monkeys){
		std::cout << m.numInspected() << std::endl;
	}
	std::cout << "\n\n";
		}
	}

	std::sort(monkeys.begin(), monkeys.end());
	std::reverse(monkeys.begin(), monkeys.end());

	unsigned long long monkeyBusiness = monkeys[0].numInspected() * monkeys[1].numInspected();


	std::cout << monkeyBusiness << std::endl;
}
