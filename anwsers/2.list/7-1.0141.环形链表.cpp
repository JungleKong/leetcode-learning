#include "../../include/utils.h"

bool hasCycle(ListNode *head) {
    ListNode* fast = head, * slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head, * slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            // 一个指针从相交节点开始,另一个从头节点开始,若有环,相遇节点即为环入口
            while (slow != head) {
                slow = slow->next;
                head = head->next;
            }
            return slow;
        }
    }
    return nullptr;
}

// 使用哈希表TODO

int main() {
    float a = 0.1;
    double b = double(a);
    printf("%.18f\n", a);
    printf("%.18f\n", b);
    return 0;
}
