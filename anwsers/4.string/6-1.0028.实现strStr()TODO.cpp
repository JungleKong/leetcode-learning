#include "../../include/utils.h"


// next - 1的形式
void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); ++i) {
        while (j >= 0 && s[j + 1] != s[i]) {
            j = next[j];
        }
        if (s[j + 1] == s[i]) {
            j++;
        }
        next[i] = j;
    }
}   

int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    
    int next[needle.size()];
    getNext(next, needle);
    int j = -1;
    for (int i = 0; i < haystack.size(); ++i) {
        while (j >=0 && needle[j + 1] != haystack[i]) {  // 不匹配
            j = next[j];
        }
        if (needle[j + 1] == haystack[i]) {  // 当前字符匹配
            j++;
        }
        if (j == (needle.size() - 1)) {  // 匹配到了模式串
            return i - j;
        }
    }
    return -1;  // 没有匹配的情况
}

// next 不减1
void getNext2(int* next, const string& s) {
    int j = 0;
    next[0] = j;
    for (int i = 1; i < s.size(); ++i) {
        while (j >= 1 && s[j] != s[i]) {
            j = next[j - 1];
        }
        if (s[j] == s[i]) {
            j++;
        } 
        next[i] = j;
    }
}

int strStr2(const string& haystack, const string& needle) {
    if (needle.size() == 0) return 0;

    int next[needle.size()];
    getNext2(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++) {
        while (j >= 1 && needle[j] != haystack[i]) {
            j = next[j - 1];
        }
        if (needle[j] == haystack[i]) {
            j++;
        }
        if (j == needle.size()) {
            return i - j + 1;
        }
    }
    return -1;
}

int main() {
    cout << strStr2("mississippi", "issip") << endl;
    return 0;
}