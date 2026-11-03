// 98. Validate Binary Search Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
int isValidHelper(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return root->val;
	}
	else
	{
		TreeNode* leftChild;
		TreeNode* rightChild;
		if (root->left != NULL && root->right != NULL)
		{
			leftChild = root->left;
			rightChild = root->right;
			int left = std::max(isValidHelper(leftChild->left), isValidHelper(leftChild->right));
			int right = std::min(isValidHelper(rightChild->left), isValidHelper(rightChild->right));
			if (root->val > left && root->val < right)
			{
				return root->val;
			}
		}
		else if (root->left != NULL && root->right == NULL)
		{
			leftChild = root->left;
			int left = std::max(isValidHelper(leftChild->left), isValidHelper(leftChild->right));
			if (root->val > left)
			{
				return root->val;
			}
		}
		else {
			int right = std::min(isValidHelper(rightChild->left), isValidHelper(rightChild->right));
			if (root->val < right)
			{
				return root->val;
			}
		}

	}
	return 0;
}

bool isValidBST(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	else
	{
		TreeNode* leftChild; {}
		TreeNode* rightChild;{}
		if (root->left != NULL && root->right != NULL) {
			leftChild = root->left;
			rightChild = root->right;
			int left = std::max(isValidHelper(leftChild->left), isValidHelper(leftChild->right));
			int right = std::min(isValidHelper(rightChild->left), isValidHelper(rightChild->right));
			if (root->val > left && root->val < right)
			{
				return true;
			}
		}
		else if (root->left != NULL && root->right == NULL)
		{
			leftChild = root->left;
			int left = std::max(isValidHelper(leftChild->left), isValidHelper(leftChild->right));
			if (root->val > left)
			{
				return true;
			}
		}
		else
		{
			int right = std::min(isValidHelper(rightChild->left), isValidHelper(rightChild->right));
			if (root->val < right)
			{
				return root->val;
			}
		}
		return false;
	}
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
	std::cout << "Test 2 (Expected 0): " << isValidBST(test2) << "\n";

	// Test 1: Simple Valid BST (Expected: 1)
	//     2
	//    / \
    //   1   3
	TreeNode* test1 = new TreeNode(2);
	test1->left = new TreeNode(1);
	test1->right = new TreeNode(3);
	std::cout << "Test 1 (Expected 1): " << isValidBST(test1) << "\n";
	// Test 3: Deep Subtree Violation - Node 4 is in right subtree of 5 (Expected: 0)
	//       5
	//      / \
    //     1   6
	//        / \
    //       4   7
	TreeNode* test3 = new TreeNode(5);
	test3->left = new TreeNode(1);
	test3->right = new TreeNode(6);
	test3->right->left = new TreeNode(4);
	test3->right->right = new TreeNode(7);
	std::cout << "Test 3 (Expected 0): " << isValidBST(test3) << "\n";
	// Test 4: Duplicate Values (Expected: 0)
	//     2
	//    / \
    //   2   2
	TreeNode* test4 = new TreeNode(2);
	test4->left = new TreeNode(2);
	test4->right = new TreeNode(2);
	std::cout << "Test 4 (Expected 0): " << isValidBST(test4) << "\n";
	// Test 5: Left-Skewed Tree / Single Child Nodes (Expected: 1)
	//       3
	//      /
	//     2
	//    /
	//   1
	TreeNode* test5 = new TreeNode(3);
	test5->left = new TreeNode(2);
	test5->left->left = new TreeNode(1);
	std::cout << "Test 5 (Expected 1): " << isValidBST(test5) << "\n";
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
