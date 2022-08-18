#include "../../include/utils.h"

class Solution {
vector<vector<int>> res;
vector<int> tmp;
vector<bool> used;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(0, nums);
        return res;
    }

    void backtracking(int begin, vector<int>& nums) {
        if (tmp.size() >= 2) {
            res.push_back(tmp);
        }
        if (begin > nums.size()) return;
        unordered_set<int> uset;
        for (int i = begin; i < nums.size(); i++) {
            if (!tmp.empty() && nums[i] < tmp.back() || uset.find(nums[i]) != uset.end()) continue;;
            uset.insert(nums[i]);
            tmp.push_back(nums[i]);
            backtracking(i + 1, nums);
            tmp.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {3,4,6,3,3};
    Solution so;
    printVec(so.findSubsequences(nums));
    return 0;
}