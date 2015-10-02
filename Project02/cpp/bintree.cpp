////--------------------------------------------------------------------------
//// Start of bintree.cpp
#include "bintree.h"
////--------------------------------------------------------------------------
//// BinTree()
//// default constractor
//// sets root to NULL
BinTree::BinTree(){
	root = NULL;
}

////--------------------------------------------------------------------------
//// BinTree()
//// copy constracotr
BinTree::BinTree(const BinTree& copy) {
	// call helper method copyBinTreeHelper()
	copyBinTreeHelper(copy.root, root);
}

////--------------------------------------------------------------------------
//// ccopyBinTreeHelper()
//// helper for copy constractor
//// void type method:
//// makes a deep copy of each node of BinTree to a current BinTree
//// two parameters: BinTree root(copy_node), and current root(new_node)
void BinTree::copyBinTreeHelper(Node *copy_node, Node*& new_node){
	// check for valid condtion
	if (copy_node == NULL){ new_node = NULL; }
	// continue fills up the BinTree
	else{
		new_node = new Node;                     // allocating new Node;
		new_node->left = new_node->right = NULL; // set left and right to NULL
		// making a deep coppy of copy_node->data into 
		// new_node->data using NodeData's copy constractor
		new_node->data = new NodeData(*copy_node->data); // deep copy
		// make a recursive calls
		copyBinTreeHelper(copy_node->left, new_node->left);   // left nodes
		copyBinTreeHelper(copy_node->right, new_node->right); // right nodes
	}
}

////--------------------------------------------------------------------------
//// ~BinTree()
//// destructor
BinTree::~BinTree(){
	// check if BinTree is already empty
	if (isEmpty()) { return; }
	// call method makeEmpty()
	makeEmpty();
}

////--------------------------------------------------------------------------
//// makeEmpty()
//// void type method:
//// deletes existed BinTree
void BinTree::makeEmpty(){
	// call helper method makeEmptyHelper()
	makeEmptyHelper(root);
}

////--------------------------------------------------------------------------
//// makeEmptyHelper()
//// helper method for makeEmpty()
//// void type method:
//// recursivly deletes data and nodes of Bintree
//// one parameter: pointer (*) refrences (&) to a node
void BinTree::makeEmptyHelper(Node* & node) {
	//base case: node  points to NULL
	if (node == NULL) { return; }       // return if node == NULL
	// make recursive calls
	makeEmptyHelper(node->left);        // left node 
	makeEmptyHelper(node->right);       // right node

	delete node->data;                  // delete data
	node->data = NULL;                  // set data to NULL
	delete node;                        // delte root       
	node = NULL;                        // set root to NULL
}

////--------------------------------------------------------------------------
//// =operator()
//// BinTree obj type method: 
//// assigns current BiNTree to passed BinTree
//// one parameter: const refrences to object type of BinTree
BinTree& BinTree::operator=(const BinTree &  rhs)  {
	if (this == &rhs) { return *this; }        // check if BinTree are equal
	if (!isEmpty()) { makeEmptyHelper(root); } // delete current tree
	// recursive call helper method copyBinTreeHelper()
	// the method is also used in copy constractor
	copyBinTreeHelper(rhs.root, root);      // recurrcive call to copy BinTree
	return *this;                           // return current BinTree
}

////--------------------------------------------------------------------------
//// isEmpty()
//// bool type method:
//// checks if BinTree is empty or not
//// checks if root is NULL
bool  BinTree::isEmpty() const {
	return (root == NULL);
}

////--------------------------------------------------------------------------
//// operator==()
//// bool type method:
//// checks if current BinTree is equal to the passed BinTree
//// one parameter: const refrences to object type of BinTree
bool BinTree::operator==(const BinTree& rhs) const {
	// call helper method isEqualHelper()
	return isEqualHelper(rhs.root, root);
}

////--------------------------------------------------------------------------
//// operator!=()
//// bool type method:
//// checks if current BinTree is not equal the passed BinTree
//// one parameter: const refrences  to object type of BinTree
bool BinTree::operator!=(const BinTree & rhs) const {
	// call helper method isEqualHelper()
	return !isEqualHelper(rhs.root, root);
}
////--------------------------------------------------------------------------
//// isEqualHelper()
//// helper method for operator==() and operator!=()
//// bool type method:
//// traces two BinTrees if they both contain same
//// elements with same data and  they both has identical structure
//// two parameters: Node pointers rhs_node(passed node)
//// and my_node(root).
bool BinTree::isEqualHelper(Node* rhs_node, Node* my_node) const {
	// base case 01:
	// check if both nodes are null, get to buttom of tree
	if (rhs_node == NULL && my_node == NULL) { return true; }
	// base case 02:
	// check if just one node is null while another is not,
	// one tree is bigger than another
	if (rhs_node == NULL || my_node == NULL) { return false; }
	// base case 03:
	//check if two datas are not equal, trees are not equal
	if (*rhs_node->data != *my_node->data) { return false; }

	// recursive call on the left sides of the trees
	bool check = isEqualHelper(rhs_node->left, my_node->left);// allocate bool 
	if (!check) { return false; }  // if left sides are not equal return false
	// recursive call on the right sides of the trees
	check = isEqualHelper(rhs_node->right, my_node->right);  // reassign check
	return check;                                            // return check
}


