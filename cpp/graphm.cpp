#include "graphm.h"
#include "string.h"
#include "limits.h"
#include <iomanip>

////-------------------------------------------------------------------------
//// constractor
GraphM::GraphM() {
	makeEmpty();      // call helper method makeEmpty()
}
////-------------------------------------------------------------------------
//// distructor
GraphM::~GraphM() {
	makeEmpty();      // call helper method makeEmpty()
}
////-------------------------------------------------------------------------
//// makeEmpty()
//// helper method for constractor and distructor methods.
//// Also, used in method buildGraph
//// void type method:
//// resets all data in current Object: C table to infinity
//// T table dist to infinity, T table path to zero, T table visited to false.
void GraphM::makeEmpty(){
	size = 0;  // set size to 0
	// nested for loop, set C and T Table
	// into to initial values
	for (int i = 0; i < MAXNODES1; i++){
		for (int j = 0; j < MAXNODES1; j++){
			C[i][j] = INT_MAX;                // set C table to infinity
			T[i][j].dist = INT_MAX;           // set T table dist to infinity
			T[i][j].path = 0;                 // set T table path to 0
			T[i][j].visited = false;          // set T table visited to false
		}
	}
}

////-------------------------------------------------------------------------
//// BuildGraph()
//// void type method:
//// builds up graph node imfomation and adjacency matrix of edges between
//// each node reading from a data file.
//// assumption: the text file has valid format and valid data. Table C and T
//// have to be empty. 
//// one parameter: refrenses to ifstream. 
void GraphM::buildGraph(ifstream& infile){
	// call helper method makeEmpty()
	// for safty purpose, re-set the data
	// in tables T and C  before reading the file
	makeEmpty();                             // re-set the  data
	//fist line in the data
	infile >> size;                          // set size
	string new_name = "";                    // string that holds node name              
	getline(infile, new_name);               // empty line

	// loop assing names for nodes
	for (int i = 1; i <= size; ++i){
		data[i].setData(infile);            // set node name
	}

	// holds variables for node and its adjacancy and distance
	int from, to, dist;
	// loop reads the file until sees zero 
	while (infile >> from >> to >> dist){
		if (from == 0) break;
		C[from][to] = dist;                 // set C-Table
	}
}
////-------------------------------------------------------------------------
//// findShortesPath()
//// void type method:
//// find the shortest path and distance between every node to every other
//// node in the graph.In other words, updates table T with shortes distnce
//// Based on the provided sudo code
//// and path information
void GraphM::findShortestPath() {
	resetTable();   // re-set table T before stat building it
	for (int source = 1; source <= size; source++) {
		T[source][source].dist = 0;
		T[source][source].visited = true;

		// first waves for my neighbors
		for (int k = 1; k <= size; k++) {
			if (C[source][k] != INT_MAX) {   
				T[source][k].dist = C[source][k];
				T[source][k].path = source;
			}
		}

		int v = 0;  // hold the shortest index
		do {
			// find the shortes distance at this point
			int min = INT_MAX;
			v = 0;
		// find closest child and do second wave
			for (int k = 1; k <= size; k++) {
				if (!T[source][k].visited && (C[source][k] < min)) {
					min = C[source][k];
					v = k;
				}
			}
			if (v == 0) break;  // stop the loop

			T[source][v].visited = true;  // mark visited

			for (int w = 1; w <= size; ++w){
				if (T[source][w].visited) continue;
				if (C[v][w] == INT_MAX) continue;
				if (v == w) continue;
				if (T[source][w].dist > T[source][v].dist + C[v][w]){
					T[source][w].dist = T[source][v].dist + C[v][w];
					T[source][w].path = v;
				}
			}

		} while (v != 0); // exit the loop
	}
}

////-------------------------------------------------------------------------
//// isertEdge()
//// void type method:
//// insert an edge into graph between two given nodes in T table
//// assumption node (from) should not be bigger than current size or less
//// than 1. Similary, for adjacency (to) same conditions as for (from).
//// distance (dist) can not be nagative
//// three parameters: int (from) int (to) int (dist)
bool GraphM::insertEdge(int from, int to, int dist) {
	//check for precondition
	if (from > size || from < 1) return false;
	if (to > size || to < 1) return false;
	if (dist != 0 && from == to) return false;
	if (dist < 0) return false;
	C[from][to] = dist;   // set edge with distance in C Table 
	findShortestPath();   // re-calculate T Table
	return true;
}

