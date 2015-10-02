#include "graphb.h"
#include "string.h"
#include "limits.h"
#include <iomanip>
//std::queue<int> my_queue;

////-------------------------------------------------------------------------
//// constractor
//// ...
GraphB::GraphB(){
	for (int i = 0; i <= MAXNODESIZE; i++) {
		graph_array[i].data = NULL;
		graph_array[i].headNode = NULL;
		graph_array[i].visited = false;
	}
	size = 0;
}
////-------------------------------------------------------------------------
//// distractor
//// ...
GraphB::~GraphB() {

	for (int i = 0; i <= size; i++) {
		delete graph_array[i].data;
		graph_array[i].visited = false;
		// check if array at index i contains linked list
		if (graph_array[i].headNode != NULL) {		
			EdgeNode* delete_node = graph_array[i].headNode; // hold the head		
			while (delete_node != NULL) {			
				graph_array[i].headNode = graph_array[i].headNode->nextEdge;  // move head to next node
				delete delete_node;     // delete node
				delete_node = NULL;     // assing it to NUll
				delete_node = graph_array[i].headNode; // prepare node for next delete
			}
		}
	}

}

////-------------------------------------------------------------------------
//// buildGraph()
//// void type  mehtod:
//// builds graph from given data file
//// assumption: data file contains right format for a graphB
//// one parameter: ifstream & infile
void GraphB::buildGraph(ifstream& infile) {
	// insert size
	infile >> size;
	// for first call hold an empty line
	//  after in loop insert name of the nodes
	string new_name = ""; 
	getline(infile, new_name);
	// loop that inserts name of the data into array
	for (int i = 1; i <= size; i++) {
		getline(infile, new_name);
		// need to check if direct allocation for data is allowed
		// altenative scenario: create an object
		// NodeData using copy constractor with parameter new_name
		// Ex: NodeData * tmp = new NodeData(new_name); 
		// graph_array[i].data = tmp; ???
		cout << "check string new_name: " << new_name << endl;
		// Direct assing to data
		graph_array[i].data = new NodeData(new_name);

	}
	// integers that hold edge from one node to its adjacancy node
	int from, to;
	while (infile >> from >> to) {
		if (from == 0) break;  // end of the object info
		//  assignt first node in the list
		if (graph_array[from].headNode == NULL) {
			EdgeNode *  ptr = new EdgeNode;
			ptr->adjGraphNode = to;
			graph_array[from].headNode = ptr;
			graph_array[from].headNode->nextEdge = NULL;
		}
		else if( graph_array[from].headNode->adjGraphNode > to) {
			EdgeNode *  ptr = new EdgeNode;
			ptr->adjGraphNode = to;
			ptr->nextEdge = graph_array[from].headNode;
			graph_array[from].headNode = ptr;
			//graph_array[from].headNode->nextEdge = NULL;
		}
        // need to insert in increasing order
		// current seeting:
		// latest insertion goes to the front
		else {
			EdgeNode * ptr = new EdgeNode;                              // new node
			ptr->adjGraphNode = to;                                     // assing the adjcancy
			
			EdgeNode * priv = graph_array[from].headNode;               // hold head
			EdgeNode * current = graph_array[from].headNode->nextEdge;  // hold next node after head
			
			// loop until find right place for prt 
			// do it until reach the end of the linked list or ptr has to be less than current
			while (current != NULL && current->adjGraphNode < ptr->adjGraphNode) {
				priv = current; // move priv to current
				current = current->nextEdge; // move current to next node
			}
			// insert ptr between priv and current
			ptr->nextEdge = current;
			priv->nextEdge = ptr;
		}
	}
}

////-------------------------------------------------------------------------
//// displayAll()
//// void type method:
//// displays info of the GraphB
void  GraphB::displayAll() {
	// check if GraphB contains anything
	if (size == 0) { return; }
	// cout to print inital inforamtion of the list
	cout << "GraphB info:" << endl;
	cout << "Name:    " << "linked list " << endl;
	for (int i = 1; i <= size; i++) {
		cout  << " " << *graph_array[i].data << endl;
		if (graph_array[i].headNode != NULL) {
			EdgeNode * current = graph_array[i].headNode;  // pointer to the head
			while (current != NULL)   { // loop unitl reach end of the linked list
				cout << " " << current->adjGraphNode;
				current = current->nextEdge;
			}
		 }
		cout << endl;
	}
}
////-------------------------------------------------------------------------
//// bredthFirstSearch()
//// void type mehtod:
//// displays bredthFirstSearch algorithm
void GraphB::bredthFirstSearch() {
	for (int v = 1; v <= size; v++) {
		if (!graph_array[v].visited)   {   // check if node has been visited
			// call helper method bfs()
		}
	}
}
////-------------------------------------------------------------------------
//// dfs()
//// helper method for bredthFirstSearch
//// recursivly builds bredth first search algorithm and print it
	//void GraphB::bfs(int v) {
	//	// mark v visited
	//	graph_array[v].visited = true;
	//	cout << v;
	//	my_queue.push(v);
	//	EdgeNode* node = graph_array[v].headNode;
	//	for (int i = 1; i <= size; i++) {
	//		if (!graph_array[i].visited) {
	//			graph_array[i].visited = true;
	//			my_queue.pop;
	//		}
	//	}
	//}