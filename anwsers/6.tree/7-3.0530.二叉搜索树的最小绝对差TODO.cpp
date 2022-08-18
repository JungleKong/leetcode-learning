#include "../../include/utils.h"

void inorder(TreeNode* node, vector<int>& res) {
    if (node == nullptr) return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}

int getMinimumDifference(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    int ans = INT_MAX;
    for (int i = 0; i < res.size() - 1; i++) {
        ans = min(ans, res[i + 1] - res[i]);
    }
    return ans;
}   

// 传TreeNode*不行, 传TreeNode** ??
void inorder(TreeNode* node, TreeNode** prev, int& res) {
    if (node == nullptr) return;
    inorder(node->left, prev, res);
    if (prev != nullptr)
        res = min(res, node->val - (*prev)->val);
    prev = &node;
    inorder(node->right, prev, res);
}

// 把指针放到外部, 因为迭代的时候会更新又不更新
TreeNode* prevv = nullptr;
void inorder(TreeNode* node, int& res) {
    if (node == nullptr) return;
    inorder(node->left, res);
    if (prevv != nullptr)
        res = min(res, node->val - prevv->val);
    prevv = node;
    inorder(node->right, res);
}

int getMinimumDifference2(TreeNode* root) {
    int res = INT_MAX;
    inorder(root, res);
    return res;
}   


int main() {
    vector<int> tree = {5,4,7};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << getMinimumDifference2(root) << endl;

    // Solution1 so;
    // cout << so.getMinimumDifference(root) << endl;
    return 0;
}