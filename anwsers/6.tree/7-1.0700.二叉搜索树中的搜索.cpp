#include "../../include/utils.h"

TreeNode* searchBST(TreeNode* root, int val) { 
    TreeNode* node = root;
    while (node != nullptr) {
        if (node->val > val) {
            node = node->left;
        } else if (node->val < val) {
            node = node->right;
        } else if (node->val == val) {
            return node;
        }
    }
    return nullptr;
}



TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;
    if (root->val > val) return searchBST(root->left, val);
    else if (root->val < val) return searchBST(root->right, val);
    else if (root->val = val) return root;
    return nullptr;
}