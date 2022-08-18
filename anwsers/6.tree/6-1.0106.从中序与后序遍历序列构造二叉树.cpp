#include "../../include/utils.h"

// inorder: left-root-right
// postorder: left-right-root
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;
    // root
    TreeNode* root = new TreeNode(postorder.back());
    auto it = find(inorder.begin(), inorder.end(), postorder.back());
    int i = distance(inorder.begin(), it);

    // slice by index will doog performance
    vector<int> inorder_left = vector<int>(inorder.begin(), inorder.begin() + i);
    vector<int> inorder_right = vector<int>(inorder.begin() + i + 1, inorder.end());

    vector<int> postorder_left = vector<int>(postorder.begin(), postorder.begin() + i);
    vector<int> postorder_right = vector<int>(postorder.begin() + i, postorder.end() - 1);

    root->left = buildTree(inorder_left, postorder_left);
    root->right = buildTree(inorder_right, postorder_right);
    return root;
}

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    printTree(buildTree(inorder, postorder));
    return 0;
}