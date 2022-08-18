#include "../../include/utils.h"
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int maxdep = 0;
    for (int i = 0; i < root->children.size(); i++) {
        maxdep = max(maxDepth(root->children[i]), maxdep);
    }
    return 1 + maxdep;
}

// ?????
int maxDepth2(Node* root) {
    if (root == nullptr) return 0;
    vector<int> vec(root->children.size());
    for (int i = 0; i < root->children.size(); i++) {
        vec[i] = maxDepth(root->children[i]);
    }
    return 1 + (*max_element(vec.begin(), vec.end()));
}

