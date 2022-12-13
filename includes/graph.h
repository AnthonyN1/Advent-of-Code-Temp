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
 * @brief A directed graph with optional weighted edges.
 * 
 * @tparam V  the type of vertex labels
 * 
*/
template <class V> class Graph{
	public:
		//==================================================//
		//                     Accessors                    //
		//==================================================//
		/**
		 * @return a set of the vertex labels in the graph.
		 * 
		*/
		std::set<V> getVertices() const;

		/**
		 * @param v1  the label of the source vertex
		 * @param v2  the label of the destination vertex
		 * 
		 * @return the weight of the edge between the vertices labeled by v1 and v2.
		 * 
		*/
		long long getWeight(const V &v1, const V &v2) const { return weights_.at(std::make_pair(v1, v2)); }

		/**
		 * @param v1  the label of the source vertex
		 * @param v2  the label of the destination vertex
		 * 
		 * @return true if the graph has an edge from the vertices labeled by v1 and v2, and false otherwise.
		 * 
		*/
		bool hasEdge(const V &v1, const V &v2) const { return adjList_.at(v1).find(v2) != adjList_.at(v1).end(); }

		//==================================================//
		//                     Modifiers                    //
		//==================================================//
		/**
		 * @brief Adds an edge to the graph between two vertices with an optional weight.
		 * 
		 * @param v1  the label of the source vertex
		 * @param v2  the label of the destination vertex
		 * @param w   the edge weight
		 * 
		*/
		void addEdge(const V &v1, const V &v2, long long w=1);

		/**
		 * @brief Adds a vertex to the graph.
		 * 
		 * @param v  the label of the vertex
		 * 
		*/
		void addVertex(const V &v);
	private:
		std::map<V, std::set<V>> adjList_;					/** An adjacency list representation of a mathematical graph. */
		std::map<std::pair<V, V>, long long> weights_;		/** A map of edges to their weights. */
};

#include "graph.hpp"

#endif
