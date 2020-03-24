#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Tree
{
	private:
		struct Node
		{
			int key;
			Node* left;
			Node* right;
		};
		Node* root;
		int nr_nodes, lheight, rheight;
		void AddLeafPrivate(int key, Node* Ptr);
		int FindSmallestPrivate(Node* Ptr);
		void RemoveNodePrivate(int key, Node* parent);
		Node* CreateLeaf(int key);
		void RemoveRootMatch();
		void RemoveMatch(Node* parent, Node* match, bool left);
		void RemoveSubtree(Node* Ptr);
		int CountNodesPrivate(Node* Ptr, int& nr_nodes);
		int MaxHeightPrivate(Node* Ptr, int& lheight, int& rheight);
		string GetInorderPrivate(Node* Ptr);
		string PrintPreorderPrivate(Node* Ptr);
		string PrintPostorderPrivate(Node* Ptr);
	
	public:
		Tree();
		~Tree();
		void AddLeaf(int key);
		int FindSmallest();
		void RemoveNode(int key);
		int CountNodes();
		int CountEdges();
		int MaxHeight();
		string PrintInorder();
		string PrintPreorder();
		string PrintPostorder();
};

#endif


