#ifndef GRAPHL_H
#define GRAPHL_H
#include <iostream>
#include <fstream>
#include <iostream>
#include "nodedata.h"
using namespace std;
int const MAXNODES = 100;  // const size of an array
//--------------------------  class GraphL  ---------------------------------
//  ADT: GraphL calculates depth-first algorithm (search alway starts at 
//  node #1).Reads data from provided data file, and find the depth-firts
//  recovery path. Also, display all inforamtion of the current  GraphL.
//
//  Implementation and assumptions:
//  -- Implemenet as Graph by using array and linked list
//  -- Implemenet depth-fist algorithm
//  -- Assumption: the data file has to be correct in order to build 
//     object GraphL. 
//---------------------------------------------------------------------------
class GraphL
{
public:
	GraphL();                      // constractor
	~GraphL();                     // distractor
	void buildGraph(ifstream&);    // buildGrapth from given data
	void depthFirstSearch();       // depthfirstsearch algorithm
	void displayGraph();           // display all info about the graph
private:
	void makeEmpty();              // makeEmpty()
	void dfs(int v);               // helper  method for depthfirstsearch
	
	int size;                      // hold current size
	struct EdgeNode;               // structure of Edge node
	struct GraphNode {
		EdgeNode* edgeHead;        // head of the list
		NodeData* data;            // name of the node
		bool visited;              // bool visited
	};
	GraphNode node_array[MAXNODES + 1]; // graphnode arrat size of 0 to 100
	
	struct EdgeNode {               // sturcture for linked list
		int adjGraphNode;           // int that holds adjacancy 
		EdgeNode* nextEdge;         // next node
	};
};
#endif