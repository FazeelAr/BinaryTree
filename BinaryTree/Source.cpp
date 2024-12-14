#include"BinaryTree.h"
#include"BSTree.h"
int main()
{
	/*BinaryTree<int> tree{};
	tree.insertNode(1);
	tree.insertNode(2);
	tree.insertNode(3);
	tree.insertNode(4);
	tree.insertNode(5);
	tree.inOrderTrav();
	cout << '\n' << tree.searchNode(0);*/
	BSTree<int> tree{};
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);
	tree.inOrderTrav();
	cout << '\n' << tree.search(8);
	cout << '\n' << tree.deleteNode(1);

}