#include <iostream>
#include "AVLTree.h"

using namespace std;
//Dannie Brockbank
//This is my cooode
//Section 003?
//---------------------

AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
	DestructorHelper(root);
}
void AVLTree::DestructorHelper(Node * cursor)
{
	// base case
	if (cursor == nullptr)
		return;
	// recursive case
	DestructorHelper(cursor->left);
	DestructorHelper(cursor->right);
	delete cursor;
}

void AVLTree::Insert(int data){

	root = InsertHelper(root, data);
}

Node * AVLTree::InsertHelper(Node * cursor, int data)
{
	if (cursor == nullptr) {
		cursor = new Node(data);
		cursor->height = 0;
	}
	else if (data < cursor->data) {
		//left subtree
		cursor->left = InsertHelper(cursor->left, data);
		//check to see if it is out of balance 
		if (getHeight(cursor->left) - getHeight(cursor->right) == 2) {
			if (data < cursor->left->data) {
				cursor = singleRightRotate(cursor);
			}
			else {
				cursor = rightLeftRotation(cursor);
			}
		}
	}
	else if (data > cursor->data) {
		//right subtree
		cursor->right = InsertHelper(cursor->right, data);
		if (getHeight(cursor->right) - getHeight(cursor->left) == 2) {
			if (data > cursor->right->data) {
				cursor = singleLeftRotate(cursor);
			}
			else {
				cursor = leftRightRotation(cursor);
			}
		}
	}
	cursor->height = max(getHeight(cursor->left), getHeight(cursor->right)) + 1;
	return cursor;
}



void AVLTree::Print()
{
	PrintHelper(root, "");
	cout << endl;
}
void AVLTree::PrintHelper(Node * cursor, std::string indent)
{
	if (cursor == nullptr)
	{
		cout << indent << "[Empty]" << endl;
		return;
	}
	else if (cursor->height == 0) {
		
		cout << indent <<  cursor->data << '(' << cursor->height << ") [leaf]" << endl;
		return;
	}

	cout << indent << cursor->data << '(' << cursor->height << ')'<< endl;
	PrintHelper(cursor->left, indent + "   ");
	PrintHelper(cursor->right, indent + "   ");
}

bool AVLTree::IsLeaf(Node * cursor)
{
	if (cursor == nullptr)
		return false;
	if (cursor->left == nullptr && cursor->right == nullptr)
		return true;
	else
		return false;
}
bool AVLTree::IsParentToOnlyOneChild(Node * cursor)
{
	if (cursor == nullptr)
		return false;
	if (cursor->left == nullptr && cursor->right != nullptr)
		return true;
	if (cursor->left != nullptr && cursor->right == nullptr)
		return true;
	else
		return false;
}

Node * AVLTree::FindSuccessor(Node * cursor)
{
	if (cursor == nullptr) {
		return nullptr;
	}
	Node *child = cursor->right;
	while (child->left != nullptr)
		child = child->left;
	return child;
}



void AVLTree::Remove(int target)
{
	root = RemoveHelper(root, target);
}
Node * AVLTree::RemoveHelper(Node * cursor, int target)
{
	if (cursor == nullptr)
		return nullptr;
	if (cursor->data == target)
	{
		if (IsLeaf(cursor) == true)
		{
			delete cursor;
			return nullptr;
		}

		if (cursor->left != nullptr && cursor->right == nullptr)
		{
			Node *tmp = cursor->left;
			delete cursor;
			return tmp;
		}
		if (cursor->right != nullptr && cursor->left == nullptr)
		{
			Node *tmp = cursor->right;
			delete cursor;
			return tmp;
		}
		Node *successor = FindSuccessor(cursor);
		cursor->data = successor->data;
		cursor->right = RemoveHelper(cursor->right, cursor->data);
	}
	else
	{
		if (target <= cursor->data)
		{
			cursor->left = RemoveHelper(cursor->left, target);
		}
		else
		{
			cursor->right = RemoveHelper(cursor->right, target);
		}
	}

	return cursor;
}
int AVLTree::getHeight(Node *cursor) {
		if (cursor == nullptr) {
			return -1;
		}
		return cursor->height;
	}
int AVLTree::getBalance(Node *cursor) {
	if (cursor == nullptr || cursor->right == nullptr || cursor->left == nullptr) {
		return 0;
	}
	int balance = cursor->left->height - cursor->right->height;
	return balance;
}

Node* AVLTree::singleRightRotate(Node* cursor) {
	Node *temp = cursor->left;
	cursor->left = temp->right;
	temp->right = cursor;
	cursor->height = max(getHeight(cursor->left), getHeight(cursor->right)) + 1;
	temp->height = max(getHeight(temp->left), cursor->height) + 1;
	return temp;
}
Node* AVLTree::singleLeftRotate(Node* cursor) {
	Node *temp = cursor->right;
	cursor->right = temp->left;
	temp->left = cursor;
	cursor->height = max(getHeight(cursor->left), getHeight(cursor->right)) + 1;
	temp->height = max(getHeight(temp->right), cursor->height) + 1;
	return temp;
}

Node* AVLTree::leftRightRotation(Node *cursor) {
	cursor->right = singleRightRotate(cursor->right);
	return singleLeftRotate(cursor);
}

Node* AVLTree::rightLeftRotation(Node *cursor) {
	cursor->left = singleLeftRotate(cursor->left);
	return singleRightRotate(cursor);
}

int AVLTree::max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void AVLTree::PreOrderTraversal() {
	PreOrderHelper(root);
	cout << "\n";
}

void AVLTree::PreOrderHelper(Node *cursor) {
	if (cursor != nullptr) {
		cout << cursor->data << ", " ;
		PreOrderHelper(cursor->left);
		PreOrderHelper(cursor->right);
	}
}
