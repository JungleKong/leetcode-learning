#include "../../include/utils.h"

class MyLinkedList {
public:
int size;
ListNode* dummy;
    MyLinkedList() {
        dummy = new ListNode();
        size = 0;
    }

    ~MyLinkedList() {
        // TODO 析构
    }
    
    int get(int index) {
        if (index < 0 || index + 1 > size) {
            return -1;
        }

        ListNode* cur = dummy;
        while (index--) {
            cur = cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* head = dummy->next;
        ListNode* nowHead = new ListNode(val);
        dummy->next = nowHead;
        nowHead->next = head;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = dummy;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        ListNode* node = new ListNode(val);
        cur->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
        } else if (index >= size) {
            addAtTail(val);
        } else {
            ListNode* cur = dummy;
            while (index--) {
                cur = cur->next;
            }
            ListNode* next = cur->next;
            ListNode* node = new ListNode(val);
            cur->next = node;
            node->next = next;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        ListNode* cur = dummy;
        while (index--) {
            cur = cur->next;
        }
        ListNode* next = cur->next;
        cur->next = cur->next->next;
        delete next;
        size--;
    }
};


int main() {
    MyLinkedList listNode;
    listNode.addAtHead(1);
    listNode.addAtHead(2);
    listNode.addAtTail(0);
    listNode.addAtIndex(2,2);
    listNode.addAtIndex(4,4);
    printList(listNode.dummy);
    printf("%d\n", listNode.get(6));
}