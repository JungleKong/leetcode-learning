#include "../../include/utils.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        else if (left && !right) return left;
        else if (!left && right) return right;
        else return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, TreeNode*> fa;
        unordered_map<int, bool> visited;
        fa[root->val] = nullptr;
        dfs(root, fa);

        while (p) {
            visited[p->val] = true;
            p = fa[p->val];
        }
        while (q) {
            if (visited[q->val]) return q;
            q = fa[q->val];
        }

        return nullptr;
    }

    void dfs(TreeNode* root, unordered_map<int, TreeNode*>& fa) {
        if (root == nullptr) return ;
        if (root->left) {
            fa[root->left->val] = root;
            dfs(root->left, fa);
        }
        if (root->right) {
            fa[root->right->val] = root;
            dfs(root->right, fa);
        }
    }
};