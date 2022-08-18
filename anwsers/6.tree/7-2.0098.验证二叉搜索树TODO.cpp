#include "../../include/utils.h"

// 错误:[5,4,6,null,null,3,7]
bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    if (!root->left && !root->right) return true;
    else if (root->left && !root->right) return (root->left->val < root->val) && isValidBST(root->left);
    else if (!root->left && root->right) return (root->val < root->right->val) && isValidBST(root->right);
    else return (root->left->val < root->val) && isValidBST(root->left) && (root->val < root->right->val) && isValidBST(root->right);
}


bool helper(TreeNode* root, long lower, long upper) {
    if (!root) return true;
    if (root->val <= lower || root->val >= upper) return false;
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}
bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

void inorder(TreeNode* node, vector<int>& res) {
    if (node == nullptr) return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}

// TODO BST中序遍历是有序的
bool isValidBST(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] > res[i + 1]) return false;
    }
    return true;
}
