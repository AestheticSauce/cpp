// 230 Kth Smallest Element in a BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

std::vector<int> helper(TreeNode* root, std::vector<int>& data) 
{
	

	if (root == NULL) 
	{
		return data;
	}

	data = helper(root->left, data);
	
	if (data[0] != 0) 
	{
		data[0] = data[0] - 1;
		data[1] = root->val;
	}

	data = helper(root->right, data);

	return data;
	
}
int kthSmallest(TreeNode* root, int k) {
	if (root == NULL) return NULL;

	if (root->left == NULL && root->right == NULL) {
		return root->val;
	}
	
	std::vector<int> data = { k,root->val };
	data = helper(root, data);
	return data[1];

}
int main()
{
    // ==========================================
    // Test Case 1: Standard Balanced BST
    // Tree: [3, 1, 4, null, 2]
    //       3
    //      / \
    //     1   4
    //      \
    //       2
    // k = 1 -> Expected Output: 1
    // ==========================================
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    int k1 = 1;
    std::cout << "Test Case 1 (Expected: 1): " << kthSmallest(root1, k1) << std::endl;


    // ==========================================
    // Test Case 2: Multi-level BST
    // Tree: [5, 3, 6, 2, 4, null, null, 1]
    //         5
    //        / \
    //       3   6
    //      / \
    //     2   4
    //    /
    //   1
    // k = 3 -> Expected Output: 3
    // ==========================================
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);

    int k2 = 3;
    std::cout << "Test Case 2 (Expected: 3): " << kthSmallest(root2, k2) << std::endl;


    // ==========================================
    // Test Case 3: Single Node Tree
    // Tree: [10]
    // k = 1 -> Expected Output: 10
    // ==========================================
    TreeNode* root3 = new TreeNode(10);

    int k3 = 1;
    std::cout << "Test Case 3 (Expected: 10): " << kthSmallest(root3, k3) << std::endl;


    // ==========================================
    // Test Case 4: Left-Skewed Tree
    // Tree: 3 -> 2 -> 1
    // k = 2 -> Expected Output: 2
    // ==========================================
    TreeNode* root4 = new TreeNode(3);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(1);

    int k4 = 2;
    std::cout << "Test Case 4 (Expected: 2): " << kthSmallest(root4, k4) << std::endl;


    // ==========================================
    // Test Case 5: Right-Skewed Tree
    // Tree: 1 -> 2 -> 3
    // k = 3 -> Expected Output: 3
    // ==========================================
    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);

    int k5 = 3;
    std::cout << "Test Case 5 (Expected: 3): " << kthSmallest(root5, k5) << std::endl;

    return 0;
}