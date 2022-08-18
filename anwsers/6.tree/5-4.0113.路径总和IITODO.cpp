#include "../../include/utils.h"


void helper(TreeNode* node, int sum, vector<int>& tmp, vector<vector<int>>& res) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) {
        tmp.emplace_back(node->val);
        if (node->val == sum) {
            res.emplace_back(tmp);
        }
        tmp.pop_back();
        return;
    }

    tmp.emplace_back(node->val);
    helper(node->left, sum - node->val, tmp, res);
    tmp.pop_back();

    tmp.push_back(node->val);
    helper(node->right, sum - node->val, tmp, res);
    tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> tmp;
    helper(root, targetSum, tmp, res);
    return res;
}


int main() {
    vector<int> tree = {1,2,3,4,5};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << pathSum(root, 9) << endl;
    return 0;
}