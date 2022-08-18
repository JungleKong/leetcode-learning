#include "../../include/utils.h"

// left-right-root
void traversal(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    traversal(root->left, res);
    traversal(root->right, res);
    res.emplace_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    traversal(root, res);
    return res;
}

// left-right-root
vector<int> postorderTraversal2(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    TreeNode* prev = nullptr;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        if (node->right == nullptr || node->right == prev) {
            res.push_back(node->val);
            prev = node;
            node = nullptr;
        } else {
            stk.push(node);
            node = node->right;
        }
    }
    return res;
}

int main() {
    vector<int> tree = {5,4,6,1,2};
    TreeNode* root = creatTree(tree);
    printTree(root);
    printVec(postorderTraversal2(root));
    return 0;
}