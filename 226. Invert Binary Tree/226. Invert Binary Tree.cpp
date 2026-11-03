// 226. Invert Binary Tree.cpp : This file contains the 'main' function.
#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root)
{
    TreeNode* curr = root;
    std::queue<TreeNode*> q;
    if(curr != nullptr)
    {
        q.push(curr);
        while (!q.empty()) 
        {
        curr = q.front();
        q.pop();

        if(curr->left !=nullptr && curr->right !=nullptr)
        {
            q.push(curr->left);
            q.push(curr->right);
            TreeNode* temp = curr->right;
            curr->right = curr->left;
            curr->left = temp;
        }
        else if (curr->left != nullptr) 
        {
            q.push(curr->left);
            curr->right = curr->left;
            curr->left = nullptr;
        }
        else if (curr->right != nullptr) 
        {
            q.push(curr->right);
            curr->left = curr->right;
            curr->right = nullptr;
        }

        }
    }
   
    return root;
}

void printLevelOrder(TreeNode* root)
{
    if (!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->val << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    std::cout << "\n";
}

int main()
{

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node9 = new TreeNode(9);

    TreeNode* node2 = new TreeNode(2, node1, node3); 
    TreeNode* node7 = new TreeNode(7, node6, node9); 

    TreeNode* root = new TreeNode(4, node2, node7);

    std::cout << "Tree (Level Order): ";
    printLevelOrder(root);
    invertTree(root);
    printLevelOrder(root);

    return 0;
}