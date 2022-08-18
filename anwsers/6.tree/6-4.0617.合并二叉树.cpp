#include "../../include/utils.h"

TreeNode* merge(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return nullptr;
    TreeNode* root;
    if (root1 != nullptr && root2 == nullptr) {
        root = new TreeNode(root1->val);
        root->left = merge(root1->left, nullptr);
        root->right = merge(root1->right, nullptr);
    }
    if (root1 == nullptr && root2 != nullptr) {
        root = new TreeNode(root2->val);
        root->left = merge(nullptr, root2->left);
        root->right = merge(nullptr, root2->right);
    }
    if (root1 != nullptr && root2 != nullptr) {
        root = new TreeNode(root1->val + root2->val);
        root->left = merge(root1->left, root2->left);
        root->right = merge(root1->right, root2->right);
    }
    return root;
}
// 不改变原始数据
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return merge(root1, root2);
}   

// 将root2添加到root1上
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
    if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
    // 修改了t1的数值和结构
    t1->val += t2->val;                             // 中
    t1->left = mergeTrees(t1->left, t2->left);      // 左
    t1->right = mergeTrees(t1->right, t2->right);   // 右
    return t1;
}

int main() {
    vector<int> tree1 = {1,3,2,5};
    vector<int> tree2 = {2,1,3,null,4,null,7};

    printTree(mergeTrees(creatTree(tree1), creatTree(tree2)));
    return 0;
}