#include <iostream>
#include "AVLTree.h"

void TestTree(AVLTree *avlTree, int data[], int dataElements)
{
	for (int i = 0; i < dataElements; i++)
	{
		avlTree->Insert(data[i]);
	}

	avlTree->PreOrderTraversal();
}

int main()
{
	int data0[] = { 89, 32, 17 };
	int data1[] = { 10, 15, 20, 25, 30, 35 };
	int data2[] = { 10, 15, 20, 25, 30, 22 };
	int data3[] = { 35, 30, 25, 20, 15, 10 };
	int data4[] = { 35, 30, 25, 20, 15, 22 };
	int data5[] = { 35, 30, 25, 20, 15, 10, 40, 45 };
	int data6[] = { 21,26,30,9,4,14,28,18,15,10,2,3,7 };

	AVLTree *tmpTree = new AVLTree;

	TestTree(tmpTree, data0, 3);
	delete tmpTree;

	tmpTree = new AVLTree;
	TestTree(tmpTree, data1, 6);
	delete tmpTree;

	tmpTree = new AVLTree;
	TestTree(tmpTree, data2, 6);
	delete tmpTree;

	tmpTree = new AVLTree;
	TestTree(tmpTree, data3, 6);
	delete tmpTree;

	tmpTree = new AVLTree;
	TestTree(tmpTree, data4, 6);
	delete tmpTree;

	tmpTree = new AVLTree;
	TestTree(tmpTree, data5, 8);
	delete tmpTree;

	tmpTree = new AVLTree;
	TestTree(tmpTree, data6, 13);
	tmpTree->Print();
	delete tmpTree;


	std::cout << "Press [Enter] key to terminate.  ";
	getchar();
}
