#include "../../include/utils.h"

bool isValid(string s) {
    int n = s.size();
    if (n % 2 == 1) return false;  // 奇数个返回假
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

    stack<char> stk;
    for (char ch: s) {
        if (pairs.count(ch)) {
            if (stk.empty() || stk.top() != pairs[ch]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(ch);
        }
    }
    return stk.empty();
}

int main() {
    string s = "[[()]]";
    cout << isValid(s) << endl;
    return 0;
}