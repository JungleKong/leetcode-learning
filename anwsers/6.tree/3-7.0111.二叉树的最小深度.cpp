#include "../../include/utils.h"

// 后序递归
int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right != nullptr) {
        return 1 + minDepth(root->right);
    }
    if (root->left != nullptr && root->right == nullptr) {
        return 1 + minDepth(root->left);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right)); 
}


// 基本都可用层序遍历解决
int minDepth1(TreeNode* root) {
    int ans = 0;
    if (root == nullptr) return ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        ans++;
        int nowLayer = que.size();
        for (int i = 0; i < nowLayer; ++i) {
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left == nullptr && temp->right == nullptr) return ans;
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        } 
        
    }
    return ans;
}


int main() {
    vector<int> tree = {1,2,2,3,4,4,3,5};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << minDepth(root) << endl;
    return 0;
}