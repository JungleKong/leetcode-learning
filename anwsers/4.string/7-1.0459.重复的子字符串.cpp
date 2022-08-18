#include "../../include/utils.h"


void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = j;
    for (int i = 1; i< s.size(); ++i) {
        while (j >= 0 && s[j + 1] != s[i]) {
            j = next[j];
        }
        if (s[j + 1] == s[i]) {
            j++;
        }
        next[i] = j;
    }
}

void getext2(int* next, const string& s) {
    int j = 0;
    next[0] = j;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[j] != s[i]) {
            j = next[j - 1];
        }
        if (s[j] == s[i]) {
            j++;
        }
        next[i] = j;
    }
}

//   s: a s d f a s d f a s d f
//next:-1-1-1-1 0 1 2 3 4 5 6 7
bool repeatedSubstringPattern(string s) {
    if (s.size() == 0) {
        return false;
    }
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
        return true;
    }
    return false;
}

bool repeatedSubStringPattern2(const string& s) {
    string str = s + s;
    if (str.find(s, 1) == s.size()) return true;
    return false;
}

bool repeatedSubStringPattern3(const string& s) {
    if (s.size() == 0) return false;
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) return true;
    return false;
}

int main() {
    cout << repeatedSubstringPattern("asdfasdfasdf") << endl;
    return false;
}