////--------------------------------------------------------------------------
//// getHeight()
//// integer type function:
//// return height of given data
//// one parameter: const refrences to a object NodeData (given_data)
int BinTree::getHeight(const NodeData& given_data) {
	// call helper method retriveTreeElement()
	return retriveBinTreeElement(root, given_data);
}

////--------------------------------------------------------------------------
//// retriveBinTreeElement()
//// helper method for getHeight()
//// integer type method:
//// recursevly finds location of the element in the Tree
//// two parameters: pointer to node (root)
//// and references to NodeData (given_data)
int BinTree::retriveBinTreeElement(Node* node, const NodeData& given_data) {
	// base case 01:
	// node is NULL (reach buttom of tree)
	if (node == NULL) { return 0; }
	// base case 02:
	// given data exist in the BinTree
	if (*node->data == given_data) {
		// call helper method getTreeHeight()
		return getTreeHeight(node);
	}
	// recursive call on the left side of the tree
	int result = retriveBinTreeElement(node->left, given_data); // left
	// check if data was on the left side
	if (result == 0) {
		// if the data wasn't one the left check right side (result != 0)
		// recursive call on the right side of the tree
		result = retriveBinTreeElement(node->right, given_data); //right
	}
	return result; //return result
}

////--------------------------------------------------------------------------
//// bstreeToArray()
//// helper method for retriveBinTreeElement()
//// integer type fucntion:
//// counts the leafs of the given root from
//// left and right sides. return the biger leaf
//// one parameter: pointer to a node (node)
int BinTree::getTreeHeight(Node* node) {
	// base case 01:
	// reach the buttom of the BinTree
	if (node == NULL) { return 0; }
	// recurisve call on the left side of the tree
	int left = getTreeHeight(node->left);  // count leafs on the left subTree
	// recurisve call on the right side of the tree
	int right = getTreeHeight(node->right);// count leafs on the right subTree
	// check if Tree has more left leafs
	if (left > right) {
		return left + 1; // return number of nodes on the left subtree
	}
	// check if Tree has more right leafs 
	else {
		return right + 1; // return number of nodes on the right subtree
	}
}
////--------------------------------------------------------------------------
//// bstreeToArray()
//// void type method:
//// converts BinTree into array of increasing order
//// assumes size of array up to 100 and leaves empty tree
//// one parameter: static array type of NodeData
void BinTree::bstreeToArray(NodeData* new_array[]) {
	int index = -1;                                // count the index of array
	// call helper method (bstreeToArrayHelper()
	bstreeToArrayHelper(root, new_array, index);
	makeEmpty();                                   // distroy empty tree
}

////--------------------------------------------------------------------------
//// bstreeToArrayHelper()
//// helper method for bstreeToArray()
//// void type method:
//// converts BinTre into  sorted array using indroder traversel of the tree
//// pointers change from BinTree nodes to array indexes
//// three parameter: pointer refrenses to a node (root), array type 
//// of NodeData (new_array), int referenses to index (index of array).
void BinTree::bstreeToArrayHelper(Node*& node, NodeData* new_array[], int& index) {
	// base case:
	if (node == NULL) return; // end of the leaf
	// recurisve call on the left side of the tree
	bstreeToArrayHelper(node->left, new_array, index); // left
	++index;                        // increase index
	new_array[index] = node->data; // point array at index to node->data
	node->data = NULL;             // direfrences node->data to NULL
	// recurisve call on the right side of the tree
	bstreeToArrayHelper(node->right, new_array, index); // right
}

