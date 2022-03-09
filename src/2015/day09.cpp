/*
	Advent of Code - 2015: Day 09
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
	Parses an input line into a pair of vertices and the undirected edge weight between them.
*/
void parseInput(Graph &g, const std::string &str){
	std::vector<std::string> parts = Utils::split(str, " = ");
	std::vector<std::string> verts = Utils::split(parts[0], " to ");

	unsigned long long weight = std::stoi(parts[1]);

	// Adds the vertices to the graph.
	g.addVertex(verts[0]);
	g.addVertex(verts[1]);

	// Adds the two directed edges (one undirected edge) to the graph.
	g.addEdge(verts[0], verts[1], weight);
	g.addEdge(verts[1], verts[0], weight);
}

/*
	Returns the cost of the path of g in order of verts.
	Returns errorVal if the path isn't possible.
*/
unsigned long long getPathCost(const Graph &g, const std::vector<std::string> &verts, unsigned long long errorVal){
	unsigned long long cost = 0;
	for(unsigned int i = 0; i < verts.size() - 1; ++i){
		if(g.hasEdge(verts[i], verts[i + 1])){
			cost += g.getWeight(verts[i], verts[i + 1]);
		} else{
			return errorVal;
		}
	}

	return cost;
}


void partOne(const std::vector<std::string> &input){
	Graph g;
	for(const std::string &str : input)
		parseInput(g, str);
	
	// Variation of Traveling Salesman Problem (NP-Complete).
	// Cycle through all possible permutations (brute-force).
	std::vector<std::string> vertices = g.getVertices();
	std::sort(vertices.begin(), vertices.end());

	unsigned long long lowest = std::numeric_limits<unsigned long long>::max();
	do{
		// Finds the minimum cost path.
		lowest = std::min(lowest, getPathCost(g, vertices, std::numeric_limits<unsigned long long>::max()));
	} while(std::next_permutation(vertices.begin(), vertices.end()));


	std::cout << lowest << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	Graph g;
	for(const std::string &str : input)
		parseInput(g, str);
	
	// Variation of Traveling Salesman Problem (NP-Complete).
	// Cycle through all possible permutations (brute-force).
	std::vector<std::string> vertices = g.getVertices();
	std::sort(vertices.begin(), vertices.end());

	unsigned long long highest = 0;
	do{
		// Finds the maximum cost path.
		highest = std::max(highest, getPathCost(g, vertices, 0));
	} while(std::next_permutation(vertices.begin(), vertices.end()));


	std::cout << highest << std::endl;
}
