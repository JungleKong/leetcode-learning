#include "../../include/utils.h"

class Solution {
private:
    int maxCount = 0;
    int count = 0;
    TreeNode* prev = nullptr;
    vector<int> res;
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }

    void inorder(TreeNode* cur) {
        if (cur == nullptr) return;
        inorder(cur->left);

        if (prev == nullptr) {  // first node
            count = 1;
        } else if (prev->val == cur->val) {
            count++;
        } else {
            count = 1;
        }

        if (count == maxCount) {
            res.push_back(count);
        } else if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(count);
        }
        prev = cur;
        inorder(cur->right);
    }
};

// 先遍历用额外空间存储再判断
