#ifndef BSTREE_H
#define BSTREE_H
#include<iostream>
using namespace std;
#include<vector>
#include<queue>
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
	Node* insertRec(Node*& node, T val);
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	bool equal(Node* p, Node* q);
	int balance(Node* node);
	bool isMirror(Node* p, Node* q);
public:
	Node* getRoot()
	{
		return root;
	}
	void insert(T val);
	void recInsert(T val);
	void inOrderTrav();
	void postOrderTrav();
	void preOrderTrav();
	bool search(T val);
	bool deleteNode(T val);
	T floor(T val);
	T ceil(T val);
	void remTree(Node* node);
	bool isEqual(Node* other);
	bool isBalanced();
	~BSTree();
	bool isSymmetric(Node* root);
};
template<typename T>
struct BSTree<T>::Node* BSTree<T>::insertRec(Node*& node, T val)
{
	if (node == nullptr)
	{
		return new Node(val);
	}
	else if (node->data > val)
	{
		node->left = insertRec(node->left, val);
	}
	else if(node->data < val)
	{
		node->right = insertRec(node->right, val);
	}
	return node;
}
template<typename T>
void BSTree<T>::recInsert(T val)
{
	root = insertRec(root,val);
}
template<typename T>
void BSTree<T>::inOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	inOrder(node->left);
	cout << node->data << ' ';
	inOrder(node->right);

}
template<typename T>
void BSTree<T>::preOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << ' ';
	preOrder(node->left);
	preOrder(node->right);
}
template<typename T>
void BSTree<T>::postOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << ' ';
}
template<typename T>
void BSTree<T>::insert(T val)
{
	if (root == nullptr)
	{
		root = new Node{ val };
		return;
	}
	Node* iter = root, * prev = root;
	bool flag = false;
	while (iter != nullptr)
	{
		if (iter->data == val)
		{
			iter->left = new Node{ val,iter->left,iter->right };
			return;
		}
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
	}
	if (prev->data < val)
	{
		prev->right = new Node{ val };
	}
	else
	{
		prev->left = new Node{ val };
	}
	return;
	
	//cout << "\nduplicate Node";
}
template<typename T>
void BSTree<T>::inOrderTrav()
{
	inOrder(root);
}
template<typename T>
void BSTree<T>::postOrderTrav()
{
	postOrder(root);
}
template<typename T>
void BSTree<T>::preOrderTrav()
{
	preOrder(root);
}
template<typename T>
bool BSTree<T>::search(T val)
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
template<typename T>
bool BSTree<T>::deleteNode(T val)
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
template<typename T>
T BSTree<T>::floor(T val)
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
	if (iter && iter->data == val)
	{
		return iter->data;
	}
	return last;
}
template<typename T>
T BSTree<T>::ceil(T val)
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
template<typename T>
void BSTree<T>::remTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	remTree(node->left);
	remTree(node->right);
	delete node;
}
template<typename T>
BSTree<T>::~BSTree()
{
	if (root == nullptr)
	{
		return;
	}
	remTree(root);
}
template<typename T>
bool BSTree<T>::isEqual(Node* other)
{
	return equal(root, other);
}
template<typename T>
int BSTree<T>::balance(Node* node)
{
	if (node == nullptr)
	{
		return false;
	}
	int left = balance(root->left);
	if (left == -1)
	{
		return -1;
	}
	int right = balance(node->right);
	if (right == -1)
	{
		return -1;
	}
	if (abs(left - right) > 1)
	{
		return -1;
	}
	return left > right ? left + 1 : right + 1;
}
template<typename T>
bool BSTree<T>::isBalanced()
{
	if (root == nullptr)
	{
		return false;
	}
	return balance(root) != -1;
}
template<typename T>
bool BSTree<T>::equal(Node* p, Node* q)
{
	if (p == nullptr && q == nullptr)
	{
		return true;
	}
	if (p == nullptr || q == nullptr)
	{
		return false;
	}
	if (p->data == q->data)
	{
		return equal(p->left) && equal(p->right);
	}
	return false;
}
template<typename T>
bool BSTree<T>::isMirror(Node* p, Node* q)
{
	if (p == nullptr && q == nullptr)
	{
		return true;
	}
	if (p == nullptr || q == nullptr)
	{
		return false;
	}
	return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);
}
template<typename T>
bool BSTree<T>::isSymmetric(Node* root)
{
	if (root == nullptr)
	{
		return false;
	}
	return isMirror(root->left, root->right);
}
#endif //BSTREE_H;