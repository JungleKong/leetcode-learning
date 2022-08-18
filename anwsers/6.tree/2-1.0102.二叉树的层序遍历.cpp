#include "../../include/utils.h"

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {{}};
    vector<vector<int>> res;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> tmp(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            tmp[i] = node->val;
            if (node->left) que.emplace(node->left);
            if (node->right) que.emplace(node->right);
        }
        res.emplace_back(tmp);
    }
    return res;
}

void helper(TreeNode* root, vector<vector<int>>& res, int depth) {
    if (root == nullptr) return ;
    if (res.size() == depth) res.push_back(vector<int>());
    res[depth].push_back(root->val);
    helper(root->left, res, depth + 1);
    helper(root->right, res, depth + 1);
}   

vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> res;
    helper(root, res, 0);
    return res;

}

int main() {
    vector<int> tree = {5,4,6,1,2};
    TreeNode* root = creatTree(tree);
    printTree(root);
    printVec(levelOrder2(root));
    return 0;
}