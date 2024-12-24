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
		Node* iter = root, * prev = nullptr;

		// Step 1: Search for the node to delete
		while (iter != nullptr && iter->data != val)
		{
			prev = iter;
			if (val < iter->data)
				iter = iter->left;
			else
				iter = iter->right;
		}

		// If the node is not found
		if (iter == nullptr) return false;

		// Step 2: Node with no children (leaf node)
		if (iter->left == nullptr && iter->right == nullptr)
		{
			if (prev == nullptr) // Node to delete is the root
				root = nullptr;
			else if (prev->left == iter)
				prev->left = nullptr;
			else
				prev->right = nullptr;

			delete iter;
		}

		// Step 3: Node with one child
		else if (iter->left == nullptr || iter->right == nullptr)
		{
			Node* child = (iter->left != nullptr) ? iter->left : iter->right;

			if (prev == nullptr) // Node to delete is the root
				root = child;
			else if (prev->left == iter)
				prev->left = child;
			else
				prev->right = child;

			delete iter;
		}

		// Step 4: Node with two children
		else
		{
			// Find inorder successor (smallest in the right subtree)
			Node* successor = iter->right, * successorParent = iter;
			while (successor->left != nullptr)
			{
				successorParent = successor;
				successor = successor->left;
			}

			// Copy the successor's data to the current node
			iter->data = successor->data;

			// Delete the successor
			if (successorParent->left == successor)
				successorParent->left = successor->right;
			else
				successorParent->right = successor->right;

			delete successor;
		}

		return true;
	}
	T floor(T val)
	{
		if (nullptr == root)
		{
			throw "\nTree is Empty";
		}
		if (root->data == val)
		{
			return root->data;
		}

		Node* iter = root;
		T last = -1;
		while (iter != nullptr && root->data != val)
		{
			if (iter->data > val)
			{
				iter = iter->left;
			}
			else
			{
				last = iter->data;
				iter = iter->right;
			}
		}
		if (iter->data == val)
		{
			return iter->data;
		}
		return last;
	}
	T ceil(T val)
	{
		if (nullptr == root)
		{
			throw "\nTree is Empty";
		}
		if (root->data == val)
		{
			return root->data;
		}
		Node* iter = root;
		T retVal = -1;
		while (iter != nullptr)
		{
			if (iter->data == val)
			{
				return iter->data;
			}
			else if (iter->data < val)
			{
				iter = iter->right;
			}
			else
			{
				retVal = iter->data;
				iter = iter->left;
			}
		}
		return retVal;
	}
};
#endif //BSTREE_H;