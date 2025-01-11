#include"BinaryTree.h"
#include"BSTree.h"
void mirror(BinaryTree<int>::Node* node)
{
	if (node == nullptr)
	{
		return ;
	}
	BinaryTree<int>::Node* temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirror(node->left);
	mirror(node->right);
}
int main()
{
	//BinaryTree<int> tree{};
	//tree.insertNode(1);
	//tree.insertNode(2);
	//tree.insertNode(3);
	//tree.insertNode(4);
	//tree.insertNode(5);
	//tree.insertNode(6);
	//tree.insertNode(7);
	//tree.insertNode(8);
	//tree.levelOrder();
	///*cout << "\nAfter Deletion: ";
	//tree.removeNode(3);*/
	//mirror(tree.getRoot());
	//cout << '\n';
	//tree.levelOrder();
	//cout <<"\nparent: " <<  tree.getParent(4)->data;
	//cout << '\n' << tree.searchNode(1)<<"\nLevelOrder: ";
	//tree.levelOrder();
	//cout << "\nHeight: " << tree.getHeight(tree.getRoot());
	//tree.~BinaryTree();
	BSTree<int> tree{};
	tree.recInsert(1);
	tree.recInsert(2);
	tree.recInsert(3);
	tree.recInsert(4);
	tree.recInsert(5);
	//trerecI.insert(6);
	tree.recInsert(7);
	tree.recInsert(8);
	tree.recInsert(9); 
	tree.recInsert(10);
	tree.inOrderTrav();
	//cout << '\n' << tree.search(8);
	//cout << '\n' << tree.deleteNode(tree.getRoot(),6) << '\n';
	cout << '\n' << tree.floor(6) << '\n';
	tree.inOrderTrav();
}