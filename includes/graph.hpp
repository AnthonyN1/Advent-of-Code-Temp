/*
	Advent of Code - Graph Implementation
	Author: Anthony Nool (AnthonyN1)
*/

#include <map>
#include <queue>
#include <set>
#include <utility>


template <class V> std::map<V, unsigned int> Graph<V>::bfs(const V &start) const {
	// Initializes the map associating vertex labels with distances from the start vertex.
	std::map<V, unsigned int> distances;
	distances[start] = 0;

	// Keeps a queue of vertex labels to process.
	std::queue<V> toSee;
	toSee.push(start);

	while(!toSee.empty()){
		V currVertex = toSee.front();
		toSee.pop();

		unsigned int currDistance = distances[currVertex];

		for(const V &adjacent : adjList_.at(currVertex)){
			if(distances.find(adjacent) == distances.end()){
				distances[adjacent] = currDistance + 1;
				toSee.push(adjacent);
			}
		}
	}

	return distances;
}


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
