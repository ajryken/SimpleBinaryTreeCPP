#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

struct node
{
	char data;
	
	node* left;
	node* right;
};

class BinaryTree
{
	public:
	BinaryTree();
	node* root;
	void preOrder(node* currentRoot);
	void inOrder(node* currentRoot);
	void postOrder(node* currentRoot);
	void insert(node* &currentRoot, char c);
	void remove(node* &currentRoot, char c);
	char smallest(node* currentRoot);
	char largest(node* currentRoot);
	node* search(node* currentRoot, char c);
	void parenthetical(node* currentRoot);
};

//CONSTRUCTOR
BinaryTree::BinaryTree()
{
	root = nullptr;
}

//PREORDER TRAVERSAL
void BinaryTree::preOrder(node* currentRoot)
{
	if(currentRoot != nullptr){
		cout << currentRoot->data;
		preOrder(currentRoot->left);
		preOrder(currentRoot->right);
	}
}

//INORDER TRAVERSAL
void BinaryTree::inOrder(node* currentRoot)
{
	if(currentRoot != nullptr){
		inOrder(currentRoot->left);
		cout << currentRoot->data;
		inOrder(currentRoot->right);
	}
}

//POSTORDER TRAVERSAL
void BinaryTree::postOrder(node* currentRoot)
{
	if(currentRoot != nullptr){
		postOrder(currentRoot->left);
		postOrder(currentRoot->right);
		cout << currentRoot->data;
	}
}

//INSERTS A NODE INTO THE TREE
void BinaryTree::insert(node* &currentRoot, char c)
{
	if(currentRoot == nullptr)
	{
		node* newNode = new node;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = c;
		currentRoot = newNode;
	}
	else
	{
		if(c < currentRoot->data){
			insert(currentRoot->left, c);
		}
		else{
			insert(currentRoot->right, c);
		}	
	}
}

//REMOVES A NODE FROM THE TREE
void BinaryTree::remove(node* &currentRoot, char c)
{

	if(currentRoot == nullptr){
		cout << c << " is not in the tree.\n\n";
		return;
	}
	else if(c < currentRoot->data){
		remove(currentRoot->left, c);
	}
	else if(c > currentRoot->data){
		remove(currentRoot->right, c);
	}
	else
	{
		node* dltPtr;
		if(currentRoot->left == nullptr){
			dltPtr = currentRoot;
			currentRoot = currentRoot->right;
			delete dltPtr;
			return;
		}
		else if(currentRoot->right == nullptr)
		{
			dltPtr = currentRoot;
			currentRoot = currentRoot->left;
			delete dltPtr;
			return;
		}
		else{
			dltPtr = currentRoot->left;
			while(dltPtr->right != nullptr){
				dltPtr = dltPtr->right;
			}
			
			currentRoot->data = dltPtr->data;
			
			remove(currentRoot->left, dltPtr->data);
		}
	}
}

//RETURNS DATA OF SMALLEST NODE IN TREE
char BinaryTree::smallest(node* currentRoot)
{
	if(currentRoot == NULL){
		cout << "The tree is empty.\n";
		return ' ';
	}
	else
	{
		while(currentRoot->left != nullptr){
			currentRoot = currentRoot->left;
		}
		return currentRoot->data;
	}
}

//RETURNS DATA OF LARGEST NODE IN TREE
char BinaryTree::largest(node* currentRoot)
{
	if(currentRoot == NULL)
	{
		cout << "ERROR: TREE IS EMPTY" << endl;
		return ' ';
	}
	else
	{
		while(currentRoot->right != nullptr) currentRoot = currentRoot->right;
		return currentRoot->data;
	}
}

//RETURNS LOCATION OF NODE SPECIFIED BY KEY PARAMETER
node* BinaryTree::search(node* currentRoot, char key)
{
	if(currentRoot == nullptr)
	{
		cout << "ERROR: " << key << " IS NOT IN TREE" << endl;
		return nullptr;
	}
	else if(currentRoot->data > key) return search(currentRoot->left, key);
	else if(currentRoot->data < key) return search(currentRoot->right, key);
	else return currentRoot;
}

//PRINTS TREE IN PARANTHETICAL NOTATION
void BinaryTree::parenthetical(node* currentRoot)
{
	//CHECK FOR EMPTY NODE
	if(currentRoot == nullptr) return;

	//PRINTS VALUE FROM NODE
	cout << currentRoot->data;

	if(currentRoot->left != nullptr || currentRoot->right != nullptr) {
		cout << "(";
		parenthetical(currentRoot->left);
		parenthetical(currentRoot->right);
		cout << ")";
	}
}

#endif