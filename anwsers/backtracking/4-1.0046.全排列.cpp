#include "../../include/utils.h"

class Solution {
    vector<vector<int>> res;
    vector<int> tmp; 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(used, nums);
        return res;
    }

    void backtracking(vector<bool>& used, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            tmp.push_back(nums[i]);
            used[i] = true;
            backtracking(used, nums);
            tmp.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution so;
    printVec(so.permute(nums));
    return 0;
}