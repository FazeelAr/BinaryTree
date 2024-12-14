#ifndef BSTREE_H
#define BSTREE_H
#include<iostream>
using namespace std;
template<typename T>
class BSTree
{
public:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node(T dt, Node* l = nullptr, Node* r = nullptr)
		{
			data = dt;
			left = l;
			right = r;
		}
	};
private:
	Node* root;
	void inOrder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inOrder(node->left);
		cout << node->data << ' ';
		inOrder(node->right);

	}
	void preOrder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		cout << node->data << ' ';
		preOrder(node->left);
		preOrder(node->right);
	}
	void postOrder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << ' ';
	}
public:
	void insert(T val)
	{
		if (root == nullptr)
		{
			root = new Node{ val };
			return;
		}
		Node* iter = root, *prev = root;
		bool flag = false;
		while (iter != nullptr && flag == false)
		{
			if (iter->data < val)
			{
				prev = iter;
				iter = iter->right;
			}
			else if(iter->data > val)
			{
				prev = iter;
				iter = iter->left;
			}
			else
			{
				flag = true;
			}
		}
		if (iter == nullptr && flag == false)
		{
			if (prev->data < val)
			{
				prev->right = new Node{ val };
			}
			else
			{
				prev->left = new Node{ val };
			}
			return;
		}
		cout << "\nduplicate Node";
	}
	void inOrderTrav()
	{
		inOrder(root);
	}
	void postOrderTrav()
	{
		postOrder(root);
	}
	void preOrderTrav()
	{
		preOrder(root);
	}
	bool search(T val)
	{
		if (root == nullptr)
		{
			return false;
		}
		Node* iter = root, * prev = root;
		bool flag = false;
		while (iter != nullptr && flag == false)
		{
			if (iter->data < val)
			{
				prev = iter;
				iter = iter->right;
			}
			else if (iter->data > val)
			{
				prev = iter;
				iter = iter->left;
			}
			else
			{
				flag = true;
			}
		}
		return flag;
	}
	bool deleteNode(T val)
	{
		/*if (root->data == val)
		{
			delete root;
			root = nullptr;
			return true;
		}*/
		Node* iter = root, * prev = root;
		bool flag = false;
		while (iter != nullptr && iter->data != val)
		{
			if (iter->data > val)
			{
				prev = iter;
				iter = iter->left;
			}
			else if (iter->data < val)
			{
				prev = iter;
				iter = iter->right;
			}
			else
			{
				flag = true;
			}
		}
		cout << "\ndata to be deleted: " << iter->data << '\n';
		if (iter == nullptr)
		{
			if (prev->left == nullptr && prev->right == nullptr)
			{
				delete prev;
			}
			else if (prev->left == nullptr && prev->right != nullptr)
			{
				prev->right = iter->right;
				delete iter;
			}
			else if (prev->left != nullptr && prev->right == nullptr)
			{
				prev->left = iter->left;
				delete iter;
			}
			else
			{
				iter = iter->left;
				while (iter->right != nullptr)
				{
					iter = iter->right;
				}
				prev->data = iter->data;
				delete iter;
			}
			return true;
		}
		return false;
	}
};
#endif //BSTREE_H;