#include "../../include/utils.h"

string removeDuplicates(string s) {
    string res;
    for (char ch: s) {
        if (!res.empty() && res.back() == ch) {
            res.pop_back();
        } else res.push_back(ch);
    }   
    return res;
}


// timeout
string removeDuplicates2(string s) {
    bool removed = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            s.erase(i - 1, 2);
            removed = true;
            i++;
        }
    }
    if (removed) {
        s = removeDuplicates(s);
        return s;
    } else return s;
}

int main() {
    return 0;
}