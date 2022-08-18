#include "../../include/utils.h"


int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int main() {
    vector<int> tree = {1,2,2,3,4,4,3,5};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << maxDepth(root) << endl;
    return 0;
}