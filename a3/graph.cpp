#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
#include <time.h>
using namespace std;


/////////////////////////////////////////////////////////
// constructors
/////////////////////////////////////////////////////////

// construct a random graph
template <class T>
Graph<T>::Graph( const vector<T> &vertex_set, bool is_directed )
{
	size = vertex_set.size();
	directed = is_directed;

	// FILL IN
}

/////////////////////////////////////////////////////////
// accessors
/////////////////////////////////////////////////////////

template <class T>
vector<T> Graph<T>::vertices()
{
	vector<T> vertex_set;

	for (vertex_iterator i = begin(); i != end(); i++) {
		vertex_set.push_back(i->first);
	}
	return vertex_set;
}



/////////////////////////////////////////////////////////
// mutators
/////////////////////////////////////////////////////////

// insert edge
template <class T>
void Graph<T>::insert( const T &u, const T &v )
{
	adjacency_list[u].push_back(v);
}



/////////////////////////////////////////////////////////
// predicates
/////////////////////////////////////////////////////////

template <class T>
bool Graph<T>::is_vertex( const T &u ) const
{
	return (adjacency_list.find(u) != end());
}

template <class T>
bool Graph<T>::is_edge( const T &u, const T &v ) const
{
	vertex_iterator i = adjacency_list.find(u);
	if (i == end()) {
		return false;
	}
	assert( i->first == u );

	typedef typename std::vector<T> NeighborList;
	typedef typename NeighborList::const_iterator neighbor_iterator;

	NeighborList neighbors = i->second;
	neighbor_iterator j = find( neighbors.begin(), neighbors.end(), v );
	return (j != neighbors.end()) ? true : false;
}





////////////////////////////////////////////////////////////
// Breadth First Search 
////////////////////////////////////////////////////////////
#define INFINITY	-1
enum COLOR {WHITE, GRAY, BLACK};

template <class T>
struct BFS_Vertex {
	COLOR color;
	int distance;
	T previous;
};


template <class T>
Graph<T> Graph<T>::BFS( const T & start_vertex )
{
	map<T, BFS_Vertex<T> > BFS_Tree;
	Graph<T> outputTree;
	queue<T> BFS_Queue;

	// FILL IN

	return outputTree;
}




////////////////////////////////////////////////////////////
// Depth First Search 
////////////////////////////////////////////////////////////
template <class T>
struct DFS_Vertex {
	COLOR color;
	int discover_time, finish_time;
	T previous;
};


template <class T>
Graph<T> Graph<T>::DFS()
{
	map<T, DFS_Vertex<T> > DFS_Tree;
	Graph<T> outputTree;
	stack<T> DFS_Stack;

	// FILL IN

	return outputTree;	
}


