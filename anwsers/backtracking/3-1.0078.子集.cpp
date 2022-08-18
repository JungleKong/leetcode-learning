#include "../../include/utils.h"

class Solution {
vector<vector<int>> res;
vector<int> tmp;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0, nums);
        return res;
    }

    void backtracking2(int begin, vector<int>& nums) {
        res.push_back(tmp);
        if (begin >= nums.size()) {
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtracking(i + 1, nums);
            tmp.pop_back();
        }
    }

    // 回溯， 每个位置都有取或者不取， 共有2**n中状态， 类似于0/1的表示
    void backtracking(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        backtracking(i + 1, nums);
        tmp.pop_back();
        backtracking(i + 1, nums);
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution so;
    printVec(so.subsets(nums));
    return 0;
}