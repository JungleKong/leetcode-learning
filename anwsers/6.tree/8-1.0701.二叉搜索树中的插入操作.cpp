#include "../../include/utils.h"

class Solution {
public:
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        // 后继节点
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while (node != nullptr) {
            if (node->val < val) {
                prev = node;
                node = node->right;
            } else if (node->val >= val) {
                prev = node;
                node = node->left; 
            }
        }
        if (prev->val > val) prev->left = new TreeNode(val);
        else prev->right = new TreeNode(val);
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

int main() {
    vector<int> tree = {4,2,7,1,3};
    TreeNode* root = creatTree(tree);
    printTree(root);

    Solution so;
    printTree(so.insertIntoBST(root, 4));
    return 0;
}