#include "../../include/utils.h"

class Solution {
    vector<vector<int>> res;
    vector<int> tmp; 
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(used, nums);
        return res;
    }

    void backtracking(vector<bool>& used, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            if (used[i] == false) {
                tmp.push_back(nums[i]);
                used[i] = true;
                backtracking(used, nums);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {1,2,1};
    Solution so;
    printVec(so.permuteUnique(nums));
    return 0;
}