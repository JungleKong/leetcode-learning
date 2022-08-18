#include "../../include/utils.h"

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    auto it = max_element(nums.begin(), nums.end());
    TreeNode* root = new TreeNode(*it);

    vector<int> left = vector<int>(nums.begin(), it);
    vector<int> right = vector<int>(it + 1, nums.end());

    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
}