////--------------------------------------------------------------------------
//// arrayToBSTree()
//// void type of method:
//// converts array of NodeData into  balanced BinarySearchTree
//// assumes that BinTree is empty before taking arrays' objects
//// one parameter: array type of NodeData
void BinTree::arrayToBSTree(NodeData* input_array[]) {
	makeEmpty();                                        // clean tree
	int length = -1;                                    // lenght of the array
	// while loop that difines the actual lenght of the array
	while (input_array[++length] != NULL) {};
	// if array contains elements, convert array to BSTree
	if (length > 0) {
		// call helper method arrayToBSTreeHelper()
		arrayToBSTreeHelper(root, input_array, 0, length - 1);
	}
}
////--------------------------------------------------------------------------
//// arrayToBSTreeHelper()
//// helper method for arrayToBSTree()
//// void type method:
//// build Balanced BinTree from a sorted array of NodeData leaving the array
//// filled with NULLs. The roor is always  mid = min + (max-min) / 2 
//// min is index 0, higth is lenght of array
//// four parameters: pointer to a refrenses node (root), 
//// array of NodeData's, int min (array[0]), int max = lenght of the array
void BinTree::arrayToBSTreeHelper(Node*& node, NodeData* input_array[], int min, int max) {
	// base case:
	// min goes over the max 
	if (min > max) return;
	// find the middle or the array
	int middle = min + (max - min) / 2;      // find mid of array  
	Node* tmp_node = new Node;               // new tmp_node
	tmp_node->left = tmp_node->right = NULL; // set left and right to null
	// point tmp_node.data to array[middle]
	tmp_node->data = input_array[middle];
	// direfcenses the array[middle]= NULL
	input_array[middle] = NULL;              //set array[middle] to null              
	node = tmp_node;                         // point node to a tmp_node

	// recurisve call on the left and right sides of the tree
	arrayToBSTreeHelper(node->left, input_array, min, middle - 1); // left
	arrayToBSTreeHelper(node->right, input_array, middle + 1, max);// right
}

////--------------------------------------------------------------------------
//// operator<<()
//// ostream type method:
//// overload << to display the BinTree in inorder traversal
//// two paraeters: ostream refrenses, const objectBintTree refrences
ostream& operator<<(ostream &output, const BinTree &tree) {
	// call helper method inorderDisplay()
	tree.inorderDisplay(tree.root, output);
	// add new line after printing the tree
	output << endl;
	return output;
}

////--------------------------------------------------------------------------
//// inorderDisplay()
//// helper method for operator<<()
//// void type method:
//// displays the BinTree in inorder traversal
//// two parameters: pointer node(root), ostream refrenses(output)
void BinTree::inorderDisplay(Node* node, ostream& output) const {
	//based case:
	//rich end of the tree
	if (node == NULL) { return; }
	// recurisve call on the left and right sides of the tree
	inorderDisplay(node->left, output);  // left 
	output << " " << *node->data;        // overload output
	inorderDisplay(node->right, output); // right
}

////--------------------------------------------------------------------------
//// retrive()
//// bool type method:
//// finds if given object contains in the tree
//// reports true if object is tree 
//// reports false if object is not in the tree
//// assings found element to provided refrenses of NodeData(second parameter)
//// two parameters: const refrenses to a NodeData,(find_data),
//// pointer refresnses to NodeData (input_data)
bool BinTree::retrieve(const NodeData& find_data, NodeData*& input_data) const {
	// call helper method retriveBSTreeElemenet()
	return retriveBSTreeElement(root, find_data, input_data);
}

////--------------------------------------------------------------------------
//// retriveBSTreeElement()
//// helper method for retrive()
//// bool type method:
//// finds if given object contains in the tree
//// makes binary traversal search for given object
//// three parameters: pointer to a node (root), const refrecnese to NodeData
//// (find_data), Pointer refrences to NodeData (input_data)
bool BinTree::retriveBSTreeElement(Node* node, const NodeData& find_data, NodeData*& input_data) const {
	// base case 01:
	//check if root is null
	if (node == NULL) {
		input_data = NULL;        // refrenses input_data
		return false;
	}
	// base case 02:
	// check if root contains the same data
	if (*node->data == find_data) {
		input_data = node->data;  // refrenses input_data
		return true;
	}
	// do binary search:
	// if find_data is more than node->data go left
	else if (*node->data > find_data){
		return retriveBSTreeElement(node->left, find_data, input_data);
	}
	// if find data is less than node->data go right
	else {
		return retriveBSTreeElement(node->right, find_data, input_data);
	}
}
////--------------------------------------------------------------------------
//// insert()
//// bool type method:
//// insert NodeData into a tree
//// one parameter: pointer to object NodeData (dapaptr)
bool BinTree::insert(NodeData* dataptr) {

	Node* ptr = new Node;
	if (ptr == NULL) return false;            // out of memory
	ptr->data = dataptr;
	ptr->left = ptr->right = NULL;
	if (isEmpty()) {
		root = ptr;
		return true;
	}

	Node* current = root;                           // walking pointer
	bool inserted = false;                          // whether inserted yet

	// if item is less than current item, insert in left subtree,
	// otherwise insert in right subtree
	while (!inserted) {
		// no duplicates allowed
		if (*ptr->data == *current->data) {
			delete ptr->data;
			ptr->data = NULL;
			delete ptr;
			ptr = NULL;
			inserted = true;
		}
		else if (*ptr->data < *current->data) {
			if (current->left == NULL) {              // insert left
				current->left = ptr;
				inserted = true;
			}
			else
				current = current->left;               // one step left
		}
		else {
			if (current->right == NULL) {             // insert right
				current->right = ptr;
				inserted = true;
			}
			else
				current = current->right;              // one step right
		}
	}
	return true;
}

