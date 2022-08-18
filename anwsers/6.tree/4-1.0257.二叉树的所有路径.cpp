#include "../../include/utils.h"

class Solution {
private:

    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result); // 左
        if (cur->right) traversal(cur->right, path + "->", result); // 右
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;

    }
};

void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
    path.push_back(cur->val);
    if (cur->left == nullptr && cur->right == nullptr) {
        string sPath;
        for (int i = 0; i < path.size() - 1; i++) {
            sPath += to_string(path[i]);
            sPath += "->";
        }
        sPath += to_string(path.back());
        res.push_back(sPath);
        return;
    }
    // path.emplace_back(cur->val);
    if (cur->left) {
        traversal(cur->left, path, res);
        path.pop_back();
    }
    if (cur->right) {
        traversal(cur->right, path, res);
        path.pop_back();
    }
}


vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) return {};
    vector<string> res;
    vector<int> path;
    traversal(root, path, res);
    return res;
}


// 利用层序遍历
vector<string> binaryTreePaths2(TreeNode* root) {
    if (root == nullptr) return {};
    queue<TreeNode*> que;
    unordered_map<TreeNode*, string> maps;
    maps[root] = to_string(root->val);
    que.emplace(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            string path = maps[node];
            if (node->left) {
                que.emplace(node->left);
                maps[node->left] = path + "->" + to_string(node->left->val);
            }
            if (node->right) {
                que.emplace(node->right);
                maps[node->right] = path + "->" + to_string(node->right->val);
            }
            if (node->left || node->right) {
                maps.erase(node);
            }
        }
    }
    vector<string> res;
    for (auto& p: maps) {
        res.emplace_back(p.second);
    }
    return res;
}




int main() {
    vector<int> tree = {1,2,2,3,4,4,3,5,6};
    TreeNode* root = creatTree(tree);
    printTree(root);
    cout << binaryTreePaths2(root) << endl;
    return 0;
}