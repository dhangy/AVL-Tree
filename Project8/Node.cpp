#include "Node.h"



Node::Node()
{
	left = right = nullptr;
	height = 0;
}

Node::Node(int data)
{
	left = right = nullptr;
	this->data = data;
	height = 0;
}


Node::~Node()
{
}
