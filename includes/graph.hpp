/*
	Advent of Code - Graph Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <map>
#include <set>
#include <utility>


//==================================================//
//                     Accessors                    //
//==================================================//
/**
 * @return a collection of the vertex labels in the graph.
 * 
*/
template <class V> std::set<V> Graph<V>::getVertices() const {
	std::set<V> verts;

	typename std::map<V, std::set<V>>::const_iterator itr;
	for(itr = adjList_.cbegin(); itr != adjList_.cend(); ++itr)
		verts.insert(itr->first);
	
	return verts;
}


//==================================================//
//                     Modifiers                    //
//==================================================//
/**
 * @brief Adds an edge from v1 to v2 with a specified weight to the graph.
 * 
 * @param v1      the label of the source vertex
 * @param v2      the label of the destination vertex
 * @param weight  the edge weight
 * 
*/
template <class V> void Graph<V>::addEdge(const V &v1, const V &v2, long long weight){
	adjList_[v1].insert(v2);
	weights_[std::make_pair(v1, v2)] = weight;
}

/**
 * @brief Adds a vertex to the graph.
 * 
 * @param v  the label of the vertex
 * 
*/
template <class V> void Graph<V>::addVertex(const V &v){
	if(adjList_.find(v) == adjList_.end())
		adjList_[v] = std::set<V>();
}
