#include "../../include/utils.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int n = nums.size() / 2;
        vector<int> left = vector<int>(nums.begin(), nums.begin() + n);
        vector<int> right = vector<int>(nums.begin() + n + 1, nums.end());
        TreeNode* root = new TreeNode(nums[n]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) { 
        return buildTree(nums, 0, nums.size());
    }

    TreeNode* buildTree(vector<int>& nums, int begin, int end) {
        if (begin == end) return nullptr;
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, begin, mid);  // [)
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }
};