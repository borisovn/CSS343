#ifndef GRAPHL_B
#define GRAPHL_B
#include <iostream>
#include <fstream>
#include <iostream>
#include <queue>
#include "nodedata.h"
using namespace std;
std::queue<int> my_queue;
int const MAXNODESIZE = 100;
class GraphB {
public:
	GraphB();                             // constractor
	~GraphB();                            // distractor
	void buildGraph(ifstream& infile);    // buildGraph from given file
	void displayAll();                    // display given data
	void bredthFirstSearch();             // bredth first search algorithm

private:
	void bfs(int v);                      // helper method for bredth first search
	int size;                             // hold size
	struct EdgeNode;                      // struct node for linked list
	struct GraphNode {                     // GraphNode struct 
		EdgeNode * headNode;               // head of linked list
		NodeData * data;                   // pointer to the data
		bool visited;                      // dool visited
	};
	GraphNode  graph_array[MAXNODESIZE+1];
	struct EdgeNode {
		EdgeNode* nextEdge;               // pointer to the next node
		int adjGraphNode;                 // data holder for current pointer

	};
	

	
};
#endif 