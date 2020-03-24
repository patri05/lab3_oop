#include "meniu.h"
#include "Node.h"
#include <iostream>

using namespace std;

void meniu()
{

	/*
		functia afiseaza pe ecran un meniu din care se pot alege 
		optiuni
	*/

	int v[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 }, ok = 1, x, y, input;
	Tree myTree;
	
	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(v[i]);
	}
	
	while (ok != 0)
	{
		system("cls");
		cout<<myTree.PrintInorder();
		cout << endl;
		cout << "-------MENIU-------" << endl;
		cout << "1.Add leaf" << endl;
		cout << "2.Deleate leaf" << endl;
		cout << "3.Print the tree inorder" << endl;
		cout << "4.Print the tree preorder" << endl;
		cout << "5.Print the tree postorder" << endl;
		cout << "6.Print the number of nodes" << endl;
		cout << "7.Print the number of edges" << endl;
		cout << "8.Print the height of the tree" << endl;
		cout << "Choose an option:";
		cin >> x;
		
		while (x < 1 || x>8)
		{
			cout << "Wrong option try again:";
			cin >> x;
			cout << endl;
		}
		if (x == 1)
		{
			cout << "Enter the value for the node:";
			cin >> y;
			myTree.AddLeaf(y);
		}
		if (x == 2)
		{
			cout << "Delete Node: ";
			cin >> input;
			if (input != -1)
			{
				cout << endl;
				myTree.RemoveNode(input);
			}
		}
		if (x == 3)
		{
			cout << myTree.PrintInorder();
			cout << endl;
		}
		if (x == 4)
		{
			cout << myTree.PrintPreorder();
			cout << endl;
		}
		if (x == 5)
		{
			cout << myTree.PrintPostorder();
			cout << endl;
		}
		if (x == 6)
		{
			cout << myTree.CountNodes() << endl;
		}
		if (x == 7)
		{
			cout << myTree.CountEdges() << endl;
		}
		if (x == 8)
		{
			cout << myTree.MaxHeight() << endl;
		}
		cout << "If you want to continue prees 1 else 0 : ";
		cin >> ok;
		while (ok != 1 && ok != 0)
		{
			cout << "Wrong option,try again:";
			cin >> ok;
			cout << endl;
		}
	}
}



