/*
	Advent of Code - Graph Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <map>
#include <set>
#include <utility>


template <class V> std::set<V> Graph<V>::getVertices() const {
	std::set<V> verts;

	typename std::map<V, std::set<V>>::const_iterator itr;
	for(itr = adjList_.cbegin(); itr != adjList_.cend(); ++itr)
		verts.insert(itr->first);
	
	return verts;
}


template <class V> void Graph<V>::addEdge(const V &v1, const V &v2, long long w){
	adjList_[v1].insert(v2);
	weights_[std::make_pair(v1, v2)] = w;
}

template <class V> void Graph<V>::addVertex(const V &v){
	if(adjList_.find(v) == adjList_.end())
		adjList_[v] = std::set<V>();
}
