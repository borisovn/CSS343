#ifndef GRAPHM_H
#define GRAPHM_H
#include <iostream>
#include <fstream>
#include <iostream>
#include "nodedata.h"
using namespace std;
//--------------------------  class GraphM  ---------------------------------
//  ADT: GraphM  calcultates Djistra's shortest path algorithm, including
//  recovering  the paths. Reads data from provided data file, and find the 
//  lowest  cost paths and display the cost and path from every node to every
//  other node. Also, dispaly routine that outputs one path detail.
//
// Implementation and assumptions:
//   -- Implement as a Graph by using two damincial arrays
//   -- Implement Djistra's shortes path algorithm
//   -- Implement with following methods: buildgraph, insertEdge,
//      removeEdge, display, displayAll.
//   -- Assumption: insertEdge insrt node with in existing matrix
//                  also, edge can't not contain negative distance
//   -- Assumption: removeEdge can be removed only if the adjacancy
//                  to a node exit in its matrix.
//   -- Assumption: every time user call BuildGraph method,table C and T
//                  have to be empty.
//---------------------------------------------------------------------------
int const MAXNODES1 = 100;                 // constant size for T and C table
class GraphM
{
public:
	GraphM();                                // constractor
	~GraphM();                               // destructor
	void buildGraph(ifstream&);              // buildgraph from the file
	void findShortestPath();                 // Dijkstra's  algorithm 
	bool insertEdge(int from, int to, int dist); // insertedge between 2 node
	bool removeEdge(int from, int to);       // remove edge between 2 nodes
	void display(int from, int to);          // displayedge between 2 nodes
	void displayAll();                       // displayAll info for T table
	
private:
	void resetTable();                      // helper method to reset T table
	void makeEmpty();                       // reset T and C table
	void findPath(int from, int to);        // recover path for shortest dist
	void findData(int from, int to);        // revover data for shortest dist

	int size;                               // hold current size of matrix
	NodeData data[MAXNODES1];               // hold array of data
	int C[MAXNODES1][MAXNODES1];            // hold info for C table
	struct TableType {                      // structure for T table
		bool visited;                       // hold bool visited
		int dist;                           // hold distance      
		int path;                           // hold path
	};
	TableType T[MAXNODES1][MAXNODES1];      // T table

};
#endif