#include "../../include/utils.h"

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int prev = 0;
        traversal(root, prev);
        return root;
    }

    // right-root-left
    void traversal(TreeNode* root, int& prev) {
        if (root == nullptr) return;
        traversal(root->right, prev);
        root->val += prev;
        prev = root->val;
        traversal(root->left, prev);
    }
};