#include "../../include/utils.h"

// all in layer order
int sumOfLeftLeaves2(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> que;
    que.emplace(root);
    int res = 0;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) {
                if (node->left->left == nullptr && node->left->right == nullptr) {
                    res += node->left->val;
                } else {
                    que.emplace(node->left);
                }
            }
            if (node->right) que.emplace(node->right);
        }
    }
    return res;
}

// pre orderv: root-left-right
int sumOfLeftLeaves3(TreeNode* root) {
    if (root == nullptr) return 0;  // not necessary
    stack<TreeNode*> stk;
    TreeNode* node = root;
    int res = 0;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.emplace(node);
            if (node->left && node->left->left == nullptr && node->left->right == nullptr) {
                res += node->left->val;
            }
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
    return res;
}

// in orderv: left-root-right
int sumOfLeftLeaves4(TreeNode* root) {
    // if (root == nullptr) return 0;  // not necessary
    stack<TreeNode*> stk;
    TreeNode* node = root;
    int res = 0;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.emplace(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        if (node->left && node->left->left == nullptr && node->left->right == nullptr) {
            res += node->left->val;
        }
        node = node->right;
    }
    return res;
}

// post orderv: left-right-root
int sumOfLeftLeaves5(TreeNode* root) {
    // if (root == nullptr) return 0;  // not necessary
    stack<TreeNode*> stk;
    TreeNode* node = root;
    TreeNode* prev = nullptr;
    int res = 0;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.emplace(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        if (node->right == nullptr || node->right == prev) {
            if (node->left && node->left->left == nullptr && node->left->right == nullptr) {
                res += node->left->val;
            }
            prev = node;
            node = nullptr;
        } else {
            stk.emplace(node);
            node = node->right;
        }
    }
    return res;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    int res = 0;
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        res += root->left->val;
    }
    return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}



int main() {
    vector<int> tree = {1,2,3,4,5,6,7,8};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << sumOfLeftLeaves5(root) << endl;
    return 0;
}