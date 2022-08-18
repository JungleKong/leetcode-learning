#include "../../include/utils.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, target, candidates, tmp, res);
        return res;

    }

    void backtracking(int i, int sum, int target, vector<int>& candidates, vector<int>& tmp, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        if (sum + candidates[0] > target) {
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            tmp.push_back(candidates[j]);
            backtracking(j + 1, sum + candidates[j], target, candidates, tmp, res);
            tmp.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    Solution so;
    printVec(so.combinationSum2(candidates, 8));
    return 0;
}