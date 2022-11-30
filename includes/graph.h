/*
	Advent of Code - Graph Header
	Author: Anthony Nool (AnthonyN1)
*/

#ifndef __graph_h_
#define __graph_h_

#include <map>
#include <set>
#include <utility>


/**
 * @brief A directed Graph with optional weighted edges.
 * 
 * @tparam V  the type of vertex labels
 * 
*/
template <class V> class Graph{
	public:
		// Accessors
		std::set<V> getVertices() const;
		long long getWeight(const V &v1, const V &v2) const { return weights_.at(std::make_pair(v1, v2)); }
		bool hasEdge(const V &v1, const V &v2) const { return adjList_.at(v1).find(v2) != adjList_.at(v1).end(); }

		// Modifiers
		void addEdge(const V &v1, const V &v2, long long weight=1);
		void addVertex(const V &v);
	private:
		std::map<V, std::set<V>> adjList_;
		std::map<std::pair<V, V>, long long> weights_;
};

#include "graph.hpp"

#endif
