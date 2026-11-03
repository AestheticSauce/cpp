// 230. Kth Smallest Element in a BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
int kthSmallest(TreeNode* root, int k) {
    std::vector<int> arr;
    dfs(root, arr);
    std::sort(arr.begin(), arr.end());
    return arr[k - 1];
        
}
void dfs(TreeNode* root, std::vector<int> &arr)
{
    if (root == NULL) {
        return;
    }
    arr.push_back(root->val);
    dfs(root->right,arr);
    dfs(root->left,arr);
}
int main()
{

    std::cout << "Hello World!\n";
}

