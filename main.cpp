#include <iostream>
#include <string>
#include "Node.h"
#include "meniu.h"
#include <assert.h>

using namespace std;


void Test()
{
	/*
		functie de test
	*/

	int v[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
	Tree myTree;
	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(v[i]);
	}
	assert(myTree.CountNodes() == 16);
	assert(myTree.CountEdges() == 15);
	assert(myTree.MaxHeight() == 5);
	assert(myTree.PrintInorder() == "2 3 4 14 15 21 32 50 52 64 70 76 80 83 87 100 ");
	assert(myTree.PrintPostorder() == "3 2 14 15 4 32 21 52 70 64 80 87 83 100 76 50 ");
	assert(myTree.PrintPreorder() == "50 21 4 2 3 15 14 32 76 64 52 70 100 83 80 87 ");
}


int main()
{
	meniu();
	Test();
	system("PAUSE");

	return 0;
}
