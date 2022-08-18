#include "../../include/utils.h"


bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr) return targetSum = root->val;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->left, targetSum - root->val);
}


int main() {
    vector<int> tree = {1,2,3,4,5};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << hasPathSum(root, 9) << endl;
    return 0;
}