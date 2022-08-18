#include "../../include/utils.h"

// left-root-right
void traversal(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    traversal(root, res);
    return res;
}

// left-root-right
vector<int> inorderTraversal2(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        res.push_back(node->val);
        node = node->right;
    }
    return res;
}


int main() {
    vector<int> tree = {1,2,3,4,5,6};
    TreeNode* root = creatTree(tree);
    printTree(root);

    printVec(inorderTraversal2(root));
    return 0;

}
