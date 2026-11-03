// 100Same Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) { return true; }
    if (!p || !q) { return false; }
    if ((q->val == p->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
        return true;
    }
    return false;
}

int main() {
    // Tree p: [1, 2, 1]
    //       1
    //      / \
    //     2   1
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(1));

    // Tree q: [1, 1, 2]
    //       1
    //      / \
    //     1   2
    TreeNode* q = new TreeNode(1, new TreeNode(1), new TreeNode(2));

    bool result = isSameTree(p, q);

    std::cout << std::boolalpha;
    std::cout << "Are the trees identical? " << result << "\n";

    
    delete p->left;
    delete p->right;
    delete p;

    delete q->left;
    delete q->right;
    delete q;

    return 0;
}