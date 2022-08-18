#include "../../include/utils.h"

// root-left-right
void traversal(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    res.emplace_back(root->val);
    traversal(root->left, res);
    traversal(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    traversal(root, res);
    return res;
}

// root-left-right
vector<int> preorderTraversal2(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            res.push_back(node->val);
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
    return res;
}


int main() {
    vector<int> tree = {5,4,6,1,2};
    TreeNode* root = creatTree(tree);
    printTree(root);
    printVec(preorderTraversal2(root));
    return 0;
}