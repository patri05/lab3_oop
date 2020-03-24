#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int lheight=0, rheight=0;

Tree::Tree()
{
	root = NULL;
}

Tree::Node* Tree::CreateLeaf(int key)
{
	Node* n = new Node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void Tree::AddLeaf(int key)
{
	
	/*
		key - valoarea care trebuie adaugata
		functia transmite ca parametru valoarea nodului si radacina catre 
		functia privata de adaugare pentru a incepe cautarea pozitiei 
		de la radacina arborelui 
	*/

	AddLeafPrivate(key, root);
}

void Tree::AddLeafPrivate(int key, Node* Ptr)
{

	/*
		key - valoarea care trebuie adaugata
		Ptr - nodul parinte	
		functia cauta recursiv unde se poate adauga nodul si il adauga
		adaca arborele este gol atunci acesta este creeat si elementul 
		adaugat este radacina arborelui
		de asemenea este verificat daca nodul exista in arbore
	*/

	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			AddLeafPrivate(key, Ptr->left);
		}
		else
		{
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			AddLeafPrivate(key, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "The key " << key << " has already been added to the tree" << endl;
	}
}

int Tree::FindSmallest()
{

	/*
		functia apeleaza functia privata dandu-i ca parametru 
		radacina arborelui
		functia returneaza valoarea ce-a mai mica primita de la functia
		privata
	*/

	return FindSmallestPrivate(root);
}

int Tree::FindSmallestPrivate(Node* Ptr)
{

	/*
		Ptr - nodul parinte
		functia cauta si returneaza cel mai mic element dintr-un arbore
		intai se verifica daca arborele este gol
		daca nu se cauta recursiv valoarea cea mai mica
	*/

	if (root == NULL)
	{
		cout << "The tree is empty" << endl;
		return -1000;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return FindSmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
}

void Tree::RemoveNode(int key)
{

	/*
		key - nodul care trebuie eliminat
		functia apeleaza functia privata de eliminare a uni nod
		si ii da ca parametru valoarea nodului care trebuie eliminat
		si pointerul catre radacina arborelui
	*/

	RemoveNodePrivate(key, root);
}

void Tree::RemoveNodePrivate(int key, Node* parent)
{

	/*
		key - nodul care trebuie eliminat
		parent - nodul parinte
		functia cauta recursiv valoarea care trebuie eliminata
		daca o gaseste aceasta este eliminata din arbore
		daca nu atunci se afiseaza un mesaj de eroare
	*/

	if (root != NULL)//verificare daca arborele este gol
	{
		if (root->key == key)//verificare daca nodul pe care dorim sa il verificam este nodul radacina
		{
			RemoveRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else
			{
				cout << "The key " << key << " was not found in the tree" << endl;
			}
		}
	}
	else
	{
		cout << "The is empty" << endl;
	}
}

void Tree::RemoveRootMatch()
{

	/*
		functia aceasta este o functie ajutatoare pentru
		functia de eliminare a unui nod
		functia elimina nodul radacina daca este posibil 
	*/

	if (root != NULL)
	{
		Node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;
		//cazul 1: nodul radacina nu are copii
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		//cazul 2: nodul radacina are un copil
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted. " << "The new root cintains key " << root->key << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted. " << "The new root cintains key " << root->key << endl;
		}
		//cazul 3: nodul radacina are 2 copii
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			cout << "The root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
		}
	}
	else //daca nu a fost efectuat nici o operatie de mai sus inseamna ca arborele este gol
	{
		cout << "Can not remove the root, the tree is empty" << endl;
	}
}

void Tree::RemoveMatch(Node* parent, Node* match, bool left)
{

	/*
		parent - nodul parinte
		match - nodul pe care vrem sa il eliminam
		left - arata daca match este copilul stang sau drept al lui parent
		functia aceasta este o functie ajutatoare pentru
		functia de eliminare a unui nod
		functia elimina un nod 
	*/

	if (root != NULL)
	{
		Node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;
		//cazul 1: nodul cautat nu are copii
		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ?
				parent->left = NULL :
				parent->right = NULL;
			delete delPtr;
			cout << "The node containig the key " << matchKey << " was removed" << endl;
		}
		//cazul 2: nodul cautat are un copil
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ?
				parent->left = match->right :
				parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containig the key " << matchKey << " was removed" << endl;
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ?
				parent->left = match->left :
				parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containig the key " << matchKey << " was removed" << endl;
		}
		//cazul 3: nodul cautat are 2 copii
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else//daca nu a fost efectuat nici o operatie de mai sus inseamna ca arborele este gol
	{
		cout << "Can not remove match. The tree is empty" << endl;
	}
}

