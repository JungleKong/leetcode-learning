#include "../../include/utils.h"

class Solution {
vector<vector<int>> res;
vector<int> tmp;
vector<bool> used;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        backtracking(0, nums);
        return res;
    }

    void backtracking(int begin, vector<int>& nums) {
        res.push_back(tmp);
        if (begin >= nums.size()) {
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            // if (i > begin && nums[i] == nums[i - 1]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            tmp.push_back(nums[i]);
            used[i] = true;
            backtracking(i + 1, nums);
            tmp.pop_back();
            used[i] = false;
        }
    }
};
