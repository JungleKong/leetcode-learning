#include "../../include/utils.h"

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* cur = dummy;
    while (cur->next && cur->next->next) {
        ListNode* first = cur->next;
        ListNode* second = first->next;
        ListNode* third = second->next;

        cur->next = second;
        second->next = first;
        first->next = third;
        cur = first;
    }
    ListNode* node = dummy->next;
    delete dummy;
    return node;
}

// 递归写法
ListNode* swapPairs2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* next = head->next;
    head->next = swapPairs2(next->next);
    next->next = head;
    return next;
}

int main() {
    vector<int> list = {5,2};
    ListNode* root = creatList(list);
    printList(swapPairs2(root));
    return 0; 
}