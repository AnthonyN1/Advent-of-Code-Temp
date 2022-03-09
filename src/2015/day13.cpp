/*
	Advent of Code - 2015: Day 13
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../../includes/graph.h"
#include "../../includes/utils.h"


/*
	Parses an input line into a pair of vertices and the directed edge weight between them.
*/
void parseInput(Graph &g, const std::vector<std::string> &parts){
	std::string nameTwo = parts[parts.size() - 1].substr(0, parts[parts.size() - 1].size() - 1);

	// Adds the vertices (names of the two people) to the graph.
	g.addVertex(parts[0]);
	g.addVertex(nameTwo);

	// Determines the edge weight (happiness units).
	long long units = std::stoi(parts[3]);
	if(parts[2] == "lose") units *= -1;

	// Adds the edge (the relationship between the two people) to the graph.
	g.addEdge(parts[0], nameTwo, units);
}

/*
	Calculates the total change in happiness in the graph with a cycle in the order of verts.
*/
long long getChangeInHappiness(const Graph &g, const std::vector<std::string> &verts){
	long long happiness = 0;
	for(unsigned int i = 0; i < verts.size(); ++i){
		// Calculates the change in happiness w.r.t to person on the left.
		if(i == 0) happiness += g.getWeight(verts[i], verts[verts.size() - 1]);
		else happiness += g.getWeight(verts[i], verts[i - 1]);

		// Calculates the change in happiness w.r.t to person on the right.
		if(i == verts.size() - 1) happiness += g.getWeight(verts[i], verts[0]);
		else happiness += g.getWeight(verts[i], verts[i + 1]);
	}

	return happiness;
}


void partOne(const std::vector<std::string> &input){
	Graph g;
	for(const std::string &str : input)
		parseInput(g, Utils::split(str, " "));
	
	// Cycles through all possible permutations (brute-force).
	std::vector<std::string> vertices = g.getVertices();
	std::sort(vertices.begin(), vertices.end());

	long long highest = std::numeric_limits<long long>::min();
	do{
		// Finds the maximum change in happiness.
		highest = std::max(highest, getChangeInHappiness(g, vertices));
	} while(std::next_permutation(vertices.begin(), vertices.end()));


	std::cout << highest << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	Graph g;
	for(const std::string &str : input)
		parseInput(g, Utils::split(str, " "));
	
	// Adds a neutral vertex to the graph (connected with edge weights of 0).
	g.addVertex("Me");

	std::vector<std::string> vertices = g.getVertices();
	for(const std::string &vert : vertices){
		g.addEdge("Me", vert, 0);
		g.addEdge(vert, "Me", 0);
	}
	
	// Cycles through all possible permutations (brute-force).
	vertices = g.getVertices();
	std::sort(vertices.begin(), vertices.end());

	long long highest = std::numeric_limits<long long>::min();
	do{
		// Finds the maximum change in happiness.
		highest = std::max(highest, getChangeInHappiness(g, vertices));
	} while(std::next_permutation(vertices.begin(), vertices.end()));


	std::cout << highest << std::endl;
}
