#include "../../include/utils.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum3(int n, int k) {
        backtracking(1, 0, n, k);
        return res;

    }

    void backtracking(int i, int sum, int n, int k) {
        if (tmp.size() == n && sum == k) {
            res.push_back(tmp);
            return;
        }
        for (int j = i; j <= 9; j++) {
            tmp.push_back(j);
            backtracking(j + 1, sum + j, n, k);
            tmp.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    Solution so;
    printVec(so.combinationSum3(3, 9));
    return 0;
}