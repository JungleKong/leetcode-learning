#include "../../include/utils.h"

// all in layer order
int findBottomLeftValue2(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);
    int res = root->val;
    while (!que.empty()) {
        int size = que.size();
        res = que.front()->val;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) que.emplace(node->left);
            if (node->right) que.emplace(node->right);
        }
    }
    return res;
}

void traversal(TreeNode* root, int leftLen, int& maxLen, int& maxLeftValue) {
    // 这里有一个隐藏条件就是只有leftLen > maxLen才会更新值,保证结果是最深层最左边的
    // 如果是leftLen >= maxLen, 得到结果是最深层最右边的,因为递归顺序是left->right
    if (root->left == nullptr && root->right == nullptr) {
        if (leftLen > maxLen) {
            maxLen = leftLen;
            maxLeftValue = root->val;
        }
        return;
    }
    if (root->left) {
        traversal(root->left, leftLen + 1, maxLen, maxLeftValue);
    }
    if (root->right) {
        traversal(root->right, leftLen + 1, maxLen, maxLeftValue);
    }
}

int findBottomLeftValue(TreeNode* root) {
    int maxlen = 0, maxLeftValue = 0;
    traversal(root, 0, maxlen, maxLeftValue);
    return maxLeftValue;
}


int main() {
    vector<int> tree = {1,2,3,4,5};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << findBottomLeftValue(root) << endl;
    return 0;
}