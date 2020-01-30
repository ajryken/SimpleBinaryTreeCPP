#include "binaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinaryTree bt;

	bt.insert(bt.root, 'M');
	bt.insert(bt.root, 'E');
	bt.insert(bt.root, 'P');
	bt.insert(bt.root, 'G');
	bt.insert(bt.root, 'L');

	cout << endl << "In Order List" << endl;
	bt.inOrder(bt.root);
	cout << endl << endl;

	char small = bt.smallest(bt.root);
	cout << "Smallest Value: " << small << endl;
	char large = bt.largest(bt.root);
	cout << "Largest Value: " << large << endl;
	node* request = bt.search(bt.root, 'L');
	cout << "Location of 'L': " << request << endl << endl;

	bt.remove(bt.root, 'E');
	cout << "'E' Deleted" << endl;
	bt.inOrder(bt.root);
	cout << endl << endl;
	
	bt.remove(bt.root, 'P');
	cout << "'P' Deleted" << endl;
	bt.inOrder(bt.root);
	cout << endl << endl;

	small = bt.smallest(bt.root);
	cout << "Smallest Value: " << small << endl;
	large = bt.largest(bt.root);
	cout << "Largest Value: " << large << endl;
	request = bt.search(bt.root, 'L');
	cout << "Location of 'L': " << request << endl;

	return 0;
}