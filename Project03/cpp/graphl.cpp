#include "graphl.h"
#include "string.h"
#include "limits.h"
#include "nodedata.h"
#include <iomanip>

////-------------------------------------------------------------------------
//// constracotor
GraphL::GraphL()  {
	// initialize the object
	size = 0;
	for (int i = 0; i <= MAXNODES; ++i){
		node_array[i].visited = false;
		node_array[i].edgeHead = NULL;
		node_array[i].data = NULL;
	}
}

////-------------------------------------------------------------------------
//// distractor
GraphL::~GraphL() {
	makeEmpty();
}

////-------------------------------------------------------------------------
//// makeEmpty()
//// helper method for distractor
//// void type method:
//// delete current object
void GraphL::makeEmpty()  {
	// delete up to size of an array
	for (int x = 1; x <= size; ++x) {
		
		node_array[x].visited = false;           // set false
		delete node_array[x].data;               // delete name of edge
		node_array[x].data = NULL;               
		
		// check if index contains linked list
		if (node_array[x].edgeHead != NULL) {
			EdgeNode* del = node_array[x].edgeHead;  // hold head
			while (del != NULL) {
				// moved head
				node_array[x].edgeHead = node_array[x].edgeHead->nextEdge;
				delete del;  // delete node
				del = NULL;  
				del = node_array[x].edgeHead; // next node to delete
			}
		}
	}
}

////-------------------------------------------------------------------------
//// BuildGraph()
//// void type method:
//// builds up graph node information and adjacency list of 
//// edges between each node reading from a data file
//// one parameter: ifstream & infile
void GraphL::buildGraph(ifstream& infile){
	infile >> size;                            // initialaze size
	string new_name = "";                      // initialaze string
	getline(infile, new_name);                 // empty line
	//loop to insert name of edges (data)
	for (int i = 1; i <= size; ++i){
		getline(infile, new_name);            
		NodeData* tmp = new NodeData(new_name); // allocated new object
		node_array[i].data = tmp;               // insert object into array
	}
	int from, to;                         // int for node and its adjacancy
	// loop to fill up the linked list
	while (infile >> from >> to) {
		if (from == 0) break;             // end of the filing object data
		// first node at index [from]
		if (node_array[from].edgeHead == NULL) {
			EdgeNode* node = new EdgeNode;     // allocated new node
			node->adjGraphNode = to;           // insert adjacancy
			node_array[from].edgeHead = node;  // point to the head
			node_array[from].edgeHead->nextEdge = NULL;
		}
		// more than one node at index [from]
		else {
			EdgeNode* node = new EdgeNode;    // allocated new node
			node->adjGraphNode = to;          // insert adjacancy
			node->nextEdge = node_array[from].edgeHead;  // repointered
			node_array[from].edgeHead = node;  // assing as new head
		}
	}

}

////-------------------------------------------------------------------------
//// depthFirstSearch()
//// void type of  method:
//// Makes a depth-first search and displays each node in depth-first order 
//// Based on provided sudo code
void GraphL::depthFirstSearch()  {
	cout << "Depth-fisrt ordering:";  // print the discription
	// loop until the end of the size
	for (int v = 1; v <= size; ++v) { 
		if (!node_array[v].visited)   // check if node has been visited
			dfs(v);                   // call helper method dfs()
	}
	cout << endl;                    // end of the discription
}

////-------------------------------------------------------------------------
//// dfs()
//// helper method for depthFirstSearch()
//// void type  method:
//// recurcivly finds the depthFirstSearch by
//// passing the adjecancy graph node
//// Based on provided sudo code
void GraphL::dfs(int v) {
	
	cout << setw(2) << v;                 // print node
	node_array[v].visited = true;         // mark visited
	EdgeNode* current = node_array[v].edgeHead; // pointer to the head
	
	while (current != NULL) {             // loop up to end of linked list
		// check if array at index of node hasn't been visited
		if (!node_array[current->adjGraphNode].visited) {
			dfs(current->adjGraphNode);   // recursive call
		}
		current = current->nextEdge;      // move pointer on next node
	}
}

////-------------------------------------------------------------------------
//// displayGraph()
//// void type method:
//// Displays each node information and edge in the graph
void GraphL::displayGraph()  {
	
	cout << "Graph:" << endl;    // initial discrription 
	// loop to print all info of the array 
	for (int i = 1; i <= size; ++i) {
		// print index and name of the node
		cout << "Node" << i << "      " << *node_array[i].data << endl;
		// diclear node that points to head
		EdgeNode* current = node_array[i].edgeHead;
		// check if at current index array has linked list
		while (current != NULL) {   // print linked list if exist
			cout << setw(7) << "edge " << i << 
		    setw(2) << current->adjGraphNode << endl;
			current = current->nextEdge;  // moved to next node
		}
	}

}

////-------------------------------------------------------------------------