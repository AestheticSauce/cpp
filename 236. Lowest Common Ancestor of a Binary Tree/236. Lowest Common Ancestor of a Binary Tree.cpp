// 236. Lowest Common Ancestor of a Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct TreeNode {
  int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
 {

     //checks if root itself is the treenode that we are looking for, if it is then just return the root itself because its decendants will contain the node
     if (root == NULL || root == p || root == q) 
     {
         return root;
     }

     //checks for p and q as root of the tree isnt the one that is p or q
     TreeNode* left = lowestCommonAncestor(root->left, p, q);
     TreeNode* right = lowestCommonAncestor(root->right, p, q);

     //if both left and right contain the p and q we are looking for then return the root
     if(left != NULL && right!= NULL)
     {
         return root;
     }
     //if left contain both p and q then return left
     if (left != NULL) {
         return left;
     }
     //else return right
     else {
         return right;
     }
 }
 
int main()
{
    std::cout << "Hello World!\n";
}

