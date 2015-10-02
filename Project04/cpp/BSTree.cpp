////--------------------------------------------------------------------------
//// Start of bintree.cpp
#include  "BSTree.h"
////--------------------------------------------------------------------------
//// BinTree()
//// default constractor
//// sets root to NULL
BinTree::BinTree(){
	root = NULL;
	movieID = 0;
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
//// isEmpty()
//// bool type method:
//// checks if BinTree is empty or not
//// checks if root is NULL
bool  BinTree::isEmpty() const {
	return (root == NULL);
}

////--------------------------------------------------------------------------
//// overload << to display the BinTree in inorder traversal
void BinTree::displayAll() {
	inorderDisplay(root);
	cout << endl;
}

////--------------------------------------------------------------------------
//// inorderDisplay()
//// helper method for operator<<()
//// void type method:
//// displays the BinTree in inorder traversal
//// two parameters: pointer node(root), ostream refrenses(output)
void BinTree::inorderDisplay(Node* node) const {
	//based case:
	//rich end of the tree
	if (node == NULL) { return; }
	// recurisve call on the left and right sides of the tree
	inorderDisplay(node->left);  // left 
	cout << node->data->printInfo();
	inorderDisplay(node->right); // right
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
Movie* BinTree::retrieve(const Movie* find_data) {
	// call helper method retriveBSTreeElemenet()
	return retriveBSTreeElement(root, find_data);
}

////--------------------------------------------------------------------------
//// retriveBSTreeElement()
//// helper method for retrive()
//// bool type method:
//// finds if given object contains in the tree
//// makes binary traversal search for given object
//// three parameters: pointer to a node (root), const refrecnese to NodeData
//// (find_data), Pointer refrences to NodeData (input_data)
Movie* BinTree::retriveBSTreeElement(Node*& node, const Movie* find_data) const {
	// base case 01:
	//check if root is null
	if (node == NULL) {
		return  NULL;        // refrenses input_data	
	}
	// base case 02:
	// check if root contains the same data
	if (node->data->isEqual( find_data)) {
		return node->data;  // refrenses input_data	
	}
	// do binary search:
	// if find_data is more than node->data go left
	else if (node->data->isGreater(find_data)){
		return retriveBSTreeElement(node->left, find_data);
	}
	// if find data is less than node->data go right
	else {
		return retriveBSTreeElement(node->right, find_data);
	}
}


////--------------------------------------------------------------------------
//// insertBinary()
//// bool type of method:
//// insert data into tree resusively
//// one parameter: pointer to the object Nodedata *
bool BinTree::insertBinary(Movie* data) {
	return insertBinaryHelper(root, data);
}

////--------------------------------------------------------------------------
//// insertBinaryHelper()
//// helper method for insertBinary
//// bool type method:
//// resursivly insert data into tree
bool BinTree::insertBinaryHelper(Node*& new_node, Movie* data) {
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
	if (new_node->data->isEqual(data)) {
		
		bool new_stock = new_node->data->increaseStock(data->getStock()); // increase the stock
		delete data;                                                      // delete diplicate
		data = NULL;
		return new_stock;
	}
	if (new_node->data->isGreater(data)) {
		return insertBinaryHelper(new_node->left, data);
	}
	else {
		return insertBinaryHelper(new_node->right, data);
	}
}

////--------------------------------------------------------------------------
