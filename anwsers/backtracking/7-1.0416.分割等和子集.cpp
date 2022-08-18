#include "../../include/utils.h"

class Solution {
public:

    /**
     * @brief 01背包中,dp[j] 表示： 容量为j的背包，所背的物品价值可以最大为dp[j]
     *        01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
     *        一维滚动
     * 
     * @param nums 
     * @return true 
     * @return false 
     */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false; 
        int bag = sum / 2;

        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[bag] == bag) return true;
        return false;
    }

    // 二维数组
    bool canPartition(const vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false; 
        int bagSize = sum / 2;
        vector<int> weight = nums;
        vector<int> value = nums;

        vector<vector<int>> dp(weight.size(), vector<int>(bagSize + 1, 0));
        for (int i = weight[0]; i < bagSize; i++) {
            dp[0][i] = value[0];        
        }
        for (int i = 1; i < weight.size(); i++) {
            for (int j = 0; j <= bagSize; j++) {
                if (j < weight[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
        if (dp[weight.size() - 1][bagSize] == bagSize) return true;
        return false;
    }
};


int main() {
    return 0;
}