#include "../../include/utils.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(1, 0, n, k, tmp, res);
        return res;
    }
 
    void backtracking(int i, int j, int n, int k, vector<int>& tmp, vector<vector<int>>& res) {
        if (j == k) {
            res.push_back(tmp);
            return;
        }
        for (int m = i; m <= n; m++) {
            tmp.push_back(m);
            backtracking(m + 1, j + 1, n, k, tmp, res);
            tmp.pop_back();
        }
    } 
};

int main() {
    Solution so;
    printVec(so.combine(4,2));
    return 0;
}