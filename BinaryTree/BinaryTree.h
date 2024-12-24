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
	Node* search(Node* node, T key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		Node* res = nullptr;
		if (node->data == key)
		{
			res = node;
		}
		if (res == nullptr && node->left != nullptr)
		{
			res = search(node->left, key);
		}
		if (res == nullptr && node->right != nullptr)
		{
			res = search(node->right, key);
		}
		return res;
	}
	Node* parent(Node* node, T key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		Node* res = nullptr;
		if ((node->left && node->left->data == key) || (node->right && node->right->data == key))
		{
			res = node;
		}
		if (res == nullptr && node->left != nullptr)
		{
			res = parent(node->left, key);
		}
		if (res == nullptr && node->right != nullptr)
		{
			res = parent(node->right, key);
		}
		return res;
	}
	int countNodes(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return 1 + (countNodes(node->left) + countNodes(node->right));
	}
	void deleteTree(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
		node = nullptr;
	}
public:
	BinaryTree()
	{
		root = nullptr;
	}
	
	~BinaryTree()
	{
		if (!root)
			return;
		deleteTree(root);
		root = nullptr;
	}
	Node*& getRoot()
	{
		return root;
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
		return search(root, val) == nullptr ? false : true;
	}
	bool removeNode(T key)
	{
		Node* rem = parent(root, key);
		if (rem != nullptr && rem->left->data==key)
		{
			deleteTree(rem->left);
			rem->left = nullptr;
			return true;
		}
		if (rem != nullptr && rem->right->data == key)
		{
			deleteTree(rem->right);
			rem->right = nullptr;
			return true;
		}
		return false;
	}
	// Function to delete a node from the binary tree
	Node* deleteNode(Node* root, int val) 
	{
		if (root == nullptr) return nullptr;
		// Use a queue to perform BFS
		queue<Node*> q;
		q.push(root);
		Node* target = nullptr;

		// Find the target node
		while (!q.empty()) 
		{
			Node* curr = q.front();
			q.pop();

			// Check for current node is the target node to delete
			if (curr->data == val) 
			{
				target = curr;
				break;
			}
			// Add children to the queue
			if (curr->left)
			{
				q.push(curr->left);
			}
			if (curr->right)
			{
				q.push(curr->right);
			}
		}
		// If target node is not found, return the original tree
		if (target == nullptr) return root;

		// Find the deepest rightmost node and its parent
		pair<Node*, Node*> last = { nullptr, nullptr };
		queue<pair<Node*, Node*>> q1;
		q1.push({ root, nullptr });

		while (!q1.empty()) 
		{
			auto curr = q1.front();
			q1.pop();

			// Update the last
			last = curr;

			if (curr.first->left)
				q1.push({ curr.first->left, curr.first });
			if (curr.first->right)
				q1.push({ curr.first->right, curr.first });
		}

		Node* lastNode = last.first;
		Node* lastParent = last.second;

		// Replace target's value with the last node's value
		target->data = lastNode->data;

		// Remove the last node
		if (lastParent) 
		{
			if (lastParent->left == lastNode)
				lastParent->left = nullptr;
			else 
				lastParent->right = nullptr;
			delete lastNode;
		}
		else 
		{
			// If the last node was the root
			delete lastNode;
			return nullptr;
		}
		return root;
	}
	Node* getParent(T key)
	{
		return parent(root, key);
	}
	void levelOrder()
	{
		if (root == nullptr)
		{
			return;
		}
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			Node* curr = q.front();
			q.pop();
			cout << curr->data << ' ';
			if (curr->left)
			{
				q.push(curr->left);
			}
			if (curr->right)
			{
				q.push(curr->right);
			}
		}
	}
	int getHeight(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
};
#endif // !BINARY_TREE_H
