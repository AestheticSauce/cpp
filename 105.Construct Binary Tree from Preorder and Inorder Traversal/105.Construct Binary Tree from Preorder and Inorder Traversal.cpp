// 105.Construct Binary Tree from Preorder and Inorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};


int index = 0;
std::unordered_map<int, int> map;



TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
        map[inorder[i]] = i;
    }
    return helper(preorder, 0, inorder.size() - 1);
}



TreeNode* helper(std::vector<int>& preorder, int start, int end) {
    if (start > end) return nullptr;

    int rootVal = preorder[index++];

    TreeNode* root = new TreeNode(rootVal);
    int mid = map[rootVal];

    root->left = helper(preorder, start, mid - 1);
    root->right = helper(preorder, mid + 1, end);
}


void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main() {
    // ==========================================
    // Tree 1: Perfect / Full Binary Tree
    //        10
    //       /  \
    //      5    20
    //     / \   / \
    //    3   7 15  25
    // ==========================================
    TreeNode* tree1 = new TreeNode(10);
    tree1->left = new TreeNode(5);
    tree1->right = new TreeNode(20);
    tree1->left->left = new TreeNode(3);
    tree1->left->right = new TreeNode(7);
    tree1->right->left = new TreeNode(15);
    tree1->right->right = new TreeNode(25);
    //inOrderTraversal(tree1);
    std::cout << "--------------------------" << std::endl;
    //preOrderTraversal(tree1);
    // ==========================================
    // Tree 2: Left-Skewed Tree
    //     100
    //     /
    //    80
    //   /
    //  60
    //  /
    // 40
    // ==========================================
    TreeNode* tree2 = new TreeNode(100);
    tree2->left = new TreeNode(80);
    tree2->left->left = new TreeNode(60);
    tree2->left->left->left = new TreeNode(40);
    tree2->left->left->left->right = new TreeNode(20);
    // ==========================================
    // Tree 3: Right-Skewed Tree
    //    1
    //     \
    //      2
    //       \
    //        3
    //         \
    //          4
    // ==========================================
    TreeNode* tree3 = new TreeNode(1);
    tree3->right = new TreeNode(2);
    tree3->right->right = new TreeNode(3);
    tree3->right->right->right = new TreeNode(4);

    // ==========================================
    // Tree 4: Zig-Zag Tree
    //        50
    //       /
    //      25
    //        \
    //         35
    //        /
    //       30
    // ==========================================
    TreeNode* tree4 = new TreeNode(50);
    tree4->left = new TreeNode(25);
    tree4->left->right = new TreeNode(35);
    tree4->left->right->left = new TreeNode(30);

    // ==========================================
    // Tree 5: Asymmetric Binary Tree
    //         1
    //        / \
    //       2   3
    //        \   \
    //         4   5
    //        /
    //       6
    // ==========================================
    TreeNode* tree5 = new TreeNode(1);
    tree5->left = new TreeNode(2);
    tree5->right = new TreeNode(3);
    tree5->left->right = new TreeNode(4);
    tree5->left->right->left = new TreeNode(6);
    tree5->right->right = new TreeNode(5);
  
    std::cout << "All 5 trees constructed successfully.\n";

    // Clean up memory
    freeTree(tree1);
    freeTree(tree2);
    freeTree(tree3);
    freeTree(tree4);
    freeTree(tree5);
 
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
