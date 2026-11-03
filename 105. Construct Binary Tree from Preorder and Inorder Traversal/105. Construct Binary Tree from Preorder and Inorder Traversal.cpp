// 105. Construct Binary Tree from Preorder and Inorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
 void dfs_InOrder(TreeNode *root)
 {
	 if (root == NULL) return;
	 dfs_InOrder(root->left);
	 std::cout << (root->val) << '\n';
	 dfs_InOrder(root->right);

 }
 void dfs_preOrder(TreeNode * root)
 {
	 if (root == NULL) return;
	 std::cout << root->val << '\n';
	 dfs_preOrder(root->left);
	 dfs_preOrder(root->right);
 }
int main()
{
	// Test 2: Simple Invalid BST - Right child smaller than root (Expected: 0)
	//     5
	//    / \
    //   1   4
	//      / \
    //     3   6
	TreeNode* test2 = new TreeNode(5);
	test2->left = new TreeNode(1);
	test2->right = new TreeNode(4);
	test2->right->left = new TreeNode(3);
	test2->right->right = new TreeNode(6);
	dfs_InOrder(test2);
	std::cout << "--------------\n";
	dfs_preOrder(test2);
}


