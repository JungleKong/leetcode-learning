#include "../../include/utils.h"

bool isHappy(int n) {
    unordered_set<int> set;
    while (true) {
        int res = 0;
        string str = to_string(n);
        while(n > 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        if (res == 1) return true;
        if (set.find(res) != set.end()) return false;
        set.insert(res);
        n = res;
        res = 0;
    }
    return false;
}


int helper(int n) {
    int res = 0;
    while (n > 0) {
        res += pow(n % 10, 2);
        n /= 10;
    }
    return res;
}

// 快慢指针法. 有循环最终会相遇.没有循环快指针最先到达1
bool isHappy2(int n) {
    int slow = n;
    int fast = helper(n);
    while (fast != 1 && slow != fast) {
        slow = helper(slow);
        fast = helper(helper(fast));
    }
    return fast == 1;
}
int main() {
    cout << isHappy(19) << endl;
    return 0;
}