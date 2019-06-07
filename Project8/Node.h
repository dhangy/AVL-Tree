#pragma once
class Node
{
public:
	Node();
	Node(int data);
	~Node();

	int data;
	int height;
	Node* left;
	Node* right;
};

