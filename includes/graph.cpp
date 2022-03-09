/*
	Advent of Code - Graph Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "graph.h"


//==================================================//
//                     Observer                     //
//==================================================//
/*
	Returns a vector of all the vertices in the graph.
*/
std::vector<std::string> Graph::getVertices() const {
	std::vector<std::string> verts;

	std::map<std::string, std::set<std::string>>::const_iterator itr;
	for(itr = adjList_.cbegin(); itr != adjList_.cend(); ++itr)
		verts.push_back(itr->first);
	
	return verts;
}


//==================================================//
//                     Mutators                     //
//==================================================//
/*
	Adds an edge between v1 and v2 with weight weight to the graph.
*/
void Graph::addEdge(const std::string &v1, const std::string &v2, unsigned long long weight){
	adjList_[v1].insert(v2);
	weights_[std::make_pair(v1, v2)] = weight;
}

/*
	Adds a vertex v to the graph.
*/
void Graph::addVertex(const std::string &v){
	if(adjList_.find(v) == adjList_.end())
		adjList_[v] = std::set<std::string>();
}
