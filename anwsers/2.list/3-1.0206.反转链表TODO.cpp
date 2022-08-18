#include "../../include/utils.h"


ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}


// 递归TODO
ListNode* reverse(ListNode* prev, ListNode* cur) {
    if (cur == nullptr) return prev;
    ListNode* next = cur->next;
    cur->next = prev;
    return reverse(cur, next);
}

ListNode* reverseList2(ListNode* head) {
    return reverse(nullptr, head);
}

// 另一种递归TODO
ListNode* reverseList3(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    // 翻转第二个节点
    ListNode* last = reverseList3(head->next);

    // 翻转第二个节点指向头节点
    head->next->next = head;
    // 头节点变为尾节点指向nullptr
    head->next = nullptr;
    return last;
}



int main() {
    int list[] = {5,2,3,4,1,3,1};
    ListNode* root = creatList(list, 7);
    printList(reverseList2(root));
    return 0; 
}