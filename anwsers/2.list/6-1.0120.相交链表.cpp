#include "../../include/utils.h"

// 利用一个哈系表存储指针
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<long> set;
    ListNode* curA = headA;
    while (curA) {
        set.insert((long)curA);
        curA = curA->next;
    }
    ListNode* curB = headB;
    while (curB) {
        if (set.find((long)curB) != set.end()) {
            return curB;
        }
        curB = curB->next;
    }
    return nullptr;
}

// 当成一个环来处理,相当于求长度的最小公倍数次
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

// 计算出两个链表的长度,长的那个移动到和短的那个对齐的位置
// 1->2->3->4->5
//       |

//       6->4->5
//       |
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode* curA = headA, * curB = headB;
    while (curA) {
        lenA++;
        curA = curA->next;
    }
    while (curB) {
        lenB++;
        curB = curB->next;
    }
    int move = 0;
    if (lenA > lenB) {
        move = lenA - lenB;
    } else {
        move = lenB - lenA;
        std::swap(headA, headB);
    }

    ListNode* curA = headA;
    ListNode* curB = headB;
    while (move--) {
        curA = curA->next;
    }

    while (curA != curB) {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}

