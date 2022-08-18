#include "../../include/utils.h"

class Solution {
vector<string> res;
string str;
const vector<string> vec = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        backtracking(0, digits);
        return res;
    }

    void backtracking(int i, const string& digits) {
        if (i = digits.size()) {
            res.push_back(str);
            return;
        }
        string letters = vec[digits[i] - '2'];
        for (int j = 0; j < letters.size(); j++) {
            str += letters[j];
            backtracking(i + 1, digits);
            str.pop_back();
        }
    }
};