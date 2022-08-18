#include "../../include/utils.h"

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

bool helper(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    return (root1->val == root2->val) && helper(root1->left, root2->right) && helper(root1->right, root2->left);
}

bool isSymmetric(TreeNode* root) {
    // 先翻转, 再判断是否相等?
    TreeNode* root2 = invertTree(root);
    return helper(root, root2);
}

bool isSymmetric2(TreeNode* root) {
    if (root == nullptr) return true;
    return helper(root->left, root->right);
}

int main() {
    vector<int> tree = {1,2,2,3,4,4,3};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << isSymmetric2(root) << endl;
    return 0;
}
