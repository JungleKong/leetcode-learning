#include "../../include/utils.h"

// 层序遍历O(n)
int countNodes2(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> que;
    que.emplace(root);
    int res = 0;
    while (!que.empty()) {
        int size = que.size();
        res += size;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left)  que.emplace(node->left);
            if (node->right) que.emplace(node->right);
        }
    }
    return res;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    TreeNode* left = root->left;
    TreeNode* right = root->right; 
    int leftDepth = 0, rightDepth = 0;
    while (left) {
        left = left->left;
        leftDepth++;
    }
    while (right) {
        right = right->right;
        rightDepth++;
    }
    if (leftDepth == rightDepth) {
        return (2 << leftDepth) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
    vector<int> tree = {1,2,2,3,4,4,3,5};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << countNodes(root) << endl;
    return 0;
}