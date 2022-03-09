/*
	Advent of Code - Graph Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __graph_h_
#define __graph_h_

#include <map>
#include <set>
#include <string>
#include <utility>


class Graph{
	public:
		// Observers
		std::vector<std::string> getVertices() const;
		unsigned long long getWeight(const std::string &v1, const std::string &v2) const { return weights_.at(std::make_pair(v1, v2)); }
		bool hasEdge(const std::string &v1, const std::string &v2) const { return adjList_.at(v1).find(v2) != adjList_.at(v1).end(); }

		// Mutators
		void addEdge(const std::string &v1, const std::string &v2, unsigned long long weight);
		void addVertex(const std::string &v);
	private:
		std::map<std::string, std::set<std::string>> adjList_;
		std::map<std::pair<std::string, std::string>, unsigned long long> weights_;
};

#endif
