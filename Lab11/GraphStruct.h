#ifndef GRAPHSTRUCT
#define GRAPHSTRUCT
#include <iostream>
#include <list>
using namespace std;

class Graph {

	protected:
		int numVertices;
		list<int>* adjLists;
		bool* visited;

	public:
		// constructor
		Graph(int);

		// destructor
		~Graph();

		// prototype functions
		void addEdge(int, int);
		void removeEdge(int, int);
		bool hasEdge(int, int);
		void outEdge(int);
		void inEdge(int);
		void DFS(int);
		void BFS(int);
		void printGraph();

		list<int> getOutEdge(int vertex) {
			return adjLists[vertex];
		}

		list<int> getInEdge(int vertex) {
			list<int> queue;
			list<int> temp;
			list<int> ::iterator it = adjLists->begin();
			for (int i = 0; i < numVertices; i++) {
				list<int>::iterator it;
				for (it = adjLists[i].begin(); it != adjLists[i].end(); ++it) {
					if (*it == vertex) {
						queue.push_back(i);
					}
				}
			}
			return queue;
		}
};

// constructor, initialize the graph
Graph::Graph(int vertices) {

	this->numVertices = vertices;
	adjLists = new list<int>[vertices];
	visited = new bool[vertices];
	
	for (int i = 0; i < vertices; i++) {
		visited[i] = false;
	}
}

// destructor
Graph::~Graph() {
	delete adjLists;
	delete visited;
}

// Add edges
void Graph::addEdge(int src, int dest) {

	if (src < 0 || dest < 0) {
		cout << "Shoudl be positive!" << endl;
		return;
	}
	if (src == dest) {
		cout << "Error" << endl;
		return;
	}
	adjLists[src].push_back(dest);
}

// remove edges
void Graph::removeEdge(int src, int dest) {

	if (src < 0 || dest < 0) {
		cout << "Should be positive!" << endl;
		return;
	}
	
	if (adjLists[src].empty()) {
		cout << "Nothing to remove" << endl << endl;
		return;
	}
	adjLists[src].remove(dest);
}

// a BFS function to check whether d is reachable from s
bool Graph::hasEdge(int s, int d) {
	
	if (s == d) return true; // base case

	list<int> queue;
	// mark the current node and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent vertices of a vertex
	list<int>::iterator it;

	while (!queue.empty()) {

		// dequeue a vertex from queue and print it
		s = queue.front();
		queue.pop_front();

		// get all adjacent vertices of dequeued vertex s
		// if a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (it = adjLists[s].begin(); it != adjLists[s].end(); ++it) {
			// if this adjacent node is the destination node, then return true
			if (*it == d) {
				return true;
			}
			// else continue to do BFS
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
	// if BFS is complete without visiting d
	return false;
}

// return a list of all integers n that edge(m, n) of Edge
void Graph::outEdge(int vertex) {

	list<int>queue = getOutEdge(vertex);
	if (queue.empty()) cout << "Nothing in that vertex!" << endl;
	else {
		cout << "List of elements has " << vertex << " as outEdge: ";
		for (int i : queue) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void Graph::inEdge(int vertex) {

	list<int> queue = getInEdge(vertex);
	if (queue.empty()) cout << "Nothing in that vertex!" << endl;
	else {
		cout << "List of elements has " << vertex << " as inEdge: ";
		list<int> queue = getInEdge(vertex);

		while (!queue.empty()) {
			cout << " " << queue.front();
			queue.pop_front();
		}
		cout << endl;
	}
}

// print out the graph
void Graph::printGraph() {

	for (int i = 0; i < numVertices; i++) {
		cout << "vertex " << i << ": ";
		for (int it : adjLists[i]) {
			if (adjLists[i].empty()) continue;
			cout << it << " -> ";
		}
		cout << endl;
	}
	cout << endl;
}

// DFS algorithm
void Graph::DFS(int vertex) {

	visited[vertex] = true;
	list<int> adjList = adjLists[vertex];

	cout << vertex << " ";

	list<int>::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i) {
		if (!visited[*i]) {
			DFS(*i);
		}
	}
}

// BFS algorithm
void Graph::BFS(int vertex) {

	visited = new bool[vertex];
	for (int i = 0; i < numVertices; i++) {
		visited[i] = false;
	}
	list<int> queue;
	visited[vertex] = true;
	queue.push_back(vertex);

	list<int>::iterator it;

	while (!queue.empty()) {
		int current = queue.front();
		cout << current << " ";
		queue.pop_front();

		for (it = adjLists[current].begin(); it != adjLists[current].end(); ++it) {
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}

#endif // !GRAPHSTRUCT