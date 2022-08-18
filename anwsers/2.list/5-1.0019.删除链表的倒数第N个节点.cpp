#include "../../include/utils.h"

// 题目保证删除的节点一定在链表中
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* dummy = new ListNode();
    dummy->next = head;

    // 使用快慢指针
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // 先让快指针走n, 再一起走, 这样当快指针走到尾, 慢指针走到n
    while (n--) {
        fast = fast->next;
    }
    while (fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    ListNode* node = dummy->next;
    delete dummy;
    return node;
}


int main() {
    vector<int> list = {5,3,5,7};
    ListNode* root = creatList(list);
    printList(removeNthFromEnd(root, 3));
    return 0; 
}