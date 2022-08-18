// header only

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include "utils.h"

struct SegmentTreeNode {
    int start;
    int end;
    int sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;

    SegmentTreeNode(int a, int b): start(0), end(0), sum(0), left(nullptr), right(nullptr) {}
};



class SegmentTree {
private:
typedef SegmentTreeNode Node;
Node* root;

public:
    SegmentTree(): root(nullptr) {}
    Node* build(vector<int>& nums, int start, int end){
        if (start > end) return nullptr;
        Node* node = new Node(start, end);
        if (start == end) {
            node->sum = nums[start];
            return node;
        }
        int mid = (start + end) / 2;
        node->left = build(nums, start, mid);
        node->right = build(nums, mid + 1, end);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }

    int modify(int i, int val) {
        return modify(root, i, val);
    }

    int query(int i, int j) {
        return query(root, i, j);
    }
private:
    int modify(Node* node, int i, int val) {
        if (node == nullptr) return 0;
    }

    int query(Node* node, int i, int j) {

    }

};
#endif // SEGMENT_TREE_H
