#include "../include/utils.h"

// 利用双指针去除多余空格, 参考"../array/0027"
void removeExtraSpaces(string& s) {
    int slow = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (slow != 0) s[slow++] = ' ';
            while (i < s.size() && s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}


string reverseWords(string s) {
    removeExtraSpaces(s);

    int len = s.size();
    reverse(s.begin(), s.end());

    int i = 0, j = 0;
    while (j <= len) {
        if (s[j] == ' ' || j == len) {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        j++;
    }
    return s;
}   