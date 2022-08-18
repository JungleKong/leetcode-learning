#include "../../include/utils.h"

class Solution {
vector<string> res;
vector<string> tmp;
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(0, s);
        return res;
    }

    void backtracking(int begin, const string& s) {
        if (begin >= s.size() && tmp.size() == 4) {
            res.push_back(tmp[0] + "." + tmp[1] + "." + tmp[2] + "." + tmp[3]);
        }

        for (int i = begin; i < s.size(); i++) {
            if (i > begin && s[begin] == '0') break;  // 01
            if (i - begin >= 4) break;  // 四位数肯定大于255
            string str = s.substr(begin, i - begin + 1);
            int ip = atoi(str.c_str());
            if (ip < 256) {
                tmp.push_back(str);
                backtracking(i + 1, s);
                tmp.pop_back();
            }
        }
    }
};

int main() {
    Solution so;
    printVec(so.restoreIpAddresses("1231231231234"));
    return 0;
}