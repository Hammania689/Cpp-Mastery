#pragma once
#include <iostream>
#include "string"
using namespace std;

struct PotusNode
{
	string lastName;
	PotusNode *parent;
	PotusNode *leftChild;
	PotusNode *rightChild;

	PotusNode() : leftChild(nullptr), rightChild(nullptr) {};
};

class BinarySearchTree
{
public:
	// First node of the tree
	PotusNode *root;

	// Use to add a node to the tree. Is done so by use of Recursion
	PotusNode* AddToTree(PotusNode * recursiveRoot,string data)
	{
		// Tree is Empty
		if (recursiveRoot == nullptr)
			recursiveRoot = GetNewNode(recursiveRoot,data);

		// Assign to proper child node based on value being less or greater than
		else if (data[0] <= recursiveRoot->lastName[0])
			recursiveRoot->leftChild = AddToTree(recursiveRoot->leftChild, data);
		else
			recursiveRoot->rightChild = AddToTree(recursiveRoot->rightChild, data);
		
		// Return the tree and its new addition
		return recursiveRoot;
	}
	
	// Use to assign a dynamicly alloc Potus node ptr inital values and parent information
	PotusNode* GetNewNode(PotusNode * parent,string data)
	{
		auto newNode = new PotusNode();
		newNode->parent = parent;
		newNode->lastName = data;
		return newNode;
	}

	// Use to Recursively Print Tree In Order ** Order of Nodes matter
	PotusNode* PrintInOrder(PotusNode *recursiveRoot) const
	{
	

		// If the recursive node is null
		if (recursiveRoot == nullptr)
			return nullptr;

		// Traverses to the leftside of the tree Recursively. 
		PrintInOrder(recursiveRoot->leftChild);

		// Print current node's value
		cout << recursiveRoot->lastName << " " << endl;
			
		// Traverse to the Right child
		PrintInOrder(recursiveRoot->rightChild);
	}

	// Use to Find lowest Node value in a Tree
	PotusNode* LowestSubtreeNode(PotusNode* root)
	{
		if (root->leftChild == nullptr)
			return  root;
		
		root = LowestSubtreeNode(root->leftChild);
	}

	// Use to Delete a Node from the Tree by use of Recursion
	PotusNode* DeleteNode(PotusNode *recursiveRoot, string data)
	{

		// Base Case for Recursion
		if (recursiveRoot == nullptr)
			return nullptr;

		// Inductive Cases that handle traversals of SubTrees until the node is found
		else if (data < recursiveRoot->lastName)
			recursiveRoot->leftChild = DeleteNode(recursiveRoot->leftChild, data);
		else if (recursiveRoot->lastName < data)
			recursiveRoot->rightChild = DeleteNode(recursiveRoot->rightChild, data);

		// Inductive Cases for when we find the node within the Tree
		else 
		{
			// Case 1 : Node being deleted is a leaf
			if (recursiveRoot->leftChild == nullptr && recursiveRoot->rightChild == nullptr)
			{
				delete recursiveRoot; 
				recursiveRoot = nullptr;
			}
			
			// Case 2 : At least one child
			else if (recursiveRoot->leftChild == nullptr)
			{
				auto temp = recursiveRoot;
				recursiveRoot = recursiveRoot->rightChild;
				delete temp;
			}

			else if(recursiveRoot->rightChild == nullptr)
			{
				auto temp = recursiveRoot;
				recursiveRoot = recursiveRoot->leftChild;
				delete temp;
			}

			// case 3 : both children
			else 
			{
				// Find the min value in the right subtree
				// Copy the contents 
				// Delete the duplicate
				auto temp = LowestSubtreeNode(recursiveRoot->rightChild);
				recursiveRoot->lastName = temp->lastName;
				recursiveRoot->rightChild = DeleteNode(temp, temp->lastName);
			}
		}
		return recursiveRoot;
	}

	// Use to Recursively check if the argument for data exists within the tree
	string isInTree(PotusNode *recursiveRoot, string data) const
	{
		// If the current Node has the same lastname as that being searched then its a match
		if (recursiveRoot->lastName == data)
			return "Found Potus " + data +"\n";

		// Recursive search the left and right child (if they aren't nullptrs)
		else if (data < recursiveRoot->lastName && recursiveRoot->leftChild != nullptr)
			return isInTree(recursiveRoot->leftChild, data);
		else if (data > recursiveRoot->lastName && recursiveRoot->rightChild != nullptr)
			return isInTree(recursiveRoot->rightChild, data);
		
		// Otherwise the Potus doesn't exist
		return "No Potus " + data + " exist in the list \n";
	}

	BinarySearchTree(): root(nullptr)	{}
	~BinarySearchTree()	{};
};