
#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include <fstream>
#include "nodedata.h"
//--------------------------  class BinTree  --------------------------------
// ADT BinTree: a tree data structure in which each node (root) has at 
//  most two children(left,right), and each node points to data(NodeData).
//
// Implementation and assumptions:
//   -- Implement as a binary search tree
//   -- default constructor set root to NULL
//   -- Implement with following futures: assign operator (=)
//      equality operators(== and !=) operator<<, retireve, getHight
//      makeEmpty, insert, displaySideways, bstreeToArray, arrayToBSTree
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method
//   -- BinTree can be build into balanced BinTree by two functions:
//      bstreToArry and arrayToBSTree.
//   -- arrayToBSTree method assumes that current tree is empty

//---------------------------------------------------------------------------
class BinTree {
	// display the BinTree in inOrder
	friend ostream& operator<<(ostream&, const BinTree&);

public:
	BinTree();							   // constructor
	BinTree(const BinTree&);			   // copy constructor
	~BinTree();							   // destructor
	void makeEmpty();					   // empty out BinTree
	BinTree& operator=(const BinTree&);    // assings BinTrees
	bool operator==(const BinTree&) const; // compares for equal of 2 BinTrees
	bool operator!=(const BinTree&) const; // compares for equal of 2 BinTrees
	bool isEmpty() const;                  // true if tree is empty, otherwise false
	bool insert(NodeData*);                // inserts NodeData 
	
	int getHeight(const NodeData&);        // finds higth of elemenent 
	bool retrieve(const NodeData&, NodeData*&) const; // retrive data from BinTree
	void displaySideways() const;    // displays the tree sideways
	void bstreeToArray(NodeData*[]); // converts BinTree into array of NodeData
	void arrayToBSTree(NodeData*[]); // converts array of NodeData into BSTree

	bool insertBinary(NodeData *);         // recurisve insert
	bool deleteNode(const NodeData&);

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

	//helpers
	int retriveBinTreeElement(Node*, const NodeData&); //helper for getHeight() 
	int getTreeHeight(Node*);                // helper for retriveBinTreeElement()	
	void makeEmptyHelper(Node*&);            // helper for makeEmpty()
	void copyBinTreeHelper(Node*, Node*&);    // helper for BinTree(const BinTree&)
	void inorderDisplay(Node*, ostream&) const; // helper for operator<<()
	bool isEqualHelper(Node*, Node*) const;   // helper for oeprator==()
	bool retriveBSTreeElement(Node*, const NodeData&, NodeData*&) const; // helper for retrive()
	void bstreeToArrayHelper(Node*&, NodeData*[], int&); // helper for bstreeToArray()
	void arrayToBSTreeHelper(Node*&, NodeData*[], int, int); // helper for arrayToBSTree()
	void sideways(Node*, int) const;			// helper for displaySideways()

	// adiditional futures
	bool insertBinaryHelper(Node*&,NodeData*);
	bool findDeleteNode(Node*&, const NodeData&);
	void finalDeleteNode(Node*&);
	NodeData* findTheMostLeft(Node*&);
};

#endif
