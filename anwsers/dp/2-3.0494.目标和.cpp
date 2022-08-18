#include "../../include/utils.h"

class Solution {
int res = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        backtracking(0, 0, nums, target);
        return res;
    }

    void backtracking(int index, int sum, vector<int>& nums, int target) {
        if (index == nums.size()) {
            if (target == sum)
                res++;
            return;
        }

        backtracking(index + 1, sum + nums[index], nums, target);

        backtracking(index + 1, sum - nums[index], nums, target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2 == 1) return 0;
        int bagSize = (target + sum) / 2;
        if (bagSize < 0) return 0;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

int main() {
    Solution so;
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    cout << so.findTargetSumWays(nums, 3) << endl;
    return 0;
}