////-------------------------------------------------------------------------
//// removeEdge()
//// void type method:
//// remove an edge between two given nodes in T table.
//// assumption: the remove edge has to exist in T table matrix.
//// two parameters: int (from) int (to).
bool GraphM::removeEdge(int from, int to) {
	// check if edge exist within extiting T table
	if (from > size || from < 1) return false;
	if (to > size || to < 1) return false;
	// check if  the edge  already doesn't exist in current T table
	if (C[from][to] == INT_MAX) return true;
	C[from][to] = INT_MAX;        // remove edge from C table  
	findShortestPath();           // re-calculate T Table
	return true;
}

////-------------------------------------------------------------------------
//// resetTable()
//// helper method for insertEdge and removeEdge
//// arraise all infromtaion from T table
void GraphM::resetTable() {
	// nested for loop to re-set data in T table
	for (int i = 0; i < MAXNODES1; i++) {
		for (int j = 0; j < MAXNODES1; j++) {
			T[i][j].dist = INT_MAX;              // set dist to infinity 
			T[i][j].path = 0;                    // set path to zero
			T[i][j].visited = false;             // set visited to false
		}
	}
}

////-------------------------------------------------------------------------
//// displayAll()
//// void type method:
//// uses cout to demonstrate that the the algorithm works properly.
//// displays T table: description of the node (name), from node, to node,
//// Dijkstra's algorithm, and recover path for Dijkstra's algorithm.
void GraphM::displayAll() {
    // print  header of the discription
	cout << "Description" << setw(20) << "From node" << setw(10) << "To node"
		 << setw(14) << "Dijkstra's" << setw(7) << "Path" << endl;
	
	// neasted for loop to print the all data
	for (int from = 1; from <= size; from++) {
		cout << data[from] << endl;          // print the name of the node
		for (int to = 1; to <= size; to++) {
			// skip  from node to node Ex: 1 to 1 or 2 to 2
			if (T[from][to].dist != 0) {      
				cout << setw(27) << from;                  // print from
				cout << setw(10) << to;                    // print to
				// check if the edge has not adjancancy nodes
				if (T[from][to].dist == INT_MAX) {
					cout << setw(12) << "----" << endl;    // zero distance
				}
				// else, print distance and path for an edge
				else {
					cout << setw(12) << T[from][to].dist; // print distance
					cout << setw(10);                     // set some space
					//call helper method findPath()
					findPath(from, to);
					cout << endl;                         //end of edge info

				}
			}
		}
	}
}

////-------------------------------------------------------------------------
//// display()
//// void type method:
//// uses cout to demonstrate that the the algorithm works properly.
//// displays given edge from node to its adjancent node
//// assumption: edge has to exist in T table. In other words,
//// node from to node to has to be no bigger or less than size
//// two parameter: int (from) int (to)
void GraphM::display(int from, int to) {
	//check if edge exist in T Table
	if ((from > size || from < 0) || (to > size || to < 0)) {
		cout << setw(7) << from << setw(7) << to;
		// print ---  to indicate invalid input  
		cout << setw(15) << "----" << endl;
		return;
	}
	// print  from node and to node
	cout << setw(7) << from << setw(7) << to;    
	// check if adge has a adjacency node
	// print all info for a edge
	if (T[from][to].dist != INT_MAX) {
		cout << setw(12) << T[from][to].dist << setw(15); // print distance
		// call helper method findPath()
		findPath(from, to);                               // find path
		cout << endl;                                     // add new line
		// call helper method findData()
		findData(from, to);                               // find data
	}
	// no adjacency for edge 
	else {
		cout << setw(15) << "----" << endl;
	}
	cout << endl;
}

////-------------------------------------------------------------------------
//// findData()
//// helper method for display()
//// void type method:
//// recursivly find  the data for given edge distance
//// two parameters: int from int to
void GraphM::findData(int from, int to) {
	// base case01:
	// no such data exist
	if (T[from][to].dist == INT_MAX) {
		return;
	}
	// base case02:
	// begining of the data
	if (from == to) {
		cout << data[to] << endl;          // print the data 
		return;
	}
	int point = to;                        // hold the data
	// recursive call 
	findData(from, to = T[from][to].path);
	cout << data[point] << endl;           // print the data   
}

////-------------------------------------------------------------------------
//// findPath()
//// helper method for display() and displayAll()
//// void type method:
//// recursivly find the path for given edge 
void GraphM::findPath(int from, int to) {
	// base case01:
	// no sush path exist
	if (T[from][to].dist == INT_MAX) {
		return;
	}
	// base case02:
	// begining of the path
	if (from == to) {
		cout << to << " ";                  // print path
		return;
	}
	int point = to;                         // hold path
	findPath(from, to = T[from][to].path);
	cout << point << " ";                   // print path

}

////-------------------------------------------------------------------------