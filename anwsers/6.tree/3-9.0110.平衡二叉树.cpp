#include "../../include/utils.h"

// 前序遍历(根左右)求深度
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int leftDepth = maxDepth(root->left), rightDepth = maxDepth(root->right);
 
    if (abs(leftDepth -rightDepth) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right); 
}


// 后序遍历(左右根)求高度
// 返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1
int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1) return -1;
    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode* root) {
    return getHeight(root) == -1 ? false : true;
}