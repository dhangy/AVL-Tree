#pragma once
#include <string>
#include "Node.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void Insert(int data);
	void Remove(int target);
	void Print();
	void PreOrderTraversal();
	int getHeight(Node *cursor);
	int getBalance(Node *cursor);
	void PreOrderHelper(Node *cursor);

private:
	Node * root;
	
	Node* InsertHelper(Node *cursor, int data);
	void PrintHelper(Node *cursor, std::string indent);
	Node *RemoveHelper(Node * cursor, int target);
	bool IsLeaf(Node *cusor);
	bool IsParentToOnlyOneChild(Node *cursor);
	Node *FindSuccessor(Node *cursor);
	Node* singleRightRotate(Node* cursor);
	Node* singleLeftRotate(Node* cursor);
	Node* rightLeftRotation(Node* cursor);
	Node* leftRightRotation(Node* cursor);
	int max(int a, int b);
	void DestructorHelper(Node *cursor);

};