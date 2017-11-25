#include "BinaryTree.h"

int main(int argc,char *agrv[])
{
	BinarySearchTree bt;

	bt.root = bt.AddToTree(bt.root, "50");
	bt.root = bt.AddToTree(bt.root, "70");
	bt.root = bt.AddToTree(bt.root, "30");
	bt.root = bt.AddToTree(bt.root, "45");
	bt.root = bt.AddToTree(bt.root, "2");


	bt.PrintInOrder(bt.root);
	
	cout << endl;
	cout << "Search the tree for : \t";

	auto data = string();
	cin >> data;

	cout << bt.isInTree(bt.root, data);
	

	bt.DeleteNode(bt.root, data);
	bt.PrintInOrder(bt.root);
	

	cin.ignore();
	cin.ignore();
	return (0);
}