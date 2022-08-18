#include "../../include/utils.h"

class Solution {
vector<vector<string>> res;
vector<string> tmp;
public:
    vector<vector<string>> partition(string s) {
        backtracking(0, s);
        return res;
    }

    void backtracking(int begin, const string& s) {
        if (begin >= s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = begin; i < s.size(); i++) {
            if (isPalindrome(s, begin, i)) {
                tmp.push_back(s.substr(begin, i - begin + 1));
                backtracking(i + 1, s);
                tmp.pop_back();
            }
        }
    }

    bool isPalindrome(const string& str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) return false;
        }
        return true;
    }
};

int main() {
    Solution so;
    printVec(so.partition("aab"));
    return 0;
}