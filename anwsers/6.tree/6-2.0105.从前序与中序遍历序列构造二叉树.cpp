#include "../../include/utils.h"

// preorder: root-left-right
// inorder: left-root-right
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;

    TreeNode* root = new TreeNode(preorder.front());
    auto it = find(inorder.begin(), inorder.end(), preorder.front());
    int i = distance(inorder.begin(), it);

    vector<int> preorder_left = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + i);
    vector<int> preorder_right = vector<int>(preorder.begin() + 1 + i, preorder.end());

    vector<int> inorder_left = vector<int>(inorder.begin(), inorder.begin() + i);
    vector<int> inorder_right = vector<int>(inorder.begin() + 1 + i, inorder.end());

    root->left = buildTree(preorder_left, inorder_left);
    root->right = buildTree(preorder_right, inorder_right);
    return root;
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    printTree(buildTree(preorder, inorder));
    return 0;
}