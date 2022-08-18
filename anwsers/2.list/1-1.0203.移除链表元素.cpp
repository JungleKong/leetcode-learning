#include "../../include/utils.h"

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* cur = dummy;
    while (cur->next != nullptr) {
        if (cur->next->val == val) {
            ListNode* node = cur->next;
            cur->next = cur->next->next;
            delete node;
        } else {
            cur = cur->next;
        }
    }
    ListNode* root = dummy->next;
    delete dummy;
    return root;
    
}

int main() {
    int list[] = {1,2,3,4,1,3,1};
    ListNode* root = creatList(list, 7);
    printList(removeElements(root, 1));
    return 0;
}