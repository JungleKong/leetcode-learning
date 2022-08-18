#include "../../include/utils.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left && root->right) {
                TreeNode* node = root->right;
                delete root;
                return node;
            } else if (root->left && !root->right) {
                TreeNode* node = root->left;
                delete root;
                return node;
            } else if (root->left && root->left) {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;  // 后继节点
                }
                cur->left = root->left;
                TreeNode* node = root->right;
                delete root;
                return node;
            }
        }
        return root;
    }
};