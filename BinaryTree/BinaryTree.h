#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<iostream>
using namespace std;
#include<queue>
template<typename T>
class BinaryTree
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
	bool search(Node* node, T value)
	{
		if (node == nullptr)
		{
			return false;
		}
		else if (node->data == value)
		{
			return true;
		}
		bool flag = false;
		flag = search(node->left, value);
		if (flag)
		{
			return true;
		}
		flag = search(node->right, value);
		return flag;
	}
	int countNodes(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return 1 + (countNodes(node->left) + countNodes(node->right));
	}
public:
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
	void insertNode(T data)
	{
		Node* newNode = new Node{ data };
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			Node* current = q.front();
			q.pop();

			if (current->left == nullptr)
			{
				current->left = newNode;
				return;
			}
			else
			{
				q.push(current->left);
			}

			if (current->right == nullptr)
			{
				current->right = newNode;
				return;
			}
			else
			{
				q.push(current->right);
			}
		}
	}
	
	bool searchNode(T val)
	{
		return search(root, val);
	}
	
};
#endif // !BINARY_TREE_H