Tree::~Tree()
{
	RemoveSubtree(root);
}

void Tree::RemoveSubtree(Node* Ptr)
{

	/*
		Ptr - nodul parinte
		aceasta functie este o functie ajutatoare pentru deconstructor
		functia elimina recursiv toate nodurile arborelui 
	*/
	
	if (Ptr != NULL)
	{
		if (Ptr->left != NULL)
		{
			RemoveSubtree(Ptr->left);
		}
		if (Ptr->right != NULL)
		{
			RemoveSubtree(Ptr->right);
		}
		cout << "Deleting the node conteining key" << Ptr->key << endl;
		delete Ptr;
	}
}

int Tree::CountNodes()
{

	/*
		functia returneaza numarul de noduri din arbore
	*/

	int nr_nodes = 0;
	return CountNodesPrivate(root, nr_nodes);
}

int Tree::CountNodesPrivate(Node* Ptr, int& nr_nodes)
{

	/*
		Ptr - nodul parinte
		nr_nodes - numarul de noduri
		functia numara recursiv numarul de noduri din arbore
		si returneaza numarul de noduri
	*/

	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			nr_nodes++;
			CountNodesPrivate(Ptr->left, nr_nodes);
		}
		if (Ptr->right != NULL)
		{
			nr_nodes++;
			CountNodesPrivate(Ptr->right, nr_nodes);
		}
	}
	else
	{
		return 0; //se returneaza 0 daca arborele este gol
	}
	return nr_nodes + 1;
}

int Tree::MaxHeight()
{

	/*
		functia returneaza inaltimea arborelui
	*/

	int lheight = 0, rheight = 0;
	return MaxHeightPrivate(root, lheight, rheight);
}

int Tree::MaxHeightPrivate(Node* Ptr, int& lheight, int& rheight)
{

	/*
		Ptr - nodul parinte
		lheight - inaltimea din partea stanga a arborelui
		rheight - inaltimea din partea dreapta a arborelui
		functia calculeaza recursiv inaltimea
		functia returneaza inaltimea
	*/

	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			lheight = MaxHeightPrivate(Ptr->left, lheight, rheight);
		}
		else if (Ptr->right != NULL)
		{
			rheight = MaxHeightPrivate(Ptr->right, lheight, rheight);
		}
		if (lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return (rheight + 1);
		}
	}
}

int Tree::CountEdges()
{
	//functia returneaza numarul de muchii a unui arbore
	return CountNodes() - 1;
}

string Tree::PrintInorder()
{
	//functia returneaza ca si string nodurile intregului arbore in ordine
	return GetInorderPrivate(root);
}

string Tree::GetInorderPrivate(Node* Ptr)
{
	/*
		Ptr - nodul parinte
		functia returneaza ca si string nodurile in ordine
	*/

	string inorder = "";
	if (root == NULL)
		return inorder;
	if (Ptr->left != NULL)
		inorder += GetInorderPrivate(Ptr->left);
	inorder += to_string(Ptr->key) + " ";
	if (Ptr->right != NULL)
		inorder += GetInorderPrivate(Ptr->right);
	return inorder;
}

string Tree::PrintPostorder()
{
	//functia returneaza ca si string nodurile intregului arbore in postordine
	return PrintPostorderPrivate(root);
}

string Tree::PrintPostorderPrivate(Node* Ptr)
{
	/*
		Ptr - nodul parinte
		functia returneaza ca si string nodurile in postordine
	*/

	string postorder = "";
	if (root == NULL)
		return postorder;
	if (Ptr->left != NULL)
		postorder += PrintPostorderPrivate(Ptr->left);
	if (Ptr->right != NULL)
		postorder += PrintPostorderPrivate(Ptr->right);
	postorder += to_string(Ptr->key) += " ";
	return postorder;
}

string Tree::PrintPreorder()
{
	//functia returneaza ca si string nodurile intregului arbore in preordine
	return PrintPreorderPrivate(root);
}

string Tree::PrintPreorderPrivate(Node* Ptr)
{

	/*
		Ptr - nodul parinte
		functia returneaza ca si string nodurile in preordine
	*/

	string preorder = "";
	if (root == NULL)
		return preorder;
	preorder += to_string(Ptr->key) += " ";
	if (Ptr->left != NULL)
		preorder += PrintPreorderPrivate(Ptr->left);
	if (Ptr->right != NULL)
		preorder += PrintPreorderPrivate(Ptr->right);
	return preorder;
}