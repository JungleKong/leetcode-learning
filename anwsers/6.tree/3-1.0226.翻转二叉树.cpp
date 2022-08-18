#include "../../include/utils.h"

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

TreeNode* invertTree2(TreeNode* root) {
    if (root == nullptr) return root;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            swap(node->left, node->right);
            if (node->left) que.emplace(node->left);
            if (node->right) que.emplace(node->right);
        }
    }
    return root;
}

int main() {
    vector<int> tree = {5,4,6,1,2};
    TreeNode* root = creatTree(tree);
    printTree(root);
    printTree(invertTree(root));
    return 0;
}