////------------------------- displaySideways ---------------------------------
//// Displays a binary tree as though you are viewing it from the side;
//// hard coded displaying to standard output.
//// Preconditions: NONE
//// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, -1);
}

//////---------------------------- Sideways -------------------------------------
////// Helper method for displaySideways
////// Preconditions: NONE
////// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;       // display information of object
		sideways(current->left, level);
	}
}
//// End of bintree.cpp 

////--------------------------------------------------------------------------
//// insertBinary()
//// bool type of method:
//// insert data into tree resusively
//// one parameter: pointer to the object Nodedata *
bool BinTree::insertBinary(NodeData* data) {
	return insertBinaryHelper(root, data);
}
//// end of the lab2
////--------------------------------------------------------------------------

//// Aditinonal futures
//// resursive insert
//// resursive delete

////--------------------------------------------------------------------------
//// insertBinaryHelper()
//// helper method for insertBinary
//// bool type method:
//// resursivly insert data into tree
bool BinTree::insertBinaryHelper(Node*& new_node, NodeData* data) {
	// base case01:
	// found  right spot for a node
	if (new_node == NULL) {
		new_node = new Node();
		new_node->data = data;
		new_node->left = new_node->right = NULL;
		return true;
	}
	// base case 02:
	// attempt to inser duplicate
	// no dublicates allowed
	if (*new_node->data == *data) {
		delete data;
		data = NULL;
		return true;
	}
	if (*new_node->data > *data) {
		return insertBinaryHelper(new_node->left, data);
	}
	else {
		return insertBinaryHelper(new_node->right, data);
	}
}

////--------------------------------------------------------------------------
//// deleteNode()
//// ...
bool BinTree::deleteNode(const NodeData& data) {
	// call helper function findDeleteNode
	return findDeleteNode(root, data);
}

////--------------------------------------------------------------------------
//// findDeleteNode()
//// ...
bool BinTree::findDeleteNode(Node*& new_node, const NodeData& data) {
	// base case02:
	// no such data exist in the tree
	if (new_node == NULL) {
		return false;
	}
	// base case01:
	// node found
	if (*new_node->data == data) {
		 finalDeleteNode(new_node);
		 return true;
	}

	if (*new_node->data > data) {
		return findDeleteNode(new_node->left, data);
	}
	else {
		return findDeleteNode(new_node->right, data);
	   }
	}

	////--------------------------------------------------------------------------
	//// finalDeleteData()
	//// ...
	void BinTree::finalDeleteNode(Node*& del) {
		// base case 01:
		// no childs exit for the leaf
		if (del->left == NULL && del->right == NULL) {
			delete del->data;
			del->data = NULL;
			delete del;
			del = NULL;
		}
		if (del->left == NULL) {
			Node* tmp = del;
			del = del->right;
			delete tmp->data;
			tmp->data = NULL;
			delete tmp;
			tmp = NULL;
		}
		if (del->right == NULL) {
			Node * tmp = del;
			del = del->left;
			delete tmp->data;
			delete tmp;
			tmp = NULL;
		}
		else {
			delete del->data;
			del->data = findTheMostLeft(del->right);
		}
	}
	////--------------------------------------------------------------------------
	//// findTheMostLeft()
	//// ...
	NodeData* BinTree::findTheMostLeft(Node*& node) {
		if (node->left == NULL) {
			// ------------------------------------------------------------
			// multiple ways to manage data:
			// FIRST:
			// allocated new memory for a node data
			// copy the object(NodeData) using copy concstractor;
			// after copying, delete existing odject
			// NodeData * object = new NodeData (*node->data);
			// after, hold the node, and move its pointer to the right side
			// Node* tmp = node;
			// node = node->next;
			// then, delete hold data , and the hold isteself
			// delete hold->data;
			// delete hold;
			// ------------------------------------------------------------
			// SECOND:
			//  direfrenses the pointers to the objects
			NodeData * object =  node->data;
			node->data = NULL;
			//*object = *node->data;
			Node * tmp = node;
			node = node->right;
		//	delete tmp->data;
		//	tmp->data = NULL;
			delete tmp;
			tmp = NULL;
			return object;
		}
		else {
			return findTheMostLeft(node->left);
		}
	}

